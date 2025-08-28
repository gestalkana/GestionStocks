<?php

namespace App\Providers;

use Illuminate\Support\ServiceProvider;
use Carbon\Carbon;

class AppServiceProvider extends ServiceProvider
{
    /**
     * Register any application services.
     */
    public function register(): void
    {
        //
    }

    /**
     * Bootstrap any application services.
     */
    public function boot(): void
    {
        Carbon::setLocale('fr'); // pour les noms de mois/jours
        setlocale(LC_TIME, 'fr_FR.UTF-8'); // pour strftime (si jamais utilisé)
    }
}
