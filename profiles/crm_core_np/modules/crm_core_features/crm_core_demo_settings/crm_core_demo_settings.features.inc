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
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
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
function crm_core_demo_settings_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_homebox().
 */
function crm_core_demo_settings_homebox() {
  $homeboxes = array();

  $homeboxes['crm_core_dashboard'] = array (
    'regions' => 2,
    'cache' => 1,
    'color' => 0,
    'colors' => 
    array (
      0 => '#E4F0F8',
      1 => '#E4F0F8',
      2 => '#E4F0F8',
      3 => '#E4F0F8',
      4 => '#E4F0F8',
      5 => '#E4F0F8',
    ),
    'blocks' => 
    array (
      'menu_menu-crm-core-content' => 
      array (
        'module' => 'menu',
        'delta' => 'menu-crm-core-content',
        'region' => 2,
        'movable' => 0,
        'status' => 1,
        'open' => 1,
        'closable' => 0,
        'title' => '',
        'weight' => -22,
      ),
      'views_d2b9063a2b28cbc611462754cfae32a3' => 
      array (
        'module' => 'views',
        'delta' => 'd2b9063a2b28cbc611462754cfae32a3',
        'region' => 1,
        'movable' => 0,
        'status' => 1,
        'open' => 1,
        'closable' => 0,
        'title' => '',
        'weight' => -22,
      ),
      'views_cff147d847be508f315012f24c5edc53' => 
      array (
        'module' => 'views',
        'delta' => 'cff147d847be508f315012f24c5edc53',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -25,
      ),
    ),
    'widths' => 
    array (
    ),
    'title' => 'Dashboard',
    'path' => 'crm/dashboard/hb',
    'menu' => 1,
    'enabled' => 1,
    'auto_save' => 1,
    'full' => 1,
    'roles' => 
    array (
      0 => 'authenticated user',
    ),
  );


  return $homeboxes;
}
