<?php

/**
 * @file
 * Rules implementations.
 */

/**
 * Implements hook_rules_action_info().
 */
function deploy_rules_action_info() {
  return array(
    'deploy_rules_action_deploy_plan' => array(
      'label' => t('Deploy a plan'),
      'group' => t('Deploy'),
      'parameter' => array(
        'plan_name' => array(
          'type' => 'text',
          'label' => t('Plan name'),
          'options list' => 'deploy_rules_plan_get_options'
        ),
      ),
    ),
    'deploy_rules_action_add_to_managed_plan' => array(
      'label' => t('Add entity to managed deployment plan'),
      'group' => t('Deploy'),
      'parameter' => array(
        'plan_name' => array(
          'type' => 'text',
          'label' => t('Plan name'),
          'description' => t('The plan to add the entity to.'),
          'options list' => 'deploy_rules_manager_plan_get_options'
        ),
        'entity' => array(
          'type' => 'entity',
          'label' => t('Entity'),
          'description' => t('The entity that shall be added to the plan.'),
          'wrapped' => TRUE,
        ),
      ),
    ),
    'deploy_manager_action_delete_from_plan' => array(
      'label' => t('Remove an entity from a deployment plan'),
      'group' => t('Deploy'),
      'parameter' => array(
        'plan_name' => array(
          'type' => 'text',
          'label' => t('Plan name'),
          'description' => t('The plan to remove the entity from.'),
          'options list' => 'deploy_rules_manager_plan_get_options'
        ),
        'entity' => array(
          'type' => 'entity',
          'label' => t('Entity'),
          'description' => t('The entity that shall be removed from the plan.'),
          'wrapped' => TRUE,
        ),
      ),
    ),
  );
}

/**
 * Option callback.
 */
function deploy_rules_plan_get_options() {
  return deploy_plan_get_options(array('fetch_only' => FALSE));
}

/**
 * Option callback.
 */
function deploy_rules_manager_plan_get_options() {
  return deploy_manager_plan_get_options(array('fetch_only' => FALSE));
}

/**
 * Action callback for the "Deploy a plan" action.
 */
function deploy_rules_action_deploy_plan($plan_name) {
  if ($plan = deploy_manager_plan_load($plan_name)) {
    $plan->deploy();
    return;
  }
  watchdog('deploy', 'Cannot deploy non-managed plan %name', array('%name' => $plan_name), WATCHDOG_ERROR);
}

/**
 * Action callback for the "Add to deploy plan" action.
 */
function deploy_rules_action_add_to_managed_plan($plan_name, $entity_wrapper) {
  if (!deploy_manager_plan_load($plan_name)) {
    watchdog('deploy', 'Cannot add to non-managed plan %name', array('%name' => $plan_name), WATCHDOG_ERROR);
    return;
  }
  $entity_type = $entity_wrapper->type();
  $entity = $entity_wrapper->value();
  deploy_manager_add_to_plan($plan_name, $entity_type, $entity);
}

/**
 * Action callback for the "Remove from deploy plan" action.
 */
function deploy_manager_action_delete_from_plan($plan_name, $entity_wrapper) {
  if (!deploy_manager_plan_load($plan_name)) {
    watchdog('deploy manager', 'Attempted to remove from a non-existent deploy plan or one that cannot be arbitrarily removed from: @plan', array('@plan' => $plan_name), WATCHDOG_ERROR);
    return;
  }
  $entity_type = $entity_wrapper->type();
  $entity = $entity_wrapper->value();
  deploy_manager_delete_from_plan($plan_name, $entity_type, $entity);
}
