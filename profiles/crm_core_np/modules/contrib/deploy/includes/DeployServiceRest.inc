<?php

/**
 * Base class for REST-based service plugins.
 * 
 * This is not a full plugin, but an abstract class that plugins can extend.
 */
class DeployServiceRest implements DeployService {

  /**
   * Configuration options.
   *
   * @var array
   */
  public $config = array();

  /**
   * An associative array of http headers for the REST request.
   *
   * @var array
   */
  public $headers = array();

  /**
   * Constructor for a service plugin.
   *
   * @param array $config
   *   An associative array of configuration settings for the service plugin.
   */
  public function __construct(Array $config = array()) {
    $this->config += array(
      'debug' => FALSE,
      'url' => '',
      'headers' => array(),
    );
    $this->config = array_merge($this->config, $config);
  }

  public function deploy(Traversable $iterator) {}

  public function publish(Traversable $iterator) {}

  /**
   * Makes a HTTP request.
   *
   * @param string $url
   *   The URL to request.
   * @param string $method
   *   The request method to use, like 'POST', 'GET' or 'PUT'.
   * @param string $data
   *   The payload to send with the request.
   */
  public function httpRequest($url, $method, $data = NULL) {
    $options = array(
      'method' => $method,
      'headers' => $this->config['headers'],
      'data' => $data,
    );

    if ($this->config['debug']) {
      watchdog('deploy', 'Service request: %url <pre>@options</pre>', array('%url' => $url, '@options' => print_r($options, TRUE)), WATCHDOG_DEBUG);
    }

    $response = drupal_http_request($url, $options);

    if ($this->config['debug']) {
      watchdog('deploy', 'Service response: <pre>@response</pre>', array('@response' => print_r($response, TRUE)), WATCHDOG_DEBUG);
    }
    if (isset($response->error) || !in_array($response->code, array(200, 304))) {
      throw new DeployServiceException(t('Service error: @code @error', array('@code' => $response->code, '@error' => $response->error)));
    }
  }

  /**
   * Configuration form.
   *
   * @param array $form_state
   *   The complete form state.
   */
  public function configForm(&$form_state) {
    return array(
      'url' => array(
        '#type' => 'textfield',
        '#title' => t('Endpoint URL'),
        '#description' => t('Enter endpoint URL. Example: %url', array('%url' => 'http://example.com/api')),
        '#default_value' => $this->config['url'],
      ),
    );
  }

}
