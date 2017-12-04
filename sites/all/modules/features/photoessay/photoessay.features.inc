<?php
/**
 * @file
 * photoessay.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function photoessay_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function photoessay_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function photoessay_node_info() {
  $items = array(
    'node_gallery_gallery' => array(
      'name' => t('Gallery'),
      'base' => 'node_content',
      'description' => t('A gallery of nodes.'),
      'has_title' => '1',
      'title_label' => t('Gallery Name'),
      'help' => '',
    ),
    'node_gallery_item' => array(
      'name' => t('Gallery Item'),
      'base' => 'node_content',
      'description' => t('A gallery node item.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
