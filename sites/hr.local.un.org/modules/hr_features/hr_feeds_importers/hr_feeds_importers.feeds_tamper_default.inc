<?php
/**
 * @file
 * hr_feeds_importers.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function hr_feeds_importers_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'faqs-status-default_value';
  $feeds_tamper->importer = 'faqs';
  $feeds_tamper->source = 'status';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['faqs-status-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_doc-published-default_value';
  $feeds_tamper->importer = 'hr_doc';
  $feeds_tamper->source = 'published';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['hr_doc-published-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_doc-taxonomy-explode';
  $feeds_tamper->importer = 'hr_doc';
  $feeds_tamper->source = 'taxonomy';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ', ',
    'limit' => '',
    'real_separator' => ', ',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['hr_doc-taxonomy-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_docfiles-path-convert_case';
  $feeds_tamper->importer = 'hr_docfiles';
  $feeds_tamper->source = 'path';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 6;
  $feeds_tamper->description = 'Convert case';
  $export['hr_docfiles-path-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_docfiles-path-find_replace';
  $feeds_tamper->importer = 'hr_docfiles';
  $feeds_tamper->source = 'path';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => ' ',
    'replace' => '_',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'space to underscore';
  $export['hr_docfiles-path-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_docfiles-path-find_replace_devlsource';
  $feeds_tamper->importer = 'hr_docfiles';
  $feeds_tamper->source = 'path';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'DEVLSOURCE_DOCUMENTS',
    'replace' => 'DEVL/SOURCE_DOCUMENTS',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 5;
  $feeds_tamper->description = 'Find replace DEVLSOURCE';
  $export['hr_docfiles-path-find_replace_devlsource'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_docfiles-path-find_replace_domain';
  $feeds_tamper->importer = 'hr_docfiles';
  $feeds_tamper->source = 'path';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/',
    'replace' => 'http://dev-hr-protal.gotpantheon.com/',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Find replace';
  $export['hr_docfiles-path-find_replace_domain'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_docfiles-path-find_replace_percent20';
  $feeds_tamper->importer = 'hr_docfiles';
  $feeds_tamper->source = 'path';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '%20',
    'replace' => '_',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = '%20 to underscore';
  $export['hr_docfiles-path-find_replace_percent20'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_docfiles-path-find_replace_to_public';
  $feeds_tamper->importer = 'hr_docfiles';
  $feeds_tamper->source = 'path';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'http://hr-portal/sites/hr.un.org/files/',
    'replace' => 'public://',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 7;
  $feeds_tamper->description = 'Find replace to public://';
  $export['hr_docfiles-path-find_replace_to_public'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_handbook-cat_topic_subtop-explode';
  $feeds_tamper->importer = 'hr_handbook';
  $feeds_tamper->source = 'cat_topic_subtop';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '||',
    'limit' => '',
    'real_separator' => '||',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['hr_handbook-cat_topic_subtop-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_handbook-lang-default_value';
  $feeds_tamper->importer = 'hr_handbook';
  $feeds_tamper->source = 'lang';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'en',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['hr_handbook-lang-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_handbook-path-convert_case';
  $feeds_tamper->importer = 'hr_handbook';
  $feeds_tamper->source = 'path';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Convert case';
  $export['hr_handbook-path-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_handbook-path-devlsource';
  $feeds_tamper->importer = 'hr_handbook';
  $feeds_tamper->source = 'path';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'DEVLSOURCE_DOCUMENTS',
    'replace' => 'DEVL/SOURCE_DOCUMENTS',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Find replace DEVLSOURCE';
  $export['hr_handbook-path-devlsource'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_handbook-path-find_replace';
  $feeds_tamper->importer = 'hr_handbook';
  $feeds_tamper->source = 'path';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/',
    'replace' => 'http://dev-hr-protal.gotpantheon.com/',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['hr_handbook-path-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_handbook-path-pct20er';
  $feeds_tamper->importer = 'hr_handbook';
  $feeds_tamper->source = 'path';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '%20',
    'replace' => '_',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = '%20er';
  $export['hr_handbook-path-pct20er'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_handbook-path-underscore_space';
  $feeds_tamper->importer = 'hr_handbook';
  $feeds_tamper->source = 'path';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => ' ',
    'replace' => '_',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'space_to_underscore';
  $export['hr_handbook-path-underscore_space'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_handbook-published-default_value';
  $feeds_tamper->importer = 'hr_handbook';
  $feeds_tamper->source = 'published';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['hr_handbook-published-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hr_handbook-taxonomy-explode';
  $feeds_tamper->importer = 'hr_handbook';
  $feeds_tamper->source = 'taxonomy';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ', ',
    'limit' => '',
    'real_separator' => ', ',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['hr_handbook-taxonomy-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material-custom_text-find_replace';
  $feeds_tamper->importer = 'ref_material';
  $feeds_tamper->source = 'Custom text';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/',
    'replace' => 'https://hr.un.org/',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Dev to prod';
  $export['ref_material-custom_text-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files-file-find_replace_devtoprod';
  $feeds_tamper->importer = 'ref_material_doc_files';
  $feeds_tamper->source = 'file';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/',
    'replace' => 'https://hr.un.org/',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Dev to prod';
  $export['ref_material_doc_files-file-find_replace_devtoprod'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files-filename-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/sites/hr.un.org/files/file/refmaterials/documents/',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'remove beginning of string';
  $export['ref_material_doc_files-filename-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files-filename-urldecode';
  $feeds_tamper->importer = 'ref_material_doc_files';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'urldecode';
  $feeds_tamper->settings = array(
    'method' => 'raw',
    'function' => 'rawurldecode',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'URL Decode';
  $export['ref_material_doc_files-filename-urldecode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_audio-file-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_audio';
  $feeds_tamper->source = 'file';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/',
    'replace' => 'https://hr.un.org/',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Dev to prod';
  $export['ref_material_doc_files_audio-file-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_audio-filename-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_audio';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/sites/hr.un.org/files/file/refmaterials/documents/',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['ref_material_doc_files_audio-filename-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_audio-filename-find_replace2';
  $feeds_tamper->importer = 'ref_material_doc_files_audio';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/sites/hr.un.org/files/',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['ref_material_doc_files_audio-filename-find_replace2'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_audio-filename-urldecode';
  $feeds_tamper->importer = 'ref_material_doc_files_audio';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'urldecode';
  $feeds_tamper->settings = array(
    'method' => 'raw',
    'function' => 'rawurldecode',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'URL Decode';
  $export['ref_material_doc_files_audio-filename-urldecode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_form-file-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_form';
  $feeds_tamper->source = 'file';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/',
    'replace' => 'https://hr.un.org/',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Dev to prod';
  $export['ref_material_doc_files_form-file-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_form-filename-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_form';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/sites/hr.un.org/files/file/refmaterials/documents/',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['ref_material_doc_files_form-filename-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_form-filename-urldecode';
  $feeds_tamper->importer = 'ref_material_doc_files_form';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'urldecode';
  $feeds_tamper->settings = array(
    'method' => 'raw',
    'function' => 'rawurldecode',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'URL Decode';
  $export['ref_material_doc_files_form-filename-urldecode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_guide-file-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_guide';
  $feeds_tamper->source = 'file';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/',
    'replace' => 'https://hr.un.org/',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Dev to prod';
  $export['ref_material_doc_files_guide-file-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_guide-filename-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_guide';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/sites/hr.un.org/files/file/refmaterials/documents/',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['ref_material_doc_files_guide-filename-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_guide-filename-urldecode';
  $feeds_tamper->importer = 'ref_material_doc_files_guide';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'urldecode';
  $feeds_tamper->settings = array(
    'method' => 'raw',
    'function' => 'rawurldecode',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'URL Decode';
  $export['ref_material_doc_files_guide-filename-urldecode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_handbook-file-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_handbook';
  $feeds_tamper->source = 'file';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/',
    'replace' => 'https://hr.un.org/',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Dev to prod';
  $export['ref_material_doc_files_handbook-file-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_handbook-filename-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_handbook';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/sites/hr.un.org/files/file/refmaterials/documents/',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['ref_material_doc_files_handbook-filename-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_handbook-filename-urldecode';
  $feeds_tamper->importer = 'ref_material_doc_files_handbook';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'urldecode';
  $feeds_tamper->settings = array(
    'method' => 'raw',
    'function' => 'rawurldecode',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'URL Decode';
  $export['ref_material_doc_files_handbook-filename-urldecode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_list-file-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_list';
  $feeds_tamper->source = 'file';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/',
    'replace' => 'https://hr.un.org/',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Dev to prod';
  $export['ref_material_doc_files_list-file-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_list-filename-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_list';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/sites/hr.un.org/files/file/refmaterials/documents/',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['ref_material_doc_files_list-filename-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_list-filename-urldecode';
  $feeds_tamper->importer = 'ref_material_doc_files_list';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'urldecode';
  $feeds_tamper->settings = array(
    'method' => 'raw',
    'function' => 'rawurldecode',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'URL Decode';
  $export['ref_material_doc_files_list-filename-urldecode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_manual-file-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_manual';
  $feeds_tamper->source = 'file';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/',
    'replace' => 'https://hr.un.org/',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Dev to prod';
  $export['ref_material_doc_files_manual-file-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_manual-filename-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_manual';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/sites/hr.un.org/files/file/refmaterials/documents/',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['ref_material_doc_files_manual-filename-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_manual-filename-urldecode';
  $feeds_tamper->importer = 'ref_material_doc_files_manual';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'urldecode';
  $feeds_tamper->settings = array(
    'method' => 'raw',
    'function' => 'rawurldecode',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'URL Decode';
  $export['ref_material_doc_files_manual-filename-urldecode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_policy-file-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_policy';
  $feeds_tamper->source = 'file';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/',
    'replace' => 'https://hr.un.org/',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Dev to prod';
  $export['ref_material_doc_files_policy-file-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_policy-filename-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_policy';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/sites/hr.un.org/files/file/refmaterials/documents/',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['ref_material_doc_files_policy-filename-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_policy-filename-urldecode';
  $feeds_tamper->importer = 'ref_material_doc_files_policy';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'urldecode';
  $feeds_tamper->settings = array(
    'method' => 'raw',
    'function' => 'rawurldecode',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'URL Decode';
  $export['ref_material_doc_files_policy-filename-urldecode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_quick_guides-file-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_quick_guides';
  $feeds_tamper->source = 'file';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/',
    'replace' => 'https://hr.un.org/',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Dev to prod';
  $export['ref_material_doc_files_quick_guides-file-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_quick_guides-filename-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_quick_guides';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/sites/hr.un.org/files/file/refmaterials/documents/',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['ref_material_doc_files_quick_guides-filename-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_quick_guides-filename-urldecode';
  $feeds_tamper->importer = 'ref_material_doc_files_quick_guides';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'urldecode';
  $feeds_tamper->settings = array(
    'method' => 'raw',
    'function' => 'rawurldecode',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'URL Decode';
  $export['ref_material_doc_files_quick_guides-filename-urldecode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_video-file-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_video';
  $feeds_tamper->source = 'file';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/',
    'replace' => 'https://hr.un.org/',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Dev to prod';
  $export['ref_material_doc_files_video-file-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_video-filename-find_replace';
  $feeds_tamper->importer = 'ref_material_doc_files_video';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://hrdev.un.org/sites/hr.un.org/files/file/refmaterials/documents/',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['ref_material_doc_files_video-filename-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ref_material_doc_files_video-filename-urldecode';
  $feeds_tamper->importer = 'ref_material_doc_files_video';
  $feeds_tamper->source = 'filename';
  $feeds_tamper->plugin_id = 'urldecode';
  $feeds_tamper->settings = array(
    'method' => 'raw',
    'function' => 'rawurldecode',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'URL Decode';
  $export['ref_material_doc_files_video-filename-urldecode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'subject_matter_area-published-default_value';
  $feeds_tamper->importer = 'subject_matter_area';
  $feeds_tamper->source = 'published';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['subject_matter_area-published-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'users-roles-role_map';
  $feeds_tamper->importer = 'users';
  $feeds_tamper->source = 'roles';
  $feeds_tamper->plugin_id = 'role_map';
  $feeds_tamper->settings = array(
    'role_map_2' => 'authenticated user',
    'role_map_3' => 'administrator',
    'role_map_4' => 'webmaster',
    'role_map_5' => 'editor_dr',
    'role_map_6' => 'approver_dr',
    'role_map_7' => 'publisher_dr',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Drupal roles';
  $export['users-roles-role_map'] = $feeds_tamper;

  return $export;
}
