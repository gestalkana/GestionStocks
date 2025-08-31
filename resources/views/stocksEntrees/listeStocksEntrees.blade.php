<!-- Zone d'impression -->
<div id="zoneImpression">
    <!-- Liste des Entrees de stocks -->
    <table class="table table-hover align-middle mb-0">
        <thead class="table-light">
            <tr>
                <th>#Ref</th>
                <th>Produit</th>
                <th>Quantité</th>
                <th>Date d'entrée</th>
                <th>Date d'expiration</th>
                <th>Stock Avant</th>
                <th>Stock Après</th>
                <th>magasin</th>
                <th>Utilisateur</th>
                <th class="text-center no-print">Actions</th>
            </tr>
        </thead>
        <tbody>
            @forelse ($stocksEntrees as $entree)
                <!-- <tr id="entree-row-{{ $entree->id }}"> -->
                <tr 
                    class="entree-row"
                    data-lot="{{ strtolower($entree->numero_lot) }}"
                    data-produit="{{ strtolower($entree->produit->nom) }}"
                    data-mois="{{ \Carbon\Carbon::parse($entree->date_entree)->month }}"
                    data-entrepot-id="{{ $entree->entrepot->id ?? '' }}"
                    data-user-id="{{ $entree->user->id ?? '' }}"
                >
                    <td>{{ $entree->numero_lot}}</td>
                    <td>{{ $entree->produit->nom }}</td>
                    <td>{{ $entree->quantite }}</td>
                    <td>{{ \Carbon\Carbon::parse($entree->date_entree)->format('d/m/Y') }}</td>
                    <td>{{ 
                        $entree->date_expiration ? \Carbon\Carbon::parse($entree->date_expiration)->format('d/m/Y') : 'Non défini' 
                        }}
                    </td>
                    <td>{{ $entree->stock_avant }}</td>
                    <td>{{ $entree->stock_apres }}</td>
                       <td>{{ $entree->entrepot->nom ?? 'Non défini' }}</td>
                    <td>{{ $entree->user->name }}</td>
                    <td class="text-end no-print">
                        <a href="{{ route('stocksEntrees.show', $entree->id) }}" class="btn btn-sm btn-outline-secondary me-1" title="Voir">
                            <i class="bi bi-eye"></i>
                        </a>
                        <!-- Modification 
                        <button type="button"
                                class="btn btn-outline-warning btn-sm edit-entree-btn me-1"
                                data-id="{{ $entree->id }}"
                                data-quantite="{{ $entree->quantite }}"
                                data-date="{{ \Carbon\Carbon::parse($entree->date_expiration)->format('Y-m-d') }}">
                          <i class="bi bi-pencil-square" title="Modifier"></i>
                        </button>-->
                        <!-- Suppression -->
                        <form action="{{ route('stocksEntrees.destroy', $entree->id) }}" method="POST" class="d-inline" onsubmit="return confirm('Confirmer la suppression ?')">
                            @csrf
                            @method('DELETE')
                            <button type="submit" class="btn btn-sm btn-outline-danger" title="Supprimer">
                                <i class="bi bi-trash"></i>
                            </button>
                        </form>
                    </td>
                </tr>
            @empty
                <tr>
                    <td colspan="8" class="text-center text-muted py-4">
                        <i class="bi bi-inbox me-2 fs-5"></i> Aucune entrée enregistrée.
                    </td>
                </tr>
            @endforelse
        </tbody>
    </table>
</div>
