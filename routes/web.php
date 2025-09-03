<?php

use App\Http\Controllers\ProfileController;
use Illuminate\Support\Facades\Route;
use App\Http\Controllers\ProduitController;
use App\Http\Controllers\CategorieController;
use App\Http\Controllers\HomeController;
use App\Http\Controllers\StocksEntreesController;
use App\Http\Controllers\StocksSortiesController;
use App\Http\Controllers\FournisseurController;
use App\Http\Controllers\UniteMesureController;
use App\Http\Controllers\EntrepotController;



Route::get('/home',[HomeController::class, 'index']
)->middleware(['auth', 'verified'])->name('home');

Route::resource('produits', ProduitController::class
)->middleware(['auth', 'verified']);

Route::resource('categories', CategorieController::class
)->middleware(['auth', 'verified']);

Route::get('/produits/categories/reload', [CategorieController::class, 'reloadCategoriesFragment'])->name('categories.reload');Route::post('/unite_mesures', [UniteMesureController::class, 'store'])->name('unite_mesures.store');

//Route::resource('unite_mesures', [UniteMesureController::class, 'store'])->name('unite_mesures.store');

Route::resource('unite_mesures', UniteMesureController::class);

Route::resource('entrepots', EntrepotController::class);

Route::resource('fournisseurs', FournisseurController::class
)->middleware(['auth', 'verified']);

Route::resource('stocksEntrees', StocksEntreesController::class
)->middleware(['auth', 'verified']);

Route::get('/stocksEntrees/reload', [StocksEntreesController::class, 
            'reload'])->name('stocksEntrees.reload');

Route::resource('stocksSorties', StocksSortiesController::class
)->middleware(['auth', 'verified']);

Route::post('/stocks-sorties/ajax-store', [StocksSortiesController::class, 'ajaxStore'])->name('stocksSorties.ajaxStore');

Route::put('/stocks-sorties/{numero_bon}', [StocksSortiesController::class, 'update'])->name('stocksSorties.update');


Route::get('/produits/{id}/stock-disponible', [StocksSortiesController::class, 'getStockDisponible']);

Route::get('/api/lots-disponibles/{produit}', [StocksSortiesController::class, 'lotsDisponibles']);


Route::middleware('auth')->group(function () {
    Route::get('/profile', [ProfileController::class, 'edit'])->name('profile.edit');
    Route::patch('/profile', [ProfileController::class, 'update'])->name('profile.update');
    Route::delete('/profile', [ProfileController::class, 'destroy'])->name('profile.destroy');
});


require __DIR__.'/auth.php';




/*Route::get('/', function () {
    return view('home');
})->middleware(['auth', 'verified'])->name('home');

Route::get('/dashboard', function () {
    return view('dashboard');
})->middleware(['auth', 'verified'])->name('dashboard');
*/