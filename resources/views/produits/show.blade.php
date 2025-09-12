{{-- resources/views/produits/show.blade.php --}}
@extends('layouts.app')

@section('title', 'Détails du produit')
@section('Page-title', 'Détails du produit')

@section('content')
<div class="card shadow-sm mb-4 small">
    <div class="card-header bg-cardProduit text-white d-flex justify-content-between align-items-center py-2">
        <h6 class="mb-0"><i class="bi bi-box-seam me-2"></i>Produit : {{ $produit->nom }} </h6>

        <div class="d-flex align-items-center">
            <!-- Bouton Retour -->
            <a href="{{ route('produits.index') }}" class="btn btn-light btn-sm me-2" title="Retour">
                <i class="bi bi-arrow-left"></i>
            </a>
            <!-- Bouton Modification -->
            <button class="btn btn-warning btn-sm edit-produit-btn me-2"
                    data-id="{{ $produit->id }}"
                    data-nom="{{ $produit->nom }}"
                    data-code="{{ $produit->code_produit }}"
                    data-prix-achat="{{ $produit->prix_achat }}"
                    data-prix-vente="{{ $produit->prix_unitaire }}"
                    data-description="{{ $produit->description }}"
                    data-unite-id="{{ $produit->UniteMesure->id ?? ''  }}">
                <i class="bi bi-pencil-square" title="Modifier"></i>
            </button>

            <!-- Bouton Suppression -->
            <form action="{{ route('produits.destroy', $produit->id) }}"
                  method="POST"
                  class="d-inline delete-produit-form"
                  data-produit-id="{{ $produit->id }}"
                  data-produit-nom="{{ $produit->nom }}">
                @csrf
                @method('DELETE')
                <button type="button"
                        class="btn btn-danger btn-sm">
                    <i class="bi bi-trash"></i>
                </button>
            </form>
        </div>
    </div>
    <div class="card-body">
        <div class="row g-2">
            <!-- Code produit -->
            <div class="col-md-4">
                <div class="form-floating">
                    <input type="text" readonly class="form-control form-control-sm" id="code_produit" value="{{ $produit->code_produit }}">
                    <label for="code_produit" class="fw-semibold">Code produit</label>
                </div>
            </div>

            <!-- Nom -->
            <div class="col-md-4">
                <div class="form-floating">
                    <input type="text" readonly class="form-control form-control-sm" id="nom" value="{{ $produit->nom }}">
                    <label for="nom" class="fw-semibold">Nom</label>
                </div>
            </div>

            <!-- Catégorie -->
            <div class="col-md-4">
                <div class="form-floating">
                    <input type="text" readonly class="form-control form-control-sm" id="categorie" value="{{ $produit->categorie->nom }}">
                    <label for="categorie" class="fw-semibold">Catégorie</label>
                </div>
            </div>

            <!-- Quantité -->
            <div class="col-md-4">
                <div class="form-floating">
                    <input type="number" readonly class="form-control form-control-sm" id="quantite" value="{{ $quantiteTotaleStock }}">
                    <label for="quantite" class="fw-semibold">Quantité en stock</label>
                </div>
            </div>

            <!-- Prix de vente -->
            <div class="col-md-4">
                <div class="form-floating">
                    <input type="number" readonly class="form-control form-control-sm" id="prix_unitaire" value="{{ $produit->prix_unitaire }}">
                    <label for="prix_unitaire" class="fw-semibold">Prix de vente</label>
                </div>
            </div>

            <!-- Prix d'achat -->
            <div class="col-md-4">
                <div class="form-floating">
                    <input type="number" readonly class="form-control form-control-sm" id="prix_achat" value="{{ $produit->prix_achat }}">
                    <label for="prix_achat" class="fw-semibold">Prix d'achat</label>
                </div>
            </div>

            <!-- Description -->
            <div class="col-md-8">
                <div class="form-floating">
                    <textarea readonly class="form-control form-control-sm" id="description" style="height: 50px;">{{ $produit->description }}</textarea>
                    <label for="description" class="fw-semibold">Description</label>
                </div>
            </div>

            <!-- Unité de Mesure -->
            <div class="col-md-4">
                <div class="form-floating">
                    <input type="text" readonly class="form-control form-control-sm" id="unite_mesure" value="{{ $produit->UniteMesure?->nom }}">
                    <label for="prix_achat" class="fw-semibold">Unité de Mesure</label>
                </div>
            </div>

        </div>
    </div>
</div>

<div>
    <h6 class="mb-2"><i class="bi bi-stack me-2"></i>Stocks disponibles</h6>
    <div class="table-responsive">
        <table class="table table-bordered table-sm align-middle table-hover">
            <thead class="table-primary text-center small">
                <tr>
                    <th class="text-start">Fournisseur</th>
                    <th>Numéro de Lot</th>
                    <th>Quantité Entree</th>
                    <th>Quantité restante</th>
                    <th>Date d'entrée</th>
                    <th>Date d'expiration</th>
                    <th>Date du dernier sortie</th>
                </tr>
            </thead>
            <tbody class="small">
                @forelse ($lotsDisponibles as $entree)
                    <tr>
                       
                        <td class="text-break">{{ $entree->fournisseur->nom ?? 'N/A' }}</td>
                        <td class="text-center">{{ $entree->numero_lot ?? 'N/A' }}</td>
                        <td class="text-center">
                            <span class="badge bg-secondary fs-6">
                                
                            {{ $entree->quantite }}
                            </span>
                        </td>
                        <td class="text-center">
                            <span class="badge bg-info fs-6">{{ intval($entree->quantite_restante) }}</span>
                        </td>
                        
                        <td class="text-center">
                            {{ \Carbon\Carbon::parse($entree->date_entree)->format('d/m/Y') }}
                        </td>
                        <td class="text-center">
                            {{ \Carbon\Carbon::parse($entree->date_expiration)->format('d/m/Y') }}
                        </td><td class="text-center">
                            {{ $entree->date_derniere_sortie ? \Carbon\Carbon::parse($entree->date_derniere_sortie)->format('d/m/Y') : 'Aucune sortie' }}

                        </td>
                    </tr>
                @empty
                    <tr>
                        <td colspan="7" class="text-center text-muted">Aucun lot disponible</td>
                    </tr>
                @endforelse
            </tbody>
        </table>
    </div>
</div>
@include('produits.modalEdition')
@include('produits.modalSuppression')
@endsection
