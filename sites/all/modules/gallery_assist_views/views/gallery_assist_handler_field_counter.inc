<?php
// $Id: gallery_assist_handler_field_counter.inc,v 1.3 2010/09/09 04:50:12 jcmc Exp $

/**
 * @file
 */

class gallery_assist_handler_field_counter extends views_handler_field {
  function construct() {
    parent::construct();
  }

  function element_type() {
    return 'span';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['counter_prefix'] = array('default' => NULL);
    $options['counter_suffix'] = array('default' => NULL);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['counter_prefix'] = array(
      '#title' => t('Counter Prefix'),
      '#type' => 'textfield',
      '#default_value' => $this->options['counter_prefix'],
      '#weight' => 4,
      '#size' => 16,
    );

    $form['counter_suffix'] = array(
      '#title' => t('Counter Suffix'),
      '#type' => 'textfield',
      '#default_value' => $this->options['counter_suffix'],
      '#weight' => 4,
      '#size' => 16,
    );
  }

  function render($values) {

    $count = db_result(db_query("SELECT COUNT(DISTINCT(pid)) FROM {gallery_assist_item} WHERE gref = %d", $values->{$this->field_alias}));
    $output = !empty($this->options['counter_prefix']) ? $this->options['counter_prefix'] : '';
    $output .= $count;
    $output .= !empty($this->options['counter_suffix']) ? $this->options['counter_suffix'] : '';

    return $output;
  }
}

