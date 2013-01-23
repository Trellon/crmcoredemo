<?php
/**
 * @file
 *   Deploy module web services functions.
 */

/**
 * Implements hook_services_resources.
 */
function deploy_services_resources() {
  $resources = array('deploy' => array());

  $resources['deploy']['index'] = array(
    'help' => t('This method returns a list of deployment plans'),
    'callback' => 'deploy_services_index',
    'file' => array('type' => 'inc', 'module' => 'deploy', 'name' => 'deploy.services'),
    // TODO add support for args
    'args' => array(),
    'access arguments' => array('administer deployments'),
  );

  $resources['deploy']['create'] = array(
    'help' => t('Creates a deployment plan'),
    'callback' => 'deploy_services_create',
    'file' => array('type' => 'inc', 'module' => 'deploy', 'name' => 'deploy.services'),
    'args' => array(
      array(
        'name' => 'data',
        'type' => 'struct',
        'description' => 'The plan object',
        'source' => 'data',
        'optional' => FALSE,
      ),
    ),
    'access arguments' => array('administer deployments'),
  );

  $resources['deploy']['retrieve'] = array(
    'file' => array('type' => 'inc', 'module' => 'deploy', 'name' => 'deploy.services'),
    'help' => t('Retrieve a deployment plan'),
    'callback' => 'deploy_services_retrieve',
    'args' => array(
      array(
        'name' => 'name',
        'type' => 'string',
        'description' => 'The name of the plan to fetch',
        'source' => array('path' => '0'),
        'optional' => FALSE,
      ),
    ),
    'access arguments' => array('administer deployments'),
  );

  $resources['deploy']['update'] = array(
    'callback' => 'deploy_services_update', 
    'file' => array('type' => 'inc', 'module' => 'deploy', 'name' => 'deploy.services'),
    'args' => array(
      array(
        'name' => 'name', 
        'optional' => FALSE, 
        'source' => array('path' => 0), 
        'description' => 'The name of the deployment plan.', 
        'type' => 'int',
      ),
      array(
        'name' => 'config', 
        'optional' => FALSE, 
        'source' => 'data', 
        'description' => 'The configuration for the deployment plan.', 
        'type' => 'array',
      ),
    ),
    'access arguments' => array('administer deployments'),
  );

  $resources['deploy']['targeted_actions'] = array();
  $resources['deploy']['targeted_actions']['deploy'] = array(
    'help' => t('This method deploys a deployment plan.'),
    'callback' => 'deploy_services_deploy',
    'file' => array('type' => 'inc', 'module' => 'deploy', 'name' => 'deploy.services'),
    'args' => array(
      array(
        'name' => 'name',
        'type' => 'string',
        'description' => 'The name of the plan to fetch',
        'source' => array('path' => '0'),
        'optional' => FALSE,
      ),
    ),
    'access arguments' => array('administer deployments'),
  );

  return $resources;
}

/**
 * services create operation callback.
 */
function deploy_services_create($data) {
  $plan = deploy_plan_save($data);

  return array(
    'pid' => $plan->pid,
    'name' => $plan->name,
    'uri' => services_resource_uri(array('deploy', $plan->name)),
  );
}

/**
 * services create operation callback.
 */
function deploy_services_update($name, $data) {
  $data['name'] = $name;
  $plan = deploy_plan_save($data);

  return array(
    'pid' => $plan->pid,
    'name' => $plan->name,
    'uri' => services_resource_uri(array('deploy', $plan->name)),
  );
}

/**
 * Services deploy action callback.
 *
 * @param $name
 *   The name of the plan to retrieve.
 *
 * @return
 *   TRUE on success, Exception on error or FALSE if the plan is not found.
 */
function deploy_services_deploy($name) {
  $plan = deploy_plan_load($name);
  if (!$plan) {
    return services_error(t('Not Found'), 404, t("Plan '@plan' not found", array('@plan' => $plan)));
  }

  try {
    $plan->deploy();
  } catch (Exception $e) {
    return services_error(t('Internal Server Error'), 500, $e->getMessage());
  }
  return TRUE;
}

/**
 * Services index operation callback.
 *
 * @return
 *   A list of available deployment plans.
 */
function deploy_services_index() {
  return deploy_plan_load_all();
}

/**
 * Services retrieve operation callback.
 *
 * @param $name
 *   The name of the plan to retrieve.
 *
 * @return
 *  The deployment plan object or FALSE if not found.
 */
function deploy_services_retrieve($name) {
  $plan = deploy_plan_load($name);

  if (is_object($plan)) {
    unset($plan->aggregator->plan);
    unset($plan->processor->plan);
  }

  return $plan;
}

