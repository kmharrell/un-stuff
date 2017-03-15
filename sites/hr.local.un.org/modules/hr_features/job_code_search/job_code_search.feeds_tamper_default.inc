<?php
/**
 * @file
 * job_code_search.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function job_code_search_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'jcs_job_code-xpathparser_5-find_replace';
  $feeds_tamper->importer = 'jcs_job_code';
  $feeds_tamper->source = 'xpathparser:5';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'A',
    'replace' => '1',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['jcs_job_code-xpathparser_5-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'jcs_job_code-xpathparser_5-find_replace1';
  $feeds_tamper->importer = 'jcs_job_code';
  $feeds_tamper->source = 'xpathparser:5';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'I',
    'replace' => '0',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['jcs_job_code-xpathparser_5-find_replace1'] = $feeds_tamper;

  return $export;
}
