document.addEventListener('DOMContentLoaded', () => {
  attachEditEntreeListeners();

  const editEntreeForm = document.getElementById('editEntreeForm');
  if (editEntreeForm) {
    editEntreeForm.addEventListener('submit', function (e) {
      e.preventDefault();

      const id = document.getElementById('editEntreeId')?.value;
      const csrfToken = document.querySelector('meta[name="csrf-token"]')?.getAttribute('content');

      const data = {
        quantite: document.getElementById('editQuantite')?.value,
        date_expiration: document.getElementById('editDateExpiration')?.value,
      };

      fetch(`/stocksEntrees/${id}`, {
        method: 'PUT',
        headers: {
          'X-CSRF-TOKEN': csrfToken,
          'Accept': 'application/json',
          'Content-Type': 'application/json',
        },
        body: JSON.stringify(data)
      })
      .then(async response => {
        const responseData = await response.json();
        if (!response.ok) {
          let message = "Erreur lors de la mise à jour de l'entrée.";
          if (responseData.errors) {
            message = Object.values(responseData.errors).flat().join("\n");
          } else if (responseData.message) {
            message = responseData.message;
          }
          throw new Error(message);
        }

        return responseData;
      })
      .then(data => {
        const entree = data.stocksEntrees;
        const modalEl = document.getElementById('editEntreeModal');
        if (modalEl) {
          bootstrap.Modal.getOrCreateInstance(modalEl).hide();
          setTimeout(forceCleanModal, 350);
        }

        showSuccessAlert('update', 'entrée');

        const row = document.querySelector(`#entree-row-${entree.id}`);
        if (row) {
          row.innerHTML = `
            <td>#MV${String(entree.id).padStart(4, '0')}</td>
            <td>${entree.produit.nom}</td>
            <td>${entree.quantite}</td>
            <td>${formatDate(entree.date_entree)}</td>
            <td>${formatDate(entree.date_expiration)}</td>
            <td>${entree.stock_avant ?? ''}</td>
            <td>${entree.stock_apres ?? ''}</td>
            <td>${entree.user.name}</td>
            <td class="text-end">
              <a href="/stocksEntrees/${entree.id}" class="btn btn-sm btn-outline-secondary me-1" title="Voir">
                <i class="bi bi-eye"></i>
              </a>
              <button type="button"
                      class="btn btn-outline-warning btn-sm edit-entree-btn me-1"
                      data-id="${entree.id}"
                      data-quantite="${entree.quantite}"
                      data-date="${entree.date_expiration}">
                <i class="bi bi-pencil-square" title="Modifier"></i>
              </button>
              <form action="/stocksEntrees/${entree.id}" method="POST" class="d-inline" onsubmit="return confirm('Confirmer la suppression ?')">
                <input type="hidden" name="_token" value="${csrfToken}">
                <input type="hidden" name="_method" value="DELETE">
                <button type="submit" class="btn btn-sm btn-outline-danger" title="Supprimer">
                  <i class="bi bi-trash"></i>
                </button>
              </form>
            </td>
          `;
          attachEditEntreeListeners();
        }
      })
      .catch(error => {
        alert(error.message);
        console.error("Erreur lors de la modification de l'entrée :", error);
      });
    });
  }

  const cancelBtn = document.getElementById('cancelEditEntreeBtn');
  if (cancelBtn) {
    cancelBtn.addEventListener('click', () => {
      const modalEl = document.getElementById('editEntreeModal');
      if (modalEl) {
        bootstrap.Modal.getOrCreateInstance(modalEl).hide();
        setTimeout(forceCleanModal, 350);
      }
    });
  }
});

function fillEditEntreeForm(data) {
  const idEl = document.getElementById('editEntreeId');
  const dateEl = document.getElementById('editDateExpiration');
  const qteEl = document.getElementById('editQuantite');
  if (idEl) idEl.value = data.id;
  if (dateEl) dateEl.value = data.date_expiration;
  if (qteEl) qteEl.value = data.quantite;
}

function attachEditEntreeListeners() {
  document.querySelectorAll('.edit-entree-btn').forEach(button => {
    button.addEventListener('click', function () {
      fillEditEntreeForm({
        id: this.dataset.id,
        date_expiration: this.dataset.date,
        quantite: this.dataset.quantite,
      });

      const modal = new bootstrap.Modal(document.getElementById('editEntreeModal'));
      modal.show();
    });
  });
}

function formatDate(dateStr) {
  const date = new Date(dateStr);
  return date.toLocaleDateString('fr-FR');
}

function forceCleanModal() {
  document.querySelectorAll('.modal-backdrop').forEach(el => el.remove());
  const stillOpen = document.querySelector('.modal.show');
  if (!stillOpen) {
    document.body.classList.remove('modal-open');
    document.body.style.paddingRight = '';
    document.body.style.overflowY = '';
  }
}
