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
        Schema::table('produits', function (Blueprint $table) {
    $table->dropForeign(['categorie_id']);

    // Modifier la colonne pour qu'elle accepte NULL
    $table->unsignedBigInteger('categorie_id')->nullable()->change();

    // Recréer la contrainte avec ON DELETE SET NULL
    $table->foreign('categorie_id')
          ->references('id')
          ->on('categories')
          ->onDelete('set null');
    });

    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::table('produits', function (Blueprint $table) {
        $table->dropForeign(['categorie_id']);
        $table->foreign('categorie_id')
              ->references('id')
              ->on('categories');
    });
    }
};
