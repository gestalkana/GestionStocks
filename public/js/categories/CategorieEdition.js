 // Fonction pour remplir les champs du formulaire de modification
function fillEditForm(data) {
  document.getElementById('editCategoryId').value = data.id;
  document.getElementById('editCategoryName').value = data.nom;
  document.getElementById('editCategoryReference').value = data.reference;
  document.getElementById('editCategoryDescription').value = data.description;
}

// Fonction pour rattacher les événements aux boutons "modifier"
function attachEditListeners() {
  document.querySelectorAll('.edit-categorie-btn').forEach(button => {
    button.addEventListener('click', function () {
      fillEditForm({
        id: this.dataset.id,
        nom: this.dataset.nom,
        reference: this.dataset.reference,
        description: this.dataset.description
      });

      const editModal = new bootstrap.Modal(document.getElementById('editCategoryModal'));
      editModal.show();
    });
  });
}

document.addEventListener('DOMContentLoaded', () => {
  // Attacher les événements aux boutons d'édition
  attachEditListeners();

  // Gestion de la soumission du formulaire
  const editForm = document.getElementById('editCategoryForm');
  if (editForm) {
    editForm.addEventListener('submit', function(e) {
      e.preventDefault();

      const id = document.getElementById('editCategoryId').value;
      const formData = new FormData(editForm);
      const csrfToken = document.querySelector('meta[name="csrf-token"]').getAttribute('content');

      fetch(`/categories/${id}`, {
        method: 'POST',
        headers: {
          'X-CSRF-TOKEN': csrfToken,
          'Accept': 'application/json',
        },
        body: formData
      })
      .then(response => {
        if (!response.ok) throw new Error('Erreur lors de la mise à jour.');
        return response.json();
      })
      .then(data => {
        // Recharger la liste des catégories
        fetch('/produits/categories/reload')
          .then(response => response.text())
          .then(html => {
              document.querySelector('#categories').innerHTML = html;
              showSuccessAlert('update', 'catégorie');
              // Reattacher les événements (Edit et supp) aux nouveaux boutons
              attachEditListeners(); 
              attachDeleteListeners();
              // Fermer le modal proprement
              bootstrap.Modal.getOrCreateInstance(document.getElementById('editCategoryModal')).hide();

              // Laisse Bootstrap faire l’animation, puis nettoie si besoin
              setTimeout(forceCleanModal, 350); // après l’animation
          });
      })
      .catch(error => {
        alert(error.message);
      });
    });
  }
});


//BOUTON ANNULER - EDITION
document.getElementById('cancelEditBtn').addEventListener('click', () => {
  const editModalEl = document.getElementById('editCategoryModal');
  let editModal = bootstrap.Modal.getInstance(editModalEl);
  if (!editModal) {
    editModal = new bootstrap.Modal(editModalEl);
  }
  editModal.hide();
  // Fermer le modal proprement
  bootstrap.Modal.getOrCreateInstance(document.getElementById('editCategoryModal')).hide();

  // Laisse Bootstrap faire l’animation, puis nettoie si besoin
  setTimeout(forceCleanModal, 350); // après l’animation
});


function forceCleanModal() {
  // Supprimer le backdrop
  document.querySelectorAll('.modal-backdrop').forEach(el => el.remove());

  // Vérifier qu'aucun autre modal n’est visible
  const stillOpen = document.querySelector('.modal.show');
  if (!stillOpen) {
    document.body.classList.remove('modal-open');
    document.body.style.paddingRight = '';
    document.body.style.overflowY = ''; // optionnel, pour forcer le scroll
  }
}
