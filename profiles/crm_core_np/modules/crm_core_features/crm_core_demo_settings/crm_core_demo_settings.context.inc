<?php
/**
 * @file
 * crm_core_demo_settings.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crm_core_demo_settings_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front_page';
  $context->description = 'Controls the layout of the front page for CRM Core Demo';
  $context->tag = 'demo';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Controls the layout of the front page for CRM Core Demo');
  t('demo');
  $export['front_page'] = $context;

  return $export;
}
