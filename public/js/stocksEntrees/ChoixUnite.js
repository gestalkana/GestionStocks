document.addEventListener('DOMContentLoaded', function () {
    const produitSelect = document.getElementById('produitSelect');
    const uniteInput = document.getElementById('uniteInput');
    const uniteHiddenInput = document.getElementById('uniteHiddenInput'); // facultatif

    produitSelect.addEventListener('change', function () {
        const selectedOption = produitSelect.options[produitSelect.selectedIndex];
        let unite = selectedOption.getAttribute('data-unite');
        unite = unite && unite.trim() !== '' ? unite : 'Non défini';
        uniteInput.value = unite;

        if (uniteHiddenInput) {
            uniteHiddenInput.value = unite;
        }
    });

    // Initialiser si un produit est déjà sélectionné
    if (produitSelect.value) {
        const selectedOption = produitSelect.options[produitSelect.selectedIndex];
        let unite = selectedOption.getAttribute('data-unite');
        unite = unite && unite.trim() !== '' ? unite : 'Non défini';
        uniteInput.value = unite;

        if (uniteHiddenInput) {
            uniteHiddenInput.value = unite;
        }
    }
});
