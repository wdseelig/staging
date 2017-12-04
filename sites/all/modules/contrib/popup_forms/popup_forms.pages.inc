<?php

/**
 * @file
 * module menu callback ad related functions
 */

/**
 * Page callback for Popup form.
 *
 * Path: ajax-get-popup-form/%
 *
 * @param string $form_id
 *   ID of a form to get.
 *
 * @return string
 *   Rendered form.
 */
function popup_forms_get_ajax_form($form_key) {
  $form_data = popup_forms_get_form_data($form_key);
  // Check popup form existence.
  if ($form_data === FALSE) {
    return MENU_NOT_FOUND;
  }
  // Check access for form.
  elseif (!_popup_forms_check_form_access($form_data)) {
    return MENU_ACCESS_DENIED;
  }
  drupal_set_title($form_data['title']);
  return popup_forms_get_popup_form($form_data);
}

/**
 * Page callback for 'form/%' path.
 */
function popup_forms_form_page($form_id) {
  $form_data = popup_forms_get_form_data($form_id);
  drupal_set_title($form_data['title']);
  return popup_forms_get_popup_form($form_data, FALSE);
}

/**
 * Helper function to build popup form.
 *
 * @param array $form_data
 *   Popup form information, as returned from hook_popup_form_data().
 * @param bool $ajax
 *   Is form fetching via ajax or not.
 *
 * @return string|bool
 *   Rendered form or FALSE if access denied.
 */
function popup_forms_get_popup_form($form_data, $ajax = TRUE) {
  // Include form file.
  if (isset($form_data['file'])) {
    include_once $form_data['file'];
  }
  // Build form.
  $form_state = array();
  $form_state['build_info']['args'] = _popup_forms_get_form_arguments($form_data);
  if (isset($form_data['file'])) {
    $form_state['build_info']['files'][] = $form_data['file'];
  }
  // This flag shows we are inside popup form.
  $form_state['popup_form'] = TRUE;
  $form_state['popup_forms_not_ajax'] = !$ajax;
  $form_state['popup_forms_data'] = $form_data;
  $form = drupal_build_form($form_data['form id'], $form_state);
  $form['#popup_form_state'] = $form_state;
  return $form;
}

/**
 * Gets arguments for popup form callback.
 *
 * @param array $form_info
 *   Array with form info, same as popup_forms_get_form_data() returns.
 *
 * @return array
 *   Array with form arguments.
 */
function _popup_forms_get_form_arguments($form_info) {
  $args = array();
  foreach ($form_info['form arguments'] as $key => $default) {
    if (isset($_GET[$key])) {
      $args[] = !empty($default['load callback']) ? $default['load callback']($_GET[$key]) : $_GET[$key];
    }
    else {
      $default_value = !empty($default['default value']) ? $default['default value'] : '';
      $args[] = !empty($default['load callback']) ? $default['load callback']($default_value) : $default_value;
    }
  }
  return $args;
}
