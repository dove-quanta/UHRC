<?php

/** Error reporting */
error_reporting(E_ALL);
ini_set('display_errors', TRUE);
ini_set('display_startup_errors', TRUE);
//date_default_timezone_set('Europe/London');

if (PHP_SAPI == 'cli')
  die('This example should only be run from a Web Browser');

/** Include PHPExcel */
require_once dirname(__FILE__) . '/Classes/PhpWord/Autoloader.php';
\PhpOffice\PhpWord\Autoloader::register();

function download_word() {

  $nodes = explode("|", trim($_GET['qq'], "|"));
  $phpWord = new \PhpOffice\PhpWord\PhpWord();

// Every element you want to append to the word document is placed in a section.
// To create a basic section:


  $section = $phpWord->addSection();
  foreach ($nodes as $nid) {

    $node = node_load($nid);
    $recommendation = empty($node->field_recommendation) ? "" : $node->field_recommendation['und'][0]['value'];
    $thematic_area = empty($node->field_thematic_area) ? "" : node_load($node->field_thematic_area['und'][0]['target_id'])->title;
    $mechanism = empty($node->field_mechanism) ? "" : node_load($node->field_mechanism['und'][0]['target_id'])->title;
    $responsible_mda = empty($node->field_responsible_mda) ? "" : node_load($node->field_responsible_mda['und'][0]['target_id'])->title;
    $contributing_mda = empty($node->field_contributing_mda) ? "" : node_load($node->field_contributing_mda['und'][0]['target_id'])->title;
    $indicators = empty($node->field_indicators) ? "" : $node->field_indicators['und'][0]['value'];
    $baseline = empty($node->field_baseline) ? "" : $node->field_baseline['und'][0]['value'];
    $target = empty($node->field_target) ? "" : $node->field_target['und'][0]['value'];
    $status_of_implementation = empty($node->field_status_of_implementation) ? "" : $node->field_status_of_implementation['und'][0]['value'];
// After creating a section, you can append elements:
    $section->addText('Recommendation: ' . $recommendation);
    $section->addText('Thematic Area: ' . $thematic_area);
    $section->addText('Mechanisms: ' . $mechanism);
    $section->addText('Responsible MDA: ' . $responsible_mda);
    $section->addText('Contributing MDA: ' . $contributing_mda);
    $section->addText('Indicators: ' . $indicators);
    $section->addText('Baseline: ' . $baseline);
    $section->addText('Target: ' . $target);
    $section->addText('Status of Implementation' . $status_of_implementation);
    $section->addText('---------------------------------------------------------------');
  }



  $date = new DateTime();
  $filename = 'Recommendations' . $date->format('-Y-m-d-His') . '.docx';
// Redirect output to a client's web browser (Excel5)
  header('Content-Type: application/vnd.openxmlformats-officedocument.wordprocessingml.document');
  header('Content-Disposition: attachment;filename="' . $filename . '"');
  header('Cache-Control: max-age=0');
// If you're serving to IE 9, then the following may be needed
  header('Cache-Control: max-age=1');

// If you're serving to IE over SSL, then the following may be needed
  header('Expires: Mon, 26 Jul 1997 05:00:00 GMT'); // Date in the past
  header('Last-Modified: ' . gmdate('D, d M Y H:i:s') . ' GMT'); // always modified
  header('Cache-Control: cache, must-revalidate'); // HTTP/1.1
  header('Pragma: public'); // HTTP/1.0
//$objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel5');  
  $objWriter = \PhpOffice\PhpWord\IOFactory::createWriter($phpWord, 'Word2007');
  $objWriter->save('php://output');
  exit;
}
