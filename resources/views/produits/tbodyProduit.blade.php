{{-- resources/views/produits/tbodyProduit.blade.php --}}
@forelse ($produits as $produit)
    @php
        // Choix de la couleur du badge
        $currentColor = $badgeColors[$colorIndex % count($badgeColors)];
        $colorIndex++;

        // Contenu pour le tooltip
        $tooltipContent = "
            <strong>{$produit->nom}</strong><br>
            ".e(Str::limit($produit->description, 100))."<br>
            <small style='color: #007bff; font-weight: 600;'>Cliquez pour voir plus</small>
        ";

        // Définition du statut et badge correspondant
        $seuil_min = 10;
        if ($produit->stock <= 0) {
            $status = 'Rupture';
            $badgeClass = 'bg-danger';
        } elseif ($produit->stock <= $seuil_min) {
            $status = 'Stock faible';
            $badgeClass = 'bg-warning';
        } else {
            $status = 'Disponible';
            $badgeClass = 'bg-success';
        }
    @endphp

    <tr data-entrepot-id="{{ $produit->stocksEntrees->first()->entrepot_id ?? '' }}"
        data-categorie-id="{{ $produit->categorie_id }}">
        <td><input type="checkbox" class="row-checkbox" /></td>
        <td>{{ $produit->code_produit }}</td>
        <td>
            <a href="{{ route('produits.show', $produit->id) }}"
               class="text-dark fw-semibold text-decoration-none hover-color"
               data-tippy-content="{{ $tooltipContent }}">
               {{ $produit->nom }}
            </a><br>
            <small class="text-muted">
                {{ Str::limit($produit->description ?? 'Aucune description', 20) }}
            </small>
        </td>

        <td data-categorie-id="{{ $produit->categorie?->id ?? '' }}">
            <span class="badge {{ $currentColor }}">
                {{ $produit->categorie?->nom ?? 'N/A' }}
            </span>
        </td>
        <td>{{ $produit->stock ?? 0 }}</td>
        <td>{{ number_format($produit->prix_achat ?? 0, 2, ',', ' ') }} Ar</td>
        <td>{{ number_format($produit->prix_unitaire ?? 0, 2, ',', ' ') }} Ar</td>
        <td data-statut="{{ strtolower(str_replace(' ', '_', $status)) }}">
            <span class="badge {{ $badgeClass }}">{{ $status }}</span>
        </td>
    </tr>
@empty
    <tr id="emptyRow">
        <td colspan="8" class="text-center text-muted">
            Aucun produit enregistré pour l’instant.
        </td>
    </tr>
@endforelse
