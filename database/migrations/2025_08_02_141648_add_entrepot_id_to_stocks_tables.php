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
         Schema::table('stocks_entrees', function (Blueprint $table) {
            $table->foreignId('entrepot_id')->nullable()->constrained();
         });

        Schema::table('stocks_sorties', function (Blueprint $table) {
            $table->foreignId('entrepot_id')->nullable()->constrained();
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
       Schema::table('stocks_entrees', function (Blueprint $table) {
            $table->dropForeign(['entrepot_id']);
            $table->dropColumn('entrepot_id');
        });

        Schema::table('stocks_sorties', function (Blueprint $table) {
            $table->dropForeign(['entrepot_id']);
            $table->dropColumn('entrepot_id');
        });
    }
};
