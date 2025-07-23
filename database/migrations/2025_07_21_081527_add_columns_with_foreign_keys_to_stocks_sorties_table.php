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
        Schema::table('stocks_sorties', function (Blueprint $table) {
             $table->foreignId('produit_id')
                  ->constrained('produits')
                  ->onDelete('cascade');

            $table->foreignId('stock_entree_id')
                  ->constrained('stocks_entrees')
                  ->onDelete('cascade');
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::table('stocks_sorties', function (Blueprint $table) {
            $table->dropForeign(['produit_id']);
            $table->dropForeign(['stock_entree_id']);
        });
    }
};
