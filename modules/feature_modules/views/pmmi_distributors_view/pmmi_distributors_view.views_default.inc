<?php
/**
 * @file
 * pmmi_distributors_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pmmi_distributors_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'distributors';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Distributors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<h1>Distributors</h1>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_distributor_address_locality']['id'] = 'field_distributor_address_locality';
  $handler->display->display_options['fields']['field_distributor_address_locality']['table'] = 'field_data_field_distributor_address';
  $handler->display->display_options['fields']['field_distributor_address_locality']['field'] = 'field_distributor_address_locality';
  $handler->display->display_options['fields']['field_distributor_address_locality']['label'] = '';
  $handler->display->display_options['fields']['field_distributor_address_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_distributor_address_locality']['element_label_colon'] = FALSE;
  /* Field: Content: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_distributor_address_administrative_area']['id'] = 'field_distributor_address_administrative_area';
  $handler->display->display_options['fields']['field_distributor_address_administrative_area']['table'] = 'field_data_field_distributor_address';
  $handler->display->display_options['fields']['field_distributor_address_administrative_area']['field'] = 'field_distributor_address_administrative_area';
  $handler->display->display_options['fields']['field_distributor_address_administrative_area']['label'] = '';
  $handler->display->display_options['fields']['field_distributor_address_administrative_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_distributor_address_administrative_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_distributor_address_administrative_area']['display_name'] = 0;
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_distributor_address_country']['id'] = 'field_distributor_address_country';
  $handler->display->display_options['fields']['field_distributor_address_country']['table'] = 'field_data_field_distributor_address';
  $handler->display->display_options['fields']['field_distributor_address_country']['field'] = 'field_distributor_address_country';
  $handler->display->display_options['fields']['field_distributor_address_country']['label'] = '';
  $handler->display->display_options['fields']['field_distributor_address_country']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_distributor_address_country']['alter']['text'] = '<strong>[title]</strong>, [field_distributor_address_locality], [field_distributor_address_administrative_area], [field_distributor_address_country]';
  $handler->display->display_options['fields']['field_distributor_address_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_distributor_address_country']['display_name'] = 1;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'distributor' => 'distributor',
  );
  /* Filter criterion: Content: Address - Country */
  $handler->display->display_options['filters']['field_distributor_address_country']['id'] = 'field_distributor_address_country';
  $handler->display->display_options['filters']['field_distributor_address_country']['table'] = 'field_data_field_distributor_address';
  $handler->display->display_options['filters']['field_distributor_address_country']['field'] = 'field_distributor_address_country';
  $handler->display->display_options['filters']['field_distributor_address_country']['value'] = array(
    'US' => 'US',
  );
  /* Filter criterion: Content: Industries Served (field_distributor_industries) */
  $handler->display->display_options['filters']['field_distributor_industries_tid']['id'] = 'field_distributor_industries_tid';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['table'] = 'field_data_field_distributor_industries';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['field'] = 'field_distributor_industries_tid';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_distributor_industries_tid']['expose']['operator_id'] = 'field_distributor_industries_tid_op';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['expose']['label'] = 'Industries Served';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['expose']['operator'] = 'field_distributor_industries_tid_op';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['expose']['identifier'] = 'field_distributor_industries_tid';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_distributor_industries_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['vocabulary'] = 'industries_served';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'US';
  $handler->display->display_options['header']['area']['content'] = '<h2>US</h2>';
  $handler->display->display_options['header']['area']['format'] = 'advanced_html';
  $handler->display->display_options['path'] = 'distributors';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Distributors';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Non-US';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Non-US</h2>';
  $handler->display->display_options['header']['area']['format'] = 'advanced_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'distributor' => 'distributor',
  );
  /* Filter criterion: Content: Address - Country */
  $handler->display->display_options['filters']['field_distributor_address_country']['id'] = 'field_distributor_address_country';
  $handler->display->display_options['filters']['field_distributor_address_country']['table'] = 'field_data_field_distributor_address';
  $handler->display->display_options['filters']['field_distributor_address_country']['field'] = 'field_distributor_address_country';
  $handler->display->display_options['filters']['field_distributor_address_country']['operator'] = 'not in';
  $handler->display->display_options['filters']['field_distributor_address_country']['value'] = array(
    'US' => 'US',
  );
  /* Filter criterion: Content: Industries Served (field_distributor_industries) */
  $handler->display->display_options['filters']['field_distributor_industries_tid']['id'] = 'field_distributor_industries_tid';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['table'] = 'field_data_field_distributor_industries';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['field'] = 'field_distributor_industries_tid';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_distributor_industries_tid']['expose']['operator_id'] = 'field_distributor_industries_tid_op';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['expose']['label'] = 'Industries Served';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['expose']['operator'] = 'field_distributor_industries_tid_op';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['expose']['identifier'] = 'field_distributor_industries_tid';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_distributor_industries_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_distributor_industries_tid']['vocabulary'] = 'industries_served';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $export['distributors'] = $view;

  return $export;
}
