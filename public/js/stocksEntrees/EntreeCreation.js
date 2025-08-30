(() => {
  document.addEventListener('DOMContentLoaded', () => {
    const form = document.querySelector('[data-module="stocks-entrees-form"]');
    if (!form) {
      console.info('[StocksEntreesModule] Formulaire d\'entrée de stock non présent sur cette page. Script ignoré.');
      return;
    }

    console.info('[StocksEntreesModule] Initialisé');

    // Mettre à jour automatiquement l'unité en fonction du produit choisi
    const produitSelect = document.getElementById('produitSelect');
    const uniteInput = document.getElementById('uniteInput');

    produitSelect?.addEventListener('change', () => {
      const selectedOption = produitSelect.selectedOptions[0];
      const unite = selectedOption?.dataset.unite || '';
      uniteInput.value = unite;
    });

    form.addEventListener('submit', async (event) => {
      event.preventDefault();

      const formData = new FormData(form);

      try {
        const response = await fetch(form.action, {
          method: 'POST',
          headers: {
            'X-Requested-With': 'XMLHttpRequest',
            'X-CSRF-TOKEN': form.querySelector('input[name="_token"]')?.value || '',
            'Accept': 'application/json'
          },
          body: formData
        });

        if (!response.ok) {
          const text = await response.text();

          if (response.status === 422) {
            // Erreurs de validation
            const data = JSON.parse(text);
            handleErrors(data.errors);

          } else if (response.status === 409) {
            // Produit déjà enregistré dans un autre magasin
            const data = JSON.parse(text);
            Swal.fire({
              icon: 'warning',
              title: 'Produit déjà enregistré',
              text: data.message || 'Ce produit est déjà enregistré dans un autre magasin.',
              confirmButtonText: 'OK'
            });

          } else {
            throw new Error('Erreur serveur: ' + text);
          }
          return;
        }

        const data = await response.json();

        if (data && data.entree) {
          addEntryToTable(data.entree);

          Swal.fire({
            icon: 'success',
            title: 'Stock ajouté avec succès',
            text: data.message || 'Le stock a bien été enregistré.',
            showConfirmButton: false,
            timer: 2500,
            timerProgressBar: true,
            position: 'center',
            background: '#f0fdf4',
            color: '#065f46',
          });

          form.reset();
          uniteInput.value = '';

          const collapseEl = document.getElementById('formCollapse');
          if (collapseEl) {
            const bsCollapse = bootstrap.Collapse.getInstance(collapseEl);
            if (bsCollapse) bsCollapse.hide();
          }
        }

      } catch (error) {
        alert(error.message || 'Une erreur est survenue');
      }
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

    function addEntryToTable(entree) {
      const tbody = document.querySelector('#stocksEntreesTable tbody');
      if (!tbody) return;

      const tr = document.createElement('tr');
      tr.innerHTML = `
        <td>${entree.numero_lot}</td>
        <td>${entree.produit.nom}</td>
        <td>${entree.quantite}</td>
        <td>${new Date(entree.date_entree).toLocaleDateString('fr-FR')}</td>
        <td>${entree.date_expiration ? new Date(entree.date_expiration).toLocaleDateString('fr-FR') : '—'}</td>
        <td>${entree.stock_avant ?? 0}</td>
        <td>${entree.stock_apres ?? 0}</td>
        <td>${entree.entrepot?.nom || '—'}</td>
        <td>${entree.user?.name || '—'}</td>
        <td class="text-end">
          <a href="/stocksEntrees/${entree.id}" class="btn btn-sm btn-outline-secondary me-1"><i class="bi bi-eye"></i></a>
          <a href="/stocksEntrees/${entree.id}/edit" class="btn btn-sm btn-outline-warning me-1"><i class="bi bi-pencil-square"></i></a>
          <form action="/stocksEntrees/${entree.id}" method="POST" class="d-inline" onsubmit="return confirm('Confirmer la suppression ?')">
            <input type="hidden" name="_token" value="${document.querySelector('meta[name=csrf-token]')?.content}">
            <input type="hidden" name="_method" value="DELETE">
            <button class="btn btn-sm btn-outline-danger"><i class="bi bi-trash"></i></button>
          </form>
        </td>
      `;
      tbody.prepend(tr);
    }
  });
})();
