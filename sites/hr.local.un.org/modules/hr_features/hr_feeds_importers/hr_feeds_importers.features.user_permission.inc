<?php
/**
 * @file
 * hr_feeds_importers.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hr_feeds_importers_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'tamper handbook_multilingual'.
  $permissions['tamper handbook_multilingual'] = array(
    'name' => 'tamper handbook_multilingual',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  return $permissions;
}
