<?php
/**
 * @file
 * hr_document.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hr_document_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "file_entity" && $api == "file_type") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hr_document_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hr_document_node_info() {
  $items = array(
    'hr_document' => array(
      'name' => t('HR Handbook Document'),
      'base' => 'node_content',
      'description' => t('An HR Portal Handbook Document '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
