<?php

namespace Database\Factories;

use Illuminate\Database\Eloquent\Factories\Factory;

/**
 * @extends \Illuminate\Database\Eloquent\Factories\Factory<\App\Models\Stocks_Entrees>
 */
class StocksEntreesFactory extends Factory
{
    /**
     * Define the model's default state.
     *
     * @return array<string, mixed>
     */
    public function definition(): array
    {
        return [
            'produit_id' => \App\Models\Produit::inRandomOrder()->first()?->id,
            'fournisseur_id' => \App\Models\Fournisseur::inRandomOrder()->first()?->id,
            'quantite' => $this->faker->numberBetween(10, 1000),
            'date_entree' => $this->faker->date(),
            'numero_lot' => strtoupper($this->faker->bothify('LOT-####')),
            'date_expiration' => $this->faker->optional()->date(),
            'entrepot_id' => \App\Models\Entrepot::inRandomOrder()->first()?->id,
            'user_id' => 1, // à adapter selon le système d’auth
            //'user_id' => \App\Models\User::inRandomOrder()->first()?->id,
        ];
    }
}
