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
    public function index()
    {
        // Récupération des entrées avec les relations
        $stocksEntrees = StocksEntrees::with(['produit', 'fournisseur', 'user', 'entrepot'])->orderBy('date_entree')->get();
        $entrepots = Entrepot::all();
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

        // $entree->stock_avant = $stockAvant;
        // $entree->stock_apres = $stockApres;
        $entree->save();

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
