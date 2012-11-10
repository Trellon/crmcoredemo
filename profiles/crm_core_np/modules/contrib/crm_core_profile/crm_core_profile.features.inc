<?php

/**
 * Implements hook_features_export_options
 */
function crm_core_profile_features_export_options() {
  
  // load all of the crm_core_profile
  $options = array();
  $crm_core_profiles = crm_core_profile_load_all();
  if (!empty($crm_core_profiles)) {
    foreach (crm_core_profile_load_all() as $crm_core_profile) {
      $options[$crm_core_profile['name']] = $crm_core_profile['label'];
    }    
  }
  
  return $options;
}

/**
 * Implements hook_features_export
 */
function crm_core_profile_features_export($data, &$export, $module_name) {
  foreach ($data as $crm_core_profile_name) {
    // [component name][name]
    $export['features']['crm_core_profile'][$crm_core_profile_name] = $crm_core_profile_name;
    $export['dependencies']['crm_core_profile'] = 'crm_core_profile';
    $export['dependencies']['features'] = 'features'; 
       
    // get all of the module dependencies for crm_core_profile module
    // get all the dependencies for all the fields used in the profile  
    // @todo: grab contact fields used in the crm_core_profile????? 
    $field_dependencies = _crm_core_profile_field_dependencies($crm_core_profile_name);
    if (!empty($field_dependencies)) {
      foreach ($field_dependencies as $dependency_module) {
        $export['dependencies'][$dependency_module] = $dependency_module; 
      }
    }
        
    // crm_core_profile_activity related dependencies
    // @todo: grab the activity type and all of its fields into the feature?
    if (module_exists('crm_core_profile_activity')) {
      $crm_core_profile_activity = crm_core_profile_activity_load($crm_core_profile_name);
      if (!empty($crm_core_profile_activity)) {
        $export['dependencies']['crm_core_profile_activity'] = 'crm_core_profile_activity';
        $field_dependencies = _crm_core_profile_field_dependencies($crm_core_profile_name);
        if (!empty($field_dependencies)) {
          foreach ($field_dependencies as $dependency_module) {
            $export['dependencies'][$dependency_module] = $dependency_module; 
          }
        } 
      }  
    }
    
  }
  
  return array();
}

/**
 * Implements hook_features_export_render
 */
function crm_core_profile_features_export_render($module_name, $data, $export = NULL) {
  $code = array();
  $code[] = '$crm_core_profile = array();';
  foreach ($data as $name) {
    $code[] = "  \$crm_core_profile['profile']['{$name}'] = " . features_var_export(crm_core_profile_load($name)) .";";    
    // add the activity to the code string if it is necessary
    if (module_exists('crm_core_profile_activity')) {
      $crm_core_profile_activity = crm_core_profile_activity_load($name);
      if (!empty($crm_core_profile_activity)) {
        $code[] = "  \$crm_core_profile['activity']['{$name}'] = " . features_var_export(crm_core_profile_activity_load($name)) .";";  
      }      
    }    
  }
  $code[] = "return \$crm_core_profile;";
  $code = implode("\n", $code);
  
  return array('crm_core_profile_default' => $code);
}

/**
 * Implements hook_features_revert().
 */
function crm_core_profile_features_revert($module) {
  crm_core_profile_features_rebuild($module);
}
 
/**
 * Implements hook_features_rebuild
 */
function crm_core_profile_features_rebuild($module) {
  if ($crm_core_profiles = features_get_default('crm_core_profile', $module)) {
    _crm_core_profile_features_rebuild($crm_core_profiles);
  }
}

/**
 *
 * Rebuild a crm_core_profile feature (and crm_core_profile_activity)
 */
function _crm_core_profile_features_rebuild($crm_core_profiles) {
  $types = array('profile', 'activity');
  foreach ($types as $type) {
    if (!empty($crm_core_profiles[$type])) {
      if ($type == 'profile') {
        $function = 'crm_core_profile_load_all';  
      } else {
        $function = 'crm_core_profile_' . $type . '_load_all';  
      }
      
      $existings = $function();
      foreach ($crm_core_profiles[$type] as $component) {  
        foreach ($existings as $existing) {
          if ($existing['name'] === $component['name']) {
            $existing = $component;  
          }  
        }
        
        // @todo: make serialization load better
        // apparently serialized blob field saves array into serialized but does not load into array
        if (!is_array($component['fields'])) {
          $component['fields'] = unserialize($component['fields']);  
        }
        
        $create_action = ($type == 'profile') ? 'contact' : $type;
        if (!is_array($component['create_' . $create_action . '_actions'])) {
          $component['create_' . $create_action . '_actions'] = unserialize($component['create_' . $create_action . '_actions']);
        }  
  
       $save = ($type == 'profile') ? 'crm_core_profile_save' : 'crm_core_profile_' . $type . '_save';
       $save($component); 
      }
    }     
  }   
}

/**
 * Finding dependencies based on a crm_core_profile_given
 *
 * @params
 * (string) $name    CRM Core Profile name
 * (string) $type            The type of crm_core_profile component, possible values are 
 *                           profile, profile_activity
 *
 */
function _crm_core_profile_field_dependencies($name, $type = 'profile') {
  
  $dependencies = array();
  $function = 'crm_core_' . $type . '_load';
  
  $data = $function($name);
  if (!is_array($data['fields'])) {
    $data['fields'] = unserialize($data['fields']);  
  }
  foreach ($data['fields']['toggle'] as $field => $toggle) {
    if ($field === $toggle) {
      $info = field_info_field($field);
      $dependencies[] = $info['module'];  
    }
  }    
  return array_unique($dependencies);
}

