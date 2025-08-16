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
    // -------------------------------
    // Validation des données
    // -------------------------------
    $request->validate([
        'date_sortie' => 'required|date',
        'client' => 'nullable|string',
        'produits' => 'required|array',
        'produits.*.produit_id' => 'required|exists:produits,id',
        'produits.*.quantite' => 'required|numeric|min:1',
        'produits.*.lots' => 'nullable|array',
    ]);

    // -------------------------------
    // Génération du numéro de bon
    // -------------------------------
    $numeroBon = $this->genererNumeroBon();

    // -------------------------------
    // Parcours des produits
    // -------------------------------
    foreach ($request->produits as $produitData) {
        $lots = $produitData['lots'] ?? [];
        $quantiteDemandee = $produitData['quantite'];
        $totalLots = 0;

        // -------------------------------
        // Vérification des lots
        // -------------------------------
        foreach ($lots as $lot) {
            [$lotId, $qte] = explode(':', $lot);
            $qte = (int) $qte;

            $stock = StocksEntrees::find($lotId);
            if (!$stock) {
                return back()->with('error', "Le lot {$lotId} n'existe pas.");
            }
            if ($stock->quantite < $qte) {
                return back()->with('error', "Le stock du lot {$lotId} est insuffisant. Disponible : {$stock->quantite}, demandé : {$qte}.");
            }

            $totalLots += $qte;
        }

        if ($totalLots > $quantiteDemandee) {
            return back()->with('error', "La somme des lots ({$totalLots}) dépasse la quantité demandée ({$quantiteDemandee}).");
        }

        // -------------------------------
        // Création des sorties pour chaque lot
        // -------------------------------
        foreach ($lots as $lot) {
            [$lotId, $qte] = explode(':', $lot);

            StocksSorties::create([
                'produit_id'     => $produitData['produit_id'],
                'stock_entree_id'=> $lotId,
                'quantite'       => $qte,
                'date_sortie'    => $request->date_sortie,
                'motif'          => $request->client,
                'user_id'        => auth()->id(),
                'statut'         => $request->action === 'validé' ? 'valide' : 'brouillon',
                'numero_bon'     => $numeroBon,
            ]);

            // Mise à jour du stock restant
            $stock = StocksEntrees::find($lotId);
            $stock->quantite -= $qte;
            $stock->save();
        }

        // -------------------------------
        // Si aucun lot défini, sortie normale
        // -------------------------------
        if (empty($lots)) {
            StocksSorties::create([
                'produit_id'     => $produitData['produit_id'],
                'stock_entree_id'=> null,
                'quantite'       => $quantiteDemandee,
                'date_sortie'    => $request->date_sortie,
                'motif'          => $request->client,
                'user_id'        => auth()->id(),
                'statut'         => $request->action === 'valider' ? 'valide' : 'brouillon',
                'numero_bon'     => $numeroBon,
            ]);
        }
    }

    // -------------------------------
    // Redirection avec message
    // -------------------------------
    return redirect()->route('stocksSorties.index')
        ->with('success', $request->action === 'valider' 
            ? 'Sortie validée et stock mis à jour.' 
            : 'Sortie enregistrée en brouillon.');
}

public function ajaxStore(Request $request)
{
    // -------------------------------
    // Récupération du statut et numéro de bon
    // -------------------------------
    $statut = strtolower($request->statut ?? 'brouillon'); // converti en minuscule pour uniformité
    $numeroBon = $this->genererNumeroBon();

    // -------------------------------
    // Vérification de la présence de produits
    // -------------------------------
    if (!$request->has('produits') || empty($request->produits)) {
        return response()->json([
            'success' => false,
            'message' => 'Aucun produit sélectionné.'
        ], 422);
    }

    foreach ($request->produits as $produitData) {
        $produitId = $produitData['produit_id'] ?? null;
        $quantiteDemandee = (int) ($produitData['quantite'] ?? 0);
        $lots = $produitData['lots'] ?? [];

        // -------------------------------
        // Validation produit et quantité
        // -------------------------------
        if (!$produitId || $quantiteDemandee <= 0) {
            return response()->json([
                'success' => false,
                'message' => "Produit ou quantité invalide."
            ], 422);
        }

        // -------------------------------
        // Gestion des lots si statut valide
        // -------------------------------
        if ($statut === 'valide' && !empty($lots) && is_array($lots)) {
            $totalLots = 0;

            foreach ($lots as $lot) {
                [$lotId, $qte] = explode(':', $lot);
                $qte = (int) $qte;

                $stock = StocksEntrees::find($lotId);
                if (!$stock) {
                    return response()->json([
                        'success' => false,
                        'message' => "Le lot #{$lotId} n'existe pas."
                    ], 422);
                }

                if ($stock->quantite < $qte) {
                    return response()->json([
                        'success' => false,
                        'message' => "Stock insuffisant pour le lot #{$lotId} (disponible: {$stock->quantite}, demandé: {$qte})."
                    ], 422);
                }

                $totalLots += $qte;
            }

            if ($totalLots > $quantiteDemandee) {
                return response()->json([
                    'success' => false,
                    'message' => "La somme des lots ({$totalLots}) dépasse la quantité demandée ({$quantiteDemandee})."
                ], 422);
            }

            // -------------------------------
            // Création des sorties et mise à jour des stocks
            // -------------------------------
            foreach ($lots as $lot) {
                [$lotId, $qte] = explode(':', $lot);
                $qte = (int) $qte;

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

                $stock = StocksEntrees::find($lotId);
                $stock->quantite -= $qte;
                $stock->save();
            }

        } else {
            // -------------------------------
            // Cas brouillon ou sans lots
            // -------------------------------
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
        'message' => $statut === 'valide'
            ? 'Sortie validée et stock mis à jour.'
            : 'Sortie enregistrée en brouillon.'
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
            // Calculer la quantité déjà sortie pour ce lot
            $quantiteSortie = StocksSorties::where('stock_entree_id', $lot->id)->sum('quantite');
            // Ne garder que les lots où il reste au moins 1 unité
            return ($lot->quantite - $quantiteSortie) > 0;
        })
        ->map(function ($lot) {
            $quantiteSortie = StocksSorties::where('stock_entree_id', $lot->id)->sum('quantite');
            return [
                'id' => $lot->id,
                'produit' => $lot->produit->nom,
                'numero_lot' => $lot->numero_lot, // <- colonne réelle dans ta table
                'date_entree' => $lot->date_entree,
                'date_expiration' => $lot->date_expiration,
                'reste' => $lot->quantite - $quantiteSortie,
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
