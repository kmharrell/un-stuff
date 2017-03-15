<?php
/**
 * @file
 * staff_member_lookup.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function staff_member_lookup_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['hr_jcs-hr_jcs_staff_lookup_form'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'hr_jcs_staff_lookup_form',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hr_jcs',
    'node_types' => array(),
    'pages' => 'user/*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'hr_portal' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hr_portal',
        'weight' => -29,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
