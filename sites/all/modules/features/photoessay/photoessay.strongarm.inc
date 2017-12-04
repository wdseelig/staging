<?php
/**
 * @file
 * photoessay.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function photoessay_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_node_gallery_gallery';
  $strongarm->value = 0;
  $export['comment_anonymous_node_gallery_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_node_gallery_item';
  $strongarm->value = 0;
  $export['comment_anonymous_node_gallery_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_node_gallery_gallery';
  $strongarm->value = 1;
  $export['comment_default_mode_node_gallery_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_node_gallery_item';
  $strongarm->value = 1;
  $export['comment_default_mode_node_gallery_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_node_gallery_gallery';
  $strongarm->value = '50';
  $export['comment_default_per_page_node_gallery_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_node_gallery_item';
  $strongarm->value = '50';
  $export['comment_default_per_page_node_gallery_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_node_gallery_gallery';
  $strongarm->value = 1;
  $export['comment_form_location_node_gallery_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_node_gallery_item';
  $strongarm->value = 1;
  $export['comment_form_location_node_gallery_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_node_gallery_gallery';
  $strongarm->value = '2';
  $export['comment_node_gallery_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_node_gallery_item';
  $strongarm->value = '2';
  $export['comment_node_gallery_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_node_gallery_gallery';
  $strongarm->value = '1';
  $export['comment_preview_node_gallery_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_node_gallery_item';
  $strongarm->value = '1';
  $export['comment_preview_node_gallery_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_node_gallery_gallery';
  $strongarm->value = 1;
  $export['comment_subject_field_node_gallery_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_node_gallery_item';
  $strongarm->value = 1;
  $export['comment_subject_field_node_gallery_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__node_gallery_item';
  $strongarm->value = array(
    'teaser' => array(
      'custom_settings' => TRUE,
    ),
    'node_gallery_node_thumbnail' => array(
      'custom_settings' => TRUE,
    ),
    'extra_fields' => array(
      'display' => array(
        'node_gallery_navigation' => array(
          'node_gallery_node_thumbnail' => array(
            'visible' => FALSE,
            'weight' => 1,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
      ),
    ),
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'node_gallery_node_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_node__node_gallery_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_node_gallery_gallery';
  $strongarm->value = '0';
  $export['language_content_type_node_gallery_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_node_gallery_item';
  $strongarm->value = '0';
  $export['language_content_type_node_gallery_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_node_gallery_gallery';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_node_gallery_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_node_gallery_item';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_node_gallery_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_node_gallery_gallery';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_node_gallery_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_node_gallery_item';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_node_gallery_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_node_gallery_gallery';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_node_gallery_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_node_gallery_item';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_node_gallery_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_node_gallery_gallery';
  $strongarm->value = '1';
  $export['node_preview_node_gallery_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_node_gallery_item';
  $strongarm->value = '1';
  $export['node_preview_node_gallery_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_node_gallery_gallery';
  $strongarm->value = 1;
  $export['node_submitted_node_gallery_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_node_gallery_item';
  $strongarm->value = 0;
  $export['node_submitted_node_gallery_item'] = $strongarm;

  return $export;
}
