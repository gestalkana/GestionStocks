<?php

namespace Database\Factories;

use Illuminate\Database\Eloquent\Factories\Factory;
use App\Models\StocksEntrees;

/**
 * @extends \Illuminate\Database\Eloquent\Factories\Factory<\App\Models\Stocks_Sorties>
 */
class StocksSortiesFactory extends Factory
{
    /**
     * Define the model's default state.
     *
     * @return array<string, mixed>
     */
    public function definition(): array
    {
        // On prend une entrée existante
        $stockEntree = StocksEntrees::inRandomOrder()->first();

        if (!$stockEntree) {
            // Si aucun stock_entree n'existe encore, on en crée un
            $stockEntree = StocksEntrees::factory()->create();
        }

        // On limite la quantité sortie pour ne pas dépasser le stock d'entrée
        $quantiteSortie = $this->faker->numberBetween(1, $stockEntree->quantite);

        return [
            'produit_id' => $stockEntree->produit_id,
            'stock_entree_id' => $stockEntree->id,
            'quantite' => $quantiteSortie,
            'date_sortie' => $this->faker->dateTimeBetween(
                $stockEntree->date_entree, // min = date d’entrée
                'now' // max = aujourd’hui
            ),
            'motif' => $this->faker->sentence(),
            'numero_bon' => strtoupper($this->faker->bothify('BON-####')),
            'statut' => $this->faker->randomElement(['brouillon','validé','annulé']),
            'client' => $this->faker->name(),
            'entrepot_id' => $stockEntree->entrepot_id,
            'user_id' => 1,
            //'user_id' => \App\Models\User::inRandomOrder()->first()?->id,
        ];
    }
    // Méthode personnalisée pour créer plusieurs lignes avec le même numero_bon
    public function withMultipleProducts(int $count = 3)
    {
        $numeroBon = strtoupper($this->faker->bothify('BON-####'));

        return tap($this, function () use ($count, $numeroBon) {
            for ($i = 0; $i < $count; $i++) {
                \App\Models\StocksSorties::factory()->create([
                    'numero_bon' => $numeroBon,
                ]);
            }
        });
    }
}
