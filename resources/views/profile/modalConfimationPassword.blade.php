<!-- resources/views/profile/modalConfimationPassword.blade.php -->

<div class="modal fade" id="confirmPasswordModal" tabindex="-1" aria-labelledby="confirmPasswordModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <form id="confirmPasswordForm" class="modal-content">
      <div class="modal-header">
        <h5 class="modal-title" id="confirmPasswordModalLabel">Confirmer la modification</h5>
        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Fermer"></button>
      </div>
      <div class="modal-body">
        <div class="mb-3">
          <label for="current_password" class="form-label">Mot de passe actuel</label>
          <input type="password" id="current_password" name="current_password" class="form-control" required>
          <div class="invalid-feedback" id="passwordError"></div>
        </div>
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Annuler</button>
        <button type="submit" class="btn btn-primary">Confirmer</button>
      </div>
    </form>
  </div>
</div>
