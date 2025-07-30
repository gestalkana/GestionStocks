<!-- MODAL DE MODIFICATION ENTREE -->
<div class="modal fade" id="editEntreeModal" tabindex="-1" aria-labelledby="editEntreeModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">
      <form id="editEntreeForm">
        @csrf
        <div class="modal-header">
          <h5 class="modal-title" id="editEntreeModalLabel">Modifier la date d'expiration</h5>
          <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Fermer"></button>
        </div>
        <div class="modal-body">
          <input type="hidden" id="editEntreeId">
          <div class="row g-2">
            <div class="col-md-6">
              <label for="editQuantite" class="form-label">Quantité</label>
              <input type="number" class="form-control" id="editQuantite" name="quantite" min="1" required>
            </div>
            <div class="col-md-6">
              <label for="editDateExpiration" class="form-label">Date d'expiration</label>
              <input type="date" class="form-control" id="editDateExpiration" name="date_expiration" required>
            </div>
          </div>
        </div>
        <div class="modal-footer">
          <button type="button" id="cancelEditEntreeBtn" class="btn btn-secondary">Annuler</button>
          <button type="submit" class="btn btn-primary">Enregistrer</button>
        </div>
      </form>
    </div>
  </div>
</div>
