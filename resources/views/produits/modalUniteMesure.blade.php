<!-- Modal Ajouter Unité de Mesure -->
<div class="modal fade" id="modalAjouterUnite" tabindex="-1" aria-labelledby="modalAjouterUniteLabel" aria-hidden="true">
  <div class="modal-dialog">
    <form id="formAjouterUnite" action="{{-- route('unite_mesures.store') --}}" method="POST">
      @csrf
      <div class="modal-content">
        <div class="modal-header">
          <h5 class="modal-title" id="modalAjouterUniteLabel">Ajouter une nouvelle unité de mesure</h5>
          <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Fermer"></button>
        </div>
        <div class="modal-body">
          <div class="mb-3">
            <label for="code" class="form-label">Code (ex : kg, pc)</label>
            <input type="text" class="form-control" id="code" name="code" required>
          </div>
          <div class="mb-3">
            <label for="nom" class="form-label">Nom</label>
            <input type="text" class="form-control" id="nom" name="nom" required>
          </div>
          <div class="mb-3">
            <label for="symbole" class="form-label">Symbole (optionnel)</label>
            <input type="text" class="form-control" id="symbole" name="symbole">
          </div>
          <div id="modalErrorMsg" class="text-danger" style="display:none;"></div>
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Annuler</button>
          <button type="submit" class="btn btn-primary">Ajouter</button>
        </div>
      </div>
    </form>
  </div>
</div>
