<?php

module_load_include('inc', 'drpl01', 'common');

function get_recommendation_data()
{
    $start = isset($_GET['iDisplayStart']) ? $_GET['iDisplayStart'] : "0";
    $length = isset($_GET['iDisplayLength']) ? $_GET['iDisplayLength'] : "0";
    $skey = isset($_GET['sSearch']) ? $_GET['sSearch'] : "";
    $mkey = isset($_GET['mSearch']) ? $_GET['mSearch'] : "";
    $SEARCH = isset($_GET['SEARCH']) ? $_GET['SEARCH'] : "";
    $mechanism = isset($_GET['mechanism']) ? $_GET['mechanism'] : "";
    $mda = isset($_GET['mda']) ? $_GET['mda'] : "";
    $theme = isset($_GET['theme']) ? $_GET['theme'] : "";
    $year = isset($_GET['year']) ? $_GET['year'] : "";
    $SEARCH = explode(",", str_replace("|", "", $SEARCH));
    $A = array();
    $B = array();
    $C = array();
    $D = array();
    if (!empty($mda)) {
        $A[] = $mda;
    }
    if (!empty($mechanism)) {
        $B[] = $mechanism;
    }
    if (!empty($theme)) {
        $C[] = $theme;
    }
    if (!empty($year)) {
        $D[] = $year . "-01-01T00:00:00";
    }
    $skey = empty($mkey) ? $skey : $mkey;
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
    $types=array( "recommendation");
    $filters = array(
        "field_mechanism" => array($B,"target_id"),
        "field_thematic_area" => array($C,"target_id"),
        "field_responsible_mda" => array($A,"target_id"),
        "field_year" => array($D,"value")
    );
    GenericFilter($nodes, $filters,$types);
    $iTotal = count($nodes);
    $iFilteredTotal = count($nodes);
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
        $row[] = $node->field_recommendation['und'][0]['value'] . '<br><a class="btn-xs btn-primary" href="' . $filename . '" title="Download source document" target="' . $target . '">
  <i class="fa fa-download"></i></a>' . "<input class='ohrc-id' type='hidden' value='" . $node->nid . "'/>";
        $row[] = node_load($node->field_thematic_area['und'][0]['target_id'])->title;

        $date = new DateTime($node->field_year['und'][0]['value']);
        $year = $date->format('Y');
        $row[] = $mechanism . " (" . $year . ")";
        $date = empty($node->field_next_state_deadline) ? "" : new DateTime($node->field_next_state_deadline['und'][0]['value']);
        $row[] = empty($node->field_next_state_deadline) ? "" : $date->format('Y');
        $cmda="Contributor(s):<ul>";
        foreach($node->field_contributing_mda['und'] as $cmdatid){
            $cmda.="<li>".node_load($cmdatid['target_id'])->title."</li>";
        }
        $cmda.="</ul>";
        $row[] = "Responsible:<br>".node_load($node->field_responsible_mda['und'][0]['target_id'])->title."<br>".$cmda;
        $row[] = empty($node->field_indicators) ? "" : $node->field_indicators['und'][0]['value'];
        $row[] = empty($node->field_baseline) ? "" : $node->field_baseline['und'][0]['value'];
        $row[] = empty($node->field_target) ? "" : $node->field_target['und'][0]['value'];
        $row[] = empty($node->field_means_of_verification) ? "" : node_load($node->field_means_of_verification['und'][0]['target_id'])->title;
        $row[] = empty($node->field_status_of_implementation) ? "" : $node->field_status_of_implementation['und'][0]['value'];
        $output['aaData'][] = $row;
    }
    echo json_encode($output);
}
