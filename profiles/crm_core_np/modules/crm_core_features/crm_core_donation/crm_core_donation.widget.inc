<?php

/**
 * Render the donation widget
 */
function crm_core_donation_widget($donation_page_id) {
  
  module_load_include('inc', 'crm_core_donation', 'crm_core_donation.pages');
  $donation_page = crm_core_donation_page_load($donation_page_id);
  if (empty($donation_page)) {
    return;  
  }
  if ($donation_page['widget'] == 0) {
    return;    
  }
  
  // find the current amount donation from this page
  $query = new EntityFieldQuery();
  $donations = $query->entityCondition('entity_type', 'crm_core_activity')
                    ->entityCondition('bundle', 'donation')
                    ->fieldCondition('field_donation_campaign', 'value', $donation_page_id)
                    ->execute();
  $current = 1;
  if (!empty($donations)) {
    foreach($donations['crm_core_activity'] as $id => $donation) {
        $entity = crm_core_activity_load($id);
        $current += $entity->field_donation_amounts[LANGUAGE_NONE][0]['value'];
    }  
  }
                      
  $goal = $donation_page['goal'];
  if ($goal == 0 || $goal == '') {
    $goal = (int) ($current / .9);  
  }
  
  $header = unserialize($donation_page['header']);
  $variables = array(
    'title' => $donation_page['title'],
    'message' => strip_tags($header['value']),
    'current' => $current,
    'goal' => $goal,
    'url' => l('Donate', 'donation_pages/' . $donation_page_id, array('absolute' => TRUE, 'attributes' => array('target' => '_blank', 'class' => array('donate'),),)),
    'percentage' => ceil(($current / $goal) * 100),
  );
  
  $output = _crm_core_donation_widget($variables);
  
  echo $output;
  
}

/**
 * Output the donation widget
 */
function _crm_core_donation_widget($v) {
  return '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>Untitled Document</title>
<link rel="stylesheet" type="text/css" href="' . base_path() . drupal_get_path('module', 'crm_core_donation') . '/crm_core_donation_widget.css" />
</head>
<body>
<div id="crm_core_donation_widget" class="donation_page">
	<h2>' . $v['title'] . '</h2>
	<div class="progress">
	<span class="start">$0</span>
	<span class="end">$' . number_format($v['goal']) . '</span>
    <div class="progressbar">
      <div style="width:' . $v['percentage'] . '%"></div>
    </div>
    <div class="current">$' . $v['current'] . ' raised</div>
  </div>
  
    <div class="description">' . $v['message'] . '</div>
    ' . $v['url'] . '
</div>
</body>
</html>';  
}
