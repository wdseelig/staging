<?php
/*
*	Implementation of hook_views_default_views
*/
function volunteertimeslots_views_default_views () {
	
	$view = new view();
$view->name = 'VTSViews';
$view->description = 'Views to display various parts of the Volunteer Time Slots data';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'VTSViews';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '[field_eventimage]<br><br>
[body]';
$handler->display->display_options['header']['area']['format'] = '3';
$handler->display->display_options['header']['area']['tokenize'] = TRUE;
/* Relationship: Entity Reference: Referenced Entity */
$handler->display->display_options['relationships']['field_vtsevent_target_id']['id'] = 'field_vtsevent_target_id';
$handler->display->display_options['relationships']['field_vtsevent_target_id']['table'] = 'field_data_field_vtsevent';
$handler->display->display_options['relationships']['field_vtsevent_target_id']['field'] = 'field_vtsevent_target_id';
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content: EventImage */
$handler->display->display_options['fields']['field_eventimage']['id'] = 'field_eventimage';
$handler->display->display_options['fields']['field_eventimage']['table'] = 'field_data_field_eventimage';
$handler->display->display_options['fields']['field_eventimage']['field'] = 'field_eventimage';
$handler->display->display_options['fields']['field_eventimage']['relationship'] = 'field_vtsevent_target_id';
$handler->display->display_options['fields']['field_eventimage']['label'] = '';
$handler->display->display_options['fields']['field_eventimage']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_eventimage']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_eventimage']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_eventimage']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
/* Field: Content: vtsevent */
$handler->display->display_options['fields']['field_vtsevent_1']['id'] = 'field_vtsevent_1';
$handler->display->display_options['fields']['field_vtsevent_1']['table'] = 'field_data_field_vtsevent';
$handler->display->display_options['fields']['field_vtsevent_1']['field'] = 'field_vtsevent';
$handler->display->display_options['fields']['field_vtsevent_1']['group_type'] = 'count_distinct';
$handler->display->display_options['fields']['field_vtsevent_1']['label'] = '';
$handler->display->display_options['fields']['field_vtsevent_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_vtsevent_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_vtsevent_1']['type'] = 'entityreference_entity_id';
$handler->display->display_options['fields']['field_vtsevent_1']['settings'] = array(
  'link' => 0,
);
$handler->display->display_options['fields']['field_vtsevent_1']['group_column'] = 'entity_id';
/* Field: Content: vtsstarttime */
$handler->display->display_options['fields']['field_vtsstarttime']['id'] = 'field_vtsstarttime';
$handler->display->display_options['fields']['field_vtsstarttime']['table'] = 'field_data_field_vtsstarttime';
$handler->display->display_options['fields']['field_vtsstarttime']['field'] = 'field_vtsstarttime';
$handler->display->display_options['fields']['field_vtsstarttime']['label'] = '';
$handler->display->display_options['fields']['field_vtsstarttime']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_vtsstarttime']['alter']['text'] = '<h2>[field_vtsstarttime]</h2>';
$handler->display->display_options['fields']['field_vtsstarttime']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_vtsstarttime']['alter']['path'] = 'vts_schedule/[field_vtsevent_1]/[nid]';
$handler->display->display_options['fields']['field_vtsstarttime']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_vtsstarttime']['settings'] = array(
  'format_type' => 'volunteereventdayv2',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
