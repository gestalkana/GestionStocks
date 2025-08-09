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
            $table->string('numero_bon')->nullable()->after('id');
            $table->string('statut')->default('brouillon')->after('motif');
            $table->string('client')->nullable()->after('date_sortie');
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::table('stocks_sorties', function (Blueprint $table) {
             $table->dropColumn(['numero_bon', 'statut', 'client']);
        });
    }
};
