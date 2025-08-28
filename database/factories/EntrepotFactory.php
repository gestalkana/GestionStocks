<?php

namespace Database\Factories;

use Illuminate\Database\Eloquent\Factories\Factory;

/**
 * @extends \Illuminate\Database\Eloquent\Factories\Factory<\App\Models\Entrepot>
 */
class EntrepotFactory extends Factory
{
    /**
     * Define the model's default state.
     *
     * @return array<string, mixed>
     */
    public function definition(): array
    {
          return [
            'nom' => 'Entrepot ' . $this->faker->city(),
            'emplacement' => $this->faker->address(),
        ];
    }
}
