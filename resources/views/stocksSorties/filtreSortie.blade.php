<form method="GET" class="mb-3" id="filtreForm">
  <div class="d-flex flex-wrap gap-2 align-items-end">

    <!-- Recherche -->
    <div class="flex-grow-1 min-w-200">
      <label for="filtreRecherche" class="form-label small mb-1">Recherche</label>
      <input type="text" id="filtreRecherche" name="recherche" class="form-control form-control-sm"
             placeholder="🔍 N° Bon ou ordre">
    </div>

    <!-- Mois -->
    <div class="flex-grow-1 min-w-150">
      <label for="filtreMois" class="form-label small mb-1">Mois</label>
      <!--@php $moisSelectionne = request('mois', now()->month); @endphp
      <select id="filtreMois" name="mois" class="form-select form-select-sm">
        <option value="">Tous les mois</option>
        @foreach(range(1, 12) as $mois)
          <option value="{{ $mois }}" {{ $mois == $moisSelectionne ? 'selected' : '' }}>
            {{ ucfirst(\Carbon\Carbon::create()->month($mois)->locale('fr')->translatedFormat('F')) }}
          </option>
        @endforeach
      </select> -->
      <select id="filtreMois" name="mois" class="form-select form-select-sm">
      <option value="">Tous les mois</option>
      @foreach (range(1, 12) as $mois)
        <option value="{{ $mois }}" {{ $mois == now()->month ? 'selected' : '' }}>
          {{ ucfirst(\Carbon\Carbon::create()->month($mois)->locale('fr')->translatedFormat('F')) }}
        </option>
      @endforeach
    </select>
    </div>

    <!-- Statut -->
    <div class="flex-grow-1 min-w-150">
      <label for="filtreStatut" class="form-label small mb-1">Statut</label>
      <select id="filtreStatut" name="statut" class="form-select form-select-sm">
        <option value="">Tous</option>
        <option value="valide">Validé</option>
        <option value="brouillon">Brouillon</option>
      </select>
    </div>

    <!-- Utilisateur -->
    <div class="flex-grow-1 min-w-150">
      <label for="filtreUtilisateur" class="form-label small mb-1">Utilisateur</label>
      <select id="filtreUtilisateur" name="utilisateur" class="form-select form-select-sm">
        <option value="moi" selected>Moi</option>
        <option value="autre">Autre</option>
        <option value="">Tous</option>
      </select>
    </div>

    <!-- Groupe de boutons -->
    <div class="d-flex flex-column align-items-start flex-shrink-0">
      <label class="form-label small mb-1 invisible">Actions</label>
      <div class="d-flex gap-1">
        <button id="resetFiltres" type="button" class="btn btn-outline-secondary btn-sm" title="Réinitialiser">
          <i class="bi bi-arrow-repeat"></i>
        </button>
        <button id="btnImprimer" type="button" class="btn btn-primary btn-sm" title="Imprimer">
          <i class="bi bi-printer"></i>
        </button>
      </div>
    </div>

  </div>
</form>
