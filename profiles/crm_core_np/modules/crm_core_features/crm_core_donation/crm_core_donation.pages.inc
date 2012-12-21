<?php

/**
 * Form builder for the donation page creation form
 *
 * @params
 *
 * (array) $donation_page - an array of existing donation page details
 * (bool) $pdp - Personal donation page
 *               If specified, only certain options are available on personal donation page creation
 */
function crm_core_donation_page_form($form, &$form_state, $donation_page_id = NULL, $pdp = FALSE) {
  global $user;
  $donation_page = array();
  if (isset($donation_page_id)) {
    $donation_page = crm_core_donation_page_load($donation_page_id);
  }

  $donation_profile = variable_get('crm_core_donation_profile', '');
  if ($donation_profile == '') {
    $form['message'] = array(
      '#prefix' => '<div class="messages warning">',
      '#suffix' => '</div>',
      '#markup' => 'You have not set up a CRM Core Profile for donation, please do so ' . l(t('here'), 'admin/crm/donation/config') . ' before you can create additional donation pages.'
    );

    return $form;
  }

  $form['options'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
  );

  if (!empty($donation_page)) {
    $form['options']['id'] = array(
      '#type' => 'value',
      '#value' => $donation_page['id'],
    );
  }

  if (empty($donation_page)) {
    $form['options']['created'] = array(
      '#type' => 'value',
      '#value' => time(),
    );
  }

  if ($pdp) {
    $form['options']['pdp'] = array(
      '#type' => 'value',
      '#value' => 1,
    );
  }

  $form['options']['name'] = array(
    '#type' => 'value',
    '#value' => $donation_profile,
  );

  $form['options']['uid'] = array(
    '#type' => 'value',
    '#value' => (!empty($donation_page)) ? $donation_page['uid'] : $user->uid,
  );

  $form['options']['title'] = array(
    '#type' => 'textfield',
    '#title' => 'Title',
    '#description' => t('The donation page title'),
    '#default_value' => (!empty($donation_page)) ? $donation_page['title'] : 'Donate Today',
    '#required' => TRUE,
  );

  $form['options']['data'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
  );

  // payment methods
  if (!$pdp) {
    $options = array('' => t('--select--'));
    $options += crm_core_donation_payment_method_instances();
    $default_value = array();
    if (!empty($donation_page)) {
      $donation_page['data'] = unserialize($donation_page['data']);
      if (array_key_exists('data', $donation_page)) {
        if (isset($donation_page['data']['payment_method'])) {
          $default_value = $donation_page['data']['payment_method'];
        }
      }
    }

    $form['options']['data']['payment_method'] = array(
      '#title' => 'Payment method',
      '#description' => t('Choose the default payment methods available for this donation page'),
      '#type' => 'select',
      '#multiple' => FALSE,
      '#options' => $options,
      '#default_value' => $default_value,
    );
  }

  $form['options']['status'] = array(
    '#type' => 'checkbox',
    '#title' => 'Active',
    '#default_value' => (!empty($donation_page)) ? $donation_page['status'] : 1,
  );

//  $form['options']['amounts'] = array(
//    '#type' => 'textarea',
//    '#title' => 'Amounts',
//    '#description' => t('Please enter the donation amount options, each options should be on a separate line'),
//    '#default_value' => (!empty($donation_page)) ? unserialize($donation_page['amounts']) : '',
//  );

  $header_default = (!empty($donation_page)) ? unserialize($donation_page['header']) : array();
  $form['options']['header'] = array(
    '#type' => 'text_format',
    '#title' => 'Donation page header',
    '#description' => t('The content that will display on the top of the donation page'),
    '#default_value' => (!empty($header_default)) ? $header_default['value'] : '',
    '#format' => (!empty($header_default)) ? $header_default['format'] : filter_default_format(),
    '#rows' => 2,
  );

  $footer_default = (!empty($donation_page)) ? unserialize($donation_page['footer']) : array();
  $form['options']['footer'] = array(
    '#type' => 'text_format',
    '#title' => 'Donation page footer',
    '#description' => t('The content that will display on the bottom of the donation page'),
    '#default_value' => (!empty($footer_default)) ? $footer_default['value'] : '',
    '#format' => (!empty($footer_default)) ? $footer_default['format'] : filter_default_format(),
    '#rows' => 2,
  );

  if (!empty($donation_page)) {
    $form['options']['path'] = array(
      '#type' => 'textfield',
      '#title' => 'Path',
      '#description' => t('Specify a url alias (path) for this donation page'),
      '#default_value' => (!empty($donation_page)) ? $donation_page['path'] : '',
    );
  }

  if (!$pdp) {
    $form['options']['redirect'] = array(
      '#type' => 'textfield',
      '#title' => 'Redirect',
      '#description' => t('The redirect path after a successful donation'),
      '#default_value' => (!empty($donation_page)) ? $donation_page['redirect'] : '',
    );
  }

  $form['options']['goal'] = array(
    '#type' => 'textfield',
    '#title' => 'Goal',
    '#description' => t('The goal of this campaign, 0 means no goal'),
    '#default_value' => (!empty($donation_page)) ? $donation_page['goal'] : 0,
  );

  $widget_setting = (!empty($donation_page)) ? $donation_page['widget'] : 0;
  $form['options']['widget'] = array(
    '#type' => 'checkbox',
    '#title' => 'Donation page widget',
    '#description' => t('Include a donation thermometer widget'),
    '#default_value' => $widget_setting,
  );

  if ((bool) $widget_setting) {
    $form['widget'] = array(
      '#title' => 'widget',
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    global $base_url;
    $href = $base_url . '/donation_widgets/' . $donation_page['id'];
    $markup = '<iframe width="300" height="300" src="' . $href . '"></iframe>';

    $form['widget']['embed'] = array(
      '#type' => 'textarea',
      '#default_value' => $markup,
      '#title' => 'Embed code',
      '#rows' => 1,
    );
    $form['widget']['preview'] = array(
      '#markup' => $markup,
    );
  }

  // @add start/end campaign?


  // hide fields that are not accessible to PDP settings

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => (!empty($donation_page)) ? t('Save') : t('Create'),
  );

  $form['cancel'] = array(
    '#markup' => ($pdp) ? l(t('Cancel'), 'user') : l(t('Cancel'), 'crm/donations'),
  );

  return $form;
}

