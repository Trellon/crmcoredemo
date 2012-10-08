<?php
/**
 * @file
 * Code for the SF Center Node claim feature.
 * userpoints integration
 */
define('USERPOINTS_NODE_CLAIM', 'crm_core_node_claim');
define('USERPOINTS_NODE_CLAIM_TID', 'crm_core_node_claim_tid');
define('USERPOINTS_NODE_CLAIM_OPERATION', 'crm_core_node_claim_commit');


/**
 * Implements hook_userpoints
 */
function crm_core_node_claim_userpoints($op, $params = array()) {
  switch ($op) {
    case 'setting':
      $group = 'crm_core_node_claim';
      $form[$group] = array(
        '#type'        => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed'   => TRUE,
        '#title'       => t('Points for claiming a node.'),
      );

      $form[$group][USERPOINTS_NODE_CLAIM] = array(
        '#type'          => 'textfield',
        '#title'         => t('Points for claiming a node.'),
        '#default_value' => variable_get(USERPOINTS_NODE_CLAIM, 0),
        '#size'          => 5,
        '#maxlength'     => 5,
      );
      
      $form[$group][USERPOINTS_NODE_CLAIM_TID] = array(
      '#type'          => 'select',
      '#title'         => t('Category'),
      '#default_value' => variable_get(USERPOINTS_NODE_CLAIM_TID, 0),
      '#options'       => userpoints_get_categories(),
      '#description'   => t('Points for claiming a node will be assigned to this category. You can modify what categories are available by modifying the <a href="!url">Userpoints taxonomy</a>.',
        array('!url' => url('admin/structure/taxonomy/userpoints'))),
      );
      return $form;    
    break;  
  }  
}

/**
 * Implements hook_userpoints_info().
 */
function crm_core_node_claim_userpoints_info() {
  return array(
    USERPOINTS_NODE_CLAIM_OPERATION => array(
      'description' => t('Committed for claiming a node'),
    ),
  );
}

/**
 * Implements hook_entity_update
 */
function crm_core_node_claim_entity_update($entity, $type) {
  if (!module_exists('userpoints')) {
    return;  
  }
  
  global $user;
  if ($type == 'crm_core_activity' && $entity->type == 'node_claim') {
    $status = (!empty($entity->field_claim_status[LANGUAGE_NONE][0]['value']))
      ? $entity->field_claim_status[LANGUAGE_NONE][0]['value']
      : 'none';
    
    if ($status == 'accepted') {
      $activity_user = crm_core_node_claim_userpoints_get_activity_user_to_award($entity);
      $points = crm_core_node_claim_userpoints_get_user_entity_awarded_points_sum($entity, $activity_user,
        USERPOINTS_NODE_CLAIM_OPERATION);
      if (empty($points)) {
        $points = variable_get(USERPOINTS_NODE_CLAIM, 0);
        $params = array(
          'uid' => $activity_user->uid,
          'entity_id' => $entity->activity_id,
          'entity_type' => $type,
          'tid' => variable_get(USERPOINTS_NODE_CLAIM_TID, 0),
        );
        // Award the points
        $params['points'] = $points;
        $params['operation'] = USERPOINTS_NODE_CLAIM_OPERATION;
        userpoints_userpointsapi($params);
      }
    } elseif ($status == 'rejected') {
      $activity_user = crm_core_node_claim_userpoints_get_activity_user_to_award($entity);
      $points = crm_core_node_claim_userpoints_get_user_entity_awarded_points_sum($entity, $activity_user,
        USERPOINTS_NODE_CLAIM_OPERATION);
      if (!empty($points) && $points > 0) {
        $params = array(
          'uid' => $activity_user->uid,
          'entity_id' => $entity->activity_id,
          'entity_type' => $type,
          'tid' => variable_get(USERPOINTS_NODE_CLAIM_TID, 0),
        );
        // Award the points
        $params['points'] = $points * -1;
        $params['operation'] = USERPOINTS_NODE_CLAIM_OPERATION;
        userpoints_userpointsapi($params);
      }
    }
  }  
}


/**
 * Implements hook_entity_insert
 */
function crm_core_node_claim_entity_insert($entity, $type) {
  if (!module_exists('userpoints')) {
    return;
  }

  if ($type == 'crm_core_activity' && $entity->type == 'node_claim') {
    $status = $entity->field_claim_status[LANGUAGE_NONE][0]['value'];
    if ($status == 'accepted') {
      $activity_user = crm_core_node_claim_userpoints_get_activity_user_to_award($entity);
      $points = variable_get(USERPOINTS_NODE_CLAIM, 0);
      $params = array(
        'uid' => $activity_user->uid,
        'entity_id' => $entity->activity_id,
        'entity_type' => $type,
        'tid' => variable_get(USERPOINTS_NODE_CLAIM_TID, 0),
      );
      // Award the points
      $params['points'] = $points;
      $params['operation'] = USERPOINTS_NODE_CLAIM_OPERATION;
      userpoints_userpointsapi($params);
    }
  }
}

/**
 * Return a user object that have to be awarded
 *
 * @param object crm_core_activity entity
 *
 * @return object $user
 */
function crm_core_node_claim_userpoints_get_activity_user_to_award($entity) {
  // we have to award the user that's in the activity or the current user?
  // we should award to the user on the particiant list because admin can create this activity
  // from the ui
  if (module_exists('crm_user_sync')) {
    $contact_id = $entity->field_activity_participants[LANGUAGE_NONE][0]['target_id'];
    return _crm_user_sync_get_related_entity('crm_core_contact', $contact_id, 'crm_user_sync');
  }
  else
  {
    global $user;
    return $user;
  }
}


/**
 * Retrieve from a db a summary of awarded points for $user and $entity on specific $opareation type.
 *
 * @param object crm_core_activity entity
 *
 * @param object user
 *
 * @param string userpoints operation type
 *
 * @return integer summ or FALSE
 */
function crm_core_node_claim_userpoints_get_user_entity_awarded_points_sum ($entity, $activity_user, $operation) {
  $query = db_select('userpoints_txn')
    ->fields('userpoints_txn', array('points'));
  $query->condition('entity_id', $entity->activity_id)
    ->condition('uid', $activity_user->uid)
    ->condition('operation', $operation)
    ->condition('entity_type', 'crm_core_activity');
  $query->addExpression('SUM(points)', 'points_count');

  $existed_userpoints_sum = $query->execute()->fetchField(1);

  if (empty($existed_userpoints_sum)) {
    return FALSE;
  }

  return $existed_userpoints_sum;
}
