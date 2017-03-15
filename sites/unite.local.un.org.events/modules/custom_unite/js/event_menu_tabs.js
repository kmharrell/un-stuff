(function($) {
  Drupal.behaviors.event_menu_tabs = {
    attach: function(context) {
      $('.field-name-field-menu-tabs input').each(function(iter, elem) {
        if ($(elem).val() == 'home' || $(elem).val() == 'event-content') {
          $(elem).attr('checked', 'checked');
          $(elem).hide();
        }
      });
    }
  }
})(jQuery);