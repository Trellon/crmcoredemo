<?php
/**
 * @file
 * crm_core_demo_settings.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function crm_core_demo_settings_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-crm-core-content:crm/donations/new
  $menu_links['menu-crm-core-content:crm/donations/new'] = array(
    'menu_name' => 'menu-crm-core-content',
    'link_path' => 'crm/donations/new',
    'router_path' => 'crm/donations/new',
    'link_title' => 'Add New Donation Page',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'crm-core-content',
          1 => 'crm-core-donation-page',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-crm-core-content:node/add/blog-post
  $menu_links['menu-crm-core-content:node/add/blog-post'] = array(
    'menu_name' => 'menu-crm-core-content',
    'link_path' => 'node/add/blog-post',
    'router_path' => 'node/add/blog-post',
    'link_title' => 'Add New Blog Post',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'crm-core-content',
          1 => 'crm-core-blog-post',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-crm-core-content:node/add/event
  $menu_links['menu-crm-core-content:node/add/event'] = array(
    'menu_name' => 'menu-crm-core-content',
    'link_path' => 'node/add/event',
    'router_path' => 'node/add/event',
    'link_title' => 'Add New Event',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'crm-core-content',
          1 => 'crm-core-event',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-crm-core-content:node/add/online-petition
  $menu_links['menu-crm-core-content:node/add/online-petition'] = array(
    'menu_name' => 'menu-crm-core-content',
    'link_path' => 'node/add/online-petition',
    'router_path' => 'node/add/online-petition',
    'link_title' => 'Add New Online Petition',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'crm-core-content',
          1 => 'crm-core-petition',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-crm-core-content:node/add/volunteer-opportunity
  $menu_links['menu-crm-core-content:node/add/volunteer-opportunity'] = array(
    'menu_name' => 'menu-crm-core-content',
    'link_path' => 'node/add/volunteer-opportunity',
    'router_path' => 'node/add/volunteer-opportunity',
    'link_title' => 'Add New Volunteer Opportunity',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'crm-core-content',
          1 => 'crm-core-volunteer',
        ),
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
  t('Add New Blog Post');
  t('Add New Donation Page');
  t('Add New Event');
  t('Add New Online Petition');
  t('Add New Volunteer Opportunity');


  return $menu_links;
}
