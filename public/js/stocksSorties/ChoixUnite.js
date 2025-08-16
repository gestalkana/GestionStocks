document.addEventListener('DOMContentLoaded', function () {
    // Contexte spécifique pour limiter la portée (ex: un formulaire spécifique)
    const formContainer = document.querySelector('.form-produit'); // <- adapter au conteneur parent
    if (!formContainer) return; // Protection si le conteneur n'existe pas

    // Fonction pour mettre à jour l'unité
    function updateUnite(selectElement) {
        const index = selectElement.dataset.index;
        const selectedOption = selectElement.options[selectElement.selectedIndex];
        if (!selectedOption) return; // Protection

        let unite = selectedOption.getAttribute('data-unite');
        unite = unite && unite.trim() !== '' ? unite : 'Non défini';

        // Champ unité correspondant
        const uniteInput = formContainer.querySelector(`.unite-input[data-index="${index}"]`);
        if (uniteInput) {
            uniteInput.value = unite;
        }
    }

    // Initialisation et gestion des changements
    const produitSelects = formContainer.querySelectorAll('.produit-select');
    produitSelects.forEach(function (select) {
        if (select.value) {
            updateUnite(select);
        }

        select.addEventListener('change', function () {
            updateUnite(this);
        });
    });
});
