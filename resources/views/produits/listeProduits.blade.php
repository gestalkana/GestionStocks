<!-- Liste des produits -->
<div id="zoneImpression">
<table class="table table-sm table-striped table-hover align-middle">
  <thead class="table-primary">
    <tr>
      <th scope="col"><input type="checkbox" id="selectAll" /></th>
      <th scope="col">Référence</th>
      <th scope="col">Nom du produit</th>
      <th scope="col">Catégorie</th>
      <th scope="col">Quantité</th>
      <th scope="col">Unite de Mesure</th>
    <!--   <th scope="col">Prix d'achat</th>
      <th scope="col">Prix de vente</th> -->
      <th scope="col">Statut</th>
    </tr>
  </thead>
  <tbody id="produitsTableBody">
     @include('produits.tbodyProduit', ['produits' => $produits])
  </tbody>
</table>
</div>
{{-- Boutons de pagination --}}
 <!-- Ajouter des liens de pagination -->
<!-- <div class="d-flex justify-content-center mb-4">

</div> -->