<?php

function get_view_comments_data() {

  $start = isset($_GET['iDisplayStart']) ? $_GET['iDisplayStart'] : "0";
  $end = isset($_GET['iDisplayLength']) ? $_GET['iDisplayLength'] : "0";
  $skey = isset($_GET['sSearch']) ? $_GET['sSearch'] : "";
  $NID = isset($_GET['NID']) ? $_GET['NID'] : "";

  $results = db_query('select  a.cid from comment a where a.nid = :nid order by a.cid desc', array(':nid' => $NID));
  $iTotal = $results->rowCount();
  $iFilteredTotal = $results->rowCount();
  $output = array(
    "sEcho" => intval($_GET['sEcho']),
    "iTotalRecords" => $iTotal,
    "iTotalDisplayRecords" => $iFilteredTotal,
    "aaData" => array()
  );
  foreach($results as $result){
    $cid=$result->cid;
    $comment=comment_load($cid);
    $row=array();
    $row[]=$comment->cid;
    $row[]=$comment->name;
    $date = new DateTime('@' . $comment->created);
    $row[] = $date->format('Y-m-d H:i:s');
    $row[]="<h4>".$comment->subject."</h4><p>".$comment->comment_body['und'][0]['value']."</p>";
    //$row[]="<a href='view-replies?NID='".$cid." class='btn btn-default btn-sm'><i class='fa fa-mail-reply'></i> Replies</a>";
    $output['aaData'][] = $row;      
  }
  echo json_encode($output);
}
