
  <div class="d-flex justify-content-between align-items-center mb-2">
    <h5>Liste des Catégories</h5>
    <button type="button" class="btn btn-primary mb-2" data-bs-toggle="modal" data-bs-target="#createCategoryModal">
      <i class="bi bi-plus-circle me-1"></i> Ajouter une catégorie
    </button>
  </div>

  <table class="table table-sm table-striped table-hover align-middle w-100 mb-4">
    <thead class="table-primary">
      <tr>
        <th scope="col">#</th>
        <th scope="col">Nom de la catégorie</th>
        <th scope="col">Description</th>
        <th scope="col">Produits associés</th>
        <th scope="col">Date de création</th>
        <th scope="col" class="text-center">Actions</th>
      </tr>
    </thead>
    <tbody>
      @forelse ($categories as $index => $categorie)
      <tr>
        <td>
          <div>
            <strong>{{ $categorie->reference }}</strong>
          </div>
        </td>
        <td>{{ $categorie->nom }}</td>
        <td>{{ $categorie->description ?? '—' }}</td>
        <td>
         <span class="badge 
         {{ $categorie->produits_count > 0 ? 'bg-info text-dark' : 'bg-danger text-white' }}">
              {{ $categorie->produits_count }}
        </span>

        </td>
        <td>{{ $categorie->created_at->format('d/m/Y') }}</td>
        <td>
          <!-- Bouton Modifier -->
          <a href="#" class="btn btn-sm btn-outline-primary edit-categorie-btn"
             data-id="{{ $categorie->id }}"
             data-reference="{{ $categorie->reference }}"
             data-nom="{{ $categorie->nom }}"
             data-description="{{ $categorie->description }}"
             data-bs-toggle="modal"
             data-bs-target="#editcategorieModal">
             Modifier
          </a>

          <!-- Le formulaire  de suppression -->
          <form action="{{ route('categories.destroy', $categorie) }}"
              method="POST"
              class="d-inline delete-categorie-form"
              data-categorie-id="{{ $categorie->id }}"
              data-categorie-name="{{ $categorie->nom }}">
            @csrf
            @method('DELETE')
            <button type="button"
                    class="btn btn-sm btn-outline-danger">
                Supprimer
            </button>
        </form>
        </td>
      </tr>
      @empty
      <tr>
        <td colspan="7" class="text-center text-muted">Aucune catégorie disponible.</td>
      </tr>
      @endforelse
    </tbody>
  </table>
