<?php

namespace App\Http\Controllers;
use App\Models\StocksSorties;
use App\Models\Produit;
use App\Models\Fournisseur;
use App\Models\StocksEntrees;
use Illuminate\Http\Request;
use Illuminate\Support\Carbon;


class StocksSortiesController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        // Récupération des sorties de stock groupées par bon de sortie
        $stocksSortiesGroupes = StocksSorties::with(['produit', 'user'])
            ->orderBy('date_sortie', 'desc')
            ->get()
            ->groupBy('bon_sortie');

        $stocksSortiesFormatted = [];

        foreach ($stocksSortiesGroupes as $bon => $sorties) {
            foreach ($sorties as $sortie) {
                $produitId = $sortie->produit_id;
                $date = $sortie->date_sortie;

                // Calcul du stock total d’entrée jusqu’à la date
                $totalEntree = StocksEntrees::where('produit_id', $produitId)
                    ->whereDate('date_entree', '<=', $date)
                    ->sum('quantite');

                // Calcul du total de sorties jusqu’à la date et ID courant
                $totalSortieAvant = StocksSorties::where('produit_id', $produitId)
                    ->whereDate('date_sortie', '<=', $date)
                    ->where('id', '<', $sortie->id)
                    ->sum('quantite');

                $sortieQuantite = floatval($sortie->quantite ?? 0);

                $stockAvant = $totalEntree - $totalSortieAvant;
                $stockApres = $stockAvant - $sortieQuantite;

                $sortie->stock_avant = $stockAvant;
                $sortie->stock_apres = $stockApres;
                $sortie->bon_sortie_code = $bon;

                $stocksSortiesFormatted[] = $sortie;
            }
        }

        // Produits avec des stocks disponibles
        $produitsAvecStock = Produit::whereHas('stocksEntrees', function ($query) {
            $query->select('produit_id')->groupBy('produit_id');
        })->get()->filter(function ($produit) {
            $totalEntree = StocksEntrees::where('produit_id', $produit->id)->sum('quantite');
            $totalSortie = StocksSorties::where('produit_id', $produit->id)->sum('quantite');
            return ($totalEntree - $totalSortie) > 0;
        });

        // Lots disponibles à afficher dans le formulaire (stocks d’entrée non totalement utilisés)
        $stocksEntreesDisponibles = StocksEntrees::with('produit')
            ->get()
            ->filter(function ($entree) {
                $totalSortie = StocksSorties::where('stock_entree_id', $entree->id)->sum('quantite');
                return ($entree->quantite - $totalSortie) > 0;
            });

        $numeroBon = $this->genererNumeroBon();

        return view('stocksSorties.index', [
            'stocksSorties' => $stocksSortiesFormatted,
            'produits' => $produitsAvecStock,
            'stocksEntrees' => $stocksEntreesDisponibles,
            'numeroBon' => $numeroBon, // Passe-le à la vue
        ]);
    }



    /**
     * Show the form for creating a new resource.
     */
    public function create()
    {
        //
    }

    /**
     * Store a newly created resource in storage.
     */
    public function store(Request $request)
    {
    $request->validate([
        'date_sortie' => 'required|date',
        'client' => 'nullable|string',
        'produits' => 'required|array',
        'produits.*.produit_id' => 'required|exists:produits,id',
        'produits.*.quantite' => 'required|numeric|min:1',
        'produits.*.lots' => 'nullable|array',
    ]);

    // Génération du numéro de bon
    $numeroBon = $this->genererNumeroBon();
    //$numeroBon = 'BS-' . str_pad(StocksSorties::max('id') + 1, 4, '0', STR_PAD_LEFT);

    foreach ($request->produits as $produitData) {
        $sortie = StocksSorties::create([
            'produit_id'     => $produitData['produit_id'],
            'stock_entree_id'=> null, // défini par lot si nécessaire
            'quantite'       => $produitData['quantite'],
            'date_sortie'    => $request->date_sortie,
            'motif'          => $request->client,
            'user_id'        => auth()->id(),
            'statut'         => $request->action === 'valider' ? 'valide' : 'brouillon',
            'numero_bon'     => $numeroBon,
        ]);

        // Si des lots sont définis
        if ($request->action === 'valider' && isset($produitData['lots'])) {
            foreach ($produitData['lots'] as $lot) {
                [$lotId, $qte] = explode(':', $lot);

                // Création d'une ligne de sortie liée à un lot précis
                $sortieLot = $sortie->replicate(); // on copie les infos
                $sortieLot->stock_entree_id = $lotId;
                $sortieLot->quantite = $qte;
                $sortieLot->save();

                // Mise à jour du stock restant dans le lot
                $stock = StocksEntrees::find($lotId);
                if ($stock) {
                    $stock->quantite -= $qte;
                    if ($stock->quantite < 0) {
                        return back()->with('error', "Le stock du lot {$lotId} est insuffisant.");
                    }
                    $stock->save();
                }
            }

            // Supprime la sortie vide de base
            $sortie->delete();
        }
    }

    return redirect()->route('stocksSorties.index')
        ->with('success', $request->action === 'valider' 
            ? 'Sortie validée et stock mis à jour.' 
            : 'Sortie enregistrée en brouillon.');
    }
    //Enregistrement via ajax
    public function ajaxStore(Request $request)
    {
    $statut = $request->statut ?? 'brouillon';
    $numeroBon = $this->genererNumeroBon();

    if (!$request->has('produits')) {
        return response()->json([
            'success' => false,
            'message' => 'Aucun produit sélectionné.'
        ]);
    }

    foreach ($request->produits as $produitData) {
        $produitId = $produitData['produit_id'];
        $quantiteDemandee = $produitData['quantite'];

        if ($statut === 'valide' && isset($produitData['lots'])) {
            foreach ($produitData['lots'] as $lot) {
                [$lotId, $qte] = explode(':', $lot);
                StocksSorties::create([
                    'produit_id' => $produitId,
                    'stock_entree_id' => $lotId,
                    'quantite' => $qte,
                    'date_sortie' => now(),
                    'motif' => $request->motif,
                    'client' => $request->client,
                    'user_id' => auth()->id(),
                    'numero_bon' => $numeroBon,
                    'statut' => 'valide'
                ]);
            }
        } else {
            StocksSorties::create([
                'produit_id' => $produitId,
                'stock_entree_id' => null,
                'quantite' => $quantiteDemandee,
                'date_sortie' => now(),
                'motif' => $request->motif,
                'client' => $request->client,
                'user_id' => auth()->id(),
                'numero_bon' => $numeroBon,
                'statut' => 'brouillon'
            ]);
        }
        }

        return response()->json([
            'success' => true,
            'message' => 'Bon de sortie enregistré avec succès.'
        ]);
    }


    /**
     * Display the specified resource.
     */
    public function show(Stocks_Sorties $stocks_Sorties)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(Stocks_Sorties $stocks_Sorties)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, $id)
    {
        $sortie = StocksSorties::findOrFail($id);

        $validated = $request->validate([
            'quantite' => 'required|numeric|min:1',
            'motif' => 'nullable|string|max:255',
            'date_sortie' => 'required|date|before_or_equal:today',
        ]);

        $sortie->update($validated);

        $sortie->load('produit', 'user');

        return response()->json([
            'message' => 'Sortie mise à jour avec succès.',
            'stocksSorties' => $sortie,
        ]);
    }

    public function getStockDisponible($id)
    {
    $date = Carbon::now();

    $totalEntree = StocksEntrees::where('produit_id', $id)
        ->whereDate('date_entree', '<=', $date)
        ->sum('quantite');

    $totalSortie = StocksSorties::where('produit_id', $id)
        ->whereDate('date_sortie', '<=', $date)
        ->sum('quantite');

    $stockDisponible = $totalEntree - $totalSortie;

    return response()->json(['stock_disponible' => $stockDisponible]);
    }

    public function lotsDisponibles($produitId)
    {
        $lots = StocksEntrees::with('produit')
            ->where('produit_id', $produitId)
            ->get()
            ->filter(function ($lot) {
                $sortie = StocksSorties::where('stock_entree_id', $lot->id)->sum('quantite');
                return ($lot->quantite - $sortie) > 0;
            })
            ->map(function ($lot) {
                $sortie = StocksSorties::where('stock_entree_id', $lot->id)->sum('quantite');
                return [
                    'id' => $lot->id,
                    'produit' => $lot->produit->nom,
                    'date_entree' => $lot->date_entree,
                    'date_expiration' => $lot->date_expiration,
                    'reste' => $lot->quantite - $sortie,
                ];
            })
            ->values();

        return response()->json($lots);
    }

    private function genererNumeroBon()
    {
    $now = now(); // Date actuelle
    $prefixe = 'BS' . $now->format('Ym'); // BS202507

    // Chercher les bons du mois actuel
    $dernier = StocksSorties::where('numero_bon', 'like', $prefixe . '-%')
        ->orderByDesc('numero_bon')
        ->first();

    if ($dernier) {
        $lastNumber = intval(substr($dernier->numero_bon, -3));
        $newNumber = str_pad($lastNumber + 1, 3, '0', STR_PAD_LEFT);
    } else {
        $newNumber = '001';
    }

    return $prefixe . '-' . $newNumber;
    }


    /**
     * Remove the specified resource from storage.
     */
    public function destroy(Stocks_Sorties $stocks_Sorties)
    {
        //
    }
}
