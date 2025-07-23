let deleteForm = null;
let deleteId = null;
let deleteType = null;

document.addEventListener('DOMContentLoaded', () => {
  attachProduitDeleteListeners();

  // Vérifie si une alerte de succès doit être affichée
  const action = sessionStorage.getItem('successAlertAction');
  const element = sessionStorage.getItem('successAlertElement');

  if (action && element) {
    showSuccessAlert(action, element);
    sessionStorage.removeItem('successAlertAction');
    sessionStorage.removeItem('successAlertElement');
  }

  document.getElementById('confirmDeleteBtn').addEventListener('click', () => {
    if (!deleteForm || !deleteId) {
      alert('Erreur interne. Aucune information de suppression trouvée.');
      return;
    }

    const csrfToken = document.querySelector('meta[name="csrf-token"]').getAttribute('content');

    fetch(`/produits/${deleteId}`, {
      method: 'DELETE',
      headers: {
        'X-CSRF-TOKEN': csrfToken,
        'Accept': 'application/json'
      }
    })
    .then(response => {
      if (!response.ok) {
        return response.json().then(err => {
          throw new Error(err.message || 'Erreur lors de la suppression du produit.');
        });
      }
      return response.json();
    })
    .then(data => {
      // Stocke les infos d'alerte dans sessionStorage
      sessionStorage.setItem('successAlertAction', 'delete');
      sessionStorage.setItem('successAlertElement', 'produit');

      // Redirige vers la page index
      window.location.href = '/produits';
    })
    .catch(error => {
      alert(error.message);
    })
    .finally(() => {
      const modal = bootstrap.Modal.getOrCreateInstance(document.getElementById('confirmDeleteModal'));
      modal.hide();
      setTimeout(forceCleanModal, 350);
    });
  });

  document.getElementById('cancelDeleteBtn').addEventListener('click', () => {
    const modal = bootstrap.Modal.getOrCreateInstance(document.getElementById('confirmDeleteModal'));
    modal.hide();
    setTimeout(forceCleanModal, 350);
  });
});

function attachProduitDeleteListeners() {
  document.querySelectorAll('.delete-produit-form').forEach(form => {
    const button = form.querySelector('button');

    const newButton = button.cloneNode(true);
    button.replaceWith(newButton);

    newButton.addEventListener('click', () => {
      deleteForm = form;
      deleteId = form.dataset.produitId;
      const produitNom = form.dataset.produitNom;
      document.getElementById('modal-delete-message').textContent = `Êtes-vous sûr de vouloir supprimer le produit "${produitNom}" ?`;

      const deleteModal = new bootstrap.Modal(document.getElementById('confirmDeleteModal'));
      deleteModal.show();
    });
  });
}

function forceCleanModal() {
  deleteForm = null;
  deleteId = null;
  deleteType = null;
}
