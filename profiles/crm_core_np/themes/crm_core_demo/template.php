<?php 
/**
 * @file
 * template.php file for CRM Core Demo theme.
 * 
 * This file contains a number of practical demonstrations
 * for how to work with CRM Core demo code. 
 * 
 * - hook_pre_render_views_view: used to override various activity
 *   feeds and apply stylized formating consistently through the
 *   interface.
 * 
 */

/**
 * Preprocess variables for block.tpl.php
 * 
 * @see block.tpl.php
 */
function crm_core_demo_preprocess_block(&$variables){
  
	// adding classes specific to twitter bootstrap to allow some blocks
	// to display as horizontal rows in the theme. the only block regions we
	// are modifying are 'below' and 'bottom'.
	
	// blocks can be added to the theme using the block module and the context
	// module. This function accounts for the presence of each.
	
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
  // only do this for the proper regions
  if($variables['elements']['#block']->region === 'below' || $variables['elements']['#block']->region === 'bottom'){
    $mod = 'span' . 12 / ($regions[$item]['cblocks'] + $regions[$item]['blocks']);
    $variables['classes_array'][] = $mod;
  }
  
}

/**
 * Preprocess variables for page.tpl.php
 * 
 * This function sets some variables around menus, contact information for the current user and such.
 * 
 * Information on the variables being set is provided within the function itself.
 *
 * @see page.tpl.php
 */
function crm_core_demo_preprocess_page(&$variables) {
  
  // this function sets some variables used for controlling navigation in various sections of the site.
  // it is mostly concerned with creating navigation within the CRM sections. we are using this instead of a context, for various reasons
  // having to do with the logic related to triggers.
  // In terms of what we are doing:
  // - setting contact information for the current user
  // - creating menus with administrative links
  // - employing some other, general functional / navigation items
	
  
  // only set these variables in the admin section of the site. If someone needs these variables elsewhere, move them around 
  // in the function.
  if(arg(0) == 'crm'){
    
    global $user;
    
    // create some variables to be used in the main layout of the site
    $variables['site_link'] = l('Back to Full Site', '', array('absolute' => TRUE)); // set a link returning users to the full site
    $variables['logout'] = l('Logout', 'user/logout'); // set a link allowing users to log out
    $variables['contact_name'] = $user->name; // set the name of the user
    $variables['crm_admin_menu'] = '';
    
    // get the contact record for the current user
    $contact = crm_user_sync_get_contact_from_uid($user->uid);
    
    // set the contact name for the user, if it exists. otherwise, use the name for the user account.
    if($contact->contact_name[LANGUAGE_NONE][0]['given']){
      $variables['contact_name'] = $contact->contact_name[LANGUAGE_NONE][0]['given'] . ' ' . $contact->contact_name[LANGUAGE_NONE][0]['family'];
    }
    $variables['contact_name'] = l('Logged in as ' . $variables['contact_name'], 'users/' . $user->name);
    
    // create a menu for CRM Core administrative links. output it as a drop down menu
    // TODO: make this a settable variable in the crm admin
    $menu = menu_tree('menu-crm-core-administrative-fea');
    $links = array();
    foreach ($menu as $item => $value){
      if(strpos($item, '#') === FALSE){
        $links[] = array(
          'title' => $value['#title'],
          'href' => $value['#href'],
        );
      }
    }
    $variables['crm_admin_menu'] = theme('bootstrap_btn_dropdown', array('label' => 'Settings ', 'links' => $links, 'type' => 'link btn-small', 'holder_class' => array('pull-right')));
    
    // create a menu for CRM Core navigation and place it in the layout.
    // TODO: make the name of the menu customizable within the theme.
    $nav_links = menu_navigation_links('menu-crm-core-basic-nav');
    // add some classes to the links, to make them prettier
    foreach ($nav_links as $item => $val){
      // add in some markup for the item
      if(stripos($nav_links[$item]['title'], 'Report') !== FALSE){
        $nav_links[$item]['icon'] = '<div class="nav_icon nav_icon_reports"></div>';
      }
      if(stripos($nav_links[$item]['title'], 'Dashboard') !== FALSE){
        $nav_links[$item]['icon'] = '<div class="nav_icon nav_icon_dashboard"></div>';
      }
      if(stripos($nav_links[$item]['title'], 'Contact') !== FALSE){
        $nav_links[$item]['icon'] = '<div class="nav_icon nav_icon_contacts"></div>';
      }
    }
    // output the tabs. These will be the main navigation for the CRM section and appear at the top of each page.
    $variables['crm_nav'] = theme('links', array('links' => $nav_links, 'attributes' => array('class'=> array('nav-tabs', 'nav')) ));
    
    // only display the tabs when we are viewing a contact. Some of the features are built so they will work with 
    // other Drupal themes, and will need tabs. This theme only needs them selectively.
    if(arg(1) == '' || (arg(1) === 'contact' && arg(2) == '') || (arg(1) === 'reports' && arg(2) == '')){
      $variables['tabs'] = '';
    }
    
  }
  
}

