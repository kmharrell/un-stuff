<?php
/**
 * @file
 * job_code_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function job_code_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'job_code';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_job_code';
  $view->human_name = 'Job Code';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Job Codes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>We\'re sorry, no results match your search criteria.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Indexed Node: Job Code */
  $handler->display->display_options['fields']['field_code']['id'] = 'field_code';
  $handler->display->display_options['fields']['field_code']['table'] = 'search_api_index_job_code';
  $handler->display->display_options['fields']['field_code']['field'] = 'field_code';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_job_code';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Indexed Node: Grade */
  $handler->display->display_options['fields']['field_grade']['id'] = 'field_grade';
  $handler->display->display_options['fields']['field_grade']['table'] = 'search_api_index_job_code';
  $handler->display->display_options['fields']['field_grade']['field'] = 'field_grade';
  $handler->display->display_options['fields']['field_grade']['label'] = 'Level';
  /* Field: Job Network » Parent terms: Name (indexed) */
  $handler->display->display_options['fields']['field_job_network_parent_name_field']['id'] = 'field_job_network_parent_name_field';
  $handler->display->display_options['fields']['field_job_network_parent_name_field']['table'] = 'search_api_index_job_code';
  $handler->display->display_options['fields']['field_job_network_parent_name_field']['field'] = 'field_job_network_parent_name_field';
  $handler->display->display_options['fields']['field_job_network_parent_name_field']['label'] = 'Job Network Acronym';
  /* Field: Job Network » Parent terms: Description (indexed) */
  $handler->display->display_options['fields']['field_job_network_parent_description']['id'] = 'field_job_network_parent_description';
  $handler->display->display_options['fields']['field_job_network_parent_description']['table'] = 'search_api_index_job_code';
  $handler->display->display_options['fields']['field_job_network_parent_description']['field'] = 'field_job_network_parent_description';
  $handler->display->display_options['fields']['field_job_network_parent_description']['label'] = 'Job Network';
  $handler->display->display_options['fields']['field_job_network_parent_description']['link_to_entity'] = 0;
  /* Field: Job Network: Name (indexed) */
  $handler->display->display_options['fields']['field_job_network_name_field']['id'] = 'field_job_network_name_field';
  $handler->display->display_options['fields']['field_job_network_name_field']['table'] = 'search_api_index_job_code';
  $handler->display->display_options['fields']['field_job_network_name_field']['field'] = 'field_job_network_name_field';
  $handler->display->display_options['fields']['field_job_network_name_field']['label'] = 'Job Family Acronym';
  /* Field: Job Network: Description (indexed) */
  $handler->display->display_options['fields']['field_job_network_description']['id'] = 'field_job_network_description';
  $handler->display->display_options['fields']['field_job_network_description']['table'] = 'search_api_index_job_code';
  $handler->display->display_options['fields']['field_job_network_description']['field'] = 'field_job_network_description';
  $handler->display->display_options['fields']['field_job_network_description']['label'] = 'Job Family';
  $handler->display->display_options['fields']['field_job_network_description']['link_to_entity'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_job_code';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Keyword';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['description'] = 'Note: The user can search on Job Code, Job Title, Job Network and Job Family.';
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
  /* Filter criterion: Job Network: Parent terms (indexed) */
  $handler->display->display_options['filters']['field_job_network_parent_1']['id'] = 'field_job_network_parent_1';
  $handler->display->display_options['filters']['field_job_network_parent_1']['table'] = 'search_api_index_job_code';
  $handler->display->display_options['filters']['field_job_network_parent_1']['field'] = 'field_job_network_parent';
  $handler->display->display_options['filters']['field_job_network_parent_1']['value'] = array();
  $handler->display->display_options['filters']['field_job_network_parent_1']['group'] = 1;
  $handler->display->display_options['filters']['field_job_network_parent_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_job_network_parent_1']['expose']['operator_id'] = 'field_job_network_parent_1_op';
  $handler->display->display_options['filters']['field_job_network_parent_1']['expose']['label'] = 'Job Network';
  $handler->display->display_options['filters']['field_job_network_parent_1']['expose']['operator'] = 'field_job_network_parent_1_op';
  $handler->display->display_options['filters']['field_job_network_parent_1']['expose']['identifier'] = 'field_job_network_parent_1';
  $handler->display->display_options['filters']['field_job_network_parent_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_job_network_parent_1']['type'] = 'select';
  /* Filter criterion: Indexed Node: Job Network */
  $handler->display->display_options['filters']['field_job_network']['id'] = 'field_job_network';
  $handler->display->display_options['filters']['field_job_network']['table'] = 'search_api_index_job_code';
  $handler->display->display_options['filters']['field_job_network']['field'] = 'field_job_network';
  $handler->display->display_options['filters']['field_job_network']['value'] = array();
  $handler->display->display_options['filters']['field_job_network']['group'] = 1;
  $handler->display->display_options['filters']['field_job_network']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_job_network']['expose']['operator_id'] = 'field_job_network_op';
  $handler->display->display_options['filters']['field_job_network']['expose']['label'] = 'Job Family';
  $handler->display->display_options['filters']['field_job_network']['expose']['operator'] = 'field_job_network_op';
  $handler->display->display_options['filters']['field_job_network']['expose']['identifier'] = 'field_job_network';
  $handler->display->display_options['filters']['field_job_network']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_job_network']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Grade */
  $handler->display->display_options['filters']['field_grade']['id'] = 'field_grade';
  $handler->display->display_options['filters']['field_grade']['table'] = 'search_api_index_job_code';
  $handler->display->display_options['filters']['field_grade']['field'] = 'field_grade';
  $handler->display->display_options['filters']['field_grade']['value'] = array();
  $handler->display->display_options['filters']['field_grade']['group'] = 1;
  $handler->display->display_options['filters']['field_grade']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_grade']['expose']['operator_id'] = 'field_grade_op';
  $handler->display->display_options['filters']['field_grade']['expose']['label'] = 'Level';
  $handler->display->display_options['filters']['field_grade']['expose']['operator'] = 'field_grade_op';
  $handler->display->display_options['filters']['field_grade']['expose']['identifier'] = 'field_grade';
  $handler->display->display_options['filters']['field_grade']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_grade']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'job-codes';
  $export['job_code'] = $view;

  return $export;
}
