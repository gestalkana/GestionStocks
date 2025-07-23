$(document).on('click', '.pagination-produits a', function(e) {
    e.preventDefault();
    var url = $(this).attr('href');

    $.ajax({
        url: url,
        type: 'GET',
        dataType: 'html',
        success: function(data) {
            $('#produits-container').html(data);
        },
        error: function() {
            alert('Erreur lors du chargement des données.');
        }
    });
});

