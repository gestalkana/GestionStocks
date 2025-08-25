<?php

namespace Database\Factories;

use Illuminate\Database\Eloquent\Factories\Factory;
use Illuminate\Support\Str;

/**
 * @extends \Illuminate\Database\Eloquent\Factories\Factory<\App\Models\Produit>
 */
class ProduitFactory extends Factory
{
    /**
     * Define the model's default state.
     *
     * @return array<string, mixed>
     */
    public function definition(): array
    {
        return [
            'nom' => $this->faker->word(),
            'description' => $this->faker->sentence(),
            'prix_unitaire' => $this->faker->randomFloat(2, 10, 500),
            'prix_achat' => $this->faker->randomFloat(2, 5, 300),
            'categorie_id' => \App\Models\Categorie::inRandomOrder()->first()?->id,
            'unite_mesure_id' => \App\Models\UniteMesure::inRandomOrder()->first()?->id,
            'code_produit' => strtoupper(Str::random(10)),
        ];
    }
}
