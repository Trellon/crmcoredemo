<?php

class deploy_ui_endpoint extends ctools_export_ui {

  /**
   * Pseudo implementation of hook_menu_alter().
   *
   * @todo
   *   Can we do this in $plugin instead?
   */
  function hook_menu(&$items) {
    parent::hook_menu($items);
    $items['admin/structure/deploy/endpoints']['type'] = MENU_LOCAL_TASK;
  }

  /**
   * Form callback for basic config.
   */
  function edit_form(&$form, &$form_state) {
    $item = $form_state['item'];

    // Basics.
    $form['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => $item->title,
      '#required' => TRUE,
    );
    $form['name'] = array(
      '#type' => 'machine_name',
      '#title' => t('Machine-readable name'),
      '#default_value' => $item->name,
      '#required' => TRUE,
      '#machine_name' => array(
        'exists' => 'deploy_endpoint_load',
        'source' => array('title'),
      ),
    );
    $form['description'] = array(
      '#type' => 'textarea',
      '#title' => t('Description'),
      '#default_value' => $item->description,
    );
    $form['debug'] = array(
      '#type' => 'checkbox',
      '#title' => t('Debug mode'),
      '#description' => t('Check this to enable debug mode with extended watchdog logging.'),
      '#default_value' => $item->debug,
    );

    // Authenticators.
    $authenticators = deploy_get_authenticator_plugins();
    $options = array();
    foreach ($authenticators as $key => $authenticator) {
      $options[$key] = array(
        'name' => $authenticator['name'],
        'description' => $authenticator['description'],
      );
    }
    $form['authenticator_plugin'] = array(
      '#prefix' => '<label>' . t('Authenticator') . '</label>',
      '#type' => 'tableselect',
      '#required' => TRUE,
      '#multiple' => FALSE,
      '#header' => array(
        'name' => t('Name'),
        'description' => t('Description'),
      ),
      '#options' => $options,
      '#default_value' => $item->authenticator_plugin,
    );

    // Services.
    $services = deploy_get_service_plugins();
    $options = array();
    foreach ($services as $key => $service) {
      $options[$key] = array(
        'name' => $service['name'],
        'description' => $service['description'],
      );
    }
    $form['service_plugin'] = array(
      '#prefix' => '<label>' . t('Service') . '</label>',
      '#type' => 'tableselect',
      '#required' => TRUE,
      '#multiple' => FALSE,
      '#header' => array(
        'name' => t('Name'),
        'description' => t('Description'),
      ),
      '#options' => $options,
      '#default_value' => $item->service_plugin,
    );
  }

  /**
   * Submit callback for basic config.
   */
  function edit_form_submit(&$form, &$form_state) {
    $item = $form_state['item'];

    $item->name = $form_state['values']['name'];
    $item->title = $form_state['values']['title'];
    $item->description = $form_state['values']['description'];
    $item->debug = $form_state['values']['debug'];
    $item->authenticator_plugin = $form_state['values']['authenticator_plugin'];
    $item->service_plugin = $form_state['values']['service_plugin'];
  }

  function edit_form_authenticator(&$form, &$form_state) {
    $item = $form_state['item'];
    if (!is_array($item->authenticator_config)) {
      $item->authenticator_config = unserialize($item->authenticator_config);
    }
    $service = new $item->service_plugin((array)$item->service_config);
    // Create the authenticator object.
    $authenticator = new $item->authenticator_plugin($service, (array)$item->authenticator_config);

    $form['authenticator_config'] = $authenticator->configForm($form_state);
    if (!empty($form['authenticator_config'])) {
      $form['authenticator_config']['#tree'] = TRUE;
    }
    else {
      $form['authenticator_config'] = array(
        '#type' => 'markup',
        '#markup' => '<p>' . t('There are no settings for this authenticator plugin.') . '</p>',
      );
    }
  }

  function edit_form_authenticator_submit(&$form, &$form_state) {
    $item = $form_state['item'];
    if (!empty($form_state['values']['authenticator_config'])) {
      $item->authenticator_config = $form_state['values']['authenticator_config'];
    }
    else {
      $item->authenticator_config = array();
    }
  }

  function edit_form_service(&$form, &$form_state) {
    $item = $form_state['item'];
    if (!is_array($item->service_config)) {
      $item->service_config = unserialize($item->service_config);
    }
    $service = new $item->service_plugin((array)$item->service_config);

    $form['service_config'] = $service->configForm($form_state);
    if (!empty($form['service_config'])) {
      $form['service_config']['#tree'] = TRUE;
    }
    else {
      $form['service_config'] = array(
        '#type' => 'markup',
        '#markup' => '<p>' . t('There are no settings for this service plugin.') . '</p>',
      );
    }
  }

  function edit_form_service_submit(&$form, &$form_state) {
    $item = $form_state['item'];
    if (!empty($form_state['values']['service_config'])) {
      $item->service_config = $form_state['values']['service_config'];
    }
    else {
      $item->service_config = array();
    }
  }

}
