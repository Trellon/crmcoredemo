<?php

/*
 * @file
 *
 */
 
function twitter_bootstrap_ui_admin_settings() {
  $form['twitter_bootstrap_ui_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter bootstrap Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => -1
  );
  $form['twitter_bootstrap_ui_settings']['jquerymobile_ui_plugin_jq_file'] = array(
    '#type' => 'textfield',
    '#title' => t('jQuery JavaScript'),
    '#default_value' => variable_get('twitter_bootstrap_ui_jq_files', twitter_bootstrap_theme_get_setting('twitter_bootstrap_jq_files')),
    '#description' => t('Enter the path and filename, relative to Drupal root, where the jQuery JavaScript file is located.'),
  );
  $form['twitter_bootstrap_ui_settings']['twitter_bootstrap_ui_css_files'] = array(
    '#type' => 'textarea',
    '#title' => t('CSS includes'),
    '#default_value' => variable_get('twitter_bootstrap_ui_css_files', twitter_bootstrap_theme_get_setting('twitter_bootstrap_css_files')),
    '#description' => t('Enter the path and filename, relative to Drupal root, where the CSS file is located, seperated by an new line.'),
  );
  $form['twitter_bootstrap_ui_settings']['twitter_bootstrap_ui_js_files'] = array(
    '#type' => 'textarea',
    '#title' => t('JS includes'),
    '#default_value' => variable_get('twitter_bootstrap_ui_js_files', twitter_bootstrap_theme_get_setting('twitter_bootstrap_js_files')),
    '#description' => t('Enter the path and filename, relative to Drupal root, where the JavaScript file is located, seperated by an new line.'),
  );

  return system_settings_form($form);
}
