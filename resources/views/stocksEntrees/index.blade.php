@extends('layouts.app')

@section('title', 'Entrées de Stock')
@section('Page-title', 'Entrées de Stock' )

@section('content')
<div class="container-fluid py-4">
    <!-- En-tête -->
    <div class="d-flex justify-content-between align-items-center mb-4">
        <h2 class="mb-0">
            <i class="bi bi-box-seam-fill me-2"></i> Entrées en Stock
        </h2>
        <button class="btn btn-primary" type="button" data-bs-toggle="collapse" data-bs-target="#formCollapse">
            <i class="bi bi-plus-circle me-1"></i> Ajouter une entrée
        </button>
    </div>
    <!-- Formulaire d'ajout d'Entree de stock - Formulaire Collapse -->
    @include('stocksEntrees.create')

    <!-- Tableau des entrées -->
    <div class="card shadow-sm border-0">
        <div class="card-header bg-light d-flex align-items-center">
            <i class="bi bi-clock-history me-2"></i>
            <h5 class="mb-0">Historique des entrées</h5>
        </div>
        <div class="table-responsive" id="stocksEntreesTable">
            <table class="table table-hover align-middle mb-0">
                <thead class="table-light">
                    <tr>
                        <th>#Ref</th>
                        <th>Produit</th>
                        <th>Quantité</th>
                        <th>Date d'entrée</th>
                        <th>Date d'expiration</th>
                        <th>Stock Avant</th>
                        <th>Stock Après</th>
                        <th>Utilisateur</th>
                        <th class="text-center">Actions</th>
                    </tr>
                </thead>
                <tbody>
                    @forelse ($stocksEntrees as $entree)
                        <tr>
                            <td>#MV{{ str_pad($entree->id, 4, '0', STR_PAD_LEFT) }}</td>
                            <td>{{ $entree->produit->nom }}</td>
                            <td>{{ $entree->quantite }}</td>
                            <td>{{ \Carbon\Carbon::parse($entree->date_entree)->format('d/m/Y') }}</td>
                            <td>{{ \Carbon\Carbon::parse($entree->date_expiration)->format('d/m/Y') }}</td>
                            <td>{{ $entree->stock_avant }}</td>
                            <td>{{ $entree->stock_apres }}</td>
                            <td>{{ $entree->user->name }}</td>
                            <td class="text-end">
                                <a href="{{ route('stocksEntrees.show', $entree->id) }}" class="btn btn-sm btn-outline-secondary me-1" title="Voir">
                                    <i class="bi bi-eye"></i>
                                </a>
                                <a href="{{ route('stocksEntrees.edit', $entree->id) }}" class="btn btn-sm btn-outline-warning me-1" title="Modifier">
                                    <i class="bi bi-pencil-square"></i>
                                </a>
                                <form action="{{ route('stocksEntrees.destroy', $entree->id) }}" method="POST" class="d-inline" onsubmit="return confirm('Confirmer la suppression ?')">
                                    @csrf
                                    @method('DELETE')
                                    <button type="submit" class="btn btn-sm btn-outline-danger" title="Supprimer">
                                        <i class="bi bi-trash"></i>
                                    </button>
                                </form>
                            </td>
                        </tr>
                    @empty
                        <tr>
                            <td colspan="8" class="text-center text-muted py-4">
                                <i class="bi bi-inbox me-2 fs-5"></i> Aucune entrée enregistrée.
                            </td>
                        </tr>
                    @endforelse
                </tbody>
            </table>
        </div>
    </div>
</div>
@endsection
