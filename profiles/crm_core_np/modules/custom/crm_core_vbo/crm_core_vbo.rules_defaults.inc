<?php
/**
 * @file
 * crm_core_vbo.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crm_core_vbo_default_rules_configuration() {
  $items = array();
  $items['rules_delete_activity'] = entity_import('rules_config', '{ "rules_delete_activity" : {
      "LABEL" : "Delete Activity",
      "PLUGIN" : "action set",
      "TAGS" : [ "CRM Core Activity" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "crm_core_activity" : { "label" : "Activity", "type" : "crm_core_activity" } },
      "ACTION SET" : [ { "entity_delete" : { "data" : [ "crm-core-activity" ] } } ]
    }
  }');
  $items['rules_delete_contact'] = entity_import('rules_config', '{ "rules_delete_contact" : {
      "LABEL" : "Delete Contact",
      "PLUGIN" : "action set",
      "TAGS" : [ "CRM Core" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "crm_core_contact" : { "label" : "Contact", "type" : "crm_core_contact" } },
      "ACTION SET" : [ { "entity_delete" : { "data" : [ "crm-core-contact" ] } } ]
    }
  }');
  return $items;
}
