<?php

namespace App\Http\Controllers;

use App\Models\Produit;
use App\Models\Categorie;
use App\Models\StocksEntrees;
use App\Models\StocksSorties;
use App\Models\UniteMesure;
use Illuminate\Http\Request;

class ProduitController extends Controller
{
    /**
     * Display a listing of the resource.
     */
   public function index(Request $request)
    {
        $produits = Produit::with('categorie')->paginate(10);
        // Récupère toutes les catégories avec le nombre de produits associés
        $categories = Categorie::withCount('produits')->latest()->get();
        // Récupère toutes les unités de mesure
        $uniteMesure = UniteMesure::all();

        if ($request->ajax()) {
            return view('produits.listeProduits', compact('produits'))->render();
        }

        return view('produits.index', compact('produits', 'categories', 'uniteMesure'));
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
            'prix_unitaire' => 'required|numeric|min:0',
            'prix_achat' => 'nullable|numeric|min:0',
            'date_expiration' => 'nullable|date',
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
    public function show(Produit $produit)
    {
    return view('produits.show', compact('produit'));
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
    public function update(Request $request, Produit $produit)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(Produit $produit)
    {
        //
    }
}
