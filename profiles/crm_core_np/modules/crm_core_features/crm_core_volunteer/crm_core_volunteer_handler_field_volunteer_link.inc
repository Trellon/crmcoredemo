<?php

/**
 * Field handler to present a link to a volunteer opportunity application/commitment.
 */
class crm_core_volunteer_handler_field_volunteer_link extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['nid'] = 'nid';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    $nid = $this->get_value($values, 'nid');
    
    $crm_core_profile = variable_get('crm_core_volunteer_profile', '');

    // check for permission
    $node = node_load($nid);
    $access = user_access('crm_core volunteer apply');
    if (!$access) {
      if (!user_is_logged_in()) {
        return l('<span>' . $text . '</span>', 'user', array('query' => array('destination' => drupal_get_path_alias('node/' . $node->nid)), 'html' => TRUE, 'attributes' => array('class' => array('crm_core_volunteer_link'))));        
      }
      else 
      {
        return;  
      } 
    }

    $check = _crm_core_volunteer_check_commitment($nid);
    $quota = crm_core_volunteer_check_quota($node);
    if ($check || $quota) {
      return;  
    }
     
    return l('<span>' . $text . '</span>', 'node/' . $nid . '/volunteer/' . $crm_core_profile, array('html' => TRUE, 'attributes' => array('class' => array('crm_core_volunteer_link'))));
  }
}