<section id="comments" class="<?php print $classes; ?>"<?php print $attributes; ?>>  
  <?php if ($content['comment_form']): ?>
    <section id="comment-form-wrapper" class="well">
      <h3 class="title"><?php print t('Add new comment'); ?></h3>
      <?php print render($content['comment_form']); ?>
    </section> <!-- /#comment-form-wrapper -->
  <?php endif; ?>
  
  <?php if ($content['comments'] && $node->type != 'forum'): ?>
  	<section class="comments-view">
    <?php print render($title_prefix); ?>
    <h2 class="title"><?php print t('Comments'); ?></h2>
    <?php print render($title_suffix); ?>
  	</section>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

  
</section> <!-- /#comments -->
