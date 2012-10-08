<?php
/**
 * @file
 * crm_core_donation.features.inc
 */

/**
 * Implements hook_default_crm_core_activity_type().
 */
function crm_core_donation_default_crm_core_activity_type() {
  $items = array();
  $items['donation'] = entity_import('crm_core_activity_type', '{
    "type" : "donation",
    "label" : "Donation",
    "weight" : 0,
    "description" : "A monetary donation"
  }');
  return $items;
}

/**
 * Implements hook_views_api().
 */
function crm_core_donation_views_api() {
  return array("version" => "3.0");
}
