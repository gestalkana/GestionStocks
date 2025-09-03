@extends('layouts.app')

@section('title', 'Détails du Lot Entrée')
@section('Page-title', 'Détails du Lot Entrée')

@section('content')
    <div class="d-flex justify-content-between align-items-center mb-4">
        <a href="{{ route('stocksEntrees.index') }}" class="btn btn-sm btn-secondary d-flex align-items-center" aria-label="Retour à la liste des lots">
            <i class="bi bi-arrow-left me-2"></i> Retour à la liste
        </a>
        <div class="d-flex justify-content-between">
            <button id="btnImprimer" type="button" class="btn btn-primary d-flex align-items-center" title="Imprimer cette page" aria-label="Imprimer">
                <i class="bi bi-printer me-2"></i> Imprimer
            </button>
        </div>
    </div>


    {{-- Informations du lot d'entrée --}}
    <div class="card shadow-sm mb-5">
        <div class="card-header bg-light d-flex justify-content-between align-items-center">
            <h5 class="mb-0">Informations du Lot Entrée</h5>
            <div class="d-flex align-items-center">
                <!-- Modification -->
                <button type="button"
                    class="btn btn-warning btn-sm edit-entree-btn me-2"
                    data-id="{{ $stockEntree->id }}"
                    data-quantite="{{ $stockEntree->quantite }}"
                    data-date="{{ \Carbon\Carbon::parse($stockEntree->date_expiration)->format('Y-m-d') }}"
                    {{ $stockEntree->stocksSorties->count() > 0 ? 'disabled' : '' }}>
                  <i class="bi bi-pencil-square" title="Modifier"></i>
                </button>
                <!-- Suppression -->
                <form action="{{ route('stocksEntrees.destroy', $stockEntree->id) }}" method="POST" class="d-inline" onsubmit="return confirm('Confirmer la suppression ?')">
                    @csrf
                    @method('DELETE')
                    <button type="submit" class="btn btn-sm btn-outline-danger" title="Supprimer">
                        <i class="bi bi-trash"></i>
                    </button>
                </form>
            </div>
        </div>
        <div class="card-body">
            <div class="row g-3">
                <div class="col-md-4"><strong>Numéro de Lot :</strong> {{ $stockEntree->numero_lot }}</div>
                <div class="col-md-4"><strong>Produit :</strong> {{ $stockEntree->produit?->nom ?? '-' }}</div>
                <!-- <div class="col-md-4"><strong>Quantité :</strong> {{ number_format($stockEntree->quantite, 0, ',', ' ') }}</div> -->
                <div class="col-md-4"><strong>Quantité :</strong> <span id="quantite_affichee">{{ number_format($stockEntree->quantite, 0, ',', ' ') }}</span></div>

                <div class="col-md-4"><strong>Date d'entrée :</strong> {{ \Carbon\Carbon::parse($stockEntree->date_entree)->translatedFormat('d F Y') }}</div>
                <!-- <div class="col-md-4">
                    <strong>Date d'expiration :</strong> 
                    @if ($stockEntree->date_expiration)
                        {{ \Carbon\Carbon::parse($stockEntree->date_expiration)->translatedFormat('d F Y') }}
                    @else
                        <span class="badge bg-secondary">-</span>
                    @endif
                </div> -->
                <div class="col-md-4">
                  <strong>Date d'expiration :</strong>
                  <span id="expiration_affichee">
                    @if ($stockEntree->date_expiration)
                      {{ \Carbon\Carbon::parse($stockEntree->date_expiration)->translatedFormat('d F Y') }}
                    @else
                      <span class="badge bg-secondary">-</span>
                    @endif
                  </span>
                </div>

                <!-- <div class="col-md-4">
                    <strong>Stock restant :</strong> 
                    <span class="{{ ($stockEntree->quantite - $stockEntree->stocksSorties->sum('quantite')) <= 0 ? 'text-danger fw-bold' : '' }}">
                        {{ number_format($stockEntree->quantite - $stockEntree->stocksSorties->sum('quantite'), 0, ',', ' ') }}
                    </span>
                </div> -->
                <div class="col-md-4">
                    <strong>Stock restant :</strong>
                    <span id="stock_restant" data-total-sorties="{{ $stockEntree->stocksSorties->sum('quantite') }}"
                    class="{{ ($stockEntree->quantite - $stockEntree->stocksSorties->sum('quantite')) <= 0 ? 'text-danger fw-bold' : '' }}">
                    {{ number_format($stockEntree->quantite - $stockEntree->stocksSorties->sum('quantite'), 0, ',', ' ') }}
                    </span>
                </div>

                <div class="col-md-4"><strong>Entrepôt :</strong> {{ $stockEntree->entrepot?->nom ?? '-' }}</div>
                <div class="col-md-4"><strong>Utilisateur :</strong> {{ $stockEntree->user?->name ?? '-' }}</div>
            </div>
        </div>
    </div>

    {{-- Historique des sorties --}}
    <div class="card shadow-sm">
        <div class="card-header bg-light d-flex justify-content-between align-items-center">
            <h5 class="mb-0">Historique des Sorties pour ce Lot</h5>
            <span class="badge bg-info text-dark">{{ $stockEntree->stocksSorties->count() }} sortie{{ $stockEntree->stocksSorties->count() > 1 ? 's' : '' }}</span>
        </div>
        <div class="table-responsive">
            <table class="table table-striped table-hover align-middle mb-0">
                <thead class="table-light">
                    <tr>
                        <th>Numéro de Bon</th>
                        <th>Date de Sortie</th>
                        <th>Quantité</th>
                        <th>Motif</th>
                        <th>Client</th>
                        <th>Utilisateur</th>
                        <th>Statut</th>
                    </tr>
                </thead>
                <tbody>
                    @forelse ($stockEntree->stocksSorties as $sortie)
                    <tr>
                        <td>{{ $sortie->numero_bon ?? '-' }}</td>
                        <td>{{ \Carbon\Carbon::parse($sortie->date_sortie)->translatedFormat('d F Y') }}</td>
                        <td>{{ number_format($sortie->quantite, 0, ',', ' ') }}</td>
                        <td>{{ $sortie->motif ?? '-' }}</td>
                        <td>{{ $sortie->client ?? '-' }}</td>
                        <td>{{ $sortie->user?->name ?? '-' }}</td>
                        <td>
                            @if($sortie->statut)
                                <span class="badge 
                                    {{ 
                                        $sortie->statut === 'validé' ? 'bg-success' : 
                                        ($sortie->statut === 'en attente' ? 'bg-warning text-dark' : 
                                        ($sortie->statut === 'annulé' ? 'bg-danger' : 'bg-secondary')) 
                                    }}">
                                    {{ ucfirst($sortie->statut) }}
                                </span>
                            @else
                                <span class="text-muted">-</span>
                            @endif
                        </td>
                    </tr>
                    @empty
                    <tr>
                        <td colspan="7" class="text-center text-muted py-4">
                            <i class="bi bi-inbox me-2 fs-4"></i> Aucune sortie enregistrée pour ce lot.
                        </td>
                    </tr>
                    @endforelse
                </tbody>
            </table>
        </div>
    </div>
<div id="zoneImpression" class="invisible">
 @include('stocksEntrees.zoneImpression')
</div>
 @include('stocksEntrees.modalEdition')
@endsection
