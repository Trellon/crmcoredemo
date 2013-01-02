<?php

/**
 * @file
 * A file containing the Views Decorator module, which provides "horizontal extensibility"
 * for Views by implementing the Decorator API.
 */

/**
 * Build all handler decorators.
 */
function views_decorator_build_handler_decorators($handlers) {
  $templates = views_decorator_discover_handler_decorator_templates();

  $definitions = array();
  // Loading handler decorators' definitions.
  foreach ($templates as $template => $template_definition) {
    $decorators = array();
    // Decorate all the handlers which inherit from the decorator template's parent and add those decorators to the definitions cache.
    foreach ($handlers as $handler) {
      if (class_exists($handler) && is_subclass_of($handler, $template_definition['parent'])) {
        // Create a handler decorator definition.
        $handler_decorator = _views_decorator_get_handler_decorator($handler, $template_definition['module']);
        $decorator_definition = array(
          'parent' => $handler,
        );

        // Merge the definition in.
        $decorators[$handler_decorator] = $decorator_definition;
        // We have to merge the definition to the handlers array too to iterate through it in the next iteration and obtain decorators combining functionalities from several decorator templates.
        $handlers[$handler_decorator] = $decorator_definition;
      }
    }

    // Merge definitions in.
    $definitions[$template] = $template_definition;
    $definitions[$template]['decorators'] = $decorators;
  }

  $definitions = array(
    'templates' => $definitions,
  );

  // Build decorators.
  decorator_set_decorators('views_decorator', $definitions);
}

/**
 * Build and return list of all handler decorator templates available in the system.
 */
function views_decorator_discover_handler_decorator_templates() {
  $templates = array();
  // Get decorator templates from all modules by invoking 'views_decorators' hook.
  foreach (module_implements('views_decorators') as $module) {
    $function = $module . '_views_decorators';
    $result = $function();
    if (!is_array($result)) {
      continue;
    }

    $module_dir = isset($result['info']['module']) ? $result['info']['module'] : $module;
    $path = isset($result['info']['path']) ? $result['info']['path'] : drupal_get_path('module', $module_dir);

    if (isset($result['handlers'])) {
      foreach ($result['handlers'] as $handler => $def) {
        if (!isset($def['module'])) {
          $def['module'] = $module_dir;
        }
        if (!isset($def['path'])) {
          $def['path'] = $path;
        }
        if (!isset($def['file'])) {
          $def['file'] = "$handler.inc";
        }
        if (!isset($def['handler'])) {
          $def['handler'] = $handler;
        }
        // Merge the definition in.
        $templates[$handler] = $def;
      }
    }
  }
  return $templates;
}

/**
 * Helper function for generating decorated handler's name.
 */
function _views_decorator_get_handler_decorator($handler, $module) {
  // '_handler_SUFIX'
  if ($sufix = strstr($handler, '_handler')) {
    // 'PREFIX'
    $prefix = substr($handler, 0, strpos($handler, '_handler'));
    if ($prefix == 'views') {
      // 'module_handler_SUFIX'
      return $module . $sufix;
    }
    else {
      // 'module_PREFIX_handler_SUFIX'
      return $module .'_'. $prefix . $sufix;
    }
  }
  else {
    return false;
  }
}

/**
 * Implements hook_views_data_alter().
 */
function views_decorator_views_data_alter(&$data) {
  // Search $data for registered handlers.
  $handlers = array();
  foreach ($data as $table) {
    foreach ($table as $field) {
      if (is_array($field)) {
        $handlers = array_merge($handlers, _views_decorator_discover_handlers($field));
      }
    }
  }
  $handlers = array_unique($handlers);

  // Create handler decorators.
  views_decorator_build_handler_decorators($handlers);

  // We need to search $data for the registered handlers for which we've build decorators and change them accordingly.
  foreach ($data as &$table) {
    foreach ($table as &$field) {
      if (is_array($field)) {
        array_walk_recursive($field, '_views_decorator_change_handler');
      }
    }
  }
}

/**
 * Helper function for recursivelly discovering registered handlers.
 */
function _views_decorator_discover_handlers($data) {
  $handlers = array();
  if (is_array($data)) {
    foreach ($data as $key => $value) {
      if ($key === 'handler') {
        $handlers[] = $value;
      }
      $handlers = array_merge($handlers, _views_decorator_discover_handlers($value));
    }
  }
  return $handlers;
}

/**
 * Helper function for changing registered handlers.
 */
function _views_decorator_change_handler(&$value, $key) {
  if ($key === 'handler') {
    if ($decorator = decorator_get_decorator('views_decorator', $value)) {
      $value = $decorator;
    }
  }
}
