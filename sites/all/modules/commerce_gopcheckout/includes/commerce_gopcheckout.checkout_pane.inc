<?php
/**
 * Implements base_settings_form()
 */
function commerce_gopcheckout_pane_settings_form($checkout_pane) {
  $form['commerce_gopcheckout_pane_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Commerce GOP Checkout Pane Field'),
    '#default_value' => variable_get('commerce_gopcheckout_pane_field', ''),
  );
  return $form;
}
/**
 * Implements base_checkout_form()
 */
 function commerce_gopcheckout_pane_checkout_form($form, $form_state, $checkout_pane, $order) {
  $checkout_form['commerce_gopcheckout_pane_field_display'] = array(
    '#markup' => variable_get('commerce_gopcheckout_pane_field', ''),
  );
  $checkout_form['employed'] = array(
  	'#title' => t('Are you employed?'),
    '#type' => 'radios',
    '#options' => array('yes' => t('Yes'), 'no' => t('No')),
    '#required' => TRUE,
  );
  $checkout_form['employerinfo'] = array(
  	'#title' => t('Employer Information'),
  	'#type' => 'fieldset',
  	'#states' => array (
  		'visible' => array(
  			':input[name="commerce_gopcheckout[employed]"]' => array('value' => 'yes'),
  			),
  		)
  	);
  	$checkout_form['employerinfo']['employername'] = array(
  		'#title' => t('Employer Name'),
  		'#type' => textfield,
  		'#size' => 40,
  		'#maxlength' => 40,
  	);
 		$checkout_form['employer_mailing_address'] = array(
   	 '#type' => 'addressfield',
    	'#title' => t('Employer Mailing Address just added'),
    	'#required' => TRUE,
    	'#default_widget' => 'addressfield_standard',
    	'#default_formatter' => 'addressfield_default',
    	'#default_value' => array('country' => 'US'),
  );
  variable_set("aaa2","Made it into the commerce_gopcheckout_page_checkout_form routine");
 //	kpr ($checkout_form);
 //  kpr ($checkout_pane);
  return $checkout_form;
}
/**
 * Implements base_checkout_form_submit()
 */
function commerce_gopcheckout_pane_checkout_form_submit($form, &$form_state, $checkout_pane, $order) {
  // do something here with 
  // $form_state['values']['my_module_pane_field2']
  variable_set("aaa3","Made it into the commerce_gopcheckout_page_checkout_form_submit routine");
  kpr ($form);
}
