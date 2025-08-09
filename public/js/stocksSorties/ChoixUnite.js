document.addEventListener('DOMContentLoaded', function () {
    // Fonction pour mettre à jour l'unité
    function updateUnite(selectElement) {
        const index = selectElement.dataset.index;
        const selectedOption = selectElement.options[selectElement.selectedIndex];
        let unite = selectedOption.getAttribute('data-unite');
        unite = unite && unite.trim() !== '' ? unite : 'Non défini';

        // Trouver le champ unité correspondant à l'index
        const uniteInput = document.querySelector(`.unite-input[data-index="${index}"]`);
        if (uniteInput) {
            uniteInput.value = unite;
        }
    }

    // Initialisation et gestion des changements
    const produitSelects = document.querySelectorAll('.produit-select');
    produitSelects.forEach(function (select) {
        // Initialiser à l'ouverture si un produit est déjà sélectionné
        if (select.value) {
            updateUnite(select);
        }

        // Ajouter l'écouteur de changement
        select.addEventListener('change', function () {
            updateUnite(this);
        });
    });
});
