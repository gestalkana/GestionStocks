 <!-- Formulaire Collapse -->
    <!-- Formulaire Collapse -->
<div class="collapse mb-3" id="formCollapse">
    <div class="card border-0 shadow-sm">
        <div class="card-body p-3">
            <!-- Bouton Ajouter un magasin -->
            <div class="d-flex justify-content-end mb-2">
                <button type="button" class="btn btn-sm btn-outline-primary" data-bs-toggle="modal" data-bs-target="#ajouterMagasinModal">
                    <i class="bi bi-plus-lg me-1"></i> Ajouter un magasin
                </button>
            </div>

            <!-- Formulaire d'entrée -->
            <form id="createStocksEntreesForm" method="POST" action="{{ route('stocksEntrees.store') }}" data-module="stocks-entrees-form">
                @csrf
                <div class="row g-2">
                    <!-- Magasin -->
                    <div class="col-sm-6 col-md-8">
                        <label class="form-label form-label-sm mb-1">Magasin</label>
                        <select name="entrepot_id" class="form-select form-select-sm" required>
                            <option value="">-- Sélectionner un magasin --</option>
                            @foreach ($entrepots as $entrepot)
                                <option value="{{ $entrepot->id }}">{{ $entrepot->nom }}</option>
                            @endforeach
                        </select>
                    </div>

                    <!-- Date d'entrée -->
                    <div class="col-sm-6 col-md-4">
                        <label class="form-label form-label-sm mb-1">Date d'entrée</label>
                        <input type="date" name="date_entree" class="form-control form-control-sm" value="{{ date('Y-m-d') }}" required>
                    </div>

                    <!-- Produit -->
                    <div class="col-6 col-md-3">
                        <label class="form-label form-label-sm mb-1">Produit</label>
                        <select name="produit_id" id="produitSelect" class="form-select form-select-sm" required>
                            <option value="">-- Sélectionner --</option>
                            @foreach ($produits as $produit)
                                <option value="{{ $produit->id }}" data-unite="{{ $produit->uniteMesure->nom ?? 'Non défini' }}">
                                    {{ $produit->nom }}
                                </option>
                            @endforeach
                        </select>
                    </div>

                    <!-- Quantité -->
                    <div class="col-6 col-md-2">
                        <label class="form-label form-label-sm mb-1">Quantité</label>
                        <input type="number" name="quantite" class="form-control form-control-sm" required>
                    </div>

                    <!-- Unité -->
                    <div class="col-6 col-md-2">
                        <label class="form-label form-label-sm mb-1">Unité</label>
                        <input type="text" id="uniteInput" class="form-control form-control-sm" readonly>
                    </div>

                    <!-- Fournisseur -->
                    <div class="col-6 col-md-3">
                        <label class="form-label form-label-sm mb-1">Fournisseur (optionnel)</label>
                        <select name="fournisseur_id" class="form-select form-select-sm">
                            <option value="">-- Aucun --</option>
                            @foreach ($fournisseurs as $fournisseur)
                                <option value="{{ $fournisseur->id }}">{{ $fournisseur->nom }}</option>
                            @endforeach
                        </select>
                    </div>

                    <!-- Date d’expiration -->
                    <div class="col-md-2">
                        <label class="form-label form-label-sm mb-1">Date d’expiration</label>
                        <input type="date" name="date_expiration" class="form-control form-control-sm" value="{{ date('Y-m-d') }}" required>
                    </div>

                    <!-- Commentaire & bouton -->
                    <div class="col-12 d-flex flex-column flex-md-row align-items-start align-items-md-end justify-content-between mt-2">
                        <div class="w-100 me-md-2 mb-2 mb-md-0">
                            <label class="form-label form-label-sm mb-1">Commentaire (optionnel)</label>
                            <input type="text" name="commentaire" class="form-control form-control-sm" placeholder="Ajouter un commentaire si nécessaire...">
                        </div>
                        <div class="text-end">
                            <button type="submit" class="btn btn-sm btn-success">
                                <i class="bi bi-save me-1"></i> Enregistrer
                            </button>
                        </div>
                    </div>
                </div>
            </form>
        </div>
    </div>
</div>
