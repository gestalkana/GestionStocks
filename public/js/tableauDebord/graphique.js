document.addEventListener('DOMContentLoaded', function () {
    const ctx = document.getElementById('stockChart');

    if (ctx && window.chartData) {
        new Chart(ctx, {
            type: 'bar',
            data: {
                labels: window.chartData.labels,
                datasets: [
                    {
                        label: 'Entrées',
                        data: window.chartData.entrees,
                        backgroundColor: 'rgba(14, 116, 144, 0.7)',
                    },
                    {
                        label: 'Sorties',
                        data: window.chartData.sorties,
                        backgroundColor: 'rgba(239, 68, 68, 0.7)',
                    }
                ]
            },
            options: {
                responsive: true,
                plugins: {
                    legend: {
                        position: 'top',
                    },
                    title: {
                        display: true,
                        text: 'Historique des stocks sur 7 jours'
                    }
                },
                scales: {
                    y: {
                        beginAtZero: true
                    }
                }
            }
        });
    }
});
