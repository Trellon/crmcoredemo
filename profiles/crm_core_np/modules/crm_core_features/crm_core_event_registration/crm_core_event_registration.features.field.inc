<?php
/**
 * @file
 * crm_core_event_registration.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function crm_core_event_registration_field_default_fields() {
  $fields = array();

  // Exported field: 'crm_core_activity-event_registration-field_activity_date'.
  $fields['crm_core_activity-event_registration-field_activity_date'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'crm_core_activity',
      ),
      'field_name' => 'field_activity_date',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'granularity' => array(
          'day' => 'day',
          'hour' => 'hour',
          'minute' => 'minute',
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'repeat' => 0,
        'timezone_db' => 'UTC',
        'todate' => '',
        'tz_handling' => 'site',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'event_registration',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'crm_core_activity',
      'field_name' => 'field_activity_date',
      'label' => 'Date',
      'required' => FALSE,
      'settings' => array(
        'default_value' => 'now',
        'default_value2' => 'blank',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'display_all_day' => 0,
          'increment' => '15',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'repeat_collapsed' => 0,
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'crm_core_activity-event_registration-field_activity_notes'.
  $fields['crm_core_activity-event_registration-field_activity_notes'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'crm_core_activity',
      ),
      'field_name' => 'field_activity_notes',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '1',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'event_registration',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 2,
        ),
      ),
      'entity_type' => 'crm_core_activity',
      'field_name' => 'field_activity_notes',
      'label' => 'Notes',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'crm_core_activity-event_registration-field_activity_participants'.
  $fields['crm_core_activity-event_registration-field_activity_participants'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'crm_core_activity',
      ),
      'field_name' => 'field_activity_participants',
      'foreign keys' => array(),
      'indexes' => array(
        'target_entity' => array(
          1 => 'target_id',
        ),
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '1',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'target_bundles' => array(),
        ),
        'handler_submit' => 'Change handler',
        'target_type' => 'crm_core_contact',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'event_registration',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'crm_core_activity',
      'field_name' => 'field_activity_participants',
      'label' => 'Participants',
      'required' => TRUE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => 60,
        ),
        'type' => 'entityreference_autocomplete_tags',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'crm_core_activity-event_registration-field_registration_attendee'.
  $fields['crm_core_activity-event_registration-field_registration_attendee'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_registration_attendee',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'event_registration',
      'default_value' => array(
        0 => array(
          'value' => '1',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_integer',
          'weight' => 4,
        ),
      ),
      'entity_type' => 'crm_core_activity',
      'field_name' => 'field_registration_attendee',
      'label' => 'Number of Attendees',
      'required' => 0,
      'settings' => array(
        'max' => '10',
        'min' => '1',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'crm_core_activity-event_registration-field_registration_event'.
  $fields['crm_core_activity-event_registration-field_registration_event'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_registration_event',
      'foreign keys' => array(),
      'indexes' => array(
        'target_entity' => array(
          1 => 'target_id',
        ),
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'sort' => array(
            'direction' => 'ASC',
            'field' => 'body:value',
            'property' => 'nid',
            'type' => 'none',
          ),
          'target_bundles' => array(
            'event' => 'event',
          ),
        ),
        'handler_submit' => 'Change handler',
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'event_registration',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 3,
        ),
      ),
      'entity_type' => 'crm_core_activity',
      'field_name' => 'field_registration_event',
      'label' => 'Event',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'crm_core_activity-event_registration-field_registration_event_type'.
  $fields['crm_core_activity-event_registration-field_registration_event_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_registration_event_type',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'free' => 'Free',
          'paid' => 'Paid',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'event_registration',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 5,
        ),
      ),
      'entity_type' => 'crm_core_activity',
      'field_name' => 'field_registration_event_type',
      'label' => 'Event Type',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'crm_core_activity-event_registration-field_registration_order'.
  $fields['crm_core_activity-event_registration-field_registration_order'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_registration_order',
      'foreign keys' => array(),
      'indexes' => array(
        'target_entity' => array(
          1 => 'target_id',
        ),
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'sort' => array(
            'direction' => 'ASC',
            'field' => 'commerce_line_items:line_item_id',
            'property' => 'order_id',
            'type' => 'none',
          ),
          'target_bundles' => array(
            'commerce_order' => 'commerce_order',
          ),
        ),
        'handler_submit' => 'Change handler',
        'target_type' => 'commerce_order',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'event_registration',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The order associated with this event registration if the event type was paid',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 6,
        ),
      ),
      'entity_type' => 'crm_core_activity',
      'field_name' => 'field_registration_order',
      'label' => 'Admission',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'crm_core_activity-event_registration-field_registration_role'.
  $fields['crm_core_activity-event_registration-field_registration_role'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_registration_role',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'attendee' => 'attendee',
          'host' => 'host',
          'speaker' => 'speaker',
          'volunteer' => 'volunteer',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'event_registration',
      'default_value' => array(
        0 => array(
          'value' => 'attendee',
        ),
      ),
      'deleted' => '0',
      'description' => 'The registration role for the given user',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 8,
        ),
      ),
      'entity_type' => 'crm_core_activity',
      'field_name' => 'field_registration_role',
      'label' => 'Role',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'crm_core_activity-event_registration-field_registration_status'.
  $fields['crm_core_activity-event_registration-field_registration_status'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_registration_status',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'pending' => 'pending',
          'registered' => 'registered',
          'cancelled' => 'cancelled',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'event_registration',
      'default_value' => array(
        0 => array(
          'value' => 'pending',
        ),
      ),
      'deleted' => '0',
      'description' => 'The status of this registration',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 7,
        ),
      ),
      'entity_type' => 'crm_core_activity',
      'field_name' => 'field_registration_status',
      'label' => 'Status',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-event-body'.
  $fields['node-event-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Event Summary',
      'required' => 0,
      'settings' => array(
        'display_summary' => 1,
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '20',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '-4',
      ),
    ),
  );

  // Exported field: 'node-event-field_crmer_address'.
  $fields['node-event-field_crmer_address'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_crmer_address',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'addressfield',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'addressfield',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => array(
        0 => array(
          'element_key' => 'node|event|field_crmer_address|und|0',
          'thoroughfare' => '',
          'premise' => '',
          'locality' => '',
          'administrative_area' => '',
          'postal_code' => '',
          'country' => 'US',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'addressfield',
          'settings' => array(
            'format_handlers' => array(
              0 => 'address',
            ),
            'use_widget_handlers' => 1,
          ),
          'type' => 'addressfield_default',
          'weight' => 2,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_crmer_address',
      'label' => 'Address',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'addressfield',
        'settings' => array(
          'available_countries' => array(
            'US' => 'US',
          ),
          'format_handlers' => array(
            'address' => 'address',
            'address-hide-country' => 0,
            'organisation' => 0,
            'name-full' => 0,
            'name-oneline' => 0,
          ),
        ),
        'type' => 'addressfield_standard',
        'weight' => '-2',
      ),
    ),
  );

  // Exported field: 'node-event-field_crmer_event_date'.
  $fields['node-event-field_crmer_event_date'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_crmer_event_date',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 'hour',
          'minute' => 'minute',
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => 'UTC',
        'todate' => 'optional',
        'tz_handling' => 'site',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
          ),
          'type' => 'date_default',
          'weight' => 5,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_crmer_event_date',
      'label' => 'Event Date',
      'required' => 0,
      'settings' => array(
        'default_value' => 'now',
        'default_value2' => 'same',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'increment' => '15',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-event-field_crmer_event_phone'.
  $fields['node-event-field_crmer_event_phone'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_crmer_event_phone',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'cck_phone',
      'settings' => array(
        'size' => '15',
      ),
      'translatable' => '0',
      'type' => 'phone_number',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'cck_phone',
          'settings' => array(),
          'type' => 'global_phone_number',
          'weight' => 6,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_crmer_event_phone',
      'label' => 'Phone',
      'required' => 0,
      'settings' => array(
        'all_country_codes' => 0,
        'country_code_position' => 'after',
        'country_codes' => array(
          'country_selection' => array(
            'ad' => 0,
            'ae' => 0,
            'af' => 0,
            'ag' => 0,
            'ai' => 0,
            'al' => 0,
            'am' => 0,
            'an' => 0,
            'ao' => 0,
            'ar' => 0,
            'as' => 0,
            'at' => 0,
            'au' => 0,
            'aw' => 0,
            'az' => 0,
            'ba' => 0,
            'bb' => 0,
            'bd' => 0,
            'be' => 0,
            'bf' => 0,
            'bg' => 0,
            'bh' => 0,
            'bi' => 0,
            'bj' => 0,
            'bm' => 0,
            'bn' => 0,
            'bo' => 0,
            'br' => 0,
            'bs' => 0,
            'bt' => 0,
            'bw' => 0,
            'by' => 0,
            'bz' => 0,
            'ca' => 0,
            'cc' => 0,
            'cd' => 0,
            'cf' => 0,
            'cg' => 0,
            'ch' => 0,
            'ci' => 0,
            'ck' => 0,
            'cl' => 0,
            'cm' => 0,
            'cn' => 0,
            'co' => 0,
            'cr' => 0,
            'cu' => 0,
            'cv' => 0,
            'cx' => 0,
            'cy' => 0,
            'cz' => 0,
            'de' => 0,
            'dj' => 0,
            'dk' => 0,
            'dm' => 0,
            'do' => 0,
            'dz' => 0,
            'ec' => 0,
            'ee' => 0,
            'eg' => 0,
            'er' => 0,
            'es' => 0,
            'et' => 0,
            'fi' => 0,
            'fj' => 0,
            'fk' => 0,
            'fm' => 0,
            'fo' => 0,
            'fr' => 0,
            'ga' => 0,
            'gb' => 0,
            'gd' => 0,
            'ge' => 0,
            'gf' => 0,
            'gh' => 0,
            'gi' => 0,
            'gl' => 0,
            'gm' => 0,
            'gn' => 0,
            'gp' => 0,
            'gq' => 0,
            'gr' => 0,
            'gt' => 0,
            'gu' => 0,
            'gw' => 0,
            'gy' => 0,
            'hk' => 0,
            'hn' => 0,
            'hr' => 0,
            'ht' => 0,
            'hu' => 0,
            'id' => 0,
            'ie' => 0,
            'il' => 0,
            'in' => 0,
            'io' => 0,
            'iq' => 0,
            'ir' => 0,
            'is' => 0,
            'it' => 0,
            'jm' => 0,
            'jo' => 0,
            'jp' => 0,
            'ke' => 0,
            'kg' => 0,
            'kh' => 0,
            'ki' => 0,
            'km' => 0,
            'kn' => 0,
            'kp' => 0,
            'kr' => 0,
            'kw' => 0,
            'ky' => 0,
            'kz' => 0,
            'la' => 0,
            'lb' => 0,
            'lc' => 0,
            'li' => 0,
            'lk' => 0,
            'lr' => 0,
            'ls' => 0,
            'lt' => 0,
            'lu' => 0,
            'lv' => 0,
            'ly' => 0,
            'ma' => 0,
            'mc' => 0,
            'md' => 0,
            'me' => 0,
            'mg' => 0,
            'mh' => 0,
            'mk' => 0,
            'ml' => 0,
            'mm' => 0,
            'mn' => 0,
            'mo' => 0,
            'mp' => 0,
            'mq' => 0,
            'mr' => 0,
            'ms' => 0,
            'mt' => 0,
            'mu' => 0,
            'mv' => 0,
            'mw' => 0,
            'mx' => 0,
            'my' => 0,
            'mz' => 0,
            'na' => 0,
            'nc' => 0,
            'ne' => 0,
            'nf' => 0,
            'ng' => 0,
            'ni' => 0,
            'nl' => 0,
            'no' => 0,
            'np' => 0,
            'nr' => 0,
            'nu' => 0,
            'nz' => 0,
            'om' => 0,
            'pa' => 0,
            'pe' => 0,
            'pf' => 0,
            'pg' => 0,
            'ph' => 0,
            'pk' => 0,
            'pl' => 0,
            'pm' => 0,
            'pr' => 0,
            'ps' => 0,
            'pt' => 0,
            'pw' => 0,
            'py' => 0,
            'qa' => 0,
            'ro' => 0,
            'rs' => 0,
            'ru' => 0,
            'rw' => 0,
            'sa' => 0,
            'sb' => 0,
            'sc' => 0,
            'sd' => 0,
            'se' => 0,
            'sg' => 0,
            'sh' => 0,
            'si' => 0,
            'sk' => 0,
            'sl' => 0,
            'sm' => 0,
            'sn' => 0,
            'so' => 0,
            'sr' => 0,
            'ss' => 0,
            'st' => 0,
            'sv' => 0,
            'sy' => 0,
            'sz' => 0,
            'tc' => 0,
            'td' => 0,
            'tg' => 0,
            'th' => 0,
            'tj' => 0,
            'tk' => 0,
            'tm' => 0,
            'tn' => 0,
            'to' => 0,
            'tp' => 0,
            'tr' => 0,
            'tt' => 0,
            'tv' => 0,
            'tw' => 0,
            'tz' => 0,
            'ua' => 0,
            'ug' => 0,
            'us' => 'us',
            'uy' => 0,
            'uz' => 0,
            'va' => 0,
            'vc' => 0,
            've' => 0,
            'vg' => 0,
            'vi' => 0,
            'vn' => 0,
            'vu' => 0,
            'wf' => 0,
            'ws' => 0,
            'ye' => 0,
            'yt' => 0,
            'za' => 0,
            'zm' => 0,
            'zw' => 0,
          ),
          'hide_single_cc' => 1,
        ),
        'default_country' => 'us',
        'enable_country_level_validation' => 1,
        'enable_default_country' => 1,
        'enable_extension' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'cck_phone',
        'settings' => array(
          'size' => 15,
        ),
        'type' => 'phone_number',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-event-field_crmer_registration'.
  $fields['node-event-field_crmer_registration'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_crmer_registration',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Free' => 'Free',
          'Paid' => 'Paid',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'event',
      'default_value' => array(
        0 => array(
          'value' => 'None',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 4,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_crmer_registration',
      'label' => 'Registration',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '0',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Address');
  t('Admission');
  t('Date');
  t('Event');
  t('Event Date');
  t('Event Summary');
  t('Event Type');
  t('Notes');
  t('Number of Attendees');
  t('Participants');
  t('Phone');
  t('Registration');
  t('Role');
  t('Status');
  t('The order associated with this event registration if the event type was paid');
  t('The registration role for the given user');
  t('The status of this registration');

  return $fields;
}
