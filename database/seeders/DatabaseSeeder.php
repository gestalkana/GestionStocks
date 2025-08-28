<?php

namespace Database\Seeders;

// use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;
use App\Models\User;
use App\Models\Categorie;
use App\Models\UniteMesure;
use App\Models\Entrepot;
use App\Models\Fournisseur;
use App\Models\Produit;
use App\Models\StocksEntrees;
use App\Models\StocksSorties;

class DatabaseSeeder extends Seeder
{
    /**
     * Seed the application's database.
     */
    public function run(): void
    {
        // User::factory(10)->create();

        $this->call(CleanDatabaseSeeder::class);
        
        Categorie::factory(10)->create();
        UniteMesure::factory(5)->create();
        Entrepot::factory(3)->create();
        Fournisseur::factory(10)->create();
        Produit::factory(20)->create();
        StocksEntrees::factory(50)->create();
        StocksSorties::factory(30)->create();
        //Pour les produits multiples
        StocksSorties::factory()->withMultipleProducts(5);

        /*User::factory()->create([
            'name' => 'Test User',
            'email' => 'test@example.com',
        ]);*/    
    }
}
