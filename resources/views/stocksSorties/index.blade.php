@extends('layouts.app')
@section('title', 'Sorties de Stock')
@section('Page-title', 'Sorties de Stock' )

@section('content')
<div class="container-fluid py-4">
    <!-- En-tête -->
    <div class="d-flex justify-content-between align-items-center mb-4">
        <h2 class="mb-0">
            <i class="bi bi-box-arrow-up me-2"></i> Sorties de Stock
        </h2>
        <button class="btn btn-danger" type="button" data-bs-toggle="collapse" data-bs-target="#formCollapse">
            <i class="bi bi-dash-circle me-1"></i> Enregistrer une sortie
        </button>
    </div>

    <!-- Formulaire Collapse -->
    <div class="collapse mb-4" id="formCollapse">
        <div class="card border-0 shadow-sm">
            <div class="card-body">
                <form action="{{ route('stocksSorties.store') }}" method="POST">
                    @csrf
                    <div class="row g-3">
                        <div class="col-md-4">
                            <label class="form-label">Produit</label>
                            <select name="produit_id" class="form-select" required>
                                @foreach ($produits as $produit)
                                    <option value="{{ $produit->id }}">{{ $produit->nom }}</option>
                                @endforeach
                            </select>
                        </div>
                        <div class="col-md-2">
                            <label class="form-label">Quantité</label>
                            <input type="number" name="quantite" class="form-control" required>
                        </div>
                        <div class="col-md-3">
                            <label class="form-label">Destination</label>
                            <input type="text" name="destination" class="form-control" placeholder="Service, client..." required>
                        </div>
                        <div class="col-md-3">
                            <label class="form-label">Date de sortie</label>
                            <input type="date" name="date_sortie" class="form-control" value="{{ date('Y-m-d') }}" required>
                        </div>
                        <div class="col-12 text-end mt-3">
                            <button type="submit" class="btn btn-success">
                                <i class="bi bi-save me-1"></i> Enregistrer
                            </button>
                        </div>
                    </div>
                </form>
            </div>
        </div>
    </div>

    <!-- Tableau des sorties -->
    <div class="card shadow-sm border-0">
        <div class="card-header bg-light d-flex align-items-center">
            <i class="bi bi-clock-history me-2"></i>
            <h5 class="mb-0">Historique des sorties</h5>
        </div>
        <div class="table-responsive">
            <table class="table table-hover align-middle mb-0">
                <thead class="table-light">
                    <tr>
                        <th>#Ref</th>
                        <th>Produit</th>
                        <th>Quantité</th>
                        <th>Date</th>
                        <th>Stock Avant</th>
                        <th>Stock Après</th>
                        <th>Destination</th>
                        <th>Utilisateur</th>
                        <th class="text-end">Actions</th>
                    </tr>
                </thead>
                <tbody>
                    @forelse ($stocksSorties as $sortie)
                        <tr>
                            <td>#ST{{ str_pad($sortie->id, 4, '0', STR_PAD_LEFT) }}</td>
                            <td>{{ $sortie->produit->nom }}</td>
                            <td>{{ $sortie->quantite }}</td>
                            <td>{{ \Carbon\Carbon::parse($sortie->date_sortie)->format('d/m/Y') }}</td>
                            <td>{{ $sortie->stock_avant }}</td>
                            <td>{{ $sortie->stock_apres }}</td>
                            <td>{{ $sortie->destination }}</td>
                            <td>{{ $sortie->user->name }}</td>
                            <td class="text-end">
                                <a href="{{ route('stocksSorties.show', $sortie->id) }}" class="btn btn-sm btn-outline-secondary me-1" title="Voir">
                                    <i class="bi bi-eye"></i>
                                </a>
                                <a href="{{ route('stocksSorties.edit', $sortie->id) }}" class="btn btn-sm btn-outline-warning me-1" title="Modifier">
                                    <i class="bi bi-pencil-square"></i>
                                </a>
                                <form action="{{ route('stocksSorties.destroy', $sortie->id) }}" method="POST" class="d-inline" onsubmit="return confirm('Confirmer la suppression ?')">
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
                            <td colspan="9" class="text-center text-muted py-4">
                                <i class="bi bi-inbox me-2 fs-5"></i> Aucune sortie enregistrée.
                            </td>
                        </tr>
                    @endforelse
                </tbody>
            </table>
        </div>
    </div>
</div>
@endsection
