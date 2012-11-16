<?php
/**
 * @file
 * crm_core_petition.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crm_core_petition_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'petition_content';
  $context->description = 'Define context on petition content view';
  $context->tag = 'Petition';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'online_petition' => 'online_petition',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-petition_report-petition_count' => array(
          'module' => 'views',
          'delta' => 'petition_report-petition_count',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Define context on petition content view');
  t('Petition');
  $export['petition_content'] = $context;

  return $export;
}
