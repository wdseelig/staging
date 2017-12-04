<?php

/**
 * @file
 * Callbacks for administrating entities.
 */

/**
 * Choose bundle of entity to add.
 * 
 * @return array
 *   Array describing a list of bundles to render.
 */


/**
 * Form constructor for the entity add form.
 * 
 * @param string $type
 *   Bundle of the entity to add.
 * 
 * @return array
 *   Entity edit form.
 */
function wcgopindividualinfo_add() {
  drupal_set_title(t('Create new %type', array('%type' => 'wcgopindividualinfo')));

  // Return form for the given entity bundle.
  $entity = entity_create('wcgopindividualinfo', array('type' => $type));
  $output = entity_ui_get_form('wcgopindividualinfo', $entity);
  return $output;
}

/**
 * Form constructor for "wcgopindividualinfo" entity
 * 
 * This function is necessary for entity_ui_get_form() function.
 * 
 * @see entity_ui_get_form()
 * 
 * @param object $entity
 *   Enity to edit.
 * 
 * @return array
 *   Entity edit form.
 */
function wcgopindividualinfo_edit_wcgopindividualinfo_form($form, &$form_state, $entity) {
  return wcgopindividualinfo_form($form, $form_state, $entity);
}


/**
 * Form constructor for the entity edit form.
 * 
 * In this form we shall manually define all form elements related to editable
 * properties of the entity.
 * 
 * @param object $entity
 *   Enity to edit.
 * 
 * @return array
 *   Entity edit form.
 */
