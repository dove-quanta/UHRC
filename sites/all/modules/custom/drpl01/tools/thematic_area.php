<?php
global $user;
module_load_include('inc', 'node', 'node.pages');
function addnode($line){
	$line= str_replace ( "\n" , "" , $line );
	$data=explode ( "|" , $line , 15);
	$node = (object) array(
	  'uid' => $user->uid,
	  'name' => $user->name,
	  'type' => 'thematic_area',
	  'language' => 'und',
	);
	node_object_prepare($node);

	$fields = field_info_instances('node');
	$form_state = array();
	foreach($fields['menu'] as $field_name => $values) {
	  $form_state['values'][$field_name] = array('und' => array());
	}	
	$form_state['values']['title']=$data[0];

	$form_state['values']['op']=t('Save');
	drupal_form_submit('thematic_area_node_form',$form_state, $node);
}
$filename="sites/all/modules/custom/drpl01/thematic_area.txt";
$filearray = file($filename);
$i=-1;
foreach($filearray as $line){
	$i=$i+1;
	if($i==0) {
		continue;
	}
	
	addnode($line);
}


