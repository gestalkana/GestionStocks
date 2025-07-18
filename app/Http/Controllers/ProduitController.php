<?php

namespace App\Http\Controllers;

use App\Models\Produit;
use App\Models\Categorie;
use Illuminate\Http\Request;

class ProduitController extends Controller
{
    /**
     * Display a listing of the resource.
     */
   public function index()
    {
    $produits = Produit::with('categorie')->paginate(10);
    $categories = Categorie::withCount('produits')->get();

    return view('produits.index', compact('produits', 'categories'));
    }

    /**
     * Show the form for creating a new resource.
     */
    public function create()
    {
        $categories = Categorie::all(); // Récupère toutes les catégories
        return view('produits.create', compact('categories'));
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
        //
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
