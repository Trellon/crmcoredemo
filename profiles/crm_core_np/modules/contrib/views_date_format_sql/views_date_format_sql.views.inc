<?php
/**
 * @file
 * This file contains the hook to assign this handler as default to node 'created' and 'changed' date fields.
 */

/**
 * Implements hook_views_data_alter().
 */
function views_date_format_sql_views_data_alter(&$data) {
  // loops through fields definitions looking for date fields
  // and change the standard date handler with our own.
  foreach($data as $module => &$table) {
    foreach($table as $id => &$field) {
      if (is_array($field) &&
          array_key_exists('field', $field) &&
          is_array($field['field']) &&
          array_key_exists('handler', $field['field']) &&
         ($field['field']['handler'] == 'views_handler_field_date')) {
          $field['field']['handler'] = 'views_date_format_sql_handler_field_date';
      }
    }
  }

}
