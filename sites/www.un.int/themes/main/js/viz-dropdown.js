(function ($) {
	$(document).ready(function(){
	
	  $('.locator-menu li').each(function() {
	    var $dropdown = $(this);
	
	    $($dropdown).find('a.locator-link').click(function(e) {
	      e.preventDefault();
	      var $div = $($dropdown).find("div.expander");
	      
	      $div.slideToggle(500);
	      $("div.expander").not($div).hide();
	      return false;
	    });
	  });
	    
	  $("div.expander").hide();  
	  
	  $(".quicktabs-views-group:odd").addClass("views-row-odd");                 
	  $(".quicktabs-views-group:even").addClass("views-row-even");   
	  $("#map-canvas").sticky({ topSpacing: 0 });
	  
	});
})(jQuery);
