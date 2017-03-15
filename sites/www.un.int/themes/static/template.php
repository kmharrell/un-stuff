<?php

/**
 * @file template.php
 */
function static_preprocess_page(&$variables) {
  if (arg(0) != 'info' && arg(0) != 'user' && !(arg(0) == 'node' && arg(1) == '82') ) {
	$domain = domain_get_domain();
	if($domain['domain_id'] == 1):
	  drupal_goto('main');
	endif;
  }
}
/*
function static_preprocess_html(&$variables) {
   $domain = domain_get_domain();
  $filename = 'domain-' . $domain['machine_name'] . '.css';
  drupal_add_css(path_to_theme() . '/css/' . $filename);  
  
}
*/