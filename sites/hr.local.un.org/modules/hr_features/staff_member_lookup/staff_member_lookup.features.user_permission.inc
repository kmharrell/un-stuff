<?php
/**
 * @file
 * staff_member_lookup.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function staff_member_lookup_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create staff_member_info content'.
  $permissions['create staff_member_info content'] = array(
    'name' => 'create staff_member_info content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any staff_member_info content'.
  $permissions['delete any staff_member_info content'] = array(
    'name' => 'delete any staff_member_info content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own staff_member_info content'.
  $permissions['delete own staff_member_info content'] = array(
    'name' => 'delete own staff_member_info content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any staff_member_info content'.
  $permissions['edit any staff_member_info content'] = array(
    'name' => 'edit any staff_member_info content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own staff_member_info content'.
  $permissions['edit own staff_member_info content'] = array(
    'name' => 'edit own staff_member_info content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