/**
 * Overriding default text areas to remove the handlebars from the bottom.
 * Adding a autosizing jquery plugin instead.
 * 
 * @param array $variables: preprocessing variables
 */
function crm_core_demo_textarea($variables) {
  $element = $variables['element'];
  $element['#attributes']['name'] = $element['#name'];
  $element['#attributes']['id'] = $element['#id'];
  $element['#attributes']['cols'] = $element['#cols'];
  $element['#attributes']['rows'] = $element['#rows'];
  _form_set_class($element, array('form-textarea'));
 
  $wrapper_attributes = array(
    'class' => array('form-textarea-wrapper'),
  );
 
  // Add resizable behavior.
  if (!empty($element['#resizable'])) {
    $wrapper_attributes['class'][] = 'resizable';
  }
 
  $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
  $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
  $output .= '</div>';
  return $output;
}


/**
 * Implementation of hook_preprocess_views_pre_render
 * 
 * This function is used as a preprocessing function for views
 * within the theme. Each time a view is loaded, it directs 
 * traffic to the appropriate preprocessing function.
 * 
 */
function crm_core_demo_views_pre_render(&$view) {
	
	// check to see if the view has a name. if so, look for
	// a correlate function in the theme that can be loaded
	// to preprocess variables within the view
	
  // dpm($view->name);
  
	if (isset($view->name)) {
		$function = 'crm_core_demo_preprocess_views_view__'.$view->name;
		if (function_exists($function)) {
			$function($view);
		}
	}
	
}

/**
 * Preprocessor for the contact list
 * @param unknown_type $view
 */
function crm_core_demo_preprocess_views_view__crm_core_contacts_alt(&$view) {
  
// dpm($view->result);
  
}

/**
 * Example of a theme preprocessing function. 
 * 
 * This function assigns several custom variables to the view being loaded. 
 * It is specific to the view being presented, helping to keep code 
 * well-organized within this file.
 */
