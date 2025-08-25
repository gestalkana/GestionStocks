@extends('layouts.app')

@section('title', 'Détails du Bon de Sortie')
@section('Page-title', 'Détails du Bon de Sortie')

@section('content')
    <!-- Bouton retour -->
    <a href="{{ route('stocksSorties.index') }}" class="btn btn-sm btn-secondary mb-3">
        <i class="bi bi-arrow-left"></i> Retour à la liste
    </a>

    <!-- Informations du bon -->
    <div class="card shadow-sm mb-4">
        <div class="card-header bg-light">
            <h5 class="mb-0">Informations du Bon de Sortie</h5>
        </div>
        <div class="card-body">
            <div class="row g-3">
                <div class="col-md-4"><strong>Numéro :</strong> {{ $bon->numero_bon }}</div>
                <div class="col-md-4"><strong>Date :</strong> {{ \Carbon\Carbon::parse($bon->date_sortie)->format('d/m/Y') }}</div>
                <div class="col-md-4"><strong>Statut :</strong> {{ $bon->statut }}</div>
                <div class="col-md-4"><strong>Ordre N° :</strong> {{ $bon->numero_ordre ?? '-' }}</div>
                <div class="col-md-4"><strong>Client :</strong> {{ $bon->client ?? '-' }}</div>
                <div class="col-md-4"><strong>Utilisateur :</strong> {{ $bon->user?->name ?? '-' }}</div>
                <div class="col-md-4"><strong>Motif :</strong> {{ $bon->motif ?? '-' }}</div>

            </div>
        </div>
    </div>

    <!-- Tableau des produits -->
    <div class="card shadow-sm">
        <div class="card-header bg-light">
            <h5 class="mb-0">Produits sortis</h5>
        </div>
        <div class="table-responsive">
            <table class="table table-striped align-middle mb-0">
                <thead class="table-light">
                    <tr>
                        <th>Produit</th>
                        <th>Quantité</th>
                        <th>Numéro de Lot</th>
                        <th>Stock Avant</th>
                        <th>Stock Après</th>
                    </tr>
                </thead>
                <tbody>
                    @forelse ($sorties as $ligne)
                        <tr>
                            <td>{{ $ligne->produit?->nom ?? '-' }}</td>
                            <td>{{ $ligne->quantite }}</td>
                            <td>{{ $ligne->stocksEntrees?->numero_lot ?? 'N/A' }}</td>
                            <td>{{ $ligne->stock_avant ?? '-' }}</td>
                            <td>{{ $ligne->stock_apres ?? '-' }}</td>
                        </tr>
                    @empty
                        <tr>
                            <td colspan="5" class="text-center text-muted py-4">
                                <i class="bi bi-inbox me-2 fs-5"></i> Aucun produit sorti.
                            </td>
                        </tr>
                    @endforelse
                </tbody>
            </table>
        </div>
    </div>
@endsection
