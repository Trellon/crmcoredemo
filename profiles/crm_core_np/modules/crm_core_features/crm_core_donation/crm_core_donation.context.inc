<?php
/**
 * @file
 * crm_core_donation.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crm_core_donation_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_core_donation_reports';
  $context->description = 'Displays summary information along with reports in the system.';
  $context->tag = 'crm-core-report';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'crm/reports/donations-overview' => 'crm/reports/donations-overview',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-donations_totals-block_1' => array(
          'module' => 'views',
          'delta' => 'donations_totals-block_1',
          'region' => 'above',
          'weight' => '-10',
        ),
        'crm_core_donation-crm_core_donation_reports_chart' => array(
          'module' => 'crm_core_donation',
          'delta' => 'crm_core_donation_reports_chart',
          'region' => 'above',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Displays summary information along with reports in the system.');
  t('crm-core-report');
  $export['crm_core_donation_reports'] = $context;

  return $export;
}