/* Sort criterion: Content: vtsstarttime (field_vtsstarttime) */
$handler->display->display_options['sorts']['field_vtsstarttime_value']['id'] = 'field_vtsstarttime_value';
$handler->display->display_options['sorts']['field_vtsstarttime_value']['table'] = 'field_data_field_vtsstarttime';
$handler->display->display_options['sorts']['field_vtsstarttime_value']['field'] = 'field_vtsstarttime_value';
/* Contextual filter: Content: vtsevent (field_vtsevent) */
$handler->display->display_options['arguments']['field_vtsevent_target_id']['id'] = 'field_vtsevent_target_id';
$handler->display->display_options['arguments']['field_vtsevent_target_id']['table'] = 'field_data_field_vtsevent';
$handler->display->display_options['arguments']['field_vtsevent_target_id']['field'] = 'field_vtsevent_target_id';
$handler->display->display_options['arguments']['field_vtsevent_target_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_vtsevent_target_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_vtsevent_target_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_vtsevent_target_id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'volunteertimesloteventday' => 'volunteertimesloteventday',
);
/* Filter criterion: Content: vtsstarttime (field_vtsstarttime) */
$handler->display->display_options['filters']['field_vtsstarttime_value']['id'] = 'field_vtsstarttime_value';
$handler->display->display_options['filters']['field_vtsstarttime_value']['table'] = 'field_data_field_vtsstarttime';
$handler->display->display_options['filters']['field_vtsstarttime_value']['field'] = 'field_vtsstarttime_value';
$handler->display->display_options['filters']['field_vtsstarttime_value']['value']['value'] = '2016';
$handler->display->display_options['filters']['field_vtsstarttime_value']['granularity'] = 'year';
$handler->display->display_options['filters']['field_vtsstarttime_value']['year_range'] = '-0:+0';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<font color="red">[title]</font>
[field_eventimage]<br><br>
[body]
[field_eventcoordinator]<br>';
$handler->display->display_options['header']['area']['format'] = '3';
$handler->display->display_options['header']['area']['tokenize'] = TRUE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content: EventImage */
$handler->display->display_options['fields']['field_eventimage']['id'] = 'field_eventimage';
$handler->display->display_options['fields']['field_eventimage']['table'] = 'field_data_field_eventimage';
$handler->display->display_options['fields']['field_eventimage']['field'] = 'field_eventimage';
$handler->display->display_options['fields']['field_eventimage']['relationship'] = 'field_vtsevent_target_id';
$handler->display->display_options['fields']['field_eventimage']['label'] = '';
$handler->display->display_options['fields']['field_eventimage']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_eventimage']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_eventimage']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_eventimage']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
/* Field: Content: vtsevent */
$handler->display->display_options['fields']['field_vtsevent_1']['id'] = 'field_vtsevent_1';
$handler->display->display_options['fields']['field_vtsevent_1']['table'] = 'field_data_field_vtsevent';
$handler->display->display_options['fields']['field_vtsevent_1']['field'] = 'field_vtsevent';
$handler->display->display_options['fields']['field_vtsevent_1']['group_type'] = 'count_distinct';
$handler->display->display_options['fields']['field_vtsevent_1']['label'] = '';
$handler->display->display_options['fields']['field_vtsevent_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_vtsevent_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_vtsevent_1']['type'] = 'entityreference_entity_id';
$handler->display->display_options['fields']['field_vtsevent_1']['settings'] = array(
  'link' => 0,
);
$handler->display->display_options['fields']['field_vtsevent_1']['group_column'] = 'entity_id';
/* Field: Content: EventCoordinator */
$handler->display->display_options['fields']['field_eventcoordinator']['id'] = 'field_eventcoordinator';
$handler->display->display_options['fields']['field_eventcoordinator']['table'] = 'field_data_field_eventcoordinator';
$handler->display->display_options['fields']['field_eventcoordinator']['field'] = 'field_eventcoordinator';
$handler->display->display_options['fields']['field_eventcoordinator']['relationship'] = 'field_vtsevent_target_id';
$handler->display->display_options['fields']['field_eventcoordinator']['label'] = '';
$handler->display->display_options['fields']['field_eventcoordinator']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_eventcoordinator']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_eventcoordinator']['alter']['text'] = '<h2>Event Coordinator: [field_eventcoordinator-value]</h2>';
$handler->display->display_options['fields']['field_eventcoordinator']['element_label_type'] = 'h2';
$handler->display->display_options['fields']['field_eventcoordinator']['element_label_colon'] = FALSE;
/* Field: Content: vtsstarttime */
$handler->display->display_options['fields']['field_vtsstarttime']['id'] = 'field_vtsstarttime';
$handler->display->display_options['fields']['field_vtsstarttime']['table'] = 'field_data_field_vtsstarttime';
$handler->display->display_options['fields']['field_vtsstarttime']['field'] = 'field_vtsstarttime';
$handler->display->display_options['fields']['field_vtsstarttime']['label'] = '';
$handler->display->display_options['fields']['field_vtsstarttime']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_vtsstarttime']['alter']['text'] = '<h2>[field_vtsstarttime]</h2>';
$handler->display->display_options['fields']['field_vtsstarttime']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_vtsstarttime']['alter']['path'] = 'vtsdailyview/[nid]';
$handler->display->display_options['fields']['field_vtsstarttime']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_vtsstarttime']['settings'] = array(
  'format_type' => 'eventdayview',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['relationship'] = 'field_vtsevent_target_id';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['text'] = '<h3>[body]</h3>';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'field_vtsevent_target_id';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<h1>[title]</h1>';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: vtsstarttime (field_vtsstarttime) */
