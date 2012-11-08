<?php
/**
 * @file
 * crm_core_donation.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function crm_core_donation_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:donation_pages/1
  $menu_links['main-menu:donation_pages/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'donation_pages/1',
    'router_path' => 'donation_pages/%',
    'link_title' => 'Donate',
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
  t('Donate');


  return $menu_links;
}
