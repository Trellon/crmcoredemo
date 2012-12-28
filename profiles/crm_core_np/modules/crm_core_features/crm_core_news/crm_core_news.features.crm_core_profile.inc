<?php
/**
 * @file
 * crm_core_news.features.crm_core_profile.inc
 */

/**
 * Implements hook_crm_core_profile_default().
 */
function crm_core_news_crm_core_profile_default() {
$crm_core_profile = array();
  $crm_core_profile['profile']['news_subscription'] = array(
  'name' => 'news_subscription',
  'label' => 'News subscription',
  'bundle_type' => 'individual',
  'fields' => array(
    'toggle' => array(
      'contact_name' => 'contact_name',
      'field_contact_email' => 'field_contact_email',
      'contact_image' => 0,
      'field_billing_address' => 0,
      'field_contact_phone' => 0,
      'field_contact_volunteer' => 0,
    ),
  ),
  'block' => '0',
  'path' => '',
  'redirect' => 'news',
  'message' => 'You have been subscribed!',
  'status' => '1',
  'uid' => '1',
  'created' => '1356634624',
  'create_contact_actions' => array(
    'new' => array(
      'weight' => '-9',
    ),
    'existing' => array(
      'weight' => '-10',
    ),
    'url' => array(
      'weight' => '-8',
    ),
  ),
  'user_sync' => 'current',
);
  $crm_core_profile['activity']['news_subscription'] = array(
  'name' => 'news_subscription',
  'bundle_type' => 'news_subscription',
  'fields' => array(
    'toggle' => array(
      'field_activity_participants' => 0,
      'field_activity_date' => 0,
      'field_activity_notes' => 0,
      'field_newsletter_action' => 0,
    ),
  ),
  'status' => '1',
  'created' => '1356634624',
  'create_activity_actions' => array(
    'new' => array(
      'weight' => '10',
    ),
    'recent' => array(
      'weight' => '10',
    ),
    'url' => array(
      'weight' => '10',
    ),
  ),
);
return $crm_core_profile;
}
