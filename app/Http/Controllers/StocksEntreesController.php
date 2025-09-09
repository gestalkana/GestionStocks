<?php

namespace App\Http\Controllers;

use App\Models\StocksEntrees;
use App\Models\Produit;
use App\Models\Fournisseur;
use App\Models\StocksSorties;
use App\Models\Entrepot;
use Illuminate\Http\Request;
use Illuminate\Support\Carbon;
use Illuminate\Support\Facades\Response;

class StocksEntreesController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    // public function index()
    // {
    //     // Récupération des entrées avec les relations
    //     $stocksEntrees = StocksEntrees::with(['produit', 'fournisseur', 'user', 'entrepot'])
    //     ->orderBy('date_entree', 'desc')
    //     ->orderBy('numero_lot', 'desc')->get();
    //     $entrepots = Entrepot::all();
    //     // Récupération des sorties groupées par produit et date
    //     $stocksSortiesGrouped = StocksSorties::selectRaw('produit_id, date_sortie, SUM(COALESCE(quantite, 0)) as total_sortie')
    //         ->groupBy('produit_id', 'date_sortie')
    //         ->get();

    //     // Préparer une collection des sorties par produit et date
    //     $sortiesMap = [];

    //     foreach ($stocksSortiesGrouped as $sortie) {
    //         $key = $sortie->produit_id . '|' . $sortie->date_sortie;
    //         $sortiesMap[$key] = floatval($sortie->total_sortie ?? 0);
    //     }

    //     // Liste enrichie
    //     $stocksEntreesFormatted = [];

    //     foreach ($stocksEntrees as $entree) {
    //         $produitId = $entree->produit_id;
    //         $date = $entree->date_entree;

    //         // Quantité totale entrée jusqu'à cette date
    //         $totalEntree = StocksEntrees::where('produit_id', $produitId)
    //             ->whereDate('date_entree', '<=', $date)
    //             ->where('id', '<=', $entree->id)
    //             ->sum('quantite');
    //         $totalEntree = floatval($totalEntree);

    //         // Quantité totale sortie jusqu'à cette date
    //         $totalSortie = StocksSorties::where('produit_id', $produitId)
    //             ->whereDate('date_sortie', '<=', $date)
    //             ->where('id', '<=', $entree->id)
    //             ->sum('quantite');
    //         $totalSortie = floatval($totalSortie);

    //         // Quantité de l'entrée actuelle (sécurisée)
    //         $entreeQuantite = floatval($entree->quantite ?? 0);

    //         $stockApres = $totalEntree - $totalSortie;
    //         $stockApres = $stockApres < 0 ? 0 : $stockApres;
    //         $stockDisponible =  $totalEntree - $totalSortie;
    //         $stockAvant = $stockDisponible - $entreeQuantite;
    //         $stockAvant = $stockAvant < 0 ? 0 : $stockAvant;

    //         $entree->stock_avant = $stockAvant;
    //         $entree->stock_apres = $stockApres;
    //         $entree->stock_disponible = $stockApres;

    //         $stocksEntreesFormatted[] = $entree;
    //     }

    //     $produits = Produit::with('uniteMesure')->get();
    //     $fournisseurs = Fournisseur::all();

    //     return view('stocksEntrees.index', [
    //         'stocksEntrees' => $stocksEntreesFormatted,
    //         'produits' => $produits,
    //         'fournisseurs' => $fournisseurs,
    //         'entrepots' => $entrepots,
    //     ]);
    // }
          public function index()
        {
            // Récupération des entrées avec les relations
            $stocksEntrees = StocksEntrees::with(['produit', 'fournisseur', 'user', 'entrepot'])
                ->orderBy('date_entree', 'asc') // Chronologique pour un calcul logique
                ->orderBy('id', 'asc')
                ->get();

            $entrepots = Entrepot::all();
            $produits = Produit::with('uniteMesure')->get();
            $fournisseurs = Fournisseur::all();

            // Récupérer toutes les sorties, groupées par produit
            $stocksSorties = StocksSorties::orderBy('date_sortie', 'asc')->orderBy('id', 'asc')->get();

            // Grouper les sorties par produit pour accès rapide
            $sortiesParProduit = [];
            foreach ($stocksSorties as $sortie) {
                $sortiesParProduit[$sortie->produit_id][] = $sortie;
            }

            // Initialisation du cumul d'entrées et de sorties par produit
            $cumulEntreeParProduit = [];
            $cumulSortieParProduit = [];

            // Liste enrichie à retourner à la vue
            $stocksEntreesFormatted = [];

            foreach ($stocksEntrees as $entree) {
                $produitId = $entree->produit_id;
                $dateEntree = $entree->date_entree;
                $idEntree = $entree->id;
                $quantiteEntree = floatval($entree->quantite ?? 0);

                // Initialiser si ce produit n'a pas encore été traité
                if (!isset($cumulEntreeParProduit[$produitId])) {
                    $cumulEntreeParProduit[$produitId] = 0;
                }
                if (!isset($cumulSortieParProduit[$produitId])) {
                    $cumulSortieParProduit[$produitId] = 0;
                }

                // Stock AVANT : total entrées - total sorties pour ce produit à ce moment-là
                $stockAvant = $cumulEntreeParProduit[$produitId] - $cumulSortieParProduit[$produitId];
                $stockAvant = max(0, $stockAvant);

                // Ajouter cette entrée au cumul
                $cumulEntreeParProduit[$produitId] += $quantiteEntree;

                // Stock APRÈS : entrées cumulées - sorties cumulées (après ajout de l’entrée actuelle)
                $stockApres = $cumulEntreeParProduit[$produitId] - $cumulSortieParProduit[$produitId];
                $stockApres = max(0, $stockApres);

                // Ajouter au cumul de sortie toutes les sorties jusqu’à cette date (et ID)
                if (isset($sortiesParProduit[$produitId])) {
                    foreach ($sortiesParProduit[$produitId] as $sortie) {
                        if (
                            $sortie->date_sortie < $dateEntree ||
                            ($sortie->date_sortie == $dateEntree && $sortie->id <= $idEntree)
                        ) {
                            $cumulSortieParProduit[$produitId] += floatval($sortie->quantite ?? 0);
                        }
                    }
                }

                // Enrichir l’objet entrée
                $entree->stock_avant = $stockAvant;
                $entree->stock_apres = $stockApres;
                $entree->stock_disponible = $stockApres;

                $stocksEntreesFormatted[] = $entree;
            }

            return view('stocksEntrees.index', [
                'stocksEntrees' => collect($stocksEntreesFormatted), //transformaiton en collection
                'produits' => $produits,
                'fournisseurs' => $fournisseurs,
                'entrepots' => $entrepots,
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
        // Validation avec contrainte sur date_entree (pas de date future)
        $validated = $request->validate([
            'produit_id' => 'required|exists:produits,id',
            'quantite' => 'required|numeric|min:1',
            'fournisseur_id' => 'nullable|exists:fournisseurs,id',
            'entrepot_id' => 'required|exists:entrepots,id',
            'date_entree' => 'required|date|before_or_equal:today',
            'date_expiration' => 'nullable|date',
        ]);

        // Vérifier si le produit existe déjà dans un autre entrepôt
        $existeAutreMagasin = StocksEntrees::where('produit_id', $validated['produit_id'])
            ->where('entrepot_id', '!=', $validated['entrepot_id'])
            ->exists();

        if ($existeAutreMagasin) {
            if ($request->ajax()) {
                return response()->json([
                    'error' => true,
                    'type' => 'produit_autre_magasin',
                    'message' => 'Ce produit est déjà enregistré dans un autre magasin.'
                ], 409); // 409 = Conflict
            }
            return redirect()->back()->withErrors(['produit_id' => 'Ce produit est déjà enregistré dans un autre magasin.']);
        }

        // Génération du numéro de lot
        $validated['numero_lot'] = $this->generateNumeroLot($validated['entrepot_id']);
       
        // Création de l'entrée stock
        $entree = new StocksEntrees($validated);
        $entree->user_id = auth()->id();
        // Initialisation de la quantité disponible au moment de l'entrée
        $entree->quantite_disponible = $validated['quantite'];
        $entree->save();

        // Calcul du stock total entré jusqu'à la date d'entrée du lot (inclus)
        $totalEntree = StocksEntrees::where('produit_id', $entree->produit_id)
            ->where('entrepot_id', $entree->entrepot_id)
            ->whereDate('date_entree', '<=', $entree->date_entree)
            ->sum('quantite') ?? 0;

        // Calcul du stock total sorti jusqu'à la date d'entrée du lot (inclus)
        $totalSortie = StocksSorties::where('produit_id', $entree->produit_id)
            ->where('entrepot_id', $entree->entrepot_id)
            ->whereDate('date_sortie', '<=', $entree->date_entree)
            ->sum('quantite') ?? 0;

        // Calcul stock après et avant cette entrée
        $stockApres = $totalEntree - $totalSortie;
        $stockAvant = $stockApres - (float) $entree->quantite;

        $entree->stock_avant = $stockAvant;
        $entree->stock_apres = $stockApres;
        //stock disponible pour un lot
        //$entree->save();

        // Chargement des relations utiles pour la réponse
        $entree->load(['produit', 'user', 'entrepot']);

        if ($request->ajax()) {
            return response()->json([
                'entree' => $entree
            ]);
        }

        return redirect()->route('stocksEntrees.index')->with('success', 'Entrée enregistrée.');
    }


    /**
     * Display the specified resource.
     */
    public function show($id)
    {
        $stockEntree = StocksEntrees::with([
            'produit', 
            'entrepot', 
            'user', 
            'stocksSorties.user'])->findOrFail($id);

        return view('stocksEntrees.show', compact('stockEntree'));
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(StocksEntrees $stocksEntrees)
    {
        //
    }
    //rechargement 
     public function reload()
    {
        //$stocksEntrees = StocksEntrees::latest()->get();
        $stocksEntrees = StocksEntrees::with(['produit', 'user'])->latest()->get();

        return view('stocksEntrees.listeStocksEntrees', compact('stocksEntrees'));
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, $id)
    {
        $request->validate([
            'quantite' => 'required|integer|min:1',
            'date_expiration' => 'required|date|after_or_equal:today',
        ]);

        $entree = StocksEntrees::findOrFail($id);
        $entree->quantite = $request->input('quantite');
        $entree->date_expiration = $request->input('date_expiration');
        $entree->save();

        // Charger les relations
        $entree->load(['produit', 'user']);

        // Calcul dynamique du stock avant/après
        $produitId = $entree->produit_id;
        $date = $entree->date_entree;

        $totalEntree = StocksEntrees::where('produit_id', $produitId)
            ->whereDate('date_entree', '<=', $date)
            ->where('id', '<=', $entree->id)
            ->sum('quantite');

        $totalSortie = StocksSorties::where('produit_id', $produitId)
            ->whereDate('date_sortie', '<=', $date)
            ->sum('quantite');

        $entreeQuantite = floatval($entree->quantite ?? 0);
        $stockApres = floatval($totalEntree) - floatval($totalSortie);
        $stockAvant = $stockApres - $entreeQuantite;

        $entree->stock_avant = $stockAvant;
        $entree->stock_apres = $stockApres;

        return response()->json([
            'message' => 'Entrée mise à jour avec succès.',
            'stocksEntrees' => $entree->fresh()
        ]);
    }

   
    /**
     * Remove the specified resource from storage.
     */
    public function destroy($id)
    {
        $stockEntree = StocksEntrees::with('stocksSorties')->findOrFail($id);

        // Sécurité : empêcher la suppression si des sorties existent
        if ($stockEntree->stocksSorties->count() > 0) {
            return redirect()->back()->with('error', 'Impossible de supprimer cette entrée : des sorties y sont liées.');
        }

        // Suppression
        $stockEntree->delete();

        return redirect()->route('stocksEntrees.index')->with('success', 'Entrée de stock supprimée avec succès.');
    }


    private function generateNumeroLot($entrepotId)
    {
    // Mois et année actuels
    $moisAnnee = now()->format('my'); // MMYY

    // Compter combien de lots déjà créés ce mois-ci pour cet entrepôt
    $countThisMonth = StocksEntrees::where('entrepot_id', $entrepotId)
        ->whereMonth('date_entree', now()->month)
        ->whereYear('date_entree', now()->year)
        ->count() + 1;

    // Formater N en 3 chiffres
    $sequence = str_pad($countThisMonth, 3, '0', STR_PAD_LEFT);

    // Retourner le numéro de lot
    return 'LOT-M' . str_pad($entrepotId, 2, '0', STR_PAD_LEFT) . '-' . $moisAnnee . '-' . $sequence;
    }

}
