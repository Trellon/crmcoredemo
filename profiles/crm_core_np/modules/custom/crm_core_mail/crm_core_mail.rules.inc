<?php

/**
 * @file Implements Rules API. Introduces new action for sending mail to CRM Core Contact.
 */

/**
 * Implements hook_rules_action_info().
 */
function crm_core_mail_rules_action_info() {
  return array(
    'send_to_contact' => array(
      'label' => t('Send e-mail to the CRM Contact'),
      'group' => t('CRM Core'),
      'parameter' => array(
        'contact' => array(
          'type' => 'crm_core_contact',
          'label' => t('CRM Core Contact'),
          'description' => t('CRM Core Contact to send the e-mail.'),
        ),
        'subject' => array(
          'type' => 'text',
          'label' => t('Subject'),
          'description' => t("The e-mail subject."),
          'translatable' => TRUE,
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t("The e-mail message body."),
          'translatable' => TRUE,
        ),
      ),
      'base' => 'crm_core_mail_send_to_contact',
    ),
  );
}

/**
 * Callback for rules action 'filtered_mail'.
 */
function crm_core_mail_send_to_contact($contact, $subject, $message, $settings, RulesState $state, RulesPlugin $element) {
  // TODO: deal with language correctly (current lang, fields, tokenes, etc...)
  $langcode = LANGUAGE_NONE;
  
  $to = '';

  if (!empty($contact->field_contact_email[$langcode][0]['email'])) {
    // TODO: get email field from config
    $to = str_replace(array("\r", "\n"), '', $contact->field_contact_email[$langcode][0]['email']);
  }

  // Validate mail of recipient.
  if (!valid_email_address($to)) {
    watchdog('crm_core_mail', 'Mail was not sent because of not valid email of the recipient: %recipient', array('%recipient' => crm_core_contact_title($contact)));
    return;
  }

  // TODO: get from mail from config 
  $from = variable_get('site_mail', '');

  $params = array(
    'subject' => $subject,
    'body' => $message
  );

  // Set a unique key for this mail.
  $name = isset($element->root()->name) ? $element->root()->name : 'unnamed';
  $key = 'crm_core_mail_' . $name . '_' . $element->elementId();

  $message = drupal_mail('crm_core_mail', $key, $to, language_default(), $params, $from);

  if ($message['result']) {
    watchdog('crm_core_mail', 'Successfully sent email to %recipient', array('%recipient' => crm_core_contact_title($contact)));
  } else {
    watchdog('crm_core_mail', 'Mail was not sent to the %recipient', array('%recipient' => crm_core_contact_title($contact)));  
  }
}

