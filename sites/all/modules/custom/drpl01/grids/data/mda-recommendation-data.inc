<?php

module_load_include('inc', 'drpl01', 'common');
function get_mda_recommendation_data()
{
    global $user;
    $user = user_load($user->uid);
    $start = isset($_GET['iDisplayStart']) ? $_GET['iDisplayStart'] : "0";
    $length = isset($_GET['iDisplayLength']) ? $_GET['iDisplayLength'] : "0";
    $skey = isset($_GET['sSearch']) ? $_GET['sSearch'] : "";
    $SEARCH = isset($_GET['SEARCH']) ? $_GET['SEARCH'] : "";
    $SEARCH = explode(",", str_replace("|", "", $SEARCH));
    $A = array();
    $B = array();
    $C = array();
    $D = array();
    foreach ($SEARCH as $key) { #filter along A
        if (preg_match("/A/", $key)) {
            $A[] = str_replace("A", "", $key);
        }
        #filter along B
        if (preg_match("/B/", $key)) {
            $B[] = str_replace("B", "", $key);
        }
        #filter along C
        if (preg_match("/C/", $key)) {
            $C[] = str_replace("C", "", $key);
        }
        #filter along D
        if (preg_match("/D/", $key)) {
            $D[] = str_replace("D", "", $key) . "-01-01T00:00:00";
        }
    }
    $server = search_api_server_load('db_service');
    $index = search_api_index_load('db_service_index');
    $query = new SearchApiQuery($index);
    $query->keys($skey);
    $query->fields(array('body:value'));
    $srv = new SearchApiDbService($server);
    $result = $srv->search($query);
    $nodes = $result['results'];
    $types=array("recommendation");
    userFilter($nodes,$types);
    $iTotal = count($nodes);
    $iFilteredTotal = count($nodes);

    /*
     * Output
     */
    $output = array(
        "sEcho" => intval($_GET['sEcho']),
        "iTotalRecords" => $iTotal,
        "iTotalDisplayRecords" => $iFilteredTotal,
        "aaData" => array()
    );
    $rnodes = rangeFilter($nodes, $start, $length);
    foreach ($rnodes as $nid => $value) {
        $node = node_load($nid);
        $row = array();
        $row[] = $node->nid;
        $row[] = $node->title;
        $filename = "#";
        $target = '';
        if (!empty($node->field_verification_document)) {
            $filename = 'sites/default/files/' . $node->field_verification_document['und'][0]['filename'];
            $target = '_blank';
        }
        $mechanism = node_load($node->field_mechanism['und'][0]['target_id'])->title;
        if ($mechanism == 'Uganda Human Rights Commission') {
            $filename = 'http://www.uhrc.ug/latest-annual-report/';
            $target = '_blank';
        }
        //$row[] = "<a href='#overlay=node/".$nid."/edit' title='View/Edit'><i class='fa fa-2x fa-edit'></i></a>";
        $row[] = "<div class='btn-group ohrc-td-actions'>
  <a class='btn btn-primary' href='#'><i class='fa fa-user fa-fw'></i> Actions</a>
  <a class='btn btn-primary dropdown-toggle' data-toggle='dropdown' href='#'>
    <span class='fa fa-caret-down'></span></a>
  <ul class='dropdown-menu'>
    <li><a href='#overlay=node/" . $nid . "/edit' ><i class='fa fa-pencil fa-fw'></i> Edit</a></li>
    <li><a href='view-comments?NID=" . $nid . "' ><i class='fa fa-comment fa-fw'></i> Comments</a></li>
    <li><a href='linked-recommendation-table?NID=".$nid."' ><i class='fa fa-pencil fa-fw'></i>Other Responsible MDA</a></li>
    <li><a href='" . $filename . "' target='" . $target . "'><i class='fa fa-download fa-fw'></i> Download</a></li>
  </ul>
</div><br><br><br><br><br><br>";
        $row[] = $node->field_recommendation['und'][0]['value'] . "<input class='ohrc-id' type='hidden' value='" . $node->nid . "'/>";
        $row[] = node_load($node->field_thematic_area['und'][0]['target_id'])->title;
        //$mechanism = node_load($node->field_mechanism['und'][0]['target_id'])->title;
        $date = new DateTime($node->field_year['und'][0]['value']);
        $year = $date->format('Y');
        $row[] = $mechanism . " (" . $year . ")";
        /*$date = new DateTime($node->field_next_state_deadline['und'][0]['value']);
        $row[] = $date->format('Y');
        $row[] = node_load($node->field_responsible_mda['und'][0]['target_id'])->title;
        $row[] = $node->field_indicators['und'][0]['value'];
        $row[] = $node->field_baseline['und'][0]['value'];
        $row[] = $node->field_target['und'][0]['value'];
        $row[] = node_load($node->field_means_of_verification['und'][0]['target_id'])->title;
        $row[] = $node->field_status_of_implementation['und'][0]['value'];
        $output['aaData'][] = $row;*/
        $date = empty($node->field_next_state_deadline) ? "" :new DateTime($node->field_next_state_deadline['und'][0]['value']);
        $row[] = empty($node->field_next_state_deadline) ? "" :$date->format('Y');
        $row[] = node_load($node->field_responsible_mda['und'][0]['target_id'])->title;
        $row[] = empty($node->field_indicators) ? "" : $node->field_indicators['und'][0]['value'];
        $row[] = empty($node->field_baseline) ? "" : $node->field_baseline['und'][0]['value'];
        $row[] = empty($node->field_target) ? "" : $node->field_target['und'][0]['value'];
        $row[] = empty($node->field_means_of_verification) ? "" : node_load($node->field_means_of_verification['und'][0]['target_id'])->title;
        $row[] = empty($node->field_status_of_implementation) ? "" : $node->field_status_of_implementation['und'][0]['value'];
        $output['aaData'][] = $row;
    }
    echo json_encode($output);
}
