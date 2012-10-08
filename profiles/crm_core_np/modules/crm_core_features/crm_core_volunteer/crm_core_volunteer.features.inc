<?php
/**
 * @file
 * crm_core_volunteer.features.inc
 */

/**
 * Implements hook_default_crm_core_activity_type().
 */
function crm_core_volunteer_default_crm_core_activity_type() {
  $items = array();
  $items['volunteer_commitment'] = entity_import('crm_core_activity_type', '{
    "type" : "volunteer_commitment",
    "label" : "Volunteer Commitment",
    "weight" : 0,
    "description" : "This activity will record user volunteer application to a volunteer opportunity"
  }');
  return $items;
}
