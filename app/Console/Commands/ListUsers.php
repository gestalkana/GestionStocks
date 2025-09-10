<?php

namespace App\Console\Commands;

use Illuminate\Console\Command;
use App\Models\User;

class ListUsers extends Command
{
    protected $signature = 'user:list';
    protected $description = 'Liste tous les utilisateurs avec leur nom et email';

    public function handle()
    {
        $users = User::select('name', 'email')->get();

        if ($users->isEmpty()) {
            $this->info('Aucun utilisateur trouvé.');
            return 0;
        }

        $this->table(
            ['Nom', 'Email'],
            $users->toArray()
        );

        return 0;
    }
}
