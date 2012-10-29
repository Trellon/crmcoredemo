<?php
/**
 * @file
 * crm_core_event_registration.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crm_core_event_registration_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'crm_core_events_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_registration_event_crm_core_activity']['id'] = 'reverse_field_registration_event_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_registration_event_crm_core_activity']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_registration_event_crm_core_activity']['field'] = 'reverse_field_registration_event_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_registration_event_crm_core_activity']['label'] = 'Event Registrations';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '30';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_crmer_event_date']['id'] = 'field_crmer_event_date';
  $handler->display->display_options['fields']['field_crmer_event_date']['table'] = 'field_data_field_crmer_event_date';
  $handler->display->display_options['fields']['field_crmer_event_date']['field'] = 'field_crmer_event_date';
  $handler->display->display_options['fields']['field_crmer_event_date']['settings'] = array(
    'format_type' => 'slim',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_crmer_address']['id'] = 'field_crmer_address';
  $handler->display->display_options['fields']['field_crmer_address']['table'] = 'field_data_field_crmer_address';
  $handler->display->display_options['fields']['field_crmer_address']['field'] = 'field_crmer_address';
  $handler->display->display_options['fields']['field_crmer_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_crmer_address']['alter']['text'] = '[field_crmer_address-locality], [field_crmer_address-administrative_area]';
  $handler->display->display_options['fields']['field_crmer_address']['click_sort_column'] = 'locality';
  $handler->display->display_options['fields']['field_crmer_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_crmer_address']['group_column'] = 'entity_id';
  /* Field: SUM(CRM Activity: Number of Attendees) */
  $handler->display->display_options['fields']['field_registration_attendee']['id'] = 'field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['table'] = 'field_data_field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['field'] = 'field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['relationship'] = 'reverse_field_registration_event_crm_core_activity';
  $handler->display->display_options['fields']['field_registration_attendee']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_registration_attendee']['label'] = '';
  $handler->display->display_options['fields']['field_registration_attendee']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_registration_attendee']['alter']['text'] = '[field_registration_attendee] Registered';
  $handler->display->display_options['fields']['field_registration_attendee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registration_attendee']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[view_node] | [edit_node]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'event' => 'event',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['display_description'] = 'Administer CRM Core Events';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/crm-core/events';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['name'] = 'management';
  $export['crm_core_events_admin'] = $view;

  $view = new view();
  $view->name = 'crm_core_events_calendar';
  $view->description = 'Lists crm core events on a calendar';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events Calendar';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'event' => '#ffffff',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Event Date -  start date (field_crmer_event_date) */
  $handler->display->display_options['arguments']['field_crmer_event_date_value']['id'] = 'field_crmer_event_date_value';
  $handler->display->display_options['arguments']['field_crmer_event_date_value']['table'] = 'field_data_field_crmer_event_date';
  $handler->display->display_options['arguments']['field_crmer_event_date_value']['field'] = 'field_crmer_event_date_value';
  $handler->display->display_options['arguments']['field_crmer_event_date_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_crmer_event_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_crmer_event_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_crmer_event_date_value']['summary_options']['items_per_page'] = '25';
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
    'event' => 'event',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'events-calendar';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Events Calendar';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['crm_core_events_calendar'] = $view;

  $view = new view();
  $view->name = 'event_registration_by_contact';
  $view->description = 'List of activities of the contact';
  $view->tag = 'default';
  $view->base_table = 'crm_core_activity';
  $view->human_name = 'Event Registration by contact';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Event Registration';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'This contact has no activity, add an activity above.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: CRM Activity: Activity ID */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['label'] = '';
  $handler->display->display_options['fields']['activity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['activity_id']['hide_alter_empty'] = FALSE;
  /* Field: CRM Activity: Link */
  $handler->display->display_options['fields']['view_crm_activity']['id'] = 'view_crm_activity';
  $handler->display->display_options['fields']['view_crm_activity']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['view_crm_activity']['field'] = 'view_crm_activity';
  $handler->display->display_options['fields']['view_crm_activity']['label'] = '';
  $handler->display->display_options['fields']['view_crm_activity']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_crm_activity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_crm_activity']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['view_crm_activity']['text'] = 'View';
  /* Field: CRM Activity: Edit link */
  $handler->display->display_options['fields']['edit_crm_activity']['id'] = 'edit_crm_activity';
  $handler->display->display_options['fields']['edit_crm_activity']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['edit_crm_activity']['field'] = 'edit_crm_activity';
  $handler->display->display_options['fields']['edit_crm_activity']['label'] = '';
  $handler->display->display_options['fields']['edit_crm_activity']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_crm_activity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_crm_activity']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['edit_crm_activity']['text'] = 'Edit';
  $handler->display->display_options['fields']['edit_crm_activity']['redirect'] = 1;
  /* Field: CRM Activity: Delete link */
  $handler->display->display_options['fields']['delete_crm_activity']['id'] = 'delete_crm_activity';
  $handler->display->display_options['fields']['delete_crm_activity']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['delete_crm_activity']['field'] = 'delete_crm_activity';
  $handler->display->display_options['fields']['delete_crm_activity']['label'] = '';
  $handler->display->display_options['fields']['delete_crm_activity']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_crm_activity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_crm_activity']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['delete_crm_activity']['text'] = 'Delete';
  $handler->display->display_options['fields']['delete_crm_activity']['redirect'] = 1;
  /* Field: CRM Activity: Event */
  $handler->display->display_options['fields']['field_registration_event']['id'] = 'field_registration_event';
  $handler->display->display_options['fields']['field_registration_event']['table'] = 'field_data_field_registration_event';
  $handler->display->display_options['fields']['field_registration_event']['field'] = 'field_registration_event';
  $handler->display->display_options['fields']['field_registration_event']['settings'] = array(
    'link' => 1,
  );
  /* Field: CRM Activity: Status */
  $handler->display->display_options['fields']['field_registration_status']['id'] = 'field_registration_status';
  $handler->display->display_options['fields']['field_registration_status']['table'] = 'field_data_field_registration_status';
  $handler->display->display_options['fields']['field_registration_status']['field'] = 'field_registration_status';
  /* Field: CRM Activity: Event Type */
  $handler->display->display_options['fields']['field_registration_event_type']['id'] = 'field_registration_event_type';
  $handler->display->display_options['fields']['field_registration_event_type']['table'] = 'field_data_field_registration_event_type';
  $handler->display->display_options['fields']['field_registration_event_type']['field'] = 'field_registration_event_type';
  /* Field: CRM Activity: Number of Attendees */
  $handler->display->display_options['fields']['field_registration_attendee']['id'] = 'field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['table'] = 'field_data_field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['field'] = 'field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: CRM Activity: Admission */
  $handler->display->display_options['fields']['field_registration_order']['id'] = 'field_registration_order';
  $handler->display->display_options['fields']['field_registration_order']['table'] = 'field_data_field_registration_order';
  $handler->display->display_options['fields']['field_registration_order']['field'] = 'field_registration_order';
  $handler->display->display_options['fields']['field_registration_order']['settings'] = array(
    'link' => 0,
  );
  /* Field: CRM Activity: Role */
  $handler->display->display_options['fields']['field_registration_role']['id'] = 'field_registration_role';
  $handler->display->display_options['fields']['field_registration_role']['table'] = 'field_data_field_registration_role';
  $handler->display->display_options['fields']['field_registration_role']['field'] = 'field_registration_role';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="ctools-no-js ctools-dropbutton ctools-button" id="ctools-button-[counter]">
  <div class="ctools-link"><a href="#" class="ctools-twisty ctools-text">open</a></div>
  <div class="ctools-content">
  <ul>
          <li>[view_crm_activity]</li>
          <li>[edit_crm_activity]</li>
          <li>[delete_crm_activity]</li>
  </ul>
  </div>
  </div>';
  /* Contextual filter: CRM Activity: Participants (field_activity_participants) */
  $handler->display->display_options['arguments']['field_activity_participants_target_id']['id'] = 'field_activity_participants_target_id';
  $handler->display->display_options['arguments']['field_activity_participants_target_id']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['arguments']['field_activity_participants_target_id']['field'] = 'field_activity_participants_target_id';
  $handler->display->display_options['arguments']['field_activity_participants_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_activity_participants_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_activity_participants_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_activity_participants_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_activity_participants_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: CRM Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event_registration' => 'event_registration',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'crm/contact/%/activity/event_registration';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Event Registration';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 1;
  $export['event_registration_by_contact'] = $view;

  $view = new view();
  $view->name = 'event_registration_reports';
  $view->description = 'A quick report on registration';
  $view->tag = 'default';
  $view->base_table = 'crm_core_activity';
  $view->human_name = 'Event Registration Reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Event Registration Report';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any crm_core_activity entity of bundle event_registration';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'contact_id' => 'contact_id',
    'contact_name' => 'contact_name',
    'contact_name_1' => 'contact_name_1',
    'contact_name_2' => 'contact_name_2',
    'field_contact_email' => 'field_contact_email',
    'title' => 'title',
    'field_registration_attendee' => 'field_registration_attendee',
    'field_registration_role' => 'field_registration_role',
    'field_registration_status' => 'field_registration_status',
    'field_activity_date' => 'field_activity_date',
    'field_billing_address' => 'field_billing_address',
    'field_billing_address_1' => 'field_billing_address_1',
    'field_billing_address_2' => 'field_billing_address_2',
    'field_billing_address_3' => 'field_billing_address_3',
    'field_billing_address_4' => 'field_billing_address_4',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'contact_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'contact_name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'contact_name_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_contact_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_registration_attendee' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_registration_role' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_registration_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_date' => array(
      'sortable' => 0,
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
    'field_billing_address_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_billing_address_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_billing_address_3' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_billing_address_4' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['id'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['field'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['label'] = 'Event registrant';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_registration_event_target_id']['id'] = 'field_registration_event_target_id';
  $handler->display->display_options['relationships']['field_registration_event_target_id']['table'] = 'field_data_field_registration_event';
  $handler->display->display_options['relationships']['field_registration_event_target_id']['field'] = 'field_registration_event_target_id';
  $handler->display->display_options['relationships']['field_registration_event_target_id']['required'] = TRUE;
  /* Field: CRM Activity: Activity ID */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['label'] = '';
  $handler->display->display_options['fields']['activity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activity_id']['element_label_colon'] = FALSE;
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['contact_id']['label'] = '';
  $handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contact_id']['link_to_contact'] = 0;
  /* Field: CRM Contact: Household name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['contact_name']['label'] = 'Name';
  $handler->display->display_options['fields']['contact_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['contact_name']['alter']['text'] = '[contact_name-given], [contact_name-family]';
  $handler->display->display_options['fields']['contact_name']['element_label_colon'] = FALSE;
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
  /* Field: CRM Contact: Email */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['field_contact_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_email']['type'] = 'email_plain';
  /* Field: CRM Activity: Number of Attendees */
  $handler->display->display_options['fields']['field_registration_attendee']['id'] = 'field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['table'] = 'field_data_field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['field'] = 'field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['label'] = 'Attendees';
  $handler->display->display_options['fields']['field_registration_attendee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registration_attendee']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: View */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'View';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'crm/activity/[activity_id]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: edit */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'edit';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'crm/activity/[activity_id]/edit';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: ops */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'ops';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[nothing] / [nothing_1]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Sort criterion: CRM Activity: Date (field_activity_date) */
  $handler->display->display_options['sorts']['field_activity_date_value']['id'] = 'field_activity_date_value';
  $handler->display->display_options['sorts']['field_activity_date_value']['table'] = 'field_data_field_activity_date';
  $handler->display->display_options['sorts']['field_activity_date_value']['field'] = 'field_activity_date_value';
  $handler->display->display_options['sorts']['field_activity_date_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_activity_date_value']['expose']['label'] = 'Donation date';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_registration_event_target_id';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: CRM Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event_registration' => 'event_registration',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Event Registration Report */
  $handler = $view->new_display('page', 'Event Registration Report', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'event_registration_reports_content_:block_1';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view_1']['id'] = 'view_1';
  $handler->display->display_options['header']['view_1']['table'] = 'views';
  $handler->display->display_options['header']['view_1']['field'] = 'view';
  $handler->display->display_options['header']['view_1']['view_to_insert'] = 'event_registration_reports:revenue_per_event';
  $handler->display->display_options['header']['view_1']['inherit_arguments'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="messages warning">There is currently no one registered to this event.</div> ';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CRM Activity: Activity ID */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['label'] = '';
  $handler->display->display_options['fields']['activity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activity_id']['element_label_colon'] = FALSE;
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['contact_id']['label'] = '';
  $handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contact_id']['link_to_contact'] = 0;
  /* Field: CRM Contact: Household name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['contact_name']['label'] = 'Name';
  $handler->display->display_options['fields']['contact_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['contact_name']['alter']['text'] = '[contact_name-given], [contact_name-family]';
  $handler->display->display_options['fields']['contact_name']['element_label_colon'] = FALSE;
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
  /* Field: CRM Contact: Email */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['field_contact_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_email']['type'] = 'email_plain';
  /* Field: CRM Activity: Number of Attendees */
  $handler->display->display_options['fields']['field_registration_attendee']['id'] = 'field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['table'] = 'field_data_field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['field'] = 'field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['label'] = 'Attendees';
  $handler->display->display_options['fields']['field_registration_attendee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registration_attendee']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: View */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'View';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'crm/activity/[activity_id]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: edit */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'edit';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'crm/activity/[activity_id]/edit';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: ops */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'ops';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[nothing] / [nothing_1]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'admin/crm/report/event/registration/%';
  $handler->display->display_options['menu']['title'] = 'Event Registration Reports';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['path'] = 'admin/crm/report/event/registration/%/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Event Revenue Report */
  $handler = $view->new_display('page', 'Event Revenue Report', 'event_revenue_report');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="messages warning">There are no revenue associated with this event</div>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_registration_event_target_id']['id'] = 'field_registration_event_target_id';
  $handler->display->display_options['relationships']['field_registration_event_target_id']['table'] = 'field_data_field_registration_event';
  $handler->display->display_options['relationships']['field_registration_event_target_id']['field'] = 'field_registration_event_target_id';
  $handler->display->display_options['relationships']['field_registration_event_target_id']['required'] = TRUE;
  /* Relationship: Order Referenced */
  $handler->display->display_options['relationships']['field_registration_order_target_id']['id'] = 'field_registration_order_target_id';
  $handler->display->display_options['relationships']['field_registration_order_target_id']['table'] = 'field_data_field_registration_order';
  $handler->display->display_options['relationships']['field_registration_order_target_id']['field'] = 'field_registration_order_target_id';
  $handler->display->display_options['relationships']['field_registration_order_target_id']['ui_name'] = 'Order Referenced';
  /* Relationship: Line Item */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['relationship'] = 'field_registration_order_target_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['ui_name'] = 'Line Item';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CRM Activity: Activity ID */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['label'] = '';
  $handler->display->display_options['fields']['activity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activity_id']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_registration_event_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Event';
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['relationship'] = 'field_registration_order_target_id';
  /* Field: Commerce Order: Billing information */
  $handler->display->display_options['fields']['commerce_customer_billing']['id'] = 'commerce_customer_billing';
  $handler->display->display_options['fields']['commerce_customer_billing']['table'] = 'field_data_commerce_customer_billing';
  $handler->display->display_options['fields']['commerce_customer_billing']['field'] = 'commerce_customer_billing';
  $handler->display->display_options['fields']['commerce_customer_billing']['relationship'] = 'field_registration_order_target_id';
  /* Field: Commerce Line item: Total */
  $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
  $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_total']['type'] = 'commerce_price_formatted_amount';
  $handler->display->display_options['fields']['commerce_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Link */
  $handler->display->display_options['fields']['view_order']['id'] = 'view_order';
  $handler->display->display_options['fields']['view_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['view_order']['field'] = 'view_order';
  $handler->display->display_options['fields']['view_order']['relationship'] = 'field_registration_order_target_id';
  $handler->display->display_options['path'] = 'admin/crm/report/event/revenue/%';

  /* Display: Event Revenue Block */
  $handler = $view->new_display('block', 'Event Revenue Block', 'revenue_per_event');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_tags'] = array(
    0 => 'Array',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_registration_event_target_id']['id'] = 'field_registration_event_target_id';
  $handler->display->display_options['relationships']['field_registration_event_target_id']['table'] = 'field_data_field_registration_event';
  $handler->display->display_options['relationships']['field_registration_event_target_id']['field'] = 'field_registration_event_target_id';
  $handler->display->display_options['relationships']['field_registration_event_target_id']['required'] = TRUE;
  /* Relationship: Order */
  $handler->display->display_options['relationships']['field_registration_order_target_id']['id'] = 'field_registration_order_target_id';
  $handler->display->display_options['relationships']['field_registration_order_target_id']['table'] = 'field_data_field_registration_order';
  $handler->display->display_options['relationships']['field_registration_order_target_id']['field'] = 'field_registration_order_target_id';
  $handler->display->display_options['relationships']['field_registration_order_target_id']['ui_name'] = 'Order';
  $handler->display->display_options['relationships']['field_registration_order_target_id']['label'] = 'Order';
  /* Relationship: Line Item */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['relationship'] = 'field_registration_order_target_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['ui_name'] = 'Line Item';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Line item: Total */
  $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
  $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_total']['group_type'] = 'sum';
  $handler->display->display_options['fields']['commerce_total']['label'] = 'Total Revenue';
  $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_total']['type'] = 'commerce_price_formatted_amount';
  $handler->display->display_options['fields']['commerce_total']['settings'] = array(
    'calculation' => FALSE,
  );
  $handler->display->display_options['fields']['commerce_total']['group_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_total']['group_columns'] = array(
    'amount' => 'amount',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_registration_event_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $export['event_registration_reports'] = $view;

  $view = new view();
  $view->name = 'event_registration_reports_content_';
  $view->description = 'Event registration';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Event Registration Reports (content)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Event Registrations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any crm_core_activity entity of bundle event_registration';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Event Registration */
  $handler->display->display_options['relationships']['reverse_field_registration_event_crm_core_activity']['id'] = 'reverse_field_registration_event_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_registration_event_crm_core_activity']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_registration_event_crm_core_activity']['field'] = 'reverse_field_registration_event_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_registration_event_crm_core_activity']['ui_name'] = 'Event Registration';
  $handler->display->display_options['relationships']['reverse_field_registration_event_crm_core_activity']['label'] = 'Event Registration Activity';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_crmer_event_date']['id'] = 'field_crmer_event_date';
  $handler->display->display_options['fields']['field_crmer_event_date']['table'] = 'field_data_field_crmer_event_date';
  $handler->display->display_options['fields']['field_crmer_event_date']['field'] = 'field_crmer_event_date';
  $handler->display->display_options['fields']['field_crmer_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_crmer_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crmer_event_date']['settings'] = array(
    'format_type' => 'event_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_crmer_address']['id'] = 'field_crmer_address';
  $handler->display->display_options['fields']['field_crmer_address']['table'] = 'field_data_field_crmer_address';
  $handler->display->display_options['fields']['field_crmer_address']['field'] = 'field_crmer_address';
  $handler->display->display_options['fields']['field_crmer_address']['label'] = '';
  $handler->display->display_options['fields']['field_crmer_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_crmer_address']['alter']['text'] = '[field_crmer_address-locality], [field_crmer_address-administrative_area]';
  $handler->display->display_options['fields']['field_crmer_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crmer_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_crmer_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_crmer_address']['group_column'] = 'entity_id';
  /* Field: Content: Registration */
  $handler->display->display_options['fields']['field_crmer_registration']['id'] = 'field_crmer_registration';
  $handler->display->display_options['fields']['field_crmer_registration']['table'] = 'field_data_field_crmer_registration';
  $handler->display->display_options['fields']['field_crmer_registration']['field'] = 'field_crmer_registration';
  $handler->display->display_options['fields']['field_crmer_registration']['label'] = '';
  $handler->display->display_options['fields']['field_crmer_registration']['element_label_colon'] = FALSE;
  /* Field: COUNT(CRM Activity: Number of Attendees) */
  $handler->display->display_options['fields']['field_registration_attendee']['id'] = 'field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['table'] = 'field_data_field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['field'] = 'field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['relationship'] = 'reverse_field_registration_event_crm_core_activity';
  $handler->display->display_options['fields']['field_registration_attendee']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_registration_attendee']['label'] = '';
  $handler->display->display_options['fields']['field_registration_attendee']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_registration_attendee']['alter']['text'] = '[field_registration_attendee-value] Registered';
  $handler->display->display_options['fields']['field_registration_attendee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registration_attendee']['separator'] = ', ';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View Registrations';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/crm/report/event/registration/[nid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'event' => 'event',
  );

  /* Display: Event List */
  $handler = $view->new_display('page', 'Event List', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="messages warning">There is currently no event created in the system</div>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_crmer_event_date']['id'] = 'field_crmer_event_date';
  $handler->display->display_options['fields']['field_crmer_event_date']['table'] = 'field_data_field_crmer_event_date';
  $handler->display->display_options['fields']['field_crmer_event_date']['field'] = 'field_crmer_event_date';
  $handler->display->display_options['fields']['field_crmer_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_crmer_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crmer_event_date']['settings'] = array(
    'format_type' => 'slim',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_crmer_address']['id'] = 'field_crmer_address';
  $handler->display->display_options['fields']['field_crmer_address']['table'] = 'field_data_field_crmer_address';
  $handler->display->display_options['fields']['field_crmer_address']['field'] = 'field_crmer_address';
  $handler->display->display_options['fields']['field_crmer_address']['label'] = '';
  $handler->display->display_options['fields']['field_crmer_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_crmer_address']['alter']['text'] = '[field_crmer_address-locality], [field_crmer_address-administrative_area]';
  $handler->display->display_options['fields']['field_crmer_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crmer_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_crmer_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_crmer_address']['group_column'] = 'entity_id';
  /* Field: Content: Registration */
  $handler->display->display_options['fields']['field_crmer_registration']['id'] = 'field_crmer_registration';
  $handler->display->display_options['fields']['field_crmer_registration']['table'] = 'field_data_field_crmer_registration';
  $handler->display->display_options['fields']['field_crmer_registration']['field'] = 'field_crmer_registration';
  $handler->display->display_options['fields']['field_crmer_registration']['label'] = '';
  $handler->display->display_options['fields']['field_crmer_registration']['element_label_colon'] = FALSE;
  /* Field: COUNT(CRM Activity: Number of Attendees) */
  $handler->display->display_options['fields']['field_registration_attendee']['id'] = 'field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['table'] = 'field_data_field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['field'] = 'field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['relationship'] = 'reverse_field_registration_event_crm_core_activity';
  $handler->display->display_options['fields']['field_registration_attendee']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_registration_attendee']['label'] = '';
  $handler->display->display_options['fields']['field_registration_attendee']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_registration_attendee']['alter']['text'] = '[field_registration_attendee] Registered';
  $handler->display->display_options['fields']['field_registration_attendee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registration_attendee']['separator'] = ', ';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View Registrations';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/crm/report/event/registration/[nid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'View Revenues';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'admin/crm/report/event/revenue/[nid]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'admin/crm/report/event/registration';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Event Registrations';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Event Statistics */
  $handler = $view->new_display('block', 'Event Statistics', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_crmer_event_date']['id'] = 'field_crmer_event_date';
  $handler->display->display_options['fields']['field_crmer_event_date']['table'] = 'field_data_field_crmer_event_date';
  $handler->display->display_options['fields']['field_crmer_event_date']['field'] = 'field_crmer_event_date';
  $handler->display->display_options['fields']['field_crmer_event_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_crmer_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crmer_event_date']['settings'] = array(
    'format_type' => 'slim',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: COUNT(CRM Activity: Number of Attendees) */
  $handler->display->display_options['fields']['field_registration_attendee']['id'] = 'field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['table'] = 'field_data_field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['field'] = 'field_registration_attendee';
  $handler->display->display_options['fields']['field_registration_attendee']['relationship'] = 'reverse_field_registration_event_crm_core_activity';
  $handler->display->display_options['fields']['field_registration_attendee']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_registration_attendee']['label'] = 'Registered Attendees';
  $handler->display->display_options['fields']['field_registration_attendee']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_registration_attendee']['alter']['text'] = '[field_registration_attendee] Registered';
  $handler->display->display_options['fields']['field_registration_attendee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registration_attendee']['separator'] = ', ';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $export['event_registration_reports_content_'] = $view;

  $view = new view();
  $view->name = 'upcoming_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_crmer_event_date']['id'] = 'field_crmer_event_date';
  $handler->display->display_options['fields']['field_crmer_event_date']['table'] = 'field_data_field_crmer_event_date';
  $handler->display->display_options['fields']['field_crmer_event_date']['field'] = 'field_crmer_event_date';
  $handler->display->display_options['fields']['field_crmer_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_crmer_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crmer_event_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Content: Event Date -  start date (field_crmer_event_date) */
  $handler->display->display_options['sorts']['field_crmer_event_date_value']['id'] = 'field_crmer_event_date_value';
  $handler->display->display_options['sorts']['field_crmer_event_date_value']['table'] = 'field_data_field_crmer_event_date';
  $handler->display->display_options['sorts']['field_crmer_event_date_value']['field'] = 'field_crmer_event_date_value';
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
    'event' => 'event',
  );
  /* Filter criterion: Content: Event Date -  start date (field_crmer_event_date) */
  $handler->display->display_options['filters']['field_crmer_event_date_value']['id'] = 'field_crmer_event_date_value';
  $handler->display->display_options['filters']['field_crmer_event_date_value']['table'] = 'field_data_field_crmer_event_date';
  $handler->display->display_options['filters']['field_crmer_event_date_value']['field'] = 'field_crmer_event_date_value';
  $handler->display->display_options['filters']['field_crmer_event_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_crmer_event_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_crmer_event_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_crmer_event_date_value']['year_range'] = '-0:+1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Event Date -  start date (field_crmer_event_date) */
  $handler->display->display_options['sorts']['field_crmer_event_date_value']['id'] = 'field_crmer_event_date_value';
  $handler->display->display_options['sorts']['field_crmer_event_date_value']['table'] = 'field_data_field_crmer_event_date';
  $handler->display->display_options['sorts']['field_crmer_event_date_value']['field'] = 'field_crmer_event_date_value';
  $handler->display->display_options['sorts']['field_crmer_event_date_value']['order'] = 'DESC';
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
    'event' => 'event',
  );
  $handler->display->display_options['path'] = 'events';
  $export['upcoming_events'] = $view;

  return $export;
}
