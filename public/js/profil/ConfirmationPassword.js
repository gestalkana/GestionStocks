document.addEventListener('DOMContentLoaded', function () {
    const openConfirmBtn = document.getElementById('openConfirmModal');
    const profileForm = document.getElementById('profileForm');
    const currentPasswordHidden = document.getElementById('current_password_hidden');

    openConfirmBtn.addEventListener('click', async () => {
        // Vérifie d'abord si le formulaire est valide (HTML5 check)
        if (!profileForm.checkValidity()) {
            profileForm.reportValidity(); // Affiche les erreurs natives du navigateur
            return;
        }

        // Popup de confirmation du mot de passe
        const { value: password } = await Swal.fire({
            title: 'Confirmez votre mot de passe',
            input: 'password',
            inputLabel: 'Mot de passe actuel',
            inputPlaceholder: 'Entrez votre mot de passe',
            inputAttributes: {
                autocapitalize: 'off',
                autocorrect: 'off'
            },
            showCancelButton: true,
            confirmButtonText: 'Confirmer',
            cancelButtonText: 'Annuler',
            inputValidator: (value) => {
                if (!value) {
                    return 'Vous devez entrer votre mot de passe !';
                }
            }
        });

        if (password) {
            currentPasswordHidden.value = password;
            profileForm.submit();
        }
    });
});
