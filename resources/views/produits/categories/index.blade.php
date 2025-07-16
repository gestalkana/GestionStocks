
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


<!-- Modal création catégorie -->
<div class="modal fade" id="createCategoryModal" tabindex="-1" aria-labelledby="createCategoryModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <form id="createCategoryForm" method="POST" action="{{ route('categories.store') }}">
      @csrf
      <div class="modal-content">
        <div class="modal-header">
          <h5 class="modal-title" id="createCategoryModalLabel">Ajouter une catégorie</h5>
          <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Fermer"></button>
        </div>
        <div class="modal-body">
          <div class="mb-3">
            <label for="categoryReference" class="form-label">Référence</label>
            <input type="text" name="reference" class="form-control @error('reference') is-invalid @enderror" id="categoryReference" required>
            @error('reference')
              <div class="invalid-feedback">{{ $message }}</div>
            @enderror
          </div>
          <div class="mb-3">
            <label for="categoryName" class="form-label">Nom de la catégorie</label>
            <input type="text" name="nom" class="form-control @error('nom') is-invalid @enderror" id="categoryName" required>
            @error('nom')
              <div class="invalid-feedback">{{ $message }}</div>
            @enderror
          </div>
          <div class="mb-3">
            <label for="categoryDescription" class="form-label">Description</label>
            <textarea name="description" class="form-control" id="categoryDescription" rows="3"></textarea>
          </div>
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Annuler</button>
          <button type="submit" class="btn btn-primary">Créer</button>
        </div>
      </div>
    </form>
  </div>
</div>


<!-- Modal édition catégorie -->
<div class="modal fade" id="editCategoryModal" tabindex="-1" aria-labelledby="editCategoryModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <form id="editCategoryForm">
      @csrf
      @method('PUT')
      <div class="modal-content">
        <div class="modal-header">
          <h5 class="modal-title" id="editCategoryModalLabel">Modifier la catégorie</h5>
          <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Fermer"></button>
        </div>
        <div class="modal-body">
          <input type="hidden" id="editCategoryId">
          <div class="mb-3">
            <label for="editCategoryReference" class="form-label">Référence</label>
            <input type="text" name="reference" class="form-control" id="editCategoryReference" required>
          </div>
          <div class="mb-3">
            <label for="editCategoryName" class="form-label">Nom de la catégorie</label>
            <input type="text" name="nom" class="form-control" id="editCategoryName" required>
          </div>
          <div class="mb-3">
            <label for="editCategoryDescription" class="form-label">Description</label>
            <textarea name="description" class="form-control" id="editCategoryDescription" rows="3"></textarea>
          </div>
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Annuler</button>
          <button type="submit" class="btn btn-primary">Enregistrer</button>
        </div>
      </div>
    </form>
  </div>
</div>
