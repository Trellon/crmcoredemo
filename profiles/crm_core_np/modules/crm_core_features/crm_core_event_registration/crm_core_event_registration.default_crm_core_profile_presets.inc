<?php
/**
 * @file
 * crm_core_event_registration.default_crm_core_profile_presets.inc
 */

/**
 * Implements hook_default_crm_core_profile_presets().
 */
function crm_core_event_registration_default_crm_core_profile_presets() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'event_registration';
  $preset->label = 'Event Registration';
  $preset->bundle_type = 'individual';
  $preset->fields = array(
    'toggle' => array(
      'contact_name' => 'contact_name',
      'contact_image' => 0,
    ),
  );
  $preset->block = FALSE;
  $preset->path = '';
  $preset->redirect = '';
  $preset->message = '';
  $preset->status = TRUE;
  $preset->uid = 1;
  $preset->created = 1350567778;
  $preset->create_contact_actions = 'a:3:{s:3:"new";a:1:{s:6:"weight";s:2:"10";}s:9:"duplicate";a:1:{s:6:"weight";s:2:"10";}s:3:"url";a:1:{s:6:"weight";s:2:"10";}}';
  $preset->user_sync = '';
  $preset->activity_bundle_type = 'event_registration';
  $preset->activity_fields = array(
    'toggle' => array(
      'field_activity_notes' => 'field_activity_notes',
      'field_activity_participants' => 0,
      'field_activity_date' => 0,
    ),
  );
  $preset->activity_status = TRUE;
  $preset->activity_created = 1350567779;
  $export['event_registration'] = $preset;

  return $export;
}
