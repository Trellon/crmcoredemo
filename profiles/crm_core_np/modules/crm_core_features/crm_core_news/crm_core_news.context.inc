<?php
/**
 * @file
 * crm_core_news.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crm_core_news_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news_item_page';
  $context->description = '';
  $context->tag = 'news';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news' => 'news',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'crm_core_news-subscription' => array(
          'module' => 'crm_core_news',
          'delta' => 'subscription',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
    'breadcrumb' => 'news',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('news');
  $export['news_item_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news_list_page';
  $context->description = '';
  $context->tag = 'news';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'news:page' => 'news:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'crm_core_news-subscription' => array(
          'module' => 'crm_core_news',
          'delta' => 'subscription',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('news');
  $export['news_list_page'] = $context;

  return $export;
}
