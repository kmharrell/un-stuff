(function ($) {

  Drupal.behaviors.custom_unite_web_about_form = {
    attach: function (context, settings) {
      var locked_checkboxes = ["218", "731", "629"];
      $('.field-name-field-main-menu input[type="checkbox"]').each(function(key, item) {
        var cbVal = $(item).attr('value');
        if (locked_checkboxes.indexOf(cbVal) != -1) {
	      $(item).select();
	      $(item).click(function() {
	        return false;
	      });
        }
      });
    }
  };

})(jQuery);