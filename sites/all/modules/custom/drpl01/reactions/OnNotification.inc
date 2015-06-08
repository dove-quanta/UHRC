<?php
function update_notification($notification, $node, $type)
{
    $notification->field_rid['und'][0]['target_id'] = $node->nid;
    $notification->field_rmda['und'][0]['target_id'] = $node->field_responsible_mda['und'][0]['target_id'];
    for ($i = 0; $i < count($node->field_contributing_mda['und']); $i++) {
        $notification->field_cmda['und'][$i]['target_id'] = $node->field_contributing_mda['und'][$i]['target_id'];
    }
    $notification->field_event_type['und'][0]['value'] = $type;
    $notification->field_recepient['und'][0]['target_id'] = $node->field_responsible_mda['und'][0]['target_id'];
    node_save($notification);
}

function create_child_notifications($node)
{
    if (empty($node->field_cmda)) return;
    for ($i = 0; $i < count($node->field_cmda['und']); $i++) {
        create_child_notification($node, $i);
    }
}

function create_child_notification($node, $mda)
{
    global $user;
    $child = new stdClass();
    $child->title = $node->title;
    $child->type = $node->type;
    node_object_prepare($child); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
    $child->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled
    $child->uid = $user->uid;
    $child->status = 1; //(1 or 0): published or not
    $child->promote = 0; //(1 or 0): promoted to front page
    $child->comment = 0; // 0 =
    $child->field_rmda['und'][0]['target_id'] = $node->field_rmda['und'][0]['target_id'];
    for ($i = 0; $i < count($node->field_cmda['und']); $i++) {
        $child->field_cmda['und'][$i]['target_id'] = $node->field_cmda['und'][$i]['target_id'];
    }
    $child->field_notification_parent['und'][0]['target_id'] = $node->nid;
    $child->field_recepient['und'][0]['target_id'] = $node->field_cmda['und'][$mda]['target_id'];
    $child->field_rid['und'][0]['target_id'] = $node->field_rid['und'][0]['target_id'];
    $child = node_submit($child); // Prepare node for saving
    node_save($child);

}

?>