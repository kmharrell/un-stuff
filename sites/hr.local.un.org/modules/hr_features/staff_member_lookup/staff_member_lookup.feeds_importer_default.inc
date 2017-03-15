<?php
/**
 * @file
 * staff_member_lookup.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function staff_member_lookup_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'staff_member_lookup';
  $feeds_importer->config = array(
    'name' => 'Staff Member Lookup',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Published Date',
            'target' => 'created',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'ASOF Date',
            'target' => 'field_asof_date:start',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'First name',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Last name',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Organizational Unit',
            'target' => 'field_organisational_unit',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Job Code',
            'target' => 'field_job_code',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Job Title',
            'target' => 'field_job_title',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Job Family',
            'target' => 'field_job_family_text',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Job Network',
            'target' => 'field_job_network_text',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Contract Type',
            'target' => 'field_contract_type',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Contract Status',
            'target' => 'field_contract_status',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Level',
            'target' => 'field_level',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Appointment Type',
            'target' => 'field_contract_type',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Appointment Status',
            'target' => 'field_contract_status',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'IMIS Post No.',
            'target' => 'title',
            'unique' => 1,
          ),
          15 => array(
            'source' => 'IMIS Post No.',
            'target' => 'guid',
            'unique' => 1,
          ),
          16 => array(
            'source' => 'email ID',
            'target' => 'field_email_id',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'staff_member_info',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['staff_member_lookup'] = $feeds_importer;

  return $export;
}
