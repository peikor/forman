<?php
// $Id: gallery_assist_handler_field_data.inc,v 1.1 2010/03/21 01:36:13 jcmc Exp $

/**
 * @file
 */

class gallery_assist_handler_field_data extends views_handler_field {
  function construct() {
    parent::construct();
  }

  function element_type() {
    return 'span';
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['ga_image_data'] = array(
      '#title' => t('Counter Prefix'),
      '#type' => 'radios',
      '#default_value' => $this->options['ga_image_data'],
      '#options' => array('ptitle' => 'Image-Title', 'pdescription' => 'Image-Description'),
      '#weight' => 4,
      '#size' => 16,
    );
  }

  function render($values) {

    $image_data = db_result(db_query("SELECT ". $this->options['ga_image_data'] ." FROM {gallery_assist_translated} WHERE pid = %d", $values->{$this->field_alias}));
    $output = $image_data;

    return $output;
  }
}

