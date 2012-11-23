<?php
/**
 * @file
 * crm_core_petition.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function crm_core_petition_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:admin/crm/petitions/all
  $menu_links['main-menu:admin/crm/petitions/all'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/crm/petitions/all',
    'router_path' => 'admin/crm/petitions/all',
    'link_title' => 'Petitions',
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
  t('Petitions');


  return $menu_links;
}
