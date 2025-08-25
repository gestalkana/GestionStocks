(() => {
document.addEventListener('DOMContentLoaded', () => {
    const form = document.querySelector('[data-module="form-sortie"]');
    if (!form) {
        console.info('[SortieModule] Formulaire de sortie non présent sur cette page. Script ignoré.');
        return;
    }

    // Appel API pour mettre à jour dynamiquement le stock disponible
    document.addEventListener('change', function (e) {
        if (e.target.classList.contains('produit-select')) {
            const select = e.target;
            const produitId = select.value;
            const row = select.closest('tr');

            if (!produitId) return;

            fetch(`/produits/${produitId}/stock-disponible`)
                .then(res => res.json())
                .then(data => {
                    const stockDisponible = data.stock_disponible ?? 0;

                    // Affichage dans cellule .stock-disponible
                    const stockCell = row.querySelector('.stock-disponible');
                    if (stockCell) {
                        stockCell.textContent = stockDisponible;
                    }

                    // Mise à jour du data-stock sur l’option sélectionnée
                    const selectedOption = select.selectedOptions[0];
                    if (selectedOption) {
                        selectedOption.dataset.stock = stockDisponible;
                    }
                })
                .catch(err => {
                    console.error('Erreur récupération stock :', err);
                });
        }
    });

    // Fonction qui envoie vraiment le formulaire (ajax)
    function envoyerFormulaire(statut) {
        const formData = new FormData(form);
        formData.append('statut', statut);

        const csrfToken = document.querySelector('meta[name="csrf-token"]')?.getAttribute('content');
        if (!csrfToken) {
            Swal.fire({
                icon: 'error',
                title: 'Erreur CSRF',
                text: 'Token CSRF manquant.'
            });
            return;
        }

        fetch('/stocks-sorties/ajax-store', {
            method: 'POST',
            headers: { 'X-CSRF-TOKEN': csrfToken },
            body: formData
        })
        .then(res => {
            if (!res.ok) throw new Error(`Erreur HTTP ${res.status}`);
            return res.json();
        })
        .then(data => {
            if (data.success) {
                Swal.fire({
                    icon: 'success',
                    title: 'Succès',
                    text: data.message
                }).then(() => window.location.reload());
            } else {
                Swal.fire({
                    icon: 'error',
                    title: 'Erreur',
                    html: data.message || 'Une erreur est survenue.'
                });
            }
        })
        .catch(err => {
            Swal.fire({
                icon: 'error',
                title: 'Erreur serveur',
                text: err.message || 'Erreur inconnue lors de la soumission.'
            });
        });
    }

    // Fonction principale de validation avant envoi
    function submitSortie(statut) {
    const rows = document.querySelectorAll('#produits-sortie-body tr');
    const erreurs = [];
    const stockDepasse = [];

    const client = form.querySelector('[name="client"]')?.value.trim();
    const numeroOrdre = form.querySelector('[name="numero_ordre"]')?.value.trim();

    if (statut === 'valide' && !client) {
        erreurs.push('- Le champ "Client / Destination" est requis.');
    }

    if (!numeroOrdre) {
        erreurs.push('- Le champ "N° d’ordre de sortie" est requis.');
    }

    rows.forEach((row, index) => {
        const produitSelect = row.querySelector('.produit-select');
        const quantiteInput = row.querySelector('.quantite-input');
        const lotsHidden = row.querySelector('.lots-hidden');

        const produitOption = produitSelect?.selectedOptions[0];
        const produitId = produitSelect?.value.trim();
        const quantite = parseInt(quantiteInput?.value);
        const lotsText = lotsHidden?.textContent.trim();

        const stockDisponible = parseInt(produitOption?.dataset.stock ?? 0);

        if (!produitId) {
            erreurs.push(`- Produit manquant à la ligne ${index + 1}`);
        }

        if (!quantite || quantite <= 0) {
            erreurs.push(`- Quantité invalide à la ligne ${index + 1}`);
        }

        if (quantite > stockDisponible) {
            if (statut === 'valide') {
                erreurs.push(`- Quantité demandée (${quantite}) dépasse le stock disponible (${stockDisponible}) à la ligne ${index + 1}`);
            } else {
                stockDepasse.push(`- Quantité demandée (${quantite}) dépasse le stock disponible (${stockDisponible}) à la ligne ${index + 1}`);
            }
        }

        if (statut === 'valide' && lotsHidden?.querySelectorAll('input').length === 0) {
            erreurs.push(`- Aucun lot attribué à la ligne ${index + 1}`);
        }
    });

    if (erreurs.length > 0) {
        Swal.fire({
            icon: 'error',
            title: 'Validation échouée',
            html: erreurs.join('<br>')
        });
        return;
    }

    if (statut === 'brouillon' && stockDepasse.length > 0) {
        Swal.fire({
            icon: 'warning',
            title: 'Attention',
            html: stockDepasse.join('<br>') + '<br><br>Souhaitez-vous continuer quand même ?',
            showCancelButton: true,
            confirmButtonText: 'Oui, enregistrer',
            cancelButtonText: 'Annuler'
        }).then(result => {
            if (result.isConfirmed) {
                copierLotsDansFormulaireEtEnvoyer(statut);
            }
        });
        return;
    }

       copierLotsDansFormulaireEtEnvoyer(statut);
    }
    
    function copierLotsDansFormulaireEtEnvoyer(statut) {
    // Supprimer les anciens champs s'ils existent déjà
    const anciens = document.querySelectorAll('.input-lots-temp');
    anciens.forEach(el => el.remove());

    // Copier tous les <input type="hidden"> des .lots-hidden dans le formulaire
    const lotsHiddenInputs = document.querySelectorAll('.lots-hidden input');

    lotsHiddenInputs.forEach(input => {
        const clone = input.cloneNode();
        clone.classList.add('input-lots-temp'); // Marque temporaire
        form.appendChild(clone);
    });

    // Envoyer ensuite le formulaire
    envoyerFormulaire(statut);
    }

    // Boutons
    const btnEnregistrer = document.getElementById('btn-enregistrer');
    const btnValider = document.getElementById('btn-valider');

    if (btnEnregistrer) {
        btnEnregistrer.addEventListener('click', () => submitSortie('brouillon'));
    }

    if (btnValider) {
        btnValider.addEventListener('click', () => submitSortie('valide'));
    }
});
})();
