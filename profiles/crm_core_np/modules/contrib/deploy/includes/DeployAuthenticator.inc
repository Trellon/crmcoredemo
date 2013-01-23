<?php

/**
 * Interface for deploy authenticators.
 */
interface DeployAuthenticator {

  /**
   * Constructor for a deploy authenticator.
   *
   * @param DeployService $service
   *   The service object that we need to authenticate for.
   *
   * @param array $config
   *   An associative array representing the configration options for the
   *   authenticator.
   */
  public function __construct(DeployService $service, Array $config = array());

  /**
   * Initiates an authenticated deployment.
   *
   * @param Traversable $iterator
   *   Usually this will be an object from a subclass of DeployAggregatorBase.
   */
  public function deploy(Traversable $iterator);

  /**
   * Defines the configuration form for the authenticator.
   *
   * @param array $form_state
   *   The complete form state.
   *
   * @return array
   *   An array representing the configuation form.
   */
  public function configForm(&$form_state);

}

/**
 * Exception thrown when authentication fails.
 */
class DeployAuthenticationException extends Exception {}
