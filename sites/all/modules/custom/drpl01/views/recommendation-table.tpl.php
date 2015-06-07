<?php
$IFRAME = isset($_GET['IFRAME']) ? $_GET['IFRAME'] : "";
$SEARCH = isset($_GET['SEARCH']) ? $_GET['SEARCH'] : "";
$mSearch = isset($_GET['mSearch']) ? $_GET['mSearch'] : "";
$mechanism = isset($_GET['mechanism']) ? $_GET['mechanism'] : "";
$mda = isset($_GET['mda']) ? $_GET['mda'] : "";
$theme = isset($_GET['theme']) ? $_GET['theme'] : "";
$year = isset($_GET['year']) ? $_GET['year'] : "";
$mechanism = str_replace("Mechanism", "", $mechanism);
$mda = str_replace("MDA", "", $mda);
$theme = str_replace("Theme", "", $theme);
$year = str_replace("Year", "", $year);
?>
<script>
    function download_file(otype) {
        var ids = parent.jQuery("#iframe-recommendation-grid").contents().find(".ohrc-id");
        var qq = "";
        for (var i = 0; i < ids.length; i++) {
            qq += ids[i].value + "|";
        }
        window.location = 'download-' + otype + '?qq=' + qq;
    }
</script>
<script>
    jQuery(document).ready(function () {
        jQuery('#recommendation').dataTable({
            "oLanguage": {
                "sProcessing": '<i class="fa fa-2x fa-spinner fa-spin"></i>'
            },
            "lengthMenu": [[10, 25, 50,100,500,1000], [10, 25, 50,100,500,1000]],
            "fnServerParams": function (aoData) {
                aoData.push({"name": "SEARCH", "value": "<?php echo $SEARCH; ?>"});
                aoData.push({"name": "mSearch", "value": "<?php echo $mSearch; ?>"});
                aoData.push({"name": "mechanism", "value": "<?php echo $mechanism ; ?>"});
                aoData.push({"name": "mda", "value": "<?php echo $mda; ?>"});
                aoData.push({"name": "theme", "value": "<?php echo $theme ; ?>"});
                aoData.push({"name": "year", "value": "<?php echo $year ; ?>"});
            },
            "processing": true,
            "serverSide": true,
            "searching": false,
            //"bInfo": false,
            "aoColumnDefs": [
                {"bSearchable": false, "bVisible": false, "aTargets": [0]},
                {"bSearchable": false, "bVisible": false, "bSortable": false, "aTargets": [1]},
                {"bSearchable": false, "bSortable": false, "aTargets": [2]},
                {"bSearchable": false, "bSortable": false, "aTargets": [3]},
                {"bSearchable": false, "bSortable": false, "aTargets": [4]},
                {"bSearchable": false, "bSortable": false, "aTargets": [5]},
                {"bSearchable": false, "bSortable": false, "aTargets": [6]},
                {"bSearchable": false, "bSortable": false, "aTargets": [7]},
                {"bSearchable": false, "bSortable": false, "aTargets": [8]},
                {"bSearchable": false, "bSortable": false, "aTargets": [9]},
                {"bSearchable": false, "bSortable": false, "aTargets": [10]},
                {"bSearchable": false, "bSortable": false, "aTargets": [11]}
            ],
            "sAjaxSource": "recommendation-data"
        });
    });
</script>
<div id='ohrc-ms-div'>
    <div class="btn-group">
        <a class="btn btn-primary" href="#"><i class="fa fa-download fa-fw"></i> Export</a>
        <a class="btn btn-primary dropdown-toggle" data-toggle="dropdown" href="#">
            <span class="fa fa-caret-down"></span></a>
        <ul class="dropdown-menu">
            <li><a href="#" onclick="download_file('excel');"><i class="fa fa-columns fa-fw"></i> Excel</a></li>
            <li><a href="#" onclick="download_file('word');"><i class="fa fa-file-text-o fa-fw"></i> Word</a></li>
        </ul>
    </div>
</div>
<div id="dynamic">
    <table class="display  table table-bordered" id="recommendation" width="100%">
        <thead>
        <tr>
            <th>nid</th>
            <th>Title</th>
            <th>Recommendation</th>
            <th>Thematic area</th>
            <th>Mechanism and year</th>
            <th>Next State Report deadline</th>
            <th>Responsible MDA</th>
            <th>Indicators</th>
            <th>Baseline</th>
            <th>Target</th>
            <th>Means of verification</th>
            <th>Status of implementation</th>
        </tr>
        </thead>
        <tbody>

        </tbody>
        <tfoot>
        <tr>
            <th></th>
            <th></th>
            <th></th>
            <th></th>
            <th></th>
            <th></th>
            <th></th>
            <th></th>
            <th></th>
            <th></th>
            <th></th>
            <th></th>
        </tr>
        </tfoot>
    </table>
</div>





