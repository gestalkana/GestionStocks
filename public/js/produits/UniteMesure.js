(() => {
  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', init);
  } else {
    init();
  }

  function init() {
    const form = document.querySelector('[data-module="unite-form"]');
    const errorMsg = document.getElementById('modalErrorMsg');

    if (!form) {
      console.info('[UniteFormModule] Formulaire non présent sur cette page. Script ignoré.');
      return;
    }

    if (!errorMsg) {
      console.warn('Element "modalErrorMsg" non trouvé.');
      return;
    }

    form.addEventListener('submit', async (e) => {
      e.preventDefault();
      errorMsg.style.display = 'none';
      errorMsg.textContent = '';

      const formData = new FormData(form);

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
          } catch {}
          throw new Error(errMsg);
        }

        const result = await response.json();

        const modalEl = document.getElementById('modalAjouterUnite');
        if (modalEl) {
          const modal = bootstrap.Modal.getInstance(modalEl);
          if (modal) modal.hide();
        }

        form.reset();
        showSuccessAlert('create', 'Unité de mesure');

        const select = document.getElementById('unite_mesure_id');
        if (select) {
          const option = document.createElement('option');
          option.value = result.unite.id;
          option.textContent = `${result.unite.nom} (${result.unite.symbole || ''})`;
          option.selected = true;
          select.appendChild(option);
        }

      } catch (error) {
        errorMsg.textContent = error.message;
        errorMsg.style.display = 'block';
      }
    });
  }
})();
