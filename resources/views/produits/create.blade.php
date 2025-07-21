@push('styles')
<style>
    :root { --accent: #0e7490; }

    /* Focus style pour les champs */
    .form-control:focus, .form-select:focus {
        border-color: var(--accent);
        box-shadow: 0 0 0 .2rem rgba(14, 116, 144, .2);
    }

    /* Icônes dans les champs */
    .input-icon {
        position: absolute;
        left: 0.5rem;
        top: 50%;
        transform: translateY(-50%);
        color: #64748b;
        font-size: 0.9rem;
        pointer-events: none;
    }

    /* Champs avec icône : padding à gauche */
    .with-icon input,
    .with-icon textarea,
    .with-icon select {
        padding-left: 2rem;
        font-size: 0.9rem;
        height: calc(1.8em + 0.75rem + 2px);
    }

    /* Container et card plus petits */
    .container.py-4 {
        max-width: 100% !important;
        padding: 0.5rem;
        margin: 0 auto;
    }

    .card {
        max-width: 500px;
        margin: 0 auto;
        border-radius: 0.5rem;
        box-shadow: 0 0.125rem 0.25rem rgb(0 0 0 / 0.075);
    }

    .card-header {
        background-color: white;
        border-bottom: 1px solid #eee;
        padding: 0.5rem 1rem;
    }

    .card-header h2 {
        font-size: 1rem;
        margin: 0;
    }

    .card-body {
        padding: 0.75rem !important;
    }

    label.form-label {
        font-size: 0.85rem;
        margin-bottom: 0.25rem;
    }

    .row.g-4 {
        gap: 0.5rem;
    }

    .btn {
        font-size: 0.875rem;
        padding: 0.375rem 0.75rem;
    }
</style>
@endpush

<!-- Formulaire de création de produit -->
<div class="row mb-4">
    <div class="card border-0 shadow-sm rounded-4">
        <div class="card-header">
            <h4>
                <i class="bi bi-box-seam text-accent me-2"></i>
                Nouveau produit
            </h4>
        </div>

        <div class="card-body">
            <form id="createProductForm" action="{{ route('produits.store') }}" method="POST" enctype="multipart/form-data">
                @csrf

                <div class="row g-4">
                    <div class="col-md-6">
                        {{-- Nom du produit --}}
                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-tag input-icon"></i>
                            <label class="form-label" for="nom">Nom du produit</label>
                            <input type="text" id="nom" name="nom" class="form-control"
                                   placeholder="Ex. : Clé USB 32 Go" required value="{{ old('nom') }}">
                        </div>

                        {{-- Code produit (SKU) --}}
                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-upc input-icon"></i>
                            <label class="form-label" for="code_produit">Référence (SKU)</label>
                            <input type="text" id="code_produit" name="code_produit" class="form-control"
                                   placeholder="ABC-N‑1234" required value="{{ old('code_produit') }}">
                        </div>

                        {{-- Catégorie --}}
                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-tags input-icon"></i>
                            <label class="form-label" for="categorie_id">Catégorie</label>
                            <select id="categorie_id" name="categorie_id" class="form-select" required>
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
                        {{-- Prix vente --}}
                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-currency-dollar input-icon"></i>
                            <label class="form-label" for="prix_unitaire">
                                Prix unitaire en Ar (vente)
                            </label>
                            <input type="number" step="0.01" min="0" id="prix_unitaire" name="prix_unitaire"
                                   class="form-control" placeholder="0.00" required value="{{ old('prix_unitaire') }}">
                        </div>

                        {{-- Prix d'achat  --}}
                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-currency-dollar input-icon"></i>
                            <label class="form-label" for="prix_achat">
                                Prix d'achat en Ar
                            </label>
                            <input type="number" min="0" id="prix_achat" name="prix_achat"
                            class="form-control" placeholder="0.00" 
                            value="{{ old('prix_achat') }}">
                        </div>
                        
                        {{-- Unité de mesure --}}
                        <div class="position-relative with-icon mb-2 gap-2">
                            <i class="bi bi-box-seam input-icon"></i> {{-- Icône --}}
                            <label class="form-label" for="unite_mesure_id" >
                                Unité de mesure
                            </label>
    
                            <div class="input-group">
                                <select id="unite_mesure_id" name="unite_mesure_id" class="form-select">
                                    <option value="">-- Sélectionnez une unité --</option>
                                    @foreach($uniteMesure as $unite)
                                        <option value="{{ $unite->id }}" {{ old('unite_mesure_id') == $unite->id ? 'selected' : '' }}>
                                            {{ $unite->nom }} ({{ $unite->symbole }})
                                        </option>
                                    @endforeach
                                </select>
                                <button 
                                    class="btn btn-outline-primary" 
                                    type="button" 
                                    data-bs-toggle="modal" 
                                    data-bs-target="#modalAjouterUnite"
                                    title="Ajouter une nouvelle unité">
                                    <i class="bi bi-plus-circle"></i>
                                </button>
                            </div>
                        </div>
                    </div>

                    {{-- Description --}}
                    <div class="col-12">
                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-text-left input-icon"></i>
                            <label class="form-label" for="description">Description</label>
                            <textarea id="description" name="description" rows="3"
                                      class="form-control"
                                      placeholder="Détails, spécifications, etc.">{{ old('description') }}</textarea>
                        </div>
                    </div>
                </div>

                <div class="d-flex justify-content-around gap-2 pt-3">
                    <a href="{{ route('produits.index') }}" class="btn btn-secondary">
                        <i class="bi bi-arrow-left"></i> Annuler
                    </a>
                    <button type="submit" class="btn btn-primary">
                        <i class="bi bi-save me-1"></i> Enregistrer
                    </button>
                </div>
            </form>
        </div>
    </div>
</div>