//
document.addEventListener('DOMContentLoaded', function () {
    // Cibler tous les boutons "Modifier"
    const editButtons = document.querySelectorAll('.btn-edit-sortie');

    editButtons.forEach(button => {
        button.addEventListener('click', function () {
            // Récupérer les données du bouton
            const numeroBon = this.dataset.numero;
            const numeroOrdre = this.dataset.ordre;
            const statut = this.dataset.statut;
            const client = this.dataset.client;

            // Remplir les champs du modal
            document.getElementById('edit-numero-bon').value = numeroBon;
            document.getElementById('edit-ordre').value = numeroOrdre;
            document.getElementById('edit-statut').value = statut;
            document.getElementById('edit-client').value = client;

            // Afficher le modal Bootstrap
            const editModal = new bootstrap.Modal(document.getElementById('editSortieModal'));
            editModal.show();
        });
    });

    // Soumettre le formulaire via AJAX
    const editForm = document.getElementById('form-edit-sortie');
    editForm.addEventListener('submit', function (e) {
        e.preventDefault();

        const formData = new FormData(editForm);
        const numeroBon = document.getElementById('edit-numero-bon').value;

        fetch(`/stocks-sorties/${numeroBon}`, {
            method: 'POST',
            headers: {
                'X-CSRF-TOKEN': document.querySelector('input[name="_token"]').value,
                'X-Requested-With': 'XMLHttpRequest',
                'Accept': 'application/json',
                'X-HTTP-Method-Override': 'PUT' // Simule un PUT
            },
            body: formData
        })
        .then(response => {
            if (response.ok) {
                return response.json(); // ou `.text()` selon ta route
            }
            throw new Error('Erreur lors de la mise à jour');
        })
        .then(data => {
            // Fermer le modal
            const modal = bootstrap.Modal.getInstance(document.getElementById('editSortieModal'));
            modal.hide();

            // Optionnel : rafraîchir la page ou mettre à jour les données dans la vue
            location.reload();
        })
        .catch(error => {
            console.error(error);
            alert('Une erreur est survenue lors de la mise à jour.');
        });
    });
});