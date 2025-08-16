<?php

namespace App\Console\Commands;

use Illuminate\Console\Command;
use App\Models\StocksEntrees;
use Carbon\Carbon;

class GenerateNumeroLot extends Command
{
    // Signature de la commande
    protected $signature = 'stock:generate-lots';

    // Description
    protected $description = 'Génère les numéros de lot pour tous les produits selon le format LOT-M{ENTREPOTID}-{MMYY}-{N}';

    public function handle()
    {
        $this->info('Début de la génération des numéros de lot...');

        // Récupérer toutes les entrées triées par entrepôt et date
        $lots = StocksEntrees::orderBy('entrepot_id')
            ->orderBy('date_entree')
            ->get()
            ->groupBy(function($item) {
                // Convertir la date en Carbon pour pouvoir formater
                $date = Carbon::parse($item->date_entree);
                // Grouper par entrepôt + mois/année
                return $item->entrepot_id . '-' . $date->format('my');
            });

        foreach ($lots as $group) {
            $sequence = 1;

            foreach ($group as $entree) {
                $date = Carbon::parse($entree->date_entree);
                $moisAnnee = $date->format('my');

                $entree->numero_lot = 'LOT-M' 
                    . str_pad($entree->entrepot_id, 2, '0', STR_PAD_LEFT)
                    . '-' . $moisAnnee
                    . '-' . str_pad($sequence, 3, '0', STR_PAD_LEFT);

                $entree->save();
                $sequence++;
            }
        }

        $this->info('Numéros de lot générés avec succès !');
        return 0;
    }
}
