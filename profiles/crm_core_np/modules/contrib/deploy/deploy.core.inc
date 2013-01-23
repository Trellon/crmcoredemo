<?php

/**
 * @defgroup deploy_alter Deployment alterations
 * @{
 */

/**
 * Implements hook_entity_load().
 *
 * The 'parent' property isn't attached when terms are loaded. Deploy needs that
 * variable to correctly deploy terms.
 */
function taxonomy_entity_load(&$entities, $entity_type) {
  if ($entity_type == 'taxonomy_term') {
    foreach ($entities as &$entity) {
      if (!isset($entity->parent)) {
        $parents = taxonomy_get_parents($entity->tid);
        if (!empty($parents)) {
          $entity->parent = array();
          foreach ($parents as $parent) {
            $entity->parent[] = $parent->tid;
          }
        }
      }
    }
  }
}

/**
 * Implements hook_deploy_entity_alter().
 */
function file_deploy_entity_alter(&$entity, $entity_type) {
  if ($entity_type == 'file') {
    if (!isset($entity->file_contents)) {
      $entity->file_contents = base64_encode(file_get_contents($entity->uri));
    }
  }
}

/**
 * Implements hook_deploy_entity_alter().
 *
 * This hook will go through all fields for an entity and invoke a new hook for
 * all field modules. This saves a lot of work for each field implementaor.
 */
function field_deploy_entity_alter(&$entity, $entity_type) {
  if (empty($entity) || empty($entity_type)) {
    return;
  }

  $dependencies = array();
  list(,, $bundle_name) = entity_extract_ids($entity_type, $entity);
  $instances = field_info_instances($entity_type, $bundle_name);

  foreach ($instances as $field_name => $instance) {
    $field = field_info_field($field_name);
    foreach ($entity->{$field_name} as $langcode => &$items) {
      foreach ($items as &$item) {
        // This can potentially save *a lot* of bandwidth, since these values
        // aren't really needed when deploying.
        foreach (array('safe_value', 'safe_summary') as $key) {
          if (isset($item[$key])) {
            unset($item[$key]);
          }
        }
      }
      // TODO: Can we do this with drupal_alter()? Reason for this quick and
      // mashup is because I want to keep the argument order consistent between
      // field hooks, and still possibility to alter arguments.
      $function = $field['module'] . '_deploy_field_alter';
      if (function_exists($function)) {
        $function($entity_type, $entity, $field, $instance, $langcode, $items);
      }
    }
  }
  return $dependencies;
}

/**
 * @} End of "Deployment alterations"
 */

/**
 * @defgroup deploy_operations Bulk operations
 * @{
 */

/**
 * Implements hook_node_operations().
 */
function deploy_node_operations() {
  $operations = array();
  $options = deploy_manager_plan_get_options();
  foreach ($options as $plan_name => $plan_title) {
    $operations['deploy:add:' . $plan_name] = array(
      'label' => $plan_title,
      'callback' => 'deploy_node_operation_add_to_managed_plan',
      'callback arguments' => array('plan_name' => $plan_name),
    );
    $operations['deploy:delete:' . $plan_name] = array(
      'label' => $plan_title,
      'callback' => 'deploy_node_operation_delete_from_managed_plan',
      'callback arguments' => array('plan_name' => $plan_name),
    );
  }
  return $operations;
}

/**
 * Node operation callback.
 */
function deploy_node_operation_add_to_managed_plan($nids, $plan_name) {
  $plan = deploy_plan_load($plan_name);
  foreach ($nids as $nid) {
    $node = node_load($nid);
    deploy_manager_add_to_plan($plan_name, 'node', $node);
  }
  $deploy_link = url("admin/structure/deploy/plans/list/$plan_name/deploy", array('query' => array('cancel_path' => 'admin/content')));
  $overview_link = url('admin/structure/deploy');
  drupal_set_message(t('Nodes were added to <a href="!overview">@plan</a>. You might want to <a href="!deploy">deploy the plan</a>.', array('@plan' => $plan->title, '!overview' => $overview_link, '!deploy' => $deploy_link)));
}

/**
 * Node operation callback.
 */
function deploy_node_operation_delete_from_managed_plan($nids, $plan_name) {
  $plan = deploy_plan_load($plan_name);
  foreach ($nids as $nid) {
    $node = node_load($nid);
    deploy_manager_delete_from_plan($plan_name, 'node', $node);
  }
  $deploy_link = url("admin/structure/deploy/plans/list/$plan_name/deploy", array('query' => array('cancel_path' => 'admin/content')));
  $overview_link = url('admin/structure/deploy');
  drupal_set_message(t('Nodes were deleted from <a href="!overview">@plan</a>. You might want to <a href="!deploy">deploy the plan</a>.', array('@plan' => $plan->title, '!overview' => $overview_link, '!deploy' => $deploy_link)));
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function deploy_form_node_admin_content_alter(&$form, $form_state) {
  if (empty($form['admin']['options']['operation']['#options'])) {
    return;
  }
  $options = &$form['admin']['options']['operation']['#options'];
  $group_add = t('Add to managed deployment plan');
  $options[$group_add] = array();
  $group_delete = t('Delete from managed deployment plan');
  $options[$group_delete] = array();
  foreach ($form['admin']['options']['operation']['#options'] as $key => $value) {
    list($module) = explode(':', $key);
    if ($module == 'deploy') {
      list(,$op) = explode(':', $key);
      unset($options[$key]);
      if ($op == 'add') {
        unset($options[$key]);
        $options[$group_add][$key] = $value;
      }
      elseif ($op == 'delete') {
        $options[$group_delete][$key] = $value;
      }
    }
  }
}

/**
 * @} End of "Bulk operations"
 */
