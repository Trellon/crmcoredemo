<?php

/**
 * @file
 * Provide diff field functions for the Name Field module.
 */

/**
 * Diff field callback for parsing name field comparative values.
 */
function name_field_diff_view($items, $context) {
  $field = $context['field'];
  $instance = $context['instance'];
  $settings = $context['settings'];

  $diff_items = array();
  $format = name_get_format_by_machine_name($settings['format']);
  if (empty($format)) {
    $format = name_get_format_by_machine_name('default');
  }
  foreach ($items as $delta => $item) {
    $name = name_format($item, $format);
    $diff_items[$delta] = _name_value_sanitize($name, NULL, $settings['output']);
  }
  return $diff_items;
}

/**
 * Provide default field comparison options.
 */
function name_field_diff_default_options($field_type) {
  return array(
    'format' => 'default',
    'output' => 'default',
  );
}

/**
 * Provide a form for setting the field comparison options.
 */
function name_field_diff_options_form($field_type, $settings) {
  $options_form = array();
  $formats = array(
    'default' => t('Default'),
  ) + name_get_custom_format_options();
  $options_form['format'] = array(
    '#type' => 'select',
    '#title' => t('Name format'),
    '#default_value' => $settings['format'],
    '#options' => $formats,
    '#required' => TRUE,
  );

  $options_form['output'] = array(
    '#type' => 'radios',
    '#title' => t('Output'),
    '#default_value' => $settings['output'],
    '#options' => _name_formatter_output_options(),
    '#description' => t('This option provides additional options for rendering the field.'),
    '#required' => TRUE,
  );

  return $options_form;
}
