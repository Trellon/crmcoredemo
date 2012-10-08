<?php

/**
 * @file
 * Implements rules integration.
 */

/*
 * implement hook_rules_condition_info
 */
function crm_core_donation_rules_condition_info() {
  return array(
    'crm_core_donation_order_has_donation_data' => array(
      'label' => t('Commerce order has a donation data'),
      'parameter' => array(
        'commerce_order' => array('label' => t('Commerce Order'), 'type' => 'commerce_order'),
      ),
      'group' => t('Crm Core Donation'),
    ),
  );
}

/*
 * implement crm_core_donation_order_has_donation_data condition callback
 */
function crm_core_donation_order_has_donation_data ($order) {
  return !empty($order->data['crm_core_donation']);
}