function wcgopindividualinfo_form($form, &$form_state, $entity) {
  // Store the entity in the form.
  $form_state['wcgopindividualinfo'] = $entity;

  // Describe all properties of the entity which shall be shown on the form.
  $wrapper = entity_metadata_wrapper('wcgopindividualinfo', $entity);
  $form['LastName'] = array(
    '#type' => 'textfield',
    '#required' => FALSE,
    '#title' => t('Last Name'),
    '#default_value' => $wrapper->LastName->value(),
    '#weight' => -20,
  );
  $form['FirstName'] = array(
    '#type' => 'textfield',
    '#title' => t('First Name'),
    '#default_value' => $wrapper->FirstName->value(),
    '#weight' => -10,
  );
	$form['info_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Primary Key'),
    '#default_value' => $wrapper->info_id->value(),
    '#weight' => -10,
  );
  // Add some buttons.
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save This Individual'),
    '#weight' => 5,
    '#submit' => array('wcgopindividualinfo_form_submit'),
  );
  if (empty($entity->is_new)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete This Individual'),
      '#weight' => 15,
      '#submit' => array('wcgopindividualinfo_form_submit_delete'),
    );
  }

  return $form;
}
/**
*	Entity "Save as a Contact" handler
*/
function wcgopindividualinfo_form_addtocontacts($form, &$form_state, $entity){
	drupal_set_title(t('WCGOP Contacts System -- Add QVF Entry to Contacts'));
	$result = db_query('SELECT c.contact_id FROM {crm_core_contact} c
			WHERE c.info_id = :infoid',array('infoid' => $entity->info_id));
	if ($result->fetchAll()) {
			$form['body']['#markup'] .= '<h3>This individual is already in the WCGOP
				 Contacts DataBase!</h3>';
			 $form['actions']['submit'] = array(
    			'#type' => 'button',
    			'#value' => t('Go back'),
    			'#name' => 'goback',
    			'#attributes' => array('ONCLICK' => "history.go(-1); return false;"),
			  );
			  $form_state['redirect'] = '';
			}
	else {
		$form['body']['#markup'] .= '<h3> The individual we are adding is:<br> ' .
			'<br>Name: ' . $entity->LastName . ', ' . $entity->FirstName . 
			'<br>Street Address: ' . $entity->PrimaryAddress1 .
			'<br>City and State: ' . $entity->PrimaryCity . ', ' . $entity->PrimaryState .
				', ' . $entity->PrimaryZip . '<br><br>';
			}
			$form['body']['#markup'] .= 'Please click the ' .  "'" . 'Add Contact' . "'" .
				 ' button below if you wish to add this contact.  <br>Click the ' . "'" .
				 'Go Back' . "'" . ' button if you do not wish to do so.<br><br>';
			$form['actions']['submit'][] = array(
    			'#type' => 'submit',
    			'#name' => 'addcontact',
    			'#value' => t('Add Contact'),
    			'#submit' =>array('addtocontactssubmit'),
			  );
			  $form['actions']['submit'][] = array(
    			'#type' => 'button',
    			'#name' => 'goback',
    			'#value' => t('Go Back'),
    			'#attributes' =>array('ONCLICK' => "history.go(-1); return false;"),
			  );
			  $form_state['redirect'] = 'Something';
	return $form;
}
function addtocontactssubmit($form, &$form_state,$form_id){
//	kpr($form);
//	kpr($form_state);
//	die;
	switch($form_state['triggering_element']['#name']) {
		case "goback" :
		$form_state['redirect'] = '/addtocontacts';
		return;
		break;
		case "addcontact" :
		$contact = entity_create('crm_core_contact', array('type'=>'v2individual'));
		$wrapper = entity_metadata_wrapper('crm_core_contact',$contact);
		$wrapper->info_id = $form_state['build_info']['args']['0']->info_id;
		$wrapper->contact_name->given->set($form_state['build_info']
			['args']['0']->FirstName);
		$wrapper->contact_name->family->set($form_state['build_info']
			['args']['0']->LastName);
		$wrapper->save();
		return;
		break;
	}
	$form_state['redirect'] = 'http://www.ncms.org';
	return;
}

/**
 * Entity edit form "Save" submit handler.
 */
function wcgopindividualinfo_form_submit(&$form, &$form_state) {
  // Automatically get edited entity from the form and save it.
  // @see entity_form_submit_build_entity()
  $entity = $form_state['wcgopindividualinfo'];
  entity_form_submit_build_entity('wcgopindividualinfo', $entity, $form, $form_state);
  $wrapper = entity_metadata_wrapper('wcgopindividualinfo', $entity);
  $wrapper->save();

  // Redirect user to edited entity page.
  $entity_uri = entity_uri('wcgopindividualinfo', $entity);
  $form_state['redirect'] = $entity_uri['path'];
}

/**
 * Entity edit form "Delete" submit handler.
 */
function wcgopindividualinfo_form_submit_delete($form, &$form_state) {
  // Redirect user to "Delete" URI for this entity.
  $entity = $form_state['wcgopindividualinfo'];
  $entity_uri = entity_uri('wcgopindividualinfo', $entity);
  $form_state['redirect'] = $entity_uri['path'] . '/delete';
}

/**
 * Form constructor for the entity delete confirmation form.
 * 
 * @param object $entity
 *   Entity to delete.
 * 
 * @return array
 *   Confirmation form.
 */
function wcgopindividualinfo_form_delete($form, &$form_state, $entity) {
  // Store the entity in the form.
  $form_state['wcgopindividualinfo'] = $entity;

  // Show confirm dialog.
  $entity_uri = entity_uri('wcgopindividualinfo', $entity);
  $message = t('Are you sure you want to delete wcgopindividualinfo %title?', array('%title' => entity_label('wcgopindividualinfo', $entity)));
  return confirm_form(
    $form,
    $message,
    $entity_uri['path'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Entity "Confirm delete" form submit handler.
 */
function wcgopindividualinfo_form_delete_submit($form, &$form_state) {
  // Delete the entity.
  $entity = $form_state['wcgopindividualinfo'];
  $wrapper = entity_metadata_wrapper('wcgopindividualinfo', $entity);
  $wrapper->delete();

  // Redirect user.
  drupal_set_message(t('wcgopindividualinfo %title deleted.', array('%title' => entity_label('wcgopindividualinfo', $entity))));
  $form_state['redirect'] = '<front>';
}
