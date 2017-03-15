<?php

/**
 * @file
 * template.php
 */
function events_preprocess_html(&$variables) {
  drupal_add_css('https://fonts.googleapis.com/css?family=Strait',array('type' => 'external'));
  drupal_add_css('https://fonts.googleapis.com/css?family=Open+Sans:300,400,600,700',array('type' => 'external'));
  drupal_add_css('//netdna.bootstrapcdn.com/font-awesome/4.0.3/css/font-awesome.css', array('type' => 'external'));
  drupal_add_css('https://fonts.googleapis.com/earlyaccess/droidarabickufi.css',array('type' => 'external'));
}

function events_preprocess_page(&$variables) {
  if (arg(2) == 'manage-registration') {
	unset($variables['page']['sidebar_second']);
  }
}

function events_preprocess_views_view_table(&$vars) {
  $vars['classes_array'][] = 'table-bordered table-responsive';
}