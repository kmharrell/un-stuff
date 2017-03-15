<?php
/**
 * @file
 * job_code_search.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function job_code_search_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_grade'
  $field_bases['field_grade'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_grade',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'ASG' => 'ASG',
        'D1' => 'D1',
        'D2' => 'D2',
        'FS' => 'FS',
        'FS4' => 'FS4',
        'FS5' => 'FS5',
        'FS6' => 'FS6',
        'FS7' => 'FS7',
        'G2' => 'G2',
        'G3' => 'G3',
        'G4' => 'G4',
        'G5' => 'G5',
        'G6' => 'G6',
        'G7' => 'G7',
        'I' => 'I',
        'IA3' => 'IA3',
        'LL' => 'LL',
        'LT' => 'LT',
        'N/A' => 'N/A',
        'NOA' => 'NOA',
        'NOB' => 'NOB',
        'NOC' => 'NOC',
        'NOD' => 'NOD',
        'NPO' => 'NPO',
        'P1' => 'P1',
        'P2' => 'P2',
        'P3' => 'P3',
        'P4' => 'P4',
        'P5' => 'P5',
        'P6' => 'P6',
        'S4' => 'S4',
        'S5' => 'S5',
        'S6' => 'S6',
        'S7' => 'S7',
        'TC2' => 'TC2',
        'TC3' => 'TC3',
        'TC4' => 'TC4',
        'TC5' => 'TC5',
        'TC6' => 'TC6',
        'TC7' => 'TC7',
        'TC8' => 'TC8',
        'USG' => 'USG',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_job_network'
  $field_bases['field_job_network'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_job_network',
    'foreign keys' => array(
      'tid' => array(
        'columns' => array(
          'tid' => 'tid',
        ),
        'table' => 'taxonomy_term_data',
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'job_network',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
