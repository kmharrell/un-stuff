<div class="un-top">
	<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><img alt="United Nations" src="/<?php print drupal_get_path('theme', 'twitter_bootstrap');?>/custom/images/un.png" /></a> 
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
  	  
  	   <?php if ($page['header']): ?>
        <?php print render($page['header']); ?>
      <?php endif; ?>
  	  
  	  <section class="locator-menu">
  	  	<li class="topic-locator"><a href="#viewport"></a></li>
  	  	<!-- <li class="committee-locator"><a href="#viewport-committee"></a></li> -->
  	  </section>
  	  
  	         
  	</div>
  </div>
</header>

<canvas id="viewport"></canvas>

<!-- <canvas id="viewport-committee"></canvas> -->
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
		
		<?php print $messages; ?>
		
		<section class="committees">
		<h1>Committees</h1>
			<li><a href="info?f[0]=field_relevant_un_committees%3A63">First Committee (Disarmament & International Security)</a></li>
			<li><a href="info?f[0]=field_relevant_un_committees%3A64">Second Committee (Economic & Financial)</a></li>
			<li><a href="info?f[0]=field_relevant_un_committees%3A65">Third Committee (Social, Humanitarian & Cultural)</a></li>
			<li><a href="info?f[0]=field_relevant_un_committees%3A66">Fourth Committee (Special Political & Decolonization)</a></li>
			<li><a href="info?f[0]=field_relevant_un_committees%3A67">Fifth Committee (Administrative & Budgetary)</a></li>
			<li><a href="info?f[0]=field_relevant_un_committees%3A68">Sixth Committee (Legal)</a></li>
		</section>
		
		
	  
	  </div>
	</section>
	</div>
	<script src="/<?php print drupal_get_path('theme', 'twitter_bootstrap');?>/search_viz/lib/arbor.js"></script>
  <script src="/<?php print drupal_get_path('theme', 'twitter_bootstrap');?>/search_viz/lib/arbor-graphics.js"></script>
  <script src="/<?php print drupal_get_path('theme', 'twitter_bootstrap');?>/search_viz/lib/arbor-tween.js"></script>

  <script src="/<?php print drupal_get_path('theme', 'twitter_bootstrap');?>/search_viz/topic.js"></script>
  <script src="/<?php print drupal_get_path('theme', 'twitter_bootstrap');?>/search_viz/committee.js"></script>
  
	
	
	
  <footer class="footer container">
    <?php print render($page['footer']); ?>
  </footer>
</div>
