<!-- MODAL de modification de produit -->
<div class="modal fade" id="editProductModal" tabindex="-1" aria-labelledby="editProductModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">
      <form id="editProductForm">
        @csrf
        <div class="modal-header">
          <h5 class="modal-title" id="editProductModalLabel">Modifier le produit</h5>
          <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Fermer"></button>
        </div>
        <div class="modal-body">
          <input type="hidden" id="editProduitId" name="id">
          <div class="row g-2">
            <div class="col-md-6">
              <label for="editProduitNom" class="form-label">Nom</label>
              <input type="text" class="form-control" id="editProduitNom" name="nom">
            </div>
            <div class="col-md-6">
              <label for="editProduitCode" class="form-label">Code produit</label>
              <input type="text" class="form-control" id="editProduitCode" name="code_produit">
            </div>
            <div class="col-md-6">
              <label for="editProduitPrixAchat" class="form-label">Prix d'achat</label>
              <input type="number" step="0.01" class="form-control" id="editProduitPrixAchat" name="prix_achat">
            </div>
            <div class="col-md-6">
              <label for="editProduitPrixVente" class="form-label">Prix de vente</label>
              <input type="number" step="0.01" class="form-control" id="editProduitPrixVente" name="prix_unitaire">
            </div>
            <div class="col-md-6">
              <label for="editProduitUnite" class="form-label">Unité de mesure</label>
              <select class="form-select" id="editProduitUnite" name="unite_mesure_id">
                @foreach ($uniteMesure as $unite)
                  <option value="{{ $unite->id }}">{{ $unite->nom }}</option>
                @endforeach
              </select>
            </div>
            <div class="col-md-12">
              <label for="editProduitDescription" class="form-label">Description</label>
              <textarea class="form-control" id="editProduitDescription" name="description"></textarea>
            </div>
          </div>
        </div>
        <div class="modal-footer">
          <button type="button" id="cancelEditProductBtn" class="btn btn-secondary">Annuler</button>
          <button type="submit" class="btn btn-primary">Enregistrer</button>
        </div>
      </form>
    </div>
  </div>
</div>
