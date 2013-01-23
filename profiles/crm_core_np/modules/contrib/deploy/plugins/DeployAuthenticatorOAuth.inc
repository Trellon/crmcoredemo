<?php

class DeployAuthenticatorOAuth implements DeployAuthenticator {
  public function __construct(DeployService $service, Array $config = array()) {
    $this->service = $service;
    $this->config += array(
      'debug' => FALSE,
    );
    $this->config = array_merge($this->config, $config);
  }

  public function deploy(Traversable $iterator) {

  }

  public function configForm(&$form_state) {
    return array();
  }
}
