<div id="zoneImpression">
<table class="table table-hover align-middle mb-0">
    <thead class="table-light">
        <tr>
            <th># Bon de Sortie</th>
            <th>Nombre de Produits</th>
            <th>Date</th>
            <th>Statut</th>
            <th>Ordre n°</th>
            <th>Utilisateur</th>
            <th class="text-center no-print">Actions</th>
        </tr>
    </thead>
    <tbody id="sortiesTableBody">
@forelse ($stocksSorties as $bon)
    <tr
        class="sortie-row"
        data-numero="{{ strtolower($bon['numero_bon']) }}"
        data-ordre="{{ strtolower($bon['numero_ordre']) }}"
        data-mois="{{ \Carbon\Carbon::parse($bon['date_sortie'])->month }}"
        data-statut="{{ strtolower($bon['statut']) }}"
        data-user-id="{{ $bon['user']?->id ?? '' }}"
    >
        <td>{{ $bon['numero_bon'] }}</td>
        <td>{{ $bon['nombre_produits'] }}</td>
        <td>{{ \Carbon\Carbon::parse($bon['date_sortie'])->format('d/m/Y') }}</td>
        <td>{{ $bon['statut'] }}</td>
        <td>{{ $bon['numero_ordre'] ?? 'non défini'}}</td>
        <td>{{ $bon['user']?->name ?? '-' }}</td>
        <td class="text-center no-print">
             <a href="{{ route('stocksSorties.show', $bon['id']) }}" class="btn btn-sm btn-outline-secondary me-1" title="Voir">
                <i class="bi bi-eye"></i>
            </a>
            <a href="{{ route('stocksSorties.edit', $bon['id']) }}" class="btn btn-sm btn-outline-warning me-1" title="Modifier">
                <i class="bi bi-pencil-square"></i>
            </a>
            <form action="{{ route('stocksSorties.destroy', $bon['id']) }}" method="POST" class="d-inline" onsubmit="return confirm('Confirmer la suppression ?')">
                @csrf
                @method('DELETE')
                <button type="submit" class="btn btn-sm btn-outline-danger" title="Supprimer">
                    <i class="bi bi-trash"></i>
                </button>
            </form>
        </td>
    </tr>
@empty
    <tr id="emptyRow">
        <td colspan="6" class="text-center text-muted py-4">
            <i class="bi bi-inbox me-2 fs-5"></i> Aucune sortie enregistrée.
        </td>
    </tr>
@endforelse
</tbody>
</table>
</div>

