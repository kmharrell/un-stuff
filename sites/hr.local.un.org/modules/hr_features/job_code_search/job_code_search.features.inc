<?php
/**
 * @file
 * job_code_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function job_code_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_views_api().
 */
function job_code_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function job_code_search_node_info() {
  $items = array(
    'job_code' => array(
      'name' => t('Job Code'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Job Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function job_code_search_default_search_api_index() {
  $items = array();
  $items['job_code'] = entity_import('search_api_index', '{
    "name" : "Job Code",
    "machine_name" : "job_code",
    "description" : null,
    "server" : "search_api_db",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "job_code" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_job_network:parent" : "field_job_network:parent",
              "field_job_network:field_job_network" : "field_job_network:field_job_network"
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "title2" : true,
              "field_job_network:name" : true,
              "field_job_network:description" : true,
              "field_job_network:name_field" : true,
              "field_job_network:parent:name" : true,
              "field_job_network:parent:description" : true,
              "field_job_network:parent:name_field" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 1,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_job_network:name" : true,
              "field_job_network:description" : true,
              "field_job_network:name_field" : true,
              "field_job_network:parent:name" : true,
              "field_job_network:parent:description" : true,
              "field_job_network:parent:name_field" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_code" : { "type" : "text" },
        "field_grade" : { "type" : "string" },
        "field_job_network" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_job_network:description" : { "type" : "text" },
        "field_job_network:field_code" : { "type" : "text" },
        "field_job_network:field_job_network" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_job_network:name" : { "type" : "text" },
        "field_job_network:name_field" : { "type" : "text" },
        "field_job_network:parent" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_job_network:parent:description" : { "type" : "list\\u003Ctext\\u003E" },
        "field_job_network:parent:field_code" : { "type" : "list\\u003Ctext\\u003E" },
        "field_job_network:parent:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_job_network:parent:name_field" : { "type" : "list\\u003Ctext\\u003E" },
        "field_job_network:parent:tid" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_job_network:tid" : { "type" : "integer" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text" },
        "title2" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
