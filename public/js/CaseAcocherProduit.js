//permet de sélectionner tous les produits
document.getElementById('selectAll').addEventListener('change', function () {
    const isChecked = this.checked;
    document.querySelectorAll('.row-checkbox').forEach(cb => cb.checked = isChecked);
});

//compteur des nombres de produit sélectionner
const checkboxes = document.querySelectorAll('.row-checkbox');
const selectAll = document.getElementById('selectAll');
const countDisplay = document.getElementById('selection-count');
const actionButtons = document.querySelectorAll('.btn-group button');

function updateSelectionUI() {
  const checked = document.querySelectorAll('.row-checkbox:checked').length;
  countDisplay.textContent = `${checked} sélectionné${checked > 1 ? 's' : ''}`;

  actionButtons.forEach(btn => {
    btn.disabled = checked === 0;
  });
}

// Lorsqu'on clique sur "tout sélectionner"
selectAll.addEventListener('change', function () {
  const isChecked = this.checked;
  checkboxes.forEach(cb => {
    cb.checked = isChecked;
  });
  updateSelectionUI(); // On met à jour le compteur ici aussi
});

// Pour chaque checkbox individuelle
checkboxes.forEach(cb => {
  cb.addEventListener('change', () => {
// On décoche "tout sélectionner" si une case est décochée manuellement
    if (!cb.checked) selectAll.checked = false;
    // Si toutes sont cochées manuellement, on coche aussi "tout sélectionner"
    else if (document.querySelectorAll('.row-checkbox:checked').length === checkboxes.length) {
      selectAll.checked = true;
    }
    updateSelectionUI();
  });
});

// Initialiser l’état des boutons au démarrage
updateSelectionUI();

