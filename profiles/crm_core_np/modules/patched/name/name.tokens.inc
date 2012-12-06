<?php

/**
 * @file
 * Builds placeholder replacement tokens for country-related data.
 */

/**
 * Implements hook_token_info().
 */
function name_token_info() {
  // Start depreciated tokens. These only work if given a name object.
  $types['name'] = array(
    'name' => t('Name (depreciated)'),
    'description' => t('Raw name component tokens. (depreciated)'),
    'needs-data' => 'name',
  );
  $old_tokens['default'] = array(
    'name' => t('Name (depreciated)'),
    'description' => t('Full default formatted name. Do not use, depreciated!'),
  );
  foreach (name_get_custom_format_options() as $machine_name => $formatter_title) {
    $old_tokens['formatter-' . $machine_name] = array(
      'name' => t('Name: %formatter formatted (depreciated)', array('%formatter' => $formatter_title)),
      'description' => t('Name using the %formatter formatter.', array('%formatter' => $formatter_title)),
    );
  }
  foreach (_name_translations() as $component => $component_label) {
    $old_tokens['component-' . $component] = array(
      'name' => t('Name component: %component (depreciated)', array('%component' => $component_label)),
      'description' => t('The %component component of the name.', array('%component' => $component_label)),
    );
  }
  // End depreciated tokens.

  // The basic generic user real name token.
  $user_tokens['realname'] = array(
    'name' => t('Real name'),
    'description' => t('The real name of the user account, from the RealName or Name modules.'),
  );

  // New field integration.
  $types['name-field'] = array(
    'name' => t('Name field values'),
    'description' => t('Name field in the default format.'),
    'needs-data' => 'name-field',
  );
  foreach (name_get_custom_format_options() as $machine_name => $formatter_title) {
    $tokens['formatter-' . $machine_name] = array(
      'name' => t('Formatted name: %formatter', array('%formatter' => $formatter_title)),
      'description' => t('Uses the %formatter format.', array('%formatter' => $formatter_title)),
    );
  }
  foreach (_name_translations() as $component => $component_label) {
    $tokens['component-' . $component] = array(
      'name' => t('Component: %component', array('%component' => $component_label)),
      'description' => t('The name component %component.', array('%component' => $component_label)),
    );
  }

  $token_info = array(
    'types' => $types,
    'tokens' => array(
      'name' => $old_tokens,
      'name-field' => $tokens,
      'user' => $user_tokens,
    ),
  );

  foreach (name_token_types_chained(NULL, TRUE) as $entity_type => $tokens) {
    $token_info['tokens'][$entity_type] = $tokens;
  }

  return $token_info;
}

/**
 * Implements hook_tokens().
 */
