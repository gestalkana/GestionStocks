<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;
use Illuminate\Support\Facades\DB;

class CleanDatabaseSeeder extends Seeder
{
    public function run(): void
    {
        // Liste des tables à nettoyer (ordonnées dans l'ordre inverse des dépendances)
        $tables = [
            'stocks_sorties',
            'stocks_entrees',
            'produits',
            'fournisseurs',
            'entrepots',
            'unite_mesures',
            'categories',
        ];

        // Construire la commande TRUNCATE avec CASCADE
        $tablesList = implode(', ', $tables);

        // Exécuter TRUNCATE CASCADE pour vider toutes les tables (sauf users)
        DB::statement("TRUNCATE TABLE $tablesList CASCADE;");
    }
}
