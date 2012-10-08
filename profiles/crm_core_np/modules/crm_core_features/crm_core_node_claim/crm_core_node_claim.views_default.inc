<?php
/**
 * @file
 * crm_core_node_claim.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crm_core_node_claim_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'resource_claim_queue';
  $view->description = 'Provide a list of resource claim that are pending';
  $view->tag = 'default';
  $view->base_table = 'crm_core_activity';
  $view->human_name = 'Resource Claim Queue';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Resource Claim Queue';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer crm core node claim';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['group_rendered'] = 1;
  $handler->display->display_options['style_options']['columns'] = array(
    'activity_id' => 'activity_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'activity_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Below are list of resource claims filed by different users, please click each one to see the details of the claim. Once the claim is approved the user will have the ownership of the resource and will be able to manage it.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<table><tr><td>There is currently no node claims in the queue</td></tr></table>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_claim_reference_target_id']['id'] = 'field_claim_reference_target_id';
  $handler->display->display_options['relationships']['field_claim_reference_target_id']['table'] = 'field_data_field_claim_reference';
  $handler->display->display_options['relationships']['field_claim_reference_target_id']['field'] = 'field_claim_reference_target_id';
  $handler->display->display_options['relationships']['field_claim_reference_target_id']['label'] = 'Resource node';
  $handler->display->display_options['relationships']['field_claim_reference_target_id']['required'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['id'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['field'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['label'] = 'Claimant';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['required'] = 0;
  /* Field: CRM Activity: Activity ID */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['label'] = 'Claim ID';
  $handler->display->display_options['fields']['activity_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['activity_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['activity_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['activity_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['activity_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['activity_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['activity_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['activity_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['activity_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['activity_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['activity_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['activity_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['activity_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['activity_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['activity_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['activity_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['activity_id']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['activity_id']['format_plural'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_claim_reference_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Resource';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Activity: Date */
  $handler->display->display_options['fields']['field_activity_date']['id'] = 'field_activity_date';
  $handler->display->display_options['fields']['field_activity_date']['table'] = 'field_data_field_activity_date';
  $handler->display->display_options['fields']['field_activity_date']['field'] = 'field_activity_date';
  $handler->display->display_options['fields']['field_activity_date']['label'] = 'Claim Date';
  $handler->display->display_options['fields']['field_activity_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_activity_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_activity_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_activity_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_activity_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_activity_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_activity_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_activity_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_activity_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_activity_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_activity_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_activity_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_activity_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_activity_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_activity_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_activity_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_activity_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_activity_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_activity_date']['field_api_classes'] = 0;
  /* Field: Activity: Claim reason */
  $handler->display->display_options['fields']['field_claim_reason']['id'] = 'field_claim_reason';
  $handler->display->display_options['fields']['field_claim_reason']['table'] = 'field_data_field_claim_reason';
  $handler->display->display_options['fields']['field_claim_reason']['field'] = 'field_claim_reason';
  $handler->display->display_options['fields']['field_claim_reason']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_claim_reason']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_claim_reason']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_claim_reason']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_claim_reason']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_claim_reason']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_claim_reason']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_claim_reason']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_claim_reason']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_claim_reason']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_claim_reason']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_claim_reason']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_claim_reason']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_claim_reason']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_claim_reason']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_claim_reason']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_claim_reason']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_claim_reason']['field_api_classes'] = 0;
  /* Field: Contact: Organization name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['fields']['contact_name']['label'] = 'Claimant';
  $handler->display->display_options['fields']['contact_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['contact_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['contact_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['contact_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['contact_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['contact_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['contact_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['contact_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['contact_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['contact_name']['type'] = 'name_default_short_full';
  $handler->display->display_options['fields']['contact_name']['field_api_classes'] = 0;
  /* Field: Approve Link */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Approve Link';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Approve';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'admin/structure/crm/node_claim/approve/[activity_id]';
  $handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_1']['hide_alter_empty'] = 0;
  /* Field: Reject Link */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Reject Link';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'Reject';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'admin/structure/crm/node_claim/reject/[activity_id]';
  $handler->display->display_options['fields']['nothing_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_2']['hide_alter_empty'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Action';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[nothing_1] | [nothing_2]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Filter criterion: CRM Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'node_claim' => 'node_claim',
  );
  /* Filter criterion: Activity: Status (field_claim_status) */
  $handler->display->display_options['filters']['field_claim_status_value']['id'] = 'field_claim_status_value';
  $handler->display->display_options['filters']['field_claim_status_value']['table'] = 'field_data_field_claim_status';
  $handler->display->display_options['filters']['field_claim_status_value']['field'] = 'field_claim_status_value';
  $handler->display->display_options['filters']['field_claim_status_value']['value'] = array(
    'pending' => 'pending',
  );

  /* Display: Resource Claim Queue */
  $handler = $view->new_display('page', 'Resource Claim Queue', 'page');
  $handler->display->display_options['path'] = 'admin/sfcenter/node_claim';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Resource Claim Queue';
  $handler->display->display_options['menu']['description'] = 'Claim queue for the resource claim';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $export['resource_claim_queue'] = $view;

  return $export;
}
