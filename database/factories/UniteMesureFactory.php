<?php

namespace Database\Factories;

use Illuminate\Database\Eloquent\Factories\Factory;
use Illuminate\Support\Str;

/**
 * @extends \Illuminate\Database\Eloquent\Factories\Factory<\App\Models\UniteMesure>
 */
class UniteMesureFactory extends Factory
{
    /**
     * Define the model's default state.
     *
     * @return array<string, mixed>
     */
    public function definition(): array
    {
               $unites = [
            ['nom' => 'kilogramme', 'symbole' => 'kg'],
            ['nom' => 'litre', 'symbole' => 'L'],
            ['nom' => 'mètre', 'symbole' => 'm'],
            ['nom' => 'centimètre', 'symbole' => 'cm'],
            ['nom' => 'pièce', 'symbole' => 'pcs'],
        ];

        $unite = $this->faker->randomElement($unites);

        return [
            'code' => strtoupper(Str::random(5)),
            'nom' => $unite['nom'],
            'symbole' => $unite['symbole'],
        ];
    }
}
