<?php
/**
 * @file
 * deploy_example.deploy_plans.inc
 */

/**
 * Implements hook_deploy_plans_default().
 */
function deploy_example_deploy_plans_default() {
  $export = array();

  $plan = new DeployPlan;
  $plan->disabled = FALSE; /* Edit this to true to make a default plan disabled initially */
  $plan->api_version = 1;
  $plan->name = 'deploy_example_plan';
  $plan->title = 'Example plan';
  $plan->description = 'Example plan configured for manual deployments with the managed aggragator. Works well with the UUID Services Example feature on the endpoint site.';
  $plan->debug = 1;
  $plan->aggregator_plugin = 'DeployAggregatorManaged';
  $plan->aggregator_config = array(
    'delete_post_deploy' => 0,
  );
  $plan->fetch_only = 0;
  $plan->processor_plugin = 'DeployProcessorMemory';
  $plan->processor_config = array();
  $plan->endpoints = array(
    'deploy_example_endpoint' => 'deploy_example_endpoint',
  );
  $export['deploy_example_plan'] = $plan;

  return $export;
}
