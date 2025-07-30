const selectAll = document.getElementById('selectAll');
const checkboxes = document.querySelectorAll('.row-checkbox');
const countDisplay = document.getElementById('selection-count');
const actionButtons = document.querySelectorAll('.btn-group button');

function updateSelectionUI() {
  const checked = document.querySelectorAll('.row-checkbox:checked').length;
  if (countDisplay) {
    countDisplay.textContent = `${checked} sélectionné${checked > 1 ? 's' : ''}`;
  }

  actionButtons.forEach(btn => {
    btn.disabled = checked === 0;
  });
}

if (selectAll) {
  selectAll.addEventListener('change', function () {
    const isChecked = this.checked;
    checkboxes.forEach(cb => cb.checked = isChecked);
    updateSelectionUI();
  });
}

checkboxes.forEach(cb => {
  cb.addEventListener('change', () => {
    if (selectAll) {
      if (!cb.checked) selectAll.checked = false;
      else if (document.querySelectorAll('.row-checkbox:checked').length === checkboxes.length) {
        selectAll.checked = true;
      }
    }
    updateSelectionUI();
  });
});

updateSelectionUI();
