<?php
/**
 * @file
 * job_code_search_deprecated.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function job_code_search_deprecated_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'jcs_job_code_deprecated';
  $feeds_importer->config = array(
    'name' => 'JCS Job Code (Deprecated)',
    'description' => 'Current/Deprecated Job Codes',
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
            'source' => 'GRADE',
            'target' => 'field_grade',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'JOBCODE',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'TITLE',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'JOB FAMILY',
            'target' => 'field_job_network_deprecated',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'JOBCODE',
            'target' => 'field_job_code',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'job_code_deprecated',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['jcs_job_code_deprecated'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'jcs_job_family_deprecated';
  $feeds_importer->config = array(
    'name' => 'JCS Job Family (Deprecated)',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
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
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'JOB FAMILY',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'JOB FAMILY',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'JF DESCRIPTION',
            'target' => 'description',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'JOB NETWORK',
            'target' => 'parent',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'job_network_deprecated',
        'insert_new' => '1',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['jcs_job_family_deprecated'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'jcs_job_network_deprecated';
  $feeds_importer->config = array(
    'name' => 'JCS Job Network (Deprecated)',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
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
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'JOB NETWORK',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'JOB NETWORK',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Description',
            'target' => 'description',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'job_network_deprecated',
        'insert_new' => '1',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['jcs_job_network_deprecated'] = $feeds_importer;

  return $export;
}
