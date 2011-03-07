<?php
// $Id: gallery_assist_handler_field_cover.inc,v 1.4 2010/09/09 04:50:12 jcmc Exp $

/**
 * @file
 */

class gallery_assist_handler_field_cover extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['opath'] = 'opath';
    $this->additional_fields['tpath'] = 'tpath';
    $this->additional_fields['nid'] = 'nid';
    $this->additional_fields['pid'] = 'pid';
  }

  function element_type() {
    return 'span';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['linked_to'] = array('default' => 0);
    if (module_exists('imagecache')) {
      $options['icformat'] = array('default' => TRUE);
    }
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

    $cPath = $base_path . $values->{$this->aliases['tpath']};
    $iPath = preg_replace('/\/thm\//', '/img/', $cPath);

    if (module_exists('imagecache') && $this->options['icformat'] != 'none') {
      $preset = imagecache_preset($this->options['icformat']);
    }
    else {
      $preset['presetname'] = $this->options['icformat'];
    }

    $data = array(
      'pid' => $values->{$this->field_alias},
      'nid' => $values->{$this->aliases['nid']},
      'img' => $iPath,
      'tpath' => $values->{$this->aliases['tpath']},
      'opath' => $values->{$this->aliases['opath']},
      'ptitle' => $values->gallery_assist_translated_ptitle,
      'palt' => $values->gallery_assist_translated_palt,
      'presetname' => $preset['presetname'],
      'linked_to' => $this->options['linked_to'],
      'type' => $this->options['type'],
    );

    if (is_file($values->{$this->aliases['opath']}) || is_file($values->{$this->aliases['tpath']})) {
      return theme('gallery_assist_display_cover', $data);
    }

  }
}

