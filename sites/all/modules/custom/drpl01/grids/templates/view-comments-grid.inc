
<script>
  jQuery(document).ready(function() {
    jQuery('#view-comments').dataTable({
      "oLanguage": {
        "sProcessing": '<i class="fa fa-2x fa-spinner fa-spin"></i>'
      },
      "fnServerParams": function(aoData) {
        aoData.push({"name": "NID", "value": "{$NID}"});
        aoData.push({"name": "SEARCH", "value": "{$SEARCH}"});
        aoData.push({"name": "IFRAME", "value": "{$IFRAME}"});
      },
      "bProcessing": true,
      "bServerSide": true,
      "searching": false,
      //"bInfo": false,
      "aoColumnDefs": [
        {"bSearchable": false, "bVisible": false, "aTargets": [0]},
        {"bSearchable": false, "bSortable": false, "aTargets": [1]},
        {"bSearchable": false, "bSortable": false, "aTargets": [2]},
        {"bSearchable": false, "bSortable": false, "aTargets": [3]},
      ],
      "sAjaxSource": "view-comments-data"
    });
  });
</script>
<div class='row'>

  <div class="col-md-3">    
    <div class="btn-group" id="comment-actions">
      <a class="btn btn-primary" href="#"><i class="fa fa-user fa-fw"></i> Actions</a>
      <a class="btn btn-primary dropdown-toggle" data-toggle="dropdown" href="#">
        <span class="fa fa-caret-down"></span></a>
      <ul class="dropdown-menu">
        <li><a href="node/add/recommendation-comments?NID={$NID}"><i class="fa fa-plus fa-fw"></i> Add</a></li>
      </ul>
    </div>
  </div>  
  <div class="col-md-3"></div>
  <div class="col-md-3"></div>
  <div class="col-md-3">
    <a class="btn btn-default btn-sm" href="mda-recommendation-table">
      <i class="fa fa-reply"></i> Back to your recommendations
    </a>
  </div>
</div>
<div id="dynamic">
  <table  class="display  table table-bordered" id="view-comments" width="100%">
    <thead>
      <tr>
        <th >nid</th>
        <th >User</th>
        <th >Date</th>
        <th >Title/Comment</th>
      </tr>
    </thead>
    <tbody>

    </tbody>
    <tfoot>
      <tr>
        <th ></th>
        <th ></th>
        <th ></th>
        <th ></th>
      </tr>
    </tfoot>
  </table>
</div>





