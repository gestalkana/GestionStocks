document.addEventListener('DOMContentLoaded', function () {
    const inputRecherche = document.querySelector('#filtreRecherche');
    const selectCategorie = document.querySelector('#filtreCategorie');
    const selectStatut = document.querySelector('#filtreStatut');
    const selectEntrepot = document.querySelector('#filtreEntrepot'); // 🆕
    const tbody = document.querySelector('#produitsTableBody');

    // Cloner toutes les lignes d'origine
    const allRows = Array.from(tbody.querySelectorAll('tr')).map(row => row.cloneNode(true));

    // Ligne "aucun produit"
    const emptyRow = document.createElement('tr');
    emptyRow.id = 'emptyRow';
    emptyRow.innerHTML = `<td colspan="8" class="text-center text-muted">Aucun produit correspondant.</td>`;

    function filtrerTableau() {
        const recherche = inputRecherche.value.toLowerCase().trim();
        const categorie = selectCategorie.value;
        const statut = selectStatut.value.toLowerCase().replace(/\s+/g, '_');
        const entrepot = selectEntrepot.value; // 🆕

        tbody.innerHTML = '';
        let anyVisible = false;

        allRows.forEach(row => {
            if (row.id === 'emptyRow') return;

            const nomProduit = row.cells[2].innerText.toLowerCase();
            const badgeCategorie = row.cells[3].querySelector('span');
            const nomCategorie = badgeCategorie ? badgeCategorie.innerText.toLowerCase() : '';
            const categorieId = row.cells[3].getAttribute('data-categorie-id') || '';
            const statutProduit = row.querySelector('td[data-statut]')?.getAttribute('data-statut');
            const entrepotId = row.getAttribute('data-entrepot-id') || ''; // 🆕

            let match = true;

            // Recherche par nom ou catégorie
            if (recherche && !nomProduit.includes(recherche) && !nomCategorie.includes(recherche)) {
                match = false;
            }

            // Filtre par catégorie
            if (categorie && categorieId !== categorie) match = false;

            // Filtre par statut
            if (statut && statutProduit !== statut) match = false;

            // Filtre par magasin (entrepôt) 🆕
            if (entrepot) {
                if (entrepot === 'sans_magasin') {
                    // Produit sans entrepôt assigné
                    if (entrepotId && entrepotId.trim() !== '') match = false;
                } else {
                    // Produit avec entrepôt spécifique
                    if (entrepotId !== entrepot) match = false;
                }
            }

            if (match) {
                tbody.appendChild(row.cloneNode(true));
                anyVisible = true;
            }
        });

        if (!anyVisible) tbody.appendChild(emptyRow);
    }

    // Déclencheurs instantanés
    inputRecherche.addEventListener('keyup', filtrerTableau);
    selectCategorie.addEventListener('change', filtrerTableau);
    selectStatut.addEventListener('change', filtrerTableau);
    selectEntrepot.addEventListener('change', filtrerTableau); // 🆕

    // Réinitialisation
    const resetBtn = document.getElementById('resetFiltres');
    resetBtn.addEventListener('click', function () {
        inputRecherche.value = '';
        selectCategorie.value = '';
        selectStatut.value = '';
        selectEntrepot.value = ''; // 🆕
        tbody.innerHTML = '';
        allRows.forEach(row => tbody.appendChild(row.cloneNode(true)));
    });
});
