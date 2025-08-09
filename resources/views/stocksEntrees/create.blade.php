 <!-- Formulaire Collapse -->
    <div class="collapse mb-4" id="formCollapse">
        <div class="card border-0 shadow-sm">
            <div class="card-body">
                <form id="createStocksEntreesForm" method="POST" 
                      action="{{ route('stocksEntrees.store') }}">
                    @csrf
                    <div class="row g-3">
                        <!-- Sélection du magasin -->
                        <div class="col-md-12">
                            <label class="form-label">Magasin</label>
                           <div class="input-group">
                                <select name="magasin_id" class="form-select" required>
                                    <option value="">-- Sélectionner un magasin --</option>
                                    @foreach ($magasins as $magasin)
                                        <option value="{{ $magasin->id }}">{{ $magasin->nom }}</option>
                                    @endforeach
                                </select>
                                <button type="button" class="btn btn-outline-primary" data-bs-toggle="modal" data-bs-target="#ajouterMagasinModal">
                                    Ajouter un nouveau
                                </button>
                            </div>
                        </div>

                        <!-- Saisie du produit, quantité, unité, fournisseur, date -->
                        <div class="col-md-3">
                            <label class="form-label">Produit</label>
                            <select name="produit_id" id="produitSelect" class="form-select" required>
                                <option value="">-- Sélectionner --</option>
                                @foreach ($produits as $produit)
                                    <option 
                                        value="{{ $produit->id }}" 
                                        data-unite="{{ $produit->uniteMesure->nom ?? 'Non défini' }}">
                                        {{ $produit->nom }}
                                    </option>
                                @endforeach
                            </select>
                        </div>

                        <div class="col-md-2">
                            <label class="form-label">Quantité</label>
                            <input type="number" name="quantite" class="form-control" required>
                        </div>

                        <div class="col-md-2">
                            <label class="form-label">Unité</label>
                            <input type="text" id="uniteInput" class="form-control" readonly>
                        </div>

                        <div class="col-md-3">
                            <label class="form-label">Fournisseur (optionnel)</label>
                            <select name="fournisseur_id" class="form-select">
                                <option value="">-- Aucun --</option>
                                @foreach ($fournisseurs as $fournisseur)
                                    <option value="{{ $fournisseur->id }}">{{ $fournisseur->nom }}</option>
                                @endforeach
                            </select>
                        </div>

                        <div class="col-md-2">
                            <label class="form-label">Date d’expiration</label>
                            <input type="date" name="date_expiration" class="form-control" value="{{ date('Y-m-d') }}" required>
                        </div>

                        <!-- Ligne Commentaire + Bouton -->
                        <div class="col-md-12 d-flex align-items-end justify-content-between mt-3">
                            <!-- Commentaire (optionnel) -->
                            <div class="me-3 flex-grow-1">
                                <label class="form-label">Commentaire (optionnel)</label>
                                <input type="text" name="commentaire" class="form-control" placeholder="Ajouter un commentaire si nécessaire...">
                            </div>

                            <!-- Bouton -->
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
