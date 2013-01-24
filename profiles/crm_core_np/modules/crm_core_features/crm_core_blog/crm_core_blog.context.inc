<?php
/**
 * @file
 * crm_core_blog.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crm_core_blog_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog';
  $context->description = 'Active when viewing blogs in the site.';
  $context->tag = 'blog';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'blog' => 'blog',
        'blog/*' => 'blog/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-crm_core_blog-block_2' => array(
          'module' => 'views',
          'delta' => 'crm_core_blog-block_2',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Active when viewing blogs in the site.');
  t('blog');
  $export['blog'] = $context;

  return $export;
}
