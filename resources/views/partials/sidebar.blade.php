<nav class="col-md-3 col-lg-2 d-md-block sidebar">
      <a class="hover-link {{ Request::is('home*') ? 'text-dark fw-bold bg-primary' : '' }}" 
        href="{{ route('home') }}">
         <i class="bi bi-speedometer2"></i> Tableau de bord
       </a>
       <a class="hover-link {{ Request::is('produits*') ? 'text-dark fw-bold bg-primary' : '' }}" href="{{ route('produits.index') }}">
         <i class="bi bi-box-seam"></i> Produits
       </a>
        <a class="hover-link {{ Request::is('fournisseurs*') ? 'text-dark fw-bold bg-primary' : '' }}" href="{{ route('fournisseurs.index') }}">
         <i class="bi bi-truck"></i> Fournisseurs
       </a>
       <a class="hover-link {{ Request::is('stocksEntrees*') ? 'text-dark fw-bold bg-primary' : '' }}" href="{{ route('stocksEntrees.index') }}">
         <i class="bi bi-box-arrow-in-down"></i> Entrées de Stock
       </a>
       <a class="hover-link {{ Request::is('stocksSorties*') ? 'text-dark fw-bold bg-primary' : '' }}" href="{{ route('stocksSorties.index') }}">
         <i class="bi bi-box-arrow-up"></i> Sorties de stock
       </a>
</nav>