$handler->display->display_options['sorts']['field_vtsstarttime_value']['id'] = 'field_vtsstarttime_value';
$handler->display->display_options['sorts']['field_vtsstarttime_value']['table'] = 'field_data_field_vtsstarttime';
$handler->display->display_options['sorts']['field_vtsstarttime_value']['field'] = 'field_vtsstarttime_value';
$handler->display->display_options['path'] = 'vtsviews/%';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Volunteer Events';
$handler->display->display_options['defaults']['group_by'] = FALSE;
$handler->display->display_options['defaults']['query'] = FALSE;
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['empty'] = TRUE;
$handler->display->display_options['header']['area']['content'] = 'Please choose one of the events below:';
$handler->display->display_options['header']['area']['format'] = '3';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: vtsevent */
$handler->display->display_options['fields']['field_vtsevent']['id'] = 'field_vtsevent';
$handler->display->display_options['fields']['field_vtsevent']['table'] = 'field_data_field_vtsevent';
$handler->display->display_options['fields']['field_vtsevent']['field'] = 'field_vtsevent';
$handler->display->display_options['fields']['field_vtsevent']['label'] = '';
$handler->display->display_options['fields']['field_vtsevent']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_vtsevent']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_vtsevent']['type'] = 'entityreference_entity_id';
$handler->display->display_options['fields']['field_vtsevent']['settings'] = array(
  'view_mode' => 'default',
  'links' => 1,
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'field_vtsevent_target_id';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = 'vtsviews/[field_vtsevent]';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: vtsstarttime (field_vtsstarttime) */
$handler->display->display_options['sorts']['field_vtsstarttime_value']['id'] = 'field_vtsstarttime_value';
$handler->display->display_options['sorts']['field_vtsstarttime_value']['table'] = 'field_data_field_vtsstarttime';
$handler->display->display_options['sorts']['field_vtsstarttime_value']['field'] = 'field_vtsstarttime_value';
$handler->display->display_options['block_description'] = 'VTS View Events';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<h2>Please choose the event you would like to volunteer for:</h2>
<br><br>';
$handler->display->display_options['header']['area']['format'] = '3';
$handler->display->display_options['header']['area']['tokenize'] = TRUE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: vtsevent */
$handler->display->display_options['fields']['field_vtsevent_2']['id'] = 'field_vtsevent_2';
$handler->display->display_options['fields']['field_vtsevent_2']['table'] = 'field_data_field_vtsevent';
$handler->display->display_options['fields']['field_vtsevent_2']['field'] = 'field_vtsevent';
$handler->display->display_options['fields']['field_vtsevent_2']['label'] = '';
$handler->display->display_options['fields']['field_vtsevent_2']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_vtsevent_2']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_vtsevent_2']['type'] = 'entityreference_entity_id';
$handler->display->display_options['fields']['field_vtsevent_2']['settings'] = array(
  'link' => 0,
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'field_vtsevent_target_id';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '<h2>vtsviews/[field_vtsevent_2]</h2>';
$handler->display->display_options['fields']['title']['element_type'] = 'h2';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: vtsstarttime */
$handler->display->display_options['fields']['field_vtsstarttime']['id'] = 'field_vtsstarttime';
$handler->display->display_options['fields']['field_vtsstarttime']['table'] = 'field_data_field_vtsstarttime';
$handler->display->display_options['fields']['field_vtsstarttime']['field'] = 'field_vtsstarttime';
$handler->display->display_options['fields']['field_vtsstarttime']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_vtsstarttime']['settings'] = array(
  'format_type' => 'long',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: vtsstarttime (field_vtsstarttime) */
$handler->display->display_options['sorts']['field_vtsstarttime_value']['id'] = 'field_vtsstarttime_value';
$handler->display->display_options['sorts']['field_vtsstarttime_value']['table'] = 'field_data_field_vtsstarttime';
$handler->display->display_options['sorts']['field_vtsstarttime_value']['field'] = 'field_vtsstarttime_value';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'volunteertimesloteventday' => 'volunteertimesloteventday',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
/* Filter criterion: Content: vtsstarttime (field_vtsstarttime) */
$handler->display->display_options['filters']['field_vtsstarttime_value']['id'] = 'field_vtsstarttime_value';
$handler->display->display_options['filters']['field_vtsstarttime_value']['table'] = 'field_data_field_vtsstarttime';
$handler->display->display_options['filters']['field_vtsstarttime_value']['field'] = 'field_vtsstarttime_value';
$handler->display->display_options['filters']['field_vtsstarttime_value']['value']['value'] = '2016';
$handler->display->display_options['filters']['field_vtsstarttime_value']['granularity'] = 'year';
$handler->display->display_options['path'] = 'vtsVolunteerEvents';
$translatables['VTSViews'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('[field_eventimage]<br><br>
[body]'),
  t('Content entity referenced from field_vtsevent'),
  t('<h2>[field_vtsstarttime]</h2>'),
  t('All'),
  t('Page'),
  t('<font color="red">[title]</font>
[field_eventimage]<br><br>
[body]
[field_eventcoordinator]<br>'),
  t('<h2>Event Coordinator: [field_eventcoordinator-value]</h2>'),
  t('<h3>[body]</h3>'),
  t('<h1>[title]</h1>'),
  t('Block'),
  t('Volunteer Events'),
  t('Please choose one of the events below:'),
  t('VTS View Events'),
  t('<h2>Please choose the event you would like to volunteer for:</h2>
<br><br>'),
  t('vtsstarttime'),
);

// (Export ends here.)

  // Add view to list of views to provide.
  $views[$view->name] = $view;

  // ...Repeat all of the above for each view the module should provide.

  // At the end, return array of default views.
  $view = new view();
$view->name = 'vtseventday';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'VTSEventDay';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = '<No Title>';
$handler->display->display_options['css_class'] = 'vtsbody';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['columns'] = array(
  'title' => 'title',
  'field_vtsevent' => 'field_vtsevent',
  'field_vtsstarttime' => 'field_vtsstarttime',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'title' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_vtsevent' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_vtsstarttime' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['override'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: vtsstarttime */
$handler->display->display_options['fields']['field_vtsstarttime']['id'] = 'field_vtsstarttime';
$handler->display->display_options['fields']['field_vtsstarttime']['table'] = 'field_data_field_vtsstarttime';
$handler->display->display_options['fields']['field_vtsstarttime']['field'] = 'field_vtsstarttime';
$handler->display->display_options['fields']['field_vtsstarttime']['label'] = '';
$handler->display->display_options['fields']['field_vtsstarttime']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_vtsstarttime']['alter']['text'] = ' [field_vtsstarttime]';
$handler->display->display_options['fields']['field_vtsstarttime']['element_type'] = 'div';
$handler->display->display_options['fields']['field_vtsstarttime']['element_class'] = 'vtseventdaytoptime';
$handler->display->display_options['fields']['field_vtsstarttime']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_vtsstarttime']['settings'] = array(
  'format_type' => 'eventdayview',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
/* Field: Content: vtsevent */
$handler->display->display_options['fields']['field_vtsevent']['id'] = 'field_vtsevent';
$handler->display->display_options['fields']['field_vtsevent']['table'] = 'field_data_field_vtsevent';
$handler->display->display_options['fields']['field_vtsevent']['field'] = 'field_vtsevent';
$handler->display->display_options['fields']['field_vtsevent']['label'] = '';
$handler->display->display_options['fields']['field_vtsevent']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_vtsevent']['alter']['text'] = '[field_vtsevent] &nbsp;&nbsp;&nbsp;  [field_vtsstarttime] ';
$handler->display->display_options['fields']['field_vtsevent']['element_type'] = 'h2';
$handler->display->display_options['fields']['field_vtsevent']['element_class'] = 'vtseventdaytop';
$handler->display->display_options['fields']['field_vtsevent']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_vtsevent']['settings'] = array(
  'link' => 0,
);
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Contextual filter: Content: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'volunteertimesloteventday' => 'volunteertimesloteventday',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'vtseventday';
$translatables['vtseventday'] = array(
  t('Master'),
  t('<No Title>'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t(' [field_vtsstarttime]'),
  t('[field_vtsevent] &nbsp;&nbsp;&nbsp;  [field_vtsstarttime] '),
  t('All'),
  t('Page'),
);

// (Export ends here.)

  // Add view to list of views to provide.
  $views[$view->name] = $view;

  // ...Repeat all of the above for each view the module should provide.

  // At the end, return array of default views.
  
  
	$view = new view();
$view->name = 'vtsdailyview';
$view->description = 'View of the intervals and slots for an event/day combination';
$view->tag = 'default';
$view->base_table = 'vtsentity_vtsintervals';
$view->human_name = 'VTSDailyView';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['row_class'] = 'vtsrowheight';
$handler->display->display_options['style_options']['columns'] = array(
  'EntityID' => 'EntityID',
  'timestart' => 'timestart',
  'timeend' => 'timeend',
  'EventDay' => 'EventDay',
  'EventID' => 'EventID',
  'handle1' => 'handle1',
  'handle2' => 'handle2',
  'handle3' => 'handle3',
  'handle4' => 'handle4',
  'handle5' => 'handle5',
  'title' => 'title',
  'timestart_1' => 'timestart_1',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'EntityID' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'timestart' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'timeend' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'EventDay' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'EventID' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'handle1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => 'views-align-center',
    'separator' => '',
    'empty_column' => 1,
  ),
  'handle2' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 1,
  ),
  'handle3' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 1,
  ),
  'handle4' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 1,
  ),
  'handle5' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 1,
  ),
  'title' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'timestart_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Header: Global: View area */
$handler->display->display_options['header']['view']['id'] = 'view';
$handler->display->display_options['header']['view']['table'] = 'views';
$handler->display->display_options['header']['view']['field'] = 'view';
$handler->display->display_options['header']['view']['view_to_insert'] = 'vtseventday:default';
$handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
/* Footer: Global: View area */
$handler->display->display_options['footer']['view']['id'] = 'view';
$handler->display->display_options['footer']['view']['table'] = 'views';
$handler->display->display_options['footer']['view']['field'] = 'view';
/* Relationship: VTSinterval: EventID */
$handler->display->display_options['relationships']['EventID']['id'] = 'EventID';
$handler->display->display_options['relationships']['EventID']['table'] = 'vtsentity_vtsintervals';
$handler->display->display_options['relationships']['EventID']['field'] = 'EventID';
$handler->display->display_options['relationships']['EventID']['required'] = TRUE;
/* Field: VTSinterval: VTSInterval ID */
$handler->display->display_options['fields']['EntityID']['id'] = 'EntityID';
$handler->display->display_options['fields']['EntityID']['table'] = 'vtsentity_vtsintervals';
$handler->display->display_options['fields']['EntityID']['field'] = 'EntityID';
$handler->display->display_options['fields']['EntityID']['exclude'] = TRUE;
/* Field: VTSinterval: Start Time */
$handler->display->display_options['fields']['timestart']['id'] = 'timestart';
$handler->display->display_options['fields']['timestart']['table'] = 'vtsentity_vtsintervals';
$handler->display->display_options['fields']['timestart']['field'] = 'timestart';
$handler->display->display_options['fields']['timestart']['exclude'] = TRUE;
$handler->display->display_options['fields']['timestart']['date_format'] = 'unixtodate';
$handler->display->display_options['fields']['timestart']['second_date_format'] = 'long';
$handler->display->display_options['fields']['timestart']['format_date_sql'] = 0;
/* Field: VTSinterval: End Time */
$handler->display->display_options['fields']['timeend']['id'] = 'timeend';
$handler->display->display_options['fields']['timeend']['table'] = 'vtsentity_vtsintervals';
$handler->display->display_options['fields']['timeend']['field'] = 'timeend';
$handler->display->display_options['fields']['timeend']['label'] = 'Time Interval';
$handler->display->display_options['fields']['timeend']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['timeend']['alter']['text'] = '<div class="timeinterval"><h3>[timestart] TO [timeend]</h3></div>';
$handler->display->display_options['fields']['timeend']['element_label_type'] = 'h2';
$handler->display->display_options['fields']['timeend']['element_label_class'] = 'firsthandleheader';
$handler->display->display_options['fields']['timeend']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['timeend']['date_format'] = 'unixtodate';
$handler->display->display_options['fields']['timeend']['second_date_format'] = 'long';
$handler->display->display_options['fields']['timeend']['format_date_sql'] = 0;
/* Field: VTSinterval: EventDay */
$handler->display->display_options['fields']['EventDay']['id'] = 'EventDay';
$handler->display->display_options['fields']['EventDay']['table'] = 'vtsentity_vtsintervals';
$handler->display->display_options['fields']['EventDay']['field'] = 'EventDay';
$handler->display->display_options['fields']['EventDay']['exclude'] = TRUE;
/* Field: VTSinterval: EventID */
$handler->display->display_options['fields']['EventID']['id'] = 'EventID';
$handler->display->display_options['fields']['EventID']['table'] = 'vtsentity_vtsintervals';
$handler->display->display_options['fields']['EventID']['field'] = 'EventID';
$handler->display->display_options['fields']['EventID']['exclude'] = TRUE;
/* Field: VTSinterval: handle1 */
$handler->display->display_options['fields']['handle1']['id'] = 'handle1';
$handler->display->display_options['fields']['handle1']['table'] = 'vtsentity_vtsintervals';
$handler->display->display_options['fields']['handle1']['field'] = 'handle1';
$handler->display->display_options['fields']['handle1']['label'] = '          Volunteer(s)';
$handler->display->display_options['fields']['handle1']['alter']['text'] = '<div class="firsthandleheader"><h3>[handle1]</h3></div>';
$handler->display->display_options['fields']['handle1']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['handle1']['alter']['path'] = 'vts-update?type=nojs&itemID=[EntityID]&itemHandle=[handle1]&itemslot=1';
$handler->display->display_options['fields']['handle1']['alter']['link_class'] = 'use-ajax vtsclass[EntityID]_1';
$handler->display->display_options['fields']['handle1']['alter']['prefix'] = '<h3>';
$handler->display->display_options['fields']['handle1']['alter']['suffix'] = '</h3>';
$handler->display->display_options['fields']['handle1']['element_label_type'] = 'h2';
$handler->display->display_options['fields']['handle1']['element_label_class'] = 'firsthandleheader';
$handler->display->display_options['fields']['handle1']['element_label_colon'] = FALSE;
/* Field: VTSinterval: handle2 */
$handler->display->display_options['fields']['handle2']['id'] = 'handle2';
$handler->display->display_options['fields']['handle2']['table'] = 'vtsentity_vtsintervals';
$handler->display->display_options['fields']['handle2']['field'] = 'handle2';
$handler->display->display_options['fields']['handle2']['label'] = '';
$handler->display->display_options['fields']['handle2']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['handle2']['alter']['path'] = 'vts-update?type=nojs&itemID=[EntityID]&itemHandle=[handle2]&itemslot=2';
$handler->display->display_options['fields']['handle2']['alter']['link_class'] = 'use-ajax vtsclass[EntityID]_2';
$handler->display->display_options['fields']['handle2']['alter']['prefix'] = '<h3>';
$handler->display->display_options['fields']['handle2']['alter']['suffix'] = '</h3>';
$handler->display->display_options['fields']['handle2']['element_label_type'] = 'h2';
$handler->display->display_options['fields']['handle2']['element_label_class'] = 'firsthandleheader';
$handler->display->display_options['fields']['handle2']['element_label_colon'] = FALSE;
/* Field: VTSinterval: handle3 */
$handler->display->display_options['fields']['handle3']['id'] = 'handle3';
$handler->display->display_options['fields']['handle3']['table'] = 'vtsentity_vtsintervals';
$handler->display->display_options['fields']['handle3']['field'] = 'handle3';
$handler->display->display_options['fields']['handle3']['label'] = '';
$handler->display->display_options['fields']['handle3']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['handle3']['alter']['path'] = 'vts-update?type=nojs&itemID=[EntityID]&itemHandle=[handle2]&itemslot=3';
$handler->display->display_options['fields']['handle3']['alter']['link_class'] = 'use-ajax vtsclass[EntityID]_3';
$handler->display->display_options['fields']['handle3']['alter']['prefix'] = '<h3>';
$handler->display->display_options['fields']['handle3']['alter']['suffix'] = '</h3>';
$handler->display->display_options['fields']['handle3']['element_label_colon'] = FALSE;
/* Field: VTSinterval: handle4 */
$handler->display->display_options['fields']['handle4']['id'] = 'handle4';
$handler->display->display_options['fields']['handle4']['table'] = 'vtsentity_vtsintervals';
$handler->display->display_options['fields']['handle4']['field'] = 'handle4';
$handler->display->display_options['fields']['handle4']['label'] = '';
$handler->display->display_options['fields']['handle4']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['handle4']['alter']['path'] = 'vts-update?type=nojs&itemID=[EntityID]&itemHandle=[handle2]&itemslot=4';
$handler->display->display_options['fields']['handle4']['alter']['link_class'] = 'use-ajax vtsclass[EntityID]_4';
$handler->display->display_options['fields']['handle4']['alter']['prefix'] = '<h3>';
$handler->display->display_options['fields']['handle4']['alter']['suffix'] = '</h3>';
$handler->display->display_options['fields']['handle4']['element_label_colon'] = FALSE;
/* Field: VTSinterval: handle5 */
$handler->display->display_options['fields']['handle5']['id'] = 'handle5';
$handler->display->display_options['fields']['handle5']['table'] = 'vtsentity_vtsintervals';
$handler->display->display_options['fields']['handle5']['field'] = 'handle5';
$handler->display->display_options['fields']['handle5']['label'] = '';
$handler->display->display_options['fields']['handle5']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['handle5']['alter']['path'] = 'vts-update?type=nojs&itemID=[EntityID]&itemHandle=[handle2]&itemslot=5';
$handler->display->display_options['fields']['handle5']['alter']['link_class'] = 'use-ajax vtsclass[EntityID]_5';
$handler->display->display_options['fields']['handle5']['alter']['prefix'] = '<h3>';
$handler->display->display_options['fields']['handle5']['alter']['suffix'] = '</h3>';
$handler->display->display_options['fields']['handle5']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'EventID';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
/* Field: VTSinterval: Start Time */
$handler->display->display_options['fields']['timestart_1']['id'] = 'timestart_1';
$handler->display->display_options['fields']['timestart_1']['table'] = 'vtsentity_vtsintervals';
$handler->display->display_options['fields']['timestart_1']['field'] = 'timestart';
$handler->display->display_options['fields']['timestart_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['timestart_1']['date_format'] = 'eventdayview';
$handler->display->display_options['fields']['timestart_1']['second_date_format'] = 'long';
$handler->display->display_options['fields']['timestart_1']['format_date_sql'] = 0;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[title]';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Contextual filter: VTSinterval: EventDay */
$handler->display->display_options['arguments']['EventDay']['id'] = 'EventDay';
$handler->display->display_options['arguments']['EventDay']['table'] = 'vtsentity_vtsintervals';
$handler->display->display_options['arguments']['EventDay']['field'] = 'EventDay';
$handler->display->display_options['arguments']['EventDay']['default_action'] = 'not found';
$handler->display->display_options['arguments']['EventDay']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['EventDay']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['EventDay']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['EventDay']['summary_options']['items_per_page'] = '25';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'vtsdailyview';
$translatables['vtsdailyview'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('Node'),
  t('VTSInterval ID'),
  t('.'),
  t(','),
  t('Start Time'),
  t('Time Interval'),
  t('<div class="timeinterval"><h3>[timestart] TO [timeend]</h3></div>'),
  t('EventDay'),
  t('EventID'),
  t('          Volunteer(s)'),
  t('<div class="firsthandleheader"><h3>[handle1]</h3></div>'),
  t('<h3>'),
  t('</h3>'),
  t('Title'),
  t('[title]'),
  t('All'),
  t('Page'),
);

// (Export ends here.)

  // Add view to list of views to provide.
  $views[$view->name] = $view;

  // ...Repeat all of the above for each view the module should provide.

  // At the end, return array of default views.
  return $views;
}