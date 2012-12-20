<?php 

function crm_core_demo_preprocess_region(&$variables){
  // dpm($variables);
}

function crm_core_demo_preprocess_block(&$variables){
  
  // creating a static variable to store information about the number of blocks in each region
  // it will be a keyed array that simply lists the number of blocks in each item
  $regions = &drupal_static(__FUNCTION__);
  $item = $variables['elements']['#block']->region;
  
  // check to see whether or not we have already counted the blocks for this region
  if(!isset($regions[$item])){
    
    // set up the region array
    $regions[$item] = array('blocks' => 0, 'cblocks' => 0);
    
    // check for blocks set in Drupal
    $regions[$item]['blocks'] = sizeof(block_list($variables['elements']['#block']->region));
    
    // check for blocks set through a context
    $count = 0;
    $ctxts = context_active_contexts(); // get a list of all active contexts to check
    
    foreach ($ctxts as $cxt => $record){
      if($record->reactions['block']){ // check to see if there are blocks defined as a reaction within the context
        foreach ($record->reactions['block']['blocks'] as $block => $data){
          if($data['region'] == $item){
            $regions[$item]['cblocks'] = $regions[$item]['cblocks'] + 1;
          }
        }
      }
    }
  }
  
  // apply a custom class to blocks based on the number of items in the region
  // only do this for the right regions
  if($variables['elements']['#block']->region === 'below' || $variables['elements']['#block']->region === 'bottom'){
    $mod = 'span' . 12 / ($regions[$item]['cblocks'] + $regions[$item]['blocks']);
    $variables['classes_array'][] = $mod;
  }
  
}

/**
 * Preprocess variables for page.tpl.php
 *
 * @see page.tpl.php
 */
function crm_core_demo_preprocess_page(&$variables) {
  // Secondary nav
  $variables['secondary_nav'] = FALSE;
  if($variables['secondary_menu']) {
    $secondary_menu = menu_load(variable_get('menu_secondary_links_source', 'user-menu'));
    
    // Build links
    $tree = menu_tree_page_data($secondary_menu['menu_name']);
    $variables['secondary_menu'] = crm_core_demo_menu_navigation_links($tree);
    
    // Build list
    $variables['secondary_nav'] = theme('twitter_bootstrap_btn_dropdown', array(
      'links' => $variables['secondary_menu'],
      'label' => $secondary_menu['title'],
      'type' => 'success',
      'attributes' => array(
        'id' => 'user-menu',
        'class' => array('pull-right'),
      ),
      'heading' => array(
        'text' => t('Secondary menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      ),
    ));
  }
  
  // Replace tabs with dropw down version
  $variables['tabs']['#primary'] = _twitter_bootstrap_local_tasks($variables['tabs']['#primary']);
}

function crm_core_demo_theme() {
  return array(
    'crm_core_demo_links' => array(
      'variables' => array('links' => array(), 'attributes' => array(), 'heading' => NULL),
    ),
    'crm_core_demo_btn_dropdown' => array(
      'variables' => array('links' => array(), 'attributes' => array(), 'type' => NULL),
    ), 
  );
}


/**
 * Returns navigational links based on a menu tree
 */
function crm_core_demo_menu_navigation_links($tree, $lvl = 0) {
  
  // Create a single level of links.
  $router_item = menu_get_item();
  $links = array();
  foreach ($tree as $item) {
    if (!$item['link']['hidden']) {
      $class = '';
      $l = $item['link']['localized_options'];
      $l['href'] = $item['link']['href'];
      $l['title'] = $item['link']['title'];
      if ($item['link']['in_active_trail']) {
        $class = ' active-trail';
        $l['attributes']['class'][] = 'active-trail';
      }
      // Normally, l() compares the href of every link with $_GET['q'] and sets
      // the active class accordingly. But local tasks do not appear in menu
      // trees, so if the current path is a local task, and this link is its
      // tab root, then we have to set the class manually.
      if ($item['link']['href'] == $router_item['tab_root_href'] && $item['link']['href'] != $_GET['q']) {
        $l['attributes']['class'][] = 'active';
      }
      // Keyed with the unique mlid to generate classes in theme_links().
      $links['menu-' . $item['link']['mlid'] . $class] = $l;
    }
  }
  return $links;
  
  
  // the original code from twitter bootstrap
  
  $result = array();

  if(count($tree) > 0) {
	foreach($tree as $id => $item) {
	  $new_item = array('title' => $item['link']['title'], 'link_path' => $item['link']['link_path'], 'href' => $item['link']['href']);
	  
	  // Dont do drugs and don't do any levels deeper then 1
	  if($lvl < 1)
		$new_item['below'] = twitter_bootstrap_menu_navigation_links($item['below'], $lvl+1);
	  
	  $result['menu-'. $item['link']['mlid']] = $new_item;
	}
  }
  
  return $result;
}



/**
 * theme_twitter_bootstrap_btn_dropdown
 */
function crm_core_demo_btn_dropdown($variables) {
  $type_class = '';
  
  // Type class
  if(isset($variables['type']))
	$type_class = ' btn-'. $variables['type'];
  
  // Start markup
  $output = '<div'. drupal_attributes($variables['attributes']) .'>';
  
  // Ad as string if its not a link
  if(is_array($variables['label'])) {
	$output .= l($variables['label']['title'], $$variables['label']['href'], $variables['label']);
  }
  
  $output .= '<a class="btn'. $type_class .' dropdown-toggle" data-toggle="dropdown" href="#">';
  
  // Its a link so create one
  if(is_string($variables['label'])) {
	$output .= check_plain($variables['label']);
  }
  
  // Finish markup 	
  $output .= '
  <span class="caret"></span>
	</a>
	' . $variables['links'] . '
  </div>';
  
  return $output;
}  


