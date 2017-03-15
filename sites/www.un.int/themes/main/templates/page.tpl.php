<header id="navbar" role="banner" class="navbar">
	  <div class="container navbarcontainer">
	  
	   <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
      <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </a>
	  
	  <?php print render($page['top-bar']); ?>
  	  
  	  <?php if ($logo): ?>
    		<a class="brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
    		  <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
    		</a>
  	  <?php endif; ?>
  	   
  	  <?php if ($site_name || $site_slogan): ?>
    		<hgroup id="site-name-slogan">
    		  <?php if ($site_name): ?>
    			<h1>
    			  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="brand"><?php print $site_name; ?></a>
    			</h1>
    		  <?php endif; ?>
    		  
       		</hgroup>
  	  <?php endif; ?>
  	  
  	  
  	  <?php if ($page['header']): ?>
        <?php print render($page['header']); ?>
      <?php endif; ?>
      <div class="nav-collapse">
    	  <nav role="navigation" class="navigation">            
            <?php if (!empty($secondary_nav)): ?>
              <?php print render($secondary_nav); ?>
            <?php endif; ?>
            <?php if (!empty($page['navigation'])): ?>
              <?php print render($page['navigation']); ?>
            <?php endif; ?>
            
            <?php if ($is_memberstates): ?>
            <section class="locator-menu">	  	  	
		  	  	<li class="home-locator"><a href="http://www.un.int">un.int</a></li>
		  	  	<li class="home-locator"><a href="<?php print $front_page; ?>">Member States</a></li>
		  	  	<li class="topic-locator">
		  	  		<a href="#" class="locator-link">Topics</a>
		  	  		 <div class="expander">
			  	  		<?php $block = module_invoke('views', 'block_view', 'topic_json-block_1');
					 		print render($block['content']); 
					 	?>
		  	  		 </div>
		  	  	</li>
		  	  	
		  	  	<li class="committee-locator">
		  	  		<a href="#" class="locator-link">Committees </a>
		  	  		<div class="expander">
		  	  		 	<?php $block = module_invoke('views', 'block_view', 'committee_json-block_1');
					 		print render($block['content']); 
					 	?>
		  	  		 </div>
		  	  	</li>
	  	  	
	  	   </section>
	  	   <div class="search-any">
	  	  	<h3>Search<span>All Missions</span></h3>
			<?php $block = module_invoke('views', 'block_view', '-exp-search-page_6');
			 	print render($block['content']); 
			?>
	  	   </div>
	  	   <?php endif; ?>

          </nav>
      </div>
  	 </div> <!-- container --> 
</header>

<div class="container">

  <header role="banner" id="page-header">
    <?php if ( $site_slogan ): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

  </header> <!-- /#header -->
	
	<div class="row">
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
	
	 <?php if ($page['sidebar_second']): ?>
      <aside class="span3 second" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>
    
	
  <footer class="footer container">
    <?php print render($page['footer']); ?>
  </footer>
</div>