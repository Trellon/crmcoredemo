<?php

/**
 * Class for a deploy aggregator that aggregates entities using a View.
 */
class DeployAggregatorViews extends DeployAggregatorBase {

  public $config = array();

  /**
   * Holds a reference to the plan object that initiated it.
   *
   * @var DeployPlan
   */
  public $plan;

  public function __construct(DeployPlan $plan = NULL, Array $config = array()) {
    $defaults = array(
      'debug' => FALSE,
      'view_name' => '',
    );
    $this->config = array_merge($defaults, $config);
    $this->plan = $plan;
  }

  /**
   * Get aggregated entities.
   */
  public function getEntities() {
    $view = views_get_view($this->config['view_name'], 'default');
    $table_data = views_fetch_data($view->base_table);
    $entity_type = $table_data['table']['entity type'];
    $entity_id_field = $table_data['table']['base']['field'];

    $view_results = views_get_view_result($view->name, 'default');
    $entities = array();
    foreach ($view_results as $view_result) {
      $entities[] = array('type' => $entity_type, 'id' => $view_result->{$entity_id_field});
    }
    return $entities;
  }

  public function configForm(&$form_state) {
    $form = array();
    $options = array();
    $views = views_get_enabled_views();

    foreach ($views as $view_name => $view) {
      $options[$view_name] = !empty($view->human_name) ? $view->human_name : $view->name;
    }

    $form['view_name'] = array(
      '#type' => 'select',
      '#title' => t('View'),
      '#description' => t('Select the view that is going to provide this deployment plan with content.'),
      '#options' => $options,
      '#default_value' => $this->config['view_name'],
    );

    return $form;
  }

}
