<?php

/**
 * @file
 * Callbacks for viewing entities.
 */

/**
 * Show list of existing entities.
 */
function wcgopindividualinfo_list() {
  drupal_set_title(t('This is a listing of our individual information'));

  // Show link to the entity "Add" page.
  $output = '<br/>';
  $output .= theme_link(
    array(
      'text' => t('Add new individual information'),
      'path' => 'wcgopindividualinfo/add',
      'options' => array(
        'attributes' => array(),
        'html' => TRUE,
      ),
    )
  );

  // Show list of existing entities.
  $entities = entity_load('wcgopindividualinfo');
  $items = array();
  foreach ($entities as $entity) {
    $entity_uri = entity_uri('wcgopindividualinfo', $entity);
    $items[] = l(entity_label('wcgopindividualinfo', $entity), $entity_uri['path']);
//			$items[] = l('This is just something to see', $entity_uri['path']);
  }
  $output .= theme_item_list(
    array(
      'items' => $items,
      'title' => t('List of existing entities.'),
      'type' => 'ul',
      'attributes' => array(),
    )
  );

  return $output;
}

/**
 * Entity view callback.
 * 
 * @param object $entity
 *   Entity to view.
 * 
 * @return array
 *   Renderable array.
 */
function wcgopindividualinfo_view($entity) {
  drupal_set_title(entity_label('wcgopindividualinfo', $entity));

  // Return automatically generated view page.
  return entity_view(
    'wcgopindividualinfo',
    array(entity_id('wcgopindividualinfo', $entity) => $entity),
    'full'
  );
}
