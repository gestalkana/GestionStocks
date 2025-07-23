<!-- Modal Bootstrap -->
<div class="modal fade" id="modalAjoutFournisseur" tabindex="-1" aria-labelledby="modalAjoutFournisseurLabel" aria-hidden="true">
  <div class="modal-dialog modal-lg modal-dialog-scrollable">
    <div class="modal-content">
      <form id="formAjoutFournisseur" action="{{ route('fournisseurs.store') }}" method="POST">
        @csrf
        <div class="modal-header">
          <h5 class="modal-title" id="modalAjoutFournisseurLabel">
            <i class="bi bi-person-plus me-1"></i> Nouveau Fournisseur
          </h5>
          <button type="button" class="btn-close" 
                  data-bs-dismiss="modal" aria-label="Fermer">
          </button>
        </div>

        <div class="modal-body">
          {{-- Formulaire --}}
          <div class="mb-3">
            <label for="nom" class="form-label">Nom <span class="text-danger">*</span></label>
            <input type="text" class="form-control" id="nom" name="nom" required>
          </div>

          <div class="mb-3">
            <label for="telephone" class="form-label">Téléphone</label>
            <input type="text" class="form-control" id="telephone" name="telephone">
          </div>

          <div class="mb-3">
            <label for="email" class="form-label">E-mail</label>
            <input type="email" class="form-control" id="email" name="email">
          </div>

          <div class="mb-3">
            <label for="statut" class="form-label">Statut</label>
            <select id="statut" name="statut" class="form-select">
              <option value="actif">Actif</option>
              <option value="inactif">Inactif</option>
              <option value="blacklisté">Blacklisté</option>
              <option value="en attente" selected>En attente</option>
            </select>
          </div>

          <div class="mb-3">
            <label for="type" class="form-label">Adresse</label>
            <input type="text" class="form-control" id="adresse" name="adresse" placeholder="Adresse...">
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
