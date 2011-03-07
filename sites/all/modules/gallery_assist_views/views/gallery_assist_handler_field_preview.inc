<?php
// $Id: gallery_assist_handler_field_preview.inc,v 1.1 2010/09/09 04:52:13 jcmc Exp $

/**
 * @file
 */

class gallery_assist_handler_field_preview extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['opath'] = 'opath';
    $this->additional_fields['ppath'] = 'ppath';
    $this->additional_fields['nid'] = 'nid';
    $this->additional_fields['pid'] = 'pid';
    $this->additional_fields['type'] = array('table' => 'node', 'field' => 'type');
    $this->additional_fields['ptitle'] = array('table' => 'gallery_assist_translated', 'field' => 'ptitle');
    $this->additional_fields['palt'] = array('table' => 'gallery_assist_translated', 'field' => 'palt');
  }

  function element_type() {
    return 'span';
  }

  function option_definition() {
    $options = parent::option_definition();
    if (module_exists('imagecache')) {
      $options['icformat'] = array('default' => TRUE);
    }
    
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    if (module_exists('imagecache')) {
      $ic_presets = imagecache_presets();
      $presets = array('none' => 'none');
      foreach ($ic_presets as $k => $v) {
        $presets[$k] = $v['presetname'];
      }

      $form['icformat'] = array(
        '#title' => t('Format'),
        '#type' => 'select',
        '#options' => $presets,
        '#default_value' => $this->options['icformat'],
        '#weight' => 4,
      );
    }
  }

  function render($values) {
    global $base_path;

    $cPath = $base_path . $values->{$this->aliases['ppath']};
    $iPath = preg_replace('/\/prev\//', '/img/', $cPath);

    if (module_exists('imagecache') && $this->options['icformat'] != 'none') {
      $preset = imagecache_preset($this->options['icformat']);
    }
    else {
      $preset['presetname'] = $this->options['icformat'];
    }

    $data = array(
      'pid' => $values->{$this->aliases['pid']},
      'nid' => $values->{$this->aliases['nid']},
      'img' => $iPath,
      'ppath' => $values->{$this->aliases['ppath']},
      'opath' => $values->{$this->aliases['opath']},
      'ptitle' => $values->gallery_assist_translated_ptitle,
      'palt' => $values->gallery_assist_translated_palt,
      'presetname' => $preset['presetname'],
      'type' => $values->node_type,
    );

    return theme('gallery_assist_display_preview', $data);
  }
}

