<?php

namespace App\Http\Controllers;

use App\Models\Entrepot;
use Illuminate\Http\Request;

class EntrepotController extends Controller
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
    $validated = $request->validate([
        'nom' => 'required|string|max:255',
        'emplacement' => 'required|string|max:255',
    ]);

    Entrepot::create($validated);

    return redirect()->back()->with('success', 'Magasin ajouté avec succès.');
}

    /**
     * Display the specified resource.
     */
    public function show(Entrepot $entrepot)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(Entrepot $entrepot)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, Entrepot $entrepot)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(Entrepot $entrepot)
    {
        //
    }
}
