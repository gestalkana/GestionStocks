<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;

class UniteMesureSeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        UniteMesure::factory(5)->create();
    }
}
