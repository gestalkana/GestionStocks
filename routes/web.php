<?php

use App\Http\Controllers\ProfileController;
use Illuminate\Support\Facades\Route;
use App\Http\Controllers\ProduitController;
use App\Http\Controllers\CategorieController;
use App\Http\Controllers\HomeController;
use App\Http\Controllers\StocksEntreesController;
use App\Http\Controllers\StocksSortiesController;
use App\Http\Controllers\FournisseurController;



Route::get('/home',[HomeController::class, 'index']
)->middleware(['auth', 'verified'])->name('home');

Route::resource('produits', ProduitController::class
)->middleware(['auth', 'verified']);

Route::resource('/produits/categories', CategorieController::class
)->middleware(['auth', 'verified']);

Route::get('/produits/categories/reload', [CategorieController::class, 'reloadCategoriesFragment'])->name('categories.reload');

Route::resource('fournisseurs', FournisseurController::class
)->middleware(['auth', 'verified']);

Route::resource('stocksEntrees', StocksEntreesController::class
)->middleware(['auth', 'verified']);

Route::resource('stocksSorties', StocksSortiesController::class
)->middleware(['auth', 'verified']);



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