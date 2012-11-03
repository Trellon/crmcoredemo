<?php
function crm_core_profile_views_default_views() {
  $view = new view();
  $view->name = 'crm_core_profile';
  $view->description = 'Display a list of CRM Core Profile forms';
  $view->tag = 'default';
  $view->base_table = 'crm_core_profile';
  $view->human_name = 'CRM Core Profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CRM Core Profile';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer crm core profile forms';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<a href="profile/new">Add a new Profile</a>';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="messages warning">You have not created any CRM Core Profile forms yet.</div>';
  /* Field: CRM Profile: Profile form name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'crm_core_profile';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Machine Name';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Field: CRM Profile: Profile form label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'crm_core_profile';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = 'Form name';
  $handler->display->display_options['fields']['label']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['path'] = 'crm_core_profile/[name]';
  $handler->display->display_options['fields']['label']['hide_alter_empty'] = FALSE;
  /* Field: CRM Profile: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'crm_core_profile';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = FALSE;
  /* Field: CRM Profile: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'crm_core_profile';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  /* Field: Edit Link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Edit Link';
  $handler->display->display_options['fields']['nothing']['label'] = 'Edit Link';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/structure/crm/profile/[name]';
  /* Field: Delete Link */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Delete Link';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Delete Link';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Delete';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'admin/structure/crm/profile/[name]/delete';
  /* Field: Action */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Action';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Action';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[nothing] / [nothing_1]';
  
  /* Display: CRM Profile forms */
  $handler = $view->new_display('page', 'CRM Profile forms', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/structure/crm/profile';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'CRM Core Profile';
  $handler->display->display_options['menu']['description'] = 'List of CRM Core Profile Form';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';

  $views['crm_core_profile'] = $view; 
  return $views;
}