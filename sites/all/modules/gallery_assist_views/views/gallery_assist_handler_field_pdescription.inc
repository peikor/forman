<?php
// $Id: gallery_assist_handler_field_pdescription.inc,v 1.1 2010/09/09 04:52:13 jcmc Exp $

/**
 * @file
 */

class gallery_assist_handler_field_pdescription extends views_handler_field {
  function construct() {
    parent::construct();
//    $this->additional_fields['pid'] = 'pid';
  }

  function element_type() {
    return 'span';
  }

  function render($values) {
    //dsm($values->{$this->field_alias});
    //return $this->fiels_alias;
    return $values->{$this->field_alias};
  }
}