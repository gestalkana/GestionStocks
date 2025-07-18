document.addEventListener('DOMContentLoaded', () => {
  // Initialisation des écouteurs au chargement
  attachDeleteListeners();

  // Écouteur pour le bouton de confirmation du modal
  document.getElementById('confirmDeleteBtn').addEventListener('click', () => {
    if (!deleteForm || !deleteId || isNaN(deleteId)) {
      alert('ID de catégorie invalide.');
      return;
    }

    const csrfToken = document.querySelector('meta[name="csrf-token"]').getAttribute('content');

    fetch(`/categories/${deleteId}`, {
      method: 'DELETE',
      headers: {
        'X-CSRF-TOKEN': csrfToken,
        'Accept': 'application/json'
      }
    })
    .then(response => {
      if (!response.ok) {
        return response.json().then(err => {
          throw new Error(err.message || 'Erreur lors de la suppression');
        });
      }
      return response.json();
    })
    .then(data => {
      console.log('Réponse reçue :', data);
      // Recharger dynamiquement la liste des catégories
      return fetch('/produits/categories/reload');
    })
    .then(response => response.text())
    .then(html => {
      document.querySelector('#categories').innerHTML = html;

      // Reattacher les écouteurs après mise à jour du DOM
      attachDeleteListeners();

      // Fermer le modal
      bootstrap.Modal.getOrCreateInstance(document.getElementById('confirmDeleteModal')).hide();
      setTimeout(forceCleanModal, 350);
    })
    .catch(error => {
      alert(error.message);
    });
  });
});

// Variables globales (si besoin)
let deleteForm = null;
let deleteId = null;

function attachDeleteListeners() {
  document.querySelectorAll('.delete-form').forEach(form => {
    const button = form.querySelector('button');

    // Cloner le bouton pour retirer tous les anciens écouteurs
    const newButton = button.cloneNode(true);
    button.replaceWith(newButton);

    newButton.addEventListener('click', () => {
      deleteForm = form;
      deleteId = form.dataset.categorieId;

      const categoryName = form.dataset.categorieName;
      const message = `Êtes-vous sûr de vouloir supprimer la catégorie "${categoryName}" ?`;
      document.getElementById('modal-delete-message').textContent = message;

      const deleteModal = new bootstrap.Modal(document.getElementById('confirmDeleteModal'));
      deleteModal.show();
    });
  });
}

// BOUTON ANNULER - SUPPRESSION
document.getElementById('cancelDeleteBtn').addEventListener('click', () => {
  const deleteModalEl = document.getElementById('confirmDeleteModal');
  let deleteModal = bootstrap.Modal.getInstance(deleteModalEl);
  
  if (!deleteModal) {
    deleteModal = new bootstrap.Modal(deleteModalEl);
  }
  
  deleteModal.hide();
  
  // Fermer proprement au cas où
  bootstrap.Modal.getOrCreateInstance(deleteModalEl).hide();
  
  // Nettoyage éventuel après l’animation (350ms)
  setTimeout(forceCleanModal, 350);
});
