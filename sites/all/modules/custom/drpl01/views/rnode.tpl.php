<?php
$nid = empty($_GET['nid']) ? '' : $_GET['nid'];
$notification = node_load($nid);
$rid = empty($notification->field_rid) ? -1 : $notification->field_rid['und'][0]['target_id'];
$node = node_load($rid);
?>
<div class="row">
    <div class="col-md-1"></div>
    <div class="col-md-10">
        <?php
        $nodev= node_view($node);
        print drupal_render($nodev);
        ?>
    </div>
    <div class="col-md-1"></div>
</div>
<div class="row">
    <div class="col-md-1"></div>
    <div class="col-md-4"></div>
    <div class="col-md-4"><a class="btn btn-default" href="node/<?php print $rid; ?>/edit" role="button">Edit recommendation</a></div>
    <div class="col-md-1"></div>
</div>
