<?php

namespace App\Console\Commands;

use Illuminate\Console\Command;
use App\Models\User;

class DeleteUser extends Command
{
    protected $signature = 'user:delete {email} {--force}';
    protected $description = 'Supprimer un utilisateur par email';

    public function handle()
    {
        $email = $this->argument('email');
        $force = $this->option('force');

        $user = User::where('email', $email)->first();

        if (!$user) {
            $this->error("❌ Utilisateur avec l'email {$email} non trouvé.");
            return 1;
        }

        // Confirmation si l'option --force n'est pas utilisée
        if (!$force) {
            if (!$this->confirm("Êtes-vous sûr de vouloir supprimer l'utilisateur {$email} ?")) {
                $this->info("Opération annulée.");
                return 0;
            }
        }

        $user->delete();

        $this->info("✅ Utilisateur {$email} supprimé avec succès.");
        return 0;
    }
}
