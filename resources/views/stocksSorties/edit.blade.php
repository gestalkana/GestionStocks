<!-- resources/views/stocksSorties/edit.blade.php -->
<div class="card border-0 shadow-sm">
    <div class="card-body">
        <h6 class="mb-4">
            <i class="bi bi-pencil-square me-2"></i> MODIFIER BON DE SORTIE
        </h6>

        <form id="form-edit-sortie" method="POST">
            @csrf
            <input type="hidden" name="_method" value="PUT">

            <div class="row g-2 mb-3">
                <div class="col-md-3">
                    <label class="form-label"><i class="bi bi-calendar-date"></i> Date de sortie</label>
                    <input type="date" name="date_sortie" class="form-control form-control-sm" required>
                </div>
                <div class="col-md-3">
                    <label class="form-label"><i class="bi bi-hash"></i> Bon n°</label>
                    <input type="text" name="numero_bon" class="form-control form-control-sm" readonly>
                </div>
                <div class="col-md-3">
                    <label class="form-label"><i class="bi bi-person"></i> Client / Destination</label>
                    <input type="text" name="client" class="form-control form-control-sm">
                </div>
                <div class="col-md-3">
                    <label class="form-label"><i class="bi bi-hash"></i> N° d’ordre de sortie</label>
                    <input type="text" name="numero_ordre" class="form-control form-control-sm" required>
                </div>
                <div class="col-md-3">
                    <label class="form-label"><i class="bi bi-pencil-square"></i> Statut</label>
                    <select name="statut" class="form-select form-select-sm">
                        <option value="Brouillon">Brouillon</option>
                        <option value="Validé">Validé</option>
                    </select>
                </div>
                <div class="col-md-6">
                    <label class="form-label"><i class="bi bi-chat-left-text"></i> Motif</label>
                    <input type="text" name="motif" class="form-control form-control-sm">
                </div>
            </div>

            <div class="mt-3">
                <h6><i class="bi bi-cart-check me-2"></i> Produits</h6>
                <table id="table-edit-produits" class="table table-sm table-bordered">
                    <thead>
                        <tr>
                            <th>Produit</th>
                            <th>Quantité</th>
                            <th></th>
                        </tr>
                    </thead>
                    <tbody>
                        <!-- rempli en JS -->
                    </tbody>
                </table>
                <button type="button" id="btn-edit-add-row" class="btn btn-outline-primary btn-sm">
                    <i class="bi bi-plus-circle"></i> Ajouter produit
                </button>
            </div>

            <div class="text-end mt-4">
                <button type="submit" class="btn btn-primary">
                    <i class="bi bi-check2-circle"></i> Enregistrer les modifications
                </button>
                <button type="button" id="btn-cancel-edit" class="btn btn-outline-secondary">
                    <i class="bi bi-x-circle"></i> Annuler
                </button>
            </div>
        </form>
    </div>
</div>
