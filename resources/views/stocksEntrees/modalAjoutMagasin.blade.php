<!-- Modal Ajouter Magasin -->
<div class="modal fade" id="ajouterMagasinModal" tabindex="-1" aria-labelledby="ajouterMagasinLabel" aria-hidden="true">
  <div class="modal-dialog">
    <form method="POST" action="{{ route('entrepots.store') }}">
      @csrf
      <div class="modal-content">
        <div class="modal-header">
          <h5 class="modal-title" id="ajouterMagasinLabel">Ajouter un nouveau magasin</h5>
          <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Fermer"></button>
        </div>
        <div class="modal-body">
          <!-- Champ nom -->
          <div class="mb-3">
            <label for="nomMagasin" class="form-label">Nom du magasin</label>
            <input type="text" name="nom" class="form-control" id="nomMagasin" required>
          </div>
          <!-- Champ emplacement -->
          <div class="mb-3">
            <label for="emplacementMagasin" class="form-label">Emplacement</label>
            <input type="text" name="emplacement" class="form-control" id="emplacementMagasin" required>
          </div>
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Annuler</button>
          <button type="submit" class="btn btn-primary">Ajouter</button>
        </div>
      </div>
    </form>
  </div>
</div>

<!-- Modal d'ajout de magasin 
<div class="modal fade" id="ajouterMagasinModal" tabindex="-1" aria-labelledby="ajouterMagasinModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <form method="POST" action="{{ route('entrepots.store') }}" id="ajouterMagasinForm">
        @csrf
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title" id="ajouterMagasinModalLabel">Ajouter un magasin</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Fermer"></button>
            </div>
            <div class="modal-body">
                <div class="mb-3">
                    <label class="form-label">Nom du magasin</label>
                    <input type="text" name="nom" class="form-control" required>
                </div>
            </div>
            <div class="modal-footer">
                <button type="submit" class="btn btn-primary">Ajouter</button>
                <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Annuler</button>
            </div>
        </div>
    </form>
  </div>
</div> -->