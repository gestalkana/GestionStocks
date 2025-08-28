<!-- Filtres dynamiques avec labels -->
<div class="row mb-3">
    <!-- Recherche -->
    <div class="col-md-3">
        <label for="searchInput" class="form-label">Recherche</label>
        <input type="text" id="searchInput" class="form-control" placeholder="Numéro de lot ou produit">
    </div>

    <!-- Mois -->
    <div class="col-md-2">
        <label for="monthFilter" class="form-label">Mois</label>
        <select id="monthFilter" class="form-select">
            <option value="">Tous les mois</option>
            @foreach (range(1, 12) as $m)
                <option value="{{ $m }}" {{ $m == now()->month ? 'selected' : '' }}>
                    {{ ucfirst(\Carbon\Carbon::create()->month($m)->locale('fr')->translatedFormat('F')) }}
                </option>
            @endforeach
        </select>
    </div>


    <!-- Magasin -->
    <div class="col-md-3">
        <label for="entrepotFilter" class="form-label">Magasin</label>
        <select id="entrepotFilter" class="form-select">
            <option value="">Tous les magasins</option>
            @foreach ($entrepots as $e)
                <option value="{{ $e->id }}">{{ $e->nom }}</option>
            @endforeach
        </select>
    </div>

    <!-- Utilisateur -->
    <div class="col-md-2">
        <label for="userFilter" class="form-label">Utilisateur</label>
        <select id="userFilter" class="form-select">
            <option value="me" selected>Moi</option>
            <option value="autre">Autre</option>
            <option value="all">Tous les utilisateurs</option>
            <!-- autres utilisateurs si besoin -->
        </select>
    </div>

    <!-- Réinitialiser -->
    <div class="col-md-1">
        <label class="form-label invisible">Réinitialiser</label>
        <button class="btn btn-outline-secondary w-100" id="resetFilters" title="Réinitialiser les filtres">
            <i class="bi bi-repeat"></i>
        </button>
    </div>

    <!-- Imprimer -->
    <div class="col-md-1">
        <label class="form-label invisible">Imprimer</label>
        <button id="btnImprimer" type="button" class="btn btn-primary w-100" title="Imprimer">
            <i class="bi bi-printer"></i>
        </button>
    </div>
</div>
