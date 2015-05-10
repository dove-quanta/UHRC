<?php

module_load_include('inc', 'drpl01', 'criteria');

function database_search() {

  $skey = isset($_GET['mSearch']) ? $_GET['mSearch'] : "";
  $mechanism = isset($_GET['mechanism']) ? $_GET['mechanism'] : "";
  $mda = isset($_GET['mda']) ? $_GET['mda'] : "";
  $theme = isset($_GET['theme']) ? $_GET['theme'] : "";
  $year = isset($_GET['year']) ? $_GET['year'] : "";
  $query = "";
  if (!empty($skey)) {
    $query.="mSearch=" . $skey . "&";
  }
  if (!empty($mda)) {
    $query.="mda=" . $mda . "&";
  }
  if (!empty($mechanism)) {
    $query.="mechanism=" . $mechanism . "&";
  }
  if (!empty($theme)) {
    $query.="theme=" . $theme . "&";
  }
  if (!empty($year)) {
    $query.="year=" . $year . "&";
  }
  $query = trim($query, "&");
#header start - write function to generate header
  $data = get_criteria();
#header end
  $data .= "<div class='row ohrc-container'>";
  $data.="<div class='col-md-3' style='width:20%;'>";
  $data.="<div class='ohrc-criteria-div' id='ohrc-left-div'>";
  $data.="<h5>Refine your search</h5>";
  $data.="<form class='form-inline'>";
  $data.="<label class='ohrc-criteria-nowrap'>Keyword: <input id='ohrc-refine' style='width:90px;' type='text' size='5' ><input type='button' value='Refine' onclick='search2();'></label>";
  $data.="</form>";
  $data.="</div>";
  $data.="<div class='ohrc-criteria-div'>";
  $data.="<h5>Mechanism</h5>";
  $data.="<iframe id='iframe-mechanism' class='ohrc-criteria' src='mechanism'>";
  $data.="</iframe>";
  $data.="</div>";
  $data.="<div class='ohrc-criteria-div'>";
  $data.="<h5>Year</h5>";
  $data.="<iframe id='iframe-year-received'  class='ohrc-criteria' src='year-received'>";
  $data.="</iframe>";
  $data.="</div>";
  $data.="<div class='ohrc-criteria-div'>";
  $data.="<h5>Thematic areas</h5>";
  $data.="<iframe id='iframe-thematic-area'  class='ohrc-criteria' src='thematic_area'>";
  $data.="</iframe>";
  $data.="</div>";
  $data.="<div class='ohrc-criteria-div'>";
  $data.="<h5>MDA</h5>";
  $data.="<iframe id='iframe-mda'  class='ohrc-criteria' src='mda'>";
  $data.="</iframe>";
  $data.="</div>";
  $data.="</div>";
  $data.="<div class='col-md-9' style='width:80%;'>";
  $data.="<iframe scrolling=\"no\" id='iframe-recommendation-grid'  class='ohrc-search' src='recommendation-grid?" . $query . "' onmouseover='changeHeight(\"iframe-recommendation-grid\");'>";
  $data.="</iframe>";
  $data.="</div>";
  $data.="</div>";
  $page = array(
    '#markup' => $data,
  );
  return $page;
}
