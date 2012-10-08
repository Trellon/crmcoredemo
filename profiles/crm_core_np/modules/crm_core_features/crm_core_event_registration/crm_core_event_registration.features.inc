<?php
/**
 * @file
 * crm_core_event_registration.features.inc
 */

/**
 * Implements hook_default_crm_core_activity_type().
 */
function crm_core_event_registration_default_crm_core_activity_type() {
  $items = array();
  $items['event_registration'] = entity_import('crm_core_activity_type', '{
    "type" : "event_registration",
    "label" : "Event Registration",
    "weight" : 0,
    "description" : ""
  }');
  return $items;
}
