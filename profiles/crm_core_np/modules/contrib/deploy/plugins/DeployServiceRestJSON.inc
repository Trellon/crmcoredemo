<?php

/**
 * Class for deploying to a REST server using JSON
 */
class DeployServiceRestJSON extends DeployServiceRest {

  public function deploy(Traversable $iterator) {
    foreach ($iterator as $entity) {
      $json_data = drupal_json_encode($entity);
      $this->config['headers']['Content-Type'] = 'application/json';

      // TODO: Consider making the resource path configurable.
      $url = $this->config['url'] . '/' . $entity->__metadata['uri'] . '.json';
      $this->httpRequest($url, 'PUT', $json_data);
    }
  }

  public function publish(Traversable $iterator) {
    foreach ($iterator as $entity) {
      $this->config['headers']['Content-Type'] = 'application/json';

      // TODO: Consider making the resource path configurable.
      $url = $this->config['url'] . '/' . $entity->__metadata['uri'] . '/publish';
      //$this->httpRequest($url, 'POST');
    }
  }
}
