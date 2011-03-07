<?php
// $Id: gallery_assist_theme.inc,v 1.2 2010/09/09 04:52:13 jcmc Exp $

/**
 * @file
 *
 * Theme preprocessors for gallery_assist plugins.
 */

/**
 * Preprocessor for the Gallery Assist style plugin cover.
 */
function template_preprocess_gallery_assist_display_cover(&$vars) {
  // Build the images.
  if (is_file($vars['view']['opath']) && $vars['view']['tpath']) {
    if (module_exists('imagecache') && $vars['view']['presetname'] != 'none') { // && variable_get('gallery_assist_use_imagecache', FALSE) == 1
      $vars['image'] = theme('imagecache', $vars['view']['presetname'], $vars['view']['opath']);
    }
    else {
      $vars['image'] = '<img src="'. $vars['view']['img'] .'" title="'. $vars['view']['ptitle'] .'" alt="'. $vars['view']['palt'] .'">';
//      theme_image($path, $alt = '', $title = '', $attributes = NULL, $getsize = TRUE)
//      $vars['image'] = theme('image', $vars['view']['img'], '', '',  NULL, TRUE);dsm($vars);
    }
  }

  // Build the output.
  switch ($vars['view']['linked_to']) {
    case 0:
      $output = $vars['image'];
      break;

    case 1:
      $url = 'node/'. $vars['view']['nid'];
      $output = l($vars['image'], $url, array('html' => TRUE));
      break;

    case 2:
      $url = 'node/'. $vars['view']['nid'] .'/'. $vars['view']['pid'];
      $output = l($vars['image'], $url, array('html' => TRUE));
      break;
  }

  // Variable to print.
  $vars['gallery_assist_cover'] = $output;
  drupal_add_css(drupal_get_path('module', 'gallery_assist') .'/css/gallery_assist.css');
}

/**
 * Preprocessor for the Gallery Assist style plugin preview.
 */
function template_preprocess_gallery_assist_display_preview(&$vars) {
  // Build the images.
  if (is_file($vars['view']['opath']) && $vars['view']['ppath']) {
    if (module_exists('imagecache') && $vars['view']['presetname'] != 'none') { // && variable_get('gallery_assist_use_imagecache', FALSE) == 1
      $vars['preview_image'] = theme('imagecache', $vars['view']['presetname'], $vars['view']['opath']);
    }
    else {
      $vars['preview_image'] = theme('image', $vars['view']['ppath']);
    }
  }
}
