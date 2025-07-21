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
            $table->string('numero_lot')->nullable()->after('produit_id');
            $table->date('date_expiration')->nullable()->after('numero_lot');
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::table('stocks_entrees', function (Blueprint $table) {
            $table->dropColumn('numero_lot');
            $table->dropColumn('date_expiration');
        });
    }
};
