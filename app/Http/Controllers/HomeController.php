<?php

namespace App\Http\Controllers;
use App\Models\StocksEntrees;
use App\Models\Produit;
use App\Models\Fournisseur;
use App\Models\StocksSorties;
use Illuminate\Support\Carbon;

use Illuminate\Support\Facades\DB;
use Illuminate\Http\Request;

class HomeController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        // Statistiques globales
        $nbProduits = Produit::count();
        $nbFournisseurs = Fournisseur::count();
        $nbEntrees = StocksEntrees::whereDate('created_at', '>=', now()->subDays(7))->sum('quantite');
        $nbSorties = StocksSorties::whereDate('created_at', '>=', now()->subDays(7))->sum('quantite');

        // Quantité restante par produit (entrées - sorties)
        $produitsStock = Produit::select('produits.id', 'produits.nom')
            ->leftJoin(DB::raw('(SELECT produit_id, SUM(quantite) as total_entree FROM stocks_entrees GROUP BY produit_id) as e'), 'produits.id', '=', 'e.produit_id')
            ->leftJoin(DB::raw('(SELECT produit_id, SUM(quantite) as total_sortie FROM stocks_sorties GROUP BY produit_id) as s'), 'produits.id', '=', 's.produit_id')
            ->get()
            ->map(function ($produit) {
                $reste = ($produit->total_entree ?? 0) - ($produit->total_sortie ?? 0);
                return [
                    'nom' => $produit->nom,
                    'reste' => $reste,
                ];
            });

        // Alerte pour les produits en stock faible (< 5)
        $alertes = $produitsStock->filter(fn($p) => $p['reste'] < 5)
            ->map(fn($p) => "Stock faible pour {$p['nom']} ({$p['reste']})")
            ->values();

        // Graphique : 7 derniers jours
        $jours = collect();
        for ($i = 6; $i >= 0; $i--) {
            $jours->push(now()->subDays($i)->format('Y-m-d'));
        }

        $labels = $jours->map(fn($date) => Carbon::parse($date)->translatedFormat('d M'));
        $entrees = $jours->map(fn($date) =>
            StocksEntrees::whereDate('created_at', $date)->sum('quantite')
        );
        $sorties = $jours->map(fn($date) =>
            StocksSorties::whereDate('created_at', $date)->sum('quantite')
        );

        return view('home', [
            'nbProduits' => $nbProduits,
            'nbFournisseurs' => $nbFournisseurs,
            'nbEntrees' => $nbEntrees,
            'nbSorties' => $nbSorties,
            'alertes' => $alertes,
            'labels' => $labels,
            'entrees' => $entrees,
            'sorties' => $sorties,
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
        //
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
