<?php

namespace App\Console\Commands;

use Illuminate\Console\Command;
use App\Models\User;
use Illuminate\Support\Facades\Hash;

class ChangeUserPassword extends Command
{
    protected $signature = 'user:change-password {email} {password}';
    protected $description = 'Change the password of a user';

    public function handle()
    {
        $email = $this->argument('email');
        $newPassword = $this->argument('password');

        $user = User::where('email', $email)->first();

        if (!$user) {
            $this->error("Utilisateur avec l'email {$email} non trouvé.");
            return 1;
        }

        $user->password = Hash::make($newPassword);
        $user->save();

        $this->info("Mot de passe mis à jour pour l'utilisateur : {$email}");

        return 0;
    }
}
