<?php
/**
 * @file
 * crm_core_demo_settings.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function crm_core_demo_settings_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ind_comm_pref|crm_core_contact|individual|form';
  $field_group->group_name = 'group_ind_comm_pref';
  $field_group->entity_type = 'crm_core_contact';
  $field_group->bundle = 'individual';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Communication Preferences',
    'weight' => '11',
    'children' => array(
      0 => 'field_ind_comm_method',
      1 => 'field_ind_comm_cont',
      2 => 'field_ind_comm_email',
      3 => 'field_ind_comm_sms',
      4 => 'field_ind_comm_mail',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ind_comm_pref|crm_core_contact|individual|form'] = $field_group;

  return $export;
}
