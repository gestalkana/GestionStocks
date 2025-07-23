// Pour la pagination des catégories
$(document).on('click', '.pagination-categories a', function(e) {
    e.preventDefault();
    const url = $(this).attr('href');

    $.ajax({
        url: url,
        type: 'GET',
        dataType: 'html',
        success: function(data) {
            $('#categories-container').html(data);
        },
        error: function() {
            alert('Erreur lors du chargement des catégories.');
        }
    });
});
