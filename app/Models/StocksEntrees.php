<?php

namespace App\Models;
use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class StocksEntrees extends Model
{
    use HasFactory;

    protected $fillable = [
        'produit_id', 
        'fournisseur_id', 
        'quantite', 
        'date_entree', 
        'date_expiration',
        'numero_lot',
        'quantite_disponible',
        'entrepot_id',
        'user_id'
    ];
    public function produit()
    {
        return $this->belongsTo(Produit::class);
    }
    public function stocksSorties()
{
    return $this->hasMany(StocksSorties::class, 'stock_entree_id');
}


    public function fournisseur()
    {
        return $this->belongsTo(Fournisseur::class);
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
