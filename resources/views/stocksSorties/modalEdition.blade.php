<!-- Modal d'édition du Bon de Sortie -->
<div class="modal fade" id="editSortieModal" tabindex="-1" aria-labelledby="editSortieModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      
      <div class="modal-header">
        <h5 class="modal-title" id="editSortieModalLabel">Modifier le Bon de Sortie</h5>
        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Fermer"></button>
      </div>

      <!-- <form action="{{ route('stocksSorties.update', $bon->numero_bon) }}" method="POST"> -->
        <form id="form-edit-sortie" method="POST">
        @csrf
        @method('PUT')
        
        <div class="modal-body">
          <input type="hidden" name="numero_bon" id="edit-numero-bon">

          <div class="mb-3">
            <label for="edit-ordre" class="form-label">Numéro d'ordre</label>
            <input type="text" class="form-control" name="numero_ordre" id="edit-ordre">
          </div>

          <div class="mb-3">
            <label for="edit-statut" class="form-label">Statut</label>
            <select class="form-select" name="statut" id="edit-statut">
              <option value="brouillon">Brouillon</option>
              <option value="valide">Validé</option>
              <option value="annule">Annulé</option>
            </select>
          </div>

          <div class="mb-3">
            <label for="edit-client" class="form-label">Client</label>
            <input type="text" class="form-control" name="client" id="edit-client">
          </div>
        </div>

        <div class="modal-footer">
          <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Annuler</button>
          <button type="submit" class="btn btn-primary">Mettre à jour</button>
        </div>
      </form>
    </div>
  </div>
</div>
