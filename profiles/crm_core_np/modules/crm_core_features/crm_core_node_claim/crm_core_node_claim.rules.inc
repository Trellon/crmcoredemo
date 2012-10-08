<?php

/**
 * @file
 * Rules hook implementations for crm_core_node_claim module.
 */


/**
 * Implements hook_rules_event_info().
 */
function crm_core_node_claim_rules_event_info() {
  $defaults = array(
    'group' => t('CRM Core node claim'),
    'module' => 'crm_core_node_claim',
    'access callback' => 'crm_core_node_claim_rules_integration_access',
  );

  $events = array();
    
//  $events['claim_profile_event_request'] = $defaults + array(
//    'label' => t('New profile claim requested'),
//    'variables' => _nursegroups_claim_profile_event_variables(),
//    'help' => t('This event is triggered when someone successfully completes a profile claim form'),
//  );
  
  $events['crm_core_node_claim_approve'] = $defaults + array(
    'label' => t('New node claim is approved'),
    'variables' => _crm_core_node_claim_event_variables(),
    'help' => t('This event is triggered when a node claim is approved'),
  );
  
  $events['crm_core_node_claim_reject'] = $defaults + array(
    'label' => t('New node claim is rejected'),
    'variables' => _crm_core_node_claim_event_variables(),
    'help' => t('This event is triggered when a node claim is rejected'),
  );
 
  return $events;
}

/**
*  integration access callback.
*/
function crm_core_node_claim_rules_integration_access($type, $name) {
  return user_access('administer profile claims');
}

/**
 * Helper function for providing common event variables.
 */
function _crm_core_node_claim_event_variables() {  
  $variables = array(
    'claim_reference' => array(
      'type' => 'node', 
      'label' => t('The reference node where the claim is made'),
     ),  
    'contact' => array(
      'type' => 'crm_core_contact', 
      'label' => t('The contact information of the requester'),
     ),
    'activity' => array(
      'type' => 'crm_core_activity', 
      'label' => t('The profile claim activity created'),
     ),
  );
    
  return $variables;
}
