
    function deleteCategory(event, categoryId) {
        event.preventDefault();

        if (!confirm('Supprimer cette catégorie ?')) return;

        fetch(`/categories/${categoryId}`, {
            method: 'DELETE',
            headers: {
                'X-CSRF-TOKEN': '{{ csrf_token() }}',
                'Accept': 'application/json',
            },
        })
        .then(response => {
            if (response.ok) {
                // Supprimer la ligne du tableau ou mettre à jour l'affichage
                const btn = event.target;
                const row = btn.closest('tr'); // ou .closest('.categorie-item') selon le HTML
                row.remove();

                // Optionnel : montrer un toast ou une alerte
                alert('Catégorie supprimée.');
            } else {
                alert('Erreur lors de la suppression.');
            }
        })
        .catch(() => {
            alert('Erreur serveur.');
        });
    }

