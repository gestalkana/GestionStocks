document.addEventListener('DOMContentLoaded', function () {
  const form = document.getElementById('createFournisseurForm');
  const modalElement = document.getElementById('createFournisseurModal');
  const modal = bootstrap.Modal.getInstance(modalElement) || new bootstrap.Modal(modalElement);

  form.addEventListener('submit', function (event) {
    event.preventDefault();

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
        addFournisseurToTable(data.fournisseur);
        showSuccessAlert('create', 'fournisseur');
        form.reset();
        modal.hide();
      }
    })
    .catch(error => {
      alert(error.message || 'Une erreur est survenue');
    });
  });

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

  function addFournisseurToTable(fournisseur) {
    const tbody = document.querySelector('#fournisseurs table tbody');

    const tr = document.createElement('tr');
    tr.innerHTML = `
      <td><strong>${fournisseur.nom}</strong></td>
      <td>${fournisseur.telephone || '—'}</td>
      <td>${fournisseur.email || '—'}</td>
      <td>${fournisseur.adresse || '—'}</td>
      <td><span class="badge bg-info text-dark">${fournisseur.statut}</span></td>
      <td>${fournisseur.type || '—'}</td>
      <td>${new Date(fournisseur.created_at).toLocaleDateString('fr-FR')}</td>
      <td>
        <!-- Actions -->
        <a href="/fournisseurs/${fournisseur.id}/edit" class="btn btn-sm btn-outline-primary">Modifier</a>
        <form action="/fournisseurs/${fournisseur.id}" method="POST" class="d-inline" onsubmit="return confirm('Supprimer ce fournisseur ?');">
          <input type="hidden" name="_token" value="${document.querySelector('meta[name=csrf-token]').content}">
          <input type="hidden" name="_method" value="DELETE">
          <button class="btn btn-sm btn-outline-danger">Supprimer</button>
        </form>
      </td>
    `;

    tbody.appendChild(tr);
  }

  function showSuccessAlert(action, model) {
    alert(`✅ ${model.charAt(0).toUpperCase() + model.slice(1)} ${action === 'create' ? 'ajouté' : 'mis à jour'} avec succès !`);
  }
});
