Installation and requirements

Popup forms require jquery.postmessage and jquery-deparam plugins.

Download jquery.postmessage at https://github.com/chrissrogers/jquery-postmessage
and place into libraries directory so that the plugin is at
sites/all/libraries/jquery.postmessage/jquery.ba-postmessage.min.js

Download jquery-deparam at https://github.com/chrissrogers/jquery-deparam
and place into libraries directory so that the plugin is at
sites/all/libraries/jquery-deparam/jquery-deparam.min.js

How to use this module

1. Implement hook_popup_forms_data().
  hook must return array of entries, where key is corresponding form id and 
  value is array in following format:

    'test_form_id' => array(
      'form arguments' => array(
        'param1' => 'def_val1',
        'param2' => 'def_val2',
      ),
      // array with buttons names (#name FAPI key), that closes the popup
      'close_buttons' => array('delete', 'cancel'),
      // file needs to be included
      'file' => drupal_get_path('module', 'my_module') . '/my_module.pages.inc',
      // same use as in hook_menu.
      'access callback' => 'user_access',
      'access arguments' => array(
        'param1' => 'def_val2',
        'param3' => 'def_val3'
      ),
      'title' => t('My form'),
    ),

2. Call popup_forms_parent_js() on page, where you want to show popup form.

3. Load popup from JS by calling
  popupFormsFormShow(
    form_id, // Your form_id, declared in hook_popup_forms_data()
    callback, // JS callback (see below)
    form_data, // Keyed form parameters, declared in hook_popup_forms_data()
    dialog_options // JQuery UI dialog options
  );

4. Receive form execution result in your callback. First param of callback 
   function is $form_state values, fetched after form submit.
