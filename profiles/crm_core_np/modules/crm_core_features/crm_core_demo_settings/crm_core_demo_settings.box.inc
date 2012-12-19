<?php
/**
 * @file
 * crm_core_demo_settings.box.inc
 */

/**
 * Implements hook_default_box().
 */
function crm_core_demo_settings_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'promo_demo';
  $box->plugin_key = 'simple';
  $box->title = 'Features you will find in this demo';
  $box->description = 'Promo - Features you will find in this demo';
  $box->options = array(
    'body' => array(
      'value' => 'Text coming soon...',
      'format' => 'filtered_html',
    ),
  );
  $export['promo_demo'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'promo_features';
  $box->plugin_key = 'simple';
  $box->title = 'Just the features you want';
  $box->description = 'Promo - Just the features';
  $box->options = array(
    'body' => array(
      'value' => 'At it’s heart, CRM Core only provides the tools for tracking contacts, relationships and activities. Every other feature is an add-on, meaning you get the functionality you need without the extras you don’t.',
      'format' => 'filtered_html',
    ),
  );
  $export['promo_features'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'promo_people';
  $box->plugin_key = 'simple';
  $box->title = 'Track people, not users';
  $box->description = 'Promo - Track people';
  $box->options = array(
    'body' => array(
      'value' => 'CRM Core provides tools for tracking contacts within your Drupal site. Over time, people build up profiles containing a record of all their interaction with your sites. A contact can be a user, but does not have to be.',
      'format' => 'filtered_html',
    ),
  );
  $export['promo_people'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'promo_portable';
  $box->plugin_key = 'simple';
  $box->title = 'Modular and portable';
  $box->description = 'Promo - Modular and Portable';
  $box->options = array(
    'body' => array(
      'value' => 'Building a new feature in CRM Core means you are creating functionality that can be ported to any other website. New features for CRM Core are being built all the time, and a community is growing around the product to bring more complex functionality to the system.~',
      'format' => 'filtered_html',
    ),
  );
  $export['promo_portable'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'promo_pro_tips';
  $box->plugin_key = 'simple';
  $box->title = 'Pro tips for getting started';
  $box->description = 'Promo - Pro Tips';
  $box->options = array(
    'body' => array(
      'value' => 'Content coming soon...',
      'format' => 'filtered_html',
    ),
  );
  $export['promo_pro_tips'] = $box;

  return $export;
}
