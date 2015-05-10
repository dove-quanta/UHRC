<?php

function get_discussions() {

  $query = new EntityFieldQuery();
  $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'ohrc_comment')
      ->propertyCondition('status', 1);
  $rResult = $query->execute();
  $nids = array();
  if (!empty($rResult['node'])) {
    $nids = array_keys($rResult['node']);
    arsort($nids);
  }

  $data = "
            <ul class='ohrc-discussion' id='ohrc-comments'>";
  $data.="<li id='ohrc-first-child'>";
  $data.="<span class='ohrc-header-discussion'><i class='fa fa-comments-o'></i>&nbsp;Discussion forums</span>";
  $data.="</li>";
  $i = 0;
  foreach ($nids as $nid) {
    $node = node_load($nid);
    $data.="<li>";
    $data.="<span class='ohrc-comment-li'><i class='fa fa-comments-o'></i>&nbsp;" . $node->title . ". </span>";
    $data.="<span class='ohrc-comment-li'>" . $node->field_your_comment['und'][0]['value'] . "</span>";
    $data.="</li>";
    $i+=1;
    if ($i > 9)
      break;
  }
  $data.="<li id='ohrc-discussion-footer'><a href='comment-grid'>View more discussion forums</a></li>";
  $data.="
            </ul>
        ";
  return $data;
}
