<?php

/**
 * Returns HTML for primary and secondary local tasks.
 */
function twitter_bootstrap_menu_local_tasks(&$vars) {
  $output = '';

  if ( !empty($vars['primary']) ) {
    $vars['primary']['#prefix'] = '<ul class="nav nav-tabs">';
    $vars['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($vars['primary']);
  }

  if ( !empty($vars['secondary']) ) {
    $vars['secondary']['#prefix'] = '<ul class="nav nav-pills">';
    $vars['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($vars['secondary']);
  }

  return $output;
}


/**
 * Returns HTML for primary and secondary local tasks.
 *
 * @ingroup themeable
 */
function twitter_bootstrap_menu_local_task($variables) {
  $link = $variables['element']['#link'];
  $link_text = $link['title'];
  $classes = array();

  if (!empty($variables['element']['#active'])) {
    // Add text to indicate active tab for non-visual users.
    $active = '<span class="element-invisible">' . t('(active tab)') . '</span>';

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link['localized_options']['html'] = TRUE;
    $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));

    $classes[] = 'active';
  }

  // Render child tasks if available.
  $children = '';
  if (element_children($variables['element'])) {
    $link['localized_options']['attributes']['class'][] = 'dropdown-toggle';
	$link['localized_options']['attributes']['data-toggle'][] = 'dropdown';
    $classes[] = 'dropdown';

    $children = drupal_render_children($variables['element']);
    $children = '</b><ul class="secondary-tabs dropdown-menu">' . $children . "</ul>";

	return '<li class="' . implode(' ', $classes) . '"><a href="#"' . drupal_attributes($link['localized_options']['attributes']) .'>' . $link_text . '<b class="caret"></a>' . $children . "</li>\n";
  }else{
	return '<li class="' . implode(' ', $classes) . '">' . l($link_text, $link['href'], $link['localized_options']) . $children . "</li>\n";
  }
}

function twitter_bootstrap_menu_tree(&$variables) {
  return '<ul class="menu nav">' . $variables['tree'] . '</ul>';
}

function twitter_bootstrap_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  
  // Sanitize title
  $element['#title'] = check_plain($element['#title']);
  
  if ($element['#below']) {
	// Ad our own wrapper
	unset($element['#below']['#theme_wrappers']);
    $sub_menu = '<ul>' . drupal_render($element['#below']) . '</ul>';

    //$element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
	//$element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
	//$element['#attributes']['class'][] = 'dropdown';
	$element['#localized_options']['html'] = TRUE;
	//$element['#title'] .= '<b class="caret"></b>';
	
	// auch
	$element['#href'] = "";
  }
  
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
* Get all primary tasks including subsets
*/
function _twitter_bootstrap_local_tasks($tabs = FALSE) {
  if ($tabs == '') {
    return $tabs;
  }
  
  if (!$tabs) {
  	$tabs = menu_primary_local_tasks();
	}
  
  foreach($tabs as $key => $element) {
	  $result = db_select('menu_router', NULL, array('fetch' => PDO::FETCH_ASSOC))
      ->fields('menu_router')
      ->condition('tab_parent', $element['#link']['path'])
      ->condition('context', MENU_CONTEXT_INLINE, '<>')
      ->condition('type', array(MENU_DEFAULT_LOCAL_TASK, MENU_LOCAL_TASK), 'IN')
      ->orderBy('weight')
      ->orderBy('title')
      ->execute();
  
    $router_item = menu_get_item($element['#link']['href']);
    $map = $router_item['original_map'];
  
    $i = 0;
    foreach ($result as $item) {
      _menu_translate($item, $map, TRUE);
  
      //only add items that we have access to
      if ($item['tab_parent'] && $item['access']) {
        //set path to that of parent for the first item
        if ($i === 0) {
          $item['href'] = $element['#link']['href'];
        }
  
        if (current_path() == $item['href']) {
          $tabs[$key][] = array(
          '#theme' => 'menu_local_task',
          '#link' => $item,
          '#active' => TRUE,
          );
        }
        else {
          $tabs[$key][] = array(
          '#theme' => 'menu_local_task',
          '#link' => $item,
          );
        }
  
        //only count items we have access to.
        $i++;
      }
    }
  }
  
  return $tabs;
}