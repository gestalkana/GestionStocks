// document.getElementById('btnImprimer').addEventListener('click', function () {
//     window.print();
// });
(function() {
    document.addEventListener('DOMContentLoaded', function () {
        const btnImprimer = document.getElementById('btnImprimer');

        if (btnImprimer) {
            btnImprimer.addEventListener('click', function () {
                const zoneImpression = document.getElementById('zoneImpression');
                if (!zoneImpression) return;

                const contenuAImprimer = zoneImpression.innerHTML;
                const originalBody = document.body.innerHTML;

                document.body.innerHTML = contenuAImprimer;
                window.print();
                document.body.innerHTML = originalBody;
                location.reload(); // recharge la page pour réinitialiser les événements JS
            });
        }
    });
})();