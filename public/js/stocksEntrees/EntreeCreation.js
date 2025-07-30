document.addEventListener('DOMContentLoaded', function () {
    const form = document.getElementById('createStocksEntreesForm');

    // Vérifie que le formulaire existe avant d'ajouter l'écouteur
    if (!form) return;

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
                const collapseEl = document.getElementById('formCollapse');
                if (collapseEl) {
                    bootstrap.Collapse.getInstance(collapseEl)?.hide();
                }
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

    function addEntryToTable(entree) {
        const tbody = document.querySelector('#stocksEntreesTable tbody');
        if (!tbody) return;

        const tr = document.createElement('tr');
        tr.innerHTML = `
            <td>#MV${String(entree.id).padStart(4, '0')}</td>
            <td>${entree.produit.nom}</td>
            <td>${entree.quantite}</td>
            <td>${new Date(entree.date_entree).toLocaleDateString('fr-FR')}</td>
            <td>${new Date(entree.date_expiration).toLocaleDateString('fr-FR')}</td>
            <td>${entree.stock_avant ?? 0}</td>
            <td>${entree.stock_apres ?? 0}</td>
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

    function showSuccessAlert(type, label) {
        alert(` ${label.charAt(0).toUpperCase() + label.slice(1)} créée avec succès.`);
    }
});
