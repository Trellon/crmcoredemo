<?php

/**
 * Class for basic memory-based processing
 */
class DeployProcessorMemory implements DeployProcessor {

  /**
   * The aggregator containing the entities to be processed.
   *
   * @var DeployAggregator
   */
  public $aggregator = NULL;

  /**
   * Configuration options.
   *
   * @var array
   */
  public $config = array();

  public function __construct(DeployAggregator $aggregator, Array $config = array()) {
    $this->aggregator = $aggregator;
    $this->config += array(
      'debug' => FALSE,
    );
    $this->config = array_merge($this->config, $config);
  }

  protected function processOperations(Array $operations = array()) {
    if (!empty($operations)) {
      foreach ($this->aggregator as $entity) {
        foreach ($operations as $operation) {
          $operation['callback']($this->aggregator->plan->name, $entity);
        }
      }
    }
  }

  public function preProcess(Array $operations = array()) {
    $this->processOperations($operations);
  }

  public function deploy($deployment_key, DeployEndpoint $endpoint, $lock_name = NULL) {
    $endpoint->deploy($deployment_key, $this->aggregator, $lock_name);
  }

  public function publish($deployment_key, DeployEndpoint $endpoint, $lock_name = NULL) {
    $endpoint->publish($deployment_key, $this->aggregator, $lock_name);
    drupal_set_message(t('Plan %plan has been deployed and published to %endpoint.', array('%plan' => $this->aggregator->plan->title, '%endpoint' => $endpoint->title)));
  }

  public function postProcess(Array $operations = array()) {
    $this->processOperations($operations);
  }

  public function configForm(&$form_state) {
    // We have no settings for this processor.
    return array();
  }
}
