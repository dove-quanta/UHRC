<?php
function update_notification($notification, $node){
    $notification->field_rid['und'][0]['target_id']=$node->nid;
    node_save($notification);

}
function create_child_recommendation($node){
    /*global $user;
    $child = new stdClass();
    $child->title = $node->title;
    $child->type = $node->type;
    node_object_prepare($child); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
    $child->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled
    $child->uid = $user->uid;
    $child->status = 1; //(1 or 0): published or not
    $child->promote = 0; //(1 or 0): promoted to front page
    $child->comment = 0; // 0 = comments disabled, 1 = read only, 2 = read/write
    $child->field_year, field_next_state_deadline, field_thematic_area
    $child = node_submit($child); // Prepare node for saving
    node_save($child);*/
    #entity_ui_clone_entity("recommendation",$node);

}