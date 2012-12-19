<?php
/**
 * @file
 * crm_core_news.features.inc
 */

/**
 * Implements hook_default_crm_core_activity_type().
 */
function crm_core_news_default_crm_core_activity_type() {
  $items = array();
  $items['news_subscription'] = entity_import('crm_core_activity_type', '{
    "type" : "news_subscription",
    "label" : "Newsletter Subscription",
    "weight" : 0,
    "description" : ""
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function crm_core_news_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function crm_core_news_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function crm_core_news_node_info() {
  $items = array(
    'simplenews' => array(
      'name' => t('Simplenews newsletter'),
      'base' => 'node_content',
      'description' => t('A newsletter issue to be sent to subscribed email addresses.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
