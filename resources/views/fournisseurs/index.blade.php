@extends('layouts.app')

@section('title', 'Fournisseurs')
@section('Page-title', 'Fournisseurs')

@section('content')
<div class="container-fluid mt-4">
    <div class="d-flex justify-content-between align-items-center mb-3">
        <h5><i class="bi bi-truck me-2"></i> Liste des Fournisseurs</h5>	
        <!-- Bouton de Création Fournisseur -->
        <button type="button" class="btn btn-sm btn-success" data-bs-toggle="modal" 
                data-bs-target="#modalAjoutFournisseur">
          <i class="bi bi-plus-circle me-1"></i> Ajouter un fournisseur
        </button>
    </div>

    <div class="row row-cols-1 row-cols-md-3 row-cols-lg-4 g-4">
        @forelse ($fournisseurs as $fournisseur)
        <div class="col">
            <div class="card h-100 shadow-sm border-0">
                <div class="card-body bg-outline-primary">
                    <h5 class="card-title fw-bold">{{ $fournisseur->nom }}</h5>

                    <p class="mb-1">
                        <i class="bi bi-telephone me-1 text-muted"></i>
                        <span class="text-muted">{{ $fournisseur->telephone ?? 'Non renseigné' }}</span>
                    </p>
                    <p class="mb-1">
                        <i class="bi bi-envelope me-1 text-muted"></i>
                        <span class="text-muted">{{ $fournisseur->email ?? 'Non renseigné' }}</span>
                    </p>
                    <p class="mb-1">
                        <i class="bi bi-globe2 me-1 text-muted"></i>
                        <span class="text-muted">{{ $fournisseur->adresse ?? '-' }}</span>
                    </p>

                    <div class="mt-2">
                        <span class="badge bg-{{ $fournisseur->statut == 'actif' ? 'success' : 'secondary' }}">
                            {{ ucfirst($fournisseur->statut) }}
                        </span>
                        @if($fournisseur->type)
                        <span class="badge bg-info text-dark">
                        	{{-- $fournisseur->type --}}
                        </span>
                        @endif
                    </div>
                </div>

                <div class="card-footer bg-cardProduit border-top-0 d-flex justify-content-evenly">
                    <a href="{{ route('fournisseurs.show', $fournisseur->id) }}" class="btn btn-sm btn-primary">
                        <i class="bi bi-eye"></i>
                    </a>
                    <!-- Bouton Modification -->
                    <button type="button"
                        class="btn btn-sm btn-warning edit-fournisseur-btn"
                        data-id="{{ $fournisseur->id }}"
                        data-nom="{{ $fournisseur->nom }}"
                        data-telephone="{{ $fournisseur->telephone }}"
                        data-email="{{ $fournisseur->email }}"
                        data-adresse="{{ $fournisseur->adresse }}"
                        data-statut="{{ $fournisseur->statut }}"
                    >
                        <i class="bi bi-pencil"></i>
                    </button>
                    <!-- Bouton Suppression -->
                    <form action="{{ route('fournisseurs.destroy', $fournisseur->id) }}" method="POST">
                        @csrf
                        @method('DELETE')
                        <button class="btn btn-sm btn-danger" onclick="return showSuccessAlert('delete', 'fournisseur')" title="Supprimer"  
                             @disabled($fournisseur->StocksEntrees->count() > 0)>
                            <i class="bi bi-trash"></i>
                        </button>
                    </form>
                </div>
            </div>
        </div>
        @empty
        <div class="col-12 text-center text-muted">
            Aucun fournisseur enregistré.
        </div>
        @endforelse
    </div>
	
    <div class="d-flex justify-content-center mt-4">
        {{ $fournisseurs->links('pagination::bootstrap-4') }}
    </div>
</div>
@include('fournisseurs.modalCreation')
@include('fournisseurs.modalEdition')
@endsection
