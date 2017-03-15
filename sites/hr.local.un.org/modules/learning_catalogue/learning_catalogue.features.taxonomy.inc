<?php
/**
 * @file
 * learning_catalogue.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function learning_catalogue_taxonomy_default_vocabularies() {
  return array(
    'learning_catalogue_category' => array(
      'name' => 'Learning Catalogue  Category',
      'machine_name' => 'learning_catalogue_category',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
    'learning_catalogue_topics' => array(
      'name' => 'Learning Catalogue Topics',
      'machine_name' => 'learning_catalogue_topics',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'learning_catalogue_type' => array(
      'name' => 'Learning Catalogue Type',
      'machine_name' => 'learning_catalogue_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
