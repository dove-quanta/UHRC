<?php

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

?>