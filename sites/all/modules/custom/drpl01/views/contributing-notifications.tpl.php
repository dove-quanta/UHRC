<div class="row">
    <div class="col-md-1"></div>
    <div class="col-md-10"><h4>Notifications</h4></div>
    <div class="col-md-1"></div>
</div>
<div class="row">
    <div class="col-md-1"></div>
    <div class="col-md-10">
        <?php
        $mda = empty($_GET['MDA']) ? "" : $_GET['MDA'];
        $filter = array();
        $args = array();
        if($mda!=''){
            $args[]=$mda;
        }
        $view = views_get_view('notifications');
        $view->set_display('block_1');
        $view->set_arguments($args);
        $view->pre_execute();
        $view->execute();
        print $view->preview();
        ?>
    </div>
    <div class="col-md-1"></div>
</div>