<?php
/**
 * @file
 * staff_member_lookup.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function staff_member_lookup_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'staff_member_lookup-asof_date-rewrite';
  $feeds_tamper->importer = 'staff_member_lookup';
  $feeds_tamper->source = 'ASOF Date';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[published date]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['staff_member_lookup-asof_date-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'staff_member_lookup-asof_date-timetodate';
  $feeds_tamper->importer = 'staff_member_lookup';
  $feeds_tamper->source = 'ASOF Date';
  $feeds_tamper->plugin_id = 'timetodate';
  $feeds_tamper->settings = array(
    'date_format' => 'm/d/Y',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Unix timestamp to Date';
  $export['staff_member_lookup-asof_date-timetodate'] = $feeds_tamper;

  return $export;
}
