<?php
/**
 * @file
 * crm_core_demo_settings.features.inc
 */

/**
 * Implements hook_default_crm_core_contact_type().
 */
function crm_core_demo_settings_default_crm_core_contact_type() {
  $items = array();
  $items['individual'] = entity_import('crm_core_contact_type', '{
    "type" : "individual",
    "label" : null,
    "weight" : 0,
    "name" : "Individual",
    "description" : "A single individual.",
    "custom" : "0",
    "disabled" : "0",
    "locked" : "1"
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function crm_core_demo_settings_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
