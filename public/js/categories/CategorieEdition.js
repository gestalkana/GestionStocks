function fillEditForm(data) {
  document.getElementById('editCategoryId').value = data.id;
  document.getElementById('editCategoryName').value = data.nom;
  document.getElementById('editCategoryReference').value = data.reference;
  document.getElementById('editCategoryDescription').value = data.description;
}

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
  attachEditListeners();

  const editForm = document.getElementById('editCategoryForm');
  if (editForm) {
    editForm.addEventListener('submit', function (e) {
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
          fetch('/produits/categories/reload')
            .then(response => response.text())
            .then(html => {
              const container = document.querySelector('#categories');
              if (container) {
                container.innerHTML = html;
                if (typeof showSuccessAlert === 'function') {
                  showSuccessAlert('update', 'catégorie');
                }
                if (typeof attachEditListeners === 'function') {
                  attachEditListeners();
                }
                if (typeof attachDeleteListeners === 'function') {
                  attachDeleteListeners();
                }

                const modalEl = document.getElementById('editCategoryModal');
                if (modalEl) {
                  bootstrap.Modal.getOrCreateInstance(modalEl).hide();
                  setTimeout(forceCleanModal, 350);
                }
              }
            });
        })
        .catch(error => {
          alert(error.message);
        });
    });
  }

  const cancelEditBtn = document.getElementById('cancelEditBtn');
  if (cancelEditBtn) {
    cancelEditBtn.addEventListener('click', () => {
      const editModalEl = document.getElementById('editCategoryModal');
      if (editModalEl) {
        const editModal = bootstrap.Modal.getInstance(editModalEl) || new bootstrap.Modal(editModalEl);
        editModal.hide();
        setTimeout(forceCleanModal, 350);
      }
    });
  }
});
