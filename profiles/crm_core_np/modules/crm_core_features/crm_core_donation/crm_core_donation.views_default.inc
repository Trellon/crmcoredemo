<?php
/**
 * @file
 * crm_core_donation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crm_core_donation_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'crm_core_donation_pages';
  $view->description = 'Displays a list of donation pages';
  $view->tag = 'default';
  $view->base_table = 'crm_core_donation_page';
  $view->human_name = 'CRM Core Donation Pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CRM Core Donation Pages';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer crm core donation';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="messages warning">You currently have not created any donation pages, please click the tab above to create one</div>';
  /* Relationship: CRM Donation: Donation Page Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: CRM Donation: Donation page ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: CRM Donation: Donation page title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'donation_pages/[id]';
  /* Field: CRM Donation: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Field: CRM Donation: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Edit link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Edit link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'crm/donations/[id]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Delete Link */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Delete Link';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Delete';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'crm/donations/[id]/delete';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Action */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Action';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Action';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[nothing]  / [nothing_1]';
  /* Sort criterion: CRM Donation: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';

  /* Display: Donation Pages */
  $handler = $view->new_display('page', 'Donation Pages', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: CRM Donation: Personal donation page */
  $handler->display->display_options['filters']['pdp']['id'] = 'pdp';
  $handler->display->display_options['filters']['pdp']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['filters']['pdp']['field'] = 'pdp';
  $handler->display->display_options['filters']['pdp']['value']['value'] = '0';
  $handler->display->display_options['path'] = 'crm/donations';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Donation';
  $handler->display->display_options['menu']['description'] = 'donation pages';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: PDP */
  $handler = $view->new_display('page', 'PDP', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CRM Donation: Donation page ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: CRM Donation: Donation page title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'donation_pages/[id]';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  /* Field: CRM Donation: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Field: CRM Donation: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Edit link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Edit link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'crm/donations/[id]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Delete Link */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Delete Link';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Delete';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'crm/donations/1/delete';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Action */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Action';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Action';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[nothing]  / [nothing_1]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: CRM Donation: Personal donation page */
  $handler->display->display_options['filters']['pdp']['id'] = 'pdp';
  $handler->display->display_options['filters']['pdp']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['filters']['pdp']['field'] = 'pdp';
  $handler->display->display_options['filters']['pdp']['value']['value'] = '1';
  $handler->display->display_options['path'] = 'crm/donations/personal-pages';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'PDP';
  $handler->display->display_options['menu']['description'] = 'personal donation pages';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $export['crm_core_donation_pages'] = $view;

  $view = new view();
  $view->name = 'donations_overview_alt';
  $view->description = 'A list of all donations recorded in the system. Filterable by date.';
  $view->tag = 'default';
  $view->base_table = 'crm_core_activity';
  $view->human_name = 'Donations Overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Donations Overview';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer crm core donation';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_donation_amounts' => 'field_donation_amounts',
    'field_activity_date' => 'field_activity_date',
    'contact_name' => 'contact_name',
    'field_billing_address' => 'field_billing_address',
  );
  $handler->display->display_options['style_options']['default'] = 'field_activity_date';
  $handler->display->display_options['style_options']['info'] = array(
    'field_donation_amounts' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'contact_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_billing_address' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['summary'] = 'List of all donations.';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['id'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['field'] = 'field_activity_participants_target_id';
  /* Field: CRM Activity: Amount */
  $handler->display->display_options['fields']['field_donation_amounts']['id'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['table'] = 'field_data_field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['field'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['text'] = '$[field_donation_amounts] ';
  $handler->display->display_options['fields']['field_donation_amounts']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: CRM Activity: Date */
  $handler->display->display_options['fields']['field_activity_date']['id'] = 'field_activity_date';
  $handler->display->display_options['fields']['field_activity_date']['table'] = 'field_data_field_activity_date';
  $handler->display->display_options['fields']['field_activity_date']['field'] = 'field_activity_date';
  $handler->display->display_options['fields']['field_activity_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: CRM Contact: Household name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['contact_name']['label'] = 'Donor';
  $handler->display->display_options['fields']['contact_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['contact_name']['settings'] = array(
    'format' => 'default',
    'markup' => 0,
    'output' => 'default',
    'multiple' => 'default',
    'multiple_delimiter' => ', ',
    'multiple_and' => 'text',
    'multiple_delimiter_precedes_last' => 'never',
    'multiple_el_al_min' => '3',
    'multiple_el_al_first' => '1',
  );
  /* Field: CRM Contact: Billing Address */
  $handler->display->display_options['fields']['field_billing_address']['id'] = 'field_billing_address';
  $handler->display->display_options['fields']['field_billing_address']['table'] = 'field_data_field_billing_address';
  $handler->display->display_options['fields']['field_billing_address']['field'] = 'field_billing_address';
  $handler->display->display_options['fields']['field_billing_address']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['field_billing_address']['label'] = 'Address';
  $handler->display->display_options['fields']['field_billing_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_billing_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Sort criterion: CRM Activity: Date (field_activity_date) */
  $handler->display->display_options['sorts']['field_activity_date_value']['id'] = 'field_activity_date_value';
  $handler->display->display_options['sorts']['field_activity_date_value']['table'] = 'field_data_field_activity_date';
  $handler->display->display_options['sorts']['field_activity_date_value']['field'] = 'field_activity_date_value';
  $handler->display->display_options['sorts']['field_activity_date_value']['order'] = 'DESC';
  /* Filter criterion: CRM Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'donation' => 'donation',
  );
  /* Filter criterion: CRM Activity: Date (field_activity_date) */
  $handler->display->display_options['filters']['field_activity_date_value']['id'] = 'field_activity_date_value';
  $handler->display->display_options['filters']['field_activity_date_value']['table'] = 'field_data_field_activity_date';
  $handler->display->display_options['filters']['field_activity_date_value']['field'] = 'field_activity_date_value';
  $handler->display->display_options['filters']['field_activity_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_activity_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_date_value']['expose']['operator_id'] = 'field_activity_date_value_op';
  $handler->display->display_options['filters']['field_activity_date_value']['expose']['label'] = 'Filter by Date';
  $handler->display->display_options['filters']['field_activity_date_value']['expose']['operator'] = 'field_activity_date_value_op';
  $handler->display->display_options['filters']['field_activity_date_value']['expose']['identifier'] = 'field_activity_date_value';
  $handler->display->display_options['filters']['field_activity_date_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_activity_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_activity_date_value']['group_info']['label'] = 'Date (field_activity_date)';
  $handler->display->display_options['filters']['field_activity_date_value']['group_info']['identifier'] = 'field_activity_date_value';
  $handler->display->display_options['filters']['field_activity_date_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_activity_date_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_activity_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_activity_date_value']['year_range'] = '-3:+1';
  /* Filter criterion: CRM Activity: Amount (field_donation_amounts) */
  $handler->display->display_options['filters']['field_donation_amounts_value']['id'] = 'field_donation_amounts_value';
  $handler->display->display_options['filters']['field_donation_amounts_value']['table'] = 'field_data_field_donation_amounts';
  $handler->display->display_options['filters']['field_donation_amounts_value']['field'] = 'field_donation_amounts_value';
  $handler->display->display_options['filters']['field_donation_amounts_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_donation_amounts_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_donation_amounts_value']['expose']['operator_id'] = 'field_donation_amounts_value_op';
  $handler->display->display_options['filters']['field_donation_amounts_value']['expose']['label'] = 'Filter by Amounts Between';
  $handler->display->display_options['filters']['field_donation_amounts_value']['expose']['operator'] = 'field_donation_amounts_value_op';
  $handler->display->display_options['filters']['field_donation_amounts_value']['expose']['identifier'] = 'field_donation_amounts_value';
  $handler->display->display_options['filters']['field_donation_amounts_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_donation_amounts_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'crm/reports/donations-overview';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Donations Overview';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $export['donations_overview_alt'] = $view;

  return $export;
}
