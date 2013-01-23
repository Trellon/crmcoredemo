<?php

/**
 * @file
 * Deploy's implementation of its own API.
 */

/**
 * Implements hook_deploy_operation_info().
 */
function deploy_deploy_operation_info() {
  return array(
    'postprocess' => array(
      array('callback' => 'deploy_manager_postprocess_operation'),
    ),
  );
}

/**
 * Implements hook_deploy_aggregators().
 */
function deploy_deploy_aggregators() {
  $path = drupal_get_path('module', 'deploy') . '/plugins';
  return array(
    'DeployAggregatorManaged' => array(
      'name' => 'Managed aggregator',
      'description' => 'Provides methods for modules (or users) to manually manage entitites to be aggregated for deployment.',
      'handler' => array(
        'class' => 'DeployAggregatorManaged',
        'file' => 'DeployAggregatorManaged.inc',
        'path' => $path,
      ),
    ),
  );
}

/**
 * Implements hook_deploy_processors().
 */
function deploy_deploy_processors() {
  $path = drupal_get_path('module', 'deploy') . '/plugins';
  return array(
    'DeployProcessorMemory' => array(
      'name' => 'Memory processor',
      'description' => 'All entities are deployed in memory. Works best with small deployments.',
      'handler' => array(
        'class' => 'DeployProcessorMemory',
        'file' => 'DeployProcessorMemory.inc',
        'path' => $path,
      ),
    ),
    'DeployProcessorQueue' => array(
      'name' => 'Queue API',
      'description' => 'All entities are queued for deployment with the Queue API. Works best with large deployments. Can be used with a separate queue worker to achive very fast and parallel deployments.',
      'handler' => array(
        'class' => 'DeployProcessorQueue',
        'file' => 'DeployProcessorQueue.inc',
        'path' => $path,
      ),
    ),
    'DeployProcessorBatch' => array(
      'name' => 'Batch API',
      'description' => 'All entities are processed with the Batch API. Works best when deployments are done through the UI.',
      'handler' => array(
        'class' => 'DeployProcessorBatch',
        'file' => 'DeployProcessorBatch.inc',
        'path' => $path,
      ),
    ),
  );
}

/**
 * Implements hook_deploy_authentications().
 */
function deploy_deploy_authenticators() {
  $path = drupal_get_path('module', 'deploy') . '/plugins';
  return array(
    'DeployAuthenticatorSession' => array(
      'name' => 'Session authentication',
      'description' => 'Performs session authentication on the endpoint. Works well when the endpoint happends to be a Drupal site using Services module and session authentication.',
      'handler' => array(
        'class' => 'DeployAuthenticatorSession',
        'file' => 'DeployAuthenticatorSession.inc',
        'path' => $path,
      ),
    ),
    'DeployAuthenticatorOAuth' => array(
      'name' => 'oAuth',
      'description' => 'Uses the oAuth protocol to authenticate with the endpoint. <strong>Does not work yet!</strong>',
      'handler' => array(
        'class' => 'DeployAuthenticatorOAuth',
        'file' => 'DeployAuthenticatorOAuth.inc',
        'path' => $path,
      ),
    ),
  );
}

/**
 * Implements hook_deploy_services().
 */
function deploy_deploy_services() {
  $path = drupal_get_path('module', 'deploy') . '/plugins';
  return array(
    'DeployServiceRestJSON' => array(
      'name' => 'REST JSON',
      'description' => 'Deploys over a REST service that can receive JSON data. Works well when the endpoint happens to be a Drupal sites using Services module with REST server.',
      'handler' => array(
        'class' => 'DeployServiceRestJSON',
        'file' => 'DeployServiceRestJSON.inc',
        'path' => $path,
      ),
    ),
  );
}
