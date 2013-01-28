<?php
/**
 * @file
 * crm_core_demo_sample_content.deploy_plans.inc
 */

/**
 * Implements hook_deploy_plans_default().
 */
function crm_core_demo_sample_content_deploy_plans_default() {
  $export = array();

  $plan = new DeployPlan();
  $plan->disabled = FALSE; /* Edit this to true to make a default plan disabled initially */
  $plan->api_version = 1;
  $plan->name = 'crm_core_demo_sample_content';
  $plan->title = 'CRM Core Demo Sample Content';
  $plan->description = 'Sample content for CRM Core Demo.';
  $plan->debug = 0;
  $plan->aggregator_plugin = 'DeployAggregatorManaged';
  $plan->aggregator_config = array(
    'delete_post_deploy' => 0,
  );
  $plan->fetch_only = 1;
  $plan->processor_plugin = '';
  $plan->processor_config = array();
  $plan->endpoints = array();
  $export['crm_core_demo_sample_content'] = $plan;

  return $export;
}
