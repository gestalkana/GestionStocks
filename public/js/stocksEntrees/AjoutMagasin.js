document.addEventListener('DOMContentLoaded', function () {
        $('#formAjoutMagasin').on('submit', function (e) {
            e.preventDefault();

            let form = $(this);
            let data = form.serialize();

            $.ajax({
                url: "{{ route('magasins.store') }}",
                method: "POST",
                data: data,
                success: function (response) {
                    // Ajouter à la liste déroulante
                    let option = $('<option>')
                        .val(response.id)
                        .text(response.nom);

                    $('select[name="magasin_id"]').append(option);
                    $('select[name="magasin_id"]').val(response.id); // Sélectionner le nouveau

                    // Fermer la modal
                    $('#ajouterMagasinModal').modal('hide');

                    // Réinitialiser le formulaire
                    form[0].reset();

                    // Message de succès (facultatif)
                    showSuccess("Magasin ajouté avec succès.");
                },
                error: function (xhr) {
                    let errors = xhr.responseJSON.errors;
                    let message = '';

                    for (let field in errors) {
                        message += errors[field][0] + '<br>';
                    }

                    $('#erreursMagasin').html(message);
                }
            });
        });

        function showSuccess(msg) {
            let alert = `
                <div class="alert alert-success alert-dismissible fade show mt-3" role="alert">
                    ${msg}
                    <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Fermer"></button>
                </div>
            `;
            $('body').prepend(alert);
        }
    });