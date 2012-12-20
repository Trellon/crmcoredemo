<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <header>
    <?php print render($title_prefix); ?>
    <?php if (!$page && $title): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
  </header>

  <div class="row-fluid">
  	<div class="span7">
  	
  		<div class="row-fluid">
      	<div class="span6"><strong>When:</strong></div>
      	<div class="span6"><strong>Where:</strong></div>
  		</div>
  	
  		<div class="row-fluid">
      	<div class="span6"><strong>Registration:</strong></div>
      	<div class="span6"><strong>Contact:</strong></div>
  		</div>
      <?php
        // Hide comments, tags, and links now so that we can render them later.
        hide($content['crm_core_event_reg_form']);
        hide($content['comments']);
        hide($content['links']);
        hide($content['field_tags']);
        print render($content);
      ?>
  	</div>
  	<div class="span5">
    	<div class="well well-large">
  	    <h3>Register</h3>
  		  <?php print render($content['crm_core_event_reg_form']); ?>
    	</div>
  	</div>
  </div>
  
  
  <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
    <footer>
      <?php print render($content['field_tags']); ?>
      <?php print render($content['links']); ?>
    </footer>
  <?php endif; ?>
  
  
          

</article> <!-- /.node -->
