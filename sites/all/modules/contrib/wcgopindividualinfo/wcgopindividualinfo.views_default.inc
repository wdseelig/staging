<?php

/**
 * @file
 * Views exported from Drupal with "Export" button.
 */

/**
 * Implements hook_views_default_views().
 */
function wcgopindividualinfo_views_default_views() {
  $view = new view();
  $view->name = 'wcgopindividualinfo';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'wcgopindividualinfo';
  $view->human_name = 'WCGOP Individual Information+++';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'WCGOP Individual Information&&&';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view wcgopindividualinfo content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;

  $handler->display->display_options['header']['area']['content'] = '<a href="<?php print url(\'wcgopindividualinfo/add\'); ?>">Add A wcgopindividualinfo entity</a>';

//  $handler->display->display_options['header']['area']['content'] = '<h2>This is just some stuff to go in the header</h2>';
  $handler->display->display_options['header']['area']['format'] = '2';
  /* Field: wcgopindividualinfo info_id */
  $handler->display->display_options['fields']['info_id']['id'] = 'info_id';
  $handler->display->display_options['fields']['info_id']['table'] = 'wcgopindividualinfo';
  $handler->display->display_options['fields']['info_id']['field'] = 'info_id';
  /* Field: wcgopindividualinfo info_id */
  $handler->display->display_options['fields']['info_id']['id'] = 'info_id';
  $handler->display->display_options['fields']['info_id']['table'] = 'wcgopindividualinfo';
  $handler->display->display_options['fields']['info_id']['field'] = 'info_id';
   /* Field: wcgopindividualinfo FirstName */
  $handler->display->display_options['fields']['FirstName']['id'] = 'FirstName';
  $handler->display->display_options['fields']['FirstName']['table'] = 'wcgopindividualinfo';
  $handler->display->display_options['fields']['FirstName']['field'] = 'FirstName';
  /* Field: wcgopindividualinfo LastName */
  $handler->display->display_options['fields']['LastName']['id'] = 'LastName';
  $handler->display->display_options['fields']['LastName']['table'] = 'wcgopindividualinfo';
  $handler->display->display_options['fields']['LastName']['field'] = 'LastName';
  $handler->display->display_options['fields']['LastName_1']['alter']['alter_text'] = TRUE;
	$handler->display->display_options['fields']['LastName_1']['alter']['text'] = '[FirstName]  [LastName]';
	$handler->display->display_options['fields']['LastName_1']['alter']['make_link'] = TRUE;
	$handler->display->display_options['fields']['LastName_1']['alter']['path'] = 'wcgopindividualinfo/[info_id]';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'wcgopindividualinfo';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'wcgopindividualinfomenu';
  $handler->display->display_options['menu']['weight'] = '0';

  $views['wcgopindividualinfo'] = $view;
  return $views;
}
