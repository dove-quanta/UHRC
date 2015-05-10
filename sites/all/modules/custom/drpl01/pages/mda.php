<script>
  function load_url(url) {
    jQuery("#iframe-dashboard").attr("src",url);
  }
</script>
<div class="row">
  <div class="col-md-6">Welcome {$USER}</div>
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
        <li class="active"><a href="##" title="Admin dashboard" onclick="load_url('mda-dashboard');">Dashboard</a></li>
        <li class="dropdown"><a href="##" data-toggle="dropdown" title="">Recommendations<span class="caret"></span></a>
          <ul class="dropdown-menu" role="menu">
            <li><a href="##" onclick="load_url('mda-recommendation-table');">View your recommendations</a></li>
            
          </ul>
        </li>
<!--        <li class="dropdown">
          <a href="#" data-toggle="dropdown" title="">Users<span class="caret"></span></a>
          <ul class="dropdown-menu" role="menu">
            <li>
              <a href="##" onclick="load_url('admin/people');">View Users</a>              
            </li>
          </ul>
        </li>-->
      </ul>
    </div>
    <div class="tab-content ohrc-content">      
      <div class="tab-pane fade active in" id="dashboard">
        <div class="row">
          <div class="col-md-12">  
            <iframe id="iframe-dashboard" src="mda-dashboard"  scrolling="no" onload="parent.changeHeight('iframe-dashboard')" onmouseover="parent.changeHeight('iframe-dashboard')"></iframe>
          </div>  
        </div>
    </div>
  </div>
</div>





