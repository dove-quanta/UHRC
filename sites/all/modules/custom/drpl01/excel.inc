<?php

/**
 * PHPExcel
 *
 * Copyright (C) 2006 - 2014 PHPExcel
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * @category   PHPExcel
 * @package    PHPExcel
 * @copyright  Copyright (c) 2006 - 2014 PHPExcel (http://www.codeplex.com/PHPExcel)
 * @license    http://www.gnu.org/licenses/old-licenses/lgpl-2.1.txt	LGPL
 * @version    ##VERSION##, ##DATE##
 */
/** Error reporting */
error_reporting(E_ALL);
ini_set('display_errors', TRUE);
ini_set('display_startup_errors', TRUE);
//date_default_timezone_set('Europe/London');

if (PHP_SAPI == 'cli')
  die('This example should only be run from a Web Browser');

/** Include PHPExcel */
require_once dirname(__FILE__) . '/Classes/PHPExcel.php';

function download_excel() {
// Create new PHPExcel object
  $nodes = explode("|", trim($_GET['qq'], "|"));

  $objPHPExcel = new PHPExcel();

// Set document properties
  $objPHPExcel->getProperties()->setCreator("OHRC")
      ->setLastModifiedBy("OHRC")
      ->setTitle("Office 2007 XLSX Test Document")
      ->setSubject("Office 2007 XLSX Test Document")
      ->setDescription("Test document for Office 2007 XLSX, generated using PHP classes.")
      ->setKeywords("office 2007 openxml php")
      ->setCategory("Test result file");
  $row = 1;
  $objPHPExcel->setActiveSheetIndex(0)
      ->setCellValue('A' . $row, "Recommendation")
      ->setCellValue('B' . $row, "Thematic Area")
      ->setCellValue('C' . $row, "Mechanism")
      ->setCellValue('D' . $row, "Responsible MDA")
      ->setCellValue('E' . $row, "Contributing MDA")
      ->setCellValue('F' . $row, "Indicators")
      ->setCellValue('G' . $row, "Baseline")
      ->setCellValue('H' . $row, "Target")
      ->setCellValue('I' . $row, "Status Of Implementation");
  $colwidth = 30;
  $objPHPExcel->setActiveSheetIndex(0)->getStyle('A1:I1')->getFont()->setBold(true);
  $objPHPExcel->setActiveSheetIndex(0)->getColumnDimension('A')->setWidth($colwidth);
  $objPHPExcel->setActiveSheetIndex(0)->getColumnDimension('B')->setWidth($colwidth);
  $objPHPExcel->setActiveSheetIndex(0)->getColumnDimension('C')->setWidth($colwidth);
  $objPHPExcel->setActiveSheetIndex(0)->getColumnDimension('D')->setWidth($colwidth);
  $objPHPExcel->setActiveSheetIndex(0)->getColumnDimension('E')->setWidth($colwidth);
  $objPHPExcel->setActiveSheetIndex(0)->getColumnDimension('F')->setWidth($colwidth);
  $objPHPExcel->setActiveSheetIndex(0)->getColumnDimension('G')->setWidth($colwidth);
  $objPHPExcel->setActiveSheetIndex(0)->getColumnDimension('H')->setWidth($colwidth);
  $objPHPExcel->setActiveSheetIndex(0)->getColumnDimension('I')->setWidth($colwidth);
  foreach ($nodes as $nid) {
    $row = $row + 1;
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
    $objPHPExcel->setActiveSheetIndex(0)
        ->setCellValue('A' . $row, $recommendation)
        ->setCellValue('B' . $row, $thematic_area)
        ->setCellValue('C' . $row, $mechanism)
        ->setCellValue('D' . $row, $responsible_mda)
        ->setCellValue('E' . $row, $contributing_mda)
        ->setCellValue('F' . $row, $indicators)
        ->setCellValue('G' . $row, $baseline)
        ->setCellValue('H' . $row, $target)
        ->setCellValue('I' . $row, $status_of_implementation);
    $objPHPExcel->setActiveSheetIndex(0)->getRowDimension($row)->setRowHeight(30);
  }
  $styleArray = array(
  'borders' => array(
    'allborders' => array(
      'style' => PHPExcel_Style_Border::BORDER_THIN
    )
  )
);
  $objPHPExcel->setActiveSheetIndex(0)->getStyle('A1:I'.$row)->applyFromArray($styleArray);
  $objPHPExcel->setActiveSheetIndex(0)->getStyle('I1:I' . $objPHPExcel->getActiveSheet()->getHighestRow())->getAlignment()->setWrapText(true);


  $objPHPExcel->getActiveSheet()->setTitle('Recommendations');


// Set active sheet index to the first sheet, so Excel opens this as the first sheet
  $objPHPExcel->setActiveSheetIndex(0);
  $date = new DateTime();
  $filename = 'Recommendations' . $date->format('-Y-m-d-His') . '.xlsx';
// Redirect output to a clientâs web browser (Excel5)
  header('Content-Type: application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');
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
  $objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel2007');
  $objWriter->save('php://output');
  exit;
}
