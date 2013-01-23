<?php

$plugin = array(
  'schema' => 'deploy_endpoints',
  'access' => 'administer deployments',

  'menu' => array(
    'menu prefix' => 'admin/structure/deploy',
    'menu item' => 'endpoints',
    'menu title' => 'Endpoints',
  ),

  'title singular' => t('endpoint'),
  'title singular proper' => t('Endpoint'),
  'title plural' => t('endpoints'),
  'title plural proper' => t('Endpoints'),

  'use wizard' => TRUE,

  'handler' => array(
    'class' => 'deploy_ui_endpoint',
    'parent' => 'ctools_export_ui',
  ),

  'form info' => array(
    'order' => array(
      'basic' => t('Basics'),
      'authenticator' => t('Authenticator'),
      'service' => t('Service'),
    ),
  ),
);
