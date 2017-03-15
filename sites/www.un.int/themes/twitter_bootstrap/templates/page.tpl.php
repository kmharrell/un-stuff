<?php if (user_is_logged_in()): ?>
<nav role="menu-administration-menu" class="menu-administration-menu">
	<span class="menu-administration-icon"></span>
	<?php 
		$region = menu_tree_output(menu_tree_all_data('menu-administration-menu'));
		print render($region)
	?>
</nav>
<?php endif; ?>


<div class="un-top">
	<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><img alt="United Nations" src="/<?php print drupal_get_path('theme', 'twitter_bootstrap');?>/custom/images/un.png" /></a> 
	<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">Welcome to the United Nations. It&#39;s your world.</a>
	<?php print render($page['top-bar']); ?>
</div>  <!-- un-top -->
<header id="navbar" role="banner" class="navbar container">
	<div class="navbar-inner">
	  <div class="container">  
	  
  	  <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
  	  <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
  		<span class="icon-bar"></span>
  		<span class="icon-bar"></span>
  		<span class="icon-bar"></span>
  	  </a>
  	  
  	  <?php if ($logo): ?>
    		<a class="brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
    		  <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
    		</a>
  	  <?php endif; ?>
  	    <a class="brand banner-logo" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
	    		  <?php $block = module_invoke('views', 'block_view', 'about_mission-block_1');
		 	print render($block['content']); 
		?>
	    		  
	    </a>


  	  <?php if ($site_name || $site_slogan): ?>
    		<hgroup id="site-name-slogan">
    		  <?php if ($site_name): ?>
    			<h1>
    			  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="brand"><?php print $site_name; ?></a>
    			</h1>
    		  <?php endif; ?>
    		  
       		</hgroup>
  	  <?php endif; ?>
  	  
  	  
  	  
  	  <div class="nav-collapse">
    	  <nav role="navigation" class="navigation">
      		<?php if ($primary_nav): ?>
      		  <?php print $primary_nav; ?>
      		<?php endif; ?>
      	  
      		<?php if ($search): ?>
      		  <?php if ($search): print render($search); endif; ?>
      		<?php endif; ?>
      		
      		<?php if ($secondary_nav): ?>
      		  <?php print $secondary_nav; ?>
      		<?php endif; ?>
    		</nav>
    		<nav role="secondary-navigation" class="secondary-navigation">
    			<?php 
    				$region = menu_tree_output(menu_tree_all_data('menu-secondary'));
    				print render($region)
    			?>
    		</nav>
  	  </div>         
  	</div>
  </div>
</header>

<div class="container">

  <header role="banner" id="page-header">
    <?php if ( $site_slogan ): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

  </header> <!-- /#header -->
	<div class="row">
	
		<?php if ($is_front): ?>
		
		<?php if ($page['primary_highlighted_block']): ?>
		<section class="span6 front-top">  
		<?php print render($page['primary_highlighted_block']); ?>
		</section>
		<?php endif; ?>
		
		<section class="span3 front-top">
		<div class="spanmargin">
		<?php $block = module_invoke('views', 'block_view', 'about_mission-block');
		 	print render($block['content']); 
		?>
		
	 		<?php $block = module_invoke('views', 'block_view', 'mission_staff-block');
		 	print render($block['content']); 
		?>
		
		</div>
		</section>
		
		<?php if ($page['highlighted_block']): ?>
		<section class="span3 front-top">  
        <?php print render($page['highlighted_block']); ?>
		</section>
		<?php endif; ?>
		
		<?php endif; ?>
		
	<div class="front-main">	  
    <?php if ($page['sidebar_first']): ?>
      <aside class="span3" role="complementary">
      	<div class="spanmargin">
        <?php print render($page['sidebar_first']); ?>
      	</div>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>  
	  
	  <section class="<?php print _twitter_bootstrap_content_span($columns); ?>">  
	  <div class="spanmargin">
      <?php if ($page['highlighted']): ?>
        <div class="highlighted hero-unit"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
     <!--  <?php if ($breadcrumb): print $breadcrumb; endif;?> -->
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="page-header"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if ($tabs): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if ($page['help']): ?> 
        <div class="well"><?php print render($page['help']); ?></div>
      <?php endif; ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
	  </div>
	  </section>
	  
	</div>
    <?php if ($page['sidebar_second']): ?>
      <aside class="span3 second" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
  <footer class="footer container">
    <?php print render($page['footer']); ?>
  </footer>
</div>


	

