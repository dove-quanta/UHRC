<?php

module_load_include('inc', 'node', 'node.pages');

function typeFilter(&$nodes, $type) {
  $nids = array();
  foreach ($nodes as $nid => $value) {
    $node = node_load($nid);
    if ($node->type !== $type) {
      $nids[] = $nid;
    }
  }
  foreach ($nids as $nid) {
    unset($nodes[$nid]);
  }
}

function rangeFilter($nodes, $start, $length) {
  $rnodes = array();
  $count = -1;
  foreach ($nodes as $nid => $value) {
    $count++;
    if ($count < $start)
      continue;
    if (count($rnodes) > $length - 1)
      continue;
    $rnodes[$nid] = $value;
  }
  return $rnodes;
}

function categoryFilter(&$nodes, $fieldName, $tids) {
  if(count($tids)==0) return;
  $nids = array();
  foreach ($nodes as $nid => $value) {
    $node = node_load($nid);
    if (!in_array($node->{$fieldName}['und'][0]['target_id'], $tids)) {
      $nids[] = $nid;
    }
  }
  foreach ($nids as $nid) {
    unset($nodes[$nid]);
  }
}

$term = "human";
$server = search_api_server_load('db_service');
$index = search_api_index_load('db_service_index');
$query = new SearchApiQuery($index);
$query->keys($term);
$query->fields(array('body:value'));
$srv = new SearchApiDbService($server);
$result = $srv->search($query);
$nodes = $result['results'];
asort($nodes);
foreach ($nodes as $nid => $value) {
  print $nid . ":" . node_load($nid)->type . "\n";
}
print count($nodes) . "\n";
$fieldName='field_mechanism';
$tids=array(4);
typeFilter($nodes, "recommendation");
categoryFilter($nodes, $fieldName, $tids);
print count($nodes) . "\n";
$start = 1;
$length = 7;
$rnodes = rangeFilter($nodes, $start, $length);
foreach ($rnodes as $nid => $value) {
  print $nid . ":x-" . node_load($nid)->type . "\n";
}
