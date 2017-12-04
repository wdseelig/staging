<?php


/*
 *  Implements callback_entity_info_label
 */

function vtsentity_label_callback($entity){
    return ("VTSInterval " . $entity->id);
}


/**
 * Access callback for vtsinterval entities.
 */
function vtsentity_access_callback($op, $vtsinterval = NULL, $account = NULL) {
  if ($op == 'view' || $op == 'update' || $op == 'create' || $op == 'delete') {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 * Callback function for our vtsentity entities test path
 */
function vtsentity_vtsintervals() {
  
  
  $vtsintervals = entity_load('vtsinterval', array(1, 2, 3));
  
  $myinfo = entity_get_info('vtsinterval');
  $a = 1;
  
  // Saving new entities 
  if (!isset($vtsintervals[1])) {
    $entity = entity_create('vtsinterval', array('id' => 1));
    $entity->EventID = 1550;
    $entity->EventDay = 155200;
    $entity->timestart = 1437062400;
    $entity->timeend = 1437066000;
    $entity->save();
  }
  
  // Listing entities
  $list = entity_view('vtsinterval', $vtsintervals);
  
  $output = array();
  foreach ($list['vtsinterval'] as $vtsinterval) {
      $vtsinterval->handle1 = "Does this work at all?";
    $output[] = drupal_render($vtsinterval);
  }
  
  return implode($output);

}

/**
 * Callback function for displaying the individual vtsinterval page
 */
function vtsentity_view_vtsinterval($id) {
  
  $vtsintervals = entity_load('vtsinterval', array($id));
  $vtsinterval = $vtsintervals[$id];
  
  drupal_set_title("This is a view of vtsinterval number: " . $id);
  $output = entity_view('vtsinterval', array($vtsinterval));
  
  return $output;
  
}

/**
 * Form definition for adding / editing a vtsinterval.
 */
function vtsinterval_form($form, &$form_state, $vtsinterval = NULL) {
  
  $result = db_query("
    	SELECT title,nid FROM {node}
        WHERE type = :volevent",array(':volevent'=> 'volunteertimeslotevent'));
    $values = array();
    foreach ($result as $row){
        $key = $row->nid;
   	$values[$key] = $row->title;
    }
    
    $form['EventID'] = array(
    '#title' => t('Event to which this interval is attached'),
    '#type' => 'select',
    '#options' => $values,
    '#default_value' => isset($vtsinterval->EventID) ? $vtsinterval->EventID : '',   
    '#required' => TRUE,
  );
    
    $result = db_query("
    	SELECT title,nid FROM {node}
        WHERE type = :voleventday",array(':voleventday'=> 'volunteertimesloteventday'));
    $values = array();
    foreach ($result as $row){
        $key = $row->nid;
   	$values[$key] = $row->title;
    }
   

  $form['EventDay'] = array(
    '#title' => t('The day to which this interval is attached'),
    '#type' => 'select',
    '#options' => $values,
    '#default_value' => isset($vtsinterval->EventDay) ? $vtsinterval->EventDay : '',
    '#required' => TRUE,
  );

  $form['timestart'] = array(
    '#title' => t('The start time for this Interval'),
    '#type' => 'date_popup',
//    '[#date][#value]' => date('Y-m-d H:i', $vtsinterval->timestart), 
//    '#date_format' => 'm/d/Y',
//    'date' => '06/01/2017',
    '#default_value' => isset($vtsinterval->timestart) ? date('Y-m-d H:i', $vtsinterval->timestart) : '',
//      '#default_value' => date('Y-m-d H:i', $vtsinterval->timestart), 
//      '#default_value' => date('Y-m-d H:i', '1437055260'),
    '#required' => TRUE,
  );  
  $form['timeend'] = array(
      '#title' => t('The end time for this INterval'),
      '#type' => 'date_popup',
      '#default_value' => isset($vtsinterval->timeend) ? date('Y-m-d H:i', $vtsinterval->timeend) : '',
      '#required' => TRUE,
      );
  $form['handle1'] = array(
      '#title' => t('The first handle'),
      '#type' => 'textfield',
      '#default_value' => isset($vtsinterval->handle1) ? $vtsinterval->handle1 : 'Open',
      '#required' => FALSE,
  );
  $form['handle2'] = array(
      '#title' => t('The second handle'),
      '#type' => 'textfield',
      '#default_value' => isset($vtsinterval->handle1) ? $vtsinterval->handle2 : '',
      '#required' => FALSE,
  );
  $form['handle3'] = array(
      '#title' => t('The third handle'),
      '#type' => 'textfield',
      '#default_value' => isset($vtsinterval->handle3) ? $vtsinterval->handle3 : '',
      '#required' => FALSE,
  );
  $form['handle4'] = array(
      '#title' => t('The fourth handle'),
      '#type' => 'textfield',
      '#default_value' => isset($vtsinterval->handle4) ? $vtsinterval->handle4 : '',
      '#required' => FALSE,
  );
  $form['handle5'] = array(
      '#title' => t('The fifth handle'),
      '#type' => 'textfield',
      '#default_value' => isset($vtsinterval->handle5) ? $vtsinterval->handle5 : '',
      '#required' => FALSE,
  );
  
  field_attach_form('vtsinterval', $vtsinterval, $form, $form_state);
  
  $form['submit'] = array(
    '#type' => 'submit', 
    '#value' => isset($vtsinterval->id) ? t('Update interval') : t('Save interval'),
    '#weight' => 50,
  );

  return $form;
}

/**
 * Submit handler for the vtsinterval add/edit form.
 */
function vtsinterval_form_submit($form, &$form_state) {
  $vtsinterval = entity_ui_form_submit_build_entity($form, $form_state);
  $timestampstart = strtotime($form['timestart']['#value'][date] . " " . $form['timestart']['#value'][time]);
  $vtsinterval->timestart = $timestampstart;
  $timestampend = strtotime($form['timeend']['#value'][date] . " " . $form['timeend']['#value'][time]);
  $vtsinterval->timeend = $timestampend;
  $vtsinterval->save();
  drupal_set_message(t('The interval: @id has been saved.', array('@id' => $vtsinterval->id)));
  $form_state['redirect'] = 'admin/vtsintervals';
}




/**
 * Extending the EntityAPIController for the vtsinterval entity.
 */
class vtsintervalEntityController extends EntityAPIController {
  
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {

    $build = parent::buildContent($entity, $view_mode, $langcode, $content);
    
    // Our additions to the $build render array.
    $build['EntityID'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->EntityID),
      '#prefix' => '<div class="vtsentity-id">',
      '#suffix' => '</div>',
    );
    $build['EventDay'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->EventDay),
      '#prefix' => '<div class="vtsentity-day">',
      '#suffix' => '</div>',
    );
    
    $build['timestart'] = array(
        '#type' => 'markup',
        '#markup' => check_plain($entity->timestart),
        '#prefix' => '<div class="vtsentity-timestart">',
        '#suffix' => '</div>',
    );
     
    $build['timeend'] = array(
        '#type' => 'markup',
        '#markup' => date('m/d Y g:i A', check_plain($entity->timeend)),
        '#prefix' => '<div class="vtsentity-timeend">',
        '#suffix' => '</div>',
    );
    
    $build['handle1'] = array(
        '#type' => 'markup',
        '#markup' => check_plain($entity->handle1),
        '#prefix' => '<div class="vtshandle1">',
        '#suffix' => '</div>',    
    );
    $build['handle2'] = array(
        '#type' => 'markup',
        '#markup' => check_plain($entity->handle2),
        '#prefix' => '<div class="vtshandle2">',
        '#suffix' => '</div>',    
    );
    $build['handle3'] = array(
        '#type' => 'markup',
        '#markup' => check_plain($entity->handle3),
        '#prefix' => '<div class="vtshandle3">',
        '#suffix' => '</div>',    
    );
    $build['handle4'] = array(
        '#type' => 'markup',
        '#markup' => check_plain($entity->handle4),
        '#prefix' => '<div class="vtshandle4">',
        '#suffix' => '</div>',    
    );
    $build['handle5'] = array(
        '#type' => 'markup',
        '#markup' => check_plain($entity->handle5),
        '#prefix' => '<div class="vtshandle5">',
        '#suffix' => '</div>',    
    );
    return $build;
  
  }
  
}
  
/**
 * vtsinterval entity class extending the Entity class
 */
class vtsintervalEntity extends Entity {
  
  /**
   * Change the default URI from default/id to vtsinterval/id
   */
  protected function defaultUri() {
    return array('path' => 'vtsinterval/' . $this->identifier());
  }
  
}


