(function ($) {
  $(document).ready(function(){



    $("#timeline-show").click(function(){
      $("#block-views-programme-of-the-day-block-3").slideToggle(500);
      window.dispatchEvent(new Event('resize'));
      return false;

    });


  });
})(jQuery);
;
