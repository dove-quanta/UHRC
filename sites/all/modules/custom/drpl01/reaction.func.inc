<?php
function update_notification($notification, $node)
{
    $notification->field_rid['und'][0]['target_id'] = $node->nid;
    $notification->field_rmda['und'][0]['target_id'] = $node->field_responsible_mda['und'][0]['target_id'];
    for ($i = 0; $i < count($node->field_contributing_mda['und']); $i++) {
        $notification->field_cmda['und'][$i]['target_id'] = $node->field_contributing_mda['und'][$i]['target_id'];
    }
    node_save($notification);
}

function create_child_notifications($notification,$node)
{

    for ($i = 1; $i < count($node->field_responsible_mda['und']); $i++) {
        create_child_notification($notification, $node, $i);
    }
}

function create_child_notification($notification, $node, $mda)
{
    global $user;
    $child = new stdClass();
    $child->title = $notification->title;
    $child->type = $notification->type;
    $child->field_rmda['und'][0]['target_id'] = $node->field_responsible_mda['und'][$mda]['target_id'];
    for ($i = 0; $i < count($node->field_contributing_mda['und']); $i++) {
        $child->field_cmda['und'][$i]['target_id'] = $node->field_contributing_mda['und'][$i]['target_id'];
    }
    $child->field_notification_parent['und'][0]['target_id'] = $notification->nid;
    $child = node_submit($child); // Prepare node for saving
    node_save($child);

}

function create_child_recommendations($node)
{
    for ($i = 1; $i < count($node->field_responsible_mda['und']); $i++) {
        create_child_recommendation($node, $i);
    }
}

function create_child_recommendation($node, $mda)
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
    $child->comment = 0; // 0 = comments disabled, 1 = read only, 2 = read/write
    $child->field_recommendation['und'][0]['value'] = $node->field_recommendation['und'][0]['value'];
    $child->field_year['und'][0]['value'] = $node->field_year['und'][0]['value'];
    $child->field_next_state_deadline['und'][0]['value'] = $node->field_next_state_deadline['und'][0]['value'];
    $child->field_thematic_area['und'][0]['target_id'] = $node->field_thematic_area['und'][0]['target_id'];
    $child->field_mechanism['und'][0]['target_id'] = $node->field_mechanism['und'][0]['target_id'];
    $child->field_responsible_mda['und'][0]['target_id'] = $node->field_responsible_mda['und'][$mda]['target_id'];
    for ($i = 0; $i < count($node->field_contributing_mda['und']); $i++) {
        $child->field_contributing_mda['und'][$i]['target_id'] = $node->field_contributing_mda['und'][$i]['target_id'];
    }
    $child->field_parent['und'][0]['target_id'] = $node->nid;
    $child = node_submit($child); // Prepare node for saving
    node_save($child);

}

function get_emails_for_contributing_mdas($node)
{
    $emails = "";
    foreach ($node->field_contributing_mda['und'] as $contributing_mda) {
        $emails .= get_emails_for_mda($contributing_mda['target_id']) . ",";
    }
    return $emails;
}

function get_emails_for_responsible_mdas($node)
{
    $emails = "";
    foreach ($node->field_responsible_mda['und'] as $contributing_mda) {
        $emails .= get_emails_for_mda($contributing_mda['target_id']) . ",";
    }
    return $emails;
}

function get_emails_for_mda($nid)
{
    $query = "select entity_id from field_data_field_mda where bundle='user' and field_mda_target_id=$nid";
    $records = db_query($query);
    $emails = "";
    foreach ($records as $record) {
        $user = user_load($record->entity_id);
        $emails .= $user->mail . ",";
    }
    return $emails;
}

function fetch_child_recommendations($node)
{
    $query = new EntityFieldQuery();
    $query
        ->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'recommendation')
        ->propertyCondition('status', 1)
        ->fieldCondition('field_parent', 'target_id', $node->field_parent['und'][0]['target_id'], '=');
    $rResult = $query->execute();
    $nids = array_keys($rResult['node']);
    return $nids;
}

function fetch_child_recommendation_by_mda($node, $mda)
{
    $query = new EntityFieldQuery();
    $query
        ->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'recommendation')
        ->propertyCondition('status', 1)
        ->fieldCondition('field_parent', 'target_id', $node->nid, '=')
        ->fieldCondition('field_responsible_mda', 'target_id', $mda, '=');
    $rResult = $query->execute();
    $nids = array_keys($rResult['node']);
    return $nids;
}
function fetch_pending_notifications()
{
    $query = new EntityFieldQuery();
    $query
        ->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'notification')
        ->propertyCondition('status', 1)
        ->fieldCondition('field_status', 'value', "Pending", '=');
    $rResult = $query->execute();
    $nids = array_keys($rResult['node']);
    return $nids;
}