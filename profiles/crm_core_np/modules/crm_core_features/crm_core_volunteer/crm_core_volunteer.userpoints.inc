<?php
/**
 * @file
 * Code for the SF Center Volunteer feature.
 * userpoints integration
 */
define('USERPOINTS_VOLUNTEER', 'userpoints_crm_core_volunteer');
define('USERPOINTS_VOLUNTEER_TID', 'userpoints_crm_core_volunteer_tid');
/**
 * Implements hook_userpoints
 */
function crm_core_volunteer_userpoints($op, $params = array()) {
  switch ($op) {
    case 'setting':
      $group = 'userpoints_crm_core_volunteer';
      $form[$group] = array(
        '#type'        => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed'   => TRUE,
        '#title'       => t('Points for applying for a volunteer commitment.'),        
      );

      $form[$group][USERPOINTS_VOLUNTEER] = array(
        '#type'          => 'textfield',
        '#title'         => t('Points for applying for a volunteer commitment.'),
        '#default_value' => variable_get(USERPOINTS_VOLUNTEER, 0),
        '#size'          => 5,
        '#maxlength'     => 5,
      );
      
      $form[$group][USERPOINTS_VOLUNTEER_TID] = array(
      '#type'          => 'select',
      '#title'         => t('Category'),
      '#default_value' => variable_get(USERPOINTS_VOLUNTEER_TID, 0),
      '#options'       => userpoints_get_categories(),
      '#description'   => t('Volunteer commitment points will be assigned to this category. You can modify what categories are available by modifying the <a href="!url">Userpoints taxonomy</a>.', 
        array('!url' => url('admin/structure/taxonomy/userpoints'))),
      );
      return $form;    
    break;  
  }  
}

/**
 * Implements hook_userpoints_info().
 */
function crm_core_volunteer_userpoints_info() {
  return array(
    'userpoints_crm_core_volunteer_commit' => array(
      'description' => t('Committed to a volunteer opportunity'),
    ),
  );
}

/**
 * Implements hook_entity_insert
 */
function crm_core_volunteer_entity_insert($entity, $type) {
  if (!module_exists('userpoints')) {
    return;  
  }
  
  global $user;
  if ($type == 'crm_core_activity') {
    if ($entity->type == 'volunteer_commitment') {
      // we have to award the user that's in the activity or the current user?
      // we should award to the user on the particiant list because admin can create this activity
      // from the ui
      if (module_exists('crm_user_sync')) {
        $contact_id = $entity->field_activity_participants[LANGUAGE_NONE][0]['target_id'];
        $activity_user = _crm_user_sync_get_related_entity('crm_core_contact', $contact_id, 'crm_user_sync');        
      } 
      else 
      {
        $activity_user = $user;  
      }
      
      $params = array(
        'uid' => $activity_user->uid,
        'entity_id' => $entity->activity_id,
        'entity_type' => 'crm_core_activity',
        'tid' => variable_get(USERPOINTS_VOLUNTEER_TID, 0),
      );
       // Award the points
       $params['points'] = variable_get(USERPOINTS_VOLUNTEER, 0);
       $params['operation'] = 'userpoints_crm_core_volunteer_commit';      
       userpoints_userpointsapi($params);          
    }  
  }   
}