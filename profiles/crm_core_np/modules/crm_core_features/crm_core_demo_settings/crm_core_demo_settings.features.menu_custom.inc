<?php
/**
 * @file
 * crm_core_demo_settings.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function crm_core_demo_settings_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-crm-core-content.
  $menus['menu-crm-core-content'] = array(
    'menu_name' => 'menu-crm-core-content',
    'title' => 'CRM Core Content',
    'description' => 'Links for creating new CRM Core content',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('CRM Core Content');
  t('Links for creating new CRM Core content');


  return $menus;
}
