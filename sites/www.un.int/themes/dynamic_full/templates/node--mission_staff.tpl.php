<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
	
	 <div class="span3" style="margin:0 20px 0 0;">
	 
	 	<section class="staff_photo">
	 		<?php print render($content['field_mission_staff_image']); ?>
	 		<?php print render($title_prefix); ?>    
	 		 <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
      	<?php print render($title_suffix); ?>
	 	</section>
	 	
	 		
	 </div>
	 
	 <div class="span6" style="margin:0px;">
	 	
      	<section class="staff-info">
	 	<?php print render($content['field_mission_staff_posted_date']); ?>
	 	<?php print render($content['field_mission_sta_qualifications']); ?>
	 	<?php print render($content['field_mission_staff_work_history']); ?>
	 	<?php print render($content['field_mission_staff']); ?>
	 	</section>
	 	
	 	<section class="permanent-repre">
	 	
	 	<?php print render($content['field_mission_staff_message']); ?>	 	
	 
	 	</section>

	 </div>
	 
</article>
