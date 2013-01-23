<?php

/**
 * @file
 * Hooks provided by the Deploy module.
 */

/**
 * Allow modules to modify an entity before it gets deployed.
 *
 * @param $entity
 *   The entity being deployed.
 *
 * @param $entity_type
 *   The entity type; e.g. 'node' or 'user'.
 */
function hook_deploy_entity_alter(&$entity, $entity_type) {

}

/**
 * Allow modules to define dependencies to an entity.
 *
 * This hook is mostly useful to determine dependencies based on entity
 * properties or other primitive values. Implement
 * 'hook_deploy_field_dependencies' if your field module must declare a field
 * related dependency to an entity.
 *
 * @param $entity
 *   The entity being deployed.
 *
 * @param $entity_type
 *   The entity type; e.g. 'node' or 'user'.
 *
 * @return
 *   An array of entities structure as follows:
 * @code
 *   $dependencies = array(
 *     'node' => array(
 *       10 => TRUE,
 *       12 => array(
 *         'taxonomy_term' => array(
 *           14 => TRUE,
 *         ),
 *         'user' => array(
 *           8 => TRUE,
 *         ),
 *       ),
 *     ),
 *     'taxonomy_term' => array(
 *       16 => TRUE,
 *     ),
 *   );
 * @endcode
 */
function hook_deploy_entity_dependencies($entity, $entity_type) {

}

/**
 * Allow other modules to alter dependencies.
 *
 * @param $dependencies
 *   The array of dependencies to be deployed with this entity.
 *
 * @param $entity
 *   The entity being deployed.
 *
 * @param $entity_type
 *   The entity type; e.g. 'node' or 'user'.
 */
function hook_deploy_entity_dependencies_alter(&$dependencies, $entity, $entity_type) {

}

/**
 * Allow modules to define belongings for an entity.
 *
 * @param $entity
 *   The entity being deployed.
 *
 * @param $entity_type
 *   The entity type; e.g. 'node' or 'user'.
 *
 * @return
 *   An array of belongings for this entity.
 */
function hook_deploy_entity_belongings($entity, $entity_type) {

}

/**
 * Allow modules to modify the belongings of an entity before it is deployed.
 *
 * @param array $belongings
 *  The array of belongings to be deployed with the entity.

 * @param $entity
 *   The entity being deployed.
 *
 * @param $entity_type
 *   The entity type; e.g. 'node' or 'user'.
 */
function hook_deploy_entity_belongings_alter(&$belongings, $entity, $entity_type) {

}


/**
 * Allow field modules to define entity denepdencies for their fields.
 *
 * This hook should be seen as an extension of the Field API and thus, does not
 * use the 'deploy' namespace.
 *
 * @param $entity_type
 *   The entity type; e.g. 'node' or 'user'.
 *
 * @param $entity
 *   The entity being deployed.
 *
 * @param $field
 *   The particular field in the entity whose dependencies are being gathered.
 *
 * @param $instance
 *   The field instance name.
 *
 * @param $langcode
 *   The language code for the field values.
 *
 * @param $items
 *   An array of field values.
 *
 * @return
 *   An array of field dependencies, structured the same way as for dependencies
 *   at the entity level.(See hook_deploy_entity_dependencies() above)
 */
function hook_deploy_field_dependencies($entity_type, $entity, $field, $instance, $langcode, $items) {

}

/**
 * Allow modules to modify the array of dependencies for a field.
 *
 * @todo Change this to hook_deploy_field_dependencies_alter for consistency?
 *
 * @param $field_dependencies
 *   The array of dependencies for this field.
 *
 * @param $entity_type
 *   The entity type; e.g. 'node' or 'user'.
 *
 * @param $entity
 *   The entity being deployed.
 *
 * @param $field
 *   The particular field in the entity whose dependencies are being gathered.
 *
 * @param $instance
 *   The field instance name.
 *
 * @param $langcode
 *   The language code for the field values.
 *
 * @param $items
 *   An array of field values.
 */
function hook_deploy_field_dependency_alter(&$field_dependencies, $entity_type, $entity, $field, $instance, $langcode, $items) {

}

/**
 * Allow module to react to a deployment.
 *
 * @todo
 *   Rename to 'hook_entity_deploy' and add a 'hook_entity_predeploy' to mimic
 *   ie. 'hook_entity_presave' and 'hook_entity_insert'.
 *
 * @param $sender
 *   The object invoking the hook, e.g a deploy aggregator object.
 *
 * @param $args
 *   An associative array containing information about the entity deployment that
 *   just occurred. Possible keys are:
 *   - 'eid'
 *     The id of the entity that was just deployed.
 *   - 'response'
 *     A response object, e.g. from a http request.
 *   - 'plan'
 *     The plan that this entity deployment was a part of.
 */
function hook_deploy_item_deployed($sender, $args) {

}
