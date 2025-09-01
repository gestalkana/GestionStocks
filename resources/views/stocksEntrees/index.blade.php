@extends('layouts.app')

@section('title', 'Entrées de Stock')
@section('Page-title', 'Entrées de Stock' )

@section('content')
<div class="container-fluid py-2">
    <!-- En-tête -->
    <div class="d-flex justify-content-between align-items-center mb-2">
        <h5 class="mb-0">
            <i class="bi bi-box-arrow-in-down"></i> Entrées en Stock
        </h5>
        <button class="btn btn-sm btn-primary" type="button" data-bs-toggle="collapse" data-bs-target="#formCollapse">
            <i class="bi bi-plus-circle me-1"></i> Ajouter une entrée
        </button>
    </div>
    <!-- Formulaire d'ajout d'Entree de stock - Formulaire Collapse -->
    @include('stocksEntrees.create')
    <!-- Filtres -->
    @include('stocksEntrees.filtreEntree')
    <!-- La liste des entrées à mettre à jour dynamiquement -->
    <div id="zoneImpression" class="card shadow-sm border-0">
        <div class="card-header bg-light d-flex align-items-center">
            <i class="bi bi-clock-history me-2"></i>
            <h5 class="mb-0">Historique des entrées</h5>
        </div>
        <div class="table-responsive" id="stocksEntreesTable">
             <!-- Tableau des entrées -->
            @include('stocksEntrees.listeStocksEntrees')
        </div>
    </div>
</div>
@include('stocksEntrees.modalEdition')
@include('stocksEntrees.modalAjoutMagasin')
@endsection
