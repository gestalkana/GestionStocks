<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>@yield('title','Gestion des stocks')</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.10.5/font/bootstrap-icons.css" rel="stylesheet">
  <link rel="stylesheet" type="text/css" href="css/Mycss.css">

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
      <main class="col-md-9 ms-sm-auto col-lg-10 main-content">
        @yield('content')
      </main>
    </div>
  </div>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
  <script src="js/CaseAcocherProduit.js"></script>
  <script src="js/categorie.js"></script>
</body>
</html>