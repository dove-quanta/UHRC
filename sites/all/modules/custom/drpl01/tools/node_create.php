<?php

module_load_include('inc', 'node', 'node.pages');

global $user;
$node = new stdClass();
$node->title = "YOUR TITLE";
$node->type = "notification";
node_object_prepare($node); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
$node->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled
$node->uid = $user->uid;
$node->status = 1; //(1 or 0): published or not
$node->promote = 0; //(1 or 0): promoted to front page
$node->comment = 1; // 0 = comments disabled, 1 = read only, 2 = read/write
$bodytext="Hello, world";
$node->body[$node->language][0]['value']   = $bodytext;
$node->body[$node->language][0]['summary'] = text_summary($bodytext);
$node->body[$node->language][0]['format']  = 'plain_text';
$node = node_submit($node); // Prepare node for saving
node_save($node);