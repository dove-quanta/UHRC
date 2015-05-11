<?php

module_load_include('inc', 'node', 'node.pages');

$query = new EntityFieldQuery();
$query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'recommendation')
    ->propertyCondition('status', 1);
$rResult = $query->execute();
$nids = array_keys($rResult['node']);
foreach($nids as $nid) {
    $node = node_load($nid);
    get_emails_for_node($node);
}
function get_emails_for_node($node){
    $emails=array();
    $emails+=get_emails_for_mda($node->field_responsible_mda['und'][0]['target_id']);
    foreach($node->field_responsible_mda['und'] as $contributing_mda){
        $emails+=get_emails_for_mda($contributing_mda['target_id']);
    }
    return $emails;
}
function get_emails_for_mda($nid){
    $query="select entity_id from field_data_field_mda where bundle='user' and field_mda_target_id=$nid";
    $records = db_query($query);
    $emails=array();
    foreach ($records as $record) {
        $user=user_load($record->entity_id);
        $emails[]=$user->mail;
    }
    return $emails;
}