function crm_core_demo_preprocess_views_view__crm_core_recent_activities(&$view) {

	// we already know the structure of the view being loaded, so we are going
	// to make modifications based on data coming from the view. In this case, we are
	// interested in the kind of activity being presented, and want to display
	// some custom text and icons in the theme template file. Information about
	// the icon and custom text are stored here as variables with each view result.
	
	if($view->current_display !== 'block_3'){
	  
  	foreach ($view->result as $item => $data){
  
  		// TODO: remove debugging
  		// dpm($view->result[$item]);
  		// dpm($view->result[$item]->crm_core_contact_field_data_field_activity_participants_cont);
  		// dpm($view->result[$item]->field_contact_name[0]['rendered']['#markup']);
  		// dpm($view->result[$item]->field_field_donation_amounts[0]['rendered']['#markup']);
  
  	  if(is_array($view->result[$item]->field_contact_name) && sizeof($view->result[$item]->field_contact_name) > 0){
  	    
  	    // dpm($view->result[$item]->crm_core_contact_field_data_field_activity_participants_cont);
  	    
  			$name = $view->result[$item]->field_contact_name[0]['rendered']['#markup'];
  			$link = l($name,
  					// 'crm/contact/' . $view->result[$item]->crm_core_contact_field_data_field_activity_participants_cont,
  					'/crm/contact/' . $view->result[$item]->crm_core_contact_field_data_field_activity_participants_cont,
  					array('attributes' => array(
  							'class'	=> 'contact_name',
  					)
  				)
  			);
  	  } else {
  			$name = 'An anonymous user';
  			$link = $name;
  		}

  		
  		// add default icons and text to each activity item
  		$view->result[$item]->icon_class = 'activity-icon-default';
  		$view->result[$item]->activity_desc = $link . ' did something in the system';
  
  		// loop through the possible activity types
  		switch ($view->result[$item]->crm_core_activity_type){
  			case 'donation':
  				$view->result[$item]->icon_class = 'activity-icon-donation';
  				$view->result[$item]->activity_desc = $link . ' donated <strong>$' . $view->result[$item]->field_field_donation_amounts[0]['rendered']['#markup'] . '</strong>.' ;
  				break;
  			case 'event_registration':
  				$view->result[$item]->icon_class = 'activity-icon-event-registration';
  				$view->result[$item]->activity_desc = $link . ' registered for an event.';
  				break;
  			case 'petition_signature':
  				$view->result[$item]->icon_class = 'activity-icon-petition-signature';
  				$view->result[$item]->activity_desc = $link . ' signed a petition.';
  				break;
  			default:
  				break;
  		}
  	}
	}
	
}

/**
 * Implementation of hook_theme
 * Creating several custom functions for presenting links within the theme.
 */
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
 * Implementation of theme_links
 * 
 * This override creates some settings for icons that will appear next to menu items.
 * 
 * To use it, pass rendered markup for the icon as part of each link. i.e.:
 * $link['icon'] = '<div class="icon some-class"></div>'
 * 
 */
function crm_core_demo_links($variables) {
  
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  global $language_url;
  $output = '';

  if (count($links) > 0) {
    $output = '';

    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading. 
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $output .= '<ul' . drupal_attributes($attributes) . '>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = array($key);
      
      // adding in some settings to detect an icon.
      // an icon should be pre-rendered HTML that will display to the side of the link.
      // in terms of theming, position it absolutely and make the LI display: relative
      $icon = '';
      
      if (isset($link['icon'])) {
        $icon = $link['icon'];
      }
      
      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class[] = 'first';
      }
      if ($i == $num_links) {
        $class[] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
           && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $class[] = 'active';
      }
      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $output .= $icon . l($link['title'], $link['href'], $link);
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
        $output .= '<span' . $span_attributes . '>' . $icon .  $link['title'] . '</span>';
      }

      $i++;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}



/**
 * copy of theme_twitter_bootstrap_btn_dropdown
 * 
 * We need to be able to add pull-left and pull-right to some dropdowns. This lets us do that.
 * 
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

/**
 * theme_bootstrap_btn_dropdown
 * 
 * This overrides the function in bootstrap.inc to include support for classes
 * on dropdown menus.
 * 
 * We need to be able to add pull-left and pull-right to some dropdowns. This lets us do that.
 * 
 */
function crm_core_demo_bootstrap_btn_dropdown($variables) {
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
    
    $holder_class = array();
    $holder_class[] = 'dropdown-menu';
    if(isset($variables['holder_class'])){
      foreach ($variables['holder_class'] as $item => $val){
        $holder_class[] = $val;
      }
    }
    
    $sub_links = theme('links', array('links' => $variables['links'],'attributes' => array('class' => $holder_class)));
    
  }

  // Finish markup
  $output .= '<span class="caret"></span></a>' . $sub_links . '</div>';

  return $output;
}  

