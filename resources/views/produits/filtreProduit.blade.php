<!-- Interface de recherche améliorée -->
<div class="d-flex flex-wrap gap-2 align-items-end mb-3">

  <!-- Champ de recherche -->
  <div class="flex-grow-1">
    <input type="text" id="filtreRecherche" class="form-control form-control-sm" placeholder="🔍 Nom ou catégorie...">
  </div>

  <!-- Filtre catégorie -->
  <div>
    <select id="filtreCategorie" class="form-select form-select-sm">
      <option value="">Toutes les catégories</option>
      @foreach ($categories as $cat)
        <option value="{{ $cat->id }}">{{ $cat->nom }}</option>
      @endforeach
    </select>
  </div>

  <!-- Filtre statut -->
  <div>
    <select id="filtreStatut" class="form-select form-select-sm">
      <option value="">Tous les statuts</option>
      <option value="disponible">Disponible</option>
      <option value="stock faible">Stock faible</option>
      <option value="rupture">Rupture</option>
    </select>
  </div>

  <!-- Filtre entrepôt -->
  <div>
    <select id="filtreEntrepot" class="form-select form-select-sm">
      <option value="">Tous les magasins</option>
      @foreach ($entrepots as $entrepot)
        <option value="{{ $entrepot->id }}">{{ $entrepot->nom }}</option>
      @endforeach
      <option value="sans_magasin">Non assigné</option>
    </select>
  </div>

  <!-- Bouton reset -->
  <div>
    <button id="resetFiltres" class="btn btn-outline-secondary btn-sm" title="Réinitialiser">
      <i class="bi bi-arrow-repeat"></i>
    </button>
  </div>

  <!-- Bouton imprimer -->
  <div>
    <button id="btnImprimer" class="btn btn-primary btn-sm" title="Imprimer">
      <i class="bi bi-printer"></i>
    </button>
  </div>
</div>
