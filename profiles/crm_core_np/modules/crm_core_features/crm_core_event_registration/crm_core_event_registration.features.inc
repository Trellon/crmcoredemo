<?php
/**
 * @file
 * crm_core_event_registration.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function crm_core_event_registration_commerce_product_default_types() {
  $items = array(
    'event_registration' => array(
      'type' => 'event_registration',
      'name' => 'Event Registration',
      'description' => '',
      'help' => '',
      'revision' => '1',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_crm_core_activity_type().
 */
function crm_core_event_registration_default_crm_core_activity_type() {
  $items = array();
  $items['event_registration'] = entity_import('crm_core_activity_type', '{
    "type" : "event_registration",
    "label" : "Event Registration",
    "weight" : 0,
    "description" : ""
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function crm_core_event_registration_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function crm_core_event_registration_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function crm_core_event_registration_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('An content that represents an event with its associated information'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
