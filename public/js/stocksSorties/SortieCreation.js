document.addEventListener('DOMContentLoaded', function () {
    const form = document.getElementById('createStocksSortiesForm');
    const produitSelect = document.getElementById('produitSelect');
    const quantiteInput = document.getElementById('quantiteInput');

    let stockDisponible = 0;

    // Crée le message d'information pour le stock disponible
    let stockMsg = document.getElementById('stockDisponibleMsg');
    if (!stockMsg && quantiteInput) {
        stockMsg = document.createElement('div');
        stockMsg.id = 'stockDisponibleMsg';
        stockMsg.className = 'form-text text-muted mt-1';
        quantiteInput.parentNode.appendChild(stockMsg);
    }

    // Lors du changement de produit, récupérer le stock disponible
    if (produitSelect) {
        produitSelect.addEventListener('change', function () {
            const produitId = this.value;
            stockMsg.textContent = '';
            quantiteInput.value = '';
            quantiteInput.removeAttribute('max');
            quantiteInput.disabled = true;

            if (produitId) {
                fetch(`/produits/${produitId}/stock-disponible`)
                    .then(res => res.json())
                    .then(data => {
                        stockDisponible = parseFloat(data.stock_disponible ?? 0);
                        stockMsg.textContent = `Stock disponible : ${stockDisponible}`;
                        quantiteInput.setAttribute('max', stockDisponible);
                        quantiteInput.disabled = stockDisponible <= 0;

                        if (stockDisponible <= 0) {
                            stockMsg.classList.add('text-danger');
                            stockMsg.textContent += ' — Stock insuffisant';
                        } else {
                            stockMsg.classList.remove('text-danger');
                        }
                    })
                    .catch(() => {
                        stockMsg.textContent = 'Erreur lors de la récupération du stock.';
                        stockMsg.classList.add('text-danger');
                        quantiteInput.disabled = true;
                    });
            } else {
                stockDisponible = 0;
                stockMsg.textContent = '';
                quantiteInput.disabled = true;
            }
        });
    }

    // Gestion de la soumission AJAX du formulaire
    if (!form) return;

    form.addEventListener('submit', function (event) {
        event.preventDefault();

        const quantite = parseFloat(quantiteInput.value);
        if (quantite > stockDisponible) {
            alert(`Quantité demandée (${quantite}) supérieure au stock disponible (${stockDisponible}).`);
            return;
        }

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
            const contentType = response.headers.get('content-type') || '';
            if (!response.ok) {
                const errorData = contentType.includes('application/json') ? await response.json() : await response.text();
                if (response.status === 422 && errorData.errors) {
                    handleErrors(errorData.errors);
                } else {
                    throw new Error('Erreur serveur: ' + (errorData.message || errorData));
                }
                return;
            }

            const data = await response.json();

            if (data && data.sortie) {
                addSortieToTable(data.sortie);
                Swal.fire({
                    icon: 'success',
                    title: 'Sortie enregistrée',
                    text: data.message || 'Stock sorti avec succès.',
                    showConfirmButton: false,
                    timer: 2500
                });

                form.reset();
                stockDisponible = 0;
                quantiteInput.disabled = true;
                stockMsg.textContent = '';

                const collapseEl = document.getElementById('formSortieCollapse');
                if (collapseEl) {
                    bootstrap.Collapse.getInstance(collapseEl)?.hide();
                }
            }
        })
        .catch(error => {
            console.error(error);
            alert(error.message || 'Une erreur est survenue');
        });
    });

    // Affichage des erreurs de validation
    function handleErrors(errors) {
        // Nettoyage des anciennes erreurs
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

    // Ajout dynamique de la sortie dans le tableau
    function addSortieToTable(sortie) {
        const tbody = document.querySelector('#stocksSortiesTable tbody');
        if (!tbody) return;

        const tr = document.createElement('tr');
        tr.innerHTML = `
            <td>#SV${String(sortie.id).padStart(4, '0')}</td>
            <td>${sortie.produit.nom}</td>
            <td>${sortie.quantite}</td>
            <td>${new Date(sortie.date_sortie).toLocaleDateString('fr-FR')}</td>
            <td>${sortie.motif || '—'}</td>
            <td>${sortie.user?.name || '—'}</td>
        `;
        tbody.prepend(tr);
    }
});
