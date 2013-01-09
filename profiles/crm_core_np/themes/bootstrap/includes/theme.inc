<?php

function bootstrap_item_list($variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];
  $output = '';

  if (isset($title)) {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    foreach ($items as $i => $item) {
      $attributes = array();
      $children = array();
      $data = '';
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }
      if ($i == 0) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items - 1) {
        $attributes['class'][] = 'last';
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= "</$type>";
  }
 
  return $output;
}

/**
 * Returns HTML for status and/or error messages, grouped by type.
 */
function bootstrap_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );

  // Map Drupal message types to their corresponding Bootstrap classes.
  // @see http://twitter.github.com/bootstrap/components.html#alerts
  $status_class = array(
    'status' => 'success',
    'error' => 'error',
    'warning' => 'info',
  );

  foreach (drupal_get_messages($display) as $type => $messages) {
    $class = (isset($status_class[$type])) ? ' alert-' . $status_class[$type] : '';
    $output .= "<div class=\"alert alert-block$class\">\n";
    $output .= "  <a class=\"close\" data-dismiss=\"alert\" href=\"#\">x</a>\n";

    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>\n";
    }

    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= $messages[0];
    }

    $output .= "</div>\n";
  }
  return $output;
}

function bootstrap_css_alter(&$css) {
  $theme_path = drupal_get_path('theme', 'bootstrap');

  $excludes = _bootstrap_alter(bootstrap_theme_get_info('exclude'), 'css');

  if (theme_get_setting('cdn_bootstrap')){
    //first add the existing bootstrap css to the exclude
    $excludes[$theme_path . '/bootstrap/css/bootstrap.css'] = FALSE;
    $excludes[$theme_path . '/bootstrap/css/bootstrap-responsive.css'] = FALSE ;
    
    //and then add the cdn css
    $cdn_url ='http://netdna.bootstrapcdn.com/twitter-bootstrap/2.2.1/css/bootstrap-combined.min.css';
    $css[$cdn_url]['data'] = $cdn_url;
    $css[$cdn_url]['type'] = 'external';
    $css[$cdn_url]['every_page'] = TRUE;
    $css[$cdn_url]['media'] = 'all';
    $css[$cdn_url]['preprocess'] = TRUE;
    $css[$cdn_url]['group'] = CSS_THEME;
    $css[$cdn_url]['weight'] = -1;
    $css[$cdn_url]['browsers'] = array('IE' => TRUE, '!IE' => TRUE);
  }
  $css = array_diff_key($css, $excludes);
}

/**
 * Implements hook_js_alter().
 */
function bootstrap_js_alter(&$js) {
  $theme_path = drupal_get_path('theme', 'bootstrap');
  $files = array();

  $excludes = _bootstrap_alter(bootstrap_theme_get_info('exclude'), 'js');

  // If bootstrap_ui available, we should not add js from theme info file.
  if (module_exists('bootstrap_ui')) {
    libraries_load('bootstrap', 'minified');
    $excludes[drupal_get_path('theme', 'bootstrap') . '/bootstrap/js/bootstrap.js'] = array();
  }

  $js = array_diff_key($js, $excludes);
  if (theme_get_setting('cdn_jquery')) {
    // Add jQuery and the switch script to the $files array
    $files[] = 'http://ajax.googleapis.com/ajax/libs/jquery/1.8.3/jquery.min.js';

    if (theme_get_setting('cdn_bootstrap')) {
      $files[] = 'http://netdna.bootstrapcdn.com/twitter-bootstrap/2.2.1/js/bootstrap.min.js';
    }
    else {
      $files[] = $theme_path . '/bootstrap/js/bootstrap.js';
    }
    $files[] = $theme_path . '/js/switch.js';
  }
  else {
    if (theme_get_setting('cdn_bootstrap')) {
      $files[] = 'http://netdna.bootstrapcdn.com/twitter-bootstrap/2.2.1/js/bootstrap.min.js';
    }
    else {
      $files[] = $theme_path . '/bootstrap/js/bootstrap.js';
    }
  }

  // Rearrange / Add JS
  $group = -50;
  $weight = -100;
  foreach ($files as $file) {
    if (!isset($js[$file])) {
      $js[$file] = drupal_js_defaults();
      $js[$file]['data'] = $file;
      $js[$file]['group'] = $group;
      $js[$file]['weight'] = $weight;
      $weight++;
    }
  }
}

function _bootstrap_alter($files, $type) {
  $output = array();
  
  foreach($files as $key => $value) {
    if (isset($files[$key][$type])) {
      foreach ($files[$key][$type] as $file => $name) {
        $output[$name] = FALSE;
      }
    }
  }
  return $output;
}

/**
 * Returns HTML for a set of links.
 */
function bootstrap_bootstrap_links($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  //$dropdown = $variables['dropdown'];

  global $language_url;
  $output = '';

  if (count($links) > 0) {
    $output = '';
    $output .= '<ul' . drupal_attributes($attributes) . '>';

    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading. 
          'level' => 'li',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $num_links = count($links);
    $i = 1;
  
    foreach ($links as $key => $link) {
      $children = array();
      
      if (isset($link['below'])) {
        $children = $link['below'];
      }

      $attributes = array('class' => array($key));

      // Add first, last and active classes to the list of links to help out themers.
        if ($i == 1) {
          $attributes['class'][] = 'first';
        }
        if ($i == $num_links) {
          $attributes['class'][] = 'last';
        }
        if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
             && (empty($link['language']) || $link['language']->language == $language_url->language)) {
          $attributes['class'][] = 'active';
        }

      if (count($children) > 0) {
        $attributes['class'][] = 'dropdown';
        $link['attributes']['data-toggle'] = 'dropdown';
        $link['attributes']['class'][] = 'dropdown-toggle';
      }

      if (!isset($link['attributes'])) {
        $link['attributes'] = array();
      }

      $link['attributes'] = array_merge($link['attributes'], $attributes);

      if (count($children) > 0) {
        $link['attributes']['class'][] = 'dropdown';
      }

      $output .= '<li' . drupal_attributes($attributes) . '>';

      if (isset($link['href'])) {
        if (count($children) > 0) {
          $link['html'] = TRUE;
          $link['title'] .= ' <span class="caret"></span>';
          $output .=  '<a' . drupal_attributes($link['attributes']) . ' href="#">'. $link['title'] .'</a>';
        }
        else {
        // Pass in $link as $options, they share the same keys.
         $output .= l($link['title'], $link['href'], $link);
        }
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link['html'])) {
         $link['title'] = check_plain($link['title']);
        }

        $span_attributes = '';
        if (isset($link['attributes'])) {
         $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }

      $i++;

      if(count($children) > 0) {
        $attributes = array();
        $attributes['class'] = array('dropdown-menu');

        $output .= theme('bootstrap_links', array('links' => $children, 'attributes' => $attributes));
      }

      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}

function bootstrap_preprocess_table(&$variables) {

  if (isset($variables['attributes']['class']) && is_string($variables['attributes']['class'])) {
    // Convert classes to an array.
    $variables['attributes']['class'] = explode(' ', $variables['attributes']['class']);
  }

  $variables['attributes']['class'][] = 'table';
  $variables['attributes']['class'][] = 'table-striped';
  
}
