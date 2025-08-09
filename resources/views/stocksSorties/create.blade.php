<!-- resources/views/stocksSorties/create.blade.php -->
<div class="collapse mb-4" id="formCollapse">
    <div class="card border-0 shadow-sm">
        <div class="card-body">
            <h6 class="mb-4">
                <i class="bi bi-receipt me-2"></i> BON SORTIE DE STOCK
            </h6>

            <!-- <form id="form-sortie" action="{{-- route('stocksSorties.store') --}}" method="POST"> -->
            <form id="form-sortie">

                @csrf
                <div class="row g-2 mb-3">
                    <div class="col-md-3">
                        <label class="form-label"><i class="bi bi-calendar-date"></i> Date de sortie</label>
                        <input type="date" name="date_sortie" class="form-control form-control-sm" value="{{ date('Y-m-d') }}" required>
                    </div>
                    <div class="col-md-3">
                        <label class="form-label"><i class="bi bi-hash"></i> Bon n°</label>
                        <input type="text" name="bon_sortie" class="form-control form-control-sm" value="{{ $numeroBon ?? 'BS-'.str_pad(rand(1,9999), 4, '0', STR_PAD_LEFT) }}" readonly>
                    </div>
                    <div class="col-md-3">
                        <label class="form-label"><i class="bi bi-person"></i> Client / Destination</label>
                        <input type="text" name="client_destination" class="form-control form-control-sm" placeholder="Nom du client ou service">
                    </div>
                    <div class="col-md-3">
                        <label class="form-label"><i class="bi bi-pencil-square"></i> Statut</label>
                        <select name="statut" class="form-select form-select-sm">
                            <option value="Brouillon">Brouillon</option>
                            <option value="Validé">Validé</option>
                        </select>
                    </div>
                </div>

                <div class="mt-3">
                    <h6><i class="bi bi-cart-check me-2"></i> Produits à sortir</h6>
                    <table class="table table-bordered table-sm align-middle mt-2">
                        <thead class="table-light">
                            <tr>
                                <th style="width: 35%">Produit</th>
                                <th style="width: 15%">Quantité demandée</th>
                                <th style="width: 15%">UnitéMesure</th>
                                <th style="width: 30%">Lots attribués</th>
                                <th style="width: 5%" class="text-center">Action</th>
                            </tr>
                        </thead>
                        <tbody id="produits-sortie-body">
                            <tr>
                                <td>
                                    <select name="produits[0][produit_id]" class="form-select form-select-sm produit-select" data-index="0" required>
                                        <option value="">-- Choisir produit --</option>
                                        @foreach ($produits as $produit)
                                            <option 
                                                value="{{ $produit->id }}" 
                                                data-unite="{{ $produit->uniteMesure->nom ?? 'Non défini' }}">
                                                {{ $produit->nom }}
                                            </option>
                                        @endforeach
                                    </select>
                                </td>
                                <td>
                                    <input type="number" name="produits[0][quantite]" class="form-control form-control-sm quantite-input" data-index="0" min="1" required>
                                </td>
                                <td>
                                   <input type="text" class="form-control form-control-sm unite-input" data-index="0" readonly>
                                </td>
                                <td class="d-flex justify-content-between align-items-center">
                                    <button type="button" class="btn btn-outline-secondary btn-sm attribuer-lots" data-index="0">
                                        <i class="bi bi-tools"></i> Choisir lots
                                    </button>
                                    <div class="ms-2 mt-1 small text-primary lots-affiches" data-index="0">Aucun lot attribué</div>
                                    <div class="lots-hidden" data-index="0"></div>
                                </td>
                                <td class="text-center">
                                    <button type="button" class="btn btn-outline-danger btn-sm remove-row">
                                        <i class="bi bi-trash"></i>
                                    </button>
                                </td>
                            </tr>
                        </tbody>
                    </table>
                    <button type="button" id="add-row" class="btn btn-outline-primary btn-sm">
                        <i class="bi bi-plus-circle"></i> Ajouter produit
                    </button>
                </div>

               <!--  <div class="text-end mt-3">
                    <button type="submit" class="btn btn-success btn-sm">
                        <i class="bi bi-save me-1"></i> Enregistrer
                    </button>
                    <button type="submit" name="validate" value="1" class="btn btn-dark btn-sm">
                        <i class="bi bi-check2-circle"></i> Valider sortie
                    </button>
                </div> -->
                <div class="text-end mt-4">
                    <button type="button" id="btn-enregistrer" class="btn btn-success me-2">
                        <i class="bi bi-save"></i> Enregistrer
                    </button>
                    <button type="button" id="btn-valider" class="btn btn-primary">
                        <i class="bi bi-check2-circle"></i> Valider sortie
                    </button>
                </div>
            </form>
        </div>
    </div>
</div>
