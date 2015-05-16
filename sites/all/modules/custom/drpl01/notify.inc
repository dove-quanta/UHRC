<?php
module_load_include('inc', 'drpl01', 'reaction.func');
function insert_rid()
{
    $pending = fetch_pending_notifications();
    foreach ($pending as $nid) {
        $node = node_load($nid);
        if (!empty($node->field_notification_parent)) {
            $parent_notification = node_load($node->field_notification_parent['und'][0]['target_id']);
            $parent_recommendation = node_load($parent_notification->field_rid['und'][0]['target_id']);
            $mda = $node->field_rmda['und'][0]['target_id'];
            $cid = fetch_child_recommendation_by_mda($parent_recommendation, $mda);
            $node->field_rid['und'][0]['target_id'] = $cid[0];
            node_save($node);
        }
    }
}
# send emails to each pending notification
function send_notifications(){
    #insert_rid();
    $pending = fetch_pending_notifications();
    foreach ($pending as $nid) {
        $node = node_load($nid);
        $url="node/".$node->field_rid['und'][0]['target_id']."";
        $title=node_load($node->field_rmda['und'][0]['target_id'])->title;
        $author=node_load($node->field_rid['und'][0]['target_id'])->uid;
        $email=get_emails_for_mda($node->field_rmda['und'][0]['target_id']);
        $cmdas=array();
        # template for admin role
        $admin_template=node_load(1962)->body['und'][0]['value'];
        # template for responsible mda
        $rmda_template=node_load(1963);
        # template for responsible admin
        $cmda_template=node_load(1964);
        print $email."<br>";
        foreach($node->field_cmda['und'] as $cmda){
            $cmdas[]=array($cmda['target_id'],get_emails_for_mda($cmda['target_id']));
        }
    }
    var_dump($admin_template);

}


function testing(){
    $query = new EntityFieldQuery();
    $query
        ->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'mda')
        ->propertyCondition('status', 1);
    $rResult = $query->execute();
    $nids = array_keys($rResult['node']);
    foreach($nids as $nid){
        print "UG$nid : ".node_load($nid)->title."<br>";
        $new_user = array(
            'name' => "UG$nid",
            'pass' => 'uhrc', // note: do not md5 the password
            'mail' => "UG$nid@example.com",
            'status' => 1,
            'init' => "UG$nid@example.com",
            'field_mda' => array(LANGUAGE_NONE => array(array('target_id' => "$nid"))),
            'roles' => array(
                DRUPAL_AUTHENTICATED_RID => 'authenticated user',
                4 => 'mda',
            ),
        );
        #user_save(NULL, $new_user);
    }
}