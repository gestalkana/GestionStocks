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