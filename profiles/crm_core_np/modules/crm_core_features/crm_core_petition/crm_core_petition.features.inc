<?php
/**
 * @file
 * crm_core_petition.features.inc
 */

/**
 * Implements hook_default_crm_core_activity_type().
 */
function crm_core_petition_default_crm_core_activity_type() {
  $items = array();
  $items['petition_signature'] = entity_import('crm_core_activity_type', '{
    "type" : "petition_signature",
    "label" : "Petition Signature",
    "weight" : 0,
    "description" : "An act of signing an online petition"
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function crm_core_petition_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function crm_core_petition_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function crm_core_petition_node_info() {
  $items = array(
    'online_petition' => array(
      'name' => t('Online petition'),
      'base' => 'node_content',
      'description' => t('Allow people to sign up for causes they care about.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
