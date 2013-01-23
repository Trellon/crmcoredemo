<?php

/**
 * @file
 * Hooks provided by the Entity Dependency module.
 *
 * @todo
 *   Currently run-time hooks are provided to define dependencies, because some
 *   dependencies are tricky to describe in a declarative fashion. However, we
 *   should/need to make the API more declarative to be really efficient.
 *   Using hook_field_info() and hook_entity_property_info() is probably
 *   the best place to do that.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Define dependencies to an entity.
 *
 * Return an array that defines dependencies to the $entity. The
 * entity_dependency_add() function is a good helper function.
 *
 * @param $entity
 *   The entity to return dependencies for.
 * @param $entity_type
 *   The entity type of the $entity.
 *
 * @see entity_dependency_add()
 *
 * @return array
 *   The dependencies should be returned as defined below, where the keys are
 *   the entity type of the returned dependencies.
 *   @code
 *   $dependencies = array(
 *     'node' => array(
 *
 */
function hook_entity_dependencies($entity, $entity_type) {
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
 * This is not a real hook (as the other Field API hooks). This hook is called
 * for each module owner of a field. But it has the same intention as
 * hook_entity_dependencies() but is more suited for defining dependencies for
 * certain fields.
 *
 * Below is an example. Taxonomy module owns one field (the taxonomy term
 * reference field), hence it's called for all instances of that field.
 *
 * @see hook_entity_dependencies()
 */
function hook_field_entity_dependencies($entity_type, $entity, $field, $instance, $langcode, $items) {
  // No need to check for the field type here, since this hook is only called
  // for the owner of this field. Taxonomy module only owns one field.
  $dependencies = array();
  entity_dependency_add($dependencies, $items, 'taxonomy_term', 'tid');
  return $dependencies;
}
