<?php

namespace App\Console\Commands;

use Illuminate\Console\Command;
use Illuminate\Support\Str;
use App\Models\UniteMesure;

class SeedUnitesMesure extends Command
{
    protected $signature = 'seed:unites-mesure';
    protected $description = 'Insère les unités de mesure de base';

    public function handle()
    {
        $unites = [
            ['nom' => 'kilogramme', 'symbole' => 'kg'],
            ['nom' => 'litre', 'symbole' => 'L'],
            ['nom' => 'mètre', 'symbole' => 'm'],
            ['nom' => 'centimètre', 'symbole' => 'cm'],
            ['nom' => 'pièce', 'symbole' => 'pcs'],
            ['nom' => 'carton', 'symbole' => 'ctn'],
            ['nom' => 'boite', 'symbole' => 'bt'],
            ['nom' => 'sac (gony)', 'symbole' => 'gny'],
            ['nom' => 'paquet', 'symbole' => 'pqt'],
        ];

        foreach ($unites as $unite) {
            $exists = UniteMesure::where('nom', $unite['nom'])
                        ->orWhere('symbole', $unite['symbole'])
                        ->exists();

            if (!$exists) {
                UniteMesure::create([
                    'code' => strtoupper(Str::random(5)),
                    'nom' => $unite['nom'],
                    'symbole' => $unite['symbole'],
                ]);

                $this->info("Unité ajoutée : {$unite['nom']}");
            } else {
                $this->warn("Déjà existante : {$unite['nom']}");
            }
        }


       // $this->info('Unités de mesure insérées avec succès.');
    }
}
