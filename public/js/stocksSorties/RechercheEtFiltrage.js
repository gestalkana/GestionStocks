(function () {
    document.addEventListener('DOMContentLoaded', function () {
        const inputRecherche = document.querySelector('#filtreRecherche');
        const selectMois = document.querySelector('#filtreMois');
        const selectStatut = document.querySelector('#filtreStatut');
        const selectUtilisateur = document.querySelector('#filtreUtilisateur');
        const tbody = document.querySelector('#sortiesTableBody');

        if (!tbody) return; // Sécurité si la table n'est pas encore là

        const allRows = Array.from(tbody.querySelectorAll('.sortie-row')).map(row => row.cloneNode(true));
        const currentUserId = document.body.dataset.currentUserId; // injecté via Blade

        const emptyRow = document.createElement('tr');
        emptyRow.id = 'emptyRow';
        emptyRow.innerHTML = `
            <td colspan="6" class="text-center text-muted py-4">
                <i class="bi bi-inbox me-2 fs-5"></i> Aucun résultat trouvé.
            </td>`;

        function filtrerTableau() {
            const recherche = inputRecherche.value.toLowerCase().trim();
            const mois = selectMois.value;
            const statut = selectStatut.value.toLowerCase();
            const utilisateur = selectUtilisateur.value;

            tbody.innerHTML = '';
            let anyVisible = false;

            allRows.forEach(row => {
                const numero = row.getAttribute('data-numero');
                const ordre = row.getAttribute('data-ordre');
                const rowMois = row.getAttribute('data-mois');
                const rowStatut = row.getAttribute('data-statut');
                const userId = row.getAttribute('data-user-id');

                let match = true;

                //if (recherche && !numero.includes(recherche)) match = false;
                if (recherche && !numero.includes(recherche) && !ordre.includes(recherche)) match = false;
                if (mois && mois !== rowMois) match = false;
                if (statut && rowStatut !== statut) match = false;
                if (utilisateur === 'moi' && userId !== currentUserId) match = false;
                if (utilisateur === 'autre' && userId === currentUserId) match = false;

                if (match) {
                    tbody.appendChild(row.cloneNode(true));
                    anyVisible = true;
                }
            });

            if (!anyVisible) {
                tbody.appendChild(emptyRow);
            }
        }

        inputRecherche.addEventListener('keyup', filtrerTableau);
        selectMois.addEventListener('change', filtrerTableau);
        selectStatut.addEventListener('change', filtrerTableau);
        selectUtilisateur.addEventListener('change', filtrerTableau);

        const resetBtn = document.querySelector('#resetFiltres');
        resetBtn?.addEventListener('click', function (e) {
            e.preventDefault();
            inputRecherche.value = '';
            selectMois.value = '';
            selectStatut.value = '';
            selectUtilisateur.value = '';
            filtrerTableau();
        });

        filtrerTableau(); // Init au chargement
    });
    document.querySelector('#btnImprimer').addEventListener('click', function () {
    const contenu = document.querySelector('#stocksSortiesTable').innerHTML;
    const win = window.open('', '_blank');
    win.document.write(`
        <html>
            <head>
                <title>Impression Sorties de Stock</title>
                <link rel="stylesheet" href="{{ asset('css/impression.css') }}">
            </head>
            <body>
                ${contenu}
            </body>
        </html>
    `);
    win.document.close();
    win.print();
});

})();
