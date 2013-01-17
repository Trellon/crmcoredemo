<?php

/**
 * @file
 * Default display of reports for CRM Core
 *
 * Available variables:
 * 
 * - $reports: associative array listing all reports available
 *   in the system. Each entry is an array with the following keys:
 *   - title: A title for the report grouping.
 *   - reports: A list of the reports to be found. This is an array
 *     keyed by individual reports, and includes the following keys:
 *     - title: title for the report
 *     - description: a description of the report
 *     - path: a path to the report
 *   - widgets: A list of widgets indexed by CRM Core.
 */

  // dressing the reports page up to make it fancier
  // by separating reports out into two columns.
  // we are setting some important reports to appear at the top of each column,
  // then displaying the rest of the reports below. This should be in a preprocessing
  // function, but we are doing it here so people can see what is going on.
  
	  $donations = $reports['donations'];
    $donations = theme('crm_core_report_index_item', array('title' => $donations['title'], 'report' => $donations['reports']));
	  unset($reports['donations']);
  
	  $volunteer = $reports['volunteer'];
    $volunteer = theme('crm_core_report_index_item', array('title' => $volunteer['title'], 'report' => $volunteer['reports']));
	  unset($reports['volunteer']);
	  
	  $first = array();
	  $second = array();
	  
	  $counter = sizeof($reports);
	  
	  foreach($reports as $item => $val){
	    if($counter%3){
	      $first[$item] = $val; 
	    } else {
	      $second[$item] = $val; 
	    }
	    $counter--;
	  }
?>
<div class="crm_core_reports">
	<div class="row-fluid">
		<div class="span6">
		
			<?php 
			  print $donations;
    	  foreach($first as $item => $listing){
    	    print theme('crm_core_report_index_item', array('title' => $first[$item]['title'], 'report' => $first[$item]['reports']));
    	  }
			?>
		
		</div>
		<div class="span6">
			<?php 
			  print $volunteer;
    	  foreach($second as $item => $listing){
    	    print theme('crm_core_report_index_item', array('title' => $second[$item]['title'], 'report' => $second[$item]['reports']));
    	  }
			?>
		
		</div>
	
	</div>

</div>
