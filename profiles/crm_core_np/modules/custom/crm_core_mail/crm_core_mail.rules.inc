<?php

/**
 * @file Implements Rules API to introduce new action for sending mail with formatted message body.
 */

/**
 * Implements hook_rules_action_info().
 */
function crm_core_mail_rules_action_info() {
  return array(
    'filtered_mail' => array(
      'label' => t('Send filtered mail'),
      'group' => t('CRM Core'),
      'parameter' => array(
        'to' => array(
          'type' => 'text',
          'label' => t('To'),
          'description' => t('The e-mail address or addresses where the message will be sent to. The formatting of this string must comply with RFC 2822.'),
        ),
        'subject' => array(
          'type' => 'text',
          'label' => t('Subject'),
          'description' => t("The e-mail subject."),
          'translatable' => TRUE,
        ),
        'message' => array(
          'type' => 'text_formatted',
          'label' => t('Message'),
          'description' => t("The e-mail message body."),
          'translatable' => TRUE,
        ),
        'from' => array(
          'type' => 'text',
          'label' => t('From'),
          'description' => t("The e-mail from address. Leave it empty to use the site-wide configured address."),
          'optional' => TRUE,
        ),
        'language' => array(
          'type' => 'token',
          'label' => t('Language'),
          'description' => t('If specified, the language used for getting the mail message and subject.'),
          'options list' => 'entity_metadata_language_list',
          'optional' => TRUE,
          'default value' => LANGUAGE_NONE,
          'default mode' => 'selector',
        ),
      ),
      'base' => 'crm_core_mail_send',
    ),
  );
}

/**
 * Callback for rules action 'filtered_mail'.
 */
function crm_core_mail_send($to, $subject, $message, $from = NULL, $langcode, $settings, RulesState $state, RulesPlugin $element) {
  $to = str_replace(array("\r", "\n"), '', $to);
  $from = !empty($from) ? str_replace(array("\r", "\n"), '', $from) : NULL;
  $params = array(
    'subject' => $subject,
    'message' => $message,
    'langcode' => $langcode,
  );

  // Set a unique key for this mail.
  $name = isset($element->root()->name) ? $element->root()->name : 'unnamed';
  $key = 'crm_rules_action_mail_' . $name . '_' . $element->elementId();
  $languages = language_list();
  $language = $langcode == LANGUAGE_NONE ? language_default() : $languages[$langcode];

  // Validate mail of recipient
  if (valid_email_address($to)) {
    $message = drupal_mail('crm_core_mail', $key, $to, $language, $params, $from);
    if ($message['result']) {
      watchdog('rules', 'Successfully sent email to %recipient', array('%recipient' => $to));
    }
  }
  else {
    watchdog('rules', 'Mail was not sent because of not valid email of the recipient: %recipient', array('%recipient' => $to));
  }
}
