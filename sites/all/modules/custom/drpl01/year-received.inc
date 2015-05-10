<?php
function year_received() {
  $query = new EntityFieldQuery();
  $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'year')
      ->propertyCondition('status', 1);
  $rResult = $query->execute();
  $nids = array_keys($rResult['node']);
  $list_of_years=array();
  foreach ($nids as $nid) {
    
    $node = node_load($nid);
    $year = $node->title;
    $listOfYears[]=$year;
  }
  $data = "<div class='row'>";
  $data.="<div class='col-md-12'>";
  $data.="<form  id='year-received-elements'>";
  asort($listOfYears);
  foreach ($listOfYears as $year) {    
     $data.="<div><label class='ohrc-criteria-nowrap'><input type='checkbox' id='D".$year."' onchange='parent.search();'>".$year."</label></div>";
  }
  $data.="</form>";
  $data.="</div>";
  $data.="</div>";
  $page = array(
    '#markup' => $data,
  );
  return $page;
}


