<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>@yield('title','Gestion des stocks')</title>

  <!-- Bootstrap CSS -->
  <!-- <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet"> -->
  <link rel="stylesheet" href="{{ asset('vendor/bootstrap/bootstrap.min.css') }}">

  <!-- Bootstrap Icons -->
  <!-- <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.10.5/font/bootstrap-icons.css" rel="stylesheet"> -->
  <link rel="stylesheet" href="{{ asset('vendor/bootstrap-icons/bootstrap-icons.css') }}">

  <!-- SweetAlert2 -->
  <!-- <link href="https://cdn.jsdelivr.net/npm/sweetalert2@11.10.5/dist/sweetalert2.min.css" rel="stylesheet"> -->
  <link rel="stylesheet" href="{{ asset('vendor/sweetalert2/sweetalert2.min.css') }}">

  <!-- Tippy.js CSS -->
  <link rel="stylesheet" href="https://unpkg.com/tippy.js@6/dist/tippy.css" />
  <link rel="stylesheet" href="{{ asset('vendor/tippy/tippy.css') }}">

  <!-- Print.js CSS -->
  <link rel="stylesheet" href="https://printjs.crabbly.com/css/print.min.css">
  <link rel="stylesheet" href="{{ asset('vendor/printjs/print.min.css') }}">

  <!-- Feuilles de styles personnalisées -->
  <link rel="stylesheet" type="text/css" href="{{ asset('css/Mycss.css') }}">
  <link rel="stylesheet" type="text/css" href="{{ asset('css/impression.css') }}">

  <meta name="csrf-token" content="{{ csrf_token() }}">
</head>
<body data-current-user-id="{{ auth()->id() }}">
  <!-- barre de navigation -->
  @include('partials.navbar')

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

  <!-- Bootstrap JS -->
  <!-- <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" defer></script> -->
  <script src="{{ asset('vendor/bootstrap/bootstrap.bundle.min.js') }}" defer></script>

  <!-- Chart.js -->
  <!-- <script src="https://cdn.jsdelivr.net/npm/chart.js"></script> -->
  <script src="{{ asset('vendor/chartjs/chart.umd.min.js') }}"></script>

  <!-- SweetAlert2 JS -->
  <!-- <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11.10.5/dist/sweetalert2.all.min.js"></script> -->
  <script src="{{ asset('vendor/sweetalert2/sweetalert2.min.js') }}"></script>

  <!-- Tippy.js + Popper -->
  <!-- <script src="https://unpkg.com/@popperjs/core@2"></script> -->
  <script src="{{ asset('vendor/popper/popper.min.js') }}"></script>
  <!-- <script src="https://unpkg.com/tippy.js@6"></script> -->
  <script src="{{ asset('vendor/tippy/tippy.umd.min.js') }}"></script>
  <script src="{{ asset('js/Tooltip.js') }}"></script>

  <!-- Print.js -->
  <!-- <script src="https://printjs.crabbly.com/js/print.min.js" defer></script> -->
  <script src="{{ asset('vendor/printjs/print.min.js') }}" defer></script>

  <!-- jQuery -->
  <!-- <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script> -->
  <script src="{{ asset('vendor/jquery/jquery-3.6.0.min.js') }}"></script>

  <!-- Scripts personnalisés -->
  <script src="{{ asset('js/alerte/actionMessage.js') }}"></script>
  <script src="{{ asset('js/modalUtils.js') }}"></script>
  <script src="{{ asset('js/tableauDebord/graphique.js') }}"></script>

  <!-- Produit -->
  <script src="{{ asset('js/produits/PaginationProduit.js') }}"></script>
  <script src="{{ asset('js/produits/CaseAcocherProduit.js') }}"></script>
  <script src="{{ asset('js/produits/ProduitCreation.js') }}"></script>
  <script src="{{ asset('js/produits/ProduitEdition.js') }}"></script>
  <script src="{{ asset('js/produits/ProduitSuppression.js') }}"></script>
  <script src="{{ asset('js/produits/UniteMesure.js') }}"></script>
  <script src="{{ asset('js/produits/RechercheEtFiltrage.js') }}"></script>

  <!-- Catégorie -->
  <script src="{{ asset('js/categories/CategorieCreation.js') }}"></script>
  <script src="{{ asset('js/categories/CategorieEdition.js') }}"></script>
  <script src="{{ asset('js/categories/CategorieSuppression.js') }}"></script>

  <!-- Fournisseur -->
  <script src="{{ asset('js/fournisseurs/FournisseurCreation.js') }}"></script>
  <script src="{{ asset('js/fournisseurs/FournisseurEdition.js') }}"></script>

  <!-- Stocks Entrées -->
  <script src="{{ asset('js/stocksEntrees/EntreeCreation.js') }}"></script>
  <script src="{{ asset('js/stocksEntrees/EntreeEditionShow.js') }}"></script>
  <script src="{{ asset('js/stocksEntrees/ChoixUnite.js') }}"></script>
  <script src="{{ asset('js/stocksEntrees/filtreEntree.js') }}"></script>

  <!-- Stocks Sorties -->
  <script src="{{ asset('js/stocksSorties/AjoutProduitBS.js') }}"></script>
  <script src="{{ asset('js/stocksSorties/BScreation.js') }}"></script>
  <script src="{{ asset('js/stocksSorties/BSedition.js') }}"></script>
  <script src="{{ asset('js/stocksSorties/BSsuppression.js') }}"></script>
  <script src="{{ asset('js/stocksSorties/filtreSortie.js') }}"></script>
  <script src="{{ asset('js/stocksSorties/ChoixUnite.js') }}"></script>

  <!-- Impression personnalisée -->
  <script src="{{ asset('js/impression.js') }}"></script>
  <!-- Profile -->
  <script src="{{ asset('js/profil/ConfirmationPassword.js') }}"></script>
</body>
</html>
