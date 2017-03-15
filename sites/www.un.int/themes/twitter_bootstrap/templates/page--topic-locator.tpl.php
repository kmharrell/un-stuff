<div class="un-top">
	<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><img alt="United Nations" src="<?php print drupal_get_path('theme', 'twitter_bootstrap');?>/custom/images/un.png" /></a> 
	<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">Welcome to the United Nations. It&#39;s your world.</a>
	<?php print render($page['top-bar']); ?>
</div>  <!-- un-top -->

<header id="navbar" role="banner" class="navbar">
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
  	   
  	  <?php if ($site_name || $site_slogan): ?>
    		<hgroup id="site-name-slogan">
    		  <?php if ($site_name): ?>
    			<h1>
    			  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="brand"><?php print $site_name; ?></a>
    			</h1>
    		  <?php endif; ?>
    		  
       		</hgroup>
  	  <?php endif; ?>
  	  
  	  <li class="topic-locator right"></li>
  	         
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
		
	<div class="front-main">
	<section class="span12">  
	  <div class="spanmargin">
		  <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="page-header"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

		<?php print $messages; ?>
	   
	   <?php print render($page['content']); ?>
	   
	  
	  </div>
	</section>
	</div>
	
  <footer class="footer container">
    <?php print render($page['footer']); ?>
  </footer>
</div>