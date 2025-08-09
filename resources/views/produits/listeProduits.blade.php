<div class="d-flex justify-content-between align-items-center mb-2">
  <h5>Liste des produits</h5>
  <div class="d-flex align-items-center gap-3">
    <div id="selection-count" class="text-muted small">0 sélectionné</div>
    <div class="btn-group">
      <button class="btn btn-outline-danger btn-sm" title="Supprimer les éléments sélectionnés">
        <i class="bi bi-trash"></i>
      </button>
      <button class="btn btn-outline-secondary btn-sm" title="Archiver les éléments sélectionnés">
        <i class="bi bi-archive"></i>
      </button>
      <button class="btn btn-outline-primary btn-sm" title="Exporter les éléments sélectionnés">
        <i class="bi bi-download"></i>
      </button>
    </div>
  </div>
</div>

<!-- Liste des produits -->
@php
  //couleur de badge dans catégorie
  $badgeColors = ['bg-primary', 'bg-secondary', 'bg-success', 'bg-danger', 'bg-warning', 'bg-info', 'bg-dark'];
  $colorIndex = 0;
@endphp


<table class="table table-sm table-striped table-hover align-middle">
  <thead class="table-primary">
    <tr>
      <th scope="col"><input type="checkbox" id="selectAll" /></th>
      <th scope="col">Référence</th>
      <th scope="col">Nom du produit</th>
      <th scope="col">Catégorie</th>
      <th scope="col">Quantité</th>
      <th scope="col">Prix d'achat</th>
      <th scope="col">Prix de vente</th>
      <th scope="col">Statut</th>
    </tr>
  </thead>
  <tbody id="produitsTableBody">
    @forelse ($produits as $produit)
      @php
        $currentColor = $badgeColors[$colorIndex % count($badgeColors)];
        $colorIndex++;

      //contenu dans tooltip
      $tooltipContent = "
        <strong>{$produit->nom}</strong><br>
        ".e(Str::limit($produit->description, 100))."<br>
        <small style='color: #007bff; font-weight: 600;'>Cliquez pour voir plus</small>
      ";
      @endphp
      <tr>
        <td><input type="checkbox" class="row-checkbox" /></td>
        <td>{{ $produit->code_produit }}</td>
        <td>
          <div>
            <div>
              <a href="{{ route('produits.show', $produit->id) }}" class="text-dark fw-semibold text-decoration-none hover-color" data-tippy-content="{{ $tooltipContent }}">
                {{ $produit->nom }}
              </a>
            </div>
            @if ($produit->description)
              <small class="text-muted">{{ Str::limit($produit->description, 20) }}</small>
            @endif
          </div>
        </td>

        <td>
          <span class="badge {{ $currentColor }}">
            {{ $produit->categorie?->nom ?? 'N/A' }}
          </span>
        </td>
        <td>{{ $produit->stock ?? 0 }}</td>
        <td>{{ number_format($produit->prix_achat ?? 0, 2, ',', ' ') }} Ar</td>
        <td>{{ number_format($produit->prix_unitaire ?? 0, 2, ',', ' ') }} Ar</td>
        <td>
          @php
              $seuil_min = 10; // tu peux ajuster ce seuil selon le contexte
              if ($produit->stock == 0) {
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
          <span class="badge {{ $badgeClass }}">{{ $status }}</span>
        </td>
      </tr>
    @empty
      <tr>
        <td colspan="8" class="text-center text-muted">
          Aucun produit enregistré pour l’instant.
        </td>
      </tr>
    @endforelse
  </tbody>
</table>
  {{-- Boutons de pagination --}}
 <!-- Ajouter des liens de pagination -->
<div class="d-flex justify-content-center mb-4">
  <div class="pagination pagination-produits">
    {{ $produits->links('pagination::bootstrap-4') }}
  </div>
</div>