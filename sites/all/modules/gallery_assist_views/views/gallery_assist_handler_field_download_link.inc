<?php
// $Id: gallery_assist_handler_field_download_link.inc,v 1.1 2010/09/09 04:52:13 jcmc Exp $

/**
 * @file
 */

class gallery_assist_handler_field_download_link extends views_handler_field {
  function construct() {
    parent::construct();
//    $this->additional_fields['palt'] = 'palt';
  }

  function element_type() {
    return 'span';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['use_grafik'] = array('default' => FALSE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['use_grafik'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use graphic links'),
      '#description' => t('Overwrite the link text with a graphic.'),
      '#default_value' => $this->options['use_grafik'],
      '#weight' => 4,
    );

  }

  function render($values) {
    $link = l(t('Download original'), $values->{$this->field_alias});
    $output = $this->options['use_grafik'] ? gallery_assist_build_div($link, 'graph-download-link') : $link;

    return $output;
  }
}