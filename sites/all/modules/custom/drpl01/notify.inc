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

function fetch_pending_notifications()
{
    $query = new EntityFieldQuery();
    $query
        ->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'notification')
        ->propertyCondition('status', 1)
        ->fieldCondition('field_status', 'value', "Pending", '=');
    $rResult = $query->execute();
    $nids = array_keys($rResult['node']);
    return $nids;
}
# send emails to each pending notification
function send_notifications()
{
    global $base_url;
    #insert recommendation ids
    insert_rid();
    #fetch pending notifications
    $pending = fetch_pending_notifications();
    foreach ($pending as $nid) {
        $node = node_load($nid);
        if($node->field_event_type['und'][0]['value']!='Add'){
            continue;
        }
        $url = $base_url . "/" . "node/" . $node->field_rid['und'][0]['target_id'] . "";
        $rmda = node_load($node->field_rmda['und'][0]['target_id'])->title;
        $author = node_load($node->field_rid['und'][0]['target_id'])->uid;
        $params = array();
        $params['author'] = user_load($author)->name;
        $params['rmda'] = $rmda;
        $params['url'] = $url;
        print "$nid<br>";
        # process emails for admin role
        $rid = 5;
        $admins = usersOfRole($rid);
        foreach ($admins as $admin) {
            $email = getUserEmail($admin);
            $email = 'jkyeyune@hostalite.com';
            $sent = drupal_mail('drpl01', 'admin-add', $email, language_default(), $params, 'info@uhrcdatabase.org', TRUE);
            if ($sent) {
                print "Successful $admin<br>";
            }
        }

        # process email for responsible MDA
        $emails = get_emails_for_mda($nid);
        foreach ($emails as $email) {
            $email = 'jkyeyune@hostalite.com';
            $sent = drupal_mail('drpl01', 'rmda-add', $email, language_default(), $params, 'info@uhrcdatabase.org', TRUE);
            if ($sent) {
                print "Successful $nid<br>";
            }
        }

        # process emails for contributing MDA
        foreach ($node->field_cmda['und'] as $cmda) {
            $emails = get_emails_for_mda($cmda['target_id']);
            foreach ($emails as $email) {
                print $email."<br>";
                $email = 'jkyeyune@hostalite.com';
                $params['cmda'] = $cmda;
                $sent = drupal_mail('drpl01', 'cmda-add', $email, language_default(), $params, 'info@uhrcdatabase.org', TRUE);
                if ($sent) {
                    print "Successful {$cmda['target_id']}<br>";
                }
            }
        }
        #update notification status
        $node->field_status['und'][0]['value']='Sent';
        node_save($node);
    }
    foreach ($pending as $nid) {
        $node = node_load($nid);
        if($node->field_event_type['und'][0]['value']!='Update'){
            continue;
        }
        $url = $base_url . "/" . "node/" . $node->field_rid['und'][0]['target_id'] . "";
        $rmda = node_load($node->field_rmda['und'][0]['target_id'])->title;
        $author = node_load($node->field_rid['und'][0]['target_id'])->uid;
        $params = array();
        $params['author'] = user_load($author)->name;
        $params['rmda'] = $rmda;
        $params['url'] = $url;
        print "$nid<br>";
        # process emails for admin role
        $rid = 5;
        $admins = usersOfRole($rid);
        foreach ($admins as $admin) {
            $email = getUserEmail($admin);
            $email = 'jkyeyune@hostalite.com';
            $sent = drupal_mail('drpl01', 'admin-update', $email, language_default(), $params, 'info@uhrcdatabase.org', TRUE);
            if ($sent) {
                print "Successful $admin<br>";
            }
        }

        # process email for responsible MDA
        $emails = get_emails_for_mda($nid);
        foreach ($emails as $email) {
            $email = 'jkyeyune@hostalite.com';
            $sent = drupal_mail('drpl01', 'rmda-update', $email, language_default(), $params, 'info@uhrcdatabase.org', TRUE);
            if ($sent) {
                print "Successful $nid<br>";
            }
        }

        # process emails for contributing MDA
        foreach ($node->field_cmda['und'] as $cmda) {
            $emails = get_emails_for_mda($cmda['target_id']);
            foreach ($emails as $email) {
                print $email."<br>";
                $email = 'jkyeyune@hostalite.com';
                $params['cmda'] = $cmda;
                $sent = drupal_mail('drpl01', 'cmda-update', $email, language_default(), $params, 'info@uhrcdatabase.org', TRUE);
                if ($sent) {
                    print "Successful {$cmda['target_id']}<br>";
                }
            }
        }
        #update notification status
        $node->field_status['und'][0]['value']='Sent';
        node_save($node);
    }


}

function usersOfRole($role)
{
    $users = array();
    $query = "select uid from users_roles where rid=$role";
    $records = db_query($query);
    foreach ($records as $record) {
        $users[] = $record->uid;
    }
    return $users;
}

function getUserEmail($uid)
{
    return user_load($uid)->mail;
}