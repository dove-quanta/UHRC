<?php

function get_recommendation_table() {
  $IFRAME = isset($_GET['IFRAME']) ? $_GET['IFRAME'] : "";
  $SEARCH = isset($_GET['SEARCH']) ? $_GET['SEARCH'] : "";
  $mSearch = isset($_GET['mSearch']) ? $_GET['mSearch'] : "";
  $mechanism = isset($_GET['mechanism']) ? $_GET['mechanism'] : "";
  $mda = isset($_GET['mda']) ? $_GET['mda'] : "";
  $theme = isset($_GET['theme']) ? $_GET['theme'] : "";
  $year = isset($_GET['year']) ? $_GET['year'] : "";
  $mechanism = str_replace("Mechanism", "", $mechanism);
  $mda = str_replace("MDA", "", $mda);
  $theme = str_replace("Theme", "", $theme);
  $year = str_replace("Year", "", $year);
  $data = file_get_contents("sites/all/modules/custom/drpl01/grids/templates/recommendation-grid.inc");

  $data = str_replace('{$IFRAME}', $IFRAME, $data);
  $data = str_replace('{$SEARCH}', $SEARCH, $data);
  $data = str_replace('{$mSearch}', $mSearch, $data);
  $data = str_replace('{$mechanism}', $mechanism, $data);
  $data = str_replace('{$mda}', $mda, $data);
  $data = str_replace('{$theme}', $theme, $data);
  $data = str_replace('{$year}', $year, $data);
  #$data = str_replace('{$START}', $start, $data);
  #$data = str_replace('{$END}', $end, $data);
  $page = array(
    '#markup' => $data,
  );
  return $page;
}

function get_admin_recommendation_table() {
  $IFRAME = isset($_GET['IFRAME']) ? $_GET['IFRAME'] : "";
  $SEARCH = isset($_GET['SEARCH']) ? $_GET['SEARCH'] : "";
  #$start = isset($_GET['iDisplayStart']) ? $_GET['iDisplayStart'] : "0";
  #$end = isset($_GET['iDisplayLength']) ? $_GET['iDisplayLength'] : "0";
  $data = file_get_contents("sites/all/modules/custom/drpl01/grids/templates/admin-recommendation-grid.inc");

  $data = str_replace('{$IFRAME}', $IFRAME, $data);
  $data = str_replace('{$SEARCH}', $SEARCH, $data);
  #$data = str_replace('{$START}', $start, $data);
  #$data = str_replace('{$END}', $end, $data);
  $page = array(
    '#markup' => $data,
  );
  return $page;
}

function get_mda_recommendation_table() {
  $IFRAME = isset($_GET['IFRAME']) ? $_GET['IFRAME'] : "";
  $SEARCH = isset($_GET['SEARCH']) ? $_GET['SEARCH'] : "";
  #$start = isset($_GET['iDisplayStart']) ? $_GET['iDisplayStart'] : "0";
  #$end = isset($_GET['iDisplayLength']) ? $_GET['iDisplayLength'] : "0";
  $data = file_get_contents("sites/all/modules/custom/drpl01/grids/templates/mda-recommendation-grid.inc");

  $data = str_replace('{$IFRAME}', $IFRAME, $data);
  $data = str_replace('{$SEARCH}', $SEARCH, $data);
  #$data = str_replace('{$START}', $start, $data);
  #$data = str_replace('{$END}', $end, $data);
  $page = array(
    '#markup' => $data,
  );
  return $page;
}

function get_comments() {
  $IFRAME = isset($_GET['IFRAME']) ? $_GET['IFRAME'] : "";
  $SEARCH = isset($_GET['SEARCH']) ? $_GET['SEARCH'] : "";
  #$start = isset($_GET['iDisplayStart']) ? $_GET['iDisplayStart'] : "0";
  #$end = isset($_GET['iDisplayLength']) ? $_GET['iDisplayLength'] : "0";
  $data = file_get_contents("sites/all/modules/custom/drpl01/grids/templates/comment-grid.inc");

  $data = str_replace('{$IFRAME}', $IFRAME, $data);
  $data = str_replace('{$SEARCH}', $SEARCH, $data);
  #$data = str_replace('{$START}', $start, $data);
  #$data = str_replace('{$END}', $end, $data);
  $page = array(
    '#markup' => $data,
  );
  return $page;
}

function get_view_comments() {
  $IFRAME = isset($_GET['IFRAME']) ? $_GET['IFRAME'] : "";
  $SEARCH = isset($_GET['SEARCH']) ? $_GET['SEARCH'] : "";
  $NID = isset($_GET['NID']) ? $_GET['NID'] : "";
  #$start = isset($_GET['iDisplayStart']) ? $_GET['iDisplayStart'] : "0";
  #$end = isset($_GET['iDisplayLength']) ? $_GET['iDisplayLength'] : "0";
  $data = file_get_contents("sites/all/modules/custom/drpl01/grids/templates/view-comments-grid.inc");

  $data = str_replace('{$IFRAME}', $IFRAME, $data);
  $data = str_replace('{$SEARCH}', $SEARCH, $data);
  $data = str_replace('{$NID}', $NID, $data);
  #$data = str_replace('{$START}', $start, $data);
  #$data = str_replace('{$END}', $end, $data);
  $page = array(
    '#markup' => $data,
  );
  return $page;
}

function get_view_replies() {
  $IFRAME = isset($_GET['IFRAME']) ? $_GET['IFRAME'] : "";
  $SEARCH = isset($_GET['SEARCH']) ? $_GET['SEARCH'] : "";
  $NID = isset($_GET['NID']) ? $_GET['NID'] : "";
  #$start = isset($_GET['iDisplayStart']) ? $_GET['iDisplayStart'] : "0";
  #$end = isset($_GET['iDisplayLength']) ? $_GET['iDisplayLength'] : "0";
  $data = file_get_contents("sites/all/modules/custom/drpl01/grids/templates/view-replies-grid.inc");

  $data = str_replace('{$IFRAME}', $IFRAME, $data);
  $data = str_replace('{$SEARCH}', $SEARCH, $data);
  $data = str_replace('{$NID}', $NID, $data);
  #$data = str_replace('{$START}', $start, $data);
  #$data = str_replace('{$END}', $end, $data);
  $page = array(
    '#markup' => $data,
  );
  return $page;
}

