@push('styles')
<link href="{{ asset('css/formulaire-produits.css') }}" rel="stylesheet">
@endpush
<!-- Formulaire de création de produit (version réduite) -->
<div class="row mb-3">
    <div class="card border-0 shadow-sm rounded-4 p-2">
        <div class="card-header py-2">
            <h5 class="mb-0">
                <i class="bi bi-box-seam text-accent me-2"></i>
                Nouveau produit
            </h5>
        </div>

        <div class="card-body p-2">
            <form id="createProductForm" action="{{ route('produits.store') }}" method="POST" enctype="multipart/form-data">
                @csrf

                <div class="row g-3">
                    <div class="col-md-6">
                        <!-- Nom du produit -->
                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-tag input-icon"></i>
                            <label class="form-label small" for="nom">Nom du produit</label>
                            <input type="text" id="nom" name="nom" class="form-control form-control-sm"
                                   placeholder="Ex. : Clé USB 32 Go" required value="{{ old('nom') }}">
                        </div>

                        <!-- Code produit -->
                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-upc input-icon"></i>
                            <label class="form-label small" for="code_produit">Référence (SKU)</label>
                            <input type="text" id="code_produit" name="code_produit" class="form-control form-control-sm"
                                   placeholder="ABC-N‑1234" required value="{{ old('code_produit') }}">
                        </div>

                        <!-- Catégorie -->
                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-tags input-icon"></i>
                            <label class="form-label small" for="categorie_id">Catégorie</label>
                            <select id="categorie_id" name="categorie_id" class="form-select form-select-sm" required>
                                <option value="" disabled {{ old('categorie_id') ? '' : 'selected' }}>Choisir…</option>
                                @foreach($categories as $categorie)
                                    <option value="{{ $categorie->id }}" {{ old('categorie_id') == $categorie->id ? 'selected' : '' }}>
                                        {{ $categorie->nom }}
                                    </option>
                                @endforeach
                            </select>
                        </div>
                    </div>

                    <div class="col-md-6">
                        <!-- Prix vente -->
                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-currency-dollar input-icon"></i>
                            <label class="form-label small" for="prix_unitaire">Prix unitaire en Ar (vente)</label>
                            <input type="number" step="0.01" min="0" id="prix_unitaire" name="prix_unitaire"
                                   class="form-control form-control-sm" placeholder="0.00" required value="{{ old('prix_unitaire') }}">
                        </div>

                        <!-- Prix achat -->
                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-currency-dollar input-icon"></i>
                            <label class="form-label small" for="prix_achat">Prix d'achat en Ar</label>
                            <input type="number" min="0" id="prix_achat" name="prix_achat"
                                   class="form-control form-control-sm" placeholder="0.00" value="{{ old('prix_achat') }}">
                        </div>

                        <!-- Unité de mesure -->
                        <div class="position-relative with-icon mb-2 gap-2">
                            <i class="bi bi-box-seam input-icon"></i>
                            <label class="form-label small" for="unite_mesure_id">Unité de mesure</label>
                            <div class="input-group input-group-sm">
                                <select id="unite_mesure_id" name="unite_mesure_id" class="form-select form-select-sm">
                                    <option value="">-- Sélectionnez une unité --</option>
                                    @foreach($uniteMesure as $unite)
                                        <option value="{{ $unite->id }}" {{ old('unite_mesure_id') == $unite->id ? 'selected' : '' }}>
                                            {{ $unite->nom }} ({{ $unite->symbole }})
                                        </option>
                                    @endforeach
                                </select>
                                <button 
                                    class="btn btn-outline-primary btn-sm" 
                                    type="button" 
                                    data-bs-toggle="modal" 
                                    data-bs-target="#modalAjouterUnite"
                                    title="Ajouter une nouvelle unité">
                                    <i class="bi bi-plus-circle"></i>
                                </button>
                            </div>
                        </div>
                    </div>

                    <!-- Description -->
                    <div class="col-12">
                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-text-left input-icon"></i>
                            <label class="form-label small" for="description">Description</label>
                            <textarea id="description" name="description" rows="2"
                                      class="form-control form-control-sm"
                                      placeholder="Détails, spécifications, etc.">{{ old('description') }}</textarea>
                        </div>
                    </div>
                </div>

                <div class="d-flex justify-content-end gap-2 pt-2">
                    <a href="{{ route('produits.index') }}" class="btn btn-secondary btn-sm">
                        <i class="bi bi-arrow-left"></i> Annuler
                    </a>
                    <button type="submit" class="btn btn-primary btn-sm">
                        <i class="bi bi-save me-1"></i> Enregistrer
                    </button>
                </div>
            </form>
        </div>
    </div>
</div>
