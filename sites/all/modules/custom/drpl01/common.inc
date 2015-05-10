<?php
function GenericFilter(&$nodes, $filters,$types)
{
    $rem_nids = array(); // items to remove
    foreach ($filters as $fieldName => $options) {
        if (count($options[0]) == 0) unset($filters[$fieldName]);
    }
    foreach ($nodes as $nid => $value) {
        $node = node_load($nid);
        if(!in_array($node->type,$types)){
            $rem_nids[$nid]=0;
            continue;
        }
        foreach ($filters as $fieldName => $options) {
            $field_value=$options[1];
            $tids=$options[0];
            if (!in_array($node->{$fieldName}['und'][0][$field_value], $tids)) {
                $rem_nids[$nid]=0;
                continue;
            }
        }
    }
    foreach ($rem_nids as $nid=>$value) {
        unset($nodes[$nid]);
    }
}

function typeFilter(&$nodes, $type)
{
    foreach ($nodes as $nid => $value) {
        $node = node_load($nid);
        if ($node->type !== $type) {
            unset($nodes[$nid]);
        }
    }
}

function rangeFilter($nodes, $start, $length)
{
    $rnodes = array();
    $count = -1;
    foreach ($nodes as $nid => $value) {
        $count++;
        if ($count < $start)
            continue;
        if (count($rnodes) > $length - 1)
            continue;
        $rnodes[$nid] = $value;
    }
    return $rnodes;
}

function userFilter(&$nodes, $types)
{
    global $user;
    $rem_nids = array();
    foreach ($nodes as $nid => $value) {
        $node = node_load($nid);
        if(!in_array($node->type,$types)){
            $rem_nids[$nid]=0;
            continue;
        }
        if ($user->field_mda['und'][0]['target_id'] != $node->field_responsible_mda['und'][0]['target_id']) {
            $rem_nids[$nid]=0;
        }
    }
    foreach ($rem_nids as $nid=>$value) {
        unset($nodes[$nid]);
    }
}

function compare_recommendations($c1, $c2)
{
    return strcmp($c1[0], $c2[0]);
}

function compare_results($c1, $c2)
{
    $y1 = node_load($c1)->field_year['und'][0]['value'];
    $y2 = node_load($c2)->field_year['und'][0]['value'];
    return strcmp($y1, $y2);
}