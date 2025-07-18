
<!-- Modal édition catégorie -->
<div class="modal fade" id="editCategoryModal" tabindex="-1" aria-labelledby="editCategoryModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <form id="editCategoryForm">
      @csrf
      @method('PUT')
      <div class="modal-content">
        <div class="modal-header">
          <h5 class="modal-title" id="editCategoryModalLabel">Modifier la catégorie</h5>
          <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Fermer"></button>
        </div>
        <div class="modal-body">
          <input type="hidden" id="editCategoryId">
          <div class="mb-3">
            <label for="editCategoryReference" class="form-label">Référence</label>
            <input type="text" name="reference" class="form-control" id="editCategoryReference" required>
          </div>
          <div class="mb-3">
            <label for="editCategoryName" class="form-label">Nom de la catégorie</label>
            <input type="text" name="nom" class="form-control" id="editCategoryName" required>
          </div>
          <div class="mb-3">
            <label for="editCategoryDescription" class="form-label">Description</label>
            <textarea name="description" class="form-control" id="editCategoryDescription" rows="3"></textarea>
          </div>
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-secondary" data-bs-dismiss="modal" id="cancelEditBtn">Annuler</button>
          <button type="submit" class="btn btn-primary">Enregistrer</button>
        </div>
      </div>
    </form>
  </div>
</div>
