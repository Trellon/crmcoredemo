<?php

/**
 * Interface for all deploy aggregators.
 */
interface DeployAggregator extends IteratorAggregate {

  /**
   * Constructor for a deploy aggregator.
   *
   * @param DeployPlan $plan
   *   The plan that will use this aggregator.
   *
   * @param array $config
   *   An associative array representing the configuration settings for the
   *   aggregator.
   */
  public function __construct(DeployPlan $plan = NULL, Array $config = array());

  /**
   * Returns an iterator with entities for deployment.
   *
   * Since we are dealing with resursive iteration (entities with references),
   * we need to run DeployIterator through DeployIteratorIterator and return the
   * latter one.
   *
   * @return DeployIteratorIterator
   *
   * @see http://giorgiosironi.blogspot.com/2010/02/practical-php-patterns-iterator.html
   */
  //function getIterator();

  /**
   * Defines the configuration form for the aggregator.
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
 * Base class implementing the DeployAggregator interface. All aggregator plugins
 * should extend this class.
 */
class DeployAggregatorBase implements DeployAggregator {

  /**
   * Constructor for a deploy aggregator.
   *
   * @param DeployPlan $plan
   *   The plan that will use this aggregator.
   *
   * @param array $config
   *   An associative array representing the configuration settings for the
   *   aggregator.
   */
  public function __construct(DeployPlan $plan = NULL, Array $config = array()) {}

  /**
   * Defines the configuration form for the aggregator.
   *
   * @param array $form_state
   *   The complete form state.
   *
   * @return array
   *   An array representing the configuation form.
   */
  public function configForm(&$form_state) {}

  /**
   * Returns an array of entities.
   *
   * @return array()
   *   An array of entities structured as follows:
   *   @code
   *     $entities = array(
   *       'node' => array(
   *         10 => TRUE,
   *         12 => array(
   *           'taxonomy_term' => array(
   *             14 => TRUE,
   *           ),
   *           'user' => array(
   *             8 => TRUE,
   *           ),
   *         ),
   *       ),
   *       'taxonomy_term' => array(
   *         16 => TRUE,
   *       ),
   *     );
   *   @endcode
   */
  public function getEntities() {}

  /**
   * Returns a DeployIteratorIterator, which can iterate through recursive
   * iterators
   *
   * @return DeployIteratorIterator
   */
  public function getIterator() {
    $entities = $this->getEntities();
    return deploy_iterator($entities);
  }
}
