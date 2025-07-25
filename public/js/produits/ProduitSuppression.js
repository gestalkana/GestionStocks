let produitDeleteForm = null;
let produitDeleteId = null;

document.addEventListener('DOMContentLoaded', () => {
  attachProduitDeleteListeners();

  const action = sessionStorage.getItem('successAlertAction');
  const element = sessionStorage.getItem('successAlertElement');

  if (action && element) {
    showSuccessAlert(action, element);
    sessionStorage.removeItem('successAlertAction');
    sessionStorage.removeItem('successAlertElement');
  }

  const confirmBtn = document.getElementById('confirmDeleteBtnProduit');
  if (confirmBtn) {
    confirmBtn.addEventListener('click', () => {
      if (!produitDeleteForm || !produitDeleteId) {
        alert('Erreur interne. Aucune information de suppression trouvée.');
        return;
      }

      const csrfToken = document.querySelector('meta[name="csrf-token"]').getAttribute('content');

      fetch(`/produits/${produitDeleteId}`, {
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
        sessionStorage.setItem('successAlertAction', 'delete');
        sessionStorage.setItem('successAlertElement', 'produit');
        window.location.href = '/produits';
      })
      .catch(error => {
        alert(error.message);
      })
      .finally(() => {
        const modal = bootstrap.Modal.getOrCreateInstance(document.getElementById('confirmDeleteModalProduit'));
        modal.hide();
        setTimeout(forceCleanProduitModal, 350);
      });
    });
  }

  const cancelBtn = document.getElementById('cancelDeleteBtnProduit');
  if (cancelBtn) {
    cancelBtn.addEventListener('click', () => {
      const modal = bootstrap.Modal.getOrCreateInstance(document.getElementById('confirmDeleteModalProduit'));
      modal.hide();
      setTimeout(forceCleanProduitModal, 350);
    });
  }
});

function attachProduitDeleteListeners() {
  document.querySelectorAll('.delete-produit-form').forEach(form => {
    const button = form.querySelector('button');
    const newButton = button.cloneNode(true);
    button.replaceWith(newButton);

    newButton.addEventListener('click', () => {
      produitDeleteForm = form;
      produitDeleteId = form.dataset.produitId;
      const produitNom = form.dataset.produitNom;
      document.getElementById('modal-delete-message-produit').textContent = `Êtes-vous sûr de vouloir supprimer le produit "${produitNom}" ?`;

      const deleteModal = new bootstrap.Modal(document.getElementById('confirmDeleteModalProduit'));
      deleteModal.show();
    });
  });
}

function forceCleanProduitModal() {
  produitDeleteForm = null;
  produitDeleteId = null;
}