/**
 * Validation callback
 */
function crm_core_donation_page_form_validate($form, &$form_state) {
	
	// work around for automatic line break for header and footer
	$form_state['values']['options']['header']['value'] = _filter_autop($form_state['values']['options']['header']['value']);
	$form_state['values']['options']['footer']['value'] = _filter_autop($form_state['values']['options']['footer']['value']);

  // @todo: validate the amount entered and make sure no symboles, etc
  if (isset($form_state['values']['options']['goal']) && $form_state['values']['options']['goal'] != '') {
    if (!is_numeric($form_state['values']['options']['goal'])) {
      form_set_error('goal', 'Goal must be an integer number');
    }
  }

  if (isset($form_state['values']['options']['path']) && $form_state['values']['options']['path'] != '') {
    // check machien name compitability
    $match = strcspn($form_state['values']['options']['path'], 'abcdefghijklmnopqrstuvwxyz0123456789-_');
    if ($match > 0) {
      form_set_error('path', 'The path must only container lower case alphabets, numbers, dash (-) and underscore (_)');
    }
    // check if the path alias exist
    $path = drupal_lookup_path('source', $form_state['values']['options']['path']);
    if (!empty($path)) {
      if ($path !== 'donation_pages/' . $form_state['values']['options']['id']) {
        form_set_error('path', 'the url alias already exist');
      }
    }
  }
}

/**
 * Submission callback
 */
function crm_core_donation_page_form_submit($form, &$form_state) {
  // save the path alias
  if (isset($form_state['values']['options']['path']) && $form_state['values']['options']['path'] != '') {
    $loaded_path = path_load('donation_pages/' . $form_state['values']['options']['id']);
    $path = array(
      'source' => 'donation_pages/' . $form_state['values']['options']['id'],
      'alias' => $form_state['values']['options']['path'],
    );

    if ($loaded_path) {
      $path['pid'] = $loaded_path['pid'];
    }
    path_save($path);
  }

  crm_core_donation_page_save($form_state['values']['options']);

  if (isset($form_state['values']['options']['pdp'])) {
    $form_state['redirect'] = 'user';
  }
  else {
    $form_state['redirect'] = 'crm/donations';
  }

  drupal_set_message(t('The donation page has been saved'));
}

/**
 * Delete a donation page
 */
function crm_core_donation_page_delete_form($form, &$form_state, $donation_page_id) {
  // @todo: think about the donations made from this page, etc
  $form = array();
  $form['id'] = array(
    '#type' => 'value',
    '#value' => $donation_page_id,
  );

  $question = t('Are you sure you want to delete the donation page?');
  $path = 'crm/donations';

  return confirm_form($form, $question, $path);
}

/**
 * Deletion submission handler
 */
function crm_core_donation_page_delete_form_submit($form, &$form_state) {
  crm_core_donation_page_delete($form_state['values']['id']);
  $form_state['redirect'] = 'crm/donations';
  drupal_set_message(t('The donation page has been deleted'));
}

/**
 * Return available payment method instances available
 */
function crm_core_donation_payment_method_instances() {

  $data = array();

  $order = new stdClass();
  $order->type = 'commerce_order';
  $order->payment_methods = array();
  $order->order_id = NULL;
  $order->order_number = NULL;
  $order->is_new = TRUE;
  $order->data['crm_core_donation']['donation_page']['id'] = NULL;
  rules_invoke_all('commerce_payment_methods', $order);

  foreach ($order->payment_methods as $instance_id => $instance) {
    $payment_method = commerce_payment_method_load($instance['method_id']);
    $data[$instance_id] = $payment_method['short_title'];
  }

  return $data;
}

/**
 * Return fields that are accessible by PDP settings
 */
function crm_core_donation_pdp_fields() {
  return array(
    'title',
    'header',
    'footer',
    'status',
  );
}

/**
 * @file
 * Code for the CRM Core Donation pages.
 */
/**
 * Load a donation page
 *
 * @params
 * (int) $id    the donation apge id
 *
 * @return
 * (array) $donation_page    the donation page array
 */
function crm_core_donation_page_load($id) {
  $data = array();
  $query = db_select('crm_core_donation_page', 'p')
    ->fields('p')
    ->condition('id', $id);

  $result = $query->execute();
  $data = $result->fetchAssoc();

  return $data;
}

/**
 * Save a donation page
 *
 * @params
 * (array) $donation_page    the donation page array
 *
 */
function crm_core_donation_page_save($donation_page) {
  if (array_key_exists('id', $donation_page )) {
    $res = drupal_write_record('crm_core_donation_page', $donation_page, 'id');
  }
  else {
    $res = drupal_write_record('crm_core_donation_page', $donation_page);
  }

  return $res;
}

/**
 * Delete a donation page
 *
 * @params
 * (int) $id    the donation apge id
 *
 */
function crm_core_donation_page_delete($id) {
  db_delete('crm_core_donation_page')
  ->condition('id', $id)
  ->execute();
}
