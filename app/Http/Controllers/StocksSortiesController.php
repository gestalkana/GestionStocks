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
    // Récupération des sorties avec les relations
    $stocksSorties = StocksSorties::with(['produit', 'user'])->orderBy('date_sortie')->get();

    // Récupération des entrées groupées par produit et date
    $stocksEntreesGrouped = StocksEntrees::selectRaw('produit_id, date_entree, SUM(COALESCE(quantite, 0)) as total_entree')
        ->groupBy('produit_id', 'date_entree')
        ->get();

    // Préparer une map des entrées par produit et date
    $entreesMap = [];

    foreach ($stocksEntreesGrouped as $entree) {
        $key = $entree->produit_id . '|' . $entree->date_entree;
        $entreesMap[$key] = floatval($entree->total_entree ?? 0);
    }

    // Liste enrichie avec stock avant/après
    $stocksSortiesFormatted = [];

    foreach ($stocksSorties as $sortie) {
        $produitId = $sortie->produit_id;
        $date = $sortie->date_sortie;

        // Quantité totale entrée jusqu’à cette date
        $totalEntree = StocksEntrees::where('produit_id', $produitId)
            ->whereDate('date_entree', '<=', $date)
            ->sum('quantite');
        $totalEntree = floatval($totalEntree);

        // Quantité totale sortie avant cette sortie (exclure l’actuelle)
        $totalSortieAvant = StocksSorties::where('produit_id', $produitId)
            ->whereDate('date_sortie', '<=', $date)
            ->where('id', '<', $sortie->id)
            ->sum('quantite');
        $totalSortieAvant = floatval($totalSortieAvant);

        // Quantité de la sortie actuelle (sécurisée)
        $sortieQuantite = floatval($sortie->quantite ?? 0);

        $stockAvant = $totalEntree - $totalSortieAvant;
        $stockApres = $stockAvant - $sortieQuantite;

        $sortie->stock_avant = $stockAvant;
        $sortie->stock_apres = $stockApres;

        $stocksSortiesFormatted[] = $sortie;
    }

    // Envoi des données à la vue
    $produits = Produit::all(); // nécessaire pour le formulaire

    return view('stocksSorties.index', [
        'stocksSorties' => $stocksSortiesFormatted,
        'produits' => $produits,
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
            'date_sortie' => 'nullable|date',
            'motif' => 'nullable|string|max:255',
        ]);

        $validated['date_sortie'] = $validated['date_sortie'] ?? Carbon::now();
        $validated['user_id'] = auth()->id();

        $sortie = StocksSorties::create($validated);

        $sortie->load('produit', 'user');

        if ($request->ajax()) {
            return response()->json([
                'sortie' => $sortie,
                'message' => 'Sortie enregistrée avec succès.'
            ]);
        }

        return redirect()->route('stocksSorties.index')->with('success', 'Sortie enregistrée.');
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


    /**
     * Remove the specified resource from storage.
     */
    public function destroy(Stocks_Sorties $stocks_Sorties)
    {
        //
    }
}
