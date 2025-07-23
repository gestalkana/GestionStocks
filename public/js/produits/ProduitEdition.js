document.addEventListener('DOMContentLoaded', () => {
    const modalElement = document.getElementById('editProductModal');
    const modal = new bootstrap.Modal(modalElement);
    const form = document.getElementById('editProductForm');

    // Vider la modal à la fermeture
    modalElement.addEventListener('hidden.bs.modal', () => {
        forceCleanModal();
    });

    // Remplir le formulaire au clic sur un bouton modifier
    document.querySelectorAll('.edit-produit-btn').forEach(button => {
        button.addEventListener('click', function () {
            document.getElementById('editProduitId').value = this.dataset.id;
            document.getElementById('editProduitNom').value = this.dataset.nom;
            document.getElementById('editProduitCode').value = this.dataset.code;
            document.getElementById('editProduitPrixAchat').value = this.dataset.prixAchat;
            document.getElementById('editProduitPrixVente').value = this.dataset.prixVente;
            document.getElementById('editProduitDescription').value = this.dataset.description;

            modal.show();
        });
    });

    // Soumission AJAX du formulaire
    form.addEventListener('submit', function (e) {
        e.preventDefault();

        const id = document.getElementById('editProduitId').value;
        const formData = new FormData(form);
        const csrfToken = document.querySelector('meta[name="csrf-token"]').content;

        fetch(`/produits/${id}`, {
            method: 'POST',
            headers: {
                'X-CSRF-TOKEN': csrfToken,
                'Accept': 'application/json',
                'X-HTTP-Method-Override': 'PUT'
            },
            body: formData
        })
        .then(async res => {
            if (!res.ok) {
                const errorData = await res.json();
                console.error("Erreur back-end :", errorData);
                throw new Error("Erreur lors de la mise à jour.");
            }
            return res.json();
        })
        .then(data => {
            modal.hide();

            // Swal.fire({
            //     icon: 'success',
            //     title: 'Produit modifié avec succès',
            //     text: data.message || 'Le produit a bien été mis à jour.',
            //     showConfirmButton: false,
            //     timer: 2500,
            //     timerProgressBar: true,
            //     position: 'center',
            //     background: '#f0fdf4',
            //     color: '#065f46',

            // });
            showSuccessAlert('update', 'produit');

            const produit = data.produit;

            // Mise à jour dans la page principale (si champs présents)
            const nomEl = document.getElementById('nom');
            if (nomEl) nomEl.value = produit.nom;

            const codeEl = document.getElementById('code_produit');
            if (codeEl) codeEl.value = produit.code_produit;

            const prixAchatEl = document.getElementById('prix_achat');
            if (prixAchatEl) prixAchatEl.value = produit.prix_achat;

            const prixVenteEl = document.getElementById('prix_unitaire');
            if (prixVenteEl) prixVenteEl.value = produit.prix_unitaire;

            const descEl = document.getElementById('description');
            if (descEl) descEl.textContent = produit.description || '';

            // Mise à jour des data-* sur le bouton d'édition correspondant
            const editBtn = document.querySelector(`.edit-produit-btn[data-id="${produit.id}"]`);
            if (editBtn) {
                editBtn.dataset.nom = produit.nom;
                editBtn.dataset.code = produit.code_produit;
                editBtn.dataset.prixAchat = produit.prix_achat;
                editBtn.dataset.prixVente = produit.prix_unitaire;
                editBtn.dataset.description = produit.description || '';
            }
        })
        .catch(err => alert(err.message));
    });

    // Bouton Annuler (optionnel si tu utilises data-bs-dismiss)
    document.getElementById('cancelEditProductBtn').addEventListener('click', () => {
        modal.hide();
    });
});

// Fonction qui vide tous les champs de la modal
function forceCleanModal() {
    const fieldsToClear = [
        'editProduitId',
        'editProduitNom',
        'editProduitCode',
        'editProduitPrixAchat',
        'editProduitPrixVente',
        'editProduitDescription'
    ];

    fieldsToClear.forEach(id => {
        const el = document.getElementById(id);
        if (el) {
            el.value = '';
        }
    });
}
