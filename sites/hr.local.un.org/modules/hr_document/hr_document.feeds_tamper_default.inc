<?php
/**
 * @file
 * hr_document.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function hr_document_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'handbook_multilingual-handbook_status-default_value';
  $feeds_tamper->importer = 'handbook_multilingual';
  $feeds_tamper->source = 'handbook_status';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'published',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['handbook_multilingual-handbook_status-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'handbook_multilingual-language-default_value';
  $feeds_tamper->importer = 'handbook_multilingual';
  $feeds_tamper->source = 'language';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'en',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['handbook_multilingual-language-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'handbook_multilingual-publish_date-timetodate';
  $feeds_tamper->importer = 'handbook_multilingual';
  $feeds_tamper->source = 'publish_date';
  $feeds_tamper->plugin_id = 'timetodate';
  $feeds_tamper->settings = array(
    'date_format' => 'd-m-Y H:i',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Unix timestamp to Date';
  $export['handbook_multilingual-publish_date-timetodate'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'handbook_multilingual-publish_status-default_value';
  $feeds_tamper->importer = 'handbook_multilingual';
  $feeds_tamper->source = 'publish_status';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['handbook_multilingual-publish_status-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'handbook_multilingual-title-truncate_text';
  $feeds_tamper->importer = 'handbook_multilingual';
  $feeds_tamper->source = 'title';
  $feeds_tamper->plugin_id = 'truncate_text';
  $feeds_tamper->settings = array(
    'num_char' => '255',
    'ellipses' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Truncate';
  $export['handbook_multilingual-title-truncate_text'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'handbook_multilingual-title_fr-truncate_text';
  $feeds_tamper->importer = 'handbook_multilingual';
  $feeds_tamper->source = 'title_fr';
  $feeds_tamper->plugin_id = 'truncate_text';
  $feeds_tamper->settings = array(
    'num_char' => '255',
    'ellipses' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Truncate';
  $export['handbook_multilingual-title_fr-truncate_text'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'handbook_multilingual-topic_uuid-efq_finder';
  $feeds_tamper->importer = 'handbook_multilingual';
  $feeds_tamper->source = 'topic_uuid';
  $feeds_tamper->plugin_id = 'efq_finder';
  $feeds_tamper->settings = array(
    'update' => 'Update',
    'entity_type' => 'taxonomy_term',
    'bundle' => 'topics',
    'field' => 'uuid',
    'property' => TRUE,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Entity Field Query finder';
  $export['handbook_multilingual-topic_uuid-efq_finder'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'handbook_multilingual-topic_uuid-explode';
  $feeds_tamper->importer = 'handbook_multilingual';
  $feeds_tamper->source = 'topic_uuid';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '||',
    'limit' => '',
    'real_separator' => '||',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['handbook_multilingual-topic_uuid-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'handbook_multilingual_files-year-find_replace';
  $feeds_tamper->importer = 'handbook_multilingual_files';
  $feeds_tamper->source = 'year';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '1996 and Earlier',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['handbook_multilingual_files-year-find_replace'] = $feeds_tamper;

  return $export;
}
