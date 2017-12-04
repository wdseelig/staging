<?php
/**
 * @file
 * Hooks provided by popup forms module.
 */

/**
 * Defines which forms can be opened in a popup.
 *
 * @return array
 *   Array with popup form IDs as keys and the following arrays as values:
 *   - 'form id': (optional) The unique form identifier. The same that you pass
 *     to drupal_get_form(). If not set, will default to popup form id
 *     (array key).
 *   - 'form arguments': array of form callback arguments (besides $form and
 *     $form_state). Use these arguments in popupFormsFormShow() function.
 *     Keys should correspond to keys passed to popupFormsFormShow(). Values
 *     are default values for these arguments. They will be used if some
 *     parameters are omitted in call to popupFormsFormShow(). Currently only
 *     integer, floating point and string values can be passed to popup form
 *     callbacks.
 *   - 'close_buttons': Names of buttons (#name keys of FAPI elements) which
 *     should close the popup.
 *   - 'file': file which should be included, so form could work correctly.
 *     Usually a file which contains form callback.
 *   - 'access callback': function to check if the user has access to the form.
 *     Same as in hook_menu(). Default value is TRUE (everyone can access).
 *   - 'access arguments': array of arguments to pass into access callback.
 *   - 'autopage': if set to TRUE, then non-javascript page for this form
 *     will be automatically created (useful for users with disabled
 *     javascript). Use popup_forms_build_link() function to generate link to this
 *     page.
 *   - 'title': popup form title. Will show in the header of popup.
 */
function hook_popup_forms_data() {
  return array(
    'test_popup_form_id' => array(
      'form id' => 'actual_form_id',
      'form arguments' => array(
        'param1' => 'default_value1',
        'param2' => array(
          'default value' => 'default_value2',
          'load callback' => 'function_name',
        ),
      ),
      'close_buttons' => array(
        'delete',
        'cancel',
      ),
      // File to be included.
      'file' => drupal_get_path('module', 'my_module') . '/my_module.pages.inc',
      // Same use as in hook_menu().
      'access callback' => 'user_access',
      'access arguments' => array(
        'param1' => 'def_value2',
        'param3' => 'def_value3'
      ),
      'autopage' => TRUE,
      'title' => t('My form'),
    ),
  );
}

/**
 * Allows modules to change popup forms defined by the other modules.
 *
 * @param array $popup_forms
 *   Array of popup forms, returned by all implementations of
 *   hook_popup_forms_data().
 */
function hook_popup_forms_data_alter(&$popup_forms) {
  $forms['test_form_id']['close_buttons'][] = 'back';
}

/**
 * Allows modules to make necessary actions (e.g. add CSS/JS)
 * when popup form loads in popup.
 */
function hook_popup_forms_child_loading() {
  drupal_add_css(drupal_get_path('module', 'my_module') . '/my_module.css');
}
