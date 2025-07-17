<nav class="navbar">
  <div class="d-flex align-items-center gap-3">
      <span class="navbar-brand">
      	<i class="bi bi-box-seam"></i> Gestion des stocks
      </span>
      {{-- Titre dynamique de la page --}}
      @hasSection('Page-title')
        <h1 class="h5 fw-semibold mb-0 text-white d-none d-md-block">
            @yield('Page-title')
        </h1>
      @endif
  </div>
  <div class="d-flex align-items-center gap-3">
    <!-- Notification -->
    <a href="#" class="text-white text-decoration-none"><i class="bi bi-bell"></i></a>
    <!-- Paramètre -->
    <div class="dropdown">
      <a class="text-white text-decoration-none dropdown-toggle" href="#" role="button" id="dropdownMenuLink" data-bs-toggle="dropdown" aria-expanded="false">
        <i class="bi bi-gear"></i>
      </a>

      <ul class="dropdown-menu dropdown-menu-end" aria-labelledby="dropdownMenuLink">
        <li>
          <a class="dropdown-item" href="#">Profil utilisateur</a>
        </li>
        <li><hr class="dropdown-divider"></li>
        <li>
          <a class="dropdown-item" href="#">À propos / Aide</a>
        </li>
        <li><hr class="dropdown-divider"></li>
        <li>
          <a class="dropdown-item" href="#">Sauvegarde & restauration</a>
        </li> 
      </ul>
    </div>
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