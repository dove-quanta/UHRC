
<div class="row">
    <div class="col-md-1"></div>
    <div class="col-md-10">
        <?php
        $view=field_view_field("node",$node,"field_recommendation");
        print drupal_render($view);
        ?>
    </div>
    <div class="col-md-1"></div>
</div>
<div class="row">
    <div class="col-md-1"></div>
    <div class="col-md-2">
        <?php
        $view=field_view_field("node",$node,"field_year");
        print drupal_render($view);
        ?>
    </div>
    <div class="col-md-2">
        <?php
        $view=field_view_field("node",$node,"field_next_state_deadline");
        print drupal_render($view);
        ?>
    </div>
    <div class="col-md-2">
        <?php
        $view=field_view_field("node",$node,"field_sr_mandate");
        print drupal_render($view);
        ?>
    </div>
    <div class="col-md-2">
        <?php
        $display=array("label"=>"hidden");
        $view=field_view_field("node",$node,"field_thematic_area");
        print drupal_render($view);
        ?>
    </div>
    <div class="col-md-2">
        <?php
        $view=field_view_field("node",$node,"field_mechanism");
        print drupal_render($view);
        ?>
    </div>
    <div class="col-md-1"></div>
</div>
<div class="row">
    <div class="col-md-1"></div>
    <div class="col-md-4">
        <?php
        $view=field_view_field("node",$node,"field_responsible_mda");
        print drupal_render($view);
        ?>
    </div>
    <div class="col-md-4">
        <?php
        $view=field_view_field("node",$node,"field_contributing_mda");
        print drupal_render($view);
        ?>
    </div>
    <div class="col-md-2">
        <ul style="list-style:none;">
            <li>
                <?php
                $view=field_view_field("node",$node,"field_means_of_verification");
                print drupal_render($view);
                ?>
            </li>
            <li>
                <?php
                $view=field_view_field("node",$node,"field_other_means_of_verificatio");
                print drupal_render($view);
                ?>
            </li>
            <li>
                <?php
                $view=field_view_field("node",$node,"field_verification_document");
                print drupal_render($view);
                ?>
            </li>
        </ul>
    </div>
    <div class="col-md-1"></div>
</div>
<div class="row">
    <div class="col-md-1"></div>
    <div class="col-md-2">
        <?php
        $view=field_view_field("node",$node,"field_indicators");
        print drupal_render($view);
        ?>

    </div>
    <div class="col-md-2">
        <?php
        $view=field_view_field("node",$node,"field_baseline");
        print drupal_render($view);
        ?>

    </div>
    <div class="col-md-2">
        <?php
        $view=field_view_field("node",$node,"field_target");
        print drupal_render($view);
        ?>

    </div>
    <div class="col-md-1"></div>
</div>
<div class="row">
    <div class="col-md-1"></div>
    <div class="col-md-10">
        <?php
        $view=field_view_field("node",$node,"field_status_of_implementation");
        print drupal_render($view);
        ?>
    </div>
</div>
<div class="row">
    <div class="col-md-1"></div>
    <div class="col-md-6">
        <?php print render($content['comments']); ?>
    </div>
    <div class="col-md-4"></div>
    <div class="col-md-1"></div>
</div>
<!--
<div class="row">
    <div class="col-md-2"></div>
    <div class="col-md-10">
        <?php print render($content['links']); ?>
    </div>
</div>
-->
<style type="text/css">
    #edit-comment-body-und-0-format{
        display:none;
    }
</style>