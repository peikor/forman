<?php
// $Id: gallery_assist_handler_argument_pid.inc,v 1.1 2010/09/09 04:52:12 jcmc Exp $
/**
 * @file
 */

class gallery_assist_handler_argument_pid extends views_handler_argument_numeric {
  /**
   * Constructor to provide additional field to add.
   */
  function construct() {
    parent::construct();
    $this->additional_fields['pid'] = array('table' => 'gallery_assist_item', 'field' => 'pid');
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['default_argument_type']['#options']['pid'] = t('GA-Pid from the url.');
  }

  function render($values) {
    return $values->{$this->field_alias};
//    return $this->render_link(check_plain($values->{$this->field_alias}), $values);
  }
}
