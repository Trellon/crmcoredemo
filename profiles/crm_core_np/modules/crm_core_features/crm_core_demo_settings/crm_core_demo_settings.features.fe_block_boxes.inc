<?php
/**
 * @file
 * crm_core_demo_settings.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function crm_core_demo_settings_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'CRM Core Demo Jumbotron';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'promo_jumbotron';
  $fe_block_boxes->body = '<h1>CRM Core Demo</h1>
A Drupal-based approach to contact relationship management.
Demonstrates techniques for building and tracking relationships
the ways that suit your organization.';

  $export['promo_jumbotron'] = $fe_block_boxes;

  return $export;
}
