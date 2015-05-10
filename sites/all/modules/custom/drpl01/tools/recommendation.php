<?php

$user=user_load('2');
module_load_include('inc', 'node', 'node.pages');
$mda=array("Prime Minister’s Office"=>"79",
"Ministry of Gender, Labour and Social Development"=>"80",
"Ministry of Justice and Constitutional Affairs"=>"81",
"Ministry of Foreign Affairs"=>"82",
"Ministry of Internal Affairs"=>"83",
"Ministry of Defense"=>"84",
"Ministry of Health"=>"85",
"Ministry of Education"=>"86",
"Ministry of Finance"=>"87",
"Ministry of Disaster Preparedness"=>"88",
"Ministry of Trade"=>"89",
"Ministry of Lands"=>"90",
"Ministry of Public Service"=>"91",
"Ministry of Local Government"=>"92",
"Parliament"=>"244",
"All ministries"=>"93",
"Directorate of Public Prosecutions"=>"94",
"Equal Opportunities Commission"=>"95",
"Uganda Human Rights Commission"=>"96",
"Uganda Police Force"=>"97",
"Uganda Prison Services"=>"98",
"Uganda Peoples Defence Forces"=>"99",
"Uganda Law Reform Commission"=>"100",
"Uganda Aids Commission"=>"101",
"Uganda Revenue Authority"=>"102",
"Uganda AIDS Commission	"=>"103",
"Uganda Bureau of Statistics"=>"104",
"Uganda Registration Bureau"=>"105",
"National Medical Stores"=>"106",
"National Drug Authority"=>"107",
"National Council for Higher Education"=>"108",
"National Planning Authority"=>"109",
"National Council for Children"=>"110",
"National Drug Authority"=>"111");
$mechanism=array("Human Rights Committee (CCPR)"=>"3",
"Committee on Economic, Social and Cultural Rights (CESCR)"=>"4",
"Committee on the Elimination of Racial Discrimination (CERD)"=>"5",
"Committee on the Elimination of Discrimination against Women (CEDAW)"=>"6",
"Committee against Torture (CAT)"=>"7",
"Committee on the Rights of the Child (CRC)"=>"8",
"Committee on Migrant Workers (CMW)"=>"9",
"Committee on the Rights of Persons with Disabilities (CRPD)"=>"10",
"Committee on Enforced Disappearances (CED)"=>"11",
"The Subcommittee on Prevention of Torture and other Cruel, Inhuman or Degrading Treatment or Punishment (SPT)"=>"12",
"Special Rapporteurs"=>"13",
"Universal Periodic Review"=>"14",
"African Commission on People and Human Rights"=>"15",
"Special Rapporteurs"=>"16",
"Uganda Human Rights Commission"=>"17");
$thematic_areas=array("Right to Education"=>"23",
"Women’s Rights"=>"24",
"Labour Rights"=>"25",
"Right to Development"=>"26",
"Rights of IDPs and Refugees"=>"27",
"Right to the Highest Attainable Standard of Health"=>"28",
"Right against Torture, Cruel and Inhuman Treatment"=>"29",
"Civil and Political Rights"=>"30",
"Conditions of Prisoner’s"=>"31",
"Respect and Strengthening of Rights Institutions"=>"32",
"Access to Justice"=>"33",
"Right to fair hearing"=>"34",
"Unlawful Detention"=>"35",
"Right to Remedy"=>"36",
"Right to Culture"=>"37",
"Children’s Rights"=>"38",
"Right to Life"=>"39",
"Right to participate in political life"=>"40",
"Right to Body Integrity"=>"41",
"Non Discrimination"=>"42",
"Rights in relation to Family"=>"43",
"Adequate Housing"=>"44",
"Rights of Persons with Disabilities"=>"45",
"Freedom of Religion"=>"46",
"Juvenile Justice"=>"47",
"Prisoner’s conditions"=>"48",
"Conditions of Detention"=>"49",
"Indigenous Peoples’ Rights"=>"50",
"Right to access to Information"=>"51",
"Human Rights Education and awareness"=>"52",
"Rights of IDPs and Refugees"=>"53",
"Freedom of expression"=>"54",
"Freedom of Movement"=>"55",
"Freedom of Assembly"=>"56",
"Right to liberty and security of persons"=>"57",
"Older Persons’ Rights"=>"58",
"Peace and Security"=>"59",
"Independence of Institutions"=>"60",
"Minority Rights"=>"61",
"All rights"=>"62",
"Public Freedoms"=>"63",
"Freedom of Speech"=>"64",
"Freedom of Movement"=>"65",
"Right to bail"=>"66",
"Independence of National Human Rights Institutions"=>"67",
"Right to Participation"=>"68",
"Right to Compensation"=>"69",
"Right to Vote"=>"70",
"Public Freedoms"=>"71",
"Freedom of Assembly"=>"72",
"Freedom of Speech"=>"73",
"NAP"=>"74",
"Security of the person"=>"75",
"LGBT Rights"=>"76",
"Minority rights"=>"77",
"Right to Food"=>"78",
"Right to the Highest Attainable Standard of Health"=>"423",
"Economic, Social and Cultural Rights"=>"422");
function addnode($line,$mda,$thm,$mechanism){
	$line= str_replace ( "\n" , "" , $line );
	$data=explode ( "|" , $line , 20);
	$node = (object) array(
	  'uid' => $user->uid,
	  'name' => $user->name,
	  'type' => 'recommendation',
	  'language' => 'und',
	);
	node_object_prepare($node);

	$fields = field_info_instances('node');
	$form_state = array();
	foreach($fields['recommendation'] as $field_name => $values) {
	  $form_state['values'][$field_name] = array('und' => array());
	}
	$form_state['values']['title']="_blank";
$form_state['values']['field_recommendation']['und'][0][value]=$data[0];

	if(isset($thm[$data[1]])){
	$form_state['values']['field_thematic_area']['und'][0]=$thm[$data[1]];
}
	if(isset($mechanism[$data[2]])){
	$form_state['values']['field_mechanism']['und'][0]=$mechanism[$data[2]];
}
	if(isset($mda[$data[3]])){
	$form_state['values']['field_responsible_mda']['und'][0]=$mda[$data[3]];
}
	if(isset($mda[$data[4]])){
	$form_state['values']['field_contributing_mda']['und'][0]=$mda[$data[4]];
}
	$form_state['values']['field_indicators']['und'][0][value]=$data[5];
	$form_state['values']['field_baseline']['und'][0][value]=$data[6];
	$form_state['values']['field_target']['und'][0][value]=$data[7];
#	$form_state['values']['field_means_of_verification']['und'][0][value]=$data[8];
	$form_state['values']['field_status_of_implementation']['und'][0][value]=$data[9];
	$form_state['values']['field_year']['und'][0][value][date]=$data[10];
	$form_state['values']['field_next_state_deadline']['und'][0][value][date]=$data[11];
	$form_state['values']['op']=t('Save');
	drupal_form_submit('recommendation_node_form',$form_state, $node);

}
$filename="sites/all/modules/custom/drpl01/tools/uhrc.txt.csv";
$filearray = file($filename);
$i=0;
foreach($filearray as $line){	
	addnode($line,$mda,$thematic_areas,$mechanism);
}

