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
    // Récupération des sorties de stock triées par date_sortie DESC
    $stocksSorties = StocksSorties::with(['produit', 'user'])
        ->orderBy('date_sortie', 'desc')
        ->orderBy('numero_bon', 'desc')
        ->get();

    // Groupement par numéro de bon
    $stocksSortiesGroupes = $stocksSorties->groupBy('numero_bon');

    $bonsSortie = [];

    foreach ($stocksSortiesGroupes as $bon => $sorties) {
        $firstSortie = $sorties->first();

        $bonsSortie[] = [
            'numero_bon' => $bon,
            'date_sortie' => $firstSortie->date_sortie,
            'statut' => $firstSortie->statut,
            'nombre_produits' => $sorties->count(),
            'user' => $firstSortie->user,
            'id' => $firstSortie->id,
        ];
    }

    // Tri final du tableau des bons par date_sortie desc (et éventuellement numero_bon desc)
    usort($bonsSortie, function ($a, $b) {
        return strcmp($b['date_sortie'], $a['date_sortie']) ?: strcmp($b['numero_bon'], $a['numero_bon']);
    });

    // Produits avec des stocks disponibles
    $produitsAvecStock = Produit::whereHas('stocksEntrees', function ($query) {
        $query->select('produit_id')->groupBy('produit_id');
    })->get()->filter(function ($produit) {
        $totalEntree = StocksEntrees::where('produit_id', $produit->id)->sum('quantite');
        $totalSortie = StocksSorties::where('produit_id', $produit->id)->sum('quantite');
        return ($totalEntree - $totalSortie) > 0;
    });

    // Lots disponibles
    $stocksEntreesDisponibles = StocksEntrees::with('produit')->get()->filter(function ($entree) {
        $totalSortie = StocksSorties::where('stock_entree_id', $entree->id)->sum('quantite');
        return ($entree->quantite - $totalSortie) > 0;
    });

    // Numéro automatique du bon
    $numeroBon = $this->genererNumeroBon();

    return view('stocksSorties.index', [
        'stocksSorties' => $bonsSortie,
        'produits' => $produitsAvecStock,
        'stocksEntrees' => $stocksEntreesDisponibles,
        'numeroBon' => $numeroBon,
        'id' => $bonsSortie[0]['id'] ?? null,
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
    public function ajaxStore(Request $request)
    {  
        // -------------------------------
        // Validation initiale
        // -------------------------------
        // // dd($request->all());
        // \Log::info($request->all());
        // try {
        //            $request->validate([
        //     'user_id'         => 'nullable|exists:users,id',
        //     'date_sortie'         => 'required|date',
        //     'statut'              => 'required|string|in:brouillon,valide,annule',
        //     'client'              => 'nullable|string|max:255',
        //     'numero_ordre'        => 'nullable|string|max:255',
        //     'produits'            => 'required|array|min:1',
        //     'produits.*.produit_id' => 'required|exists:produits,id',
        //     'produits.*.quantite'   => 'required|integer|min:1',
        //     'produits.*.lots'       => 'nullable|array',
        //     'produits.*.lots.*'     => 'nullable|string',
        // ]);
        //     // Ton code de sauvegarde ou autre logique ici...
        //     return response()->json(['message' => 'Données validées avec succès']);
        // } catch (\Illuminate\Validation\ValidationException $e) {
        //     return response()->json(['errors' => $e->errors()], 422);
        // } catch (\Throwable $e) {
        //     // Très utile pour voir l’erreur réelle
        //     return response()->json([
        //         'error' => $e->getMessage(),
        //         'file' => $e->getFile(),
        //         'line' => $e->getLine(),
        //     ], 500);
        // }

        // -------------------------------
        // Récupération des valeurs
        // -------------------------------
        $numeroOrdre = $request->input('numero_ordre');
        $statut = strtolower($request->statut ?? 'brouillon'); // Brouillon par défaut
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
            // Gestion des lots si statut "validé"
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
                // Création des sorties et MAJ des stocks
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
                        'numero_ordre' => $numeroOrdre,
                        'statut' => 'valide'
                    ]);

                    $stock = StocksEntrees::find($lotId);
                    $stock->quantite -= $qte;
                    $stock->save();
                }
            } else {
                // -------------------------------
                // Cas "brouillon" ou sans lots
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
                    'numero_ordre' => $numeroOrdre,
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
    public function show($id)
    {
        // Récupère la sortie par ID
        $sortie = StocksSorties::with(['produit', 'user'])
            ->findOrFail($id);

        // Récupère toutes les lignes avec le même numéro de bon
        $sortiesDuBon = StocksSorties::with(['produit', 'user', 'stocksEntrees'])
            ->where('numero_bon', $sortie->numero_bon)
            ->orderBy('produit_id')
            ->get();

        // Calcul des stocks avant/après pour chaque ligne
        foreach ($sortiesDuBon as $ligne) {
            $produitId = $ligne->produit_id;
            $date = $ligne->date_sortie;

            // Total des entrées jusqu'à la date
            $totalEntree = StocksEntrees::where('produit_id', $produitId)
                ->whereDate('date_entree', '<=', $date)
                ->sum('quantite');

            // Total des sorties avant cette ligne
            $totalSortieAvant = StocksSorties::where('produit_id', $produitId)
                ->whereDate('date_sortie', '<=', $date)
                ->where('id', '<', $ligne->id)
                ->sum('quantite');

            $stockAvant = $totalEntree - $totalSortieAvant;
            $stockApres = $stockAvant - floatval($ligne->quantite);

            $ligne->stock_avant = $stockAvant;
            $ligne->stock_apres = $stockApres;
        }

        return view('stocksSorties.show', [
            'bon' => $sortie,
            'sorties' => $sortiesDuBon,
        ]);
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
        $stocksEntrees = StocksEntrees::with(['produit', 'stocksSorties'])
            ->where('produit_id', $produitId)
            ->get();

        $lots = $stocksEntrees->map(function ($lot) {
            $quantiteSortie = $lot->stocksSorties->sum('quantite');
            $reste = $lot->quantite - $quantiteSortie;

            if ($reste <= 0) return null;

            return [
                'id' => $lot->id,
                'produit' => $lot->produit->nom,
                'numero_lot' => $lot->numero_lot,
                'date_entree' => $lot->date_entree,
                'date_expiration' => $lot->date_expiration,
                'reste' => $reste,
            ];
        })->filter()
          ->sortBy([
              ['numero_lot', 'asc'],
              ['date_entree', 'asc'],
          ])->values();

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
