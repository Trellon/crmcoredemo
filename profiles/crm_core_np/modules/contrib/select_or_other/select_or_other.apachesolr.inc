<?php

/**
 * @file
 * The Select (or other) Apache Solr Search integration.
 */

/**
 * Implements hook_apachesolr_field_mappings_alter().
 *
 * Integrate with apachesolr.module.
 */
function select_or_other_apachesolr_field_mappings_alter(&$mappings) {
  $map = array(
    'display_callback' => 'apachesolr_fields_list_display_callback',
    'indexing_callback' => 'apachesolr_fields_list_indexing_callback',
    'index_type' => 'string',
    'facets' => TRUE,
  );
  $mappings['text']['select_or_other_buttons'] = &$map;
  $mappings['text']['select_or_other'] = &$map;
  $mappings['text']['select_or_other_sort'] = &$map;
}

