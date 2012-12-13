<?php
/**
 * @file
 * crm_core_volunteer.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function crm_core_volunteer_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:crm_core_profile/volunteer_application
  $menu_links['main-menu:crm_core_profile/volunteer_application'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'crm_core_profile/volunteer_application',
    'router_path' => 'crm_core_profile/%',
    'link_title' => 'Volunteer',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Volunteer');


  return $menu_links;
}
