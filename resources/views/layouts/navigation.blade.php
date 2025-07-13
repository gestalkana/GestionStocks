<nav class="bg-blue-900 px-4 py-2 flex justify-between items-center">
  <div class="flex items-center space-x-2 text-white font-semibold text-lg">
    <i class="bi bi-box-seam text-xl"></i>
    <span>Gestion des stocks</span>
  </div>

  <div class="flex items-center space-x-4 text-white text-lg">
    <!-- Notifications -->
    <a href="#" class="hover:opacity-80 transition-opacity" aria-label="Notifications">
      <i class="bi bi-bell"></i>
    </a>
    <!-- Paramètres -->
    <a href="#" class="hover:opacity-80 transition-opacity" aria-label="Paramètres">
      <i class="bi bi-gear"></i>
    </a>
    <!-- Déconnexion -->
    <a href="#" class="hover:opacity-80 transition-opacity" aria-label="Déconnexion">
      <i class="bi bi-power"></i>
    </a>

    <!-- Login / User -->
    <div class="ml-4">
      @auth
        <span class="text-sm">{{ Auth::user()->name }}</span>
      @else
        <a href="{{ route('login') }}" class="text-sm bg-white text-blue-900 px-3 py-1 rounded hover:bg-gray-100 transition">Se connecter</a>
      @endauth
    </div>
  </div>
</nav>
