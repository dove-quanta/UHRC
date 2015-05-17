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
function send_notifications()
{
    global $base_url;
    #insert_rid();
    $pending = fetch_pending_notifications();
    foreach ($pending as $nid) {
        $node = node_load($nid);
        $url = $base_url . "/" . "node/" . $node->field_rid['und'][0]['target_id'] . "";
        $rmda = node_load($node->field_rmda['und'][0]['target_id'])->title;
        $author = node_load($node->field_rid['und'][0]['target_id'])->uid;
        $email = get_emails_for_mda($node->field_rmda['und'][0]['target_id']);
        $cmdas = array();
        $params = array();
        $params['author'] = user_load($author)->name;
        $params['rmda'] = $rmda;
        $params['url'] = $url;
        # process emails for admin role
        $rid=5;
        $admins=usersOfRole($rid);
        foreach($admins as $admin){
            $email=getUserEmail($admin);
            $email = 'genesint@gmail.com';
            $sent = drupal_mail('drpl01', 'admin', $email, language_default(), $params, 'info@uhrcdatabase.org', TRUE);
            if ($sent) {
                print "Successful $admin<br>";
            }
        }

        # process email for responsible MDA
        $email=get_emails_for_mda($nid);
        $sent = drupal_mail('drpl01', 'rmda', $email, language_default(), $params, 'info@uhrcdatabase.org', TRUE);
        if ($sent) {
            print "Successful $nid<br>";
        }

        # process emails for contributing MDA
        foreach ($node->field_cmda['und'] as $cmda) {
            $email = get_emails_for_mda($cmda['target_id'])[0];
            $params['cmda'] = $cmda;
            $sent = drupal_mail('drpl01', 'cmda', $email, language_default(), $params, 'info@uhrcdatabase.org', TRUE);
            if ($sent) {
                print "Successful {$cmda['target_id']}<br>";
            }
        }
    }

}


function testing()
{
    $query = new EntityFieldQuery();
    $query
        ->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'mda')
        ->propertyCondition('status', 1);
    $rResult = $query->execute();
    $nids = array_keys($rResult['node']);
    foreach ($nids as $nid) {
        print "UG$nid : " . node_load($nid)->title . "<br>";
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

function usersOfRole($role)
{
    $users = array();
    $query = "select uid from users_roles where rid=$role";
    $records = db_query($query);
    foreach ($records as $uid) {
        $users[] = $uid;
    }
    return $users;
}
function getUserEmail($uid){
    return user_load($uid)->email;
}