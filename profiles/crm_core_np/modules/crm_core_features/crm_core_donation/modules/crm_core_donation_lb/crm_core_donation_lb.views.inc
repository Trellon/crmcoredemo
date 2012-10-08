<?php

/**
 * @file
 * Export CRM Core Donation to views.
 */


/**
 * Implements hook_views_data().
 */
function crm_core_donation_lb_views_data() {
  $data = array();

  $data['crm_core_donation_lb']['table']['group'] = t('CRM Donation Leaderboard');
  $data['crm_core_donation_lb']['table']['base'] = array(
    'field' => 'donation_page_id',
    'title' => t('CRM Core Donation Leaderboard'),
    'help' => t('The donation leaderboard'),
  );

  $data['crm_core_donation_lb']['donation_page_id'] = array(
    'title' => t('Donation page ID'),
    'help' => t('The unqiue internal identifier for a donation page'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
   'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'crm_core_donation_page',
      'field' => 'donation_page_id',
      'label' => t('Donation page'),
    ),
  );

  $data['crm_core_donation_lb']['donor_count'] = array(
    'title' => t('Donor Count'),
    'help' => t('Number of donors'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  
  $data['crm_core_donation_lb']['total'] = array(
    'title' => t('Total donation amount'),
    'help' => t('Total donation amount from the donation page'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );  

  $data['crm_core_donation_lb']['last_donation'] = array(
    'title' => t('Last donation date'),
    'help' => t('The date of the last donation'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  
  return $data;
}