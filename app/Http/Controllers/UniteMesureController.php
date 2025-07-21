<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\UniteMesure;

class UniteMesureController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        //
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
        // Validation des données d'entrée
        $validated = $request->validate([
            'nom' => 'required|string|max:255',
            'description' => 'nullable|string',
            'unite_mesure_id' => 'nullable|exists:unite_mesures,id',
        ]);

        // Création de l'objet Produit
        $produit = new Produit();
        $produit->nom = $validated['nom'];
        $produit->description = $validated['description'] ?? null;
        $produit->unite_mesure_id = $validated['unite_mesure_id'] ?? null;

        // Sauvegarde dans la base de données
        $produit->save();

        return response()->json([
            'message' => 'Produit créé avec succès.',
            'data' => $produit
        ], 201);
    }

    /**
     * Display the specified resource.
     */
    public function show(string $id)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(string $id)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, string $id)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(string $id)
    {
        //
    }
}
