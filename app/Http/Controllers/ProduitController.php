<?php

namespace App\Http\Controllers;

use App\Models\Produit;
use App\Models\Categorie;
use App\Models\StocksEntrees;
use App\Models\StocksSorties;
use App\Models\UniteMesure;
use App\Models\Entrepot;
use Illuminate\Http\Request;

class ProduitController extends Controller
{
    /**
     * Display a listing of the resource.
     */
   public function index(Request $request)
    {
    // Récupère les produits avec les relations nécessaires
    $produits = Produit::with(['categorie', 'stocksEntrees', 'stocksSorties'])->get();
    $entrepots = Entrepot::all();

    // Calcul du stock pour chaque produit
    foreach ($produits as $produit) {
        $totalEntrees = $produit->stocksEntrees->sum('quantite');
        $totalSorties = $produit->stocksSorties->sum('quantite');
        $produit->stock = $totalEntrees - $totalSorties;
    }

    // Récupère toutes les catégories avec le nombre de produits associés
    $categories = Categorie::withCount('produits')->latest()->get();

    // Récupère toutes les unités de mesure
    $uniteMesure = UniteMesure::all();

    // Couleurs pour les badges
    $badgeColors = ['bg-primary', 'bg-secondary', 'bg-success', 'bg-danger', 'bg-warning', 'bg-info', 'bg-dark'];
    $colorIndex = 0;

    // Si la requête est AJAX (filtrage), renvoyer seulement le tableau
    if ($request->ajax()) {
        return view('produits.listeProduits', compact('produits', 'badgeColors', 'colorIndex'))->render();
    }

    // Vue complète pour l’affichage normal
    return view('produits.index', compact('produits', 'categories', 'uniteMesure', 'entrepots', 'badgeColors', 'colorIndex'));
    }


    /**
     * Show the form for creating a new resource.
     */
    public function create()
    {
        $categories = Categorie::all(); // Récupère toutes les catégories
        // Récupère toutes les unités de mesure
        $uniteMesure = UniteMesure::all();
        return view('produits.create', compact('categories', 'uniteMesure'));
    }

    /**
     * Store a newly created resource in storage.
     */
    public function store(Request $request)
    {
        // Validation des données reçues
        $validatedData = $request->validate([
            'nom' => 'required|string|max:255',
            'code_produit' => 'required|string|unique:produits,code_produit',
            'description' => 'nullable|string',
            'prix_unitaire' => 'nullable|numeric|min:0',
            'prix_achat' => 'nullable|numeric|min:0',
            'date_expiration' => 'nullable|date',
            'unite_mesure_id' => 'nullable|exists:unite_mesures,id',
            'categorie_id' => 'nullable|exists:categories,id',
        ]);

        // Création du produit avec les données validées
        $produit = Produit::create($validatedData);

        // Chargement des relations nécessaires
        $produit->load('categorie');

        // Retourne une réponse (exemple : redirection ou JSON)
        return response()->json([
            'message' => 'Produit créé avec succès',
            'produit' => $produit
        ], 201);
        //return redirect()->route('produits.index');
    }
    /**
     * Display the specified resource.
     */
    /*public function show(Produit $produit)
    {
    return view('produits.show', compact('produit'));
    }
    public function show($id)
    {
    $produit = Produit::with(['categorie', 'stocksEntrees.fournisseur'])->findOrFail($id);

    $quantiteTotaleStock = $produit->stocksEntrees->sum('quantite') 
                            - StocksSorties::where('produit_id', $produit->id)->sum('quantite');

    return view('produits.show', compact('produit', 'quantiteTotaleStock'));
    }*/
    public function show($id)
    {
        $produit = Produit::with(['categorie', 'stocksEntrees.fournisseur','UniteMesure'])->findOrFail($id);
        $uniteMesure = UniteMesure::all();
        // Si l'unité de mesure n'existe pas, on crée un objet vide avec un nom par défaut
        if (!$produit->UniteMesure) {
            $produit->UniteMesure = (object) ['nom' => 'Non défini'];
        }

        // Quantité totale entrée
        $totalEntree = $produit->stocksEntrees->sum('quantite');

        // Quantité totale sortie
        $totalSortie = StocksSorties::where('produit_id', $produit->id)->sum('quantite');

        // Quantité totale en stock
        $quantiteTotaleStock = max($totalEntree - $totalSortie, 0);

        // Calculer quantité restante par entrée (proportionnelle)
        $lotsDisponibles = $produit->stocksEntrees->map(function($entree) use ($totalEntree, $totalSortie) {
            $proportion = $entree->quantite / $totalEntree;
            $quantiteSortieAssociee = $totalSortie * $proportion;
            $quantiteRestante = max($entree->quantite - $quantiteSortieAssociee, 0);
            $entree->quantite_restante = $quantiteRestante;
            return $entree;
        })->filter(function($entree) {
            return $entree->quantite_restante > 0;
        });

        return view('produits.show', compact('produit', 'quantiteTotaleStock', 'lotsDisponibles', 'uniteMesure'));
    }


    /**
     * Show the form for editing the specified resource.
     */
    public function edit(Produit $produit)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     */


    public function update(Request $request, $id)
    {
        $produit = Produit::findOrFail($id);

        // Validation des données
        $validated = $request->validate([
            'nom' => 'required|string|max:255',
            'code_produit' => 'required|string|max:100',
            'prix_achat' => 'nullable|numeric',
            'prix_unitaire' => 'required|numeric',
            'unite_mesure_id' => 'nullable|exists:unite_mesures,id',
            'description' => 'nullable|string',
        ]);

        // Mise à jour des champs
        $produit->nom = $validated['nom'];
        $produit->code_produit = $validated['code_produit'];
        $produit->prix_achat = $validated['prix_achat'];
        $produit->prix_unitaire = $validated['prix_unitaire'];
        $produit->unite_mesure_id = $validated['unite_mesure_id'];
        $produit->description = $validated['description'] ?? '';

        $produit->save();

        return response()->json([
            'success' => true,
            'message' => 'Produit mis à jour avec succès.',
            'produit' => $produit->load('uniteMesure') // charge la relation
        ]);
    }


    /**
     * Remove the specified resource from storage.
     */
    public function destroy(Request $request, $id)
    {
        $produit = Produit::findOrFail($id);

        try {
            $produit->delete();

            if ($request->expectsJson()) {
                return response()->json(['message' => 'Produit supprimé avec succès.']);
            }

            return redirect()->route('produits.index')->with('success', 'Produit supprimé avec succès.');
        } catch (\Exception $e) {
            if ($request->expectsJson()) {
                return response()->json([
                    'message' => 'Erreur lors de la suppression du produit.',
                    'error' => $e->getMessage()
                ], 500);
            }

            return redirect()->route('produits.index')->with('error', 'Erreur lors de la suppression.');
        }
    }
}
