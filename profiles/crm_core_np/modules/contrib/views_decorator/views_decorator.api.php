<?php

/**
 * @file
 * Hooks provided by Views Decorator.
 */

/**
 * @addtogroup hooks
 * @{
 * Hooks that can be implemented by other modules in order to use the Views Decorator API.
 */

/**
 * Register Views decorators.
 *
 * You can use this hook to describe which class Views uses you want to decorate.
 * Views Decorator then when needed automatically generates and registers decorators
 * for all classes having a parent link in the Views registry to this particular
 * class you've chosen. For now only works for Views handlers.
 */
function hook_views_decorators() {
  return array(
    'info' => array(
    //'module' => 'my_module',
    //'path' => drupal_get_path('module', 'my_module') . '/handlers',
    ),
    'handlers' => array(
      'my_module_handler' => array(
        'parent' => 'views_parent_handler',
      //'module' => 'my_module',
      //'path' => drupal_get_path('module', 'my_module') . '/handlers',
      //'file' => 'my_module_handler.inc',
      //'handler' => 'my_module_handler',
      ),
    ),
  );
}

/**
 * @} End of "addtogroup hooks".
 */
