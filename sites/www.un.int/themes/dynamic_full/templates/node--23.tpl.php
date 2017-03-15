<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
	
	 <div class="span3" style="margin:0 20px 0 0;">
	 
	 	<section class="permanent_representative">
	 	<h3>Permanent Representative</h3>
	 		<?php $block = module_invoke('views', 'block_view', 'mission_staff-block');
		 	print render($block['content']); 
		?>
	 		
	 	</section>
	 	
	 		
	 </div>
	 
	 <div class="span6" style="margin:0px;">
	 	
      	<section class="permanent_representative_message">
	      	
	 		<?php $block = module_invoke('views', 'block_view', 'mission_staff-block_1');
		 	print render($block['content']); 
		?>
	 		
	 	</section>
	 </div>
	 	
	 	<div class="span9 staff-thum">
		     <?php $block = module_invoke('views', 'block_view', 'mission_staff-block_2');
			 	print render($block['content']); 
			?>
	 	</div>
	 
</article>
