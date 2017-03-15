<?php

/**
 * @file template.php
 */
function main_preprocess_page(&$variables) {
  /*
if (arg(0) != 'info' && arg(0) != 'user' && arg(0) != 'admin' && arg(1) != 'add' && arg(2) != 'edit' && arg(0) != 'results' && !(arg(0) == 'node' && arg(1) == '82') ) {
	$domain = domain_get_domain();
	if($domain['domain_id'] == 1):
	  drupal_goto('node');
	endif;
  }
*/
	$variables['is_memberstates'] = false;
	$domain = domain_get_domain();
	if($domain['domain_id'] == 245):
	  $variables['is_memberstates'] = true;
	  /*
$variables['columns']--;
	  unset($variables['page']['sidebar_first']);
*/
  endif;
	
	
  /*
if (arg(0) == 'info' && (isset($_GET['blocks']) && $_GET['blocks'] == 0)) {
      $variables['columns']--;
	  unset($variables['page']['sidebar_second']);
  }
*/
}

function main_preprocess_block(&$variables) {
  
  // dpm($variables);

  if ($variables['block_html_id'] == 'block-block-3') {
	  drupal_add_js('https://www.google.com/jsapi');
	  drupal_add_js('https://maps.googleapis.com/maps/api/js?key=AIzaSyA23letq0eg85afzfuHKF8N71CFgf-GpEo&sensor=false');
	  drupal_add_js(path_to_theme().'/js/map.js');
	  drupal_add_js(path_to_theme().'/js/jquery.sticky.js');
  }
  $domain = domain_get_domain();
	if($domain['domain_id'] == 245) {
  	drupal_add_js(path_to_theme().'/js/viz-dropdown.js');
	  drupal_add_js(path_to_theme().'/js/jquery-easing-1.3.pack.js');
	}
  
  if ($variables['block_html_id'] == 'block-views-search-block-7') {
	unset($variables['block']);
	unset($variables['content']);  
  }
  $blocks_to_hide = array(
    'block-views-links-block',
    'block-views-news-block-1',
  );
  if (in_array($variables['block_html_id'], $blocks_to_hide)) {
	  $domain = domain_get_domain();
  	if($domain['domain_id'] == 245){
    	unset($variables['block']);
      unset($variables['content']);  
  	}
	
  }  
}

function main_preprocess_views_view(&$vars) {
  // Type Pages
  if ($vars['view']->name == 'search' && ($vars['view']->current_display == 'page_1')) {
    $machine_type = arg(2);
    $content_type = node_type_load($machine_type);
    $vars['title'] = '<h1 class="title">'.$content_type->name.'</h1>';
  }
  // Main search result
  if ($vars['view']->name == 'search' && ($vars['view']->current_display == 'page_6')) {
	  $title_text = array();
	  if (isset($_GET['f'])) {
		  $vars['view']->exposed_input['f'] = $_GET['f'];
	  }
	  if (isset($vars['view']->exposed_input['f'])) {
	    foreach ($vars['view']->exposed_input['f'] as $f) {
		  $term = explode(':', $f);
	      $type = $term[0];
	      if ($type == 'field_un_themes') {
		      $output = 'Topic';
	      }
	      if ($type == 'field_relevant_un_committees') {
		      $output = 'Committee';
	      }
	      $term = taxonomy_term_load($term[1]);
	      if (isset($term->name)) {
		    $output .= ': '.$term->name;
	      }
	      else {
		    $output .= '';
	      }
	      $title_text[] = $output;
	    }
	  }
	  if (isset($vars['view']->exposed_input['search_api_views_fulltext'])) {
		  $query = $vars['view']->exposed_input['search_api_views_fulltext'];	
		  $title_text[] = $query;
	  }
	  $output_text = '';
	  if (count($title_text) > 0) {
	    foreach ($title_text as $title) {
		   $output_text .= $title.'<br>';
	    }
	    $vars['title'] = '<h1 class="title">'.$output_text.'</h1>';	  
	  }
  }
}
