<?php

/**
 * @file
 * Default Rules configuration for CRM Core Email Contact
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crm_core_mail_default_rules_configuration() {
  $rules = array();

  $rule_config = '
    { "crm_core_mail_send" : {
        "LABEL" : "Send email to CRM Core Contact",
        "PLUGIN" : "action set",
        "REQUIRES" : [ "crm_core_mail" ],
        "USES VARIABLES" : {
          "contact" : { "label" : "Contact", "type" : "crm_core_contact" },
          "subject" : { "label" : "Subject", "type" : "text" },
          "from" : { "label" : "From", "type" : "text" },
          "to" : { "label" : "To", "type" : "text" },
          "message" : { "label" : "Message", "type" : "text_formatted" }
        },
        "ACTION SET" : [
          { "filtered_mail" : {
              "to" : [ "to" ],
              "subject" : [ "subject" ],
              "message" : [ "message" ],
              "from" : [ "from" ],
              "language" : [ "" ]
            }
          }
        ]
      }
    }';

  $rules['crm_core_mail_send'] = rules_import($rule_config);

  return $rules;
}
