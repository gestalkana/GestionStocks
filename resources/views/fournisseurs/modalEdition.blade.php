<!-- Modal de modification de fournisseur -->
<div class="modal fade" id="editFournisseurModal" tabindex="-1" aria-labelledby="editFournisseurModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <form id="editFournisseurForm">
        @csrf
        <div class="modal-header">
          <h5 class="modal-title" id="editFournisseurModalLabel">Modifier le fournisseur</h5>
          <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Fermer"></button>
        </div>
        <div class="modal-body">
          <input type="hidden" id="editFournisseurId" name="id">
          <div class="mb-3">
            <label for="editFournisseurNom" class="form-label">Nom</label>
            <input type="text" class="form-control" id="editFournisseurNom" name="nom">
          </div>
          <div class="mb-3">
            <label for="editFournisseurTelephone" class="form-label">Téléphone</label>
            <input type="text" class="form-control" id="editFournisseurTelephone" name="telephone">
          </div>
          <div class="mb-3">
            <label for="editFournisseurEmail" class="form-label">Email</label>
            <input type="email" class="form-control" id="editFournisseurEmail" name="email">
          </div>
          <div class="mb-3">
            <label for="editFournisseurAdresse" class="form-label">Adresse</label>
            <input type="text" class="form-control" id="editFournisseurAdresse" name="adresse">
          </div>
          <div class="mb-3">
            <label for="editFournisseurStatut" class="form-label">Statut</label>
            <select class="form-select" id="editFournisseurStatut" name="statut">
              <option value="actif">Actif</option>
              <option value="inactif">Inactif</option>
            </select>
          </div>
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Annuler</button>
          <button type="submit" class="btn btn-primary">Enregistrer</button>
        </div>
      </form>
    </div>
  </div>
</div>
