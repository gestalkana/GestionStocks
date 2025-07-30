@extends('layouts.app')

@section('title', 'Tableau de bord')

@section('Page-title')
    <i class="bi bi-speedometer2 me-2"></i> Tableau de bord
@endsection

@push('styles')
<style>
    .card-dashboard {
        background: #f8fafc;
        border: none;
        border-left: 4px solid var(--bs-primary);
        box-shadow: 0 0.2rem 0.6rem rgba(0,0,0,0.05);
        transition: transform 0.2s;
    }

    .card-dashboard:hover {
        transform: translateY(-2px);
    }

    .stat-number {
        font-size: 2rem;
        font-weight: bold;
        color: #0e7490;
    }

    .stat-label {
        font-size: 0.9rem;
        color: #64748b;
    }
</style>
@endpush

@section('content')
<div class="container-fluid py-4">
    {{-- Statistiques principales --}}
    <div class="row g-4 mb-4">
        <div class="col-md-3">
            <div class="card card-dashboard p-3">
                <div class="d-flex justify-content-between align-items-center">
                    <div>
                        <div class="stat-number">{{ $nbProduits }}</div>
                        <div class="stat-label">Produits enregistrées</div>
                    </div>
                    <i class="bi bi-box-seam fs-1 text-primary"></i>
                </div>
            </div>
        </div>

        <div class="col-md-3">
            <div class="card card-dashboard p-3">
                <div class="d-flex justify-content-between align-items-center">
                    <div>
                        <div class="stat-number">{{ $nbEntrees }}</div>
                        <div class="stat-label">Entrées récentes</div>
                    </div>
                    <i class="bi bi-box-arrow-in-down fs-1 text-success"></i>
                </div>
            </div>
        </div>

        <div class="col-md-3">
            <div class="card card-dashboard p-3">
                <div class="d-flex justify-content-between align-items-center">
                    <div>
                        <div class="stat-number">{{ $nbSorties }}</div>
                        <div class="stat-label">Sorties récentes</div>
                    </div>
                    <i class="bi bi-box-arrow-up fs-1 text-danger"></i>
                </div>
            </div>
        </div>

        <div class="col-md-3">
            <div class="card card-dashboard p-3">
                <div class="d-flex justify-content-between align-items-center">
                    <div>
                        <div class="stat-number">{{ $nbFournisseurs }}</div>
                        <div class="stat-label">Fournisseurs actifs</div>
                    </div>
                    <i class="bi bi-truck fs-1 text-warning"></i>
                </div>
            </div>
        </div>
    </div>

    {{-- Graphique / Historique / Alertes --}}
    <div class="row g-4">
        <div class="col-md-8">
            <div class="card shadow-sm rounded-4 p-4 h-100">
                <h5 class="mb-3">Graphique des mouvements</h5>
                {{-- Ici, intègre un graphique avec Chart.js, Livewire ou autre --}}
                <canvas id="stockChart" height="180"></canvas>
            </div>
        </div>

        <div class="col-md-4">
            <div class="card shadow-sm rounded-4 p-4 h-100">
                <h5 class="mb-3">Alertes ou ruptures</h5>
                <ul class="list-group list-group-flush">
                    @forelse($alertes as $alerte)
                        <li class="list-group-item">
                            <i class="bi bi-exclamation-triangle-fill text-danger me-2"></i>
                            {{ $alerte }}
                        </li>
                    @empty
                        <li class="list-group-item text-muted">Aucune alerte pour le moment.</li>
                    @endforelse
                </ul>
            </div>
        </div>
    </div>
</div>
@endsection
@push('scripts')
<script>
document.addEventListener('DOMContentLoaded', function () {
    const ctx = document.getElementById('stockChart');

    if (ctx) {
        new Chart(ctx, {
            type: 'bar',
            data: {
                labels: {!! json_encode($labels) !!},
                datasets: [
                    {
                        label: 'Entrées',
                        data: {!! json_encode($entrees) !!},
                        backgroundColor: 'rgba(14, 116, 144, 0.7)',
                    },
                    {
                        label: 'Sorties',
                        data: {!! json_encode($sorties) !!},
                        backgroundColor: 'rgba(239, 68, 68, 0.7)',
                    }
                ]
            },
            options: {
                responsive: true,
                plugins: {
                    legend: {
                        position: 'top',
                    },
                    title: {
                        display: true,
                        text: 'Historique des stocks sur 7 jours'
                    }
                },
                scales: {
                    y: {
                        beginAtZero: true
                    }
                }
            }
        });
    }
});
</script>
@endpush

