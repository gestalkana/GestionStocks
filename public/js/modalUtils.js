function forceCleanModal() {
  // Supprimer le backdrop
  document.querySelectorAll('.modal-backdrop').forEach(el => el.remove());

  // Vérifier qu'aucun autre modal n’est visible
  const stillOpen = document.querySelector('.modal.show');
  if (!stillOpen) {
    document.body.classList.remove('modal-open');
    document.body.style.paddingRight = '';
    document.body.style.overflowY = ''; // optionnel, pour forcer le scroll
  }
}
