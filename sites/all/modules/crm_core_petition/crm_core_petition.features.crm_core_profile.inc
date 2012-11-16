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
  'fields' => 'a:2:{s:6:"toggle";a:7:{s:12:"contact_name";s:12:"contact_name";s:19:"field_contact_email";s:19:"field_contact_email";s:21:"field_contact_address";s:21:"field_contact_address";s:13:"contact_image";i:0;s:21:"field_billing_address";i:0;s:23:"field_contact_volunteer";i:0;s:19:"field_contact_phone";i:0;}s:6:"weight";a:0:{}}',
  'block' => '0',
  'path' => '',
  'redirect' => '',
  'message' => 'Thank you for signing the petition!',
  'status' => '1',
  'uid' => '1',
  'created' => '1351788224',
  'create_contact_actions' => 'a:3:{s:3:"new";a:1:{s:6:"weight";s:2:"10";}s:8:"existing";a:1:{s:6:"weight";s:2:"10";}s:3:"url";a:1:{s:6:"weight";s:2:"10";}}',
  'user_sync' => '',
);
  $crm_core_profile['activity']['petition_signing_form'] = array(
  'name' => 'petition_signing_form',
  'bundle_type' => 'petition_signature',
  'fields' => 'a:2:{s:6:"toggle";a:5:{s:26:"field_crm_petition_display";s:26:"field_crm_petition_display";s:27:"field_activity_participants";i:0;s:19:"field_activity_date";i:0;s:20:"field_activity_notes";i:0;s:28:"field_crm_petition_reference";i:0;}s:6:"weight";a:0:{}}',
  'status' => '1',
  'created' => '1351788224',
  'create_activity_actions' => 'a:3:{s:3:"new";a:1:{s:6:"weight";s:2:"10";}s:6:"recent";a:1:{s:6:"weight";s:2:"10";}s:3:"url";a:1:{s:6:"weight";s:2:"10";}}',
);
return $crm_core_profile;
}
