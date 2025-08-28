<form method="GET" class="mb-3" id="filtreForm">
    <div class="row g-2 align-items-end">

        <!-- Recherche par numéro de bon -->
        <div class="col-md-3">
            <label for="filtreRecherche" class="form-label">Recherche</label>
            <input type="text" id="filtreRecherche" name="recherche" class="form-control"
                   placeholder="Recherche par N° Bon ou ordre">
        </div>

        <!-- Filtre par mois -->
        <div class="col-md-3">
            <label for="filtreMois" class="form-label">Mois</label>
            @php
                $moisSelectionne = request('mois', now()->month);
            @endphp

            <select id="filtreMois" name="mois" class="form-select">
                <option value="">Tous</option>
                @foreach(range(1, 12) as $mois)
                    <option value="{{ $mois }}" {{ $mois == $moisSelectionne ? 'selected' : '' }}>
                        {{ ucfirst(\Carbon\Carbon::create()->month($mois)->locale('fr')->translatedFormat('F')) }}
                    </option>
                @endforeach
            </select>
        </div>

        <!-- Filtre par statut -->
        <div class="col-md-2">
            <label for="filtreStatut" class="form-label">Statut</label>
            <select id="filtreStatut" name="statut" class="form-select">
                <option value="">-- Tous --</option>
                <option value="valide">Validé</option>
                <option value="brouillon">Brouillon</option>
                <!-- Ajoute d'autres statuts ici si besoin -->
            </select>
        </div>

        <!-- Filtre par utilisateur -->
        <div class="col-md-2">
            <label for="filtreUtilisateur" class="form-label">Utilisateur</label>
            <select id="filtreUtilisateur" name="utilisateur" class="form-select">
                <option value="moi" selected>Moi</option>
                <option value="autre">Autre</option>
                <option value="">Tous</option>
            </select>
        </div>

        <!-- Bouton Réinitialiser -->
        <div class="col-md-1">
            <button id="resetFiltres" type="button" class="btn btn-outline-secondary w-100" title="Réinitialiser">
                <i class="bi bi-arrow-repeat"></i>
            </button>
        </div>

        <!-- Bouton Imprimer -->
        <div class="col-md-1">
            <button id="btnImprimer" type="button" class="btn btn-primary w-100" title="Imprimer">
                <i class="bi bi-printer"></i>
            </button>
        </div>
    </div>
    
</form>
