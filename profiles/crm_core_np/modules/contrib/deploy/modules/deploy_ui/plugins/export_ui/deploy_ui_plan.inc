<?php

$plugin = array(
  'schema' => 'deploy_plans',
  'access' => 'administer deployments',

  'menu' => array(
    'menu prefix' => 'admin/structure/deploy',
    'menu item' => 'plans',
    'menu title' => 'Plans',
    'items' => array(
      // TODO: Is there a simpler way to do add this page callback natively as
      // an allowed option in CTools? It's a nightmare to follow for developers.
      'deploy' => array(
        'path' => 'list/%ctools_export_ui/deploy',
        'title' => 'Deploy',
        'page callback' => 'ctools_export_ui_switcher_page',
        'page arguments' => array('deploy_ui_plan', 'deploy', 5),
        'access arguments' => array('administer deployments'),
        'type' => MENU_LOCAL_TASK,
      ),
    ),
  ),

  'title singular' => t('plan'),
  'title singular proper' => t('Plan'),
  'title plural' => t('plans'),
  'title plural proper' => t('Plans'),

  'use wizard' => TRUE,

  'handler' => array(
    'class' => 'deploy_ui_plan',
    'parent' => 'ctools_export_ui',
  ),

  'allowed operations' => array(
    'edit' => array('title' => t('Edit')),
    'deploy' => array('title' => t('Deploy')),
  ),

  'form info' => array(
    'order' => array(
      'basic' => t('Basics'),
      'aggregator' => t('Aggregator'),
      'processor' => t('Processor'),
    ),
  ),
);
