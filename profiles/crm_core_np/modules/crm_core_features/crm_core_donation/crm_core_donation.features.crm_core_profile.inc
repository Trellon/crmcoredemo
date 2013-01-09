<?php
/**
 * @file
 * crm_core_donation.features.crm_core_profile.inc
 */

/**
 * Implements hook_crm_core_profile_default().
 */
function crm_core_donation_crm_core_profile_default() {
$crm_core_profile = array();
  $crm_core_profile['profile']['donation'] = array(
  'name' => 'donation',
  'label' => 'Donation',
  'bundle_type' => 'individual',
  'fields' => array(
    'toggle' => array(
      'contact_name' => 'contact_name',
      'field_billing_address' => 'field_billing_address',
      'field_contact_email' => 'field_contact_email',
      'contact_image' => 0,
      'field_contact_phone' => 0,
      'field_contact_volunteer' => 0,
    ),
    'weight' => array(),
  ),
  'block' => '1',
  'path' => '',
  'redirect' => 'thankyou-donation',
  'message' => '',
  'status' => '1',
  'uid' => '1',
  'created' => '1352343485',
  'create_contact_actions' => array(
    'existing' => array(
      'weight' => '-10',
    ),
    'new' => array(
      'weight' => '-8',
    ),
    'url' => array(
      'weight' => '-9',
    ),
  ),
  'user_sync' => 'current',
);
  $crm_core_profile['activity']['donation'] = array(
  'name' => 'donation',
  'bundle_type' => 'donation',
  'fields' => array(
    'toggle' => array(
      'field_donation_amounts' => 'field_donation_amounts',
      'field_donation_dedication_email' => 'field_donation_dedication_email',
      'field_donation_dedication_name' => 'field_donation_dedication_name',
      'field_donation_dedication_type' => 'field_donation_dedication_type',
      'field_activity_participants' => 0,
      'field_activity_date' => 0,
      'field_activity_notes' => 0,
      'field_donation_campaign' => 0,
      'field_donation_cc_last4' => 0,
      'field_donation_order' => 0,
      'field_donation_payment_type' => 0,
      'field_donation_receive_date' => 0,
      'field_donation_source' => 0,
      'field_donation_status' => 0,
    ),
  ),
  'status' => '1',
  'created' => '1352343485',
  'create_activity_actions' => array(
    'new' => array(
      'weight' => '0',
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
