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
  $items['crm_core_activity_delete'] = entity_import('rules_config', '{ "crm_core_activity_delete" : {
      "LABEL" : "Delete activity",
      "PLUGIN" : "action set",
      "TAGS" : [ "CRM Core" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "crm_core_activity" : { "label" : "Activity", "type" : "crm_core_activity" } },
      "ACTION SET" : [ { "entity_delete" : { "data" : [ "crm-core-activity" ] } } ]
    }
  }');
  $items['crm_core_contact_delete'] = entity_import('rules_config', '{ "crm_core_contact_delete" : {
      "LABEL" : "Delete contact",
      "PLUGIN" : "action set",
      "TAGS" : [ "CRM Core" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "crm_core_contact" : { "label" : "Contact", "type" : "crm_core_contact" } },
      "ACTION SET" : [ { "entity_delete" : { "data" : [ "crm-core-contact" ] } } ]
    }
  }');
  return $items;
}
