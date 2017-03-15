<?php

function custom_unite_views_query_alter(&$view, &$query) {
  if ($view->name == 'media') {
    $query->where[0]['type'] = 'OR';
  }
}
