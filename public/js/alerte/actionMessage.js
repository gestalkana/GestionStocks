function showSuccessAlert(action, element) {
  const elementFormatted = capitalize(element);

  const alertConfigs = {
    create: {
      title: `${elementFormatted} créé(e) avec succès`,
      text: `Le ${element} a bien été ajouté.`,
      background: '#f0fdf4',
      color: '#065f46'
    },
    update: {
      title: `${elementFormatted} modifié(e) avec succès`,
      text: `Le ${element} a bien été mis à jour.`,
      background: '#f0fdf4',
      color: '#065f46'
    },
    delete: {
      title: `${elementFormatted} supprimé(e) avec succès`,
      text: `Le ${element} a bien été supprimé.`,
      background: '#fef2f2',
      color: '#991b1b'
    }
  };

  const config = alertConfigs[action] || {
    title: `${elementFormatted} traité(e)`,
    text: `Le ${element} a été mis à jour.`,
    background: '#f0fdf4',
    color: '#065f46'
  };

  Swal.fire({
    icon: 'success',
    title: config.title,
    text: config.text,
    showConfirmButton: false,
    timer: 2500,
    timerProgressBar: true,
    position: 'center',
    background: config.background,
    color: config.color
  });
}

// Fonction pour mettre en majuscule la première lettre
function capitalize(str) {
  return str.charAt(0).toUpperCase() + str.slice(1);
}

// ✅ SweetAlert - Message d'erreur générique ou serveur
  function showErrorAlert(title = 'Erreur', message = 'Une erreur est survenue.') {
    Swal.fire({
      icon: 'error',
      title: title,
      text: message
    });
  }
