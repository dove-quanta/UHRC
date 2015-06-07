<?php
$nid=empty($_GET['nid'])?'':$_GET['nid'];
$notification=node_load($nid);
$parent=empty($notification->field_notification_parent)? -1:$notification->field_notification_parent['und'][0]['target_id'];
$rid=empty($notification->field_rid)? -1:$notification->field_rid['und'][0]['target_id'];

?>