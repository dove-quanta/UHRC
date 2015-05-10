<?php

function get_criteria() {

  $data = "<div class='row ohrc-container'>";
  $data.="<div class=\"col-md-12\">
	<div class='ohrc-search-criteria'>
    <div id='ohrc-search-header'>Searchable Criteria</div>
    <form class=\"navbar-form navbar-left\" role=\"search\" id='ohrc-form-criteria' action='database_search'>";
  $data.=get_mechanisms();
  $data.=get_years();
  $data.=get_thematic_areas();
  $data.=get_mdas();
  $data.="
        <button type=\"submit\" class=\"btn btn-default\">Go</button>
    </form>
</div>
</div>";
  $data.= "</div>";
  return $data;
}

function get_mechanisms() {

  $query = new EntityFieldQuery();
  $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'mechanism')
      ->propertyCondition('status', 1);
      //->propertyOrderBy('title', 'ASC');
  $rResult = $query->execute();
  $nids = array_keys($rResult['node']);

  $data = "
            <select class='form-control' name='mechanism'>";
  $data.="<option>Mechanism</option>";
  $optgroup = array();
  foreach ($nids as $nid) {
    $node = node_load($nid);
    $optgroup[$node->nid] = $node->field_optgroup['und'][0]['value'];
  }
  #International
  $data.="<optgroup label='International'>";
  foreach ($nids as $nid) {
    $node = node_load($nid);
    if ($optgroup[$node->nid] == 'International') {
      $data.="<option name='B" . $node->nid . "' value='" . $node->nid . "'>" . $node->title . "</option>";
    }
  }
  $data.="</optgroup>";
  #Regional
  $data.="<optgroup label='Regional'>";
  foreach ($nids as $nid) {
    $node = node_load($nid);
    if ($optgroup[$node->nid] == 'Regional') {
      $data.="<option name='B" . $node->nid . "' value='" . $node->nid . "'>" . $node->title . "</option>";
    }
  }
  $data.="</optgroup>";
  #National
  $data.="<optgroup label='National'>";
  foreach ($nids as $nid) {
    $node = node_load($nid);
    if ($optgroup[$node->nid] == 'National') {
      $data.="<option name='B" . $node->nid . "' value='" . $node->nid . "'>" . $node->title . "</option>";
    }
  }
  $data.="</optgroup>";
  $data.="
            </select>
        ";
  return $data;
}

function get_thematic_areas() {

  $query = new EntityFieldQuery();
  $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'thematic_area')
      ->propertyCondition('status', 1)
      ->propertyOrderBy('title', 'ASC');
  $rResult = $query->execute();
  $nids = array_keys($rResult['node']);

  $data = "
            <select class='form-control' name='theme'>";
  $data.="<option>Theme</option>";
  foreach ($nids as $nid) {
    $node = node_load($nid);
    $data.="<option name='C" . $node->nid . "' value='" . $node->nid . "'>" . $node->title . "</option>";
  }
  $data.="
            </select>
       ";
  return $data;
}

function get_mdas() {

  $query = new EntityFieldQuery();
  $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'mda')
      ->propertyCondition('status', 1)
      ->propertyOrderBy('title', 'ASC');
  $rResult = $query->execute();
  $nids = array_keys($rResult['node']);

  $data = "
            <select class='form-control' name='mda'>";
  $data.="<option>MDA</option>";
  foreach ($nids as $nid) {
    $node = node_load($nid);
    $data.="<option name='A" . $node->nid . "' value='" . $node->nid . "'>" . $node->title . "</option>";
  }
  $data.="
            </select>
     ";
  return $data;
}

function get_years() {
  $query = new EntityFieldQuery();
  $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'year')
      ->propertyCondition('status', 1);
  $rResult = $query->execute();
  $nids = array_keys($rResult['node']);
  $list_of_years = array();
  foreach ($nids as $nid) {

    $node = node_load($nid);
    $year = $node->title;
    $listOfYears[$year] = 0;
  }
  $data = "
            <select class='form-control' name='year'>";
  $data.="<option>Year</option>";
  $nids = array_keys($listOfYears);
  asort($nids);
  foreach ($nids as $year) {
    $data.="<option name='D" . $year . "' value='$year'>" . $year . "</option>";
  }
  $data.="
            </select>
        ";
  return $data;
}
