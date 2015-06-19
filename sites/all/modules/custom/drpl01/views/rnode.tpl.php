<?php
$nid = empty($_GET['nid']) ? '' : $_GET['nid'];
$notification = node_load($nid);
$rid = empty($notification->field_rid) ? -1 : $notification->field_rid['und'][0]['target_id'];
drupal_goto("node/$rid", array(
        'query' => array(
            'iframe' => '1'
        )
    )
);
?>