function name_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $sanitize = !empty($options['sanitize']);
  $replacements = array();

  // This handles the field tokens.
  if (isset($data[$type]) && $known_tokens = name_token_types_chained($type)) {
    foreach ($tokens as $name => $original) {
      // The RealName module provides the 'name-raw' token.
      if ($name != 'name-raw' && strpos($name, 'name-') === 0) {
        /*
         * We handle a number of different combinations here.
         * token
         * token:[delta|all]
         * token:formatter-FORMAT_NAME
         * token:[delta|all]:formatter-FORMAT_NAME
         * token:component-TYPE
         * token:[delta|all]:component-TYPE
         */
        $parts = explode(':', $name);
        $field_name = array_shift($parts);
        $field_name = str_replace('-', '_', substr($field_name, 5));

        // Ensure that this is actually a real field token before replacing.
        // This will mimimise the chances of false matches like 'name-raw'.
        if (field_info_field($field_name)) {
          $items = field_get_items($type, $data[$type], $field_name);
          if (empty($items)) {
            $replacements[$original] = '';
            continue;
          }

          // Find the delta value.
          $delta = NULL;
          $next = array_shift($parts);
          if (isset($next)) {
            if (is_numeric($next) && ((string) intval($next)) === (string) $next) {
              $delta = $next;
            }
            elseif ($next == 'all') {
              $delta = 'all';
            }
            else {
              // Return the value to the array for the next step.
              $delta = 0;
              array_unshift($parts, $next);
            }
          }
          else {
            $delta = 0;
          }

          if ($delta != 'all' && !isset($items[$delta])) {
            $replacements[$original] = '';
            continue;
          }

          // Find the token action and format / component.
          $action = NULL;
          $action_key = NULL;
          if ($next = array_shift($parts)) {
            if (strpos($next, 'formatter-') === 0) {
              $action = 'formatter';
              $action_key = substr($next, 10);
            }
            elseif (strpos($next, 'component-') === 0) {
              $action = 'component';
              $action_key = substr($next, 10);
            }
          }
          else {
            $action_key = 'default';
            $action = 'formatter';
          }

          $names = array();
          if ($action == 'formatter') {
            $format = name_get_format_by_machine_name($action_key);
            if (empty($format)) {
              $format = name_get_format_by_machine_name('default');
            }
            if ($delta != 'all') {
              $items = array($items[$delta]);
            }

            foreach ($items as $item) {
              $names[] = name_format($item, $format);
            }
          }
          else {
            if ($delta != 'all') {
              $items = array($items[$delta]);
            }
            foreach ($items as $item) {
              if (isset($item[$action_key])) {
                $names[] = $item[$action_key];
              }
            }

          }
          $names = implode(', ', array_filter($names));
          $replacements[$original] = $sanitize ? check_plain($names) : $names;
        }
      }
    }
  }

  if ($type == 'user' && !empty($data['user'])) {
    $account = $data['user'];
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'realname':
          $replacements[$original] = '';
          if (!empty($account->realname)) {
            $replacements[$original] = $sanitize ? check_plain($account->realname) : $account->realname;
          }
          break;
      }
    }
  }

  if ($type == 'name' && !empty($data['name'])) {
    $name = $data['name'];
    $name_components = array();
    foreach (_name_translations() as $key => $title) {
      if (!empty($name[$key])) {
        $name_components[$key] = $name[$key];
      }
      else {
        $name_components[$key] = '';
      }
    }

    foreach ($tokens as $key => $original) {
      if ($key == 'default') {
        // Full default formatted name.
        $default = name_format($name_components, name_settings('default_format'));
        $replacements[$original] = $sanitize ? check_plain($default) : $default;
      }
      elseif (strpos($key, 'formatter-') === 0) {
        list(,$machine_name) = explode('-', $key, 2);
        $format = name_get_format_by_machine_name($machine_name);
        $formated_name = name_format($name_components, $format);
        $replacements[$original] = $sanitize ? check_plain($formated_name) : $formated_name;
      }
      elseif (strpos($key, 'component-') === 0) {
        list(,$component) = explode('-', $key, 2);
        $replacements[$original] = $sanitize ? check_plain($name_components[$component]) : $name_components[$component];
      }
    }
  }

  return $replacements;
}

/**
 * Defines a list of token types that can be chained with the name field.
 *
 * @return
 *   If an entity (token) type is given, returns the chained sub-list.
 */
function name_token_types_chained($type = NULL, $reset = FALSE) {
  // This functions gets called rather often when replacing tokens.
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast['types'] = &drupal_static(__FUNCTION__);
  }
  $types = &$drupal_static_fast['types'];

  if (!isset($types) || $reset) {
    // Note that this hook contains translated strings, so each language is
    // cached separately.
    global $language;
    $langcode = $language->language;
    if (!$reset && $cache = cache_get("name_token_types_chained:$langcode", 'cache')) {
      $types = $cache->data;
    }

    if (!$types) {
      $types = array();
      foreach (field_info_fields() as $field_name => $info) {
        if ($info['type'] == 'name') {
          foreach ($info['bundles'] as $entity_type => $bundles) {
            // Name field. Also known as Client.
            $labels = array();
            foreach ($bundles as $bundle) {
              $instance = field_info_instance($entity_type, $field_name, $bundle);
              $labels[$instance['label']] = $instance['label'];
            }
            $label = array_shift($labels);
            $clean = str_replace('_', '-', $field_name);
            if (empty($labels)) {
              $description = t('Name field in the default format. To specify a delta value, use "@token:0". Append the other chained options after the delta value like this, "@token:0:component-given". Replace the delta value with all to obtain all items in the field like this "@token:all".',
                array('@token' => $clean));
            }
            else {
              $description = t('Name field in the default format. Also known as %labels', array('%labels' => implode(', ', $labels)));
            }
            $types[$entity_type]['name-' . $clean] = array(
              'name' => check_plain($label),
              'description' => $description,
              'type' => 'name-field',
            );
          }
        }
      }
      cache_set("name_token_types_chained:$langcode", $types);
    }
  }
  if (isset($type)) {
    return isset($types[$type]) ? $types[$type] : NULL;
  }
  return $types;
}
