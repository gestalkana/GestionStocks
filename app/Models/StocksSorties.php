<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class StocksSorties extends Model
{
    use HasFactory;

    protected $fillable = ['produit_id', 'quantite', 'date_sortie', 'motif'];

    public function produit()
    {
        return $this->belongsTo(Produit::class);
    }
    public function user()
{
    return $this->belongsTo(User::class);
}

}
