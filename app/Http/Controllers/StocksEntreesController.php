<?php

namespace App\Http\Controllers;

use App\Models\StocksEntrees;
use Illuminate\Http\Request;

class StocksEntreesController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        return view('stocksEntrees.index');
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
    public function show(Stocks_Entrees $stocks_Entrees)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(Stocks_Entrees $stocks_Entrees)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, Stocks_Entrees $stocks_Entrees)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(Stocks_Entrees $stocks_Entrees)
    {
        //
    }
}
