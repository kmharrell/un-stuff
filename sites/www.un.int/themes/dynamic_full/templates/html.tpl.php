<!DOCTYPE html>
<html lang="<?php print $language->language; ?>">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <!-- HTML5 element support for IE6-8 -->
  <!--[if lt IE 9]>
    <script src="https://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
  <![endif]-->
  <link href='https://fonts.googleapis.com/css?family=Yanone+Kaffeesatz:400,700,300' rel='stylesheet' type='text/css'>
  
  <!--[if lte IE 8]>
		<link rel="stylesheet" type="text/css" href="/<?php print drupal_get_path('theme', 'dynamic_full');?>/custom/ie8-and-down.css" />
	<![endif]-->
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>
