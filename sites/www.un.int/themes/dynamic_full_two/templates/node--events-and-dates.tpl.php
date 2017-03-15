<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
	<div class="share-this">
		<ul>
			<li class="facebook_share"><a href="http://www.facebook.com/sharer/sharer.php?u=<?php global $base_url; print $base_url . '/' .$node_url; ?>">Facebook</a></li>
			<li class="twitter_share"><a href="https://twitter.com/intent/tweet?url=<?php global $base_url; print $base_url . '/' .$node_url; ?>">Twitter</a></li>
			<li class="googleplus_share"><a href="https://plus.google.com/u/0/share?url=<?php global $base_url; print $base_url . '/' .$node_url; ?>">Google Plus</a></li>
			<li class="linkedin_share"><a href="http://www.linkedin.com/shareArticle?mini=true&url=<?php global $base_url; print $base_url . '/' .$node_url; ?>">Linkedin</a></li>
		</ul>
	</div>
	 	 

	 	<?php if($view_mode == 'teaser') { ?>
	 <header>
    <?php print render($title_prefix); ?>
    <?php if (!$page && $title): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <?php if ($display_submitted): ?>
      <span class="submitted">
        <?php print $user_picture; ?>
        <?php print $submitted; ?>
      </span>
    <?php endif; ?>
  </header>

  <?php
    // Hide comments, tags, and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_tags']);
    print render($content);
  ?>

  <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
    <footer>
      <?php print render($content['field_tags']); ?>
      <?php print render($content['links']); ?>
    </footer>
  <?php endif; ?>

  <?php print render($content['comments']); ?>
  
  <?php 
  } else { ?>
	  
  
	 	
	 	
	 	<section class="event-header">
	 		<?php print render($title_prefix); ?>    
	 		 <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
	 		 <?php print render($title_suffix); ?>
	 		 <?php print render($content['field_events_date']); ?>	 
	 	</section>
	 	
	 	<div class="span5" style="margin:0px;">
	 	 	
	 	<section class="event-map">
	 	
	 	<?php print render($content['field_location_map']); ?>	 	
	 
	 	</section>

	 	</div>
	 	
	 	<div class="span4" style="margin:0px;">
	 	 	
	 	<section class="event-info">
	 	<?php print render($content['field_events_location']); ?>
	 	<?php print render($content['field_events_attachments']); ?>
	 	<?php print render($content['field_events_related_links']); ?>
	 	<?php print render($content['field_relevant_un_committees']); ?>
	 	<?php print render($content['field_un_themes']); ?>	 	
	 
	 	</section>

	 	</div>
	 		
	 
	 <div class="span5" style="margin:30px 0 0 0;">
	 	 	
	 	<section class="event-text">
	 	
	 	<?php print render($content['body']); ?>	 	
	 
	 	</section>

	 </div>
	 
	  <div class="span4" style="margin:30px 0 0 0;">
	 	 	
	 	<section class="event-media">
	 	
	 	<?php print render($content['field_related_media']); ?>	 	
	 
	 	</section>

	 </div>
	 
	 <?php } ?>
	 
  
	 
</article>


