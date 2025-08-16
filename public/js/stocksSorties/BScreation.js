(() => {
  document.addEventListener('DOMContentLoaded', () => {
    const form = document.querySelector('[data-module="form-sortie"]');
    if (!form) {
      console.info('[SortieModule] Formulaire de sortie non présent sur cette page. Script ignoré.');
      return;
    }

    // Fonction d'envoi du formulaire (brouillon ou validation)
    function submitSortie(statut) {
      const formData = new FormData(form);
      formData.append('statut', statut);

      const csrfToken = document.querySelector('meta[name="csrf-token"]')?.getAttribute('content');
      if (!csrfToken) {
        Swal.fire({
          icon: 'error',
          title: 'Erreur CSRF',
          text: 'Token CSRF manquant.'
        });
        return;
      }

      fetch('/stocks-sorties/ajax-store', {
        method: 'POST',
        headers: {
          'X-CSRF-TOKEN': csrfToken
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

    // Boutons
    const btnEnregistrer = document.getElementById('btn-enregistrer');
    const btnValider = document.getElementById('btn-valider');

    if (!btnEnregistrer && !btnValider) {
      console.warn('[SortieModule] Aucun bouton d\'action trouvé (#btn-enregistrer ou #btn-valider).');
      return;
    }

    if (btnEnregistrer) {
      btnEnregistrer.addEventListener('click', () => submitSortie('brouillon'));
    }

    if (btnValider) {
      btnValider.addEventListener('click', () => submitSortie('valide'));
    }
  });
})();
