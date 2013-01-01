
<!-- this is a crm core page template -->

<div class="user-nav">
  <div class="container">
    this is where the user information goes
  </div>
</div>
<div class="crm-nav">
  <div class="container">
		<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
		  <img src="<?php print base_path() . path_to_theme() . '/images/crmcorelogo.png'; ?>" style="float: left;" alt="<?php print t('Home'); ?>" />
		</a>
  	<div class="crm-nav-header pull-left">
			CRM Core
  	</div>
    <div class="crm-opts-header pull-right">
      <?php if ($tabs): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
    </div>
  </div>
</div>
<div class="title-container">
  <div class="container">
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
      <h2 class="page-header"><?php print $title; ?></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
  </div>
</div>




<?php if ($page['marquee']): ?>
  <div class="masthead jumbotron">
    <div class="container">
      <?php print render($page['marquee']); ?>
    </div>
  </div>    
<?php endif; ?>  

<div class="container">

  <header role="banner" id="page-header">
    <?php if ( $site_slogan ): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </header> <!-- /#header -->

	<div class="row">
	  
    <?php if ($page['sidebar_first']): ?>
      <aside class="span3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>  
	  
	  <section class="<?php print _twitter_bootstrap_content_span($columns); ?>">
	  
	    <?php if ($page['top']): ?>
	      <?php print render($page['top']); ?>
		  <?php endif; ?>
	  
      <?php print $messages; ?>
        
      <?php if(!$is_front):?>
      
        <?php if ($page['highlighted']): ?>
          <div class="highlighted hero-unit"><?php print render($page['highlighted']); ?></div>
        <?php endif; ?>
        <a id="main-content"></a>
        <?php if ($page['help']): ?> 
          <div class="well"><?php print render($page['help']); ?></div>
        <?php endif; ?>
        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
      <?php endif; ?>
      
      <?php if ($page['above']): ?>
  	  	<!-- TODO: put this in a container -->
        <?php print render($page['above']); ?>
      <?php endif; ?>  
      
      <?php if(!$is_front):?>
	      <?php print render($page['content']); ?>
      <?php endif; ?>  
      
      <?php if ($page['below']): ?>
      	<div class="row">
  		  	<!-- TODO: put this in a container -->
          <?php print render($page['below']); ?>
      	</div>
      <?php endif; ?>  
      
	  </section>

    <?php if ($page['sidebar_second']): ?>
      <aside class="span3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
  
  <?php if ($page['bottom']): ?>
  	<!-- TODO: put this in a container -->
  	<div class="row">
	    <?php print render($page['bottom']); ?>
    </div>
  <?php endif; ?>  
      
  
  <footer class="footer container">
    <?php print render($page['footer']); ?>
  </footer>
</div>


	

