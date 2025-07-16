  //Catégorie Edition 
  document.addEventListener('DOMContentLoaded', () => {
  // Remplir les champs du modal avec les données de la catégorie
  document.querySelectorAll('.edit-category-btn').forEach(button => {
    button.addEventListener('click', () => {
      const id = button.dataset.id;
      const reference = button.dataset.reference;
      const nom = button.dataset.nom;
      const description = button.dataset.description;

      document.getElementById('editCategoryId').value = id;
      document.getElementById('editCategoryReference').value = reference;
      document.getElementById('editCategoryName').value = nom;
      document.getElementById('editCategoryDescription').value = description;
    });
  });

  // Soumission AJAX du formulaire de modification
  const editForm = document.getElementById('editCategoryForm');
  editForm.addEventListener('submit', function(e) {
    e.preventDefault();

    const id = document.getElementById('editCategoryId').value;
    const formData = new FormData(editForm);
    const csrfToken = document.querySelector('meta[name="csrf-token"]').getAttribute('content');

    fetch(`/categories/${id}`, {
      method: 'POST',
      headers: {
        'X-CSRF-TOKEN': csrfToken,
        'Accept': 'application/json',
      },
      body: formData
    })
    .then(response => {
      if (!response.ok) throw new Error('Erreur lors de la mise à jour.');
      return response.json();
    })
    .then(data => {
      //location.reload(); // Rafraîchir la page ou mettre à jour dynamiquement le tableau
      window.location.href = '/produits?onglet=categories';
      
    })
    .catch(error => {
      alert(error.message);
    });
  });
});
