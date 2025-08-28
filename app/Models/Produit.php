<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Produit extends Model
{
    /** @use HasFactory<\Database\Factories\ProduitFactory> */
    use HasFactory;

    protected $fillable = [
        'nom',
        'code_produit',
        'description',
        'prix_unitaire',
        'prix_achat',
        'categorie_id',
        'unite_mesure_id'
    ];

    public function uniteMesure()
    {
        return $this->belongsTo(UniteMesure::class);
    }
    public function categorie()
    {
        return $this->belongsTo(Categorie::class);
    }

    public function StocksEntrees()
    {
        return $this->hasMany(StocksEntrees::class);
    }

    public function StocksSorties()
    {
        return $this->hasMany(StocksSorties::class);
    }

}
