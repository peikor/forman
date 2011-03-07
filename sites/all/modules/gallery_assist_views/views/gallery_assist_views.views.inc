<?php
// $Id: gallery_assist_views.views.inc,v 1.4 2010/09/09 04:50:12 jcmc Exp $

/**
 * @file
 */

/**
 * Implementation of hook_views_data().
 */
function gallery_assist_views_views_data() {
  $data = array();
  
  // Table: gallery_assist.
  $data['gallery_assist']['table']['group']  = t('Gallery_assist');
  $data['gallery_assist']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['gallery_assist']['in_profile'] = array(
    'group' => t('Gallery Assist'),
    'title' => t('In profile'),
    'help' => t('If TRUE the gallery will be listed in the user profile.'),
    'real field' => 'in_profile',
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Table: gallery_assist_item.
  $data['gallery_assist_item']['table']['group']  = t('Gallery Assist');
  $data['gallery_assist_item']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
    'gallery_assist' => array(
      'left_field' => 'gref',
      'field' => 'gref',
    ),
    'gallery_assist_translated' => array(
      'left_field' => 'pid',
      'field' => 'pid',
    ),
    'user' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
    'files' => array(
      'left_field' => 'fid',
      'field' => 'fid',
    ),
  );

  // Integer: relation reference ID.
  $data['gallery_assist_item']['nid'] = array(
    'title' => t('Gallery Assist'),
    'help' => t('"nid" the relation field between gallery_assist_item and node table.'),
    'relationship' => array(
      'base' => 'node',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Gallery Assist'),
    ),
  );

  $data['gallery_assist_item']['pid'] = array(
    'group' => t('Gallery Assist'),
    'title' => t('Pid'),
    'help' => t('The Pid of the gallery image'),
    'field' => array(
      'handler' => 'gallery_assist_handler_field_pid',
    ),
    'argument' => array(
      'handler' => 'gallery_assist_handler_argument_pid',
    ),
// 
//    'argument' => array(
//      'handler' => 'gallery_assist_handler_argument_pid',
//      'parent' => 'views_handler_argument_numeric', // make sure parent is included
//      'name field' => 'ga_ptitle', // the field to display in the summary.
//      'numeric' => TRUE,
//      'validate type' => 'nid',
//    ),
  );

  $data['gallery_assist_item']['cover'] = array(
    'group' => t('Gallery Assist'),
    'title' => t('Image'),
    'help' => t('Gallery cover'),
    'real field' => 'pid',
    'field' => array(
      'handler' => 'gallery_assist_handler_field_cover',
    ),
  );

  $data['gallery_assist_item']['preview'] = array(
    'group' => t('Gallery Assist'),
    'title' => t('Preview Image'),
    'help' => t('The preview image'),
    'real field' => 'pid',
    'field' => array(
      'handler' => 'gallery_assist_handler_field_preview',
    ),
  );

  $data['gallery_assist_item']['is_cover'] = array(
    'group' => t('Gallery Assist'),
    'title' => t('Is cover'),
    'help' => t('Gallery cover'),
    'real field' => 'cover',
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['gallery_assist_item']['copyright'] = array(
    'group' => t('Gallery Assist'),
    'title' => t('Copyright'),
    'help' => t('Image copyright'),
    'real field' => 'copyright',
    'field' => array(
      'handler' => 'gallery_assist_handler_field_copyright',
      'click sortable' => TRUE,
     ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['gallery_assist_item']['counter'] = array(
    'group' => t('Gallery Assist'),
    'title' => t('Counter'),
    'help' => t('Amount of images in the gallery.'),
    'real field' => 'gref',
    'field' => array(
      'handler' => 'gallery_assist_handler_field_counter',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['gallery_assist_item']['download_link'] = array(
    'group' => t('Gallery Assist'),
    'title' => t('Download'),
    'help' => t('Render the download link from the original image.'),
    'real field' => 'opath',
    'field' => array(
      'handler' => 'gallery_assist_handler_field_download_link',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Table: gallery_assist_translated.
  $data['gallery_assist_translated']['table']['group']  = t('Gallery_assist');
  $data['gallery_assist_translated']['table']['join'] = array(
    'node' => array(
      'left_table' => 'gallery_assist_item',
      'left_field' => 'pid',
      'field' => 'pid',
    ),
  );

  $data['gallery_assist_translated']['ptitle'] = array(
    'group' => t('Gallery Assist'),
    'title' => t('Image title'),
    'help' => t('Image title'),
    'real field' => 'ptitle',
    'field' => array(
      'handler' => 'gallery_assist_handler_field_ptitle',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['gallery_assist_translated']['palt'] = array(
    'group' => t('Gallery Assist'),
    'title' => t('Image-Alt'),
    'help' => t('Image alternative text.'),
    'real field' => 'palt',
    'field' => array(
      'handler' => 'gallery_assist_handler_field_palt',
//      'click sortable' => TRUE,
    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
  );

  $data['gallery_assist_translated']['pdescription'] = array(
    'group' => t('Gallery Assist'),
    'title' => t('Image description'),
    'help' => t('Image description'),
    'real field' => 'pdescription',
    'field' => array(
      'handler' => 'gallery_assist_handler_field_pdescription',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

/**
 *
 */
function gallery_assist_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'gallery_assist_views') . '/views',
    ),
    'handlers' => array(
      'gallery_assist_handler_field_pid' => array(
        'parent' => 'views_handler_field',
      ),
      'gallery_assist_handler_argument_pid' => array(
        'parent' => 'views_handler_argument_numeric',
      ),
      'gallery_assist_handler_field_cover' => array(
        'parent' => 'views_handler_field',
      ),
      'gallery_assist_handler_field_preview' => array(
        'parent' => 'views_handler_field',
      ),
      'gallery_assist_handler_field_counter' => array(
        'parent' => 'views_handler_field',
      ),
      'gallery_assist_handler_field_download_link' => array(
        'parent' => 'views_handler_field',
      ),
      'gallery_assist_handler_field_ptitle' => array(
        'parent' => 'views_handler_field',
      ),
      'gallery_assist_handler_field_palt' => array(
        'parent' => 'views_handler_field',
      ),
      'gallery_assist_handler_field_pdescription' => array(
        'parent' => 'views_handler_field',
      ),
      'gallery_assist_handler_field_copyright' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_plugins
 */
function gallery_assist_views_plugins() {
  global $base_path;
  return array(
    'style' => array(
      'gallery_assist_preview' => array(
        'title'  => 'Gallery Assist Preview',
        'help' => t('Displays the preview preset from a gallery image.'),
        'handler' => 'views_plugin_style_table',
        'theme path' => drupal_get_path('module', 'gallery_assist_views') . '/views/themes',
        'theme file' => 'gallery_assist_theme.inc',
        'theme' => 'gallery_assist_display_preview',
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'no ui' => TRUE,
        'help topic' => 'gallery-assist-views',
      ),
      'gallery_assist_cover' => array(
        'title'  => 'Gallery Assist Cover',
        'help' => t('Displays the gallery cover of Gallery Assist galleries.'),
        'handler' => 'views_plugin_style_table',
        'theme path' => drupal_get_path('module', 'gallery_assist_views') . '/views/themes',
        'theme file' => 'gallery_assist_theme.inc',
        'theme' => 'gallery_assist_display_cover',
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'no ui' => TRUE,
        'help topic' => 'gallery-assist-views',
      ),

    ),
  );
}
