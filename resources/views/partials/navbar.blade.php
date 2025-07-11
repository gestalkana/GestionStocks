<nav class="navbar">
  <span class="navbar-brand">
  	<i class="bi bi-box-seam"></i> Gestion des stocks
  </span>
  <div class="d-flex align-items-center gap-3">
    <!-- Notification -->
    <a href="#" class="text-white text-decoration-none"><i class="bi bi-bell"></i></a>
    <!-- Paramètre -->
    <a href="#" class="text-white text-decoration-none"><i class="bi bi-gear"></i></a>
    <!-- Deconnexion -->
    <!-- Profile icon dropdown -->
    <div class="dropdown d-inline">
      <button class="btn btn-outline-light dropdown-toggle" type="button" data-bs-toggle="dropdown">
        <i class="bi bi-person-circle"></i>
      </button>
      <ul class="dropdown-menu dropdown-menu-end">
        <li>
          <form method="POST" action="{{ route('logout') }}">
            @csrf
            <button type="submit" class="dropdown-item text-danger">
              <i class="bi bi-box-arrow-right me-2"></i> Déconnexion
            </button>
          </form>
        </li>
      </ul>
    </div>

  </div>
</nav>