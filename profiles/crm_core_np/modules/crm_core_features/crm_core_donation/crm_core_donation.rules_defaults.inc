<?php
/**
 * @file
 * crm_core_donation.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crm_core_donation_default_rules_configuration() {
  $items = array();
  $items['rules_authorize_net_aim_credit_card_demo_'] = entity_import('rules_config', '{ "rules_authorize_net_aim_credit_card_demo_" : {
      "LABEL" : "Authorize.Net AIM - Credit Card (demo)",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "commerce_payment" ],
      "ON" : [ "commerce_payment_methods" ],
      "DO" : [
        { "commerce_payment_enable_authnet_aim" : {
            "commerce_order" : [ "commerce-order" ],
            "payment_method" : { "value" : {
                "method_id" : "authnet_aim",
                "settings" : {
                  "login" : "8A8xU9eqe",
                  "tran_key" : "2x5m7G9mh34UXC34",
                  "txn_mode" : "developer",
                  "txn_type" : "auth_capture",
                  "email_customer" : 0,
                  "log" : { "request" : 0, "response" : 0 }
                }
              }
            }
          }
        }
      ]
    }
  }');
  return $items;
}
