document.addEventListener('DOMContentLoaded', () => {
    const modalElement = document.getElementById('editFournisseurModal');
    const modal = new bootstrap.Modal(modalElement);
    const form = document.getElementById('editFournisseurForm');

    // Nettoyage
    modalElement.addEventListener('hidden.bs.modal', () => {
        form.reset();
    });

    // Remplir les champs au clic sur bouton modifier
    document.querySelectorAll('.edit-fournisseur-btn').forEach(button => {
        button.addEventListener('click', function () {
            document.getElementById('editFournisseurId').value = this.dataset.id;
            document.getElementById('editFournisseurNom').value = this.dataset.nom;
            document.getElementById('editFournisseurTelephone').value = this.dataset.telephone;
            document.getElementById('editFournisseurEmail').value = this.dataset.email;
            document.getElementById('editFournisseurAdresse').value = this.dataset.adresse;
            document.getElementById('editFournisseurStatut').value = this.dataset.statut;

            modal.show();
        });
    });

    // Soumission du formulaire via AJAX
    form.addEventListener('submit', function (e) {
        e.preventDefault();

        const id = document.getElementById('editFournisseurId').value;
        const formData = new FormData(form);
        const csrfToken = document.querySelector('meta[name="csrf-token"]').content;

        fetch(`/fournisseurs/${id}`, {
            method: 'POST',
            headers: {
                'X-CSRF-TOKEN': csrfToken,
                'Accept': 'application/json',
                'X-HTTP-Method-Override': 'PUT'
            },
            body: formData
        })
        .then(res => res.json())
        .then(data => {
            modal.hide();
            // Optionnel : affiche une alerte de succès
            showSuccessAlert('update', 'fournisseur');
            // Optionnel : rafraîchir la page ou mettre à jour le DOM
            // Attendre 2 secondes avant le reload
            setTimeout(() => {
                location.reload();
            }, 2500); // 2000 ms = 2 secondes;
        })
        .catch(err => alert("Erreur lors de la mise à jour"));
    });
});
