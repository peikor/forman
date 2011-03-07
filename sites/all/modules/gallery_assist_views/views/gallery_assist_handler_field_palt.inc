<?php
// $Id: gallery_assist_handler_field_palt.inc,v 1.1 2010/09/09 04:52:13 jcmc Exp $

/**
 * @file
 */

class gallery_assist_handler_field_palt extends views_handler_field {
  function construct() {
    parent::construct();
//    $this->additional_fields['palt'] = 'palt';
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