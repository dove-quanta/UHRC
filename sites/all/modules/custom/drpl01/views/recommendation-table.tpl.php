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
                aoData.push({"name": "SEARCH", "value": "{$SEARCH}"});
                aoData.push({"name": "mSearch", "value": "{$mSearch}"});
                aoData.push({"name": "mechanism", "value": "{$mechanism}"});
                aoData.push({"name": "mda", "value": "{$mda}"});
                aoData.push({"name": "theme", "value": "{$theme}"});
                aoData.push({"name": "year", "value": "{$year}"});
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





