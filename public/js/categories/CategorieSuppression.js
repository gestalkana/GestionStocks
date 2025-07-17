document.addEventListener('DOMContentLoaded', function () {
    let deleteForm;

    // Quand on clique sur le bouton "Supprimer"
    document.querySelectorAll('.delete-form button[data-bs-toggle="modal"]').forEach(button => {
        button.addEventListener('click', function () {
            deleteForm = button.closest('form'); // stocker le formulaire

            // Récupérer le nom de la catégorie depuis l'attribut data
            const categoryName = deleteForm.dataset.categoryName;

            // Modifier le texte du message dans la modale
            const messageElement = document.getElementById('modal-delete-message');
            messageElement.textContent = `Êtes-vous sûr de vouloir supprimer la catégorie "${categoryName}" ?`;
        });
    });

    // Quand on clique sur le bouton de confirmation
    document.getElementById('confirmDeleteBtn').addEventListener('click', function () {
        if (deleteForm) {
            deleteForm.submit(); // Soumettre le formulaire
        }
    });
});

