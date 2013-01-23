<?php

/**
 * Interface for all deploy service plugins.
 */
interface DeployService {

  /**
   * Constructor for a deploy service.
   *
   * @param array $config
   *   An associative array containing the settings for the service plugin.
   */
  public function __construct(Array $config = array());

  /**
   * Deploy all entities in the $iterator. This method should only move entities
   * over to the endpoint and create unpublished revisions (if supported). The
   * 'publish' method is responsible for publishing all successfully deployed
   * entities.
   *
   * @param Traverable $iterator
   *   This will usually be an object of a subclass of DeployAggregatorBase
   * @see DeployService::publish().
   */
  public function deploy(Traversable $iterator);

  /**
   * Publish all entities in the $iterator. This method should only publish
   * entities on the endpoint (if supported). The 'deploy' method is
   * responsible for moving the entities to the endpoint, prior to the
   * publishing.
   *
   * @param Traverable $iterator
   *   This will usually be an object of a subclass of DeployAggregatorBase
   * @see DeployService::deploy().
   */
  public function publish(Traversable $iterator);

  /**
   * Configuration form.
   *
   * @param array $form_state
   *   The complete form state.
   */
  public function configForm(&$form_state);

}

/**
 * Exception thrown when a service fails.
 */
class DeployServiceException extends Exception {}
