<?php
/**
 * @file
 * hr_document.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hr_document_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'handbook_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Handbook Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'HR Handbook';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_accordion';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name_field_et_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'name_field_et',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'col-sm-4';
  $handler->display->display_options['style_options']['use-grouping-header'] = 1;
  $handler->display->display_options['style_options']['collapsible'] = 1;
  $handler->display->display_options['style_options']['row-start-open'] = 'none';
  $handler->display->display_options['style_options']['autoheight'] = 0;
  $handler->display->display_options['style_options']['clearstyle'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Topic */
  $handler->display->display_options['relationships']['field_hrdoc_topic_tid']['id'] = 'field_hrdoc_topic_tid';
  $handler->display->display_options['relationships']['field_hrdoc_topic_tid']['table'] = 'field_data_field_hrdoc_topic';
  $handler->display->display_options['relationships']['field_hrdoc_topic_tid']['field'] = 'field_hrdoc_topic_tid';
  $handler->display->display_options['relationships']['field_hrdoc_topic_tid']['ui_name'] = 'Topic';
  /* Relationship: Topic Parent */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['relationship'] = 'field_hrdoc_topic_tid';
  $handler->display->display_options['relationships']['parent']['ui_name'] = 'Topic Parent';
  $handler->display->display_options['relationships']['parent']['label'] = 'Topic Parent';
  /* Relationship: Topic Parent Parent */
  $handler->display->display_options['relationships']['parent_1']['id'] = 'parent_1';
  $handler->display->display_options['relationships']['parent_1']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent_1']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent_1']['relationship'] = 'parent';
  $handler->display->display_options['relationships']['parent_1']['ui_name'] = 'Topic Parent Parent';
  $handler->display->display_options['relationships']['parent_1']['label'] = 'Topic Parent Parent';
  /* Relationship: Field: DocType (field_hrdoc_doctype) */
  $handler->display->display_options['relationships']['field_hrdoc_doctype_tid']['id'] = 'field_hrdoc_doctype_tid';
  $handler->display->display_options['relationships']['field_hrdoc_doctype_tid']['table'] = 'field_data_field_hrdoc_doctype';
  $handler->display->display_options['relationships']['field_hrdoc_doctype_tid']['field'] = 'field_hrdoc_doctype_tid';
  $handler->display->display_options['relationships']['field_hrdoc_doctype_tid']['label'] = 'doctype term';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Icon */
  $handler->display->display_options['fields']['field_hr_doctype_icon']['id'] = 'field_hr_doctype_icon';
  $handler->display->display_options['fields']['field_hr_doctype_icon']['table'] = 'field_data_field_hr_doctype_icon';
  $handler->display->display_options['fields']['field_hr_doctype_icon']['field'] = 'field_hr_doctype_icon';
  $handler->display->display_options['fields']['field_hr_doctype_icon']['relationship'] = 'field_hrdoc_doctype_tid';
  $handler->display->display_options['fields']['field_hr_doctype_icon']['label'] = '';
  $handler->display->display_options['fields']['field_hr_doctype_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hr_doctype_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_hr_doctype_icon']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_hr_doctype_icon']['settings'] = array(
    'file_view_mode' => 'default',
  );
  $handler->display->display_options['fields']['field_hr_doctype_icon']['group_column'] = 'fid';
  /* Field: Entity translation: Document File: translated */
  $handler->display->display_options['fields']['field_document_file_et']['id'] = 'field_document_file_et';
  $handler->display->display_options['fields']['field_document_file_et']['table'] = 'field_data_field_document_file';
  $handler->display->display_options['fields']['field_document_file_et']['field'] = 'field_document_file_et';
  $handler->display->display_options['fields']['field_document_file_et']['label'] = '';
  $handler->display->display_options['fields']['field_document_file_et']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_document_file_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_document_file_et']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_document_file_et']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_document_file_et']['group_column'] = 'fid';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'field_hrdoc_topic_tid';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Field: Field: Symbol */
  $handler->display->display_options['fields']['field_symbol']['id'] = 'field_symbol';
  $handler->display->display_options['fields']['field_symbol']['table'] = 'field_data_field_symbol';
  $handler->display->display_options['fields']['field_symbol']['field'] = 'field_symbol';
  $handler->display->display_options['fields']['field_symbol']['label'] = '';
  $handler->display->display_options['fields']['field_symbol']['element_label_colon'] = FALSE;
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et']['id'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['label'] = '';
  $handler->display->display_options['fields']['title_field_et']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field_et']['alter']['path'] = '[field_document_file_et]';
  $handler->display->display_options['fields']['title_field_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field_et']['type'] = 'text_plain';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Entity translation: Name: translated */
  $handler->display->display_options['fields']['name_field_et']['id'] = 'name_field_et';
  $handler->display->display_options['fields']['name_field_et']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field_et']['field'] = 'name_field_et';
  $handler->display->display_options['fields']['name_field_et']['relationship'] = 'field_hrdoc_topic_tid';
  $handler->display->display_options['fields']['name_field_et']['label'] = '';
  $handler->display->display_options['fields']['name_field_et']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field_et']['element_label_colon'] = FALSE;
  /* Field: Entity translation: Name: translated */
  $handler->display->display_options['fields']['name_field_et_1']['id'] = 'name_field_et_1';
  $handler->display->display_options['fields']['name_field_et_1']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field_et_1']['field'] = 'name_field_et';
  $handler->display->display_options['fields']['name_field_et_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_field_et_1']['label'] = '';
  $handler->display->display_options['fields']['name_field_et_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field_et_1']['element_label_colon'] = FALSE;
  /* Sort criterion: Taxonomy term: Name (name_field) */
  $handler->display->display_options['sorts']['name_field_value']['id'] = 'name_field_value';
  $handler->display->display_options['sorts']['name_field_value']['table'] = 'field_data_name_field';
  $handler->display->display_options['sorts']['name_field_value']['field'] = 'name_field_value';
  $handler->display->display_options['sorts']['name_field_value']['relationship'] = 'parent';
  /* Sort criterion: Taxonomy term: Name (name_field) */
  $handler->display->display_options['sorts']['name_field_value_1']['id'] = 'name_field_value_1';
  $handler->display->display_options['sorts']['name_field_value_1']['table'] = 'field_data_name_field';
  $handler->display->display_options['sorts']['name_field_value_1']['field'] = 'name_field_value';
  $handler->display->display_options['sorts']['name_field_value_1']['relationship'] = 'field_hrdoc_topic_tid';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_hrdoc_doctype_tid';
  /* Sort criterion: Field: Symbol (field_symbol) */
  $handler->display->display_options['sorts']['field_symbol_value']['id'] = 'field_symbol_value';
  $handler->display->display_options['sorts']['field_symbol_value']['table'] = 'field_data_field_symbol';
  $handler->display->display_options['sorts']['field_symbol_value']['field'] = 'field_symbol_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'parent_1';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = '%1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'topics' => 'topics',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hr_document' => 'hr_document',
  );
  /* Filter criterion: Content: Topic (field_hrdoc_topic) */
  $handler->display->display_options['filters']['field_hrdoc_topic_tid']['id'] = 'field_hrdoc_topic_tid';
  $handler->display->display_options['filters']['field_hrdoc_topic_tid']['table'] = 'field_data_field_hrdoc_topic';
  $handler->display->display_options['filters']['field_hrdoc_topic_tid']['field'] = 'field_hrdoc_topic_tid';
  $handler->display->display_options['filters']['field_hrdoc_topic_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_hrdoc_topic_tid']['vocabulary'] = 'topics';
  /* Filter criterion: Content: Document File (field_document_file:fid) */
  $handler->display->display_options['filters']['field_document_file_fid']['id'] = 'field_document_file_fid';
  $handler->display->display_options['filters']['field_document_file_fid']['table'] = 'field_data_field_document_file';
  $handler->display->display_options['filters']['field_document_file_fid']['field'] = 'field_document_file_fid';
  $handler->display->display_options['filters']['field_document_file_fid']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'handbook/category/%';
  $export['handbook_content'] = $view;

  $view = new view();
  $view->name = 'handbook_files_by_source';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_handbook_files';
  $view->human_name = 'Handbook Files by Source';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'HR Handbook by Source';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1000';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'field_symbol' => 'field_symbol',
    'url' => 'url',
    'field_file_title' => 'field_file_title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_symbol' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'url' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_file_title' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Indexed File: Symbol */
  $handler->display->display_options['fields']['field_symbol']['id'] = 'field_symbol';
  $handler->display->display_options['fields']['field_symbol']['table'] = 'search_api_index_handbook_files';
  $handler->display->display_options['fields']['field_symbol']['field'] = 'field_symbol';
  $handler->display->display_options['fields']['field_symbol']['label'] = '';
  $handler->display->display_options['fields']['field_symbol']['element_label_colon'] = FALSE;
  /* Field: Indexed File: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_handbook_files';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed File: File Title */
  $handler->display->display_options['fields']['field_file_title']['id'] = 'field_file_title';
  $handler->display->display_options['fields']['field_file_title']['table'] = 'search_api_index_handbook_files';
  $handler->display->display_options['fields']['field_file_title']['field'] = 'field_file_title';
  $handler->display->display_options['fields']['field_file_title']['label'] = '';
  $handler->display->display_options['fields']['field_file_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_file_title']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['field_file_title']['element_label_colon'] = FALSE;
  /* Sort criterion: Indexed File: File name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'search_api_index_handbook_files';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Sort criterion: Indexed File: Publish Date */
  $handler->display->display_options['sorts']['field_hrdoc_publish_date']['id'] = 'field_hrdoc_publish_date';
  $handler->display->display_options['sorts']['field_hrdoc_publish_date']['table'] = 'search_api_index_handbook_files';
  $handler->display->display_options['sorts']['field_hrdoc_publish_date']['field'] = 'field_hrdoc_publish_date';
  $handler->display->display_options['sorts']['field_hrdoc_publish_date']['order'] = 'DESC';
  /* Contextual filter: Indexed File: Source */
  $handler->display->display_options['arguments']['field_source']['id'] = 'field_source';
  $handler->display->display_options['arguments']['field_source']['table'] = 'search_api_index_handbook_files';
  $handler->display->display_options['arguments']['field_source']['field'] = 'field_source';
  $handler->display->display_options['arguments']['field_source']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_source']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_source']['title'] = 'HR Handbook by Source: %1';
  $handler->display->display_options['arguments']['field_source']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_source']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_source']['summary_options']['override'] = TRUE;
  $handler->display->display_options['arguments']['field_source']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_source']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_source']['validate_options']['code'] = '$field = field_info_field(\'field_source\');
