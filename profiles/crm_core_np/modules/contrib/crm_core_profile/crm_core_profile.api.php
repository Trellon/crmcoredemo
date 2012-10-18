<?php

/**
 *
 * Notify Drupal when a CRM Core Profile entry form is being submitted/saved
 *
 * @param array $crm_core_profile
 *   Information of the CRM Core profile that's associated with the CRM Core profile entry form
 *   Being submitted
 * @param array $form_state_values
 *   An array of form_state['values'] data submitted by the CRM Core profile entry form
 *
 */
function hook_crm_core_profile_save($crm_core_profile, $form_state_values) {
  
  // trigger an email to the user that submitted the form;
  global $user;
  
  drupal_mail('crm_core_profile_notification', 'crm_core_profile_notification', $user->mail, LANGUAGE_NONE, array(), variable_get('site_mail', NULL), TRUE);      
}


/**
 *
 * Notify Drupal when a CRM Core Profile entry form is submitted and the contact is saved
 *
 * @param array $crm_core_profile
 *   Information of the CRM Core profile that's associated with the CRM Core profile entry form
 *   Being submitted
 * @param stdClass() $contact
 *   An object that contains the CRM Core Contact data that's created/saved/updated
 *
 */
function hook_crm_core_profile_save_contact($crm_core_profile, $contact) {
  
  // saving additional information into the contact object
  $contact->field_contact_source = 'google_cpc';
  crm_core_contact_save($contact);
  
}

/**
 *
 * Offers the ability to change form elements to be rendered on the CRM Core Profile Entry form
 *
 * @param array $form
 *   The form tree
 *
 * @param array $render_fields
 *   An array of fields to be rendered, it is a sorting array with
 *   keyed by weight and value
 *
 */
function hook_crm_core_profile_theme_alter(&$form, &$render_fields) {
  $profile_activity = crm_core_profile_activity_load($form['profile_name']['#value']);
  
  if (empty($profile_activity)) {
    return; 
  }
  
  $fields = unserialize($profile_activity['fields']);
  foreach ($fields['weight'] as $field => $weight) {
      $render_fields[$weight['weight']['weight']] = "activity||" . $field;
  } 
}


/**
 *
 * Notify Drupal when a CRM Core Profile is being deleted
 *
 * @param string $machine_name
 *   The name of the CRM Core Profile being deleted
 *
 */
function hook_crm_core_profile_delete($machine_name) {
    db_delete('crm_core_profile_activity')
    ->condition('name', $machine_name)
    ->execute();  
}

/**
 * Update administrative form with ajax on contact bundle type element update
 *
 * @return ajax_commands array.
 */
function hook_crm_core_profile_new_form_bundle_type_ajax_callback() {
  $html = drupal_render($form['relation']['bundle_type']);
  $commands[] = ajax_command_replace(
    '#crm-core-profile-relation-bundle-type',
    $html
  );
  return $commands;
}
