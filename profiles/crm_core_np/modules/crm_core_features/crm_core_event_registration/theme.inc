<?php

/**
 * @file
 * Custom preprocess callbacks for event registration.
 */
DEFINE('DEFAULT_CURRENCY', 'USD');

/**
 * Custom preprocess callback for event registration reports.
 */
function crm_core_event_registration_reports_preprocess(&$vars) {
  if (empty($vars['rows'])) {
    // get rid of csv export when the view is empty
    $vars['feed_icon'] = FALSE;
  }
}


/**
 * Custom preprocess callback for event revenue block
 */
function crm_core_event_registration_reports_revenue_preprocess(&$vars) {
  module_load_include('inc', 'crm_core_event_registration', 'simple_html_dom');
  
  if (!empty($vars['rows'])) {
    $html = str_get_html($vars['rows']);
    $results = $html->find('div[class=field-content]');
    if (!empty($results)) {
      foreach ($results as $result) {
        $revenue[] = $result->plaintext;  
      }  
    }
    
    // let's add up our revenue and format it
    if (!empty($revenue)) {
      $sum = array_sum($revenue);
      $sum = commerce_currency_format($sum, DEFAULT_CURRENCY);
    }
    
    if (isset($sum)) {
      $vars['sum'] = $sum;  
    }    
  }  
}