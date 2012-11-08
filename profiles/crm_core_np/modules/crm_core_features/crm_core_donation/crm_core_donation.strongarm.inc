<?php
/**
 * @file
 * crm_core_donation.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function crm_core_donation_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crm_core_donation_billing_address';
  $strongarm->value = 'field_billing_address';
  $export['crm_core_donation_billing_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crm_core_donation_imo_message';
  $strongarm->value = '';
  $export['crm_core_donation_imo_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crm_core_donation_pdp';
  $strongarm->value = 1;
  $export['crm_core_donation_pdp'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crm_core_donation_profile';
  $strongarm->value = 'donation';
  $export['crm_core_donation_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crm_core_donation_redirect_message';
  $strongarm->value = 'Thank you for your donation';
  $export['crm_core_donation_redirect_message'] = $strongarm;

  return $export;
}
