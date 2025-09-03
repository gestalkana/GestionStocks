(function () {
    document.addEventListener('DOMContentLoaded', function () {
        const btnEnregistrer = document.getElementById('btn-enregistrer');
        const btnValider = document.getElementById('btn-valider');
        const form = document.getElementById('form-sortie');

        if (!form) return;

        // Mise à jour dynamique du stock disponible quand un produit est sélectionné
        form.addEventListener('change', function (e) {
            const select = e.target;

            if (!select.classList.contains('produit-select')) return;

            const produitId = select.value;
            const row = select.closest('tr');
            if (!produitId || !row) return;

            fetch(`/produits/${produitId}/stock-disponible`)
                .then(res => res.json())
                .then(data => {
                    const stockDisponible = data.stock_disponible ?? 0;

                    // Affichage dans cellule .stock-disponible
                    const stockCell = row.querySelector('.stock-disponible');
                    if (stockCell) {
                        stockCell.textContent = stockDisponible;
                    }

                    // Mise à jour de l’attribut data-stock de l’option sélectionnée
                    const selectedOption = select.selectedOptions[0];
                    if (selectedOption) {
                        selectedOption.dataset.stock = stockDisponible;
                    }
                })
                .catch(err => {
                    console.error('Erreur récupération stock :', err);
                });
        });

        btnEnregistrer?.addEventListener('click', () => submitForm('brouillon'));
        btnValider?.addEventListener('click', () => submitForm('valide'));

        function submitForm(statut) {
            const formData = new FormData(form);
            formData.append('statut', statut);

            // ===== Validation des lignes produits et des lots =====
            const lignesProduits = form.querySelectorAll('tr');
            let erreur = false;

            lignesProduits.forEach(row => {
                const quantiteInput = row.querySelector('input.quantite-input');
                const displayLots = row.querySelector('.lots-affiches');
                const hiddenLots = row.querySelector('.lots-hidden');

                if (!quantiteInput || !displayLots || !hiddenLots) return;

                const quantiteDemandee = parseInt(quantiteInput.value) || 0;
                const inputsHidden = hiddenLots.querySelectorAll('input[type="hidden"]');

                let totalAttribue = 0;
                inputsHidden.forEach(input => {
                    const [lotId, quantite] = input.value.split(':');
                    totalAttribue += parseInt(quantite) || 0;
                });

                if (quantiteDemandee === 0) {
                    Swal.fire({
                        icon: 'warning',
                        title: 'Quantité manquante',
                        text: 'Une ou plusieurs lignes ont une quantité demandée de 0.'
                    });
                    erreur = true;
                    return;
                }

                if (inputsHidden.length === 0 || totalAttribue === 0) {
                    Swal.fire({
                        icon: 'warning',
                        title: 'Lots manquants',
                        text: 'Tous les produits doivent avoir des lots attribués.'
                    });
                    erreur = true;
                    return;
                }

                if (totalAttribue !== quantiteDemandee) {
                    Swal.fire({
                        icon: 'error',
                        title: 'Quantité incorrecte',
                        html: `La somme des quantités des lots (<strong>${totalAttribue}</strong>) ne correspond pas à la quantité demandée (<strong>${quantiteDemandee}</strong>).`
                    });
                    erreur = true;
                    return;
                }
            });

            if (erreur) return; // Arrêt si erreur détectée

            // ===== Vérification : au moins un produit sélectionné =====
            const produits = Array.from(form.querySelectorAll('select[name^="produits"]'));
            if (produits.length === 0 || produits.every(p => !p.value)) {
                Swal.fire({
                    icon: 'warning',
                    title: 'Aucun produit',
                    text: 'Veuillez ajouter au moins un produit à la sortie.'
                });
                return;
            }

               // Vérifie que le numéro d'ordre est renseigné si le statut est "valide"
                const numeroOrdre = form.querySelector('input[name="numero_ordre"]')?.value.trim();
                if (statut === 'valide' && !numeroOrdre) {
                    Swal.fire({
                        icon: 'warning',
                        title: 'Numéro d\'ordre requis',
                        text: 'Veuillez renseigner le numéro d\'ordre avant de valider.'
                    });
                    return;
                }

            // ===== Envoi du formulaire via fetch =====
            fetch(form.action, {
                method: 'POST',
                body: formData,
                headers: {
                    'X-CSRF-TOKEN': document.querySelector('meta[name="csrf-token"]').content,
                    'X-Requested-With': 'XMLHttpRequest',
                }
            })
                .then(async response => {
                    const data = await response.json();

                    if (response.status === 422) {
                        Swal.fire({
                            icon: 'error',
                            title: 'Erreur de validation',
                            text: data.message || 'Données invalides.'
                        });
                        return;
                    }

                    if (!response.ok || data.success === false) {
                        Swal.fire({
                            icon: 'error',
                            title: 'Erreur',
                            text: data.message || 'Une erreur est survenue.'
                        });
                        return;
                    }

                    Swal.fire({
                        icon: 'success',
                        title: 'Succès',
                        text: data.message
                    }).then(() => {
                        window.location.href = "/stocksSorties";
                    });
                })
                .catch(error => {
                    console.error('Erreur JS:', error);
                    Swal.fire({
                        icon: 'error',
                        title: 'Erreur inattendue',
                        text: error.message || 'Vérifiez la console.'
                    });
                });
        }
    });
})();
