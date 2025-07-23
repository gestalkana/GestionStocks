<?php

namespace App\Http\Controllers;

use App\Models\Fournisseur;
use Illuminate\Http\Request;

class FournisseurController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        $fournisseurs = Fournisseur::paginate(12); 
        return view('fournisseurs.index', compact('fournisseurs'));
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
                'nom' => 'required|string|max:255',
                'telephone' => 'nullable|string|max:20',
                'email' => 'nullable|email|max:255',
                'adresse' => 'nullable|string|max:255',
                'statut' => 'required|string|in:actif,inactif,blacklisté,en attente',
            ]);

            $fournisseur = Fournisseur::create($validated);

            if ($request->ajax()) {
                return response()->json([
                    'fournisseur' => $fournisseur
                ]);
            }

            return redirect()->route('fournisseurs.index');
        }


    /**
     * Display the specified resource.
     */
    public function show(Fournisseur $fournisseur)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(Fournisseur $fournisseur)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, $id)
    {
        // Valider les données
        $validated = $request->validate([
            'nom' => 'required|string|max:255',
            'telephone' => 'nullable|string|max:20',
            'email' => 'nullable|email|max:255',
            'adresse' => 'nullable|string|max:255',
            'statut' => 'nullable|in:actif,inactif',
        ]);

        // Trouver le fournisseur
        $fournisseur = Fournisseur::findOrFail($id);

        // Mettre à jour
        $fournisseur->update($validated);

        // Retourner une réponse JSON pour le frontend JS
        return response()->json([
            'message' => 'Fournisseur mis à jour avec succès.',
            'fournisseur' => $fournisseur,
        ]);
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(Fournisseur $fournisseur)
    {
        //
    }
}
