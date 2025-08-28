<div class="d-flex justify-content-between align-items-center mb-2">
  <h5>Liste des produits</h5>
  <div class="d-flex align-items-center gap-3">
    <div id="selection-count" class="text-muted small">0 sélectionné</div>
    <div class="btn-group">
      <button class="btn btn-outline-danger btn-sm" title="Supprimer les éléments sélectionnés">
        <i class="bi bi-trash"></i>
      </button>
      <button class="btn btn-outline-secondary btn-sm" title="Archiver les éléments sélectionnés">
        <i class="bi bi-archive"></i>
      </button>
      <button class="btn btn-outline-primary btn-sm" title="Exporter les éléments sélectionnés">
        <i class="bi bi-download"></i>
      </button>
    </div>
  </div>
</div>

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


<!-- Liste des produits -->
<div id="zoneImpression">
<table class="table table-sm table-striped table-hover align-middle">
  <thead class="table-primary">
    <tr>
      <th scope="col"><input type="checkbox" id="selectAll" /></th>
      <th scope="col">Référence</th>
      <th scope="col">Nom du produit</th>
      <th scope="col">Catégorie</th>
      <th scope="col">Quantité</th>
    <!--   <th scope="col">Prix d'achat</th>
      <th scope="col">Prix de vente</th> -->
      <th scope="col">Statut</th>
    </tr>
  </thead>
  <tbody id="produitsTableBody">
     @include('produits.tbodyProduit', ['produits' => $produits])
  </tbody>
</table>
</div>
  {{-- Boutons de pagination --}}
 <!-- Ajouter des liens de pagination -->
<div class="d-flex justify-content-center mb-4">

</div>