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
        // Validation des données
        $validated = $request->validate([
            'code' => 'required|string|max:10|unique:unite_mesures,code',
            'nom' => 'required|string|max:255',
            'symbole' => 'nullable|string|max:10',
        ]);

        // Création et sauvegarde
        $unite = UniteMesure::create([
            'code' => $validated['code'],
            'nom' => $validated['nom'],
            'symbole' => $validated['symbole'] ?? null,
        ]);

        // Réponse JSON (201 = créé)
       return response()->json([
            'message' => 'Unité de mesure créée avec succès.',
            'unite' => [
                'id' => $unite->id,
                'nom' => $unite->nom,
                'symbole' => $unite->symbole,
            ]
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
