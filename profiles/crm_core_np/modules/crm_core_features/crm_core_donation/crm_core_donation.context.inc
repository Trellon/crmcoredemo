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
  $context->description = 'Presents additional information for overview pages.';
  $context->tag = 'crm-core-report';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'crm/reports/donations' => 'crm/reports/donations',
        'crm/reports/donations/overview' => 'crm/reports/donations/overview',
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
  t('Presents additional information for overview pages.');
  t('crm-core-report');
  $export['crm_core_donation_reports'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_core_donor_reports_overview';
  $context->description = 'Place chart block at report page';
  $context->tag = 'crm-core-report';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'crm/reports/donors' => 'crm/reports/donors',
        'crm/reports/donors/overview' => 'crm/reports/donors/overview',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-crm_core_donor_widget-donors' => array(
          'module' => 'views',
          'delta' => 'crm_core_donor_widget-donors',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-crm_core_donor_widget-frequency' => array(
          'module' => 'views',
          'delta' => 'crm_core_donor_widget-frequency',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-crm_core_donor_widget-average' => array(
          'module' => 'views',
          'delta' => 'crm_core_donor_widget-average',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place chart block at report page');
  t('crm-core-report');
  $export['crm_core_donor_reports_overview'] = $context;

  return $export;
}
