<?php
/**
 * @file
 * crm_core_volunteer.features.crm_core_profile.inc
 */

/**
 * Implements hook_crm_core_profile_default().
 */
function crm_core_volunteer_crm_core_profile_default() {
$crm_core_profile = array();
  $crm_core_profile['profile']['volunteer_application'] = array(
  'name' => 'volunteer_application',
  'label' => 'Volunteer Application',
  'bundle_type' => 'individual',
  'fields' => array(
    'toggle' => array(
      'contact_name' => 'contact_name',
      'field_contact_email' => 'field_contact_email',
      'field_contact_volunteer' => 'field_contact_volunteer',
      'field_contact_phone' => 'field_contact_phone',
      'contact_image' => 0,
      'field_billing_address' => 0,
    ),
    'weight' => array(
      'contact_name' => array(
        'weight' => array(
          'weight' => -10,
        ),
      ),
      'field_contact_email' => array(
        'weight' => array(
          'weight' => -9,
        ),
      ),
      'field_contact_phone' => array(
        'weight' => array(
          'weight' => -8,
        ),
      ),
      'field_contact_volunteer' => array(
        'weight' => array(
          'weight' => -8,
        ),
      ),
    ),
  ),
  'block' => '0',
  'path' => NULL,
  'redirect' => NULL,
  'message' => 'Thank you for applying to be a volunteer, we will get in touch with you shortly',
  'status' => '1',
  'uid' => '1',
  'created' => '1354041846',
  'create_contact_actions' => array(
    'new' => array(
      'weight' => -9,
    ),
    'existing' => array(
      'weight' => -10,
    ),
    'url' => array(
      'weight' => -8,
    ),
  ),
  'user_sync' => 'current',
);
  $crm_core_profile['profile']['volunteer_commitment'] = array(
  'name' => 'volunteer_commitment',
  'label' => 'Volunteer Commitment',
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
    'weight' => array(
      'contact_name' => array(
        'weight' => array(
          'weight' => -10,
        ),
      ),
      'field_contact_email' => array(
        'weight' => array(
          'weight' => -9,
        ),
      ),
    ),
  ),
  'block' => '0',
  'path' => '',
  'redirect' => '',
  'message' => '',
  'status' => '1',
  'uid' => '1',
  'created' => '1354040877',
  'create_contact_actions' => array(
    'existing' => array(
      'weight' => '-10',
    ),
    'new' => array(
      'weight' => '-9',
    ),
    'url' => array(
      'weight' => '-8',
    ),
  ),
  'user_sync' => 'current',
);
  $crm_core_profile['activity']['volunteer_commitment'] = array(
  'name' => 'volunteer_commitment',
  'bundle_type' => 'volunteer_commitment',
  'fields' => array(
    'toggle' => array(
      'field_activity_notes' => 'field_activity_notes',
      'field_volunteer_time' => 'field_volunteer_time',
      'field_activity_participants' => 0,
      'field_activity_date' => 0,
      'field_volunteer_opportunity' => 0,
      'field_volunteer_status' => 0,
    ),
  ),
  'status' => '1',
  'created' => '1354040877',
  'create_activity_actions' => array(
    'recent' => array(
      'weight' => '-9',
    ),
    'new' => array(
      'weight' => '-10',
    ),
    'url' => array(
      'weight' => '-8',
    ),
  ),
);
return $crm_core_profile;
}
