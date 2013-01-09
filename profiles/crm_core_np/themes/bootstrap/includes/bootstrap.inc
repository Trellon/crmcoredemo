<?php

/**
 * A wrapper function for bootstrap_theme_get_settings().
 * 
 * @param $name
 *   The name of the setting that you want to retrieve. 
 * @param $default (optional)
 *   The name (key) of the theme that you want to fetch the
 *   setting for. Defaults to NULL.   
 * @param $theme (optional)
 *   The key (machin-readable name) of a theme. Defaults to the key of the
 *   current theme if not defined.
 *   
 * @see 
 *   bootstrap_theme_get_setting().
 */
function bootstrap_theme_get_setting($name, $theme = NULL) {
  switch ($name) {
    case 'exclude':
      $setting = bootstrap_theme_get_info($name, $theme);
      break;
    default:
      $setting = theme_get_setting($name, $theme);
      break;
  }

  return isset($setting) ? $setting : NULL; 
}

function bootstrap_get_settings($theme = NULL) {
  if (!isset($theme)) {
    $theme = !empty($GLOBALS['theme_key']) ? $GLOBALS['theme_key'] : '';
  }

  if ($theme) {
    $themes = list_themes();
    $theme_object = $themes[$theme];
  }

  return $theme_object->info['settings'];
}

function bootstrap_theme_get_info($setting_name, $theme = NULL) {
  // If no key is given, use the current theme if we can determine it.
  if (!isset($theme)) {
    $theme = !empty($GLOBALS['theme_key']) ? $GLOBALS['theme_key'] : '';
  }

  $output = array();

  if ($theme) {
    $themes = list_themes();
    $theme_object = $themes[$theme];

    // Create a list which includes the current theme and all its base themes.
    if (isset($theme_object->base_themes)) {
      $theme_keys = array_keys($theme_object->base_themes);
      $theme_keys[] = $theme;
    }
    else {
      $theme_keys = array($theme);
    }

    foreach ($theme_keys as $theme_key) {
      if (!empty($themes[$theme_key]->info[$setting_name])) {
        $output[$setting_name] = $themes[$theme_key]->info[$setting_name];
      }
    }
  }
  
  return $output;
}


/**
 * Returns navigational links based on a menu tree
 */
function bootstrap_menu_navigation_links($tree, $lvl = 0) {
  $result = array();

  if (count($tree) > 0) {
    foreach ($tree as $id => $item) {
      // Only work with enabled links
      if (empty($item['link']['hidden'])) {
        $new_item = array(
          'title' => $item['link']['title'],
          'link_path' => $item['link']['link_path'],
          'href' => $item['link']['href'],
        );

        // Dont do drugs and don't do any levels deeper then 1
        if ($lvl < 1) {
          $new_item['below'] = bootstrap_menu_navigation_links($item['below'], $lvl+1);
        }

        $result['menu-'. $item['link']['mlid']] = $new_item;
      }
    }
  }
  
  return $result;
}


/*
 * Custom theme functions
 *
 */

/**
 * theme_bootstrap_btn_dropdown
 */
function bootstrap_bootstrap_btn_dropdown($variables) {
  $type_class = '';
  $sub_links ='';

  $variables['attributes']['class'][] = 'btn-group';
  // Type class
  if (isset($variables['type'])) {
    $type_class = ' btn-'. $variables['type'];
  }

  // Start markup
  $output = '<div'. drupal_attributes($variables['attributes']) .'>';

  // Ad as string if its not a link
  if (is_array($variables['label'])) {
    $output .= l($variables['label']['title'], $$variables['label']['href'], $variables['label']);
  }

  $output .= '<a class="btn'. $type_class .' dropdown-toggle" data-toggle="dropdown" href="#">';

  // Its a link so create one
  if (is_string($variables['label'])) {
    $output .= check_plain($variables['label']);
  }

  if (is_array($variables['links'])) {
    $sub_links = theme('links', array('links' => $variables['links'],'attributes' => array('class' => array('dropdown-menu'))));
  }

  // Finish markup
  $output .= '<span class="caret"></span></a>' . $sub_links . '</div>';

  return $output;
}  

/**
 * theme_bootstrap_progress_bar
 */
function bootstrap_bootstrap_progress_bar($variables) {
  $variables['attributes']['class'][] = 'progress';
  
  return "<div". drupal_attributes($variables['attributes']) .">
  <div class=\"bar\"
       style=\"width: ". $variables['percent'] ."%;\"></div>
  </div>";
}
