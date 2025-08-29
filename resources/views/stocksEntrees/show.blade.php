@extends('layouts.app')

@section('title', 'Détails du Lot Entrée')
@section('Page-title', 'Détails du Lot Entrée')

@section('content')
    <!-- Bouton retour -->
    <a href="{{ route('stocksEntrees.index') }}" class="btn btn-sm btn-secondary mb-3">
        <i class="bi bi-arrow-left"></i> Retour à la liste
    </a>

    <!-- Informations du lot d'entrée -->
    <div class="card shadow-sm mb-4">
        <div class="card-header bg-light">
            <h5 class="mb-0">Informations du Lot Entrée</h5>
        </div>
        <div class="card-body">
            <div class="row g-3">
                <div class="col-md-4"><strong>Numéro de Lot :</strong> {{ $stockEntree->numero_lot }}</div>
                <div class="col-md-4"><strong>Produit :</strong> {{ $stockEntree->produit?->nom ?? '-' }}</div>
                <div class="col-md-4"><strong>Quantité :</strong> {{ $stockEntree->quantite }}</div>
                <div class="col-md-4"><strong>Date d'entrée :</strong> {{ \Carbon\Carbon::parse($stockEntree->date_entree)->format('d/m/Y') }}</div>
                <div class="col-md-4"><strong>Date d'expiration :</strong> {{ $stockEntree->date_expiration ? \Carbon\Carbon::parse($stockEntree->date_expiration)->format('d/m/Y') : '-' }}</div>
                <div class="col-md-4"><strong>Stock restant :</strong> {{ $stockEntree->quantite - $stockEntree->stocksSorties->sum('quantite') }}</div>
                <div class="col-md-4"><strong>Entrepôt :</strong> {{ $stockEntree->entrepot?->nom ?? '-' }}</div>
                <div class="col-md-4"><strong>Utilisateur :</strong> {{ $stockEntree->user?->name ?? '-' }}</div>
            </div>
        </div>
    </div>

    <!-- Historique des sorties pour ce lot -->
    <div class="card shadow-sm">
        <div class="card-header bg-light">
            <h5 class="mb-0">Historique des Sorties pour ce Lot</h5>
        </div>
        <div class="table-responsive">
            <table class="table table-striped align-middle mb-0">
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
                            <td>{{ \Carbon\Carbon::parse($sortie->date_sortie)->format('d/m/Y') }}</td>
                            <td>{{ $sortie->quantite }}</td>
                            <td>{{ $sortie->motif ?? '-' }}</td>
                            <td>{{ $sortie->client ?? '-' }}</td>
                            <td>{{ $sortie->user?->name ?? '-' }}</td>
                            <td>{{ $sortie->statut ?? '-' }}</td>
                        </tr>
                    @empty
                        <tr>
                            <td colspan="7" class="text-center text-muted py-4">
                                <i class="bi bi-inbox me-2 fs-5"></i> Aucune sortie enregistrée pour ce lot.
                            </td>
                        </tr>
                    @endforelse
                </tbody>
            </table>
        </div>
    </div>
@endsection
