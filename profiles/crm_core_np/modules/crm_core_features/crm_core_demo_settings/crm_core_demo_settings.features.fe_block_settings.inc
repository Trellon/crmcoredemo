<?php
/**
 * @file
 * crm_core_demo_settings.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function crm_core_demo_settings_default_fe_block_settings() {
  $export = array();

  $export['version'] = '1.0';

  // Theme independent visibility settings.
  $export['visibility'] = array(
    'block-promo_jumbotron' => array(
      'machine_name' => 'promo_jumbotron',
      'module' => 'block',
    ),
    'boxes-promo_demo' => array(
      'delta' => 'promo_demo',
      'module' => 'boxes',
    ),
    'boxes-promo_features' => array(
      'delta' => 'promo_features',
      'module' => 'boxes',
    ),
    'boxes-promo_people' => array(
      'delta' => 'promo_people',
      'module' => 'boxes',
    ),
    'boxes-promo_portable' => array(
      'delta' => 'promo_portable',
      'module' => 'boxes',
    ),
    'boxes-promo_pro_tips' => array(
      'delta' => 'promo_pro_tips',
      'module' => 'boxes',
    ),
  );

  // bartik
  $theme = array();

  $theme['block-promo_jumbotron'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Promo - Jumbotron',
    'cache' => -1,
    'machine_name' => 'promo_jumbotron',
  );

  $theme['boxes-promo_demo'] = array(
    'module' => 'boxes',
    'delta' => 'promo_demo',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -2,
  );

  $theme['boxes-promo_features'] = array(
    'module' => 'boxes',
    'delta' => 'promo_features',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -2,
  );

  $theme['boxes-promo_people'] = array(
    'module' => 'boxes',
    'delta' => 'promo_people',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -2,
  );

  $theme['boxes-promo_portable'] = array(
    'module' => 'boxes',
    'delta' => 'promo_portable',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -2,
  );

  $theme['boxes-promo_pro_tips'] = array(
    'module' => 'boxes',
    'delta' => 'promo_pro_tips',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -2,
  );

  $export['theme']['bartik'] = $theme;

  // crm_core_demo
  $theme = array();

  $theme['block-promo_jumbotron'] = array(
    'module' => 'block',
    'theme' => 'crm_core_demo',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Promo - Jumbotron',
    'cache' => -1,
    'machine_name' => 'promo_jumbotron',
  );

  $theme['boxes-promo_demo'] = array(
    'module' => 'boxes',
    'delta' => 'promo_demo',
    'theme' => 'crm_core_demo',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -2,
  );

  $theme['boxes-promo_features'] = array(
    'module' => 'boxes',
    'delta' => 'promo_features',
    'theme' => 'crm_core_demo',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -2,
  );

  $theme['boxes-promo_people'] = array(
    'module' => 'boxes',
    'delta' => 'promo_people',
    'theme' => 'crm_core_demo',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -2,
  );

  $theme['boxes-promo_portable'] = array(
    'module' => 'boxes',
    'delta' => 'promo_portable',
    'theme' => 'crm_core_demo',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -2,
  );

  $theme['boxes-promo_pro_tips'] = array(
    'module' => 'boxes',
    'delta' => 'promo_pro_tips',
    'theme' => 'crm_core_demo',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -2,
  );

  $export['theme']['crm_core_demo'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export['theme'][$theme_key]);
    }
  }
  return $export;
}
