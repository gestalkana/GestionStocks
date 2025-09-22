@extends('layouts.app')

@section('title', 'Détails du fournisseur')
@section('Page-title', 'Détails du fournisseur')

@section('content')
<div class="card shadow-sm mb-4 small">
    <div class="card-header bg-cardProduit text-white d-flex justify-content-between align-items-center py-2">
        <h6 class="mb-0"><i class="bi bi-truck me-2"></i>Fournisseur : {{ $fournisseur->nom }} </h6>

        <div class="d-flex align-items-center">
            <!-- Bouton Retour -->
            <a href="{{ route('fournisseurs.index') }}" class="btn btn-light btn-sm me-2" title="Retour">
                <i class="bi bi-arrow-left"></i>
            </a>
            <!-- Bouton Modification -->
            <button type="button"
                        class="btn btn-sm btn-warning edit-fournisseur-btn me-2"
                        data-id="{{ $fournisseur->id }}"
                        data-nom="{{ $fournisseur->nom }}"
                        data-telephone="{{ $fournisseur->telephone }}"
                        data-email="{{ $fournisseur->email }}"
                        data-adresse="{{ $fournisseur->adresse }}"
                        data-statut="{{ $fournisseur->statut }}" title="Modifier">
                    <i class="bi bi-pencil" ></i>
            </button>
            <!-- Bouton Suppression -->
            <form action="{{ route('fournisseurs.destroy', $fournisseur->id) }}"
                  method="POST"
                  class="d-inline">
                @csrf
                @method('DELETE')
                <button type="submit" class="btn btn-danger btn-sm" onclick="return showSuccessAlert('delete', 'fournisseur')" title="Supprimer"  
                     @disabled($fournisseur->StocksEntrees->count() > 0)>
                    <i class="bi bi-trash"></i>
                </button>
            </form>
        </div>
    </div>

    <div class="card-body">
        <div class="row g-2">
            <!-- Nom -->
            <div class="col-md-6">
                <div class="form-floating">
                    <input type="text" readonly class="form-control form-control-sm" value="{{ $fournisseur->nom }}">
                    <label class="fw-semibold">Nom</label>
                </div>
            </div>

            <!-- Email -->
            <div class="col-md-6">
                <div class="form-floating">
                    <input type="email" readonly class="form-control form-control-sm" value="{{ $fournisseur->email }}">
                    <label class="fw-semibold">Email</label>
                </div>
            </div>

            <!-- Téléphone -->
            <div class="col-md-6">
                <div class="form-floating">
                    <input type="text" readonly class="form-control form-control-sm" value="{{ $fournisseur->telephone }}">
                    <label class="fw-semibold">Téléphone</label>
                </div>
            </div>

            <!-- Adresse -->
            <div class="col-md-6">
                <div class="form-floating">
                    <input type="text" readonly class="form-control form-control-sm" value="{{ $fournisseur->adresse }}">
                    <label class="fw-semibold">Adresse</label>
                </div>
            </div>

            <!-- Statut -->
            <div class="col-md-4">
                <div class="form-floating">
                    <input type="text" readonly class="form-control form-control-sm" value="{{ ucfirst($fournisseur->statut) }}">
                    <label class="fw-semibold">Statut</label>
                </div>
            </div>
        </div>
    </div>
</div>

<div>
    <h6 class="mb-2"><i class="bi bi-boxes me-2"></i>Produits fournis</h6>
    <div class="table-responsive">
        <table class="table table-bordered table-sm align-middle table-hover">
            <thead class="table-primary text-center small">
                <tr>
                    <th class="text-start">Produit</th>
                    <th>Numéro de Lot</th>
                    <th>Quantité Entrée</th>
                    <th>Quantité Restante</th>
                    <th>Date d'entrée</th>
                    <th>Date d'expiration</th>
                    <th>Date dernière sortie</th>
                </tr>
            </thead>
            <tbody class="small">
                @forelse ($fournisseur->StocksEntrees as $entree)
                    <tr>
                        <td class="text-break">{{ $entree->produit->nom ?? 'Produit inconnu' }}</td>
                        <td class="text-center">{{ $entree->numero_lot ?? 'N/A' }}</td>
                        <td class="text-center">
                            <span class="badge bg-secondary fs-6">{{ $entree->quantite }}</span>
                        </td>
                        <td class="text-center">
                            <span class="badge bg-info fs-6">{{ intval($entree->quantite_disponible) }}</span>
                        </td>
                        <td class="text-center">
                            {{ \Carbon\Carbon::parse($entree->date_entree)->format('d/m/Y') }}
                        </td>
                        <td class="text-center">
                            {{ \Carbon\Carbon::parse($entree->date_expiration)->format('d/m/Y') }}
                        </td>
                        <td class="text-center">
                            {{ $entree->date_derniere_sortie ? \Carbon\Carbon::parse($entree->date_derniere_sortie)->format('d/m/Y') : 'Aucune sortie' }}
                        </td>
                    </tr>
                @empty
                    <tr>
                        <td colspan="7" class="text-center text-muted">Aucun produit fourni</td>
                    </tr>
                @endforelse
            </tbody>
        </table>
    </div>
</div>
@include('fournisseurs.modalEdition')
@endsection
