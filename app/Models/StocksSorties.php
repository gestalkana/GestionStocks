<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class StocksSorties extends Model
{
    use HasFactory;

    protected $fillable = [
        'produit_id',
        'stock_entree_id',
        'quantite',
        'date_sortie',
        'motif',
        'user_id',
        'numero_bon',
        'numero_ordre',
        'statut',
        'client',
    ];

    public function produit()
    {
        return $this->belongsTo(Produit::class);
    }
    public function stocksEntrees()
    {
        return $this->belongsTo(StocksEntrees::class, 'stock_entree_id');
    }

    public function user()
    {
        return $this->belongsTo(User::class);
    }
    public function entrepot()
    {
        return $this->belongsTo(Entrepot::class);
    }


}
