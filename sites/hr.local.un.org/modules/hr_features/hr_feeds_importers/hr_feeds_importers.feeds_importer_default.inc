<?php
/**
 * @file
 * hr_feeds_importers.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hr_feeds_importers_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'articles';
  $feeds_importer->config = array(
    'name' => 'Articles',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
            'source' => 'uuid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'title_en',
            'target' => 'title_field:et:en',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'title_fr',
            'target' => 'title_field:et:fr',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'date',
            'target' => 'field_article_date:start',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'news_type',
            'target' => 'field_article_type',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'duty_station',
            'target' => 'field_duty_station',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'body_en',
            'target' => 'body:et:en',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'body_fr',
            'target' => 'body:et:fr',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'image',
            'target' => 'field_image:uri',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'keywords',
            'target' => 'field_keywords',
            'term_search' => '2',
            'autocreate' => 0,
          ),
          12 => array(
            'source' => 'newsletter_category',
            'target' => 'field_simplenews_term',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'group_uuid',
            'target' => 'og_group_ref',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'lang',
            'target' => 'language',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'article',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['articles'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'faqs';
  $feeds_importer->config = array(
    'name' => 'FAQs',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
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
            'source' => 'uuid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'body_en',
            'target' => 'body:et:en',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'body_fr',
            'target' => 'body:et:fr',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'keywords',
            'target' => 'field_keywords',
            'term_search' => '2',
            'autocreate' => 0,
          ),
          6 => array(
            'source' => 'newsletter_category',
            'target' => 'field_simplenews_term',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'group_uuid',
            'target' => 'og_group_ref',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'lang',
            'target' => 'language',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'title_en',
            'target' => 'title_field:et:en',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'title_fr',
            'target' => 'title_field:et:fr',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'status',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'faqs',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['faqs'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'fc_related_links';
  $feeds_importer->config = array(
    'name' => 'FC Related Links',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
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
      'plugin_key' => 'FeedsFieldCollectionProcessor',
      'config' => array(
        'field_name' => 'field_page_related_links',
        'host_entity_type' => 'node',
        'is_field' => 1,
        'guid_field_name' => '',
        'identifier_field_name' => '',
        'mappings' => array(),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'field_page_related_links',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['fc_related_links'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_doc';
  $feeds_importer->config = array(
    'name' => 'HR Doc',
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
            'source' => 'uuid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'path',
            'target' => 'field_document_file:MediaFeedsGUIDProvider',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'group_uuid',
            'target' => 'og_group_ref',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'newsletter_category',
            'target' => 'field_simplenews_term',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'taxonomy',
            'target' => 'field_hrdoc_topic',
            'term_search' => '2',
            'autocreate' => 0,
          ),
          5 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'published',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'hr_document',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['hr_doc'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_docfiles';
  $feeds_importer->config = array(
    'name' => 'HR Docfile',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
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
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'handbook_doc',
        'author' => '1',
        'authorize' => 0,
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'doctype',
            'target' => 'field_hrdoc_doctype',
            'term_search' => '0',
            'autocreate' => 0,
          ),
          1 => array(
            'source' => 'path',
            'target' => 'uri',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'handbook_status',
            'target' => 'field_hrdoc_handbook_status',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'issuing_body',
            'target' => 'field_hrdoc_issuing_body',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'date',
            'target' => 'field_hrdoc_publish_date:start',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'file_type',
            'target' => 'bundle',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'filename',
            'target' => 'filename',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'year',
            'target' => 'field_hrdoc_year',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'version',
            'target' => 'field_hrdoc_version',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'file_title',
            'target' => 'field_file_title:et:en',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'path',
            'target' => 'guid',
            'unique' => 1,
          ),
          11 => array(
            'source' => 'source',
            'target' => 'field_source',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'file_title',
            'target' => 'field_file_title:et:und',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['hr_docfiles'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_handbook';
  $feeds_importer->config = array(
    'name' => 'HR Handbook',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
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
            'source' => 'uuid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'path',
            'target' => 'field_document_file:MediaFeedsGUIDProvider',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'title',
            'target' => 'title_field:et:en',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'lang',
            'target' => 'language',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'group_uuid',
            'target' => 'og_group_ref',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'published',
            'target' => 'status',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'cat_topic_subtop',
            'target' => 'field_hrdoc_topic',
            'term_search' => '2',
            'autocreate' => 0,
          ),
          8 => array(
            'source' => 'workbench_moderation',
            'target' => 'workbench_moderation_state',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 1,
        'bundle' => 'hr_document',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['hr_handbook'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hr_owners';
  $feeds_importer->config = array(
    'name' => 'HR Owner',
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
            'source' => 'uuid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'group',
            'target' => 'group_group',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'hr_owners',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['hr_owners'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ref_material';
  $feeds_importer->config = array(
    'name' => 'Ref Material',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
            'source' => 'uuid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'title_en',
            'target' => 'title_field:et:en',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'title_fr',
            'target' => 'title_field:et:fr',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'duty_station',
            'target' => 'field_duty_station',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'body_en',
            'target' => 'body:et:en',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'body_fr',
            'target' => 'body:et:fr',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'keywords',
            'target' => 'field_keywords',
            'term_search' => '2',
            'autocreate' => 0,
          ),
          7 => array(
            'source' => 'newsletter_category',
            'target' => 'field_simplenews_term',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'group_uuid',
            'target' => 'og_group_ref',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'lang',
            'target' => 'language',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'published',
            'target' => 'status',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Custom text',
            'target' => 'field_ref_file:MediaFeedsGUIDProvider',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'title_default',
            'target' => 'title',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'reference_materials',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['ref_material'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ref_material_doc_files';
  $feeds_importer->config = array(
    'name' => 'Ref Material Doc Files: Factsheet',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'factsheet',
        'author' => '1',
        'authorize' => 0,
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'date',
            'target' => 'field_file_date:start',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'doc_title',
            'target' => 'field_file_description',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'file',
            'target' => 'uri',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'file',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'doc_type',
            'target' => 'bundle',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'filename',
            'target' => 'filename',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['ref_material_doc_files'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ref_material_doc_files_audio';
  $feeds_importer->config = array(
    'name' => 'Ref Material Doc Files: Audio',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'audio',
        'author' => '1',
        'authorize' => 0,
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'date',
            'target' => 'field_file_date:start',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'doc_title',
            'target' => 'field_file_description',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'file',
            'target' => 'uri',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'file',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'doc_type',
            'target' => 'bundle',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'filename',
            'target' => 'filename',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['ref_material_doc_files_audio'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ref_material_doc_files_form';
  $feeds_importer->config = array(
    'name' => 'Ref Material Doc Files: Form',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'form',
        'author' => '1',
        'authorize' => 0,
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'date',
            'target' => 'field_file_date:start',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'doc_title',
            'target' => 'field_file_description',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'file',
            'target' => 'uri',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'file',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'doc_type',
            'target' => 'bundle',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'filename',
            'target' => 'filename',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['ref_material_doc_files_form'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ref_material_doc_files_guide';
  $feeds_importer->config = array(
    'name' => 'Ref Material Doc Files: Guide',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'guide',
        'author' => '1',
        'authorize' => 0,
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'date',
            'target' => 'field_file_date:start',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'doc_title',
            'target' => 'field_file_description',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'file',
            'target' => 'uri',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'file',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'doc_type',
            'target' => 'bundle',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'filename',
            'target' => 'filename',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['ref_material_doc_files_guide'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ref_material_doc_files_handbook';
  $feeds_importer->config = array(
    'name' => 'Ref Material Doc Files: Handbook',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'handbook',
        'author' => '1',
        'authorize' => 0,
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'date',
            'target' => 'field_file_date:start',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'doc_title',
            'target' => 'field_file_description',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'file',
            'target' => 'uri',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'file',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'doc_type',
            'target' => 'bundle',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'filename',
            'target' => 'filename',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['ref_material_doc_files_handbook'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ref_material_doc_files_list';
  $feeds_importer->config = array(
    'name' => 'Ref Material Doc Files: List',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'list',
        'author' => '1',
        'authorize' => 0,
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'date',
            'target' => 'field_file_date:start',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'doc_title',
            'target' => 'field_file_description',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'file',
            'target' => 'uri',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'file',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'doc_type',
            'target' => 'bundle',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'filename',
            'target' => 'filename',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['ref_material_doc_files_list'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ref_material_doc_files_manual';
  $feeds_importer->config = array(
    'name' => 'Ref Material Doc Files: Manual',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'manual',
        'author' => '1',
        'authorize' => 0,
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'date',
            'target' => 'field_file_date:start',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'doc_title',
            'target' => 'field_file_description',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'file',
            'target' => 'uri',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'file',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'doc_type',
            'target' => 'bundle',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'filename',
            'target' => 'filename',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['ref_material_doc_files_manual'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ref_material_doc_files_policy';
  $feeds_importer->config = array(
    'name' => 'Ref Material Doc Files: Policy',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'policy',
        'author' => '1',
        'authorize' => 0,
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'date',
            'target' => 'field_file_date:start',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'doc_title',
            'target' => 'field_file_description',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'file',
            'target' => 'uri',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'file',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'doc_type',
            'target' => 'bundle',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'filename',
            'target' => 'filename',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['ref_material_doc_files_policy'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ref_material_doc_files_quick_guides';
  $feeds_importer->config = array(
    'name' => 'Ref Material Doc Files: Quick Guides',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'quick_guide',
        'author' => '1',
        'authorize' => 0,
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'date',
            'target' => 'field_file_date:start',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'doc_title',
            'target' => 'field_file_description',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'file',
            'target' => 'uri',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'file',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'doc_type',
            'target' => 'bundle',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'filename',
            'target' => 'filename',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['ref_material_doc_files_quick_guides'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ref_material_doc_files_video';
  $feeds_importer->config = array(
    'name' => 'Ref Material Doc Files: Video',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'bundle' => 'video',
        'author' => '1',
        'authorize' => 0,
        'debug' => array(
          'newEntity' => 0,
          'entityLoad' => 0,
          'entitySave' => 0,
          'setTargetElement' => 0,
          'existingEntityId' => 0,
        ),
        'mappings' => array(
          0 => array(
            'source' => 'date',
            'target' => 'field_file_date:start',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'doc_title',
            'target' => 'field_file_description',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'file',
            'target' => 'uri',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'file',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'doc_type',
            'target' => 'bundle',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'filename',
            'target' => 'filename',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => NULL,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['ref_material_doc_files_video'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'subject_matter_area';
  $feeds_importer->config = array(
    'name' => 'Subject Matter Area',
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
            'source' => 'uuid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'published',
            'target' => 'status',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'group',
            'target' => 'group_group',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'subject_matter_area',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['subject_matter_area'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'taxonomy_keywords';
  $feeds_importer->config = array(
    'name' => 'Taxonomy: Keywords',
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
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'uuid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'term_name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'parent_uuid',
            'target' => 'parentguid',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'term_name',
            'target' => 'name_field:et:en',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'term_name_fr',
            'target' => 'name_field:et:fr',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'keywords',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['taxonomy_keywords'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'taxonomy_topics';
  $feeds_importer->config = array(
    'name' => 'Taxonomy: Topics',
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
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'uuid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'parent_uuid',
            'target' => 'parentguid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'item_name',
            'target' => 'name_field:et:en',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'item_name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'item_name_fr',
            'target' => 'name_field:et:fr',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'topics',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['taxonomy_topics'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'users';
  $feeds_importer->config = array(
    'name' => 'Users',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          3 => 0,
          4 => 0,
          5 => 0,
          6 => 0,
          7 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'status',
            'target' => 'status',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'email',
            'target' => 'mail',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'uuid',
            'target' => 'guid',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'roles',
            'target' => 'roles',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['users'] = $feeds_importer;

  return $export;
}
