document.addEventListener('DOMContentLoaded', function () {
    const produitSelect = document.getElementById('produitSelect');
    const uniteInput = document.getElementById('uniteInput');
    const uniteHiddenInput = document.getElementById('uniteHiddenInput'); // facultatif

    // Protection : on ne continue que si les éléments obligatoires existent
    if (!produitSelect || !uniteInput) return;

    function updateUnite() {
        const selectedOption = produitSelect.options[produitSelect.selectedIndex];
        if (!selectedOption) return;

        let unite = selectedOption.getAttribute('data-unite');
        unite = unite && unite.trim() !== '' ? unite : 'Non défini';

        uniteInput.value = unite;

        if (uniteHiddenInput) {
            uniteHiddenInput.value = unite;
        }
    }

    // Événement sur changement de sélection
    produitSelect.addEventListener('change', updateUnite);

    // Initialiser à l’ouverture si une valeur est déjà sélectionnée
    if (produitSelect.value) {
        updateUnite();
    }
});
