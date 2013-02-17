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
  $view->name = 'crm_core_donation_pages_alt';
  $view->description = 'Describes fundraising activity from donation pages';
  $view->tag = 'default';
  $view->base_table = 'crm_core_activity';
  $view->human_name = 'CRM Core Donation Pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Donation Pages';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view crm core donation reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Donation page performance report. <a href="crm/donations">Click here to manage individual donation pages.</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Relationship: Donation Campaign Table: CRM Core Donation Source Field */
  $handler->display->display_options['relationships']['field_donation_campaign_value']['id'] = 'field_donation_campaign_value';
  $handler->display->display_options['relationships']['field_donation_campaign_value']['table'] = 'field_data_field_donation_campaign';
  $handler->display->display_options['relationships']['field_donation_campaign_value']['field'] = 'field_donation_campaign_value';
  /* Field: CRM Donation: Donation page ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['relationship'] = 'field_donation_campaign_value';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_type'] = 'em';
  /* Field: CRM Donation: Donation page title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_donation_campaign_value';
  $handler->display->display_options['fields']['title']['label'] = 'Title';
  $handler->display->display_options['fields']['title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['empty'] = '--- Other Sources ---';
  /* Field: SUM(CRM Activity: Amount) */
  $handler->display->display_options['fields']['field_donation_amounts']['id'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['table'] = 'field_data_field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['field'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_donation_amounts']['label'] = 'Totals';
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['text'] = '$[field_donation_amounts]';
  $handler->display->display_options['fields']['field_donation_amounts']['element_class'] = 'pill';
  $handler->display->display_options['fields']['field_donation_amounts']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_donation_amounts']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: MAX(CRM Activity: Date created) */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['group_type'] = 'max';
  $handler->display->display_options['fields']['created']['label'] = 'Last Donation Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'date_format_slim';
  /* Field: CRM Donation: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'field_donation_campaign_value';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['status']['alter']['text'] = 'Active';
  $handler->display->display_options['fields']['status']['empty'] = 'Not Active';
  $handler->display->display_options['fields']['status']['empty_zero'] = TRUE;
  /* Field: CRM Donation: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_donation_campaign_value';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['text'] = 'Live Page';
  $handler->display->display_options['fields']['path']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['path'] = '[path]';
  /* Field: CRM Donation: Donation page ID */
  $handler->display->display_options['fields']['id_1']['id'] = 'id_1';
  $handler->display->display_options['fields']['id_1']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['id_1']['field'] = 'id';
  $handler->display->display_options['fields']['id_1']['relationship'] = 'field_donation_campaign_value';
  $handler->display->display_options['fields']['id_1']['label'] = 'Manage Link';
  $handler->display->display_options['fields']['id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id_1']['alter']['text'] = 'Manage';
  $handler->display->display_options['fields']['id_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['id_1']['alter']['path'] = 'crm/donations/[id]';
  $handler->display->display_options['fields']['id_1']['empty'] = ' ';
  $handler->display->display_options['fields']['id_1']['empty_zero'] = TRUE;
  /* Field: CRM Donation: Donation page ID */
  $handler->display->display_options['fields']['id_2']['id'] = 'id_2';
  $handler->display->display_options['fields']['id_2']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['id_2']['field'] = 'id';
  $handler->display->display_options['fields']['id_2']['relationship'] = 'field_donation_campaign_value';
  $handler->display->display_options['fields']['id_2']['label'] = 'Overview Link';
  $handler->display->display_options['fields']['id_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id_2']['alter']['text'] = 'Overview';
  $handler->display->display_options['fields']['id_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['id_2']['alter']['path'] = 'crm/reports/donations-page/[id]/overview';
  $handler->display->display_options['fields']['id_2']['empty'] = ' ';
  $handler->display->display_options['fields']['id_2']['empty_zero'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[id_2] [id_1] [path]
';
  /* Filter criterion: CRM Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'donation' => 'donation',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'crm/reports/donations/crm-core-donation-pages';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Donation Pages';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Donations';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['crm_core_donation_pages_alt'] = $view;

  $view = new view();
  $view->name = 'crm_core_donation_sybunt_report';
  $view->description = 'Standard LYBUNT/SYBUNT reports for CRM Core Donations';
  $view->tag = 'default';
  $view->base_table = 'crm_core_contact';
  $view->human_name = 'CRM Core Donation LYBUNT/SYBUNT Reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'LYBUNT';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'List of donors who donated last year but not this year.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found. Either you don\'t have many donations, or your donors are really committed.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
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
  /* Field: CRM Contact: Organization name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['label'] = 'Name';
  $handler->display->display_options['fields']['contact_name']['element_type'] = 'strong';
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
  /* Field: SUM(CRM Activity: Amount) */
  $handler->display->display_options['fields']['field_donation_amounts']['id'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['table'] = 'field_data_field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['field'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['relationship'] = 'reverse_field_activity_participants_crm_core_activity';
  $handler->display->display_options['fields']['field_donation_amounts']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_donation_amounts']['label'] = 'Total';
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['text'] = '$[field_donation_amounts]';
  $handler->display->display_options['fields']['field_donation_amounts']['element_class'] = 'pill';
  $handler->display->display_options['fields']['field_donation_amounts']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: MAX(CRM Activity: Received Date) */
  $handler->display->display_options['fields']['field_donation_receive_date']['id'] = 'field_donation_receive_date';
  $handler->display->display_options['fields']['field_donation_receive_date']['table'] = 'field_data_field_donation_receive_date';
  $handler->display->display_options['fields']['field_donation_receive_date']['field'] = 'field_donation_receive_date';
  $handler->display->display_options['fields']['field_donation_receive_date']['relationship'] = 'reverse_field_activity_participants_crm_core_activity';
  $handler->display->display_options['fields']['field_donation_receive_date']['group_type'] = 'max';
  $handler->display->display_options['fields']['field_donation_receive_date']['label'] = 'Last Donation Date';
  $handler->display->display_options['fields']['field_donation_receive_date']['settings'] = array(
    'format_type' => 'date_format_slim',
    'fromto' => '',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'View Contact';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View Contact';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'crm/contact/[contact_id]';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Activities';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'View Activities';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'crm/contact/[contact_id]/activity';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[nothing] | [nothing_1]';
  /* Sort criterion: CRM Activity: Received Date (field_donation_receive_date) */
  $handler->display->display_options['sorts']['field_donation_receive_date_value']['id'] = 'field_donation_receive_date_value';
  $handler->display->display_options['sorts']['field_donation_receive_date_value']['table'] = 'field_data_field_donation_receive_date';
  $handler->display->display_options['sorts']['field_donation_receive_date_value']['field'] = 'field_donation_receive_date_value';
  $handler->display->display_options['sorts']['field_donation_receive_date_value']['relationship'] = 'reverse_field_activity_participants_crm_core_activity';
  /* Filter criterion: CRM Contact: Contact Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_contact';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'individual' => 'individual',
  );
  /* Filter criterion: CRM Activity: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_activity_participants_crm_core_activity';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'donation' => 'donation',
  );
  /* Filter criterion: CRM Activity: Received Date (field_donation_receive_date) */
  $handler->display->display_options['filters']['field_donation_receive_date_value']['id'] = 'field_donation_receive_date_value';
  $handler->display->display_options['filters']['field_donation_receive_date_value']['table'] = 'field_data_field_donation_receive_date';
  $handler->display->display_options['filters']['field_donation_receive_date_value']['field'] = 'field_donation_receive_date_value';
  $handler->display->display_options['filters']['field_donation_receive_date_value']['relationship'] = 'reverse_field_activity_participants_crm_core_activity';
  $handler->display->display_options['filters']['field_donation_receive_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_donation_receive_date_value']['default_date'] = '-1 year';
  /* Filter criterion: CRM Activity: Received Date (field_donation_receive_date) */
  $handler->display->display_options['filters']['field_donation_receive_date_value_1']['id'] = 'field_donation_receive_date_value_1';
  $handler->display->display_options['filters']['field_donation_receive_date_value_1']['table'] = 'field_data_field_donation_receive_date';
  $handler->display->display_options['filters']['field_donation_receive_date_value_1']['field'] = 'field_donation_receive_date_value';
  $handler->display->display_options['filters']['field_donation_receive_date_value_1']['relationship'] = 'reverse_field_activity_participants_crm_core_activity';
  $handler->display->display_options['filters']['field_donation_receive_date_value_1']['operator'] = '>';
  $handler->display->display_options['filters']['field_donation_receive_date_value_1']['default_date'] = '-2 year';

  /* Display: Page - LYBUNT */
  $handler = $view->new_display('page', 'Page - LYBUNT', 'lybunt');
  $handler->display->display_options['display_description'] = 'Display of the LYBUNT report.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'crm/reports/donors/lybunt';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'LYBUNT';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Page - SYBUNT */
  $handler = $view->new_display('page', 'Page - SYBUNT', 'sybunt');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'SYBUNT';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'List of donors who donated some year but not this year.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: CRM Contact: Contact Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_contact';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'individual' => 'individual',
  );
  /* Filter criterion: CRM Activity: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_activity_participants_crm_core_activity';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'donation' => 'donation',
  );
  /* Filter criterion: CRM Activity: Received Date (field_donation_receive_date) */
  $handler->display->display_options['filters']['field_donation_receive_date_value']['id'] = 'field_donation_receive_date_value';
  $handler->display->display_options['filters']['field_donation_receive_date_value']['table'] = 'field_data_field_donation_receive_date';
  $handler->display->display_options['filters']['field_donation_receive_date_value']['field'] = 'field_donation_receive_date_value';
  $handler->display->display_options['filters']['field_donation_receive_date_value']['relationship'] = 'reverse_field_activity_participants_crm_core_activity';
  $handler->display->display_options['filters']['field_donation_receive_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_donation_receive_date_value']['default_date'] = '-2 year';
  $handler->display->display_options['filters']['field_donation_receive_date_value']['year_range'] = '-10:+0';
  $handler->display->display_options['path'] = 'crm/reports/donors/sybunt';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'SYBUNT';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $export['crm_core_donation_sybunt_report'] = $view;

  $view = new view();
  $view->name = 'crm_core_donations_time_of_day_report';
  $view->description = 'Shows the times of day donations have been received';
  $view->tag = 'default';
  $view->base_table = 'crm_core_activity';
  $view->human_name = 'CRM Core Donations Time of Day Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Donations Day of Week';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view crm core donation reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: CRM Activity: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'day_of_week';
  /* Field: CRM Activity: Activity ID */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['activity_id']['label'] = 'Donations Received';
  /* Field: CRM Activity: Amount */
  $handler->display->display_options['fields']['field_donation_amounts']['id'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['table'] = 'field_data_field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['field'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['text'] = '$[field_donation_amounts]';
  $handler->display->display_options['fields']['field_donation_amounts']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: CRM Activity: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'crm_core_activity';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_donation_campaign_value']['id'] = 'field_donation_campaign_value';
  $handler->display->display_options['arguments']['field_donation_campaign_value']['table'] = 'field_data_field_donation_campaign';
  $handler->display->display_options['arguments']['field_donation_campaign_value']['field'] = 'field_donation_campaign_value';
  $handler->display->display_options['arguments']['field_donation_campaign_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_donation_campaign_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_donation_campaign_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_donation_campaign_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_donation_campaign_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_donation_campaign_value']['validate']['type'] = 'numeric';
  $handler->display->display_options['arguments']['field_donation_campaign_value']['validate']['fail'] = 'ignore';
  /* Filter criterion: CRM Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'donation' => 'donation',
  );

  /* Display: Time of Day */
  $handler = $view->new_display('page', 'Time of Day', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Donations Time of Day';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CRM Activity: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'hour_of_the_day_long';
  /* Field: CRM Activity: Activity ID */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['activity_id']['label'] = 'Donations Received';
  /* Field: CRM Activity: Amount */
  $handler->display->display_options['fields']['field_donation_amounts']['id'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['table'] = 'field_data_field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['field'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['text'] = '$[field_donation_amounts]';
  $handler->display->display_options['fields']['field_donation_amounts']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['path'] = 'crm/reports/donations/crm-core-donations-time-of-day-report';
  $handler->display->display_options['menu']['title'] = 'Time / Day';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Day of Week */
  $handler = $view->new_display('page', 'Day of Week', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['path'] = 'crm/reports/crm-core-donations-day-of-week';
  $export['crm_core_donations_time_of_day_report'] = $view;

  $view = new view();
  $view->name = 'crm_core_donations_widget';
  $view->description = 'Displays some total values related to donations. Just an overview, to get people to the preview page.';
  $view->tag = 'default';
  $view->base_table = 'crm_core_activity';
  $view->human_name = 'CRM Core Donations Widget';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'crm-core-widget-info';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Donors';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'crm_core_donations_widget:block_2';
  /* Field: SUM(CRM Activity: Amount) */
  $handler->display->display_options['fields']['field_donation_amounts']['id'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['table'] = 'field_data_field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['field'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_donation_amounts']['label'] = 'Total Donations';
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['text'] = '$[field_donation_amounts]';
  $handler->display->display_options['fields']['field_donation_amounts']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_donation_amounts']['empty'] = '$0';
  $handler->display->display_options['fields']['field_donation_amounts']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_donation_amounts']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Filter criterion: CRM Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'donation' => 'donation',
  );

  /* Display: Block - Total Donations */
  $handler = $view->new_display('block', 'Block - Total Donations', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'crm_core_widget';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'crm_core_donations_widget:block_2';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view_1']['id'] = 'view_1';
  $handler->display->display_options['header']['view_1']['table'] = 'views';
  $handler->display->display_options['header']['view_1']['field'] = 'view';
  $handler->display->display_options['header']['view_1']['view_to_insert'] = 'crm_core_donations_widget:block_3';

  /* Display: Block - Donations Received */
  $handler = $view->new_display('block', 'Block - Donations Received', 'block_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Donations Received';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(CRM Activity: Activity ID) */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['group_type'] = 'count';
  $handler->display->display_options['fields']['activity_id']['label'] = '';
  $handler->display->display_options['fields']['activity_id']['alter']['text'] = '$[activity_id]';
  $handler->display->display_options['fields']['activity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['activity_id']['empty'] = '0';
  $handler->display->display_options['fields']['activity_id']['hide_alter_empty'] = FALSE;

  /* Display: Block - Total Donors */
  $handler = $view->new_display('block', 'Block - Total Donors', 'block_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Individual Donors';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['id'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['field'] = 'field_activity_participants_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(DISTINCT CRM Contact: Contact ID) */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['contact_id']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['contact_id']['label'] = '';
  $handler->display->display_options['fields']['contact_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contact_id']['empty'] = '0';
  $handler->display->display_options['fields']['contact_id']['hide_alter_empty'] = FALSE;
  $export['crm_core_donations_widget'] = $view;

  $view = new view();
  $view->name = 'crm_core_donor';
  $view->description = 'Details donors in the system';
  $view->tag = 'default';
  $view->base_table = 'crm_core_activity';
  $view->human_name = 'CRM Core Donor';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Donor';
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
  $handler->display->display_options['style_options']['columns'] = array(
    'contact_id' => 'contact_id',
    'contact_name' => 'contact_name',
    'contact_name_1' => 'contact_name_1',
    'field_donation_amounts' => 'field_donation_amounts',
    'created' => 'created',
    'field_billing_address' => 'field_billing_address',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
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
    'field_donation_amounts' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_billing_address' => array(
      'sortable' => 0,
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
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['link_to_contact'] = 0;
  /* Field: CRM Contact: Organization name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['contact_name']['label'] = 'First';
  $handler->display->display_options['fields']['contact_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['contact_name']['settings'] = array(
    'format' => 'given',
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
  /* Field: CRM Contact: Organization name */
  $handler->display->display_options['fields']['contact_name_1']['id'] = 'contact_name_1';
  $handler->display->display_options['fields']['contact_name_1']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name_1']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name_1']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['contact_name_1']['label'] = 'Last';
  $handler->display->display_options['fields']['contact_name_1']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['contact_name_1']['settings'] = array(
    'format' => 'family',
    'markup' => 0,
    'output' => 'default',
    'multiple' => 'default',
    'multiple_delimiter' => ', ',
    'multiple_and' => 'text',
    'multiple_delimiter_precedes_last' => 'never',
    'multiple_el_al_min' => '3',
    'multiple_el_al_first' => '1',
  );
  $handler->display->display_options['fields']['contact_name_1']['group_column'] = 'entity_id';
  /* Field: SUM(CRM Activity: Amount) */
  $handler->display->display_options['fields']['field_donation_amounts']['id'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['table'] = 'field_data_field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['field'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['text'] = '$[field_donation_amounts] ';
  $handler->display->display_options['fields']['field_donation_amounts']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: MAX(CRM Activity: Date created) */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['group_type'] = 'max';
  $handler->display->display_options['fields']['created']['label'] = 'Last Donation';
  $handler->display->display_options['fields']['created']['date_format'] = 'date_format_slim';
  /* Field: CRM Contact: Billing Address */
  $handler->display->display_options['fields']['field_billing_address']['id'] = 'field_billing_address';
  $handler->display->display_options['fields']['field_billing_address']['table'] = 'field_data_field_billing_address';
  $handler->display->display_options['fields']['field_billing_address']['field'] = 'field_billing_address';
  $handler->display->display_options['fields']['field_billing_address']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['field_billing_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_billing_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_billing_address']['group_column'] = 'entity_id';
  /* Filter criterion: CRM Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'donation' => 'donation',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'crm/reports/donors/overview';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Donors';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Donors';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['crm_core_donor'] = $view;

  $view = new view();
  $view->name = 'donations_overview_alt';
  $view->description = 'A list of all donations recorded in the system. Filterable by date.';
  $view->tag = 'default';
  $view->base_table = 'crm_core_activity';
  $view->human_name = 'CRM Core Donations Overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Donations Overview';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view crm core donation reports';
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
    'contact_id' => 'contact_id',
    'field_donation_amounts' => 'field_donation_amounts',
    'created' => 'created',
    'contact_name' => 'contact_name',
    'field_billing_address' => 'field_billing_address',
    'id' => 'id',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'contact_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_donation_amounts' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
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
    'id' => array(
      'sortable' => 0,
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
  );
  $handler->display->display_options['style_options']['summary'] = 'List of all donations.';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['empty'] = TRUE;
  $handler->display->display_options['header']['view']['view_to_insert'] = 'donations_totals:default';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Displaying @start - @end of @total donations stored in the system.';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="pull-right"><a class="btn btn-small btn-primary" href="/crm/reports/donations-overview/export">Export to CSV.</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry! No donations could be found matching the provided criteria, or no donations have yet been recorded.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['id'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['field'] = 'field_activity_participants_target_id';
  /* Relationship: Donation Campaign Table: CRM Core Donation Source Field */
  $handler->display->display_options['relationships']['field_donation_campaign_value']['id'] = 'field_donation_campaign_value';
  $handler->display->display_options['relationships']['field_donation_campaign_value']['table'] = 'field_data_field_donation_campaign';
  $handler->display->display_options['relationships']['field_donation_campaign_value']['field'] = 'field_donation_campaign_value';
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['link_to_contact'] = 0;
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
  /* Field: CRM Activity: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: CRM Contact: Organization name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['contact_name']['label'] = 'Donor';
  $handler->display->display_options['fields']['contact_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['contact_name']['alter']['path'] = 'crm/contact/[contact_id]/activity/donation';
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
  /* Field: CRM Donation: Donation page ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['relationship'] = 'field_donation_campaign_value';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: CRM Donation: Donation page title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_donation_campaign_value';
  $handler->display->display_options['fields']['title']['label'] = 'Donation Page';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'crm/reports/donations-page/overview/[id]';
  /* Sort criterion: CRM Activity: Date (field_activity_date) */
  $handler->display->display_options['sorts']['field_activity_date_value']['id'] = 'field_activity_date_value';
  $handler->display->display_options['sorts']['field_activity_date_value']['table'] = 'field_data_field_activity_date';
  $handler->display->display_options['sorts']['field_activity_date_value']['field'] = 'field_activity_date_value';
  $handler->display->display_options['sorts']['field_activity_date_value']['order'] = 'DESC';
  /* Contextual filter: CRM Donation: Donation page ID */
  $handler->display->display_options['arguments']['id']['id'] = 'id';
  $handler->display->display_options['arguments']['id']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['arguments']['id']['field'] = 'id';
  $handler->display->display_options['arguments']['id']['relationship'] = 'field_donation_campaign_value';
  $handler->display->display_options['arguments']['id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: CRM Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'donation' => 'donation',
  );
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

  /* Display: Overview */
  $handler = $view->new_display('page', 'Overview', 'page');
  $handler->display->display_options['display_description'] = 'Online view of donations, including filters for date and amount.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Displaying @start - @end of @total donations stored in the system. <a href="/crm/reports/donations/overview/all">View All</a>';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="pull-right"><a class="btn btn-small btn-warning" href="/crm/reports/donations/overview/export/all"><i class="icon-download icon-white"></i> Export to CSV</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'crm/reports/donations/overview';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Donations Overview';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Overview';
  $handler->display->display_options['tab_options']['weight'] = '-1';

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
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: CRM Contact: Organization name */
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: CRM Donation: Donation page ID */
  $handler->display->display_options['arguments']['id']['id'] = 'id';
  $handler->display->display_options['arguments']['id']['table'] = 'crm_core_donation_page';
  $handler->display->display_options['arguments']['id']['field'] = 'id';
  $handler->display->display_options['arguments']['id']['relationship'] = 'field_donation_campaign_value';
  $handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'crm/reports/donations/overview/export/%';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
  );

  /* Display: Overview: View All */
  $handler = $view->new_display('page', 'Overview: View All', 'page_2');
  $handler->display->display_options['display_description'] = 'Online view of donations, including filters for date and amount.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Displaying @start - @end of @total donations stored in the system.';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="pull-right"><a class="btn btn-small btn-warning" href="/crm/reports/donations/overview/export/all"><i class="icon-download icon-white"></i> Export to CSV</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'crm/reports/donations/overview/all';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Donations Overview';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Individual Page */
  $handler = $view->new_display('page', 'Individual Page', 'page_1');
  $handler->display->display_options['display_description'] = 'Online view of donations for a specific donation page.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Displaying @start - @end of @total donations stored in the system. <a href="crm/reports/donations-overview/view-all">View All</a>';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="pull-right"><a class="btn btn-small btn-warning" href="/crm/reports/donations-overview/export"><i class="icon-download icon-white"></i> Export to CSV</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_donation_campaign_value']['id'] = 'field_donation_campaign_value';
  $handler->display->display_options['arguments']['field_donation_campaign_value']['table'] = 'field_data_field_donation_campaign';
  $handler->display->display_options['arguments']['field_donation_campaign_value']['field'] = 'field_donation_campaign_value';
  $handler->display->display_options['arguments']['field_donation_campaign_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_donation_campaign_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_donation_campaign_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_donation_campaign_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_donation_campaign_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'crm/reports/donations-page/%/overview';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Donations Overview';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Overview';
  $handler->display->display_options['tab_options']['weight'] = '-1';
  $export['donations_overview_alt'] = $view;

  $view = new view();
  $view->name = 'donations_totals';
  $view->description = 'Total donations received. Can be filtered by donation page to provide filtered results.';
  $view->tag = 'default';
  $view->base_table = 'crm_core_activity';
  $view->human_name = 'CRM Core Donations: Totals';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'crm-core-overview-widget';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: SUM(CRM Activity: Amount) */
  $handler->display->display_options['fields']['field_donation_amounts']['id'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['table'] = 'field_data_field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['field'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_donation_amounts']['label'] = 'Total Raised';
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_donation_amounts']['alter']['text'] = '$[field_donation_amounts]';
  $handler->display->display_options['fields']['field_donation_amounts']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: AVG(CRM Activity: Amount) */
  $handler->display->display_options['fields']['field_donation_amounts_1']['id'] = 'field_donation_amounts_1';
  $handler->display->display_options['fields']['field_donation_amounts_1']['table'] = 'field_data_field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts_1']['field'] = 'field_donation_amounts';
  $handler->display->display_options['fields']['field_donation_amounts_1']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_donation_amounts_1']['label'] = 'Average Amount';
  $handler->display->display_options['fields']['field_donation_amounts_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_donation_amounts_1']['alter']['text'] = '$[field_donation_amounts_1]';
  $handler->display->display_options['fields']['field_donation_amounts_1']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: COUNT(CRM Activity: Activity ID) */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['group_type'] = 'count';
  $handler->display->display_options['fields']['activity_id']['label'] = 'Total Donations';
  /* Filter criterion: CRM Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'donation' => 'donation',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['donations_totals'] = $view;

  return $export;
}
