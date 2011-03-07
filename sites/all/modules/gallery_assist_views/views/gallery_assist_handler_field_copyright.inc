<?php
// $Id: gallery_assist_handler_field_copyright.inc,v 1.1 2010/09/09 04:52:13 jcmc Exp $

/**
 * @file
 */

class gallery_assist_handler_field_copyright extends views_handler_field {
  function construct() {
    parent::construct();
  }

  function element_type() {
    return 'span';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link_it'] = array('default' => FALSE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['link_it'] = array(
      '#type' => 'checkbox',
      '#title' => t('Link it'),
      '#description' => t('Enable a url filter. Is the text a url build a hyperlink.'),
      '#default_value' => $this->options['link_it'],
      '#weight' => 4,
    );

  }

  function render($values) {
    $output = $this->options['link_it'] ?  _filter_html(_filter_url($values->{$this->field_alias}, 1), 1) : $values->{$this->field_alias};

    return $output;
  }
}