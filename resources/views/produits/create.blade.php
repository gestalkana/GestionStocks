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

<div class="row py-4">
    <div class="card border-0 shadow-sm rounded-4">
        <div class="card-header">
            <h4>
                <i class="bi bi-box-seam text-accent me-2"></i>
                Nouveau produit
            </h4>
        </div>

        <div class="card-body">
            <form action="/produits/store" method="POST" enctype="multipart/form-data">
                @csrf <!-- Ajoute cette ligne si tu es sous Laravel -->

                <div class="row g-4">
                    <div class="col-md-6">
                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-tag input-icon"></i>
                            <label class="form-label" for="name">Nom du produit</label>
                            <input type="text" id="name" name="name" class="form-control"
                                   placeholder="Ex. : Clé USB 32 Go" required>
                        </div>

                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-upc input-icon"></i>
                            <label class="form-label" for="sku">Référence (SKU)</label>
                            <input type="text" id="sku" name="sku" class="form-control"
                                   placeholder="ABC‑1234">
                        </div>

                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-tags input-icon"></i>
                            <label class="form-label" for="category_id">Catégorie</label>
                            <select id="category_id" name="category_id" class="form-select" required>
                                <option value="" disabled selected>Choisir…</option>
                                <option value="1">Catégorie 1</option>
                                <option value="2">Catégorie 2</option>
                                <option value="3">Catégorie 3</option>
                            </select>
                        </div>
                    </div>

                    <div class="col-md-6">
                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-currency-dollar input-icon"></i>
                            <label class="form-label" for="price">Prix unitaire</label>
                            <input type="number" step="0.01" min="0" id="price" name="price"
                                   class="form-control" placeholder="0.00" required>
                        </div>

                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-stack input-icon"></i>
                            <label class="form-label" for="quantity">Quantité en stock</label>
                            <input type="number" min="0" id="quantity" name="quantity"
                                   class="form-control" placeholder="0" required>
                        </div>

                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-image input-icon"></i>
                            <label class="form-label" for="image">Photo (optionnel)</label>
                            <input type="file" id="image" name="image" class="form-control"
                                   accept="image/*">
                        </div>
                    </div>

                    <div class="col-12">
                        <div class="position-relative with-icon mb-2">
                            <i class="bi bi-text-left input-icon"></i>
                            <label class="form-label" for="description">Description</label>
                            <textarea id="description" name="description" rows="3"
                                      class="form-control"
                                      placeholder="Détails, spécifications, etc."></textarea>
                        </div>
                    </div>
                </div>

                <div class="d-flex justify-content-end gap-2 pt-3">
                    <a href="/produits" class="btn btn-light">
                        <i class="bi bi-arrow-left"></i> Annuler
                    </a>
                    <button type="submit" class="btn text-white" style="background: var(--accent);">
                        <i class="bi bi-save me-1"></i> Enregistrer
                    </button>
                </div>
            </form>
        </div>
    </div>
</div>
