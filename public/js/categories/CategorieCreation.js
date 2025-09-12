document.addEventListener('DOMContentLoaded', function () {

  const form = document.getElementById('createCategoryForm');
  const modalElement = document.getElementById('createCategoryModal');
  const modal = bootstrap.Modal.getInstance(modalElement) || new bootstrap.Modal(modalElement);
  const submitButton = form.querySelector('button[type="submit"]');

  // Assure que l'événement submit n'est attaché qu'une seule fois
  function onSubmitHandler(event) {
    event.preventDefault();

    console.log('Form submitted'); // Pour debug

    // Bloquer le bouton pour empêcher les doubles clics
    submitButton.disabled = true;

    const formData = new FormData(form);

    fetch(form.action, {
      method: 'POST',
      headers: {
        'X-Requested-With': 'XMLHttpRequest',
        'X-CSRF-TOKEN': form.querySelector('input[name="_token"]').value,
        'Accept': 'application/json'
      },
      body: formData
    })
    .then(async response => {
      if (!response.ok) {
        const text = await response.text();
        if (response.status === 422) {
          const data = JSON.parse(text);
          handleErrors(data.errors);
          showValidationErrors(data.errors);
        } else {
          throw new Error('Erreur serveur: ' + text);
        }
      } else {
        return response.json();
      }
    })
    .then(data => {
      if (data && data.success && data.category) {
        addCategoryToTable(data.category);
        addCategoryToSelect(data.category);
        showSuccessAlert('create', 'catégorie');
        // Réactive la fonction de suppréssion catégorie
        if (typeof attachCategorieDeleteListeners === 'function') {
                  attachCategorieDeleteListeners();
        }
        form.reset();
        modal.hide();
      } else if (data && data.message) {
        showErrorAlert('Création impossible', data.message);
      }

      submitButton.disabled = false; // Réactive le bouton
    })
    .catch(error => {
      console.error(error);
      showErrorAlert('Erreur', error.message || 'Une erreur est survenue.');
      submitButton.disabled = false; // Réactive le bouton même en erreur
    });
  }

  // D'abord enlever un éventuel listener (pour éviter doublons), puis attacher
  form.removeEventListener('submit', onSubmitHandler);
  form.addEventListener('submit', onSubmitHandler);

  // 🔧 Affichage inline des erreurs de validation
  function handleErrors(errors) {
    form.querySelectorAll('.is-invalid').forEach(el => el.classList.remove('is-invalid'));
    form.querySelectorAll('.invalid-feedback').forEach(el => el.remove());

    for (const [field, messages] of Object.entries(errors)) {
      const input = form.querySelector(`[name="${field}"]`);
      if (input) {
        input.classList.add('is-invalid');
        const div = document.createElement('div');
        div.classList.add('invalid-feedback');
        div.innerText = messages.join(', ');
        input.parentNode.appendChild(div);
      }
    }
  }

  // ✅ SweetAlert - Erreurs de validation groupées
  function showValidationErrors(errors) {
    const messages = Object.values(errors).flat().join('<br>');
    Swal.fire({
      icon: 'warning',
      title: 'Erreurs de validation',
      html: messages
    });
  }

  // ✅ SweetAlert - Message d'erreur générique ou serveur
  function showErrorAlert(title = 'Erreur', message = 'Une erreur est survenue.') {
    Swal.fire({
      icon: 'error',
      title: title,
      text: message
    });
  }

  // Ajout dynamique de la nouvelle catégorie dans le tableau
  function addCategoryToTable(category) {
    const tbody = document.querySelector('#categories table tbody');
    const tr = document.createElement('tr');

    tr.innerHTML = `
      <td><div><strong>${category.reference}</strong></div></td>
      <td>${category.nom}</td>
      <td>${(category.description || '—').slice(0, 50)}${category.description && category.description.length > 50 ? '…' : ''}</td>
      <td><span class="badge bg-danger text-white">${category.products_count || 0}</span></td>
      <td>${new Date(category.created_at).toLocaleDateString('fr-FR')}</td>
      <td>
        <a href="#" class="btn btn-sm btn-outline-primary edit-category-btn"
           data-id="${category.id}"
           data-reference="${category.reference || ''}"
           data-nom="${category.nom}"
           data-description="${category.description || ''}"
           data-bs-toggle="modal"
           data-bs-target="#editCategoryModal">
           Modifier
        </a>
        <form action="/categories/${category.id}"
                  method="POST"
                  class="d-inline delete-categorie-form"
                  data-categorie-id="${category.id}"
                  data-categorie-name="${category.nom}">
              
              <input type="hidden" name="_token" value="${document.querySelector('meta[name=csrf-token]').content}">
              <input type="hidden" name="_method" value="DELETE">
              <button type="button" class="btn btn-sm btn-outline-danger">Supprimer</button>
        </form>
      </td>
    `;

    tbody.appendChild(tr);

    tr.querySelector('.edit-category-btn').addEventListener('click', function () {
      const button = this;
      document.getElementById('editCategoryId').value = button.dataset.id;
      document.getElementById('editCategoryReference').value = button.dataset.reference;
      document.getElementById('editCategoryName').value = button.dataset.nom;
      document.getElementById('editCategoryDescription').value = button.dataset.description;
    });
  }
  // Ajout dynamique de la nouvelle catégorie dans la liste deroulant
  function addCategoryToSelect(category) {
  const select = document.getElementById('categorie_id');

  const option = document.createElement('option');
  option.value = category.id;
  option.textContent = category.nom;

  select.appendChild(option); // ou insertBefore(option, select.firstChild) si tu veux en haut
}

});
