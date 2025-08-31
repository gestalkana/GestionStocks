<!-- Filtres dynamiques modernisés -->
<div class="d-flex flex-wrap gap-2 align-items-end mb-3">

  <!-- Recherche -->
  <div class="flex-grow-1 min-w-200">
    <label for="searchInput" class="form-label mb-1 small">Recherche</label>
    <input type="text" id="searchInput" class="form-control form-control-sm" placeholder="🔍 Lot ou produit">
  </div>

  <!-- Mois -->
  <div class="flex-grow-1 min-w-150">
    <label for="monthFilter" class="form-label mb-1 small">Mois</label>
    <select id="monthFilter" class="form-select form-select-sm">
      <option value="">Tous les mois</option>
      @foreach (range(1, 12) as $m)
        <option value="{{ $m }}" {{ $m == now()->month ? 'selected' : '' }}>
          {{ ucfirst(\Carbon\Carbon::create()->month($m)->locale('fr')->translatedFormat('F')) }}
        </option>
      @endforeach
    </select>
  </div>

  <!-- Magasin -->
  <div class="flex-grow-1 min-w-150">
    <label for="entrepotFilter" class="form-label mb-1 small">Magasin</label>
    <select id="entrepotFilter" class="form-select form-select-sm">
      <option value="">Tous les magasins</option>
      @foreach ($entrepots as $e)
        <option value="{{ $e->id }}">{{ $e->nom }}</option>
      @endforeach
    </select>
  </div>

  <!-- Utilisateur -->
  <div class="flex-grow-1 min-w-150">
    <label for="userFilter" class="form-label mb-1 small">Utilisateur</label>
    <select id="userFilter" class="form-select form-select-sm">
      <option value="me" selected>Moi</option>
      <option value="autre">Autre</option>
      <option value="all">Tous</option>
    </select>
  </div>

  <!-- Groupe de boutons -->
<div class="d-flex flex-column align-items-start">
  <label class="form-label mb-1 invisible">Actions</label>
  <!-- Réinitaliser -->
  <div class="d-flex gap-1">
    <button class="btn btn-outline-secondary btn-sm" id="resetFilters" title="Réinitialiser les filtres">
      <i class="bi bi-repeat"></i>
    </button>
    <!-- Impression -->
    <button id="btnImprimer" type="button" class="btn btn-primary btn-sm" title="Imprimer">
      <i class="bi bi-printer"></i>
    </button>
  </div>
</div>

</div>
