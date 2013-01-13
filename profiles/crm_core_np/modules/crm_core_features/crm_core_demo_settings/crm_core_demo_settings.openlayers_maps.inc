<?php
/**
 * @file
 * crm_core_demo_settings.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function crm_core_demo_settings_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'crm_core_contacts_individual_loc';
  $openlayers_maps->title = 'CRM Core Contacts Individual Location';
  $openlayers_maps->description = 'Displays the location for an individual contact';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '300px',
    'image_path' => 'profiles/crm_core_np/modules/contrib/openlayers/themes/default_dark/img/',
    'css_path' => 'profiles/crm_core_np/modules/contrib/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 1,
    'center' => array(
      'initial' => array(
        'centerpoint' => '0,0',
        'zoom' => '2',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'crm_core_contact_map_display_individual_openlayers_1' => 'crm_core_contact_map_display_individual_openlayers_1',
        ),
        'panMapIfOutOfView' => 0,
        'keepInMap' => 1,
      ),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => array(
          'crm_core_contact_map_display_individual_openlayers_1' => 'crm_core_contact_map_display_individual_openlayers_1',
          'google_normal' => 0,
        ),
        'point_zoom_level' => '10',
        'zoomtolayer_scale' => '10',
      ),
    ),
    'default_layer' => 'google_normal',
    'layers' => array(
      'google_normal' => 'google_normal',
      'crm_core_contact_map_display_individual_openlayers_1' => 'crm_core_contact_map_display_individual_openlayers_1',
    ),
    'layer_weight' => array(
      'crm_core_contact_map_display_individual_openlayers_1' => '0',
      'testtesttest_openlayers_1' => '0',
      'crm_core_contact_map_openlayers_1' => '0',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'crm_core_contact_map_openlayers_1' => '0',
      'testtesttest_openlayers_1' => '0',
      'crm_core_contact_map_display_individual_openlayers_1' => '0',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'crm_core_contact_map_openlayers_1' => '0',
      'testtesttest_openlayers_1' => '0',
      'crm_core_contact_map_display_individual_openlayers_1' => '0',
    ),
    'layer_activated' => array(
      'crm_core_contact_map_display_individual_openlayers_1' => 'crm_core_contact_map_display_individual_openlayers_1',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'crm_core_contact_map_openlayers_1' => 0,
      'testtesttest_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'crm_core_contact_map_display_individual_openlayers_1' => 0,
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'crm_core_contact_map_openlayers_1' => 0,
      'testtesttest_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $export['crm_core_contacts_individual_loc'] = $openlayers_maps;

  return $export;
}
