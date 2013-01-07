<?php
/**
 * @file
 * crm_core_volunteer.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crm_core_volunteer_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'crm_core_volunteer_commitment_overview';
  $view->description = 'Overview of volunteer activity. Displays individual opportunities and the amount of activity around each.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CRM Core Volunteer Commitment Overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Volunteer Commitment Overview';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view crm core volunteer reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_volunteer_opportunity_crm_core_activity']['id'] = 'reverse_field_volunteer_opportunity_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_volunteer_opportunity_crm_core_activity']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_volunteer_opportunity_crm_core_activity']['field'] = 'reverse_field_volunteer_opportunity_crm_core_activity';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_crmvo_date']['id'] = 'field_crmvo_date';
  $handler->display->display_options['fields']['field_crmvo_date']['table'] = 'field_data_field_crmvo_date';
  $handler->display->display_options['fields']['field_crmvo_date']['field'] = 'field_crmvo_date';
  $handler->display->display_options['fields']['field_crmvo_date']['settings'] = array(
    'format_type' => 'date_format_slim',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: COUNT(DISTINCT CRM Activity: Activity ID) */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['relationship'] = 'reverse_field_volunteer_opportunity_crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['activity_id']['label'] = 'Number of Volunteers';
  /* Field: Content: Number of Slots */
  $handler->display->display_options['fields']['field_crmvo_slots']['id'] = 'field_crmvo_slots';
  $handler->display->display_options['fields']['field_crmvo_slots']['table'] = 'field_data_field_crmvo_slots';
  $handler->display->display_options['fields']['field_crmvo_slots']['field'] = 'field_crmvo_slots';
  $handler->display->display_options['fields']['field_crmvo_slots']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'volunteer_opportunity' => 'volunteer_opportunity',
  );
  /* Filter criterion: Content: Date -  start date (field_crmvo_date) */
  $handler->display->display_options['filters']['field_crmvo_date_value']['id'] = 'field_crmvo_date_value';
  $handler->display->display_options['filters']['field_crmvo_date_value']['table'] = 'field_data_field_crmvo_date';
  $handler->display->display_options['filters']['field_crmvo_date_value']['field'] = 'field_crmvo_date_value';
  $handler->display->display_options['filters']['field_crmvo_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_crmvo_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crmvo_date_value']['expose']['operator_id'] = 'field_crmvo_date_value_op';
  $handler->display->display_options['filters']['field_crmvo_date_value']['expose']['label'] = 'Occurring between';
  $handler->display->display_options['filters']['field_crmvo_date_value']['expose']['operator'] = 'field_crmvo_date_value_op';
  $handler->display->display_options['filters']['field_crmvo_date_value']['expose']['identifier'] = 'field_crmvo_date_value';
  $handler->display->display_options['filters']['field_crmvo_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_crmvo_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_crmvo_date_value']['default_date'] = '-2 years';
  $handler->display->display_options['filters']['field_crmvo_date_value']['default_to_date'] = '+2 years';
  /* Filter criterion: SUM(CRM Activity: Activity ID) */
  $handler->display->display_options['filters']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['filters']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['filters']['activity_id']['relationship'] = 'reverse_field_volunteer_opportunity_crm_core_activity';
  $handler->display->display_options['filters']['activity_id']['group_type'] = 'sum';
  $handler->display->display_options['filters']['activity_id']['operator'] = 'between';
  $handler->display->display_options['filters']['activity_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['activity_id']['expose']['operator_id'] = 'activity_id_op';
  $handler->display->display_options['filters']['activity_id']['expose']['label'] = 'Number of Volunteers';
  $handler->display->display_options['filters']['activity_id']['expose']['operator'] = 'activity_id_op';
  $handler->display->display_options['filters']['activity_id']['expose']['identifier'] = 'activity_id';
  $handler->display->display_options['filters']['activity_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'crm/reports/crm-core-volunteer-commitment-overview';
  $export['crm_core_volunteer_commitment_overview'] = $view;

  $view = new view();
  $view->name = 'crm_core_volunteer_overview';
  $view->description = 'Displays a list of people who have signed up as volunteers on the site';
  $view->tag = 'default';
  $view->base_table = 'crm_core_contact';
  $view->human_name = 'CRM Core Volunteer Overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Volunteer Overview';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_activity_participants_crm_core_activity']['id'] = 'reverse_field_activity_participants_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_activity_participants_crm_core_activity']['table'] = 'crm_core_contact';
  $handler->display->display_options['relationships']['reverse_field_activity_participants_crm_core_activity']['field'] = 'reverse_field_activity_participants_crm_core_activity';
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['link_to_contact'] = 0;
  /* Field: CRM Contact: Household name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['label'] = 'Name';
  $handler->display->display_options['fields']['contact_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['contact_name']['alter']['path'] = 'crm/contact/[contact_id]';
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
  $handler->display->display_options['fields']['contact_name']['group_column'] = 'entity_id';
  /* Field: CRM Contact: Volunteer */
  $handler->display->display_options['fields']['field_contact_volunteer']['id'] = 'field_contact_volunteer';
  $handler->display->display_options['fields']['field_contact_volunteer']['table'] = 'field_data_field_contact_volunteer';
  $handler->display->display_options['fields']['field_contact_volunteer']['field'] = 'field_contact_volunteer';
  $handler->display->display_options['fields']['field_contact_volunteer']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_contact_volunteer']['alter']['text'] = 'Registered';
  $handler->display->display_options['fields']['field_contact_volunteer']['empty'] = 'Not Registered';
  $handler->display->display_options['fields']['field_contact_volunteer']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_contact_volunteer']['type'] = 'list_key';
  /* Field: COUNT(DISTINCT CRM Activity: Activity ID) */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['relationship'] = 'reverse_field_activity_participants_crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['activity_id']['label'] = 'Registered';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: CRM Contact: Volunteer (field_contact_volunteer) */
  $handler->display->display_options['filters']['field_contact_volunteer_value']['id'] = 'field_contact_volunteer_value';
  $handler->display->display_options['filters']['field_contact_volunteer_value']['table'] = 'field_data_field_contact_volunteer';
  $handler->display->display_options['filters']['field_contact_volunteer_value']['field'] = 'field_contact_volunteer_value';
  $handler->display->display_options['filters']['field_contact_volunteer_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_contact_volunteer_value']['value'] = array(
    'all' => 'all',
  );
  $handler->display->display_options['filters']['field_contact_volunteer_value']['group'] = 2;
  /* Filter criterion: CRM Activity: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_activity_participants_crm_core_activity';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'volunteer_commitment' => 'volunteer_commitment',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 3;
  /* Filter criterion: CRM Contact: Contact Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_contact';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'individual' => 'individual',
  );
  $handler->display->display_options['filters']['type']['group'] = 3;
  /* Filter criterion: COUNT(DISTINCT CRM Activity: Activity ID) */
  $handler->display->display_options['filters']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['filters']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['filters']['activity_id']['relationship'] = 'reverse_field_activity_participants_crm_core_activity';
  $handler->display->display_options['filters']['activity_id']['group_type'] = 'count_distinct';
  $handler->display->display_options['filters']['activity_id']['operator'] = '>';
  $handler->display->display_options['filters']['activity_id']['value']['value'] = '0';
  $handler->display->display_options['filters']['activity_id']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'crm/volunteer/crm-core-volunteer-overview';
  $export['crm_core_volunteer_overview'] = $view;

  $view = new view();
  $view->name = 'volunteer_commitment_report';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Volunteer commitment report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Volunteer commitment';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view crm core reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'contact_name' => 'contact_name',
    'title' => 'title',
    'field_crmvo_date' => 'title',
    'field_volunteer_time' => 'field_volunteer_time',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'contact_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ', ',
      'empty_column' => 0,
    ),
    'field_crmvo_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_volunteer_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming</h2>';
  $handler->display->display_options['header']['area']['format'] = 'plain_text';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There is no any upcoming volunteer opportunity you have committed.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_volunteer_opportunity_crm_core_activity']['id'] = 'reverse_field_volunteer_opportunity_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_volunteer_opportunity_crm_core_activity']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_volunteer_opportunity_crm_core_activity']['field'] = 'reverse_field_volunteer_opportunity_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_volunteer_opportunity_crm_core_activity']['label'] = 'Volunteer Activity';
  $handler->display->display_options['relationships']['reverse_field_volunteer_opportunity_crm_core_activity']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['id'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['field'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['relationship'] = 'reverse_field_volunteer_opportunity_crm_core_activity';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['label'] = 'Contact';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['required'] = TRUE;
  /* Field: CRM Activity: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'reverse_field_volunteer_opportunity_crm_core_activity';
  $handler->display->display_options['fields']['created']['label'] = 'Commitment date';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: CRM Contact: Household name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['contact_name']['label'] = 'Contact name';
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Volunteer opportunity';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_crmvo_date']['id'] = 'field_crmvo_date';
  $handler->display->display_options['fields']['field_crmvo_date']['table'] = 'field_data_field_crmvo_date';
  $handler->display->display_options['fields']['field_crmvo_date']['field'] = 'field_crmvo_date';
  $handler->display->display_options['fields']['field_crmvo_date']['settings'] = array(
    'format_type' => 'date_format_slim',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: CRM Activity: Estimated commitment time */
  $handler->display->display_options['fields']['field_volunteer_time']['id'] = 'field_volunteer_time';
  $handler->display->display_options['fields']['field_volunteer_time']['table'] = 'field_data_field_volunteer_time';
  $handler->display->display_options['fields']['field_volunteer_time']['field'] = 'field_volunteer_time';
  $handler->display->display_options['fields']['field_volunteer_time']['relationship'] = 'reverse_field_volunteer_opportunity_crm_core_activity';
  $handler->display->display_options['fields']['field_volunteer_time']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Date -  start date (field_crmvo_date) */
  $handler->display->display_options['sorts']['field_crmvo_date_value']['id'] = 'field_crmvo_date_value';
  $handler->display->display_options['sorts']['field_crmvo_date_value']['table'] = 'field_data_field_crmvo_date';
  $handler->display->display_options['sorts']['field_crmvo_date_value']['field'] = 'field_crmvo_date_value';
  $handler->display->display_options['sorts']['field_crmvo_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Volunteer Opportunity';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Volunteer commitment: detail */
  $handler = $view->new_display('page', 'Volunteer commitment: detail', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There is no any past volunteer opportunity you have committed.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['path'] = 'crm/reports/volunteer/detail';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Volunteer commitment report';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $export['volunteer_commitment_report'] = $view;

  $view = new view();
  $view->name = 'volunteer_opportunities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Volunteer Opportunities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My volunteer opportunities';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming</h2>';
  $handler->display->display_options['header']['area']['format'] = 'plain_text';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There is no any upcoming volunteer opportunity you have committed.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_volunteer_opportunity_crm_core_activity']['id'] = 'reverse_field_volunteer_opportunity_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_volunteer_opportunity_crm_core_activity']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_volunteer_opportunity_crm_core_activity']['field'] = 'reverse_field_volunteer_opportunity_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_volunteer_opportunity_crm_core_activity']['label'] = 'Volunteer Activity';
  $handler->display->display_options['relationships']['reverse_field_volunteer_opportunity_crm_core_activity']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['id'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['field'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['relationship'] = 'reverse_field_volunteer_opportunity_crm_core_activity';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['label'] = 'Contact';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['required'] = TRUE;
  /* Relationship: CRM Contact: Relation: User (crm_core_contact -&gt; user) */
  $handler->display->display_options['relationships']['relation_crm_user_sync_user']['id'] = 'relation_crm_user_sync_user';
  $handler->display->display_options['relationships']['relation_crm_user_sync_user']['table'] = 'crm_core_contact';
  $handler->display->display_options['relationships']['relation_crm_user_sync_user']['field'] = 'relation_crm_user_sync_user';
  $handler->display->display_options['relationships']['relation_crm_user_sync_user']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['relation_crm_user_sync_user']['required'] = TRUE;
  $handler->display->display_options['relationships']['relation_crm_user_sync_user']['r_index'] = '-1';
  $handler->display->display_options['relationships']['relation_crm_user_sync_user']['entity_deduplication_left'] = 0;
  $handler->display->display_options['relationships']['relation_crm_user_sync_user']['entity_deduplication_right'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Volunteer Opportunity';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_crmvo_date']['id'] = 'field_crmvo_date';
  $handler->display->display_options['fields']['field_crmvo_date']['table'] = 'field_data_field_crmvo_date';
  $handler->display->display_options['fields']['field_crmvo_date']['field'] = 'field_crmvo_date';
  $handler->display->display_options['fields']['field_crmvo_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: CRM Activity: Estimated commitment time */
  $handler->display->display_options['fields']['field_volunteer_time']['id'] = 'field_volunteer_time';
  $handler->display->display_options['fields']['field_volunteer_time']['table'] = 'field_data_field_volunteer_time';
  $handler->display->display_options['fields']['field_volunteer_time']['field'] = 'field_volunteer_time';
  $handler->display->display_options['fields']['field_volunteer_time']['relationship'] = 'reverse_field_volunteer_opportunity_crm_core_activity';
  $handler->display->display_options['fields']['field_volunteer_time']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Date -  start date (field_crmvo_date) */
  $handler->display->display_options['sorts']['field_crmvo_date_value']['id'] = 'field_crmvo_date_value';
  $handler->display->display_options['sorts']['field_crmvo_date_value']['table'] = 'field_data_field_crmvo_date';
  $handler->display->display_options['sorts']['field_crmvo_date_value']['field'] = 'field_crmvo_date_value';
  $handler->display->display_options['sorts']['field_crmvo_date_value']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'relation_crm_user_sync_user';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Date -  start date (field_crmvo_date) */
  $handler->display->display_options['filters']['field_crmvo_date_value']['id'] = 'field_crmvo_date_value';
  $handler->display->display_options['filters']['field_crmvo_date_value']['table'] = 'field_data_field_crmvo_date';
  $handler->display->display_options['filters']['field_crmvo_date_value']['field'] = 'field_crmvo_date_value';
  $handler->display->display_options['filters']['field_crmvo_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_crmvo_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'volunteer_opportunity' => 'volunteer_opportunity',
  );

  /* Display: Past Volunteer Opportunities Page */
  $handler = $view->new_display('page', 'Past Volunteer Opportunities Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['empty'] = TRUE;
  $handler->display->display_options['header']['view']['view_to_insert'] = 'volunteer_opportunities:block_1';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2>Past</h2>';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There is no any past volunteer opportunity you have committed.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['path'] = 'user/%user/volunteer-opportunities';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'My volunteer opportunities ';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Past Volunteer Opportunities Block */
  $handler = $view->new_display('block', 'Past Volunteer Opportunities Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming opportunities';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2>Upcoming</h2>';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_crmvo_date) */
  $handler->display->display_options['sorts']['field_crmvo_date_value']['id'] = 'field_crmvo_date_value';
  $handler->display->display_options['sorts']['field_crmvo_date_value']['table'] = 'field_data_field_crmvo_date';
  $handler->display->display_options['sorts']['field_crmvo_date_value']['field'] = 'field_crmvo_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Date -  start date (field_crmvo_date) */
  $handler->display->display_options['filters']['field_crmvo_date_value']['id'] = 'field_crmvo_date_value';
  $handler->display->display_options['filters']['field_crmvo_date_value']['table'] = 'field_data_field_crmvo_date';
  $handler->display->display_options['filters']['field_crmvo_date_value']['field'] = 'field_crmvo_date_value';
  $handler->display->display_options['filters']['field_crmvo_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_crmvo_date_value']['default_date'] = 'now';

  /* Display: Volunteer opportunities */
  $handler = $view->new_display('page', 'Volunteer opportunities', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Volunteer Opportunities';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There is no any past volunteer opportunity you have committed.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Volunteer Opportunity';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_crmvo_date']['id'] = 'field_crmvo_date';
  $handler->display->display_options['fields']['field_crmvo_date']['table'] = 'field_data_field_crmvo_date';
  $handler->display->display_options['fields']['field_crmvo_date']['field'] = 'field_crmvo_date';
  $handler->display->display_options['fields']['field_crmvo_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Volunteer Link */
  $handler->display->display_options['fields']['volunteer_link']['id'] = 'volunteer_link';
  $handler->display->display_options['fields']['volunteer_link']['table'] = 'node';
  $handler->display->display_options['fields']['volunteer_link']['field'] = 'volunteer_link';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'volunteer_opportunity' => 'volunteer_opportunity',
  );
  $handler->display->display_options['path'] = 'volunteer-opportunities';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Volunteer opportunities ';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['volunteer_opportunities'] = $view;

  return $export;
}
