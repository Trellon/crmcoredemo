<?php
/**
 * @file
 * crm_core_node_claim.features.inc
 */

/**
 * Implements hook_default_crm_core_activity_type().
 */
function crm_core_node_claim_default_crm_core_activity_type() {
  $items = array();
  $items['node_claim'] = entity_import('crm_core_activity_type', '{
    "type" : "node_claim",
    "label" : "Node Claim",
    "weight" : 0,
    "description" : "An process flow for claiming node ownership with CRM Core"
  }');
  return $items;
}

/**
 * Implements hook_views_api().
 */
function crm_core_node_claim_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
