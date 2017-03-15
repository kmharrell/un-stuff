Drupal.behaviors.mapViz = {
  attach: function (context, settings) {
    var origCenter = new google.maps.LatLng(19, 18.764648);
    var currCenter = new google.maps.LatLng(0, 0);
    var selectedLoc = {
      marker: null,
      location: null
    };
    var origZoom = 2;
    var dragging = false;

    function initialize() {
      var mapOptions = {
        center: origCenter,
        zoom: origZoom,
        mapTypeId: google.maps.MapTypeId.ROADMAP
      };
      var map = new google.maps.Map(document.getElementById("map-canvas"), mapOptions);

      var styles = [
        {
          featureType: "all",
          elementType: "labels",
          stylers: [
            { visibility: "off" }
          ]
        }/*,
        {
          featureType: "administrative",
          elementType: "all",
          stylers: [
            { visibility: "off" }
          ]
        }*/
      ];
      
      map.setOptions({styles: styles});

      var alphabet = [];
      var lastInitial = null;
      var infowindow = new google.maps.InfoWindow();
      for (var i = 0; (i<locations.nodes.length); i++) {
        var location = locations.nodes[i].node;

		var $list = jQuery("#list");
		var initial = location.gid.split('')[0].toUpperCase();
		var inAlphabet = false;
		if (inAlphabet === false && lastInitial != initial) {
			alphabet.push(initial);
			lastInitial = initial;
		}
		
        $list.append("<div class='list-item' id='list-"+location.did+"'> <img src='"+location.field_flag+"'/><h4>"+location.gid+"</h4></div>");
        var listItem = document.getElementById('list-'+location.did);

        var marker = new google.maps.Marker({
          position: new google.maps.LatLng(location.field_mission_location, location.field_mission_location_1),
          map: map
        });

        ///// MARKERS
        // Marker Hover
        google.maps.event.addListener(marker, 'mouseover', (function(location, listItem, marker) {
          return function() {
            var coords = new google.maps.LatLng(location.field_mission_location, location.field_mission_location_1);
            infoWindowOpener(location, marker);
          }
        })(location, listItem, marker));
        // Marker Click
        google.maps.event.addListener(marker, 'click', (function(location, listItem, marker) {
          return function() {
            jQuery('.selected').removeClass("selected");
            var coords = new google.maps.LatLng(location.field_mission_location, location.field_mission_location_1);
            goTo(coords, 4, true)
            jQuery(listItem).addClass("selected");
          }
        })(location, listItem, marker));

        ///// LIST ITEMS
        // ListItem Hover
        google.maps.event.addDomListener(listItem, 'mouseover', (function(location, listItem, marker) {
          return function() {
            var coords = new google.maps.LatLng(location.field_mission_location, location.field_mission_location_1);
            
            jQuery('.selected').removeClass("selected");
            jQuery(listItem).addClass("selected");
            selectedLoc.marker = marker;
            selectedLoc.location = location;
            if (!alreadyThere(coords) && !dragging) {
              goTo(coords, 4, true);
              infoWindowOpener(location, marker);
            }
          }
        })(location, listItem, marker));
        // ListItem Click 
        google.maps.event.addDomListener(listItem, 'click', (function(location, listItem, marker) {
          return function() {
            window.location = location.link;
          }
        })(location, listItem, marker));
        // ListItem Mouseout
        google.maps.event.addDomListener(listItem, 'mouseout', (function(location, listItem, marker) {
          return function() {
          }
        })(location, listItem, marker));

        google.maps.event.addListener(map, 'dragstart', function() {
          dragging = true;
          infowindow.close();
        });
        google.maps.event.addListener(map, 'dragend', function() {
          newCenter(map.getCenter());
          dragging = false;
          jQuery('.selected').removeClass("selected");
        });
        function alreadyThere(coords) {
          if (coords != undefined) {
            currCenter = coords;
          }
          if (currCenter.lat() == origCenter.lat() && currCenter.lng() == origCenter.lng()) {
            return true;
          }
          else {
            return false;
          }
        }
        function goTo(coords, zoom, sticky) {
          map.panTo(coords);
          map.setZoom(zoom);
          currCenter = coords;
          if (sticky === true) {
            newCenter(coords);
          }
        }
        function newCenter(coords) {
          origCenter = coords;
          origZoom = 4;
        }
        function infoWindowOpener(location, marker) {
          infowindow.setContent(infoContentGenerator(location));
          infowindow.open(map, marker);
        }

        //google.maps.event.addListener(infowindow, 'domready', function() {
        //});
      }
      var alphabetLinks = '<ul id="mapglossary">';
      for (var i=0; i<alphabet.length; i++) {
	      alphabetLinks += '<li><a href="#">'+alphabet[i]+'</a></li>';
      }
      alphabetLinks += '<li><a href="#">Show All</a></li>';
      alphabetLinks += '</ul>';
      jQuery('#list').before(alphabetLinks);
      jQuery('#mapglossary a').click(function() {
        var text = jQuery(this).text();
        if (text == 'Show All') { 
          jQuery('#list .list-item').show();
        }
        else {
          var letter = jQuery(this).text().split('')[0];
          jQuery('#list .list-item').hide();
          jQuery('#list .list-item').each(function (key, value) {
            
            
            var initial = jQuery.trim(jQuery(value).text());
            initial = initial.split('')[0];
            if (initial == letter) {
              jQuery('#list .list-item').eq(key).show();
            }
          });
        }
        return false;
      });
    };
    function infoContentGenerator(item) {
      var admissionYear;
      if (item.admission) {
        admissionYear = item.admission.substring(0, 10);
      }
      
      var output = '<div id="info_container">';
      output += '<div id="info_flag"><a href="'+item.link+'"><img src="'+item.field_flag+'"></a></div>';
      output += '<div class="infoboxContent">';
      output += '<a href="'+item.link+'">'+item.gid+'</a>';
      output += '<div class="address">'+item.address+'</div>';
      if (item.mission_tel) {
        output += '<div class="tel">'+item.mission_tel.replace(/\n/g, "<br />");+'</div>';
      }
      if (admissionYear) { 
        output += '<div class="admission">Admitted '+admissionYear+'</div>';
      }
      output += '</div>';
      output += '</div>';
      return output;
    }
    function compareLocations(a, b) {
	    if (a.node.gid.toLowerCase() < b.node.gid.toLowerCase()) {
		    return -1;
	    }
	    if (a.node.gid.toLowerCase() > b.node.gid.toLowerCase()) {
		    return 1;
	    }
	    return 0;
    }
    
    // Make AJAX request to get Data
    var locations = {};
    var locations1 = {};
    var locations2 = {};
    var xhr = jQuery.get('list_json', function(data) {
      locations1 = data;
      var output = [];
      var lastLoc = null;  
      for (var i=0; i<locations1.nodes.length; i++) {
        if (lastLoc == locations1.nodes[i].node.gid) {
          for (var key in locations1.nodes[i].node) {
            if (locations1.nodes[(i-1)].node[key] === null) {
              locations1.nodes[(i-1)].node[key] = locations1.nodes[i].node[key];
            }
          }
        }
        else {
          output.push(locations1.nodes[i]);
        }
        lastLoc = locations1.nodes[i].node.gid;
      }
      locations1.nodes = output;
      delete output;
      var xhr2 = jQuery.get('external_missions', function(data) {
        locations2 = data;
        locations.nodes = locations1.nodes.concat(locations2.nodes);
        delete locations1;
        delete locations2;
        locations.nodes = locations.nodes.sort(compareLocations);
        // If success, initialize the whole thing.
        initialize();			
      });
    });
    xhr.fail(function() {
      console.log("Unable to obtain JSON data.");
    })
  }
};