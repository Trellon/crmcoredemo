<?php
/**
 * @file
 * crm_core_news.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crm_core_news_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'crm_subscribers_report';
  $view->description = 'List of activities of the contact';
  $view->tag = 'default';
  $view->base_table = 'crm_core_activity';
  $view->human_name = 'Newsletter Subscription Report (detail)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Newsletter subscription: detail';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view crm core reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_activity_date' => 'field_activity_date',
    'contact_name' => 'contact_name',
    'field_newsletter_category_1' => 'field_newsletter_category_1',
    'field_newsletter_action' => 'field_newsletter_action',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_activity_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
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
    'field_newsletter_category_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_newsletter_action' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There is no subscriptions yet.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['id'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['field'] = 'field_activity_participants_target_id';
  /* Field: CRM Activity: Date */
  $handler->display->display_options['fields']['field_activity_date']['id'] = 'field_activity_date';
  $handler->display->display_options['fields']['field_activity_date']['table'] = 'field_data_field_activity_date';
  $handler->display->display_options['fields']['field_activity_date']['field'] = 'field_activity_date';
  $handler->display->display_options['fields']['field_activity_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activity_date']['settings'] = array(
    'format_type' => 'short',
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
  $handler->display->display_options['fields']['contact_name']['label'] = 'Contact Name';
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
  /* Field: CRM Activity: Newsletter Category */
  $handler->display->display_options['fields']['field_newsletter_category_1']['id'] = 'field_newsletter_category_1';
  $handler->display->display_options['fields']['field_newsletter_category_1']['table'] = 'field_data_field_newsletter_category';
  $handler->display->display_options['fields']['field_newsletter_category_1']['field'] = 'field_newsletter_category';
  $handler->display->display_options['fields']['field_newsletter_category_1']['label'] = 'Category';
  $handler->display->display_options['fields']['field_newsletter_category_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_newsletter_category_1']['group_columns'] = array(
    'tid' => 'tid',
  );
  /* Field: CRM Activity: Newsletter Action */
  $handler->display->display_options['fields']['field_newsletter_action']['id'] = 'field_newsletter_action';
  $handler->display->display_options['fields']['field_newsletter_action']['table'] = 'field_data_field_newsletter_action';
  $handler->display->display_options['fields']['field_newsletter_action']['field'] = 'field_newsletter_action';
  $handler->display->display_options['fields']['field_newsletter_action']['label'] = 'Action';
  /* Sort criterion: CRM Activity: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'crm_core_activity';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Date: Date (crm_core_activity) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['granularity'] = 'month';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-10:+10';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'crm_core_activity.created' => 'crm_core_activity.created',
  );
  /* Filter criterion: CRM Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news_subscription' => 'news_subscription',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: CRM Activity: Newsletter Action (field_newsletter_action) */
  $handler->display->display_options['filters']['field_newsletter_action_value']['id'] = 'field_newsletter_action_value';
  $handler->display->display_options['filters']['field_newsletter_action_value']['table'] = 'field_data_field_newsletter_action';
  $handler->display->display_options['filters']['field_newsletter_action_value']['field'] = 'field_newsletter_action_value';
  $handler->display->display_options['filters']['field_newsletter_action_value']['group'] = 1;
  $handler->display->display_options['filters']['field_newsletter_action_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_newsletter_action_value']['expose']['operator_id'] = 'field_newsletter_action_value_op';
  $handler->display->display_options['filters']['field_newsletter_action_value']['expose']['label'] = 'Action';
  $handler->display->display_options['filters']['field_newsletter_action_value']['expose']['operator'] = 'field_newsletter_action_value_op';
  $handler->display->display_options['filters']['field_newsletter_action_value']['expose']['identifier'] = 'field_newsletter_action_value';
  $handler->display->display_options['filters']['field_newsletter_action_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Activity: Newsletter Category (field_newsletter_category) */
  $handler->display->display_options['filters']['field_newsletter_category_tid']['id'] = 'field_newsletter_category_tid';
  $handler->display->display_options['filters']['field_newsletter_category_tid']['table'] = 'field_data_field_newsletter_category';
  $handler->display->display_options['filters']['field_newsletter_category_tid']['field'] = 'field_newsletter_category_tid';
  $handler->display->display_options['filters']['field_newsletter_category_tid']['value'] = '';
  $handler->display->display_options['filters']['field_newsletter_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_newsletter_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_newsletter_category_tid']['expose']['operator_id'] = 'field_newsletter_category_tid_op';
  $handler->display->display_options['filters']['field_newsletter_category_tid']['expose']['label'] = 'Newsletter Category';
  $handler->display->display_options['filters']['field_newsletter_category_tid']['expose']['operator'] = 'field_newsletter_category_tid_op';
  $handler->display->display_options['filters']['field_newsletter_category_tid']['expose']['identifier'] = 'field_newsletter_category_tid';
  $handler->display->display_options['filters']['field_newsletter_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_newsletter_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_newsletter_category_tid']['vocabulary'] = 'newsletter';

  /* Display: Detail */
  $handler = $view->new_display('page', 'Detail', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'crm/reports/news/detail';
  $export['crm_subscribers_report'] = $view;

  $view = new view();
  $view->name = 'crm_subscriptions_report';
  $view->description = 'List of activities of the contact';
  $view->tag = 'default';
  $view->base_table = 'crm_core_activity';
  $view->human_name = 'Newsletter Subscription Report (summary)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Newsletter subscription: summary';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view crm core reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_activity_date',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There is no subscriptions yet.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: CRM Activity: Newsletter Category (field_newsletter_category) */
  $handler->display->display_options['relationships']['field_newsletter_category_tid']['id'] = 'field_newsletter_category_tid';
  $handler->display->display_options['relationships']['field_newsletter_category_tid']['table'] = 'field_data_field_newsletter_category';
  $handler->display->display_options['relationships']['field_newsletter_category_tid']['field'] = 'field_newsletter_category_tid';
  /* Field: Simplenews category: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'simplenews_category';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'field_newsletter_category_tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: CRM Activity: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: CRM Activity: Newsletter Action */
  $handler->display->display_options['fields']['field_newsletter_action']['id'] = 'field_newsletter_action';
  $handler->display->display_options['fields']['field_newsletter_action']['table'] = 'field_data_field_newsletter_action';
  $handler->display->display_options['fields']['field_newsletter_action']['field'] = 'field_newsletter_action';
  $handler->display->display_options['fields']['field_newsletter_action']['label'] = '';
  $handler->display->display_options['fields']['field_newsletter_action']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_newsletter_action']['element_label_colon'] = FALSE;
  /* Field: CRM Activity: Date */
  $handler->display->display_options['fields']['field_activity_date']['id'] = 'field_activity_date';
  $handler->display->display_options['fields']['field_activity_date']['table'] = 'field_data_field_activity_date';
  $handler->display->display_options['fields']['field_activity_date']['field'] = 'field_activity_date';
  $handler->display->display_options['fields']['field_activity_date']['label'] = '';
  $handler->display->display_options['fields']['field_activity_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_activity_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activity_date']['settings'] = array(
    'format_type' => 'crm_core_month_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: CRM Activity: Newsletter Category */
  $handler->display->display_options['fields']['field_newsletter_category_1']['id'] = 'field_newsletter_category_1';
  $handler->display->display_options['fields']['field_newsletter_category_1']['table'] = 'field_data_field_newsletter_category';
  $handler->display->display_options['fields']['field_newsletter_category_1']['field'] = 'field_newsletter_category';
  $handler->display->display_options['fields']['field_newsletter_category_1']['label'] = '';
  $handler->display->display_options['fields']['field_newsletter_category_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_newsletter_category_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_newsletter_category_1']['group_columns'] = array(
    'tid' => 'tid',
  );
  /* Field: COUNT(CRM Activity: Newsletter Category) */
  $handler->display->display_options['fields']['field_newsletter_category']['id'] = 'field_newsletter_category';
  $handler->display->display_options['fields']['field_newsletter_category']['table'] = 'field_data_field_newsletter_category';
  $handler->display->display_options['fields']['field_newsletter_category']['field'] = 'field_newsletter_category';
  $handler->display->display_options['fields']['field_newsletter_category']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_newsletter_category']['label'] = '';
  $handler->display->display_options['fields']['field_newsletter_category']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_newsletter_category']['alter']['path'] = '/crm/reports/news/detail/?field_newsletter_category_tid=[tid]';
  $handler->display->display_options['fields']['field_newsletter_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_newsletter_category']['separator'] = ', ';
  /* Filter criterion: CRM Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news_subscription' => 'news_subscription',
  );
  /* Filter criterion: CRM Activity: Newsletter Action (field_newsletter_action) */
  $handler->display->display_options['filters']['field_newsletter_action_value']['id'] = 'field_newsletter_action_value';
  $handler->display->display_options['filters']['field_newsletter_action_value']['table'] = 'field_data_field_newsletter_action';
  $handler->display->display_options['filters']['field_newsletter_action_value']['field'] = 'field_newsletter_action_value';
  $handler->display->display_options['filters']['field_newsletter_action_value']['value'] = array(
    'subscribe' => 'subscribe',
    'unsubscribe' => 'unsubscribe',
  );
  $handler->display->display_options['filters']['field_newsletter_action_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_newsletter_action_value']['expose']['operator_id'] = 'field_newsletter_action_value_op';
  $handler->display->display_options['filters']['field_newsletter_action_value']['expose']['label'] = 'Action';
  $handler->display->display_options['filters']['field_newsletter_action_value']['expose']['operator'] = 'field_newsletter_action_value_op';
  $handler->display->display_options['filters']['field_newsletter_action_value']['expose']['identifier'] = 'field_newsletter_action_value';
  $handler->display->display_options['filters']['field_newsletter_action_value']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_newsletter_action_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Summary */
  $handler = $view->new_display('page', 'Summary', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'crm/reports/news/summary';
  $export['crm_subscriptions_report'] = $view;

  $view = new view();
  $view->name = 'news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
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
    'simplenews' => 'simplenews',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'news';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'News';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'news.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );

  /* Display: Recent News */
  $handler = $view->new_display('block', 'Recent News', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['news'] = $view;

  return $export;
}
