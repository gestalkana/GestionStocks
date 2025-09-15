@extends('layouts.app')

@section('title', 'À propos')
@section('Page-title', 'À propos de l’application')

@push('styles')
<style>
    .about-card {
        background: #ffffff;
        border-radius: 0.75rem;
        box-shadow: 0 2px 8px rgba(0,0,0,0.05);
    }
    .about-card h4, .about-card h5 {
        font-weight: 600;
    }
    .about-card ul {
        padding-left: 1rem;
    }
    .about-card li {
        margin-bottom: 0.35rem;
    }
    .about-section-icon {
        font-size: 1.2rem;
        margin-right: 0.5rem;
        color: #0d6efd;
    }
</style>
@endpush

@section('content')
<div class="row justify-content-center">
    <div class="col-md-12 col-lg-10">

        <div class="card about-card border-0">
            <div class="card-body p-2">

                <h4 class="mb-2">
                    <i class="bi bi-box-seam me-2"></i> 
                    Application de gestion de stock
                </h4>

                <p class="text-muted small">
                    Cette application a été développée pour simplifier la gestion des stocks au sein d’une entreprise 
                    ou d’un entrepôt. Elle offre une visibilité claire sur les produits disponibles, les entrées 
                    et sorties de stock, ainsi que le suivi des fournisseurs et des opérations.
                </p>

                <hr>

                <h5 class="mt-3">
                    <i class="bi bi-person-workspace about-section-icon"></i> Développeur
                </h5>
                <ul class="list-unstyled small text-muted">
                    <li><strong>Nom :</strong> Gabriel Andriamahafaly INDRIANTSILAZO</li>
                    <li><strong>Poste :</strong> Lead développer chez <span class="fw-semibold">Zita Company</span></li>
                    <li><strong>Formation :</strong> Ingénieur en informatique – Spécialisé en bases de données et génie logiciel</li>
                    <li><strong>Email :</strong> gestalkana@gmail.com</li>
                    <li><strong>GitHub :</strong> <a href="https://github.com/gestalkana" target="_blank">github.com/gestalkana</a></li>
                    <li><strong>Phone :</strong> +261 34 48 795 09</li>                    
                </ul>

                <hr>

                <h5 class="mt-3">
                    <i class="bi bi-check2-square about-section-icon"></i> Fonctionnalités principales
                </h5>
                <ul class="small text-muted">
                    <li>📦 Gestion des produits (ajout, édition, suppression)</li>
                    <li>🤝 Gestion des fournisseurs (ajout, suivi et mise à jour)</li>
                    <li>🔄 Suivi des mouvements de stock (entrées/sorties)</li>
                    <li>⚠️ Alertes de stock faible et ruptures</li>
                    <li>📜 Historique complet des opérations</li>
                    <li>👥 Gestion des utilisateurs et rôles</li>
                </ul>

                <div class="text-end mb-4">
                    <a href="{{ route('home') }}" class="btn btn-outline-primary btn-sm">
                        <i class="bi bi-arrow-left"></i> Retour au tableau de bord
                    </a>
                </div>

            </div>
        </div>

    </div>
</div>
@endsection
