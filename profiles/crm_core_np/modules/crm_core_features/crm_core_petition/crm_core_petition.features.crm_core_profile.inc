<?php
/**
 * @file
 * crm_core_petition.features.crm_core_profile.inc
 */

/**
 * Implements hook_crm_core_profile_default().
 */
function crm_core_petition_crm_core_profile_default() {
$crm_core_profile = array();
  $crm_core_profile['profile']['petition_signing_form'] = array(
  'name' => 'petition_signing_form',
  'label' => 'Petition signing form',
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
    'weight' => array(),
  ),
  'block' => '0',
  'path' => '',
  'redirect' => '',
  'message' => 'Thank you for signing the petition!',
  'status' => '1',
  'uid' => '1',
  'created' => '1351788224',
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
  'user_sync' => '',
);
  $crm_core_profile['activity']['petition_signing_form'] = array(
  'name' => 'petition_signing_form',
  'bundle_type' => 'petition_signature',
  'fields' => array(
    'toggle' => array(
      'field_crm_petition_display' => 'field_crm_petition_display',
      'field_activity_participants' => 0,
      'field_activity_date' => 0,
      'field_activity_notes' => 0,
      'field_crm_petition_reference' => 0,
    ),
  ),
  'status' => '1',
  'created' => '1351788224',
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
