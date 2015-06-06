<script>
    function load_url(url) {
        parent.jQuery("#iframe-dashboard").attr("src", url);
    }

</script>
<div class="container" style="height:500px;">
    <div class="row">
        <div class="col-md-4">

            <div class="btn-group open ohrc-dashboard-top">
                <a class="btn btn-primary ohrc-dashboard-low" href="#"><i class="fa fa-check-circle fa-fw"></i> Recommendations</a>
                <a class="btn btn-primary dropdown-toggle" data-toggle="dropdown" href="#">
                    <span class="fa fa-caret-down"></span></a>
                <ul class="dropdown-menu ohrc-dashboard-dropdown">
                    <li><a href="##" onclick="load_url('node/add/recommendation');"><i class="fa fa-plus fa-fw"></i> Add</a></li>
                    <li><a href="##" onclick="load_url('admin-recommendation-table');"><i class="fa fa-list fa-fw"></i> View</a></li>
                </ul>
            </div>
        </div>

        <div class="col-md-4">

            <div class="btn-group open ohrc-dashboard-top">
                <a class="btn btn-primary ohrc-dashboard-low" href="#"><i class="fa fa-user fa-fw"></i> User</a>
                <a class="btn btn-primary dropdown-toggle" data-toggle="dropdown" href="#">
                    <span class="fa fa-caret-down"></span></a>
                <ul class="dropdown-menu ohrc-dashboard-dropdown">
                    <li><a href="##" onclick="load_url('admin/people/create');"><i class="fa fa-plus fa-fw"></i> Add</a></li>
                    <li><a href="##" onclick="load_url('admin/people');"><i class="fa fa-list fa-fw"></i> View</a></li>
                </ul>
            </div>
        </div>

        <div class="col-md-4">

            <div class="btn-group open ohrc-dashboard-top">
                <a class="btn btn-primary ohrc-dashboard-low" href="user/logout" target="_top"><i class="fa fa-sign-out fa-fw"></i> Sign Out</a>
            </div>
        </div>
    </div>
    <div class="row">
        <div class="col-md-4">
            <!--      <a class="btn btn-sm btn-primary ohrc-dashboard" href="library" title="">
                    <div class="dashboard-item">
                      <div>Add a recommendation</div>
                    </div>
                  </a> -->
        </div>

        <div class="col-md-4">
            <!--      <a class="btn btn-sm btn-primary ohrc-dashboard" href="library" title="">
                    <div class="dashboard-item">
                      <i class="fa fa-2x fa-user"></i>
                      <div>Add a user</div>
                    </div>
                  </a> -->
        </div>

        <div class="col-md-4">
            <!--      <a class="btn btn-sm btn-primary" href="library" title="">
                    <div class="dashboard-item">
                      <div>Add a recommendation</div>
                    </div>
                  </a> -->

        </div>
    </div>

</div>
