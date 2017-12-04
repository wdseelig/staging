/**
 * @file
 * Javascript, needed for ajax form submit response.
 */

jQuery(document).ready(
  function () {
    jQuery.postMessage(
      {type: 'finish_dialog', form_state: Drupal.settings.popup_forms.form_values},
      Drupal.settings.popup_forms.ref,
      parent
    );
  }
);
