<?php
function update_notification($notification, $node, $type)
{
    $notification->field_rid['und'][0]['target_id'] = $node->nid;
    $notification->field_rmda['und'][0]['target_id'] = $node->field_responsible_mda['und'][0]['target_id'];
    for ($i = 0; $i < count($node->field_contributing_mda['und']); $i++) {
        $notification->field_cmda['und'][$i]['target_id'] = $node->field_contributing_mda['und'][$i]['target_id'];
    }
    $notification->field_event_type['und'][0]['value'] = $type;
    node_save($notification);
}
?>