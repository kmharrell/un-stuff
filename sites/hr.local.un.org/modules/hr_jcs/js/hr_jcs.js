(function($) {
  Drupal.behaviors.hr_jcs = {
    attach: function(context) {
      var $network = jQuery('select#edit-field-job-network-parent-1, select#edit-field-job-network-deprecated-parent');
      var $family = jQuery('select#edit-field-job-network');
      var $family_opts = $family.find('option');

      var detached = [];
      adjustFamily();
      $network.change(function(e) {
        adjustFamily();
      });

      function adjustFamily() {
        // Reset options.
        if (detached.length > 0) {
          for (var i=0; i<detached.length; i++) {
            $family.append(detached[i]);
          }
          detached = [];
        }

        // Get the select tid
        var $selected = $network.find('option:selected');
        var tid = $selected.val();
        if (tid != 'All') {
          // Get the appropriate tids that should be allowed
          var allowed_tids = Drupal.settings.hr_jcs.hierarchy[tid];

          // Remove non-allowed ones.
          $family_opts.each(function(delta, elem) {
            var elementTid = $(elem).val();
            if (elementTid != 'All') {
              elementTid = parseInt(elementTid);
              if (jQuery.inArray(elementTid, allowed_tids) == -1) {
                var det = $(elem).detach();
                detached.push(det);
              }
            }
          });
        }

        $family.trigger("chosen:updated");
      }
    }
  }
})(jQuery);
