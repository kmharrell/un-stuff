<?php
/**
 * @file
 * learning_catalogue.features.inc
 */

/**
 * Implements hook_node_info().
 */
function learning_catalogue_node_info() {
  $items = array(
    'learning_catalogue' => array(
      'name' => t('Learning Catalogue'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
