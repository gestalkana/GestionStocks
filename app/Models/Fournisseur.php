<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Fournisseur extends Model
{
    /** @use HasFactory<\Database\Factories\FournisseurFactory> */
    use HasFactory;

    protected $fillable = ['nom', 'email', 'telephone', 'adresse', 'statut'];

    public function StocksEntrees()
    {
        return $this->hasMany(StocksEntrees::class);
    }
}
