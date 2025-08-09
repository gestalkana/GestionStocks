<?php

namespace App\Http\Controllers;

use App\Models\StocksEntrees;
use App\Models\Produit;
use App\Models\Fournisseur;
use App\Models\StocksSorties;
use App\Models\Entrepot;
use Illuminate\Http\Request;
use Illuminate\Support\Carbon;

class StocksEntreesController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        // Récupération des entrées avec les relations
        $stocksEntrees = StocksEntrees::with(['produit', 'fournisseur', 'user', 'entrepot'])->orderBy('date_entree')->get();
        $magasins = Entrepot::all();
        // Récupération des sorties groupées par produit et date
        $stocksSortiesGrouped = StocksSorties::selectRaw('produit_id, date_sortie, SUM(COALESCE(quantite, 0)) as total_sortie')
            ->groupBy('produit_id', 'date_sortie')
            ->get();

        // Préparer une collection des sorties par produit et date
        $sortiesMap = [];

        foreach ($stocksSortiesGrouped as $sortie) {
            $key = $sortie->produit_id . '|' . $sortie->date_sortie;
            $sortiesMap[$key] = floatval($sortie->total_sortie ?? 0);
        }

        // Liste enrichie
        $stocksEntreesFormatted = [];

        foreach ($stocksEntrees as $entree) {
            $produitId = $entree->produit_id;
            $date = $entree->date_entree;

            // Quantité totale entrée jusqu'à cette date
            $totalEntree = StocksEntrees::where('produit_id', $produitId)
                ->whereDate('date_entree', '<=', $date)
                ->where('id', '<=', $entree->id)
                ->sum('quantite');
            $totalEntree = floatval($totalEntree);

            // Quantité totale sortie jusqu'à cette date
            $totalSortie = StocksSorties::where('produit_id', $produitId)
                ->whereDate('date_sortie', '<=', $date)
                ->sum('quantite');
            $totalSortie = floatval($totalSortie);

            // Quantité de l'entrée actuelle (sécurisée)
            $entreeQuantite = floatval($entree->quantite ?? 0);

            $stockApres = $totalEntree - $totalSortie;
            $stockAvant = $stockApres - $entreeQuantite;

            $entree->stock_avant = $stockAvant;
            $entree->stock_apres = $stockApres;

            $stocksEntreesFormatted[] = $entree;
        }

        $produits = Produit::with('uniteMesure')->get();
        $fournisseurs = Fournisseur::all();

        return view('stocksEntrees.index', [
            'stocksEntrees' => $stocksEntreesFormatted,
            'produits' => $produits,
            'fournisseurs' => $fournisseurs,
            'magasins' => $magasins,
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
        $validated = $request->validate([
            'produit_id' => 'required|exists:produits,id',
            'quantite' => 'required|numeric|min:1',
            'fournisseur_id' => 'nullable|exists:fournisseurs,id',
            'date_expiration' => 'nullable|date',
        ]);
        // Ajouter la date d'entrée actuelle
        $validated['date_entree'] = Carbon::now();
        $entree = new StocksEntrees($validated);
        $entree->user_id = auth()->id();
        $entree->save();

        // Calculer stock_avant et stock_apres
        $totalEntree = StocksEntrees::where('produit_id', $entree->produit_id)
            ->whereDate('date_entree', '<=', $entree->date_entree)
            ->where('id', '<=', $entree->id)
            ->sum('quantite');

        $totalSortie = StocksSorties::where('produit_id', $entree->produit_id)
            ->whereDate('date_sortie', '<=', $entree->date_entree)
            ->sum('quantite');

        $stockApres = $totalEntree - $totalSortie;
        $stockAvant = $stockApres - floatval($entree->quantite);

        $entree->stock_avant = $stockAvant;
        $entree->stock_apres = $stockApres;

        // Charger relations pour JS
        $entree->load(['produit', 'user']);

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
    public function show(StocksEntrees $stocksEntrees)
    {
        //
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
        'stocksEntrees' => $entree
    ]);
}

   
    /**
     * Remove the specified resource from storage.
     */
    public function destroy(StocksEntrees $stocksEntrees)
    {
        //
    }
}
