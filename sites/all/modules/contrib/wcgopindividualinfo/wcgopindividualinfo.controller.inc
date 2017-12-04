<?php

/**
 * @file
 * Describe entity and controller custom classes.
 */

/**
 * wcgopindividualinfo class
 */
class wcgopindividualinfo extends Entity {
  /**
   * Define the label of the entity.
   */
  protected function defaultLabel() {
    if (!isset($this->title)) {
      return $this-> FirstName . "  abcde " . $this->LastName;
    }
    return $this->title;
  }

  /**
   * Specify the default uri, which is picked up by uri() by default.
   */
  protected function defaultUri() {
    return array('path' => 'wcgopindividualinfo/' . $this->identifier());
  }
}

/**
 * wcgopindividualinfo controller class.
 */
class wcgopindividualinfoController extends EntityAPIController {
  /**
   * Build a structured array representing the entity's content.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $wrapper = entity_metadata_wrapper('wcgopindividualinfo', $entity);

    // Make "title" and "description" properties themed like default fields.
    $content['title'] = array(
      '#theme' => 'field',
      '#weight' => 0,
      '#title' => t('Tittttle'),
      '#access' => TRUE,
      '#label_display' => 'above',
      '#view_mode' => 'full',
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_title',
      '#field_type' => 'text',
      '#entity_type' => 'wcgopindividualinfo',
      '#bundle' => 'wcgopindividualinfo',
      '#items' => array(array('value' => $wrapper->info_id->value())),
      '#formatter' => 'text_default',
      0 => array('#markup' => check_plain($wrapper->info_id->value())),
    );
    $content['description'] = array(
      '#theme' => 'field',
      '#weight' => 0,
      '#title' => t('Description'),
      '#access' => TRUE,
      '#label_display' => 'above',
      '#view_mode' => 'full',
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#entity_type' => 'wcgopindividualinfo',
      '#bundle' => 'wcgopindividualinfo',
      '#items' => array(array('value' => $wrapper->LastName->value())),
      '#formatter' => 'text_default',
      0 => array('#markup' => check_plain($wrapper->LastName->value())),
    );
    

    return parent::buildContent($entity, $view_mode, $langcode, $content);
  }
}
