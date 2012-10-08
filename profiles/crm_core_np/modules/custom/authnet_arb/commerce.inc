<?php
/*
 * Integration with a commerce framework
 */

function authnet_arb_commerce_settings_pane ($settings = NULL) {

  $arb_settings = NULL;
  if (!empty($settings)) {
    $arb_settings = array(
      'login' => $settings['settings']['authnet_arb_login_id'],
      'tran_key' => $settings['settings']['authnet_arb_tran_key'],
      'sandbox' => $settings['settings']['authnet_arb_sandbox'],
      'md5_hash' => $settings['settings']['authnet_arb_md5_hash'],
      'watchdog_all' => $settings['settings']['authnet_arb_debugging_watchdog_all'],
    );  
  }
  
  $form = authnet_arb_settings_pane($arb_settings, TRUE);

  drupal_set_message(t('You may change ARB payment settings on !page page',
    array('!page' => l(t('ARB settings'), 'admin/config/authnet-arb'))),'warning');

  return $form;
}

/**
 * Payment method callback: submit form.
 */
function authet_arb_payment_pane($payment_method, $pane_values, $checkout_pane, $order) {
  $form = array();
  module_load_include('inc', 'commerce_payment', 'includes/commerce_payment.credit_card');
  $credit_card = commerce_payment_credit_card_form(array('code' => ''));
  $form['credit_card'] = $credit_card['credit_card'];
  $recurring = array();
  // allow hooks to alter the pane,
  //   usefull if you want to set payments period and step based on product or any other order data
  $recurring = module_invoke_all('authet_arb_commerce_set_recurring', $order);
  $form['recurring_options'] = authnet_arb_recurring_info_pane($recurring);
  return $form;
}

/**
 * Payment method callback: submit form validation.
 */
function authet_arb_payment_pane_validate($payment_method, $pane_form, $pane_values, $order, $form_parents = array()) {

  $valid = TRUE;

  // validate the credit card fields
  module_load_include('inc', 'commerce_payment', 'includes/commerce_payment.credit_card');
  $settings = array(
    'form_parents' => array_merge($form_parents, array('credit_card')),
  );
  if (!commerce_payment_credit_card_validate($pane_values['credit_card'], $settings)) {
    $valid = FALSE;
  }

  // validating recurring settings
  if(authnet_arb_recurring_info_pane_validation($pane_values['recurring_options'], $form_parents) === FALSE) {
    $valid = FALSE;
  }

  
  if ($valid === FALSE) {
    return FALSE;
  }

  // validate card processing
  $charge = commerce_payment_order_balance($order);
  // if the line items was not added yet, set amout to $0.01
  if (empty($charge['amount'])) {
    $charge['amount'] = '1';
  }
  if(!authnet_arb_verify_payment($charge, $pane_values['credit_card'])) {
    $prefix = implode('][', $form_parents) . '][';
    form_set_error($prefix, 'The card can\' be autorized.');
    $valid =  FALSE;
  }

  return $valid;
}

/**
 * Payment method callback: submit form submission.
 */
function authet_arb_payment_pane_submit($payment_method, $pane_form, $pane_values, &$order, $charge) {
  return authnet_arb_create_subscription ($pane_values['recurring_options'], $charge, $pane_values['credit_card'],
    array(), $order);
}
