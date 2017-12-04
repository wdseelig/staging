<?php 

/**
 * @file
 * Example entity editing UI.
 */

/**
 * Implement the entity adding/editing form.
 * 
 * The entity form must be defined by the function ENTITY_TYPE_form() so that it can be retrieved using entity_ui_get_form(). 
 * You must also implement a submit function for this form.
 * 
 * @see https://drupal.org/node/1021576 - Making use of the admin UI
 */
function entity_example_bundle_form($form, &$form_state, $entity_example, $op = 'edit') {
  if ($op == 'clone') {
    $entity_example->label .= ' (cloned)';
    $entity_example->type .= '_clone';
  }

  $form['label'] = array(
    '#title' => t('Labellll'),
    '#type' => 'textfield',
    '#default_value' => isset($entity_example->label) ? $entity_example->label : '',
  );
  
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($entity_example->type) ? $entity_example->type : '',
    '#machine_name' => array(
      'exists' => 'entity_example_get_bundles',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this entity_example bundle. It must only contain lowercase letters, numbers, and underscores.'),
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save entity'),
    '#weight' => 40,
  );
  kpr($form);
  return $form;
}


function entity_example_form($form, &$form_state, $entity_example, $op = 'edit') {
  drupal_set_title('foo form');
  kpr($form);
  kpr($form_state);
  kpr($entity_example);
  if ($op == 'clone') {
    $entity_example->label .= ' (cloned)';
    $entity_example->type .= '_clone';
  }

  $form['label'] = array(
      '#title' => t('Label'),
      '#type' => 'textfield',
      '#default_value' => isset($entity_example->label) ? $entity_example->label : '',
  );

  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($entity_example->type) ? $entity_example->type : '',
    '#machine_name' => array(
        'exists' => 'entity_example_get_bundles',
        'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this entity_example bundle. It must only contain lowercase letters, numbers, and underscores.'),
  );
  
  $form['note'] = array(
    '#title' => t('Note'),
    '#type' => 'textfield',
    '#default_value' => isset($entity_example->note) ? $entity_example->note : '',
  );  
  
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save entity'),
      '#weight' => 40,
  );
  kpr($form);
  kpr($form_state);
  kpr($entity_example);
  return $form;
}


/**
 * Form API submit callback for the type form.
 */
function entity_example_bundle_form_submit(&$form, &$form_state) {
	kpr($form);
  $entity_example = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  $entity_example->save();
  // Matching bundle entity 'admin ui' -> 'path' on hook_entity_info().
  $form_state['redirect'] = 'admin/structure/entity_example_bundles';
}

/**
 * Form API submit callback for the delete button.
 */
function entity_example_bundle_form_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/entity_example_bundles/manage/' . $form_state['entity_example_bundle']->type . '/delete';
}



/**
 * Form API submit callback for the type form.
 */
function entity_example_form_submit(&$form, &$form_state) {
	kpr($form);
  $entity_example = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  $entity_example->save();
  $form_state['redirect'] = 'admin/structure/entity_example_bundles';
}

/**
 * Form API submit callback for the delete button.
 */
function entity_example_form_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/entity_example_bundles/manage/' . $form_state['entity_example_bundle']->type . '/delete';
}
