(function () {
    // Fonction pour ajouter l'écouteur de changement sur un select produit
    function ajouterEcouteurProduit(selectElement) {
        const index = selectElement.dataset.index;
        const uniteInput = document.querySelector(`input.unite-input[data-index="${index}"]`);

        if (!uniteInput) return;

        selectElement.addEventListener('change', function () {
            const selectedOption = this.options[this.selectedIndex];
            const unite = selectedOption.dataset.unite || 'Non défini';
            uniteInput.value = unite;
        });

        // Initialisation automatique si une valeur est déjà sélectionnée
        if (selectElement.value) {
            const selectedOption = selectElement.options[selectElement.selectedIndex];
            const unite = selectedOption.dataset.unite || 'Non défini';
            uniteInput.value = unite;
        }
    }

    // Quand le DOM est prêt
    document.addEventListener('DOMContentLoaded', function () {
        // Ajouter l'écouteur à la première ligne
        const premierSelect = document.querySelector('select[name="produits[0][produit_id]"]');
        if (premierSelect) {
            ajouterEcouteurProduit(premierSelect);
        }

        // Si tu ajoutes des lignes dynamiquement ailleurs, expose la fonction dans le scope local :
        window.ajouterEcouteurProduit = ajouterEcouteurProduit; //  uniquement si nécessaire
    });
})();
