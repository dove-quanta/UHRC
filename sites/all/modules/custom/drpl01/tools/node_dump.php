<?php

global $user;
module_load_include('inc', 'node', 'node.pages');

$query = new EntityFieldQuery();
$query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'recommendation')
    ->propertyCondition('status', 1);
$rResult = $query->execute();
$nids = array_keys($rResult['node']);

foreach($nids as $nid){
  $node=node_load($nid);
 $title = '';
  $title.='|' . $node->{'field_recommendation'}['und'][0]['value'];
  $title.='|' . node_load($node->{'field_thematic_area'}['und'][0]['target_id'])->title;
  $title.='|' . node_load($node->{'field_mechanism'}['und'][0]['target_id'])->title;
  $title.='|' . $node->{'field_sr_mandate'}['und'][0]['value'];
  $title.='|' . node_load($node->{'field_responsible_mda'}['und'][0]['target_id'])->title;
  if (!empty($form_state['values']['field_contributing_mda'])) {
    $c = count($form_state['values']['field_contributing_mda']['und']);
    for ($i = 0; $i < $c; $i++) {
      $title.='|' . node_load($form_state['values']['field_contributing_mda']['und'][$i]['target_id'])->title;
    }
  }
  $title.='|' . $node->{'field_indicators'}['und'][0]['value'];
  $title.='|' . $node->{'field_baseline'}['und'][0]['value'];
  $title.='|' . $node->{'field_target'}['und'][0]['value'];

  if (!empty($node->{'field_means_of_verification'})) {
    $title.='|' . node_load($node->{'field_means_of_verification'}['und'][0]['target_id'])->title;
  }
  $title.='|' . $node->{'field_other_means_of_verificatio'}['und'][0]['value'];
  $title.='|' . $node->{'field_status_of_implementation'}['und'][0]['value'];
  $node->{'body'}['und'][0]['value'] = $title;
  $node->{'body'}['und'][0]['format'] = "plain_text";
  node_save($node);
}
/*
$node=node_load('626');
var_dump($node);*/