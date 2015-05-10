<script>
  function publish() {
    var checked = jQuery('#comment :checked');
    var query = '';
    for (var i = 0; i < checked.length; i++) {
      query = query + checked[i].id + '|';
    }
    alert(query);
  }
</script>
<script>
  jQuery(document).ready(function() {
    jQuery('#comment').dataTable({
      "oLanguage": {
        "sProcessing": '<i class="fa fa-2x fa-spinner fa-spin"></i>'
      },
      "fnServerParams": function(aoData) {
        aoData.push({"name": "SEARCH", "value": "{$SEARCH}"});
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
        {"bSearchable": false, "bSortable": false, "aTargets": [4]},
        //{"bSearchable": false, "bSortable": false, "aTargets": [5]}
      ],
      "sAjaxSource": "comment-data"
    });
  });
</script>
<div class='row'>
  <div class="col-md-6">
    <div class="btn-group" id="comment-actions">
      <a class="btn btn-primary" href="#"><i class="fa fa-user fa-fw"></i> Actions</a>
      <a class="btn btn-primary dropdown-toggle" data-toggle="dropdown" href="#">
        <span class="fa fa-caret-down"></span></a>
      <ul class="dropdown-menu">
        <li><a href="node/add/ohrc-comment"><i class="fa fa-plus fa-fw"></i> Add</a></li>
        <!--<li><a href="comment-grid"><i class="fa fa-trash-o fa-fw"></i> Delete</a></li>
        <li><a href="comment-grid"><i class="fa fa-share fa-fw"></i> Publish</a></li>
        <li><a href="comment-grid"><i class="fa fa-refresh fa-fw"></i> Refresh</a></li>-->
      </ul>
    </div>
  </div>
  <div class="col-md-6"></div>
</div>
<div id="dynamic">
  <table  class="display  table table-bordered" id="comment" width="100%">
    <thead>
      <tr>
        <th >nid</th>
        <!--<th ><input type="checkbox" /></th>-->
        <th >Title</th>
        <th >Comment</th>
        <th >User</th>
        <th >Date</th>
      </tr>
    </thead>
    <tbody>

    </tbody>
    <tfoot>
      <tr>
        <th ></th>
        <!--<th ></th>-->
        <th ></th>
        <th ></th>
        <th ></th>
        <th ></th>
      </tr>
    </tfoot>
  </table>
</div>





