<?php
/**
 * @file
 * crm_core_blog.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function crm_core_blog_taxonomy_default_vocabularies() {
  return array(
    'blog_tags' => array(
      'name' => 'Blog Tags',
      'machine_name' => 'blog_tags',
      'description' => 'Tags used in blog posts.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
