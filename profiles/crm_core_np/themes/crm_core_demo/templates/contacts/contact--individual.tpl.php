<?php 
  // contact.tpl.php
  // generic contact display template
  
  hide($contact_data['field_contact_volunteer']);
  hide($contact_data['field_contact_email']);
  
  // dpm($contact);

?>
<article id="contact-<?php print $type . '-' . $cid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php 
    // first off, add a block that appears to the right
    // this all needs to be in a row for bootstrap
      // needs to have a pic
      // needs to have the name
      // needs to have the location
      // needs to have links for email etc
    // then, add some widgets
      // information about recent event registrations
      // information about donations
      // information about other stuff
      
  ?>
  
  <?php if ($view_mode !== 'full'): ?>
	  <h2<?php print $title_attributes; ?>><a href="<?php print base_path(); ?>crm/contact/<?php print $cid; ?>"><?php print render($contact_data['contact_name']); ?></a></h2>
  <?php endif; ?>

  <?php if ($view_mode === 'full'): ?>
    <div class="row-fluid contact-upper">
    	<div class="span3 contact-details">
    		<div class="contact-picture">
	    		<?php print $pic; ?>
    		</div>
    		<div class="contact-info">
      		<?php print render($contact_data['contact_name']); ?>
      		<?php print $volunteer; ?><br>
      		<?php print $email_button; ?> | <?php print $comments; ?> Comments<br>
      		<?php print $user; ?>
      		<?php print $activity_summary; ?>
    		</div>
  		</div>
  		
    	<div class="span4 contact-activity">
    	  <div class="contact-title-ind">Recent activities</div>
    		<?php print $activities; ?>
    	</div>
  		<div class="span5 contact-overview">
    	  <div class="contact-title-ind">Address</div>
    	  there is a map below it
  		
  		</div>
    </div>
  
    <div class="row-fluid contact-lower">
    
    	<div class="span3 contact-address">
    	</div>
    	<div class="span3 contact-other">
      	  <?php print render($contact_data); ?>
    	</div>
    
    </div>
  <?php endif; ?>
  
</article>