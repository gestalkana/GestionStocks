{{-- resources/views/produits/index.blade.php --}}
@extends('layouts.app')   {{-- ou le nom de ton layout principal --}}

@section('title', 'Produits')

@section('Page-title', 'Produits')

@section('content')

   <!--  <h1 class="h4 fw-semibold mb-3">
        <i class="bi bi-box-seam me-2"></i> Produits
    </h1> -->
    {{-- Sous‑onglets Bootstrap --}}
    <ul class="nav nav-tabs mb-4" id="produitTabs" role="tablist">
        <li class="nav-item" role="presentation">
            <button class="nav-link active" id="list-tab"
                    data-bs-toggle="tab" data-bs-target="#list"
                    type="button" role="tab" aria-controls="list" aria-selected="true">
                <i class="bi bi-card-list me-1"></i> Liste des produits
            </button>
        </li>
        <li class="nav-item" role="presentation">
            <button class="nav-link" id="add-tab"
                    data-bs-toggle="tab" data-bs-target="#add"
                    type="button" role="tab" aria-controls="add" aria-selected="false">
                <i class="bi bi-plus-circle me-1"></i> Ajouter un produit
            </button>
        </li>
        <li class="nav-item" role="presentation">
            <button class="nav-link" id="cat-tab"
                    data-bs-toggle="tab" data-bs-target="#categories"
                    type="button" role="tab" aria-controls="categories" aria-selected="false">
                <i class="bi bi-tags me-1"></i> Catégories
            </button>
        </li>
        <li class="nav-item" role="presentation">
            <button class="nav-link" id="imp-tab"
                    data-bs-toggle="tab" data-bs-target="#import"
                    type="button" role="tab" aria-controls="import" aria-selected="false">
                <i class="bi bi-upload me-1"></i> Import / Export
            </button>
        </li>
    </ul>

    {{-- Contenu des onglets --}}
    <div class="tab-content" id="produitTabsContent">
        {{-- 1. Liste des produits --}}
        <div class="tab-pane fade show active" id="list" role="tabpanel" aria-labelledby="list-tab">
            @include('produits.listeProduits')   
            {{-- → resources/views/produits/show.blade.php --}}
        </div>

        {{-- 2. Ajouter un produit --}}
        <div class="tab-pane fade" id="add" role="tabpanel" aria-labelledby="add-tab">
            @include('produits.create') {{-- → formulaire d’ajout --}}
        </div>

        {{-- 3. Catégories --}}
        <div class="tab-pane fade" id="categories" role="tabpanel" aria-labelledby="cat-tab">
            @include('produits.categories.index', ['categories' => $categories])
        </div>

        {{-- 4. Import/Export (facultatif) --}}
        <div class="tab-pane fade" id="import" role="tabpanel" aria-labelledby="imp-tab">
            @includeWhen(config('app.enable_import'), 'produits.partials.import-export')
            @unless(config('app.enable_import'))
                <p class="text-muted">Fonction non activée pour le moment.</p>
            @endunless
        </div>
    </div>


@endsection


@if(request('onglet') === 'categories')
    <script>
        document.addEventListener('DOMContentLoaded', () => {
            const catTab = document.getElementById('cat-tab');
            const catPane = new bootstrap.Tab(catTab);
            catPane.show();
        });
    </script>
@endif


