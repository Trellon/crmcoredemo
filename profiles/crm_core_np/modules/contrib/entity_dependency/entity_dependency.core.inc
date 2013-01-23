<?php

/**
 * @file
 * Contains hook implementations for all relevant core module.
 */

/**
 * @defgroup entity_dependency_property Propery dependency implementations
 * @{
 */

/**
 * Implements hook_entity_dependenies().
 */
function node_entity_dependencies($entity, $entity_type) {
  if ($entity_type == 'node') {
    $dependencies = array();
    // The node has a 'user' dependency through the 'uid' and
    // 'revision_uid' properties.
    entity_dependency_add($dependencies, $entity, 'user', array('uid', 'revision_uid'));
    // The node has a 'node' dependency through the 'tnid' property.
    entity_dependency_add($dependencies, $entity, 'node', 'tnid');
    return $dependencies;
  }
}

/**
 * Implements hook_entity_dependenies().
 */
function user_entity_dependencies($entity, $entity_type) {
  if ($entity_type == 'user' && variable_get('user_pictures', 0) && !empty($entity->picture)) {
    $dependencies = array();
    $dependencies[] = array('type' => 'file', 'id' => $entity->picture->fid);
    return $dependencies;
  }
}

/**
 * Implements hook_entity_dependenies().
 */
function comment_entity_dependencies($entity, $entity_type) {
  if ($entity_type == 'comment') {
    $dependencies = array();
    entity_dependency_add($dependencies, $entity, 'user', 'uid');
    entity_dependency_add($dependencies, $entity, 'node', 'nid');
    return $dependencies;
  }
}

/**
 * Implements hook_entity_dependencies()
 */
function taxonomy_entity_dependencies($entity, $entity_type) {
  if ($entity_type == 'taxonomy_term') {
    $dependencies = array();
    $terms = taxonomy_get_parents($entity->tid);
    foreach ($terms as $tid => $term) {
      $dependencies[] = array('type' => 'taxonomy_term', 'id' => $tid);
    }
    return $dependencies;
  }
}

/**
 * Implements hook_entity_dependencies().
 */
function field_entity_dependencies($entity, $entity_type) {
  $dependencies = array();
  list(,, $bundle_name) = entity_extract_ids($entity_type, $entity);
  $instances = field_info_instances($entity_type, $bundle_name);

  foreach ($instances as $field_name => $instance) {
    $field = field_info_field($field_name);
    foreach ($entity->{$field_name} as $langcode => $items) {
      $field_dependencies = module_invoke($field['module'], 'field_entity_dependencies', $entity_type, $entity, $field, $instance, $langcode, $items);
      // Let other modules alter dependencies for this field.
      drupal_alter('field_entity_dependencies', $field_dependencies, $entity_type, $entity, $field, $instance, $langcode, $items);

      if (!empty($field_dependencies)) {
        $dependencies = array_merge_recursive($dependencies, $field_dependencies);
      }
    }
  }
  return $dependencies;
}

/**
 * @} End of "Property dependency implementations"
 */

/**
 * @defgroup entity_dependency_field Field dependency implementations
 * @{
 */

/**
 * Implements hook_field_entity_dependencies().
 */
function taxonomy_field_entity_dependencies($entity_type, $entity, $field, $instance, $langcode, $items) {
  // No need to check for the field type here, since this hook is only called
  // for the owner of this field. Taxonomy module only owns one field.
  $dependencies = array();
  entity_dependency_add($dependencies, $items, 'taxonomy_term', 'tid');
  return $dependencies;
}

/**
 * Implements hook_field_entity_dependencies().
 */
function file_field_entity_dependencies($entity_type, $entity, $field, $instance, $langcode, $items) {
  $dependencies = array();
  entity_dependency_add($dependencies, $items, 'file', 'fid');
  entity_dependency_add($dependencies, $items, 'user', 'uid');
  return $dependencies;
}

/**
 * Implements hook_field_entity_dependencies().
 */
function image_field_entity_dependencies($entity_type, $entity, $field, $instance, $langcode, $items) {
  return file_field_entity_dependencies($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * Implements hook_field_entity_dependencies().
 */
function node_reference_field_entity_dependencies($entity_type, $entity, $field, $instance, $langcode, $items) {
  $dependencies = array();
  entity_dependency_add($dependencies, $items, 'node', 'nid');
  return $dependencies;
}

/**
 * Implements hook_field_entity_dependencies().
 */
function user_reference_field_entity_dependencies($entity_type, $entity, $field, $instance, $langcode, $items) {
  $dependencies = array();
  entity_dependency_add($dependencies, $items, 'user', 'uid');
  return $dependencies;
}

/**
 * Implements hook_field_entity_dependencies().
 */
function entityreference_field_entity_dependencies($entity_type, $entity, $field, $instance, $langcode, $items) {
  $dependencies = array();
  foreach ($items as $item) {
    $info = entity_get_info($item['target_type']);
    entity_dependency_add($dependencies, $item, $item['target_type'], $info['entity keys']['id']);
  }
  return $dependencies;
}

/**
 * Implements hook_field_entity_dependencies().
 */
function field_collection_field_entity_dependencies($entity_type, $entity, $field, $instance, $langcode, $items) {
  $dependencies = array();
  entity_dependency_add($dependencies, $items, 'field_collection_item', 'value');
  return $dependencies;
}

/**
 * @} End of "Field dependency implementations"
 */
