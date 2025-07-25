window.categorieDeleteForm = null;
window.categorieDeleteId = null;

function attachCategorieDeleteListeners() {
  document.querySelectorAll('.delete-categorie-form').forEach(form => {
    const button = form.querySelector('button');
    if (!button) return;

    const newButton = button.cloneNode(true);
    button.replaceWith(newButton);

    newButton.addEventListener('click', () => {
      window.categorieDeleteForm = form;
      window.categorieDeleteId = form.dataset.categorieId;

      const categoryName = form.dataset.categorieName || '[Nom inconnu]';
      const messageEl = document.getElementById('modal-delete-message-categorie');
      if (messageEl) {
        messageEl.textContent = `Êtes-vous sûr de vouloir supprimer la catégorie "${categoryName}" ?`;
      }

      const modalEl = document.getElementById('confirmDeleteModalCategorie');
      if (modalEl) {
        const modal = bootstrap.Modal.getOrCreateInstance(modalEl);
        modal.show();
      } else {
        console.error('Modal "confirmDeleteModalCategorie" introuvable.');
      }
    });
  });
}

window.attachCategorieDeleteListeners = attachCategorieDeleteListeners;

document.addEventListener('DOMContentLoaded', () => {
  attachCategorieDeleteListeners();

  const confirmBtn = document.getElementById('confirmDeleteBtnCategorie');
  if (confirmBtn) {
    confirmBtn.addEventListener('click', () => {
      const deleteId = window.categorieDeleteId;

      if (!deleteId || isNaN(deleteId)) {
        alert('ID de catégorie invalide.');
        return;
      }

      const csrfTokenMeta = document.querySelector('meta[name="csrf-token"]');
      const csrfToken = csrfTokenMeta ? csrfTokenMeta.getAttribute('content') : '';

      fetch(`/categories/${deleteId}`, {
        method: 'DELETE',
        headers: {
          'X-CSRF-TOKEN': csrfToken,
          'Accept': 'application/json'
        }
      })
      .then(async response => {
        const data = await response.json();
        if (!response.ok) {
          throw new Error(data?.message || 'Erreur lors de la suppression');
        }
        return data;
      })
      .then(data => {
        return fetch('/produits/categories/reload');
      })
      .then(response => response.text())
      .then(html => {
        const categoriesContainer = document.querySelector('#categories');
        if (categoriesContainer) {
          categoriesContainer.innerHTML = html;
        }

        if (typeof showSuccessAlert === 'function') {
          showSuccessAlert('delete', 'categorie');
        }

        if (typeof attachEditListeners === 'function') {
          attachEditListeners();
        }

        if (typeof attachCategorieDeleteListeners === 'function') {
          attachCategorieDeleteListeners();
        }

        const modalEl = document.getElementById('confirmDeleteModalCategorie');
        if (modalEl) {
          const modal = bootstrap.Modal.getOrCreateInstance(modalEl);
          modal.hide();
          setTimeout(forceCleanCategorieModal, 350);
        }
      })
      .catch(error => {
        console.error('Erreur JS (frontend) :', error);
        alert(error.message);
      });
    });
  }

  const cancelBtn = document.getElementById('cancelDeleteBtnCategorie');
  if (cancelBtn) {
    cancelBtn.addEventListener('click', () => {
      const modalEl = document.getElementById('confirmDeleteModalCategorie');
      if (modalEl) {
        const modal = bootstrap.Modal.getOrCreateInstance(modalEl);
        modal.hide();
        setTimeout(forceCleanCategorieModal, 350);
      }
    });
  }
});

function forceCleanCategorieModal() {
  window.categorieDeleteForm = null;
  window.categorieDeleteId = null;
}
