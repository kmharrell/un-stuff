<?php

/**
 * @file
 * i18nviews_handler_sort_taxonomy_term_name class.
 */

/**
 * Sort handler for localized taxonomy terms.
 */
class i18nviews_handler_sort_taxonomy_term_name extends views_handler_sort {

  /**
   * Called to add the sort to a query.
   */
  function query() {
    $langcode = $GLOBALS['language']->language;
    $this->ensure_my_table();

    // Use alias if available (for sort using relationships).
    $left_table = empty($this->table_alias) ? $this->table : $this->table_alias;

    // Join with i18n_string table.
    $i18n_string_join = new views_join();
    $i18n_string_join->table = 'i18n_string';
    $i18n_string_join->left_table = $left_table;
    $i18n_string_join->left_field = 'tid';
    $i18n_string_join->field = 'objectid';
    $i18n_string_join->type = 'LEFT';
    $i18n_string_join->extra_type = 'AND';
    $i18n_string_join->extra = array(
      array(
        'field' => 'textgroup',
        'value' => 'taxonomy',
      ),
      array(
        'field' => 'type',
        'value' => 'term',
      ),
      array(
        'field' => 'property',
        'value' => 'name',
      ),
    );
    $i18n_string = $this->query->add_relationship('term_i18n_string', $i18n_string_join, $left_table);

    // Join with locales_target to get translated value.
    $locales_target_join = new views_join();
    $locales_target_join->table = 'locales_target';
    $locales_target_join->left_table = $i18n_string;
    $locales_target_join->left_field = 'lid';
    $locales_target_join->field = 'lid';
    $locales_target_join->type = 'LEFT';
    $locales_target_join->extra = array(
      array(
        'field' => 'language',
        'value' => $langcode,
      ),
    );
    $locales_target = $this->query->add_relationship('term_i18n_string_translation', $locales_target_join, $i18n_string);

    //  Order by translated value.
    $this->query->add_orderby($locales_target, 'translation', $this->options['order']);
  }
}
