<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class StocksEntrees extends Model
{
    use HasFactory;

    protected $fillable = ['produit_id', 'fournisseur_id', 'quantite', 'date_entree'];

    public function produit()
    {
        return $this->belongsTo(Produit::class);
    }

    public function fournisseur()
    {
        return $this->belongsTo(Fournisseur::class);
}
