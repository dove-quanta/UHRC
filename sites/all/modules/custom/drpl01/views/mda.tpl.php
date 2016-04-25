<?php
global $user;
$node = user_load($user->uid);
$MID = $node->field_mda['und'][0]['target_id']
?>
<script>
    function load_url(url) {
        jQuery("#iframe-dashboard").attr("src", url);
    }
</script>
<div class="row">
    <div class="col-md-6">Welcome <?php echo $user->name;?></div>
    <div class="col-md-6">
        <!--<span style="float:right">Logout</span>-->
    </div>
</div>
<div class="row">
    <div class="col-md-12">
        <div class='ohrc-menu'>
            <ul class="nav nav-pills nav-stacked ohrc-menu-list">
                <li class><a><strong>Content Management Menu</strong></a></li>
                <li class="divider"></li>
                <li class="active">
                    <a href="##" title="Admin dashboard" onclick="load_url('mda-dashboard');">Dashboard</a>
                </li>
                <li>
                    <a href="##" title="Recommendations"
                       onclick="load_url('mda-recommendation-table');">Recommendations</a>
                </li>
                <li>
                    <a href="##" title="Recommendations"
                       onclick="load_url('related-recommendation-table');">Related Recommendations</a>
                </li>
                <li class="divider"></li>
                <li>
                    <a href="##" title="Notifications"
                       onclick="load_url('responsible-notifications?MDA=<?php echo $MID; ?>');">Notifications</a>
                </li>
            </ul>
        </div>
        <div class="tab-content ohrc-content">
            <div class="tab-pane fade active in" id="dashboard">
                <div class="row">
                    <div class="col-md-12">
                        <iframe id="iframe-dashboard" src="mda-dashboard" scrolling="no"
                                onload="parent.changeHeight('iframe-dashboard')"
                                onmouseover="parent.changeHeight('iframe-dashboard')"></iframe>
                    </div>
                </div>
            </div>
        </div>
    </div>





