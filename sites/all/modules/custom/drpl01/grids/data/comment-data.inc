<?php

function get_comments_data() {

  $start = isset($_GET['iDisplayStart']) ? $_GET['iDisplayStart'] : "0";
  $end = isset($_GET['iDisplayLength']) ? $_GET['iDisplayLength'] : "0";
  $skey = isset($_GET['sSearch']) ? $_GET['sSearch'] : "";
  $query = new EntityFieldQuery();
  $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'ohrc_comment')
      //->propertyCondition('status', 1)
      ->propertyCondition('title', "%" . $skey . "%", "like");
  $rResult = $query->execute();
  $nids = array_keys($rResult['node']);
  $iTotal = count($nids);
  $iFilteredTotal = count($nids);
  $query = new EntityFieldQuery();
  $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'ohrc_comment')
      //->propertyCondition('status', 1)
      ->propertyCondition('title', "%" . $skey . "%", "like")
      ->range($start, $end);

  $rResult = $query->execute();
  $nids = array_keys($rResult['node']);
  /*
   * Output
   */
  $output = array(
    "sEcho" => intval($_GET['sEcho']),
    "iTotalRecords" => $iTotal,
    "iTotalDisplayRecords" => $iFilteredTotal,
    "aaData" => array()
  );

  foreach ($nids as $nid) {
    $node = node_load($nid);
    $row = array();
    $row[] = $node->nid;
    if ($node->status == 1) {
      //$row[] = '<input type="checkbox" id="' . $node->nid . '" disabled />';
    }
    else{      
     // $row[] = '<input type="checkbox" id="' . $node->nid . '" />';
    }
    $row[] = $node->title;
    $row[] = $node->field_your_comment['und'][0]['value'];
    $row[] = user_load($node->uid)->name;
    $date = new DateTime('@' . $node->created);
    $row[] = $date->format('Y-m-d H:i:s');
    $output['aaData'][] = $row;
  }
  echo json_encode($output);
}
