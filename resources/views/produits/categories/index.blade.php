
  <div class="d-flex justify-content-between align-items-center mb-2">
    <h2>Liste des Catégories</h2>
    <button type="button" class="btn btn-primary mb-3" data-bs-toggle="modal" data-bs-target="#createCategoryModal">
      <i class="bi bi-plus-circle me-1"></i> Ajouter une catégorie
    </button>
  </div>


  <table class="table table-striped table-hover align-middle w-100">
    <thead class="table-primary">
      <tr>
        <th scope="col">#</th>
        <th scope="col">Nom de la catégorie</th>
        <th scope="col">Description</th>
        <th scope="col">Produits associés</th>
        <th scope="col">Date de création</th>
        <th scope="col">Actions</th>
      </tr>
    </thead>
    <tbody>
      @forelse ($categories as $index => $category)
      <tr>
        <td>{{ $index + 1 }}</td>
        <td>
          <div>
            <strong>{{ $category->nom }}</strong>
          </div>
        </td>
        <td>{{ $category->description ?? '—' }}</td>
        <td>
          <span class="badge bg-info text-dark">
            {{ $category->products_count ?? '0' }}
          </span>
        </td>
        <td>{{ $category->created_at->format('d/m/Y') }}</td>
        <td>
          <!-- Bouton Modifier -->
          <a href="#" class="btn btn-sm btn-outline-primary edit-category-btn"
             data-id="{{ $category->id }}"
             data-reference="{{ $category->reference }}"
             data-nom="{{ $category->nom }}"
             data-description="{{ $category->description }}"
             data-bs-toggle="modal"
             data-bs-target="#editCategoryModal">
             Modifier
          </a>

         <form action="{{ route('categories.destroy', $category) }}" method="POST" class="d-inline">
              @csrf
              @method('DELETE')
              <button class="btn btn-sm btn-outline-danger">Supprimer</button>
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

