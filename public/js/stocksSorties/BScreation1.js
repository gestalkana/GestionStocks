(function () {
    document.addEventListener('DOMContentLoaded', function () {
        const btnEnregistrer = document.getElementById('btn-enregistrer');
        const btnValider = document.getElementById('btn-valider');
        const form = document.getElementById('form-sortie');

        if (!form) return;

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


        btnEnregistrer?.addEventListener('click', () => submitForm('brouillon'));
        btnValider?.addEventListener('click', () => submitForm('valide'));

        function submitForm(statut) {
            const formData = new FormData(form);

            // Ajout dynamique du statut au formulaire
            formData.append('statut', statut);

            // Vérifie qu'au moins un produit est sélectionné
            const produits = Array.from(form.querySelectorAll('select[name^="produits"]'));
            if (produits.length === 0 || produits.every(p => !p.value)) {
                Swal.fire({
                    icon: 'warning',
                    title: 'Aucun produit',
                    text: 'Veuillez ajouter au moins un produit à la sortie.'
                });
                return;
            }

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
                    const message = data.message || 'Données invalides.';
                    Swal.fire({
                        icon: 'error',
                        title: 'Erreur de validation',
                        text: message
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