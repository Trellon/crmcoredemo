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
    "label" : "News Subscription",
    "weight" : 0,
    "description" : ""
  }');
  return $items;
}

/**
 * Implements hook_views_api().
 */
function crm_core_news_views_api() {
  return array("version" => "3.0");
}
