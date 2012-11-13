<?php
/**
 * @file
 * crm_core_petition.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crm_core_petition_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'petition_report';
  $view->description = 'A report showing petition signers';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Petition Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Petition Report';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any crm_core_activity entity of bundle petition_signature';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_crm_petition_reference_crm_core_activity']['id'] = 'reverse_field_crm_petition_reference_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_crm_petition_reference_crm_core_activity']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_crm_petition_reference_crm_core_activity']['field'] = 'reverse_field_crm_petition_reference_crm_core_activity';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_crm_petition_duration']['id'] = 'field_crm_petition_duration';
  $handler->display->display_options['fields']['field_crm_petition_duration']['table'] = 'field_data_field_crm_petition_duration';
  $handler->display->display_options['fields']['field_crm_petition_duration']['field'] = 'field_crm_petition_duration';
  $handler->display->display_options['fields']['field_crm_petition_duration']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Goal */
  $handler->display->display_options['fields']['field_crm_petition_goal']['id'] = 'field_crm_petition_goal';
  $handler->display->display_options['fields']['field_crm_petition_goal']['table'] = 'field_data_field_crm_petition_goal';
  $handler->display->display_options['fields']['field_crm_petition_goal']['field'] = 'field_crm_petition_goal';
  $handler->display->display_options['fields']['field_crm_petition_goal']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: COUNT(DISTINCT CRM Activity: Activity ID) */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['relationship'] = 'reverse_field_crm_petition_reference_crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['activity_id']['label'] = 'Signer count';
  $handler->display->display_options['fields']['activity_id']['separator'] = ' ';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View signers';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/crm/report/petition/signers/[nid]';
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
    'online_petition' => 'online_petition',
  );

  /* Display: Petition List */
  $handler = $view->new_display('page', 'Petition List', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/crm/report/petition';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Petition Report';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_crm_petition_duration']['id'] = 'field_crm_petition_duration';
  $handler->display->display_options['fields']['field_crm_petition_duration']['table'] = 'field_data_field_crm_petition_duration';
  $handler->display->display_options['fields']['field_crm_petition_duration']['field'] = 'field_crm_petition_duration';
  $handler->display->display_options['fields']['field_crm_petition_duration']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Goal */
  $handler->display->display_options['fields']['field_crm_petition_goal']['id'] = 'field_crm_petition_goal';
  $handler->display->display_options['fields']['field_crm_petition_goal']['table'] = 'field_data_field_crm_petition_goal';
  $handler->display->display_options['fields']['field_crm_petition_goal']['field'] = 'field_crm_petition_goal';
  $handler->display->display_options['fields']['field_crm_petition_goal']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: COUNT(DISTINCT CRM Activity: Activity ID) */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['relationship'] = 'reverse_field_crm_petition_reference_crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['activity_id']['label'] = 'Signer count';
  $handler->display->display_options['fields']['activity_id']['separator'] = ' ';
  $handler->display->display_options['path'] = 'admin/crm/report/petition/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Petition Signers */
  $handler = $view->new_display('page', 'Petition Signers', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_crm_petition_reference_crm_core_activity']['id'] = 'reverse_field_crm_petition_reference_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_crm_petition_reference_crm_core_activity']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_crm_petition_reference_crm_core_activity']['field'] = 'reverse_field_crm_petition_reference_crm_core_activity';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['id'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['field'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['relationship'] = 'reverse_field_crm_petition_reference_crm_core_activity';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Petition';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: CRM Contact: Household name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['contact_name']['label'] = 'Name';
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
  /* Field: CRM Contact: Address */
  $handler->display->display_options['fields']['field_contact_address']['id'] = 'field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['table'] = 'field_data_field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['field'] = 'field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['field_contact_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_contact_address']['alter']['text'] = '[field_contact_address-locality], [field_contact_address-administrative_area]';
  $handler->display->display_options['fields']['field_contact_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_contact_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: CRM Contact: Email */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['relationship'] = 'field_activity_participants_target_id';
  /* Field: CRM Activity: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'reverse_field_crm_petition_reference_crm_core_activity';
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
  $handler->display->display_options['path'] = 'admin/crm/report/petition/signers/%';

  /* Display: Data export 2 */
  $handler = $view->new_display('views_data_export', 'Data export 2', 'views_data_export_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_crm_petition_reference_crm_core_activity']['id'] = 'reverse_field_crm_petition_reference_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_crm_petition_reference_crm_core_activity']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_crm_petition_reference_crm_core_activity']['field'] = 'reverse_field_crm_petition_reference_crm_core_activity';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['id'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['field'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['relationship'] = 'reverse_field_crm_petition_reference_crm_core_activity';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: CRM Contact: Household name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['contact_name']['label'] = 'Name';
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
  /* Field: CRM Contact: Address */
  $handler->display->display_options['fields']['field_contact_address']['id'] = 'field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['table'] = 'field_data_field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['field'] = 'field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['field_contact_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_contact_address']['alter']['text'] = '[field_contact_address-locality], [field_contact_address-administrative_area]';
  $handler->display->display_options['fields']['field_contact_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_contact_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: CRM Activity: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'reverse_field_crm_petition_reference_crm_core_activity';
  $handler->display->display_options['fields']['created']['label'] = 'Signing date';
  $handler->display->display_options['fields']['created']['date_format'] = 'date_format_slim';
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
  $handler->display->display_options['path'] = 'admin/crm/report/petition/signers/%/export';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'page' => 0,
  );

  /* Display: Petition Counter */
  $handler = $view->new_display('block', 'Petition Counter', 'petition_count');
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
  /* Field: COUNT(DISTINCT CRM Activity: Activity ID) */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['relationship'] = 'reverse_field_crm_petition_reference_crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['activity_id']['label'] = '';
  $handler->display->display_options['fields']['activity_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['activity_id']['alter']['text'] = '[activity_id] people signed this petition!';
  $handler->display->display_options['fields']['activity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['activity_id']['separator'] = ' ';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $export['petition_report'] = $view;

  return $export;
}
