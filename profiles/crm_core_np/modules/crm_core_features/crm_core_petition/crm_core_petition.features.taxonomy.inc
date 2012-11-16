<?php
/**
 * @file
 * crm_core_petition.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function crm_core_petition_taxonomy_default_vocabularies() {
  return array(
    'crm_petition_tags' => array(
      'name' => 'CRM Petition Tags',
      'machine_name' => 'crm_petition_tags',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
