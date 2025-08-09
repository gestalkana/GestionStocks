<table class="table table-hover align-middle mb-0">
                <thead class="table-light">
                    <tr>
                        <th>#Ref</th>
                        <th>Produit</th>
                        <th>Quantité</th>
                        <th>Date de Sortie</th>
                        <th>Stock Avant</th>
                        <th>Stock Après</th>
                        <th>Motif</th>
                        <th>Statut</th>
                        <th>Utilisateur</th>
                        <th class="text-end">Actions</th>
                    </tr>
                </thead>
                <tbody>
                    @forelse ($stocksSorties as $sortie)
                        <tr id="sortie-row-{{ $sortie->id }}">
                            <td>{{ $sortie->numero_bon }}</td>
                            <td>{{ $sortie->produit->nom }}</td>
                            <td>{{ $sortie->quantite }}</td>
                            <td>{{ \Carbon\Carbon::parse($sortie->date_sortie)->format('d/m/Y') }}</td>
                            <td>{{ $sortie->stock_avant }}</td>
                            <td>{{ $sortie->stock_apres }}</td>
                            <td>{{ $sortie->motif }}</td>
                            <td>{{ $sortie->statut }}</td>
                            <td>{{ $sortie->user->name }}</td>
                            <td class="text-end">
                                <a href="{{ route('stocksSorties.show', $sortie->id) }}" class="btn btn-sm btn-outline-secondary me-1" title="Voir">
                                    <i class="bi bi-eye"></i>
                                </a>
                                <a href="{{ route('stocksSorties.edit', $sortie->id) }}" class="btn btn-sm btn-outline-warning me-1" title="Modifier">
                                    <i class="bi bi-pencil-square"></i>
                                </a>
                                <form action="{{ route('stocksSorties.destroy', $sortie->id) }}" method="POST" class="d-inline" onsubmit="return confirm('Confirmer la suppression ?')">
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
                            <td colspan="9" class="text-center text-muted py-4">
                                <i class="bi bi-inbox me-2 fs-5"></i> Aucune sortie enregistrée.
                            </td>
                        </tr>
                    @endforelse
                </tbody>
            </table>