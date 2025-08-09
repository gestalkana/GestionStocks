@extends('layouts.app')

@section('title', 'Tableau de bord')

@section('Page-title')
    <i class="bi bi-speedometer2 me-2"></i> Tableau de bord
@endsection

@push('styles')
<style>
    .card-dashboard {
        background: #ffffff;
        border: none;
        border-radius: 0.75rem;
        box-shadow: 0 2px 6px rgba(0, 0, 0, 0.04);
        transition: all 0.2s ease-in-out;
    }

    .card-dashboard:hover {
        transform: translateY(-3px);
        box-shadow: 0 4px 12px rgba(0, 0, 0, 0.07);
    }

    .stat-number {
        font-size: 1.8rem;
        font-weight: 700;
        color: #0e7490;
        margin-bottom: 0.25rem;
    }

    .stat-label {
        font-size: 0.85rem;
        color: #6b7280;
    }

    .icon-circle {
        width: 40px;
        height: 40px;
        display: flex;
        align-items: center;
        justify-content: center;
        border-radius: 50%;
        font-size: 1.25rem;
    }

    .card-section {
        background: #ffffff;
        border-radius: 0.75rem;
        padding: 1.25rem;
        box-shadow: 0 2px 8px rgba(0, 0, 0, 0.05);
    }

    .alertes ul {
        max-height: 200px;
        overflow-y: auto;
        font-size: 0.9rem;
    }

    .btn-toggle {
        font-size: 0.75rem;
        padding: 0.25rem 0.5rem;
    }
</style>
@endpush

@section('content')
<div class="container-fluid py-2">
    {{-- Statistiques principales --}}
    <div class="row row-cols-1 row-cols-sm-2 row-cols-md-4 g-3 mb-3">
        <div class="col">
            <div class="card card-dashboard p-3">
                <div class="d-flex justify-content-between align-items-center">
                    <div>
                        <div class="stat-number">{{ $nbProduits }}</div>
                        <div class="stat-label">Produits</div>
                    </div>
                    <div class="icon-circle bg-primary-subtle text-primary">
                        <i class="bi bi-box-seam"></i>
                    </div>
                </div>
            </div>
        </div>

        <div class="col">
            <div class="card card-dashboard p-3">
                <div class="d-flex justify-content-between align-items-center">
                    <div>
                        <div class="stat-number">{{ $nbEntrees }}</div>
                        <div class="stat-label">Entrées</div>
                    </div>
                    <div class="icon-circle bg-success-subtle text-success">
                        <i class="bi bi-box-arrow-in-down"></i>
                    </div>
                </div>
            </div>
        </div>

        <div class="col">
            <div class="card card-dashboard p-3">
                <div class="d-flex justify-content-between align-items-center">
                    <div>
                        <div class="stat-number">{{ $nbSorties }}</div>
                        <div class="stat-label">Sorties</div>
                    </div>
                    <div class="icon-circle bg-danger-subtle text-danger">
                        <i class="bi bi-box-arrow-up"></i>
                    </div>
                </div>
            </div>
        </div>

        <div class="col">
            <div class="card card-dashboard p-3">
                <div class="d-flex justify-content-between align-items-center">
                    <div>
                        <div class="stat-number">{{ $nbFournisseurs }}</div>
                        <div class="stat-label">Fournisseurs</div>
                    </div>
                    <div class="icon-circle bg-warning-subtle text-warning">
                        <i class="bi bi-truck"></i>
                    </div>
                </div>
            </div>
        </div>
    </div>

    {{-- Graphique & Alertes --}}
    <div class="row g-4">
    <!-- Alerte -->
    <div class="col-12">
        <div class="card-section alertes">
            <h6 class="mb-2 d-flex justify-content-between align-items-center">
                <span>
                    <i class="bi bi-exclamation-circle text-danger me-2"></i>
                    Alertes ou ruptures ({{ $nbrRupture }})
                </span>
                <button class="btn btn-outline-danger btn-sm btn-toggle" type="button" data-bs-toggle="collapse" data-bs-target="#alertesCollapse" aria-expanded="false" aria-controls="alertesCollapse">
                    Voir +
                </button>
            </h6>

            <div class="collapse" id="alertesCollapse">
                <ul class="list-group list-group-flush">
                    @forelse($alertes as $alerte)
                        <li class="list-group-item d-flex align-items-center">
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

    <!-- Graphique -->
    <div class="col-12">
        <div class="card-section">
            <h6 class="mb-2">
                <i class="bi bi-graph-up-arrow me-2 text-primary"></i>Graphique des mouvements
            </h6>
            <canvas id="stockChart" height="90"></canvas>
            <script>
                window.chartData = {
                    labels: {!! json_encode($labels->toArray()) !!},
                    entrees: {!! json_encode($entrees->toArray()) !!},
                    sorties: {!! json_encode($sorties->toArray()) !!}
                };
            </script>
        </div>
    </div>
</div>

</div>
@endsection