if (array_key_exists($argument, $field[\'settings\'][\'allowed_values\'])) {
  $handler->validated_title = $field[\'settings\'][\'allowed_values\'][$argument];
  return true;
}
return false;';
  $handler->display->display_options['arguments']['field_source']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_source']['not'] = 0;
  /* Filter criterion: Indexed File: File type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_handbook_files';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'handbook_doc' => 'handbook_doc',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'handbook/source/%';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed File: Publish Date */
  $handler->display->display_options['sorts']['field_hrdoc_publish_date']['id'] = 'field_hrdoc_publish_date';
  $handler->display->display_options['sorts']['field_hrdoc_publish_date']['table'] = 'search_api_index_handbook_files';
  $handler->display->display_options['sorts']['field_hrdoc_publish_date']['field'] = 'field_hrdoc_publish_date';
  $handler->display->display_options['sorts']['field_hrdoc_publish_date']['order'] = 'DESC';
  /* Sort criterion: Indexed File: Version */
  $handler->display->display_options['sorts']['field_hrdoc_version']['id'] = 'field_hrdoc_version';
  $handler->display->display_options['sorts']['field_hrdoc_version']['table'] = 'search_api_index_handbook_files';
  $handler->display->display_options['sorts']['field_hrdoc_version']['field'] = 'field_hrdoc_version';
  $handler->display->display_options['sorts']['field_hrdoc_version']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'handbook/source/%/date';

  /* Display: Page 2 */
  $handler = $view->new_display('page', 'Page 2', 'page_2');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed File: File name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'search_api_index_handbook_files';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['path'] = 'handbook/source/%/alpha';
  $export['handbook_files_by_source'] = $view;

  $view = new view();
  $view->name = 'handbook_source';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Handbook Source';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Handbook Documents by Source';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_document_file_et' => 'field_document_file_et',
    'nid' => 'nid',
    'field_symbol' => 'field_symbol',
    'title_field_et' => 'title_field_et',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_document_file_et' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_symbol' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'title_field_et' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Entity translation: Document File: translated */
  $handler->display->display_options['fields']['field_document_file_et']['id'] = 'field_document_file_et';
  $handler->display->display_options['fields']['field_document_file_et']['table'] = 'field_data_field_document_file';
  $handler->display->display_options['fields']['field_document_file_et']['field'] = 'field_document_file_et';
  $handler->display->display_options['fields']['field_document_file_et']['label'] = '';
  $handler->display->display_options['fields']['field_document_file_et']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_document_file_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_document_file_et']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_document_file_et']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_document_file_et']['group_column'] = 'entity_id';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field: Symbol */
  $handler->display->display_options['fields']['field_symbol']['id'] = 'field_symbol';
  $handler->display->display_options['fields']['field_symbol']['table'] = 'field_data_field_symbol';
  $handler->display->display_options['fields']['field_symbol']['field'] = 'field_symbol';
  $handler->display->display_options['fields']['field_symbol']['label'] = '';
  $handler->display->display_options['fields']['field_symbol']['element_label_colon'] = FALSE;
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et']['id'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['label'] = '';
  $handler->display->display_options['fields']['title_field_et']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field_et']['alter']['path'] = '[field_document_file_et]';
  $handler->display->display_options['fields']['title_field_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field_et']['type'] = 'text_plain';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = ' [edit]';
  /* Sort criterion: Field: Publish Date (field_hrdoc_publish_date) */
  $handler->display->display_options['sorts']['field_hrdoc_publish_date_value']['id'] = 'field_hrdoc_publish_date_value';
  $handler->display->display_options['sorts']['field_hrdoc_publish_date_value']['table'] = 'field_data_field_hrdoc_publish_date';
  $handler->display->display_options['sorts']['field_hrdoc_publish_date_value']['field'] = 'field_hrdoc_publish_date_value';
  $handler->display->display_options['sorts']['field_hrdoc_publish_date_value']['order'] = 'DESC';
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  /* Sort criterion: Field: Symbol (field_symbol) */
  $handler->display->display_options['sorts']['field_symbol_value']['id'] = 'field_symbol_value';
  $handler->display->display_options['sorts']['field_symbol_value']['table'] = 'field_data_field_symbol';
  $handler->display->display_options['sorts']['field_symbol_value']['field'] = 'field_symbol_value';
  /* Contextual filter: Field: Source (field_source) */
  $handler->display->display_options['arguments']['field_source_value']['id'] = 'field_source_value';
  $handler->display->display_options['arguments']['field_source_value']['table'] = 'field_data_field_source';
  $handler->display->display_options['arguments']['field_source_value']['field'] = 'field_source_value';
  $handler->display->display_options['arguments']['field_source_value']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_source_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_source_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_source_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_source_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_source_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_source_value']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_source_value']['validate_options']['code'] = '$field = field_info_field(\'field_source\');
if (array_key_exists($argument, $field[\'settings\'][\'allowed_values\'])) {
  $handler->validated_title = $field[\'settings\'][\'allowed_values\'][$argument];
  return true;
}
return false;';
  $handler->display->display_options['arguments']['field_source_value']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hr_document' => 'hr_document',
  );
  /* Filter criterion: AVG(Content: This is a section of a document, not a whole document (field_document_section)) */
  $handler->display->display_options['filters']['field_document_section_value']['id'] = 'field_document_section_value';
  $handler->display->display_options['filters']['field_document_section_value']['table'] = 'field_data_field_document_section';
  $handler->display->display_options['filters']['field_document_section_value']['field'] = 'field_document_section_value';
  $handler->display->display_options['filters']['field_document_section_value']['group_type'] = 'avg';
  $handler->display->display_options['filters']['field_document_section_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_document_section_value']['value']['value'] = '1';

  /* Display: by alpha */
  $handler = $view->new_display('page', 'by alpha', 'page');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  /* Sort criterion: Field: Symbol (field_symbol) */
  $handler->display->display_options['sorts']['field_symbol_value']['id'] = 'field_symbol_value';
  $handler->display->display_options['sorts']['field_symbol_value']['table'] = 'field_data_field_symbol';
  $handler->display->display_options['sorts']['field_symbol_value']['field'] = 'field_symbol_value';
  $handler->display->display_options['path'] = 'handbook/source/%/alpha';

  /* Display: by date */
  $handler = $view->new_display('page', 'by date', 'page_1');
  $handler->display->display_options['path'] = 'handbook/source/%/date';
  $export['handbook_source'] = $view;

  $view = new view();
  $view->name = 'hr_handbook';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_index_all';
  $view->human_name = 'HR Handbook';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_accordion';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'name_field',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    2 => array(
      'field' => 'name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'col-sm-4';
  $handler->display->display_options['style_options']['use-grouping-header'] = 1;
  $handler->display->display_options['style_options']['collapsible'] = 1;
  $handler->display->display_options['style_options']['row-start-open'] = '0';
  $handler->display->display_options['style_options']['autoheight'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Indexed Node: Topic */
  $handler->display->display_options['relationships']['field_hrdoc_topic']['id'] = 'field_hrdoc_topic';
  $handler->display->display_options['relationships']['field_hrdoc_topic']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['relationships']['field_hrdoc_topic']['field'] = 'field_hrdoc_topic';
  $handler->display->display_options['relationships']['field_hrdoc_topic']['label'] = 'Subtopic';
  /* Relationship: Taxonomy term: Parent terms */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['relationship'] = 'field_hrdoc_topic';
  $handler->display->display_options['relationships']['parent']['label'] = 'Topic';
  /* Relationship: Taxonomy term: Parent terms */
  $handler->display->display_options['relationships']['parent_1']['id'] = 'parent_1';
  $handler->display->display_options['relationships']['parent_1']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['relationships']['parent_1']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent_1']['relationship'] = 'parent';
  $handler->display->display_options['relationships']['parent_1']['label'] = 'Category';
  /* Relationship: Document File: The file. (indexed) */
  $handler->display->display_options['relationships']['field_document_file_file']['id'] = 'field_document_file_file';
  $handler->display->display_options['relationships']['field_document_file_file']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['relationships']['field_document_file_file']['field'] = 'field_document_file_file';
  /* Relationship: File: DocType */
  $handler->display->display_options['relationships']['field_hrdoc_doctype']['id'] = 'field_hrdoc_doctype';
  $handler->display->display_options['relationships']['field_hrdoc_doctype']['table'] = 'entity_file';
  $handler->display->display_options['relationships']['field_hrdoc_doctype']['field'] = 'field_hrdoc_doctype';
  $handler->display->display_options['relationships']['field_hrdoc_doctype']['relationship'] = 'field_document_file_file';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'parent_1';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['link_to_entity'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_hrdoc_topic';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_entity'] = 0;
  /* Field: Taxonomy term: Icon */
  $handler->display->display_options['fields']['field_hr_doctype_icon']['id'] = 'field_hr_doctype_icon';
  $handler->display->display_options['fields']['field_hr_doctype_icon']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['field_hr_doctype_icon']['field'] = 'field_hr_doctype_icon';
  $handler->display->display_options['fields']['field_hr_doctype_icon']['relationship'] = 'field_hrdoc_doctype';
  $handler->display->display_options['fields']['field_hr_doctype_icon']['label'] = '';
  $handler->display->display_options['fields']['field_hr_doctype_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hr_doctype_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_hr_doctype_icon']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: File: Symbol */
  $handler->display->display_options['fields']['field_symbol']['id'] = 'field_symbol';
  $handler->display->display_options['fields']['field_symbol']['table'] = 'entity_file';
  $handler->display->display_options['fields']['field_symbol']['field'] = 'field_symbol';
  $handler->display->display_options['fields']['field_symbol']['relationship'] = 'field_document_file_file';
  $handler->display->display_options['fields']['field_symbol']['label'] = '';
  $handler->display->display_options['fields']['field_symbol']['element_label_colon'] = FALSE;
  /* Field: File: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'entity_file';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['relationship'] = 'field_document_file_file';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hr_document' => 'hr_document',
  );

  /* Display: Category Topics */
  $handler = $view->new_display('page', 'Category Topics', 'page');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'parent_1';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['link_to_entity'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field_1']['id'] = 'name_field_1';
  $handler->display->display_options['fields']['name_field_1']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['name_field_1']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field_1']['relationship'] = 'field_hrdoc_topic';
  $handler->display->display_options['fields']['name_field_1']['label'] = '';
  $handler->display->display_options['fields']['name_field_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field_1']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_hrdoc_file']['id'] = 'field_hrdoc_file';
  $handler->display->display_options['fields']['field_hrdoc_file']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['fields']['field_hrdoc_file']['field'] = 'field_hrdoc_file';
  $handler->display->display_options['fields']['field_hrdoc_file']['label'] = '';
  $handler->display->display_options['fields']['field_hrdoc_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hrdoc_file']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['path'] = '[field_hrdoc_file]';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Issuing Body */
  $handler->display->display_options['fields']['field_hrdoc_issuing_body']['id'] = 'field_hrdoc_issuing_body';
  $handler->display->display_options['fields']['field_hrdoc_issuing_body']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['fields']['field_hrdoc_issuing_body']['field'] = 'field_hrdoc_issuing_body';
  $handler->display->display_options['fields']['field_hrdoc_issuing_body']['label'] = '';
  $handler->display->display_options['fields']['field_hrdoc_issuing_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hrdoc_issuing_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hrdoc_issuing_body']['type'] = 'list_key';
  /* Field: Indexed Node: DocType */
  $handler->display->display_options['fields']['field_hrdoc_doctype']['id'] = 'field_hrdoc_doctype';
  $handler->display->display_options['fields']['field_hrdoc_doctype']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['fields']['field_hrdoc_doctype']['field'] = 'field_hrdoc_doctype';
  $handler->display->display_options['fields']['field_hrdoc_doctype']['label'] = '';
  $handler->display->display_options['fields']['field_hrdoc_doctype']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hrdoc_doctype']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Handbook Status */
  $handler->display->display_options['fields']['field_hrdoc_handbook_status']['id'] = 'field_hrdoc_handbook_status';
  $handler->display->display_options['fields']['field_hrdoc_handbook_status']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['fields']['field_hrdoc_handbook_status']['field'] = 'field_hrdoc_handbook_status';
  $handler->display->display_options['fields']['field_hrdoc_handbook_status']['label'] = '';
  $handler->display->display_options['fields']['field_hrdoc_handbook_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hrdoc_handbook_status']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Version */
  $handler->display->display_options['fields']['field_hrdoc_version']['id'] = 'field_hrdoc_version';
  $handler->display->display_options['fields']['field_hrdoc_version']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['fields']['field_hrdoc_version']['field'] = 'field_hrdoc_version';
  $handler->display->display_options['fields']['field_hrdoc_version']['label'] = '';
  $handler->display->display_options['fields']['field_hrdoc_version']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hrdoc_version']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Publish Date */
  $handler->display->display_options['fields']['field_hrdoc_publish_date']['id'] = 'field_hrdoc_publish_date';
  $handler->display->display_options['fields']['field_hrdoc_publish_date']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['fields']['field_hrdoc_publish_date']['field'] = 'field_hrdoc_publish_date';
  $handler->display->display_options['fields']['field_hrdoc_publish_date']['label'] = '';
  $handler->display->display_options['fields']['field_hrdoc_publish_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hrdoc_publish_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hrdoc_publish_date']['settings'] = array(
    'format_type' => 'only_full_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<img src=\'/sites/all/themes/hr_portal/css/images/doc-type-icons/[field_hrdoc_doctype].png\' />';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_hrdoc_issuing_body]/[field_hrdoc_doctype]/[field_hrdoc_publish_date]/[field_hrdoc_version]
<br>
[title_field]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Publish Date */
  $handler->display->display_options['fields']['field_hrdoc_publish_date_1']['id'] = 'field_hrdoc_publish_date_1';
  $handler->display->display_options['fields']['field_hrdoc_publish_date_1']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['fields']['field_hrdoc_publish_date_1']['field'] = 'field_hrdoc_publish_date';
  $handler->display->display_options['fields']['field_hrdoc_publish_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_hrdoc_publish_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hrdoc_publish_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'parent_1';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  $handler->display->display_options['fields']['tid']['link_to_entity'] = 0;
  /* Field: Topic: Term ID (indexed) */
  $handler->display->display_options['fields']['field_hrdoc_topic_tid']['id'] = 'field_hrdoc_topic_tid';
  $handler->display->display_options['fields']['field_hrdoc_topic_tid']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['fields']['field_hrdoc_topic_tid']['field'] = 'field_hrdoc_topic_tid';
  $handler->display->display_options['fields']['field_hrdoc_topic_tid']['label'] = 'Term ID';
  $handler->display->display_options['fields']['field_hrdoc_topic_tid']['separator'] = '';
  $handler->display->display_options['fields']['field_hrdoc_topic_tid']['link_to_entity'] = 1;
  /* Field: Topic: Parent terms (indexed) */
  $handler->display->display_options['fields']['field_hrdoc_topic_parent']['id'] = 'field_hrdoc_topic_parent';
  $handler->display->display_options['fields']['field_hrdoc_topic_parent']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['fields']['field_hrdoc_topic_parent']['field'] = 'field_hrdoc_topic_parent';
  $handler->display->display_options['fields']['field_hrdoc_topic_parent']['list']['mode'] = 'first';
  $handler->display->display_options['fields']['field_hrdoc_topic_parent']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_hrdoc_topic_parent']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_hrdoc_topic_parent']['bypass_access'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'handbook/category/%';

  /* Display: Search */
  $handler = $view->new_display('page', 'Search', 'page_2');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'search_api_views_fulltext' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 1;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hr_document' => 'hr_document',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_index_all';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'What are you looking for today ?';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['path'] = 'handbook/search';
  $export['hr_handbook'] = $view;

  $view = new view();
  $view->name = 'hr_handbook_docs';
  $view->description = 'HR Portal Handbooks:  All docs English and French.  Accordion View';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'HR Handbook Docs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'HR Handbook Docs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_accordion';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name_field_2',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'name_field',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    2 => array(
      'field' => 'name_field_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['use-grouping-header'] = 1;
  $handler->display->display_options['style_options']['collapsible'] = 1;
  $handler->display->display_options['style_options']['row-start-open'] = '0';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = TRUE;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'topics' => 'topics',
    'tags' => 0,
  );
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['relationship'] = 'term_node_tid';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent_1']['id'] = 'parent_1';
  $handler->display->display_options['relationships']['parent_1']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent_1']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent_1']['relationship'] = 'parent';
  $handler->display->display_options['relationships']['parent_1']['label'] = 'Category';
  $handler->display->display_options['relationships']['parent_1']['required'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field_2']['id'] = 'name_field_2';
  $handler->display->display_options['fields']['name_field_2']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field_2']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field_2']['relationship'] = 'parent_1';
  $handler->display->display_options['fields']['name_field_2']['label'] = '';
  $handler->display->display_options['fields']['name_field_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field_2']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field_1']['id'] = 'name_field_1';
  $handler->display->display_options['fields']['name_field_1']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field_1']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field_1']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['name_field_1']['label'] = '';
  $handler->display->display_options['fields']['name_field_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field_1']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hr_document' => 'hr_document',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'hr-handbook-docs';
  $export['hr_handbook_docs'] = $view;

  return $export;
}
