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
            $table->integer('quantite')->nullable();
            $table->date('date_sortie')->nullable();
            $table->text('motif')->nullable();
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::table('stocks_sorties', function (Blueprint $table) {
            $table->dropColumn([
                'quantite',
                'date_sortie',
                'motif',
            ]);
        });
    }
};
