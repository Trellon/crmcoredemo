<?php

/**
 * Returns the items for a given plan.
 *
 * @param $plan_name
 *   Name of the managed plan to fetch entities from.
 */
function deploy_manager_get_entities($plan_name) {
  $entities = array();
  $result = db_query("SELECT * FROM {deploy_manager_entities} WHERE plan_name = :plan_name", array(':plan_name' => $plan_name));
  foreach ($result as $record) {
    $entities[] = array('type' => $record->entity_type, 'id' => $record->entity_id);
  }
  // If the plan fetched from the database is empty, try fetch default UUID
  // entities (keyed with this plan name).
  if (empty($entities)) {
    if (module_exists('features')) {
      features_include_defaults(array('uuid_entities'));
    }
    $plans = module_invoke_all('uuid_default_entities');
    if (isset($plans[$plan_name])) {
      foreach ($plans[$plan_name] as $entity) {
        // We don't want entities that has a cause, i.e. not dependencies, because
        // those'll be taken care of when the service iterates over the queue.
        if (empty($entity->__metadata['cause'])) {
          $entity_type = $entity->__metadata['type'];
          $entity_info = entity_get_info($entity_type);
          $entity_ids = entity_get_id_by_uuid($entity_type, array($entity->{$entity_info['entity keys']['uuid']}));
          $entity_id = reset($entity_ids);
          if (!empty($entity_id)) {
            $entities[] = array('type' => $entity_type, 'id' => $entity_id);
          }
        }
      }
    }
  }
  return $entities;
}

/**
 * Loads a managed plan with the given name, returns false if no such plan
 * exists.
 */
function deploy_manager_plan_load($name) {
  $result = deploy_plan_load_all(array('aggregator_plugin' => 'DeployAggregatorManaged'));
  if (isset($result[$name])) {
    return $result[$name];
  }
  return FALSE;
}

/**
 * Returns a list of all managed plans, i.e. all plans that use the
 * DeployAggregatorManager aggregator plugin.
 */
function deploy_manager_plan_load_all() {
  return deploy_plan_load_all(array('aggregator_plugin' => 'DeployAggregatorManaged'));
}

/**
 * Options callback for the deploy_plan data type.
 */
function deploy_manager_plan_get_options($args = array()) {
  $default_args = array(
    'aggregator_plugin' => 'DeployAggregatorManaged',
  );
  $args = array_merge($default_args, $args);

  $plans = deploy_plan_load_all($args);
  $options = array();
  foreach ($plans as $plan_name => $info) {
    $options[$plan_name] = $info->title;
  }
  return $options;
}

/**
 * Adds an entity to a managed deployment plan.
 *
 * @param $plan_name
 *   The machine name of the plan to add to.
 * @param $entity_type
 *   The entity type to be deployed.
 * @param $entity
 *   The entity to be deployed.
 */
function deploy_manager_add_to_plan($plan_name, $entity_type, $entity) {
  list($entity_id, $revision_id) = entity_extract_ids($entity_type, $entity);
  $revision_id = ($revision_id === NULL) ? 0 : $revision_id;

  try {
    db_insert('deploy_manager_entities')
      ->fields(array(
        'plan_name' => $plan_name,
        'entity_type' => $entity_type,
        'entity_id' => $entity_id,
        'revision_id' => $revision_id,
        'timestamp' => time(),
      ))
      ->execute();
  }
  // The query failed, most probably because of duplicate primary keys.
  catch (Exception $e) {
    watchdog('deploy', 'Adding !entity_type !entity_id of revision !revision_id to deployment plan @plan failed. Only one entity per revision is allowed.', array('!entity_type' => $entity_type, '!entity_id' => $entity_id, '!revision_id' => $revision_id, '@plan' => $plan_name), WATCHDOG_NOTICE);
  }
}

/**
 * Delete an entity from a managed deployment plan.
 *
 * @param $plan_name
 *   The machine name of the plan to remove from.
 *
 * @param $entity_id
 *   The id of the entity to be removed from the plan.
 */
function deploy_manager_delete_from_plan($plan_name, $entity_type, $entity) {
  list($entity_id, $revision_id) = entity_extract_ids($entity_type, $entity);
  db_delete('deploy_manager_entities')
    ->condition('entity_type', $entity_type)
    ->condition('entity_id', $entity_id)
    ->condition('plan_name', $plan_name)
    ->execute();
}

/**
 * Postprocess operation callback.
 */
function deploy_manager_postprocess_operation($plan_name, $entity) {
  $plan = deploy_plan_load($plan_name);
  if (!empty($plan->aggregator_config['delete_post_deploy'])) {
    deploy_manager_delete_from_plan($plan->name, $entity->__metadata['type'], $entity);
  }
}

/**
 * Implements hook_entity_delete().
 */
function deploy_entity_delete($entity, $entity_type) {
  $plans = deploy_manager_plan_load_all();
  foreach ($plans as $plan) {
    deploy_manager_delete_from_plan($plan->name, $entity_type, $entity);
  }
}
