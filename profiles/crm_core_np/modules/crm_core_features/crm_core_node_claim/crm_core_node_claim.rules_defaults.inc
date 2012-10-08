<?php
/**
 * @file
 * crm_core_node_claim.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crm_core_node_claim_default_rules_configuration() {
  $items = array();
  $items['rules_node_claim_approval'] = entity_import('rules_config', '{ "rules_node_claim_approval" : {
      "LABEL" : "Node Claim Approval",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "CRM Core", "Node Claim", "Resource Claim" ],
      "REQUIRES" : [ "rules", "crm_core_node_claim" ],
      "ON" : [ "crm_core_node_claim_approve" ],
      "DO" : [
        { "mail" : {
            "to" : "[contact:field-contact-email]",
            "subject" : "Subject: Your Resource claim has been approved!",
            "message" : "Dear [contact:contact_name],\\r\\n\\r\\nCongratulations!\\r\\n\\r\\nYour claim to [claim-reference:title] has been approved, you are now the owner of this resource, \\r\\n\\r\\nYou can now login and edit the information of this resource at [claim-reference:edit-url].\\r\\n\\r\\nPlease be-aware that your resource will expire automatically within 1 year, please regularly update your resource information in order to prevent this from happening.\\r\\n\\r\\n\\r\\nBest,\\r\\n[site:name]"
          }
        }
      ]
    }
  }');
  $items['rules_node_claim_rejection'] = entity_import('rules_config', '{ "rules_node_claim_rejection" : {
      "LABEL" : "Node Claim Rejection",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "CRM Core", "Node Claim", "Resource Claim" ],
      "REQUIRES" : [ "rules", "crm_core_node_claim" ],
      "ON" : [ "crm_core_node_claim_reject" ],
      "DO" : [
        { "mail" : {
            "to" : "[contact:field-contact-email] \\r\\n",
            "subject" : "Your Resource claim has been rejected!\\r\\n",
            "message" : "Dear [contact:contact_name],\\r\\n\\r\\nYour claim to [claim-reference:title] at [claim-reference:url] has been rejected, this is usually due to a variety of reasons such as \\r\\n\\r\\n  We are not able to reach you to verify information.\\r\\n  You have provided incomplete information on the claim form.\\r\\n  You did not provide sufficient reasoning to claim this resource\\r\\n\\r\\nIf you feel that this has been an error or mistake, please contact us at [site:mail] with the subject of (Resource claim appeal)\\r\\n\\r\\n\\r\\nBest,\\r\\n[site:name]"
          }
        }
      ]
    }
  }');
  return $items;
}
