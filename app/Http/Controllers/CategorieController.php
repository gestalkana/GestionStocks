<?php

namespace App\Http\Controllers;

use App\Models\Categorie;
use Illuminate\Http\Request;

class CategorieController extends Controller
{
    /**
     * Afficher la liste des catégories.
     */
    public function index()
    {
        // Récupère toutes les catégories avec le nombre de produits associés
        $categories = Categorie::withCount('produits')->latest()->get();

        return view('produits.categories.index', compact('categories'));
    }

    /**
     * Afficher le formulaire de création d'une nouvelle catégorie.
     */
    public function create()
    {
        return view('categories.create');
    }

    /**
     * Enregistrer une nouvelle catégorie.
     */
    public function store(Request $request)
    {
         $validated = $request->validate([
        'reference' => 'required|string',
        'nom' => 'required|string',
        'description' => 'nullable|string',
        ]);

        $categorie = Categorie::create($validated);

        if ($request->ajax()) {
            return response()->json([
                'category' => $categorie->loadCount('produits')
            ]);
        }

        return redirect()->route('produits.index');
    }



    /**
     * Afficher le formulaire d'édition.
     */
    public function edit(Categorie $categorie)
    {
        return view('categories.edit', compact('categorie'));
    }

    /**
     * Mettre à jour une catégorie.
     */
    public function update(Request $request, Categorie $categorie)
    {
        $request->validate([
            'name' => 'required|string|max:255',
            'description' => 'nullable|string|max:1000',
        ]);

        $categorie->update($request->only('name', 'description'));

        return redirect()->route('categories.index')->with('success', 'Catégorie mise à jour.');
    }

    /**
     * Supprimer une catégorie.
     */
    public function destroy(Categorie $categorie)
    {
        $categorie->delete();

        return redirect()->route('categories.index')->with('success', 'Catégorie supprimée.');
    }
}
