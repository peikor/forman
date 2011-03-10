<?php
// $Id: gallery_assist_handler_field_pid.inc,v 1.1 2010/09/09 04:52:13 jcmc Exp $
/**
 * @file
 */

class gallery_assist_handler_field_pid extends views_handler_field {
  /**
   * Constructor to provide additional field to add.
   */
  function construct() {
    parent::construct();
    $this->additional_fields['pid'] = array('table' => 'gallery_assist_item', 'field' => 'pid');
  }

  function render($values) {
    return $values->{$this->field_alias};
  }
}