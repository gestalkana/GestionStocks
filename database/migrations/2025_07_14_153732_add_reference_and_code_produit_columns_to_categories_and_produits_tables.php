<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    /**
     * Run the migrations.
     */
    public function up(): void
    {
       
        // ➜ Ajout de `reference` à la table categories
        Schema::table('categories', function (Blueprint $table) {
            $table->string('reference')->unique();
        });

        // ➜ Ajout de `code_produit` à la table produits
        Schema::table('produits', function (Blueprint $table) {
            $table->string('code_produit')
                  ->after('nom')
                  ->unique();   // chaque code produit doit être unique
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        // Suppression des colonnes en cas de rollback
        Schema::table('produits', function (Blueprint $table) {
            $table->dropColumn('code_produit');
        });

        Schema::table('categories', function (Blueprint $table) {
            $table->dropColumn('reference');
        });;
    }
};
