<?php

namespace Database\Seeders;

use Illuminate\Database\Seeder;
use Illuminate\Support\Facades\DB;

class CleanDatabaseSeeder extends Seeder
{
    public function run(): void
    {
        $tables = [
            'stocks_sorties',
            'stocks_entrees',
            // 'produits',
            // 'fournisseurs',
            // 'entrepots',
            // 'unite_mesures',
            // 'categories',
        ];

        $driver = DB::getDriverName();

        if ($driver === 'mysql') {
            // MySQL : désactiver les contraintes FK et truncate chaque table
            DB::statement('SET FOREIGN_KEY_CHECKS = 0;');

            foreach ($tables as $table) {
                DB::table($table)->truncate();
            }

            DB::statement('SET FOREIGN_KEY_CHECKS = 1;');
        } elseif ($driver === 'pgsql') {
            // PostgreSQL : utiliser TRUNCATE avec CASCADE
            $tablesList = implode(', ', array_map(fn($t) => "\"$t\"", $tables)); // Protège les noms de table
            DB::statement("TRUNCATE TABLE $tablesList CASCADE;");
        } else {
            // Optionnel : support pour d'autres SGBD ou erreur
            throw new \Exception("Unsupported database driver: $driver");
        }
    }
}
