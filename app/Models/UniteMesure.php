<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class UniteMesure extends Model
{
    // Table associée (si nom différent du pluriel par défaut)
    //protected $table = 'unites_mesure';

    // Champs qu'on peut remplir en masse
    protected $fillable = [
        'code',
        'nom',
        'symbole',
    ];

    /**
     * Relation : une unité de mesure peut concerner plusieurs produits
     */
    public function produits()
    {
        return $this->hasMany(Produit::class, 'unite_mesure_id');
    }
}
