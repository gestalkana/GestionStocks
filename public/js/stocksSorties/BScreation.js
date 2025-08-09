document.addEventListener('DOMContentLoaded', () => {
    // Fonction d'envoi du formulaire (brouillon ou validation)
    function submitSortie(statut) {
        const form = document.getElementById('form-sortie');
        if (!form) {
            console.error('Le formulaire #form-sortie est introuvable.');
            return;
        }

        const formData = new FormData(form);
        formData.append('statut', statut);

        fetch('/stocks-sorties/ajax-store', {
            method: 'POST',
            headers: {
                'X-CSRF-TOKEN': document.querySelector('meta[name="csrf-token"]')?.getAttribute('content')
            },
            body: formData
        })
        .then(res => {
            if (!res.ok) {
                throw new Error(`Erreur HTTP ${res.status}`);
            }
            return res.json();
        })
        .then(data => {
            if (data.success) {
                Swal.fire({
                    icon: 'success',
                    title: 'Succès',
                    text: data.message
                }).then(() => window.location.reload());
            } else {
                Swal.fire({
                    icon: 'error',
                    title: 'Erreur',
                    html: data.message || 'Une erreur est survenue.'
                });
            }
        })
        .catch(err => {
            Swal.fire({
                icon: 'error',
                title: 'Erreur serveur',
                text: err.message || 'Erreur inconnue lors de la soumission.'
            });
        });
    }

    // Clic bouton Enregistrer
    const btnEnregistrer = document.getElementById('btn-enregistrer');
    if (btnEnregistrer) {
        btnEnregistrer.addEventListener('click', () => {
            submitSortie('brouillon');
        });
    } else {
        console.warn("Le bouton #btn-enregistrer n'existe pas dans le DOM.");
    }

    // Clic bouton Valider
    const btnValider = document.getElementById('btn-valider');
    if (btnValider) {
        btnValider.addEventListener('click', () => {
            submitSortie('valide');
        });
    } else {
        console.warn("Le bouton #btn-valider n'existe pas dans le DOM.");
    }
});
