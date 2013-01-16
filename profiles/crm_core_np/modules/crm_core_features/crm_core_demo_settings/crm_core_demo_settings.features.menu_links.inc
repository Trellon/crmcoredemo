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

  // Exported menu link: menu-crm-core-administrative-fea:admin/structure/crm/activity-types
  $menu_links['menu-crm-core-administrative-fea:admin/structure/crm/activity-types'] = array(
    'menu_name' => 'menu-crm-core-administrative-fea',
    'link_path' => 'admin/structure/crm/activity-types',
    'router_path' => 'admin/structure/crm/activity-types',
    'link_title' => 'Activity Types',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-crm-core-administrative-fea:admin/structure/crm/contact-types
  $menu_links['menu-crm-core-administrative-fea:admin/structure/crm/contact-types'] = array(
    'menu_name' => 'menu-crm-core-administrative-fea',
    'link_path' => 'admin/structure/crm/contact-types',
    'router_path' => 'admin/structure/crm/contact-types',
    'link_title' => 'Contact Types',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-crm-core-administrative-fea:admin/structure/crm/profile
  $menu_links['menu-crm-core-administrative-fea:admin/structure/crm/profile'] = array(
    'menu_name' => 'menu-crm-core-administrative-fea',
    'link_path' => 'admin/structure/crm/profile',
    'router_path' => 'admin/structure/crm/profile',
    'link_title' => 'CRM Core Profiles',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-crm-core-administrative-fea:admin/structure/crm/relationship-types
  $menu_links['menu-crm-core-administrative-fea:admin/structure/crm/relationship-types'] = array(
    'menu_name' => 'menu-crm-core-administrative-fea',
    'link_path' => 'admin/structure/crm/relationship-types',
    'router_path' => 'admin/structure/crm/relationship-types',
    'link_title' => 'Relationships',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-crm-core-administrative-fea:admin/structure/crm/user_sync
  $menu_links['menu-crm-core-administrative-fea:admin/structure/crm/user_sync'] = array(
    'menu_name' => 'menu-crm-core-administrative-fea',
    'link_path' => 'admin/structure/crm/user_sync',
    'router_path' => 'admin/structure/crm/user_sync',
    'link_title' => 'User Synchronization',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-crm-core-administrative-fea:admin/structure/features
  $menu_links['menu-crm-core-administrative-fea:admin/structure/features'] = array(
    'menu_name' => 'menu-crm-core-administrative-fea',
    'link_path' => 'admin/structure/features',
    'router_path' => 'admin/structure/features',
    'link_title' => 'Features',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-crm-core-basic-nav:crm
  $menu_links['menu-crm-core-basic-nav:crm'] = array(
    'menu_name' => 'menu-crm-core-basic-nav',
    'link_path' => 'crm',
    'router_path' => 'crm',
    'link_title' => 'Dashboard',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-crm-core-basic-nav:crm/contact
  $menu_links['menu-crm-core-basic-nav:crm/contact'] = array(
    'menu_name' => 'menu-crm-core-basic-nav',
    'link_path' => 'crm/contact',
    'router_path' => 'crm/contact',
    'link_title' => 'Contacts',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-crm-core-basic-nav:crm/reports
  $menu_links['menu-crm-core-basic-nav:crm/reports'] = array(
    'menu_name' => 'menu-crm-core-basic-nav',
    'link_path' => 'crm/reports',
    'router_path' => 'crm',
    'link_title' => 'Reports',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
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
  t('Activity Types');
  t('Add New Blog Post');
  t('Add New Donation Page');
  t('Add New Event');
  t('Add New Online Petition');
  t('Add New Volunteer Opportunity');
  t('CRM Core Profiles');
  t('Contact Types');
  t('Contacts');
  t('Dashboard');
  t('Features');
  t('Relationships');
  t('Reports');
  t('User Synchronization');


  return $menu_links;
}
