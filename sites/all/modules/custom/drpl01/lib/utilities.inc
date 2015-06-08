<?php
function get_emails_for_mda($nid)
{
    $query = "select entity_id from field_data_field_mda where bundle='user' and field_mda_target_id=$nid";
    $records = db_query($query);
    $emails = "";
    foreach ($records as $record) {
        $user = user_load($record->entity_id);
        $emails .= $user->mail.",";
    }
    return $emails;
}

?>