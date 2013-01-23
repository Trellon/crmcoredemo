<?php

/**
 * The interface for deployment processors.
 */
interface DeployProcessor {

  /**
   * Constructor for a deploy processor.
   *
   * @param DeployAggregator $aggregator
   *   The aggregator object that will be processed.
   * @param array $config
   *   An associative array of configuration settings for the processor.
   */
  public function __construct(DeployAggregator $aggregator, Array $config = array());

  /**
   * Runs all preprocess operations.
   *
   * @param array $operations
   *   An array of all operations to be run. Each operation contains a
   *   'callback' key with the name of the function to be run. Each function
   *   should take the aggregator as an argument.
   */
  public function preProcess(Array $operations = array());

  /**
   * Main processing method that should hand over the aggregator to the endpoint
   * to deploy all the entities.
   *
   * @param interger $deployment_key
   *   The unique deployment key for this deployment.
   * @param DeployEndpoint $endpoint
   *   The endpoint object to hand over the aggregator to.
   * @param string $lock_name
   *   Optional name of the lock that this deployment is working under.
   */
  public function deploy($deployment_key, DeployEndpoint $endpoint, $lock_name = NULL);

  /**
   * Processing method that should hand over the aggregator to the endpoint
   * to publish all deployed entities. This method will only be called after
   * successful deployments.
   *
   * @param interger $deployment_key
   *   The unique deployment key for this deployment.
   * @param DeployEndpoint $endpoint
   *   The endpoint object to hand over the aggregator to.
   * @param string $lock_name
   *   Optional name of the lock that this deployment is working under.
   */
  public function publish($deployment_key, DeployEndpoint $endpoint, $lock_name = NULL);

  /**
   * Runs all postprocess operations.
   *
   * @param array $operations
   *   An array of all operations to be run. Each operation contains a
   *   'callback' key with the name of the function to be run. Each function
   *   should take the aggregator as an argument.
   */
  public function postProcess(Array $operations = array());

  /**
   * Configuration form.
   *
   * @param array $form_state
   *   The complete form state.
   */
  public function configForm(&$form_state);

}
