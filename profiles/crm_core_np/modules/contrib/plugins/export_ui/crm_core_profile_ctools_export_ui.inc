<?php

/**
 * @file
 * A Ctools Export UI plugin for FFmpeg Converter presets.
 */
module_load_include('inc', 'crm_core_profile', 'crm_core_profile.forms');

/**
 * Define this Export UI plugin.
 */
$plugin = array(
  'schema' => 'crm_core_profile',
  'access' => 'administer crm core profile forms',
  'menu' => array(
    'menu item' => 'crm_core_profile',
    'menu prefix' => 'admin/structure/crm',
    'menu title' => 'CRM Core Profile',
    'menu description' => 'Administer CRM Core Profile Forms',
  ),

  'title singular' => t('preset'),
  'title plural' => t('presets'),
  'title singular proper' => t('CRM Core Profile preset'),
  'title plural proper' => t('CRM Core Profile presets'),

//  'handler' => array(
//    'class' => 'crm_core_profile_presets_ui',
//    'parent' => 'ctools_export_ui',
//  ),

  'form' => array(
    'settings' => 'crm_core_profile_ctools_export_ui_form',
    'validate' => 'crm_core_profile_ctools_export_ui_form_validate',
    // 'submit' => 'crm_core_profile_ctools_export_ui_form_submit',
  ),
  
//  'form' => array(
//    'settings' => 'crm_core_profile_new_form',
//    'validate' => 'crm_core_profile_new_form_validate',
//    'submit' => 'crm_core_profile_new_form_submit',
//  ),
  
);

/**
 * Ctools exportable UI form
 */
function crm_core_profile_ctools_export_ui_form(&$form, &$form_state) {    
  $profile = $form_state['item'];
  if (!isset($profile->name)) {
    $profile = array();  
  }
  
  module_load_include('inc', 'crm_core_profile', 'crm_core_profile.forms');
  $form += crm_core_profile_new_form($form, $form_state, $profile);
  unset($form['submit']);
}

/**
 * Form validation callback
 */
function crm_core_profile_ctools_export_ui_form_validate($form, &$form_state) {
  module_load_include('inc', 'crm_core_profile', 'crm_core_profile.forms');
  crm_core_profile_new_form_validate($form, $form_state);
}

// @todo: Vadim's contact load stuff is not being saved into exportables like rest of things, need to investigate

/**
 * Form submission callback
 */
//function crm_core_profile_ctools_export_ui_form_submit($form, &$form_state) {
//   module_load_include('inc', 'crm_core_profile', 'crm_core_profile.forms');
//   crm_core_profile_new_form_submit($form, $form_state);  
//}

function crm_core_profile_new_form_machine_name_check($value) {}
