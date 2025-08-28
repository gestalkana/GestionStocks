<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Entrepot extends Model
{
    /** @use HasFactory<\Database\Factories\EntrepotFactory> */
    use HasFactory;

    protected $fillable = ['nom', 'emplacement'];

    // Relations

    public function stocksEntrees()
    {
        return $this->hasMany(StocksEntrees::class);
    }

    public function stocksSorties()
    {
        return $this->hasMany(StocksSorties::class);
    }
}
