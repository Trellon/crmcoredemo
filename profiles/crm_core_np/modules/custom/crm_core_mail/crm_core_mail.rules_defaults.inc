<?php

/**
 * @file
 * Default Rules configuration.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crm_core_mail_default_rules_configuration() {
  $rules = array();

  $rule_config = '
    { "crm_core_mail_send_to_contact" : {
        "LABEL" : "Send email to the contact",
        "PLUGIN" : "action set",
        "TAGS" : [ "CRM Core" ],
        "REQUIRES" : [ "crm_core_mail" ],
        "USES VARIABLES" : {
          "contact" : { "label" : "Contact", "type" : "crm_core_contact" },
          "subject" : { "label" : "Subject", "type" : "text" },
          "message" : { "label" : "Message", "type" : "text" }
        },
        "ACTION SET" : [
          {
            "send_to_contact" : {
              "contact" : [ "contact" ],
              "subject" : [ "subject" ],
              "message" : [ "message" ]
            }
          }
        ]
      }
    }';

  $rules['crm_core_mail_send'] = rules_import($rule_config);

  return $rules;
}

