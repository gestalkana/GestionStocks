document.addEventListener('DOMContentLoaded', () => {
    const modalElement = document.getElementById('editEntreeModal');
    const modal = new bootstrap.Modal(modalElement);
    const form = document.getElementById('editEntreeForm');

    modalElement.addEventListener('hidden.bs.modal', () => {
        clearEntreeModal();
    });

    document.querySelectorAll('.edit-entree-btn').forEach(button => {
        button.addEventListener('click', function () {
            document.getElementById('editEntreeId').value = this.dataset.id;
            document.getElementById('editEntreeQuantite').value = this.dataset.quantite;
            document.getElementById('editEntreeDate').value = this.dataset.date;

            modal.show();
        });
    });

    form.addEventListener('submit', function (e) {
        e.preventDefault();

        const id = document.getElementById('editEntreeId').value;
        const formData = new FormData(form);
        const csrfToken = document.querySelector('meta[name="csrf-token"]').content;

        fetch(`/stocksEntrees/${id}`, {
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
                console.error("Erreur serveur :", errorData);
                throw new Error("Erreur lors de la mise à jour.");
            }
            return res.json();
        })
        .then(data => {
             modal.hide();
            showSuccessAlert('update', 'entrée de stock');
            
            // recharger pour voir les changements 
            setTimeout(() => {
              location.reload();
            }, 3000); // 3000 millisecondes = 3 secondes

        })
        .catch(err => alert(err.message));
    });

    document.getElementById('cancelEditEntreeBtn').addEventListener('click', () => {
        modal.hide();
    });
});

function clearEntreeModal() {
    document.getElementById('editEntreeId').value = '';
    document.getElementById('editEntreeQuantite').value = '';
    document.getElementById('editEntreeDate').value = '';
}
