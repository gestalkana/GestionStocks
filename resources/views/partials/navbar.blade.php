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
    <form method="POST" action="{{ route('logout') }}" class="d-inline">
      @csrf
     <button type="submit" class="btn btn-link text-white text-decoration-none p-0 m-0">
        <i class="bi bi-power"></i>
    </button>
    </form>
  </div>
</nav>