document.addEventListener('DOMContentLoaded', function () {
    const form = document.getElementById('createProductForm');

    if (!form) return;

    form.addEventListener('submit', function (event) {
        event.preventDefault();
        clearErrors(); // au début aussi

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
            if (data && data.produit) {
                //alert(data.message || 'Produit créé avec succès');
                //Message via sweetAlert2
                // Swal.fire({
                //     icon: 'success',
                //     title: 'Produit ajouté avec succès',
                //     text: data.message || 'Le produit a bien été enregistré.',
                //     showConfirmButton: false,
                //     timer: 2500,
                //     timerProgressBar: true,
                //     position: 'center', // <- Valeur Par défaut
                //     background: '#f0fdf4',
                //     color: '#065f46',
                // });
                showSuccessAlert('create', 'produit');

                form.reset();
                clearErrors();
                addProductToTable(data.produit);
            }
        })
        .catch(error => {
            console.error('Erreur attrapée:', error);
            alert(error.message || 'Une erreur inattendue est survenue.');
        });

        function clearErrors() {
            form.querySelectorAll('.is-invalid').forEach(el => el.classList.remove('is-invalid'));
            form.querySelectorAll('.invalid-feedback').forEach(el => el.remove());
        }

        function handleErrors(errors) {
            for (const [field, messages] of Object.entries(errors)) {
                const input = form.querySelector(`[name="${field}"]`);
                if (input) {
                    input.classList.add('is-invalid');
                    const feedback = document.createElement('div');
                    feedback.classList.add('invalid-feedback');
                    feedback.innerText = messages.join(', ');
                    input.parentNode.appendChild(feedback);
                }
            }
        }
    });
});
function addProductToTable(produit) {
    const tbody = document.getElementById('produitsTableBody');
    if (!tbody) return;

    const tr = document.createElement('tr');

    const statut = (produit.quantite && produit.quantite > 0) ? 'Disponible' : 'Rupture';
    const statutBadge = statut === 'Disponible' ? 'bg-success' : 'bg-danger';
    const quantite = produit.quantite ?? 0;

    const prixAchat = parseFloat(produit.prix_achat || 0).toLocaleString('fr-FR', {
        style: 'currency',
        currency: 'MGA',
        minimumFractionDigits: 2
    }).replace('MGA', 'Ar');

    const prixVente = parseFloat(produit.prix_unitaire || 0).toLocaleString('fr-FR', {
        style: 'currency',
        currency: 'MGA',
        minimumFractionDigits: 2
    }).replace('MGA', 'Ar');

    // Tooltip
    const tooltipContent = `
        <strong>${produit.nom}</strong><br>
        ${produit.description ? produit.description.substring(0, 100) : ''}<br>
        <small style="color: #007bff; font-weight: 600;">Cliquez pour voir plus</small>
    `;

    const link = document.createElement('a');
    link.href = `/produits/${produit.id}`;
    link.className = 'text-dark fw-semibold text-decoration-none hover-color';
    link.setAttribute('data-tippy-content', tooltipContent);
    link.textContent = produit.nom;

    // td pour le nom + description
    const tdNom = document.createElement('td');
    const divWrapper = document.createElement('div');
    const divNom = document.createElement('div');
    divNom.appendChild(link);
    divWrapper.appendChild(divNom);

    if (produit.description) {
        const small = document.createElement('small');
        small.className = 'text-muted';
        small.textContent = produit.description.substring(0, 40);
        divWrapper.appendChild(small);
    }

    tdNom.appendChild(divWrapper);

    // Construction des autres <td>
    const cells = [
        `<td><input type="checkbox" class="row-checkbox" /></td>`,
        `<td>${produit.code_produit}</td>`,
        tdNom.outerHTML, // insère le bloc HTML proprement
        `<td><span class="badge bg-secondary">${produit.categorie?.nom ?? 'N/A'}</span></td>`,
        `<td>${quantite}</td>`,
        `<td>${prixAchat}</td>`,
        `<td>${prixVente}</td>`,
        `<td><span class="badge ${statutBadge}">${statut}</span></td>`,
    ];

    tr.innerHTML = cells.join('');
    tbody.prepend(tr);

    // Appliquer tippy (assure-toi qu'il est bien chargé)
    tippy('[data-tippy-content]', {
        allowHTML: true,
        placement: 'bottom',
        theme: 'light-border',
        animation: 'fade',
    });
}

/*
function addProductToTable(produit) {
    const tbody = document.getElementById('produitsTableBody');

    if (!tbody) return;

    const tr = document.createElement('tr');

    const statut = (produit.quantite && produit.quantite > 0) ? 'Disponible' : 'Rupture';
    const statutBadge = statut === 'Disponible' ? 'bg-success' : 'bg-danger';
    const quantite = produit.quantite ?? 0;

    const prixAchat = parseFloat(produit.prix_achat || 0).toLocaleString('fr-FR', {
        style: 'currency',
        currency: 'MGA',
        minimumFractionDigits: 2
    }).replace('MGA', 'Ar');

    const prixVente = parseFloat(produit.prix_unitaire || 0).toLocaleString('fr-FR', {
        style: 'currency',
        currency: 'MGA',
        minimumFractionDigits: 2
    }).replace('MGA', 'Ar');

    tr.innerHTML = `
        <td><input type="checkbox" class="row-checkbox" /></td>
        <td>${produit.code_produit}</td>
        <td>
            <div>
                <div>
                ${produit.nom}
                </div>
                ${produit.description ? `<small class="text-muted">${produit.description}</small>` : ''}
            </div>
        </td>
        <td>
            <span class="badge bg-secondary">
                ${produit.categorie?.nom ?? 'N/A'}
            </span>
        </td>
        <td>${quantite}</td>
        <td>${prixAchat}</td>
        <td>${prixVente}</td>
        <td><span class="badge ${statutBadge}">${statut}</span></td>
    `;

    tbody.prepend(tr);
}
*/