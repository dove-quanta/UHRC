<?php
function thematic_area() {
  $query = new EntityFieldQuery();
  $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'thematic_area')
      ->propertyCondition('status', 1)
      ->propertyOrderBy('title', 'ASC');
  $rResult = $query->execute();
  $nids = array_keys($rResult['node']);

  $data = "<div class='row'>";
  $data.="<div class='col-md-12'>";
  $data.="<form  id='thematic-area-elements'>";
  foreach ($nids as $nid) {
    $node = node_load($nid);
    $data.="<div><label class='ohrc-criteria-nowrap'><input type='checkbox'id='C".$node->nid."' onchange='parent.search();'>".$node->title."</label></div>";
  }
  $data.="</form>";
  $data.="</div>";
  $data.="</div>";
  $page = array(
    '#markup' => $data,
  );
  return $page;
}


