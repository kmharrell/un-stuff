<?php
/**
 * @file
 * Features integration for Subfolders Domain.
 */

/**
 * @return array
 *   A keyed array of items, suitable for use with a FormAPI select or
 *   checkboxes element.
 */
function subfolders_domain_features_export_options() {
  $profiles = array();
  $list_subfolders = db_query("SELECT * FROM {subfolders_domain} d")->fetchAll();
  if (count($list_subfolders)) {
    foreach ($list_subfolders as $subfolder) {
      $domain_parent = domain_load($subfolder->parent_id);
      $profiles[$subfolder->site] = $subfolder->site . ' (parent site: ' . $domain_parent['sitename'] . ')';
    }
  }

  return $profiles;
}

/**
 * @param array $data
 *   this is the machine name for the component in question
 * @param array &$export
 *   array of all components to be exported
 * @param string $module_name
 *   The name of the feature module to be generated.
 * @return array
 *   The pipe array of further processors that should be called
 */
function subfolders_domain_features_export($data, &$export, $module_name = '') {
  $export['dependencies']['features'] = 'features';
  $export['dependencies']['subfolders_domain'] = 'subfolders_domain';
  $list_subfolders = db_query("SELECT * FROM {subfolders_domain} d")->fetchAll();
  if ($list_subfolders) {
    foreach ($list_subfolders as $subfolder) {
      if (in_array($subfolder->site, $data)) {
        $export['features']['subfolders_domain'][$subfolder->site] = $subfolder->site;
      }
    }
  }

  return array();
}

/**
 * Render one or more component objects to code.
 *
 * @param string $module_name
 *   The name of the feature module to be exported.
 * @param array $data
 *   An array of machine name identifiers for the objects to be rendered.
 * @param array $export
 *   The full export array of the current feature being exported. This is only
 *   passed when hook_features_export_render() is invoked for an actual feature
 *   update or recreate, not during state checks or other operations.
 * @return array
 *   An associative array of rendered PHP code where the key is the name of the
 *   hook that should wrap the PHP code. The hook should not include the name
 *   of the module, e.g. the key for `hook_example` should simply be `example`.
 */
function subfolders_domain_features_export_render($module, $data) {
  $code = array();
  foreach ($data as $name) {
    $subfolder = db_query("SELECT * FROM {subfolders_domain} d WHERE site = :site", array(':site' => $name))->fetchObject();
    if ($subfolder) {
      // Load domain by domain_id.
      $domain = domain_load($subfolder->domain_id);
      $subfolder->domain = $domain['machine_name']; // Revert domain_id to machine name of domain.
      // Load domain parent.
      $parent_domain = domain_load($subfolder->parent_id);
      $subfolder->parent = $parent_domain['machine_name'];
      unset($subfolder->domain_id, $subfolder->parent_id);
      $code[$subfolder->site] = $subfolder;
    }
  }
  $code = "  return " . features_var_export($code, '  ') . ";";
  return array('subfolders_domain_features_default_domain' => $code);
}

/**
 * Implements hook_features_revert().
 */
function subfolders_domain_features_revert($module) {
  subfolders_domain_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 *
 * Rebuilds subfolders domain from code defaults.
 */
function subfolders_domain_features_rebuild($module) {
  $settings = module_invoke($module, 'subfolders_domain_features_default_domain');
  if ($settings) {
    db_truncate('subfolders_domain')->execute();
    foreach ($settings as $setting) {
      $domain_id = db_query('SELECT domain_id FROM {domain} WHERE machine_name = :machine_name', array(':machine_name' => $setting['domain']))->fetchField();
      $parent_id = db_query('SELECT domain_id FROM {domain} WHERE machine_name = :machine_name', array(':machine_name' => $setting['parent']))->fetchField();
      $data = array(
        'site' => $setting['site'],
        'other_domain' => '',
        'language' => '',
        'domain_id' => $domain_id,
        'parent_id' => $parent_id,
        'inherit_parent_roles' => ($setting['inherit_parent_roles']) ? $setting['inherit_parent_roles'] : 0,
        'changed' => $setting['changed'],
      );
      db_insert('subfolders_domain')->fields($data)->execute();
    }
  }
}
