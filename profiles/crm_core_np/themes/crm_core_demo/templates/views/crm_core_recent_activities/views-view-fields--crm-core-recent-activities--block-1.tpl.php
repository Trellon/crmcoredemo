<?php

/**
 * @file
 * Displays individual activity records.
 * 
 * Besides the typical views variables, this file uses several variables
 * set as part of hook_views_pre_render in template.php.
 * 
 * The custom variables include:
 * 
 * - $row: Adding some variables
 *   - $row->icon-class: custom class for displaying icons
 *   - $row->activity_desc: a string of text summarizing the activity
 *
 * @ingroup views_templates
 * @see template.php
 */

	// TODO: remove debug inforamtion
	// dpm($variables);
	// dpm(array_keys(get_defined_vars()));
	// dpm($view);
	// dpm($variables);
	// dpm($row);
	// dpm($fields);
	// dpm($view);
	// dpm($yoyoyo);
	// dpm($row);
	
?>
<div class="activity_icon <?php print $row->icon_class; ?>"></div>
<div class="activity_desc clearfix">
	<?php print $row->activity_desc; ?>
	<div class="activity_date"><?php print $fields['field_activity_date']->content; ?></div>
</div>


