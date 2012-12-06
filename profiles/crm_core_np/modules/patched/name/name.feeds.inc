<?php

/**
 * @file
 * Implements Feeds mapping API
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 */
function name_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);
    if ($info['type'] == 'name') {
      foreach (_name_translations() as $key => $title) {
        if (array_key_exists($key, $info['columns'])) {
          $targets[$name . ':' . $key] = array(
            'name' => t('@name !component', array('@name' => $instance['label'], '!component' => $title)),
            'callback' => 'name_feeds_set_target',
            'description' => t('The !component component of the @label field of the node.', array('@label' => $instance['label'], '!component' => $title)),
          );
        }
      }
    }
  }
}

/**
 * Callback for feed mapping.
 */
function name_feeds_set_target($source, $entity, $target, $value) {
  if (empty($value)) {
    return;
  }

  // Handle non-multiple value fields.
  if (!is_array($value)) {
    $value = array($value);
  }

  // Iterate over all values.
  $i = 0;
  $info = field_info_field($target);
  list($field_name, $sub_field) = explode(':', $target);

  // We will call this multiple times, preserve existing values.
  $field = empty($entity->{$field_name}) ? array() : $entity->{$field_name};

  foreach ($value as $v) {
    if (!is_array($v) && !is_object($v)) {
      $field['und'][$i][$sub_field] = $v;
    }
    if ($info['cardinality'] == 1) {
      break;
    }
    $i++;
  }
  $entity->{$field_name} = $field;
}
