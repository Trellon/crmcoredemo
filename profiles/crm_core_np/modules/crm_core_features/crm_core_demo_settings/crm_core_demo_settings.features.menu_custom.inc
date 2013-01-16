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

  // Exported menu: menu-crm-core-administrative-fea.
  $menus['menu-crm-core-administrative-fea'] = array(
    'menu_name' => 'menu-crm-core-administrative-fea',
    'title' => 'CRM Core Administrative Features',
    'description' => 'This is a simple list of administrative features used in CRM Core',
  );
  // Exported menu: menu-crm-core-basic-nav.
  $menus['menu-crm-core-basic-nav'] = array(
    'menu_name' => 'menu-crm-core-basic-nav',
    'title' => 'CRM Core Basic Nav',
    'description' => 'This is just a basic navigation menu, containing links to important CRM Core pages. Adjust it to include links to specific tools in the system. ',
  );
  // Exported menu: menu-crm-core-content.
  $menus['menu-crm-core-content'] = array(
    'menu_name' => 'menu-crm-core-content',
    'title' => 'CRM Core Content',
    'description' => 'Links for creating new CRM Core content',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('CRM Core Administrative Features');
  t('CRM Core Basic Nav');
  t('CRM Core Content');
  t('Links for creating new CRM Core content');
  t('This is a simple list of administrative features used in CRM Core');
  t('This is just a basic navigation menu, containing links to important CRM Core pages. Adjust it to include links to specific tools in the system. ');


  return $menus;
}
