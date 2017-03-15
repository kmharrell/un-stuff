<?php
/**
 * @file
 * hr_document.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hr_document_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create hr_document content'.
  $permissions['create hr_document content'] = array(
    'name' => 'create hr_document content',
    'roles' => array(
      'Approver' => 'Approver',
      'Editor' => 'Editor',
      'Publisher' => 'Publisher',
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any hr_document content'.
  $permissions['delete any hr_document content'] = array(
    'name' => 'delete any hr_document content',
    'roles' => array(
      'Publisher' => 'Publisher',
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own hr_document content'.
  $permissions['delete own hr_document content'] = array(
    'name' => 'delete own hr_document content',
    'roles' => array(
      'Publisher' => 'Publisher',
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any hr_document content'.
  $permissions['edit any hr_document content'] = array(
    'name' => 'edit any hr_document content',
    'roles' => array(
      'Approver' => 'Approver',
      'Editor' => 'Editor',
      'Publisher' => 'Publisher',
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own hr_document content'.
  $permissions['edit own hr_document content'] = array(
    'name' => 'edit own hr_document content',
    'roles' => array(
      'Approver' => 'Approver',
      'Editor' => 'Editor',
      'Publisher' => 'Publisher',
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  return $permissions;
}
