<!-- resources/views/stocksSorties/partials/lot-modal.blade.php -->
<div class="modal fade" id="lotModal" tabindex="-1" aria-labelledby="lotModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">
      <div class="modal-header">
        <h5 class="modal-title" id="lotModalLabel"><i class="bi bi-boxes"></i> Attribution des lots</h5>
        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Fermer"></button>
      </div>
      <div class="modal-body">
        <table class="table table-bordered table-sm">
          <thead class="table-light">
            <tr>
              <th>Produit</th>
              <th>Lot ID</th>
              <th>Date</th>
              <th>Date D'expiration</th>
              <th>Quantité dispo</th>
              <th>Qté à sortir</th>
            </tr>
          </thead>
          <tbody id="lot-modal-body">
            <!-- Rempli dynamiquement -->
          </tbody>
        </table>
        <div class="text-end">
          <button type="button" class="btn btn-success" id="confirm-lots" data-current="">
              <i class="bi bi-check-circle"></i> Confirmer
          </button>
        </div>
      </div>
    </div>
  </div>
</div>
