<?php
/**
 * @file
 * staff_member_lookup.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function staff_member_lookup_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_node_info().
 */
function staff_member_lookup_node_info() {
  $items = array(
    'staff_member_info' => array(
      'name' => t('Staff Member Info'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Index Number'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
