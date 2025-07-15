//Catégorie Creation
document.addEventListener('DOMContentLoaded', function () {
  const form = document.getElementById('createCategoryForm');
  const modalElement = document.getElementById('createCategoryModal');
  const modal = bootstrap.Modal.getInstance(modalElement) || new bootstrap.Modal(modalElement);

  form.addEventListener('submit', function (event) {
    event.preventDefault(); // Bloque l'envoi classique du formulaire

    const formData = new FormData(form);

    fetch(form.action, {
      method: 'POST',
      headers: {
        'X-Requested-With': 'XMLHttpRequest', // Pour indiquer que c'est une requête AJAX
        'X-CSRF-TOKEN': form.querySelector('input[name="_token"]').value, // CSRF token Laravel
        'Accept': 'application/json' // Pour que Laravel retourne JSON en cas d'erreur
      },
      body: formData
    })
    .then(async response => {
  if (!response.ok) {
    const text = await response.text();
    console.log('Erreur réponse:', text);
    if (response.status === 422) {
      const data = JSON.parse(text);
      handleErrors(data.errors);
    } else {
      throw new Error('Erreur serveur: ' + text);
    }
  } else {
    return response.json();
  }
})
    .then(data => {
      if (data) {
        // Supposons que la réponse contient la nouvelle catégorie
        addCategoryToTable(data.category); // Fonction à créer pour mettre à jour le tableau
        form.reset();
        modal.hide();
      }
    })
    .catch(error => {
      alert(error.message || 'Une erreur est survenue');
    });
  });

  // Fonction pour afficher les erreurs de validation
  function handleErrors(errors) {
    // Efface les erreurs précédentes
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

  // Fonction pour ajouter la nouvelle catégorie dans le tableau HTML
  function addCategoryToTable(category) {
    const tbody = document.querySelector('#categories table tbody');
    const rowCount = tbody.querySelectorAll('tr').length;

    // Crée une nouvelle ligne
    const tr = document.createElement('tr');
    tr.innerHTML = `
      <td>${rowCount + 1}</td>
      <td><div><strong>${category.nom}</strong></div></td>
      <td>${category.description || '—'}</td>
      <td><span class="badge bg-info text-dark">${category.products_count || 0}</span></td>
      <td>${new Date(category.created_at).toLocaleDateString('fr-FR')}</td>
      <td>
        <a href="/categories/${category.id}/edit" class="btn btn-sm btn-outline-primary">Modifier</a>
        <form action="/categories/${category.id}" method="POST" class="d-inline" onsubmit="return confirm('Supprimer cette catégorie ?');">
          <input type="hidden" name="_token" value="{{ csrf_token() }}">
          <input type="hidden" name="_method" value="DELETE">
          <button class="btn btn-sm btn-outline-danger">Supprimer</button>
        </form>
      </td>
    `;
    tbody.appendChild(tr);
  }
});
