(function () {
    document.addEventListener('DOMContentLoaded', function () {
        const searchInput = document.querySelector('#searchInput');
        const monthFilter = document.querySelector('#monthFilter');
        const entrepotFilter = document.querySelector('#entrepotFilter');
        const userFilter = document.querySelector('#userFilter');
        const resetBtn = document.querySelector('#resetFilters');
        const tbody = document.querySelector('#stocksEntreesTable tbody');

        if (!tbody) return;

        // Injecté via Blade dans <body data-current-user-id="{{ auth()->id() }}">
        const currentUserId = document.body.dataset.currentUserId;

        // Cloner toutes les lignes au chargement
        const allRows = Array.from(tbody.querySelectorAll('.entree-row')).map(row => row.cloneNode(true));

        const emptyRow = document.createElement('tr');
        emptyRow.id = 'emptyRow';
        emptyRow.innerHTML = `
            <td colspan="10" class="text-center text-muted py-4">
                <i class="bi bi-inbox me-2 fs-5"></i> Aucun résultat trouvé.
            </td>`;

        function filtrerTableau() {
            const search = searchInput.value.toLowerCase().trim();
            const mois = monthFilter.value;
            const entrepotId = entrepotFilter.value;
            const utilisateur = userFilter.value;

            tbody.innerHTML = '';
            let anyVisible = false;

            allRows.forEach(row => {
                const lot = row.getAttribute('data-lot') || '';
                const produit = row.getAttribute('data-produit') || '';
                const rowMois = row.getAttribute('data-mois');
                const rowEntrepotId = row.getAttribute('data-entrepot-id') || '';
                const rowUserId = row.getAttribute('data-user-id') || '';

                let match = true;

                if (search && !lot.includes(search) && !produit.includes(search)) match = false;
                if (mois && mois !== rowMois) match = false;
                if (entrepotId && entrepotId !== rowEntrepotId) match = false;
                if (utilisateur === 'me' && rowUserId !== currentUserId) match = false;
                if (utilisateur === 'autre' && rowUserId === currentUserId) match = false;
                
                if (match) {
                    tbody.appendChild(row.cloneNode(true));
                    anyVisible = true;
                }
            });

            if (!anyVisible) {
                tbody.appendChild(emptyRow);
            }
        }

        // Événements filtres
        searchInput.addEventListener('keyup', filtrerTableau);
        monthFilter.addEventListener('change', filtrerTableau);
        entrepotFilter.addEventListener('change', filtrerTableau);
        userFilter.addEventListener('change', filtrerTableau);

        // Bouton reset
        resetBtn.addEventListener('click', function (e) {
            e.preventDefault();
            searchInput.value = '';
            monthFilter.value = ''; // vide = tous les mois (option "Tous les mois" présente)
            entrepotFilter.value = '';
            userFilter.value = 'all';
            filtrerTableau();
        });

        // Filtrer au chargement
        filtrerTableau();
    });
})();