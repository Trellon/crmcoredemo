<?php
/**
 * @file
 * crm_core_volunteer.features.inc
 */

/**
 * Implements hook_default_crm_core_activity_type().
 */
function crm_core_volunteer_default_crm_core_activity_type() {
  $items = array();
  $items['volunteer_commitment'] = entity_import('crm_core_activity_type', '{
    "type" : "volunteer_commitment",
    "label" : "Volunteer Commitment",
    "weight" : 0,
    "description" : "This activity will record user volunteer application to a volunteer opportunity",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function crm_core_volunteer_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function crm_core_volunteer_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function crm_core_volunteer_node_info() {
  $items = array(
    'volunteer_opportunity' => array(
      'name' => t('Volunteer opportunity'),
      'base' => 'node_content',
      'description' => t('Allow users to find and sign up for different volunteer opportunities.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
