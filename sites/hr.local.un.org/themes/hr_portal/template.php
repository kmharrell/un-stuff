<?php

/**
 * @file
 * template.php
 */
function hr_portal_preprocess_html(&$variables) {
  //drupal_add_css('//maxcdn.bootstrapcdn.com/font-awesome/4.2.0/css/font-awesome.min.css', array('type' => 'external'));
}

function hr_portal_preprocess_page(&$vars) {
 drupal_add_library('system', 'ui.accordion');
 drupal_add_js('jQuery(document).ready(function(){jQuery(".accordion").accordion({ collapsible: true, active: false, autoHeight: true});});', 'inline');
}

function hr_portal_menu_link_alter(&$item) {
  if ($item['link_title'] == 'FR' || $item['link_title'] == 'EN') {
    $item['options']['alter'] = true;
  }
}          

function hr_portal_translated_menu_link_alter(&$item, $map) {
  if ($item['link_title'] == 'FR' || $item['link_title'] == 'EN') {
    global $language;
    $languages = language_list('enabled');
    $path = drupal_is_front_page() ? '<front>' : $_GET['q'];
    $links = language_negotiation_get_switch_links('language', $path);
  
    $pick['en'] = 'fr';
    $pick['fr'] = 'en';

    $item['href'] = $links->links[$pick[$language->language]]['href']; 
    
    // add on rest of GETs to path
    $gets = $_GET;
    unset($gets['q']);  // remove q
    if (count($gets)) $item['localized_options']['query'] = $gets;
    
    $item['localized_options']['langcode'] = $pick[$language->language];  
    $item['localized_options']['attributes']['class'][] = 'language-link';      
    $item['localized_options']['attributes']['lang'] = $pick[$language->language]; 
    $item['localized_options']['attributes']['xml:lang'] = $pick[$language->language]; 
    $item['localized_options']['language'] = new stdClass();
    $item['localized_options']['language']->prefix = $languages[1][$pick[$language->language]]->prefix;    
    $item['localized_options']['language']->language = $pick[$language->language];
  }
}

function hr_portal_preprocess_node(&$variables) {
	$node = $variables['node'];
  global $language;

  if ($node->type == 'page' || $node->type == 'landing_page') {
    $fields = array(
      'field_page_related_links',
      'field_page_important_documents',
      'field_page_key_pages',
    );
    foreach ($fields as $field) {
      if (empty($node->{$field}[$language->language])) {
        unset($variables['content'][$field]);
      }
    }
  }
}
