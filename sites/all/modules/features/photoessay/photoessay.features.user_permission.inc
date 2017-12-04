<?php
/**
 * @file
 * photoessay.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function photoessay_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create node_gallery_gallery content'.
  $permissions['create node_gallery_gallery content'] = array(
    'name' => 'create node_gallery_gallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create node_gallery_item content'.
  $permissions['create node_gallery_item content'] = array(
    'name' => 'create node_gallery_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any node_gallery_gallery content'.
  $permissions['delete any node_gallery_gallery content'] = array(
    'name' => 'delete any node_gallery_gallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any node_gallery_item content'.
  $permissions['delete any node_gallery_item content'] = array(
    'name' => 'delete any node_gallery_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own node_gallery_gallery content'.
  $permissions['delete own node_gallery_gallery content'] = array(
    'name' => 'delete own node_gallery_gallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own node_gallery_item content'.
  $permissions['delete own node_gallery_item content'] = array(
    'name' => 'delete own node_gallery_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any node_gallery_gallery content'.
  $permissions['edit any node_gallery_gallery content'] = array(
    'name' => 'edit any node_gallery_gallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any node_gallery_item content'.
  $permissions['edit any node_gallery_item content'] = array(
    'name' => 'edit any node_gallery_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own node_gallery_gallery content'.
  $permissions['edit own node_gallery_gallery content'] = array(
    'name' => 'edit own node_gallery_gallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own node_gallery_item content'.
  $permissions['edit own node_gallery_item content'] = array(
    'name' => 'edit own node_gallery_item content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
