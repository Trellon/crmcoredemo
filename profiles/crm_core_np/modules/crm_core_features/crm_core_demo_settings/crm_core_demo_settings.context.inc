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
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'marquee',
          'weight' => '-10',
        ),
        'boxes-promo_people' => array(
          'module' => 'boxes',
          'delta' => 'promo_people',
          'region' => 'below',
          'weight' => '-10',
        ),
        'boxes-promo_features' => array(
          'module' => 'boxes',
          'delta' => 'promo_features',
          'region' => 'below',
          'weight' => '-9',
        ),
        'boxes-promo_portable' => array(
          'module' => 'boxes',
          'delta' => 'promo_portable',
          'region' => 'below',
          'weight' => '-8',
        ),
        'boxes-promo_demo' => array(
          'module' => 'boxes',
          'delta' => 'promo_demo',
          'region' => 'bottom',
          'weight' => '-10',
        ),
        'boxes-promo_pro_tips' => array(
          'module' => 'boxes',
          'delta' => 'promo_pro_tips',
          'region' => 'bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Controls the layout of the front page for CRM Core Demo');
  t('demo');
  $export['front_page'] = $context;

  return $export;
}
