 <!-- Formulaire Collapse -->
    <div class="collapse mb-4" id="formCollapse">
        <div class="card border-0 shadow-sm">
            <div class="card-body">
                <!-- Bouton pour ouvrir le modal "Ajouter un magasin" -->
                <div class="mb-3 text-end">
                    <button type="button" class="btn btn-outline-primary" data-bs-toggle="modal" data-bs-target="#ajouterMagasinModal">
                        <i class="bi bi-plus-lg"></i> Ajouter un magasin
                    </button>
                </div>

                <!-- Formulaire d'entrée de stock -->
                <form id="createStocksEntreesForm" method="POST" action="{{ route('stocksEntrees.store') }}" data-module="stocks-entrees-form">
                    @csrf
                    <div class="row g-3">
                        <!-- Sélection du magasin (entrepôt) -->
                        <div class="col-md-12">
                            <label class="form-label">Magasin</label>
                            <select name="entrepot_id" class="form-select" required>
                                <option value="">-- Sélectionner un magasin --</option>
                                @foreach ($entrepots as $entrepot)
                                    <option value="{{ $entrepot->id }}">{{ $entrepot->nom }}</option>
                                @endforeach
                            </select>
                        </div>

                        <!-- Produit -->
                        <div class="col-md-3">
                            <label class="form-label">Produit</label>
                            <select name="produit_id" id="produitSelect" class="form-select" required>
                                <option value="">-- Sélectionner --</option>
                                @foreach ($produits as $produit)
                                    <option value="{{ $produit->id }}" data-unite="{{ $produit->uniteMesure->nom ?? 'Non défini' }}">
                                        {{ $produit->nom }}
                                    </option>
                                @endforeach
                            </select>
                        </div>

                        <!-- Quantité -->
                        <div class="col-md-2">
                            <label class="form-label">Quantité</label>
                            <input type="number" name="quantite" class="form-control" required>
                        </div>

                        <!-- Unité -->
                        <div class="col-md-2">
                            <label class="form-label">Unité</label>
                            <input type="text" id="uniteInput" class="form-control" readonly>
                        </div>

                        <!-- Fournisseur -->
                        <div class="col-md-3">
                            <label class="form-label">Fournisseur (optionnel)</label>
                            <select name="fournisseur_id" class="form-select">
                                <option value="">-- Aucun --</option>
                                @foreach ($fournisseurs as $fournisseur)
                                    <option value="{{ $fournisseur->id }}">{{ $fournisseur->nom }}</option>
                                @endforeach
                            </select>
                        </div>

                        <!-- Date d’expiration -->
                        <div class="col-md-2">
                            <label class="form-label">Date d’expiration</label>
                            <input type="date" name="date_expiration" class="form-control" value="{{ date('Y-m-d') }}" required>
                        </div>

                        <!-- Commentaire + bouton submit -->
                        <div class="col-md-12 d-flex align-items-end justify-content-between mt-3">
                            <div class="me-3 flex-grow-1">
                                <label class="form-label">Commentaire (optionnel)</label>
                                <input type="text" name="commentaire" class="form-control" placeholder="Ajouter un commentaire si nécessaire...">
                            </div>
                            <div class="text-end">
                                <button type="submit" class="btn btn-success mt-4">
                                    <i class="bi bi-save me-1"></i> Enregistrer
                                </button>
                            </div>
                        </div>
                    </div>
                </form>
            </div>
        </div>
    </div>
