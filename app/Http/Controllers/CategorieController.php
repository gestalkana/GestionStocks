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

    public function show(Categorie $categorie)
    {
        // Optionnel : tu peux rediriger ou retourner une vue
        return redirect()->route('categories.index');
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
    public function update(Request $request, $id)
    {
        $categorie = Categorie::findOrFail($id);
        $categorie->reference = $request->input('reference');
        $categorie->nom = $request->input('nom');
        $categorie->description = $request->input('description');
        $categorie->save();

        if ($request->expectsJson()) {
            return response()->json([
                'success' => true,
                'message' => 'Catégorie mise à jour',
                'categorie' => $categorie  // Utile si tu veux mettre à jour une seule ligne du tableau
            ]);

        }

        // Fallback si pas AJAX
        // return redirect()->back()->with('success', 'Catégorie mise à jour');
        return redirect()->route('produits.index', ['onglet' => 'categories'])->with('success', 'Catégorie mise à jour');
    }

    public function reloadCategoriesFragment()
    {
        //$categories = Categorie::all();
        $categories = Categorie::withCount('produits')->latest()->get();
        return view('produits.categories.index', compact('categories'));
    }


    /**
     * Supprimer une catégorie.
     */
    public function destroy($id)
    {
    try {
        $categorie = Categorie::findOrFail($id);
        \Log::info('Suppression de la catégorie ' . $categorie->id);

        $categorie->delete();

        return response()->json(['success' => true, 'message' => 'Catégorie supprimée.'], 200);
    } catch (\Exception $e) {
        \Log::error('Erreur suppression : ' . $e->getMessage());

        return response()->json([
            'success' => false,
            'message' => 'Erreur : ' . $e->getMessage()
        ], 500);
    }
    }


}
