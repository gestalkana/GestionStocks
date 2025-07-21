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
        Schema::create('unite_mesures', function (Blueprint $table) {
            $table->id();
            $table->string('code')->unique();   // ex : 'piece', 'kg', 'l'
            $table->string('nom');              // ex : 'Pièce', 'Kilogramme', 'Litre'
            $table->string('symbole')->nullable(); // ex : 'pc', 'kg', 'L'
            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::dropIfExists('unite_mesures');
    }
};
