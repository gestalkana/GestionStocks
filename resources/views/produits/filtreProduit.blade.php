<!-- option de recherche et de filtrage-->
<div class="row mb-3">
  <div class="col-md-4">
    <input type="text" id="filtreRecherche" class="form-control" placeholder="Rechercher par nom ou catégorie...">
  </div>
  <div class="col-md-2">
    <select id="filtreCategorie" class="form-select">
      <option value="">Toutes les catégories</option>
      @foreach ($categories as $cat)
        <option value="{{ $cat->id }}">{{ $cat->nom }}</option>
      @endforeach
    </select>
  </div>
  <div class="col-md-2">
    <select id="filtreStatut" class="form-select">
      <option value="">Tous les statuts</option>
      <option value="disponible">Disponible</option>
      <option value="stock faible">Stock faible</option>
      <option value="rupture">Rupture</option>
    </select>
  </div>
  <div class="col-md-2">
    <select id="filtreEntrepot" class="form-select">
      <option value="">Tous les magasins</option>
      @foreach ($entrepots as $entrepot)
        <option value="{{ $entrepot->id }}">{{ $entrepot->nom }}</option>
      @endforeach
      <option value="sans_magasin">Non assigné à un magasin</option>
    </select>
  </div>

  <div class="col-md-1">
    <button id="resetFiltres" class="btn btn-outline-secondary w-100" title="Réinitialiser">
     <i class="bi bi-arrow-repeat"></i>
    </button>
  </div>
  <div class="col-md-1">
    <button id="btnImprimer" class="btn btn-primary w-100" title="Imprimer">
        <i class="bi bi-printer"></i>
    </button>
  </div>
</div>