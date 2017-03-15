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
    <div class="container">
      <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
      <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </a>

        <a class="brand logo pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
		  	<?php $block = module_invoke('views', 'block_view', 'about_mission-block_6');
		 		print render($block['content']); 
		 	?>	  
        </a>      
      <a class="brand banner-logo" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
	    		  <?php $block = module_invoke('views', 'block_view', 'about_mission-block_1');
		 	print render($block['content']); ?>	  
	  </a>

      <?php if (!empty($site_name)): ?>
      <hgroup id="site-name-slogan">
        <h1 id="site-name">
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="brand"><?php print $site_name; ?></a>
        </h1>
      </hgroup>
      <?php endif; ?>

      <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
        <div class="nav-collapse">
    	  <nav role="navigation" class="navigation">
            <?php if (!empty($domain_menu)): ?>
              <?php print render($domain_menu); ?>
            <?php endif; ?>
            
            <?php if (!empty($secondary_nav)): ?>
              <?php print render($secondary_nav); ?>
            <?php endif; ?>
            <?php if (!empty($page['navigation'])): ?>
              <?php print render($page['navigation']); ?>
            <?php endif; ?>
          </nav>
<!--
          <nav role="secondary-navigation" class="secondary-navigation">
    			<?php 
    				$region = menu_tree_output(menu_tree_all_data('menu-secondary'));
    				print render($region)
    			?>
    		</nav>
-->
        </div>
      <?php endif; ?>
    </div>
</header>

<div class="main-container container">

  <header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </header> <!-- /#header -->

  <div class="row">
  
  
  	<?php if ($is_front): ?>
		
		<?php if ($page['primary_highlighted_block']): ?>
		<section class="span12 front-top">  
		<?php print render($page['primary_highlighted_block']); ?>
		</section>
		<?php endif; ?>
	

	<?php endif; ?>
  

    <div class="front-main">
    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="span3" role="complementary">
      	<div class="spanmargin">
        <?php print render($page['sidebar_first']); ?>
      	</div>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>  

    <section class="<?php print _bootstrap_content_span($columns); ?>">
    <div class="spanmargin">
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted hero-unit"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
        <h1 class="page-header"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <div class="well"><?php print render($page['help']); ?></div>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </div>
    </section>

	</div> <!-- front-main -->
    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="span3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
</div>
<footer class="footer container">
  <?php print render($page['footer']); ?>
</footer>
