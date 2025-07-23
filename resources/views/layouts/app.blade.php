<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>@yield('title','Gestion des stocks')</title>
  <!-- bootstrap -->
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
  <!-- icon bootstrap -->
  <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.10.5/font/bootstrap-icons.css" rel="stylesheet">
  <!-- sweetAlert2 -->
  <link href="https://cdn.jsdelivr.net/npm/sweetalert2@11.10.5/dist/sweetalert2.min.css" rel="stylesheet">
  <!-- Tippy.js core -->
  <link rel="stylesheet" href="https://unpkg.com/tippy.js@6/dist/tippy.css" />
  <link rel="stylesheet" type="text/css" href="{{ asset('css/Mycss.css') }}">
  <meta name="csrf-token" content="{{ csrf_token() }}">
</head>
<body>
  <!-- barre de navigation -->
  @include('partials.navbar')
  <!-- Sidebar et contenu -->
  <div class="container-fluid">
    <div class="row">
      <!-- Sidebar -->
      @include('partials.sidebar')

      <!-- Contenu principal -->
      <main class="col-md-9 ms-sm-auto col-lg-10 main-content couleur-fond">
        @yield('content')
      </main>
    </div>
  </div>
  <!-- Bootstrap.js -->
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
  <!-- SweetAlert2.js -->
  <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11.10.5/dist/sweetalert2.all.min.js"></script>
   <!-- Tippy.js core -->
  <script src="https://unpkg.com/@popperjs/core@2"></script>
  <script src="https://unpkg.com/tippy.js@6"></script>
  <script src="{{ asset('js/Tooltip.js') }}"></script>
  <!-- Jquery -->
  <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
  <!-- Alerte -->
  <script src="{{ asset('js/alerte/actionMessage.js') }}"></script>
  <!-- AJAX  et jquery-->
  <!-- Produit -->
  <script src="{{ asset('js/produits/PaginationProduit.js') }}"></script>
  <script src="{{ asset('js/produits/CaseAcocherProduit.js') }}"></script>
  <script src="{{ asset('js/produits/ProduitCreation.js') }}"></script>
  <script src="{{ asset('js/produits/ProduitEdition.js') }}"></script>
  <script src="{{ asset('js/produits/ProduitSuppression.js') }}"></script>
  <script src="{{ asset('js/produits/UniteMesure.js') }}"></script>
  <!-- Categorie -->
  <script src="{{ asset('js/categories/CategorieCreation.js') }}"></script>
  <script src="{{ asset('js/categories/CategorieEdition.js') }}"></script>
  <script src="{{ asset('js/categories/CategorieSuppression.js') }}"></script>
  <!-- Fournisseur -->
  <script src="{{ asset('js/fournisseurs/FournisseurCreation.js') }}"></script>
  <script src="{{ asset('js/fournisseurs/FournisseurEdition.js') }}"></script>
</body>
</html>