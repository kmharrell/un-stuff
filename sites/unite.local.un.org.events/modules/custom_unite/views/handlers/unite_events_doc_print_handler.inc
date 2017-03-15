<?php

// This file must be at mymodule/views directory.

/**
 * @file
 * Definition of mymodule_handler_handlername.
 */

/**
 * Description of what my handler does.
 */
class unite_events_doc_print_handler extends views_handler_field {
  /**
   * Add some required fields needed on render().
   */
  function construct() {
    parent::construct();
  }

  function query() {
    // do nothing -- to override the parent query.
  }

  /**
   * Default options form.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['unite_events_print_arg'] = array('default' => '');
    $options['unite_events_document_nid_field'] = array('default' => '');

    return $options;
  }

  /**
   * Creates the form item for the options added.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['unite_events_print_arg'] = array(
      '#title' => t('Views argument representing parent Master Event gid'),
      '#type' => 'select',
      '#options' => array(0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ),
      '#description' => t('This field requires the view to be passed a parent "master event" as an argument. Which argument is it?'),
      '#default_value' => $this->options['unite_events_print_arg'],
    );

    $options = array();
    foreach($this->view->display_handler->handlers['field'] as $key => $value) {
      $options[$key] = $key;
    }
    $form['unite_events_document_nid_field'] = array(
      '#title' => t('Field representing this row\'s document nid'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => $this->options['unite_events_document_nid_field'],
    );
  }

  /**
   * Renders the field handler.
   */
  function render($values) {
    $arg = $this->view->args[$this->options['unite_events_print_arg']];
    if ($event_details = custom_unite_get_event_details($arg)) {
      if (!isset($event_details->field_print_status['und'][0]['value']) || $event_details->field_print_status['und'][0]['value'] != 1 ) {
        return '';
      }
      else {
        $nid_field = $this->options['unite_events_document_nid_field'];
        $nid = $values->$nid_field;
        return l('Print', 'print', array(
          'query' => array(
            'event' => $arg,
            'title' => $nid,
          ),
        ));
      }
    }
  }
}