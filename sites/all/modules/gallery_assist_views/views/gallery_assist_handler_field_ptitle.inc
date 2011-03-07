<?php
// $Id: gallery_assist_handler_field_ptitle.inc,v 1.1 2010/09/09 04:52:13 jcmc Exp $

/**
 * @file
 */

class gallery_assist_handler_field_ptitle extends views_handler_field {
  function construct() {
    parent::construct();
  }

  function element_type() {
    return 'span';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['linked_to'] = array('default' => 0);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['linked_to'] = array(
      '#title' => t('Linked to'),
      '#type' => 'select',
      '#options' => array(0 => t('no linked'), 1 => t('node'), 2 => t('image')),
      '#default_value' => $this->options['linked_to'],
      '#weight' => 4,
    );
  }

  function render($values) {
    // Build the output.
    switch ($this->options['linked_to']) {
      case 0:
        $output = $values->{$this->field_alias};
        break;

      case 1:
        $url = "node/{$values->gallery_assist_item_nid}";
        $output = l($values->{$this->field_alias}, $url, array('html' => TRUE));
        break;

      case 2:
        $url = "node/{$values->gallery_assist_item_nid}/{$values->gallery_assist_item_pid}";
        $output = l($values->{$this->field_alias}, $url, array('html' => TRUE));
        break;
    }

    return $output;
  }
}