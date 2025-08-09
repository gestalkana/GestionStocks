(() => {
  // Tester que le DOM est prêt (optionnel si script placé en fin de page)
  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', init);
  } else {
    init();
  }

  function init() {
    const form = document.getElementById('formAjouterUnite');
    const errorMsg = document.getElementById('modalErrorMsg');

    // Tests d’existence des éléments nécessaires
    if (!form) {
      console.warn('Formulaire "formAjouterUnite" non trouvé.');
      return;
    }

    if (!errorMsg) {
      console.warn('Element "modalErrorMsg" non trouvé.');
      return;
    }

    form.addEventListener('submit', async (e) => {
      e.preventDefault();

      // Toujours cacher l’erreur au départ
      errorMsg.style.display = 'none';
      errorMsg.textContent = '';

      // Collecter les données
      const formData = new FormData(form);

      // Validation basique côté client
      const code = formData.get('code');
      const nom = formData.get('nom');
      const symbole = formData.get('symbole');

      if (!code || !code.trim()) {
        errorMsg.textContent = 'Le code est obligatoire.';
        errorMsg.style.display = 'block';
        return;
      }

      if (!nom || !nom.trim()) {
        errorMsg.textContent = 'Le nom est obligatoire.';
        errorMsg.style.display = 'block';
        return;
      }

      const data = {
        code: code.trim(),
        nom: nom.trim(),
        symbole: symbole ? symbole.trim() : null,
      };

      // Récupérer token CSRF en testant l’existence
      const metaCsrf = document.querySelector('meta[name="csrf-token"]');
      if (!metaCsrf) {
        errorMsg.textContent = 'Token CSRF introuvable, impossible d\'envoyer le formulaire.';
        errorMsg.style.display = 'block';
        return;
      }
      const token = metaCsrf.getAttribute('content');

      try {
        const response = await fetch('/unite_mesures', {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
            'X-CSRF-TOKEN': token,
            'Accept': 'application/json',
          },
          body: JSON.stringify(data),
        });

        if (!response.ok) {
          let errMsg = 'Erreur lors de la sauvegarde.';
          try {
            const errData = await response.json();
            errMsg = errData.message || errMsg;
          } catch {
            // ignore parsing error
          }
          throw new Error(errMsg);
        }

        const result = await response.json();

        // Fermer la modal en testant l’instance Bootstrap
        const modalEl = document.getElementById('modalAjouterUnite');
        if (modalEl) {
          const modal = bootstrap.Modal.getInstance(modalEl);
          if (modal) modal.hide();
        }

        form.reset();
        //alert(result.message || 'Unité de mesure enregistrée avec succès.');
        showSuccessAlert('create', 'Unite de mesure');

        // Ajouter la nouvelle unité au select
        const select = document.getElementById('unite_mesure_id');
        if (select) {
          const option = document.createElement('option');
          option.value = result.unite.id; // Assure-toi que l'ID est bien retourné dans `result`
          option.textContent = `${result.unite.nom} (${result.unite.symbole || ''})`;
          option.selected = true; // La nouvelle unité est sélectionnée

          select.appendChild(option);
        }

      } catch (error) {
        errorMsg.textContent = error.message;
        errorMsg.style.display = 'block';
      }
    });
  }
})();
