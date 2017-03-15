(function ($) {

/**
 * A progressbar object. Initialized with the given id. Must be inserted into
 * the DOM afterwards through progressBar.element.
 *
 * method is the function which will perform the HTTP request to get the
 * progress bar state. Either "GET" or "POST".
 *
 * e.g. pb = new progressBar('myProgressBar');
 *      some_element.appendChild(pb.element);
 */
Drupal.progressBar = function (id, updateCallback, method, errorCallback) {
  var pb = this;
  this.id = id;
  this.method = method || 'GET';
  this.updateCallback = updateCallback;
  this.errorCallback = errorCallback;

  // The WAI-ARIA setting aria-live="polite" will announce changes after users
  // have completed their current activity and not interrupt the screen reader.
  this.element = $('<div class="progress-wrapper" aria-live="polite"></div>');
  this.element.html('<div id ="' + id + '" class="progress progress-striped active">' +
                    '<div class="progress-bar" role="progressbar" aria-valuemin="0" aria-valuemax="100" aria-valuenow="0">' +
                    '<div class="percentage sr-only"></div>' +
                    '</div></div>' +
                    '</div><div class="percentage pull-right"></div>' +
                    '<div class="message">&nbsp;</div>');
};

/**
 * Set the percentage and status message for the progressbar.
 */
Drupal.progressBar.prototype.setProgress = function (percentage, message) {
  if (percentage >= 0 && percentage <= 100) {
    $('div.progress-bar', this.element).css('width', percentage + '%');
    $('div.progress-bar', this.element).attr('aria-valuenow', percentage);
    $('div.percentage', this.element).html(percentage + '%');
  }
  $('div.message', this.element).html(message);
  if (this.updateCallback) {
    this.updateCallback(percentage, message, this);
  }
};

/**
 * Start monitoring progress via Ajax.
 */
Drupal.progressBar.prototype.startMonitoring = function (uri, delay) {
  this.delay = delay;
  this.uri = uri;
  this.sendPing();
};

/**
 * Stop monitoring progress via Ajax.
 */
Drupal.progressBar.prototype.stopMonitoring = function () {
  clearTimeout(this.timer);
  // This allows monitoring to be stopped from within the callback.
  this.uri = null;
};

/**
 * Request progress data from server.
 */
Drupal.progressBar.prototype.sendPing = function () {
  if (this.timer) {
    clearTimeout(this.timer);
  }
  if (this.uri) {
    var pb = this;
    // When doing a post request, you need non-null data. Otherwise a
    // HTTP 411 or HTTP 406 (with Apache mod_security) error may result.
    $.ajax({
      type: this.method,
      url: this.uri,
      data: '',
      dataType: 'json',
      success: function (progress) {
        // Display errors.
        if (progress.status == 0) {
          pb.displayError(progress.data);
          return;
        }
        // Update display.
        pb.setProgress(progress.percentage, progress.message);
        // Schedule next timer.
        pb.timer = setTimeout(function () { pb.sendPing(); }, pb.delay);
      },
      error: function (xmlhttp) {
        pb.displayError(Drupal.ajaxError(xmlhttp, pb.uri));
      }
    });
  }
};

/**
 * Display errors on the page.
 */
Drupal.progressBar.prototype.displayError = function (string) {
  var error = $('<div class="alert alert-block alert-error"><a class="close" data-dismiss="alert" href="#">&times;</a><h4>Error message</h4></div>').append(string);
  $(this.element).before(error).hide();

  if (this.errorCallback) {
    this.errorCallback(this);
  }
};

})(jQuery);
;
(function ($) {

  Drupal.behaviors.autologout = {
    attach: function(context, settings) {

      if (context != document) {
        return;
      }

      var paddingTimer;
      var t;
      var theDialog;
      var localSettings;

      // Activity is a boolean used to detect a user has
      // interacted with the page.
      var activity;

      // Timer to keep track of activity resets.
      var activityResetTimer;

      // Prevent settings being overriden by ajax callbacks by cloning the settings.
      localSettings = jQuery.extend(true, {}, settings.autologout);

      if (localSettings.refresh_only) {
        // On pages that cannot be logged out of don't start the logout countdown.
        t = setTimeout(keepAlive, localSettings.timeout);
      }
      else {
        // Set no activity to start with.
        activity = false;

        // Bind formUpdated events to preventAutoLogout event.
        $('body').bind('formUpdated', function(event) {
          $(event.target).trigger('preventAutologout');
        });

        // Support for CKEditor.
        if (typeof CKEDITOR !== 'undefined') {
          CKEDITOR.on('instanceCreated', function(e) {
            e.editor.on('contentDom', function() {
              e.editor.document.on('keyup', function(event) {
                // Keyup event in ckeditor should prevent autologout.
                $(e.editor.element.$).trigger('preventAutologout');
              });
            });
          });
        }

        $('body').bind('preventAutologout', function(event) {
          // When the preventAutologout event fires
          // we set activity to true.
          activity = true;

          // Clear timer if one exists.
          clearTimeout(activityResetTimer);

          // Set a timer that goes off and resets this activity indicator
          // after a minute, otherwise sessions never timeout.
          activityResetTimer = setTimeout(function () {
            activity = false;
          }, 60000);
        });

        // On pages where the user can be logged out, set the timer to popup
        // and log them out.
        t = setTimeout(init, localSettings.timeout);
      }

      function init() {
        var noDialog = Drupal.settings.autologout.no_dialog;

        if (activity) {
          // The user has been active on the page.
          activity = false;
          refresh();
        }
        else {

          // The user has not been active, ask them if they want to stay logged in
          // and start the logout timer.
          paddingTimer = setTimeout(confirmLogout, localSettings.timeout_padding);

          // While the countdown timer is going, lookup the remaining time. If there
          // is more time remaining (i.e. a user is navigating in another tab), then
          // reset the timer for opening the dialog.
          Drupal.ajax['autologout.getTimeLeft'].autologoutGetTimeLeft(function(time) {
              if (time > 0) {
                clearTimeout(paddingTimer);
                t = setTimeout(init, time);
              }
              else {
                // Logout user right away without displaying a confirmation dialog.
                if (noDialog) {
                  logout();
                  return;
                }
                theDialog = dialog();
              }
          });
        }
      }

      function dialog() {
        var buttons = {};
        buttons[Drupal.t('Yes')] = function() {
          $(this).dialog("destroy");
          clearTimeout(paddingTimer);
          refresh();
        };

        buttons[Drupal.t('No')] = function() {
          $(this).dialog("destroy");
          logout();
        };

        return $('<div id="autologout-confirm"> ' +  localSettings.message + '</div>').dialog({
          modal: true,
               closeOnEscape: false,
               width: "auto",
               dialogClass: 'autologout-dialog',
               title: localSettings.title,
               buttons: buttons,
               close: function(event, ui) {
                 logout();
               }
        });
      }

      // A user could have used the reset button on the tab/window they're actively
      // using, so we need to double check before actually logging out.
      function confirmLogout() {
        $(theDialog).dialog('destroy');

        Drupal.ajax['autologout.getTimeLeft'].autologoutGetTimeLeft(function(time) {
          if (time > 0) {
            t = setTimeout(init, time);
          }
          else {
            logout();
          }
        });
      }

      function logout() {
        if (localSettings.use_alt_logout_method) {
          window.location = Drupal.settings.basePath + "?q=autologout_ahah_logout";
        }
        else {
          $.ajax({
            url: Drupal.settings.basePath + "?q=autologout_ahah_logout",
            type: "POST",
            success: function() {
              window.location = localSettings.redirect_url;
            },
            error: function(XMLHttpRequest, textStatus) {
              if (XMLHttpRequest.status == 403 || XMLHttpRequest.status == 404) {
                window.location = localSettings.redirect_url;
              }
            }
          });
        }
      }

      /**
       * Use the Drupal ajax library to handle get time remaining events
       * because if using the JS Timer, the return will update it.
       *
       * @param function callback(time)
       *   The function to run when ajax is successful. The time parameter
       *   is the time remaining for the current user in ms.
       */
      Drupal.ajax.prototype.autologoutGetTimeLeft = function(callback) {
        var ajax = this;

        if (ajax.ajaxing) {
          return false;
        }

        ajax.options.success = function (response, status) {
          if (typeof response == 'string') {
            response = $.parseJSON(response);
          }

          if (typeof response[1].command === 'string' && response[1].command == 'alert') {
            // In the event of an error, we can assume
            // the user has been logged out.
            window.location = localSettings.redirect_url;
          }

          callback(response[2].settings.time);

          // Let Drupal.ajax handle the JSON response.
          return ajax.success(response, status);
        };

        try {
          $.ajax(ajax.options);
        }
        catch (e) {
          ajax.ajaxing = false;
        }
      };

      Drupal.ajax['autologout.getTimeLeft'] = new Drupal.ajax(null, $(document.body), {
        url: Drupal.settings.basePath  + '?q=autologout_ajax_get_time_left',
        event: 'autologout.getTimeLeft',
        error: function(XMLHttpRequest, textStatus) {
          // Disable error reporting to the screen.
        }
      });

      /**
       * Use the Drupal ajax library to handle refresh events
       * because if using the JS Timer, the return will update
       * it.
       *
       * @param function timerFunction
       *   The function to tell the timer to run after its been
       *   restarted.
       */
      Drupal.ajax.prototype.autologoutRefresh = function(timerfunction) {
        var ajax = this;

        if (ajax.ajaxing) {
          return false;
        }

        ajax.options.success = function (response, status) {
          if (typeof response == 'string') {
            response = $.parseJSON(response);
          }

          if (typeof response[1].command === 'string' && response[1].command == 'alert') {
            // In the event of an error, we can assume
            // the user has been logged out.
            window.location = localSettings.redirect_url;
          }

          t = setTimeout(timerfunction, localSettings.timeout);
          activity = false;

          // Let Drupal.ajax handle the JSON response.
          return ajax.success(response, status);
        };

        try {
          $.ajax(ajax.options);
        }
        catch (e) {
          ajax.ajaxing = false;
        }
      };

      Drupal.ajax['autologout.refresh'] = new Drupal.ajax(null, $(document.body), {
        url: Drupal.settings.basePath  + '?q=autologout_ahah_set_last',
        event: 'autologout.refresh',
        error: function(XMLHttpRequest, textStatus) {
          // Disable error reporting to the screen.
        }
      });

      function keepAlive() {
        Drupal.ajax['autologout.refresh'].autologoutRefresh(keepAlive);
      }

      function refresh() {
        Drupal.ajax['autologout.refresh'].autologoutRefresh(init);
      }

      // Check if the page was loaded via a back button click.
      var $dirty_bit = $('#autologout-cache-check-bit');
      if ($dirty_bit.length !== 0) {

        if ($dirty_bit.val() == '1') {
          // Page was loaded via a back button click, we should
          // refresh the timer.
          refresh();
        }

        $dirty_bit.val('1');
      }
    }
  };
})(jQuery);
;
/******************************************************************************************************************************

 * @ Original idea by by Binny V A, Original version: 2.00.A 
 * @ http://www.openjs.com/scripts/events/keyboard_shortcuts/
 * @ Original License : BSD
 
 * @ jQuery Plugin by Tzury Bar Yochay 
        mail: tzury.by@gmail.com
        blog: evalinux.wordpress.com
        face: facebook.com/profile.php?id=513676303
        
        (c) Copyrights 2007
        
 * @ jQuery Plugin version Beta (0.0.3)
 * @ License: jQuery-License.
 
TODO:
    add queue support (as in gmail) e.g. 'x' then 'y', etc.
    add mouse + mouse wheel events.

USAGE:
    $.hotkeys.add('Ctrl+c', function(){ alert('copy anyone?');});
    $.hotkeys.add('Ctrl+c', {target:'div#editor', type:'keyup', propagate: true},function(){ alert('copy anyone?');});>
    $.hotkeys.remove('Ctrl+c'); 
    $.hotkeys.remove('Ctrl+c', {target:'div#editor', type:'keypress'}); 
    
******************************************************************************************************************************/
(function (jQuery) {

  this.version = '(beta)(0.0.3)';

  this.all = {};

  this.special_keys = {
    27: 'esc', 9: 'tab', 32:'space', 13: 'return', 8:'backspace', 145: 'scroll', 20: 'capslock', 
    144: 'numlock', 19:'pause', 45:'insert', 36:'home', 46:'del',35:'end', 33: 'pageup', 
    34:'pagedown', 37:'left', 38:'up', 39:'right',40:'down', 112:'f1',113:'f2', 114:'f3', 
    115:'f4', 116:'f5', 117:'f6', 118:'f7', 119:'f8', 120:'f9', 121:'f10', 122:'f11', 123:'f12'};        

  this.shift_nums = { "`":"~", "1":"!", "2":"@", "3":"#", "4":"$", "5":"%", "6":"^", "7":"&", 
    "8":"*", "9":"(", "0":")", "-":"_", "=":"+", ";":":", "'":"\"", ",":"<", 
    ".":">",  "/":"?",  "\\":"|" };        

  this.add = function(combi, options, callback) {
    if (jQuery.isFunction(options)) {
      callback = options;
      options = {};
    }
    var opt = {};
    var defaults = {type: 'keydown', propagate: false, disableInInput: false, target: 'html'};
    var that = this;
    var opt = jQuery.extend( opt , defaults, options || {} );
    combi = combi.toLowerCase();        
        
    // inspect if keystroke matches
    var inspector = function(event) {
      event = jQuery.event.fix(event); // jQuery event normalization.
      var selector = event.data.selector;
      var element = jQuery(event.target);

      // Disable shortcut keys in Input, Textarea fields
      if(opt['disableInInput'] && element.is('textarea, input')) {
        return;
      }

      var
        code = event.which,
        type = event.type,
        character = String.fromCharCode(code).toLowerCase(),
        special = that.special_keys[code],
        shift = event.shiftKey,
        ctrl = event.ctrlKey,
        alt= event.altKey,
        propagate = true, // default behaivour
        mapPoint = null;

      var cbMap = that.all[selector].events[type].callbackMap;
      if(!shift && !ctrl && !alt) { // No Modifiers
        mapPoint = cbMap[special] ||  cbMap[character]
      }
      
      // deals with combinaitons (alt|ctrl|shift+anything)
      else{
        var modif = '';
        if(alt) modif +='alt+';
        if(ctrl) modif+= 'ctrl+';
        if(shift) modif += 'shift+';
        // modifiers + special keys or modifiers + characters or modifiers + shift characters
        mapPoint = cbMap[modif+special] || cbMap[modif+character] || cbMap[modif+that.shift_nums[character]]
      }

      if (mapPoint){
        mapPoint.cb(event);
        if(!mapPoint.propagate) {
          event.stopPropagation();
          event.preventDefault();
          return false;
        }
      }
    };

    // first hook for this element
    if (!this.all[opt.target]){
      this.all[opt.target] = {events:{}};
    }
    if (!this.all[opt.target].events[opt.type]){
      this.all[opt.target].events[opt.type] = {callbackMap: {}}
      jQuery(opt.target).bind(opt.type, {selector: opt.target}, inspector);
    }
    this.all[opt.target].events[opt.type].callbackMap[combi] =  {cb: callback, propagate:opt.propagate};                
    return jQuery;
	};    

  this.remove = function(exp, opt) {
    opt = opt || {};
    target = opt.target || 'html';
    type = opt.type || 'keydown';
    exp = exp.toLowerCase();
    jQuery(target).unbind(type);
    delete this.all[target].events[type].callbackMap[exp];
    return jQuery;
	};
	
  jQuery.hotkeys = this;
  return jQuery;    

})(jQuery);;

/**
 * Cookie plugin 1.0
 *
 * Copyright (c) 2006 Klaus Hartl (stilbuero.de)
 * Dual licensed under the MIT and GPL licenses:
 * http://www.opensource.org/licenses/mit-license.php
 * http://www.gnu.org/licenses/gpl.html
 *
 */
jQuery.cookie=function(b,j,m){if(typeof j!="undefined"){m=m||{};if(j===null){j="";m.expires=-1}var e="";if(m.expires&&(typeof m.expires=="number"||m.expires.toUTCString)){var f;if(typeof m.expires=="number"){f=new Date();f.setTime(f.getTime()+(m.expires*24*60*60*1000))}else{f=m.expires}e="; expires="+f.toUTCString()}var l=m.path?"; path="+(m.path):"";var g=m.domain?"; domain="+(m.domain):"";var a=m.secure?"; secure":"";document.cookie=[b,"=",encodeURIComponent(j),e,l,g,a].join("")}else{var d=null;if(document.cookie&&document.cookie!=""){var k=document.cookie.split(";");for(var h=0;h<k.length;h++){var c=jQuery.trim(k[h]);if(c.substring(0,b.length+1)==(b+"=")){d=decodeURIComponent(c.substring(b.length+1));break}}}return d}};
;
(function ($, Drupal, undefined) {

// Store all l10n_client related data + methods in its own object
  Drupal.l10nClient = {
    // Set "selected" string to unselected, i.e. -1
    selected: -1,

    // Keybindings
    keys: {'toggle': 'ctrl+shift+s', 'clear': 'esc'}, // Keybindings

    // Keybinding functions
    key: function (pressed) {
      var $l10nClient = Drupal.l10nClient.$l10nClient;
      switch (pressed) {
        case 'toggle':
          // Grab user-hilighted text & send it into the search filter
          var userSelection = window.getSelection ? window.getSelection() : document.getSelection ? document.getSelection() : document.selection.createRange().text;
          userSelection = String(userSelection);
          if (userSelection.length > 0) {
            this.filter(userSelection);
            this.toggle(1);
            $l10nClient.find('.string-search').val(userSelection).focus();
          } else {
            if ($l10nClient.is('.l10n-client-minimized')) {
              this.toggle(1);
              if (!$.browser.safari) {
                $l10nClient.find('.string-search').focus();
              }
            }
            else {
              this.toggle(0);
            }
          }
          break;
        case 'clear':
          this.filter(false);
          break;
      }
    },

    // Toggle the l10nclient
    toggle: function (state) {
      var $l10nClient = Drupal.l10nClient.$l10nClient;
      var $clientWrapper = $('#l10n-client-string-select, #l10n-client-string-editor, #l10n-client .labels .label');
      if (!!state == true) {
        $clientWrapper.show();
        $l10nClient.removeClass('l10n-client-minimized').addClass('l10n-client-maximized').find('.labels .toggle').text('X');
        if (!$.browser.msie) {
          $('body').addClass('toggle-expanded');
        }
        $.cookie('Drupal_l10n_client', '1', {expires: 7, path: '/'});
      } else {
        $clientWrapper.hide();
        $l10nClient.removeClass('l10n-client-maximized').addClass('l10n-client-minimized').find('.labels .toggle').text(Drupal.t('Translate Text'));
        if (!$.browser.msie) {
          $('body').removeClass('toggle-expanded');
        }
        $.cookie('Drupal_l10n_client', '0', {expires: 7, path: '/'});
      }
    },

    // Get a string from the DOM tree
    getString: function (index, type) {
      return $('#l10n-client-data').find('div:eq(' + index + ') .' + type).text();
    },

    // Set a string in the DOM tree
    setString: function (index, data) {
      $('#l10n-client-data').find('div:eq(' + index + ') .target').text(data);
    },

    // Filter the the string list by a search string
    filter: function (search) {
      var $l10nClient = Drupal.l10nClient.$l10nClient;
      var $stringSearch = $l10nClient.find('.string-search');
      var $stringSelect = $('#l10n-client-string-select').find('li');
      if (search === false || search === '') {
        $('#l10n-client-search-filter-clear').focus();
        $stringSelect.show();
        $stringSearch.val('').focus();
      } else if (search.length > 0) {
        $stringSelect.show().not(':contains(' + search + ')').hide();
      }
    }
  };

  // Attaches the localization editor behavior to all required fields.
  Drupal.behaviors.l10nClient = {
    attach: function (context) {
      $('#l10n-client').once('l10n-client', function () {
        $('body').addClass('l10n-client');
        var $l10nClient = $(this);
        var $l10nClientForm = $('#l10n-client-form');
        var $stringEditor = $('#l10n-client-string-editor');
        var $stringEditorSoruceText = $stringEditor.find('.source-text');
        var $stringSelect = $('#l10n-client-string-select');
        var cookie = parseInt($.cookie('Drupal_l10n_client'), 2);
        Drupal.l10nClient.$l10nClient = $l10nClient;
        Drupal.l10nClient.toggle(isNaN(cookie) ? 0 : cookie);

        // If the selection changes, copy string values to the source and target fields.
        // Add class to indicate selected string in list widget.
        $stringSelect.find('li').click(function () {
          var $this = $(this);
          var $lis = $stringSelect.find('li');
          var index = $lis.index(this);

          $lis.removeClass('active');
          $this.addClass('active');

          $stringEditorSoruceText.text(Drupal.l10nClient.getString(index, 'source'));
          $l10nClientForm.find('.translation-target').val(Drupal.l10nClient.getString(index, 'target'));
          $l10nClientForm.find('.source-textgroup').val(Drupal.l10nClient.getString(index, 'textgroup'));
          $l10nClientForm.find('.source-context').val(Drupal.l10nClient.getString(index, 'context'));
          $stringEditor.find('.context').text(Drupal.l10nClient.getString(index, 'context'));

          Drupal.l10nClient.selected = index;
          $l10nClientForm.find('.form-submit').removeAttr("disabled");
        });

        // When l10n_client window is clicked, toggle based on current state.
        $l10nClient.find('.labels .toggle').click(function () {
          Drupal.l10nClient.toggle($l10nClient.is('.l10n-client-minimized'));
        });

        // Copy source text to translation field on button click.
        $l10nClientForm.find('.edit-copy').click(function () {
          $l10nClientForm.find('.translation-target').val($stringEditorSoruceText.text());
          return false;
        });

        // Clear translation field on button click.
        $l10nClientForm.find('.edit-clear').click(function () {
          $l10nClientForm.find('.translation-target').val('');
          return false;
        });

        // Register keybindings using jQuery hotkeys
        if ($.hotkeys) {
          $.hotkeys.add(Drupal.l10nClient.keys.toggle, function () {
            Drupal.l10nClient.key('toggle');
          });
          $.hotkeys.add(Drupal.l10nClient.keys.clear, {target: '#l10n-client .string-search', type: 'keyup'}, function () {
            Drupal.l10nClient.key('clear');
          });
        }

        // Custom listener for l10n_client livesearch
        $l10nClient.find('.string-search').keyup(function () {
          Drupal.l10nClient.filter($l10nClient.find('.string-search').val());
        });

        // Clear search
        $l10nClient.find('#l10n-client-search-filter-clear').click(function () {
          Drupal.l10nClient.filter(false);
          return false;
        });

        // Send AJAX POST data on form submit.
        $l10nClientForm.submit(function () {
          var $this = $(this);

          // Prevent submit empty strings.
          $this.find('.form-submit').attr("disabled", true);
          $this.find('.edit-save').after('<div class="ajax-progress ajax-progress-throbber">' +
            '<div class="throbber">&nbsp;</div><div class="message">' +
            Drupal.t('Please wait...') + '</div></div>');

          $.ajax({
            type: "POST",
            url: $this.attr('action'),
            // Send source and target strings.
            data: {
              source: $stringEditorSoruceText.text(),
              target: $this.find('.translation-target').val(),
              textgroup: $this.find('.source-textgroup').val(),
              context: $stringEditor.find('.context').text(),
              'form_token': $this.find('input[name=form_token]').val()
            },
            success: function (data) {
              var $translationTarget = $l10nClientForm.find('.translation-target');
              var newTranslation = $translationTarget.val();
              // Store string in local js
              Drupal.l10nClient.setString(Drupal.l10nClient.selected, newTranslation);

              // Figure out the display of the new translation in the selection list.
              var newTranslationStripped = newTranslation.replace(/<\/?[^<>]+>/gi, '')
                .replace(/&quot;/g, '"')
                .replace(/&lt;/g, "<")
                .replace(/&gt;/g, ">")
                .replace(/&amp;/g, "&");

              // Only contains HTML tags (edge case). Keep the whole string.
              // HTML tags will show up in the selector, but that is normal in this case.
              var newTranslationDisplay = newTranslation;
              if (newTranslationStripped.length > 81) {
                // Long translation, strip length to display only first part.
                // We strip at 78 chars and add three dots, if the total length is
                // above 81.
                newTranslationDisplay = newTranslationStripped.substr(0, 78) + '...';
              }

              // Mark string as translated.
              $stringSelect.find('li')
                .eq(Drupal.l10nClient.selected)
                .removeClass('untranslated active')
                .addClass('translated')
                .text(newTranslationDisplay);

              // Empty input fields.
              $stringEditorSoruceText.html(data);
              $translationTarget.val('');
              $this.find('div.ajax-progress-throbber').remove();
            },
            error: function (xmlhttp) {
              alert(Drupal.t('An HTTP error @status occured.', { '@status': xmlhttp.status }));
            }
          });
          return false;
        });
      });
    }
  };
})(jQuery, Drupal);
;
(function ($) {

Drupal.behaviors.textarea = {
  attach: function (context, settings) {
    $('.form-textarea-wrapper.resizable', context).once('textarea', function () {
      var staticOffset = null;
      var textarea = $(this).addClass('resizable-textarea').find('textarea');
      var grippie = $('<div class="grippie"></div>').mousedown(startDrag);

      grippie.insertAfter(textarea);

      function startDrag(e) {
        staticOffset = textarea.height() - e.pageY;
        textarea.css('opacity', 0.25);
        $(document).mousemove(performDrag).mouseup(endDrag);
        return false;
      }

      function performDrag(e) {
        textarea.height(Math.max(32, staticOffset + e.pageY) + 'px');
        return false;
      }

      function endDrag(e) {
        $(document).unbind('mousemove', performDrag).unbind('mouseup', endDrag);
        textarea.css('opacity', 1);
      }
    });
  }
};

})(jQuery);
;
/* $Id: lightbox.js,v 1.5.2.6.2.136 2010/09/24 08:39:40 snpower Exp $ */

/**
 * jQuery Lightbox
 * @author
 *   Stella Power, <http://drupal.org/user/66894>
 *
 * Based on Lightbox v2.03.3 by Lokesh Dhakar
 * <http://www.huddletogether.com/projects/lightbox2/>
 * Also partially based on the jQuery Lightbox by Warren Krewenki
 *   <http://warren.mesozen.com>
 *
 * Permission has been granted to Mark Ashmead & other Drupal Lightbox2 module
 * maintainers to distribute this file via Drupal.org
 * Under GPL license.
 *
 * Slideshow, iframe and video functionality added by Stella Power.
 */

var Lightbox;
(function($) {
Lightbox = {
  auto_modal : false,
  overlayOpacity : 0.8, // Controls transparency of shadow overlay.
  overlayColor : '000', // Controls colour of shadow overlay.
  disableCloseClick : true,
  // Controls the order of the lightbox resizing animation sequence.
  resizeSequence: 0, // 0: simultaneous, 1: width then height, 2: height then width.
  resizeSpeed: 'normal', // Controls the speed of the lightbox resizing animation.
  fadeInSpeed: 'normal', // Controls the speed of the image appearance.
  slideDownSpeed: 'slow', // Controls the speed of the image details appearance.
  minWidth: 240,
  borderSize : 10,
  boxColor : 'fff',
  fontColor : '000',
  topPosition : '',
  infoHeight: 20,
  alternative_layout : false,
  imageArray : [],
  imageNum : null,
  total : 0,
  activeImage : null,
  inprogress : false,
  disableResize : false,
  disableZoom : false,
  isZoomedIn : false,
  rtl : false,
  loopItems : false,
  keysClose : ['c', 'x', 27],
  keysPrevious : ['p', 37],
  keysNext : ['n', 39],
  keysZoom : ['z'],
  keysPlayPause : [32],

  // Slideshow options.
  slideInterval : 5000, // In milliseconds.
  showPlayPause : true,
  autoStart : true,
  autoExit : true,
  pauseOnNextClick : false, // True to pause the slideshow when the "Next" button is clicked.
  pauseOnPrevClick : true, // True to pause the slideshow when the "Prev" button is clicked.
  slideIdArray : [],
  slideIdCount : 0,
  isSlideshow : false,
  isPaused : false,
  loopSlides : false,

  // Iframe options.
  isLightframe : false,
  iframe_width : 600,
  iframe_height : 400,
  iframe_border : 1,

  // Video and modal options.
  enableVideo : false,
  flvPlayer : '/flvplayer.swf',
  flvFlashvars : '',
  isModal : false,
  isVideo : false,
  videoId : false,
  modalWidth : 400,
  modalHeight : 400,
  modalHTML : null,


  // initialize()
  // Constructor runs on completion of the DOM loading.
  // The function inserts html at the bottom of the page which is used
  // to display the shadow overlay and the image container.
  initialize: function() {

    var s = Drupal.settings.lightbox2;
    Lightbox.overlayOpacity = s.overlay_opacity;
    Lightbox.overlayColor = s.overlay_color;
    Lightbox.disableCloseClick = s.disable_close_click;
    Lightbox.resizeSequence = s.resize_sequence;
    Lightbox.resizeSpeed = s.resize_speed;
    Lightbox.fadeInSpeed = s.fade_in_speed;
    Lightbox.slideDownSpeed = s.slide_down_speed;
    Lightbox.borderSize = s.border_size;
    Lightbox.boxColor = s.box_color;
    Lightbox.fontColor = s.font_color;
    Lightbox.topPosition = s.top_position;
    Lightbox.rtl = s.rtl;
    Lightbox.loopItems = s.loop_items;
    Lightbox.keysClose = s.keys_close.split(" ");
    Lightbox.keysPrevious = s.keys_previous.split(" ");
    Lightbox.keysNext = s.keys_next.split(" ");
    Lightbox.keysZoom = s.keys_zoom.split(" ");
    Lightbox.keysPlayPause = s.keys_play_pause.split(" ");
    Lightbox.disableResize = s.disable_resize;
    Lightbox.disableZoom = s.disable_zoom;
    Lightbox.slideInterval = s.slideshow_interval;
    Lightbox.showPlayPause = s.show_play_pause;
    Lightbox.showCaption = s.show_caption;
    Lightbox.autoStart = s.slideshow_automatic_start;
    Lightbox.autoExit = s.slideshow_automatic_exit;
    Lightbox.pauseOnNextClick = s.pause_on_next_click;
    Lightbox.pauseOnPrevClick = s.pause_on_previous_click;
    Lightbox.loopSlides = s.loop_slides;
    Lightbox.alternative_layout = s.use_alt_layout;
    Lightbox.iframe_width = s.iframe_width;
    Lightbox.iframe_height = s.iframe_height;
    Lightbox.iframe_border = s.iframe_border;
    Lightbox.enableVideo = s.enable_video;
    if (s.enable_video) {
      Lightbox.flvPlayer = s.flvPlayer;
      Lightbox.flvFlashvars = s.flvFlashvars;
    }

    // Make the lightbox divs.
    var layout_class = (s.use_alt_layout ? 'lightbox2-alt-layout' : 'lightbox2-orig-layout');
    var output = '<div id="lightbox2-overlay" style="display: none;"></div>\
      <div id="lightbox" style="display: none;" class="' + layout_class + '">\
        <div id="outerImageContainer"></div>\
        <div id="imageDataContainer" class="clearfix">\
          <div id="imageData"></div>\
        </div>\
      </div>';
    var loading = '<div id="loading"><a href="#" id="loadingLink"></a></div>';
    var modal = '<div id="modalContainer" style="display: none;"></div>';
    var frame = '<div id="frameContainer" style="display: none;"></div>';
    var imageContainer = '<div id="imageContainer" style="display: none;"></div>';
    var details = '<div id="imageDetails"></div>';
    var bottomNav = '<div id="bottomNav"></div>';
    var image = '<img id="lightboxImage" alt="" />';
    var hoverNav = '<div id="hoverNav"><a id="prevLink" href="#"></a><a id="nextLink" href="#"></a></div>';
    var frameNav = '<div id="frameHoverNav"><a id="framePrevLink" href="#"></a><a id="frameNextLink" href="#"></a></div>';
    var hoverNav = '<div id="hoverNav"><a id="prevLink" title="' + Drupal.t('Previous') + '" href="#"></a><a id="nextLink" title="' + Drupal.t('Next') + '" href="#"></a></div>';
    var frameNav = '<div id="frameHoverNav"><a id="framePrevLink" title="' + Drupal.t('Previous') + '" href="#"></a><a id="frameNextLink" title="' + Drupal.t('Next') + '" href="#"></a></div>';
    var caption = '<span id="caption"></span>';
    var numberDisplay = '<span id="numberDisplay"></span>';
    var close = '<a id="bottomNavClose" title="' + Drupal.t('Close') + '" href="#"></a>';
    var zoom = '<a id="bottomNavZoom" href="#"></a>';
    var zoomOut = '<a id="bottomNavZoomOut" href="#"></a>';
    var pause = '<a id="lightshowPause" title="' + Drupal.t('Pause Slideshow') + '" href="#" style="display: none;"></a>';
    var play = '<a id="lightshowPlay" title="' + Drupal.t('Play Slideshow') + '" href="#" style="display: none;"></a>';

    $("body").append(output);
    $('#outerImageContainer').append(modal + frame + imageContainer + loading);
    if (!s.use_alt_layout) {
      $('#imageContainer').append(image + hoverNav);
      $('#imageData').append(details + bottomNav);
      $('#imageDetails').append(caption + numberDisplay);
      $('#bottomNav').append(frameNav + close + zoom + zoomOut + pause + play);
    }
    else {
      $('#outerImageContainer').append(bottomNav);
      $('#imageContainer').append(image);
      $('#bottomNav').append(close + zoom + zoomOut);
      $('#imageData').append(hoverNav + details);
      $('#imageDetails').append(caption + numberDisplay + pause + play);
    }

    // Setup onclick handlers.
    if (Lightbox.disableCloseClick) {
      $('#lightbox2-overlay').click(function() { Lightbox.end(); return false; } ).hide();
    }
    $('#loadingLink, #bottomNavClose').click(function() { Lightbox.end('forceClose'); return false; } );
    $('#prevLink, #framePrevLink').click(function() { Lightbox.changeData(Lightbox.activeImage - 1); return false; } );
    $('#nextLink, #frameNextLink').click(function() { Lightbox.changeData(Lightbox.activeImage + 1); return false; } );
    $('#bottomNavZoom').click(function() { Lightbox.changeData(Lightbox.activeImage, true); return false; } );
    $('#bottomNavZoomOut').click(function() { Lightbox.changeData(Lightbox.activeImage, false); return false; } );
    $('#lightshowPause').click(function() { Lightbox.togglePlayPause("lightshowPause", "lightshowPlay"); return false; } );
    $('#lightshowPlay').click(function() { Lightbox.togglePlayPause("lightshowPlay", "lightshowPause"); return false; } );

    // Fix positioning.
    $('#prevLink, #nextLink, #framePrevLink, #frameNextLink').css({ 'paddingTop': Lightbox.borderSize + 'px'});
    $('#imageContainer, #frameContainer, #modalContainer').css({ 'padding': Lightbox.borderSize + 'px'});
    $('#outerImageContainer, #imageDataContainer, #bottomNavClose').css({'backgroundColor': '#' + Lightbox.boxColor, 'color': '#'+Lightbox.fontColor});
    if (Lightbox.alternative_layout) {
      $('#bottomNavZoom, #bottomNavZoomOut').css({'bottom': Lightbox.borderSize + 'px', 'right': Lightbox.borderSize + 'px'});
    }
    else if (Lightbox.rtl == 1 && Drupal.settings.lightbox2.useragent.search('MSIE') !== -1) {
      $('#bottomNavZoom, #bottomNavZoomOut').css({'left': '0px'});
    }

    // Force navigation links to always be displayed
    if (s.force_show_nav) {
      $('#prevLink, #nextLink').addClass("force_show_nav");
    }

  },

  // initList()
  // Loops through anchor tags looking for 'lightbox', 'lightshow' and
  // 'lightframe', etc, references and applies onclick events to appropriate
  // links. You can rerun after dynamically adding images w/ajax.
  initList : function(context) {

    if (context == undefined || context == null) {
      context = document;
    }

    // Attach lightbox to any links with rel 'lightbox', 'lightshow' or
    // 'lightframe', etc.
    $("a[rel^='lightbox']:not(.lightbox-processed), area[rel^='lightbox']:not(.lightbox-processed)", context).addClass('lightbox-processed').click(function(e) {
      if (Lightbox.disableCloseClick) {
        $('#lightbox').unbind('click');
        $('#lightbox').click(function() { Lightbox.end('forceClose'); } );
      }
      Lightbox.start(this, false, false, false, false);
      if (e.preventDefault) { e.preventDefault(); }
      return false;
    });
    $("a[rel^='lightshow']:not(.lightbox-processed), area[rel^='lightshow']:not(.lightbox-processed)", context).addClass('lightbox-processed').click(function(e) {
      if (Lightbox.disableCloseClick) {
        $('#lightbox').unbind('click');
        $('#lightbox').click(function() { Lightbox.end('forceClose'); } );
      }
      Lightbox.start(this, true, false, false, false);
      if (e.preventDefault) { e.preventDefault(); }
      return false;
    });
    $("a[rel^='lightframe']:not(.lightbox-processed), area[rel^='lightframe']:not(.lightbox-processed)", context).addClass('lightbox-processed').click(function(e) {
      if (Lightbox.disableCloseClick) {
        $('#lightbox').unbind('click');
        $('#lightbox').click(function() { Lightbox.end('forceClose'); } );
      }
      Lightbox.start(this, false, true, false, false);
      if (e.preventDefault) { e.preventDefault(); }
      return false;
    });
    if (Lightbox.enableVideo) {
      $("a[rel^='lightvideo']:not(.lightbox-processed), area[rel^='lightvideo']:not(.lightbox-processed)", context).addClass('lightbox-processed').click(function(e) {
        if (Lightbox.disableCloseClick) {
          $('#lightbox').unbind('click');
          $('#lightbox').click(function() { Lightbox.end('forceClose'); } );
        }
        Lightbox.start(this, false, false, true, false);
        if (e.preventDefault) { e.preventDefault(); }
        return false;
      });
    }
    $("a[rel^='lightmodal']:not(.lightbox-processed), area[rel^='lightmodal']:not(.lightbox-processed)", context).addClass('lightbox-processed').click(function(e) {
      $('#lightbox').unbind('click');
      // Add classes from the link to the lightbox div - don't include lightbox-processed
      $('#lightbox').addClass($(this).attr('class'));
      $('#lightbox').removeClass('lightbox-processed');
      Lightbox.start(this, false, false, false, true);
      if (e.preventDefault) { e.preventDefault(); }
      return false;
    });
    $("#lightboxAutoModal:not(.lightbox-processed)", context).addClass('lightbox-processed').click(function(e) {
      Lightbox.auto_modal = true;
      $('#lightbox').unbind('click');
      Lightbox.start(this, false, false, false, true);
      if (e.preventDefault) { e.preventDefault(); }
      return false;
    });
  },

  // start()
  // Display overlay and lightbox. If image is part of a set, add siblings to
  // imageArray.
  start: function(imageLink, slideshow, lightframe, lightvideo, lightmodal) {

    Lightbox.isPaused = !Lightbox.autoStart;

    // Replaces hideSelectBoxes() and hideFlash() calls in original lightbox2.
    Lightbox.toggleSelectsFlash('hide');

    // Stretch overlay to fill page and fade in.
    var arrayPageSize = Lightbox.getPageSize();
    $("#lightbox2-overlay").hide().css({
      'width': '100%',
      'zIndex': '10090',
      'height': arrayPageSize[1] + 'px',
      'backgroundColor' : '#' + Lightbox.overlayColor
    });
    // Detect OS X FF2 opacity + flash issue.
    if (lightvideo && this.detectMacFF2()) {
      $("#lightbox2-overlay").removeClass("overlay_default");
      $("#lightbox2-overlay").addClass("overlay_macff2");
      $("#lightbox2-overlay").css({'opacity' : null});
    }
    else {
      $("#lightbox2-overlay").removeClass("overlay_macff2");
      $("#lightbox2-overlay").addClass("overlay_default");
      $("#lightbox2-overlay").css({'opacity' : Lightbox.overlayOpacity});
    }
    $("#lightbox2-overlay").fadeIn(Lightbox.fadeInSpeed);


    Lightbox.isSlideshow = slideshow;
    Lightbox.isLightframe = lightframe;
    Lightbox.isVideo = lightvideo;
    Lightbox.isModal = lightmodal;
    Lightbox.imageArray = [];
    Lightbox.imageNum = 0;

    var anchors = $(imageLink.tagName);
    var anchor = null;
    var rel_parts = Lightbox.parseRel(imageLink);
    var rel = rel_parts["rel"];
    var rel_group = rel_parts["group"];
    var title = (rel_parts["title"] ? rel_parts["title"] : imageLink.title);
    var rel_style = null;
    var i = 0;

    if (rel_parts["flashvars"]) {
      Lightbox.flvFlashvars = Lightbox.flvFlashvars + '&' + rel_parts["flashvars"];
    }

    // Set the title for image alternative text.
    var alt = imageLink.title;
    if (!alt) {
      var img = $(imageLink).find("img");
      if (img && $(img).attr("alt")) {
        alt = $(img).attr("alt");
      }
      else {
        alt = title;
      }
    }

    if ($(imageLink).attr('id') == 'lightboxAutoModal') {
      rel_style = rel_parts["style"];
      Lightbox.imageArray.push(['#lightboxAutoModal > *', title, alt, rel_style, 1]);
    }
    else {
      // Handle lightbox images with no grouping.
      if ((rel == 'lightbox' || rel == 'lightshow') && !rel_group) {
        Lightbox.imageArray.push([imageLink.href, title, alt]);
      }

      // Handle other items with no grouping.
      else if (!rel_group) {
        rel_style = rel_parts["style"];
        Lightbox.imageArray.push([imageLink.href, title, alt, rel_style]);
      }

      // Handle grouped items.
      else {

        // Loop through anchors and add them to imageArray.
        for (i = 0; i < anchors.length; i++) {
          anchor = anchors[i];
          if (anchor.href && typeof(anchor.href) == "string" && $(anchor).attr('rel')) {
            var rel_data = Lightbox.parseRel(anchor);
            var anchor_title = (rel_data["title"] ? rel_data["title"] : anchor.title);
            img_alt = anchor.title;
            if (!img_alt) {
              var anchor_img = $(anchor).find("img");
              if (anchor_img && $(anchor_img).attr("alt")) {
                img_alt = $(anchor_img).attr("alt");
              }
              else {
                img_alt = title;
              }
            }
            if (rel_data["rel"] == rel) {
              if (rel_data["group"] == rel_group) {
                if (Lightbox.isLightframe || Lightbox.isModal || Lightbox.isVideo) {
                  rel_style = rel_data["style"];
                }
                Lightbox.imageArray.push([anchor.href, anchor_title, img_alt, rel_style]);
              }
            }
          }
        }

        // Remove duplicates.
        for (i = 0; i < Lightbox.imageArray.length; i++) {
          for (j = Lightbox.imageArray.length-1; j > i; j--) {
            if (Lightbox.imageArray[i][0] == Lightbox.imageArray[j][0]) {
              Lightbox.imageArray.splice(j,1);
            }
          }
        }
        while (Lightbox.imageArray[Lightbox.imageNum][0] != imageLink.href) {
          Lightbox.imageNum++;
        }
      }
    }

    if (Lightbox.isSlideshow && Lightbox.showPlayPause && Lightbox.isPaused) {
      $('#lightshowPlay').show();
      $('#lightshowPause').hide();
    }

    // Calculate top and left offset for the lightbox.
    var arrayPageScroll = Lightbox.getPageScroll();
    var lightboxTop = arrayPageScroll[1] + (Lightbox.topPosition == '' ? (arrayPageSize[3] / 10) : Lightbox.topPosition) * 1;
    var lightboxLeft = arrayPageScroll[0];
    $('#frameContainer, #modalContainer, #lightboxImage').hide();
    $('#hoverNav, #prevLink, #nextLink, #frameHoverNav, #framePrevLink, #frameNextLink').hide();
    $('#imageDataContainer, #numberDisplay, #bottomNavZoom, #bottomNavZoomOut').hide();
    $('#outerImageContainer').css({'width': '250px', 'height': '250px'});
    $('#lightbox').css({
      'zIndex': '10500',
      'top': lightboxTop + 'px',
      'left': lightboxLeft + 'px'
    }).show();

    Lightbox.total = Lightbox.imageArray.length;
    Lightbox.changeData(Lightbox.imageNum);
  },

  // changeData()
  // Hide most elements and preload image in preparation for resizing image
  // container.
  changeData: function(imageNum, zoomIn) {

    if (Lightbox.inprogress === false) {
      if (Lightbox.total > 1 && ((Lightbox.isSlideshow && Lightbox.loopSlides) || (!Lightbox.isSlideshow && Lightbox.loopItems))) {
        if (imageNum >= Lightbox.total) imageNum = 0;
        if (imageNum < 0) imageNum = Lightbox.total - 1;
      }

      if (Lightbox.isSlideshow) {
        for (var i = 0; i < Lightbox.slideIdCount; i++) {
          window.clearTimeout(Lightbox.slideIdArray[i]);
        }
      }
      Lightbox.inprogress = true;
      Lightbox.activeImage = imageNum;

      if (Lightbox.disableResize && !Lightbox.isSlideshow) {
        zoomIn = true;
      }
      Lightbox.isZoomedIn = zoomIn;


      // Hide elements during transition.
      $('#loading').css({'zIndex': '10500'}).show();
      if (!Lightbox.alternative_layout) {
        $('#imageContainer').hide();
      }
      $('#frameContainer, #modalContainer, #lightboxImage').hide();
      $('#hoverNav, #prevLink, #nextLink, #frameHoverNav, #framePrevLink, #frameNextLink').hide();
      $('#imageDataContainer, #numberDisplay, #bottomNavZoom, #bottomNavZoomOut').hide();

      // Preload image content, but not iframe pages.
      if (!Lightbox.isLightframe && !Lightbox.isVideo && !Lightbox.isModal) {
        $("#lightbox #imageDataContainer").removeClass('lightbox2-alt-layout-data');
        imgPreloader = new Image();
        imgPreloader.onerror = function() { Lightbox.imgNodeLoadingError(this); };

        imgPreloader.onload = function() {
          var photo = document.getElementById('lightboxImage');
          photo.src = Lightbox.imageArray[Lightbox.activeImage][0];
          photo.alt = Lightbox.imageArray[Lightbox.activeImage][2];

          var imageWidth = imgPreloader.width;
          var imageHeight = imgPreloader.height;

          // Resize code.
          var arrayPageSize = Lightbox.getPageSize();
          var targ = { w:arrayPageSize[2] - (Lightbox.borderSize * 2), h:arrayPageSize[3] - (Lightbox.borderSize * 6) - (Lightbox.infoHeight * 4) - (arrayPageSize[3] / 10) };
          var orig = { w:imgPreloader.width, h:imgPreloader.height };

          // Image is very large, so show a smaller version of the larger image
          // with zoom button.
          if (zoomIn !== true) {
            var ratio = 1.0; // Shrink image with the same aspect.
            $('#bottomNavZoomOut, #bottomNavZoom').hide();
            if ((orig.w >= targ.w || orig.h >= targ.h) && orig.h && orig.w) {
              ratio = ((targ.w / orig.w) < (targ.h / orig.h)) ? targ.w / orig.w : targ.h / orig.h;
              if (!Lightbox.disableZoom && !Lightbox.isSlideshow) {
                $('#bottomNavZoom').css({'zIndex': '10500'}).show();
              }
            }

            imageWidth  = Math.floor(orig.w * ratio);
            imageHeight = Math.floor(orig.h * ratio);
          }

          else {
            $('#bottomNavZoom').hide();
            // Only display zoom out button if the image is zoomed in already.
            if ((orig.w >= targ.w || orig.h >= targ.h) && orig.h && orig.w) {
              // Only display zoom out button if not a slideshow and if the
              // buttons aren't disabled.
              if (!Lightbox.disableResize && Lightbox.isSlideshow === false && !Lightbox.disableZoom) {
                $('#bottomNavZoomOut').css({'zIndex': '10500'}).show();
              }
            }
          }

          photo.style.width = (imageWidth) + 'px';
          photo.style.height = (imageHeight) + 'px';
          Lightbox.resizeContainer(imageWidth, imageHeight);

          // Clear onLoad, IE behaves irratically with animated gifs otherwise.
          imgPreloader.onload = function() {};
        };

        imgPreloader.src = Lightbox.imageArray[Lightbox.activeImage][0];
        imgPreloader.alt = Lightbox.imageArray[Lightbox.activeImage][2];
      }

      // Set up frame size, etc.
      else if (Lightbox.isLightframe) {
        $("#lightbox #imageDataContainer").addClass('lightbox2-alt-layout-data');
        var src = Lightbox.imageArray[Lightbox.activeImage][0];
        $('#frameContainer').html('<iframe id="lightboxFrame" style="display: none;" src="'+src+'"></iframe>');

        // Enable swf support in Gecko browsers.
        if (Drupal.settings.lightbox2.useragent.search('Mozilla') !== -1 && src.indexOf('.swf') != -1) {
          setTimeout(function () {
            document.getElementById("lightboxFrame").src = Lightbox.imageArray[Lightbox.activeImage][0];
          }, 1000);
        }

        if (!Lightbox.iframe_border) {
          $('#lightboxFrame').css({'border': 'none'});
          $('#lightboxFrame').attr('frameborder', '0');
        }
        var iframe = document.getElementById('lightboxFrame');
        var iframeStyles = Lightbox.imageArray[Lightbox.activeImage][3];
        iframe = Lightbox.setStyles(iframe, iframeStyles);
        Lightbox.resizeContainer(parseInt(iframe.width, 10), parseInt(iframe.height, 10));
      }
      else if (Lightbox.isVideo || Lightbox.isModal) {
        $("#lightbox #imageDataContainer").addClass('lightbox2-alt-layout-data');
        var container = document.getElementById('modalContainer');
        var modalStyles = Lightbox.imageArray[Lightbox.activeImage][3];
        container = Lightbox.setStyles(container, modalStyles);
        if (Lightbox.isVideo) {
          Lightbox.modalHeight =  parseInt(container.height, 10) - 10;
          Lightbox.modalWidth =  parseInt(container.width, 10) - 10;
          Lightvideo.startVideo(Lightbox.imageArray[Lightbox.activeImage][0]);
        }
        Lightbox.resizeContainer(parseInt(container.width, 10), parseInt(container.height, 10));
      }
    }
  },

  // imgNodeLoadingError()
  imgNodeLoadingError: function(image) {
    var s = Drupal.settings.lightbox2;
    var original_image = Lightbox.imageArray[Lightbox.activeImage][0];
    if (s.display_image_size !== "") {
      original_image = original_image.replace(new RegExp("."+s.display_image_size), "");
    }
    Lightbox.imageArray[Lightbox.activeImage][0] = original_image;
    image.onerror = function() { Lightbox.imgLoadingError(image); };
    image.src = original_image;
  },

  // imgLoadingError()
  imgLoadingError: function(image) {
    var s = Drupal.settings.lightbox2;
    Lightbox.imageArray[Lightbox.activeImage][0] = s.default_image;
    image.src = s.default_image;
  },

  // resizeContainer()
  resizeContainer: function(imgWidth, imgHeight) {

    imgWidth = (imgWidth < Lightbox.minWidth ? Lightbox.minWidth : imgWidth);

    this.widthCurrent = $('#outerImageContainer').width();
    this.heightCurrent = $('#outerImageContainer').height();

    var widthNew = (imgWidth  + (Lightbox.borderSize * 2));
    var heightNew = (imgHeight  + (Lightbox.borderSize * 2));

    // Scalars based on change from old to new.
    this.xScale = ( widthNew / this.widthCurrent) * 100;
    this.yScale = ( heightNew / this.heightCurrent) * 100;

    // Calculate size difference between new and old image, and resize if
    // necessary.
    wDiff = this.widthCurrent - widthNew;
    hDiff = this.heightCurrent - heightNew;

    $('#modalContainer').css({'width': imgWidth, 'height': imgHeight});
    // Detect animation sequence.
    if (Lightbox.resizeSequence) {
      var animate1 = {width: widthNew};
      var animate2 = {height: heightNew};
      if (Lightbox.resizeSequence == 2) {
        animate1 = {height: heightNew};
        animate2 = {width: widthNew};
      }
      $('#outerImageContainer').animate(animate1, Lightbox.resizeSpeed).animate(animate2, Lightbox.resizeSpeed, 'linear', function() { Lightbox.showData(); });
    }
    // Simultaneous.
    else {
      $('#outerImageContainer').animate({'width': widthNew, 'height': heightNew}, Lightbox.resizeSpeed, 'linear', function() { Lightbox.showData(); });
    }

    // If new and old image are same size and no scaling transition is necessary
    // do a quick pause to prevent image flicker.
    if ((hDiff === 0) && (wDiff === 0)) {
      if (Drupal.settings.lightbox2.useragent.search('MSIE') !== -1) {
        Lightbox.pause(250);
      }
      else {
        Lightbox.pause(100);
      }
    }

    var s = Drupal.settings.lightbox2;
    if (!s.use_alt_layout) {
      $('#prevLink, #nextLink').css({'height': imgHeight + 'px'});
    }
    $('#imageDataContainer').css({'width': widthNew + 'px'});
  },

  // showData()
  // Display image and begin preloading neighbors.
  showData: function() {
    $('#loading').hide();

    if (Lightbox.isLightframe || Lightbox.isVideo || Lightbox.isModal) {
      Lightbox.updateDetails();
      if (Lightbox.isLightframe) {
        $('#frameContainer').show();
        if (Drupal.settings.lightbox2.useragent.search('Safari') !== -1 || Lightbox.fadeInSpeed === 0) {
          $('#lightboxFrame').css({'zIndex': '10500'}).show();
        }
        else {
          $('#lightboxFrame').css({'zIndex': '10500'}).fadeIn(Lightbox.fadeInSpeed);
        }
      }
      else {
        if (Lightbox.isVideo) {
          $("#modalContainer").html(Lightbox.modalHTML).click(function(){return false;}).css('zIndex', '10500').show();
        }
        else {
          var src = unescape(Lightbox.imageArray[Lightbox.activeImage][0]);
          if (Lightbox.imageArray[Lightbox.activeImage][4]) {
            $(src).appendTo("#modalContainer");
            $('#modalContainer').css({'zIndex': '10500'}).show();
          }
          else {
            // Use a callback to show the new image, otherwise you get flicker.
            $("#modalContainer").hide().load(src, function () {$('#modalContainer').css({'zIndex': '10500'}).show();});
          }
          $('#modalContainer').unbind('click');
        }
        // This might be needed in the Lightframe section above.
        //$('#modalContainer').css({'zIndex': '10500'}).show();
      }
    }

    // Handle display of image content.
    else {
      $('#imageContainer').show();
      if (Drupal.settings.lightbox2.useragent.search('Safari') !== -1 || Lightbox.fadeInSpeed === 0) {
        $('#lightboxImage').css({'zIndex': '10500'}).show();
      }
      else {
        $('#lightboxImage').css({'zIndex': '10500'}).fadeIn(Lightbox.fadeInSpeed);
      }
      Lightbox.updateDetails();
      this.preloadNeighborImages();
    }
    Lightbox.inprogress = false;

    // Slideshow specific stuff.
    if (Lightbox.isSlideshow) {
      if (!Lightbox.loopSlides && Lightbox.activeImage == (Lightbox.total - 1)) {
        if (Lightbox.autoExit) {
          Lightbox.slideIdArray[Lightbox.slideIdCount++] = setTimeout(function () {Lightbox.end('slideshow');}, Lightbox.slideInterval);
        }
      }
      else {
        if (!Lightbox.isPaused && Lightbox.total > 1) {
          Lightbox.slideIdArray[Lightbox.slideIdCount++] = setTimeout(function () {Lightbox.changeData(Lightbox.activeImage + 1);}, Lightbox.slideInterval);
        }
      }
      if (Lightbox.showPlayPause && Lightbox.total > 1 && !Lightbox.isPaused) {
        $('#lightshowPause').show();
        $('#lightshowPlay').hide();
      }
      else if (Lightbox.showPlayPause && Lightbox.total > 1) {
        $('#lightshowPause').hide();
        $('#lightshowPlay').show();
      }
    }

    // Adjust the page overlay size.
    var arrayPageSize = Lightbox.getPageSize();
    var arrayPageScroll = Lightbox.getPageScroll();
    var pageHeight = arrayPageSize[1];
    if (Lightbox.isZoomedIn && arrayPageSize[1] > arrayPageSize[3]) {
      var lightboxTop = (Lightbox.topPosition == '' ? (arrayPageSize[3] / 10) : Lightbox.topPosition) * 1;
      pageHeight = pageHeight + arrayPageScroll[1] + lightboxTop;
    }
    $('#lightbox2-overlay').css({'height': pageHeight + 'px', 'width': arrayPageSize[0] + 'px'});

    // Gecko browsers (e.g. Firefox, SeaMonkey, etc) don't handle pdfs as
    // expected.
    if (Drupal.settings.lightbox2.useragent.search('Mozilla') !== -1) {
      if (Lightbox.imageArray[Lightbox.activeImage][0].indexOf(".pdf") != -1) {
        setTimeout(function () {
          document.getElementById("lightboxFrame").src = Lightbox.imageArray[Lightbox.activeImage][0];
        }, 1000);
      }
    }
  },

  // updateDetails()
  // Display caption, image number, and bottom nav.
  updateDetails: function() {

    $("#imageDataContainer").hide();

    var s = Drupal.settings.lightbox2;

    if (s.show_caption) {
      var caption = Lightbox.filterXSS(Lightbox.imageArray[Lightbox.activeImage][1]);
      if (!caption) caption = '';
      $('#caption').html(caption).css({'zIndex': '10500'}).show();
    }

    // If image is part of set display 'Image x of x'.
    var numberDisplay = null;
    if (s.image_count && Lightbox.total > 1) {
      var currentImage = Lightbox.activeImage + 1;
      if (!Lightbox.isLightframe && !Lightbox.isModal && !Lightbox.isVideo) {
        numberDisplay = s.image_count.replace(/\!current/, currentImage).replace(/\!total/, Lightbox.total);
      }
      else if (Lightbox.isVideo) {
        numberDisplay = s.video_count.replace(/\!current/, currentImage).replace(/\!total/, Lightbox.total);
      }
      else {
        numberDisplay = s.page_count.replace(/\!current/, currentImage).replace(/\!total/, Lightbox.total);
      }
      $('#numberDisplay').html(numberDisplay).css({'zIndex': '10500'}).show();
    }
    else {
      $('#numberDisplay').hide();
    }

    $("#imageDataContainer").hide().slideDown(Lightbox.slideDownSpeed, function() {
      $("#bottomNav").show();
    });
    if (Lightbox.rtl == 1) {
      $("#bottomNav").css({'float': 'left'});
    }
    Lightbox.updateNav();
  },

  // updateNav()
  // Display appropriate previous and next hover navigation.
  updateNav: function() {

    $('#hoverNav').css({'zIndex': '10500'}).show();
    var prevLink = '#prevLink';
    var nextLink = '#nextLink';

    // Slideshow is separated as we need to show play / pause button.
    if (Lightbox.isSlideshow) {
      if ((Lightbox.total > 1 && Lightbox.loopSlides) || Lightbox.activeImage !== 0) {
        $(prevLink).css({'zIndex': '10500'}).show().click(function() {
          if (Lightbox.pauseOnPrevClick) {
            Lightbox.togglePlayPause("lightshowPause", "lightshowPlay");
          }
          Lightbox.changeData(Lightbox.activeImage - 1); return false;
        });
      }
      else {
        $(prevLink).hide();
      }

      // If not last image in set, display next image button.
      if ((Lightbox.total > 1 && Lightbox.loopSlides) || Lightbox.activeImage != (Lightbox.total - 1)) {
        $(nextLink).css({'zIndex': '10500'}).show().click(function() {
          if (Lightbox.pauseOnNextClick) {
            Lightbox.togglePlayPause("lightshowPause", "lightshowPlay");
          }
          Lightbox.changeData(Lightbox.activeImage + 1); return false;
        });
      }
      // Safari browsers need to have hide() called again.
      else {
        $(nextLink).hide();
      }
    }

    // All other types of content.
    else {

      if ((Lightbox.isLightframe || Lightbox.isModal || Lightbox.isVideo) && !Lightbox.alternative_layout) {
        $('#frameHoverNav').css({'zIndex': '10500'}).show();
        $('#hoverNav').css({'zIndex': '10500'}).hide();
        prevLink = '#framePrevLink';
        nextLink = '#frameNextLink';
      }

      // If not first image in set, display prev image button.
      if ((Lightbox.total > 1 && Lightbox.loopItems) || Lightbox.activeImage !== 0) {
        // Unbind any other click handlers, otherwise this adds a new click handler
        // each time the arrow is clicked.
        $(prevLink).css({'zIndex': '10500'}).show().unbind().click(function() {
          Lightbox.changeData(Lightbox.activeImage - 1); return false;
        });
      }
      // Safari browsers need to have hide() called again.
      else {
        $(prevLink).hide();
      }

      // If not last image in set, display next image button.
      if ((Lightbox.total > 1 && Lightbox.loopItems) || Lightbox.activeImage != (Lightbox.total - 1)) {
        // Unbind any other click handlers, otherwise this adds a new click handler
        // each time the arrow is clicked.
        $(nextLink).css({'zIndex': '10500'}).show().unbind().click(function() {
          Lightbox.changeData(Lightbox.activeImage + 1); return false;
        });
      }
      // Safari browsers need to have hide() called again.
      else {
        $(nextLink).hide();
      }
    }

    // Don't enable keyboard shortcuts so forms will work.
    if (!Lightbox.isModal) {
      this.enableKeyboardNav();
    }
  },


  // enableKeyboardNav()
  enableKeyboardNav: function() {
    $(document).bind("keydown", this.keyboardAction);
  },

  // disableKeyboardNav()
  disableKeyboardNav: function() {
    $(document).unbind("keydown", this.keyboardAction);
  },

  // keyboardAction()
  keyboardAction: function(e) {
    if (e === null) { // IE.
      keycode = event.keyCode;
      escapeKey = 27;
    }
    else { // Mozilla.
      keycode = e.keyCode;
      escapeKey = e.DOM_VK_ESCAPE;
    }

    key = String.fromCharCode(keycode).toLowerCase();

    // Close lightbox.
    if (Lightbox.checkKey(Lightbox.keysClose, key, keycode)) {
      Lightbox.end('forceClose');
    }
    // Display previous image (p, <-).
    else if (Lightbox.checkKey(Lightbox.keysPrevious, key, keycode)) {
      if ((Lightbox.total > 1 && ((Lightbox.isSlideshow && Lightbox.loopSlides) || (!Lightbox.isSlideshow && Lightbox.loopItems))) || Lightbox.activeImage !== 0) {
        Lightbox.changeData(Lightbox.activeImage - 1);
      }

    }
    // Display next image (n, ->).
    else if (Lightbox.checkKey(Lightbox.keysNext, key, keycode)) {
      if ((Lightbox.total > 1 && ((Lightbox.isSlideshow && Lightbox.loopSlides) || (!Lightbox.isSlideshow && Lightbox.loopItems))) || Lightbox.activeImage != (Lightbox.total - 1)) {
        Lightbox.changeData(Lightbox.activeImage + 1);
      }
    }
    // Zoom in.
    else if (Lightbox.checkKey(Lightbox.keysZoom, key, keycode) && !Lightbox.disableResize && !Lightbox.disableZoom && !Lightbox.isSlideshow && !Lightbox.isLightframe) {
      if (Lightbox.isZoomedIn) {
        Lightbox.changeData(Lightbox.activeImage, false);
      }
      else if (!Lightbox.isZoomedIn) {
        Lightbox.changeData(Lightbox.activeImage, true);
      }
      return false;
    }
    // Toggle play / pause (space).
    else if (Lightbox.checkKey(Lightbox.keysPlayPause, key, keycode) && Lightbox.isSlideshow) {

      if (Lightbox.isPaused) {
        Lightbox.togglePlayPause("lightshowPlay", "lightshowPause");
      }
      else {
        Lightbox.togglePlayPause("lightshowPause", "lightshowPlay");
      }
      return false;
    }
  },

  preloadNeighborImages: function() {

    if ((Lightbox.total - 1) > Lightbox.activeImage) {
      preloadNextImage = new Image();
      preloadNextImage.src = Lightbox.imageArray[Lightbox.activeImage + 1][0];
    }
    if (Lightbox.activeImage > 0) {
      preloadPrevImage = new Image();
      preloadPrevImage.src = Lightbox.imageArray[Lightbox.activeImage - 1][0];
    }

  },

  end: function(caller) {
    var closeClick = (caller == 'slideshow' ? false : true);
    if (Lightbox.isSlideshow && Lightbox.isPaused && !closeClick) {
      return;
    }
    // To prevent double clicks on navigation links.
    if (Lightbox.inprogress === true && caller != 'forceClose') {
      return;
    }
    Lightbox.disableKeyboardNav();
    $('#lightbox').hide();
    $("#lightbox2-overlay").fadeOut();
    Lightbox.isPaused = true;
    Lightbox.inprogress = false;
    Lightbox.imageArray = [];
    Lightbox.imageNum = 0;
    // Replaces calls to showSelectBoxes() and showFlash() in original
    // lightbox2.
    Lightbox.toggleSelectsFlash('visible');
    if (Lightbox.isSlideshow) {
      for (var i = 0; i < Lightbox.slideIdCount; i++) {
        window.clearTimeout(Lightbox.slideIdArray[i]);
      }
      $('#lightshowPause, #lightshowPlay').hide();
    }
    else if (Lightbox.isLightframe) {
      $('#frameContainer').empty().hide();
    }
    else if (Lightbox.isVideo || Lightbox.isModal) {
      if (!Lightbox.auto_modal) {
        $('#modalContainer').hide().html("");
      }
      Lightbox.auto_modal = false;
    }
  },


  // getPageScroll()
  // Returns array with x,y page scroll values.
  // Core code from - quirksmode.com.
  getPageScroll : function() {

    var xScroll, yScroll;

    if (self.pageYOffset || self.pageXOffset) {
      yScroll = self.pageYOffset;
      xScroll = self.pageXOffset;
    }
    else if (document.documentElement && (document.documentElement.scrollTop || document.documentElement.scrollLeft)) {  // Explorer 6 Strict.
      yScroll = document.documentElement.scrollTop;
      xScroll = document.documentElement.scrollLeft;
    }
    else if (document.body) {// All other Explorers.
      yScroll = document.body.scrollTop;
      xScroll = document.body.scrollLeft;
    }

    arrayPageScroll = [xScroll,yScroll];
    return arrayPageScroll;
  },

  // getPageSize()
  // Returns array with page width, height and window width, height.
  // Core code from - quirksmode.com.
  // Edit for Firefox by pHaez.

  getPageSize : function() {

    var xScroll, yScroll;

    if (window.innerHeight && window.scrollMaxY) {
      xScroll = window.innerWidth + window.scrollMaxX;
      yScroll = window.innerHeight + window.scrollMaxY;
    }
    else if (document.body.scrollHeight > document.body.offsetHeight) { // All but Explorer Mac.
      xScroll = document.body.scrollWidth;
      yScroll = document.body.scrollHeight;
    }
    else { // Explorer Mac...would also work in Explorer 6 Strict, Mozilla and Safari.
      xScroll = document.body.offsetWidth;
      yScroll = document.body.offsetHeight;
    }

    var windowWidth, windowHeight;

    if (self.innerHeight) { // All except Explorer.
      if (document.documentElement.clientWidth) {
        windowWidth = document.documentElement.clientWidth;
      }
      else {
        windowWidth = self.innerWidth;
      }
      windowHeight = self.innerHeight;
    }
    else if (document.documentElement && document.documentElement.clientHeight) { // Explorer 6 Strict Mode.
      windowWidth = document.documentElement.clientWidth;
      windowHeight = document.documentElement.clientHeight;
    }
    else if (document.body) { // Other Explorers.
      windowWidth = document.body.clientWidth;
      windowHeight = document.body.clientHeight;
    }
    // For small pages with total height less than height of the viewport.
    if (yScroll < windowHeight) {
      pageHeight = windowHeight;
    }
    else {
      pageHeight = yScroll;
    }
    // For small pages with total width less than width of the viewport.
    if (xScroll < windowWidth) {
      pageWidth = xScroll;
    }
    else {
      pageWidth = windowWidth;
    }
    arrayPageSize = new Array(pageWidth,pageHeight,windowWidth,windowHeight);
    return arrayPageSize;
  },


  // pause(numberMillis)
  pause : function(ms) {
    var date = new Date();
    var curDate = null;
    do { curDate = new Date(); }
    while (curDate - date < ms);
  },


  // toggleSelectsFlash()
  // Hide / unhide select lists and flash objects as they appear above the
  // lightbox in some browsers.
  toggleSelectsFlash: function (state) {
    if (state == 'visible') {
      $("select.lightbox_hidden, embed.lightbox_hidden, object.lightbox_hidden").show();
    }
    else if (state == 'hide') {
      $("select:visible, embed:visible, object:visible").not('#lightboxAutoModal select, #lightboxAutoModal embed, #lightboxAutoModal object').addClass("lightbox_hidden");
      $("select.lightbox_hidden, embed.lightbox_hidden, object.lightbox_hidden").hide();
    }
  },


  // parseRel()
  parseRel: function (link) {
    var parts = [];
    parts["rel"] = parts["title"] = parts["group"] = parts["style"] = parts["flashvars"] = null;
    if (!$(link).attr('rel')) return parts;
    parts["rel"] = $(link).attr('rel').match(/\w+/)[0];

    if ($(link).attr('rel').match(/\[(.*)\]/)) {
      var info = $(link).attr('rel').match(/\[(.*?)\]/)[1].split('|');
      parts["group"] = info[0];
      parts["style"] = info[1];
      if (parts["style"] != undefined && parts["style"].match(/flashvars:\s?(.*?);/)) {
        parts["flashvars"] = parts["style"].match(/flashvars:\s?(.*?);/)[1];
      }
    }
    if ($(link).attr('rel').match(/\[.*\]\[(.*)\]/)) {
      parts["title"] = $(link).attr('rel').match(/\[.*\]\[(.*)\]/)[1];
    }
    return parts;
  },

  // setStyles()
  setStyles: function(item, styles) {
    item.width = Lightbox.iframe_width;
    item.height = Lightbox.iframe_height;
    item.scrolling = "auto";

    if (!styles) return item;
    var stylesArray = styles.split(';');
    for (var i = 0; i< stylesArray.length; i++) {
      if (stylesArray[i].indexOf('width:') >= 0) {
        var w = stylesArray[i].replace('width:', '');
        item.width = jQuery.trim(w);
      }
      else if (stylesArray[i].indexOf('height:') >= 0) {
        var h = stylesArray[i].replace('height:', '');
        item.height = jQuery.trim(h);
      }
      else if (stylesArray[i].indexOf('scrolling:') >= 0) {
        var scrolling = stylesArray[i].replace('scrolling:', '');
        item.scrolling = jQuery.trim(scrolling);
      }
      else if (stylesArray[i].indexOf('overflow:') >= 0) {
        var overflow = stylesArray[i].replace('overflow:', '');
        item.overflow = jQuery.trim(overflow);
      }
    }
    return item;
  },


  // togglePlayPause()
  // Hide the pause / play button as appropriate.  If pausing the slideshow also
  // clear the timers, otherwise move onto the next image.
  togglePlayPause: function(hideId, showId) {
    if (Lightbox.isSlideshow && hideId == "lightshowPause") {
      for (var i = 0; i < Lightbox.slideIdCount; i++) {
        window.clearTimeout(Lightbox.slideIdArray[i]);
      }
    }
    $('#' + hideId).hide();
    $('#' + showId).show();

    if (hideId == "lightshowPlay") {
      Lightbox.isPaused = false;
      if (!Lightbox.loopSlides && Lightbox.activeImage == (Lightbox.total - 1)) {
        Lightbox.end();
      }
      else if (Lightbox.total > 1) {
        Lightbox.changeData(Lightbox.activeImage + 1);
      }
    }
    else {
      Lightbox.isPaused = true;
    }
  },

  triggerLightbox: function (rel_type, rel_group) {
    if (rel_type.length) {
      if (rel_group && rel_group.length) {
        $("a[rel^='" + rel_type +"\[" + rel_group + "\]'], area[rel^='" + rel_type +"\[" + rel_group + "\]']").eq(0).trigger("click");
      }
      else {
        $("a[rel^='" + rel_type +"'], area[rel^='" + rel_type +"']").eq(0).trigger("click");
      }
    }
  },

  detectMacFF2: function() {
    var ua = navigator.userAgent.toLowerCase();
    if (/firefox[\/\s](\d+\.\d+)/.test(ua)) {
      var ffversion = new Number(RegExp.$1);
      if (ffversion < 3 && ua.indexOf('mac') != -1) {
        return true;
      }
    }
    return false;
  },

  checkKey: function(keys, key, code) {
    return (jQuery.inArray(key, keys) != -1 || jQuery.inArray(String(code), keys) != -1);
  },

  filterXSS: function(str, allowed_tags) {
    var output = "";
    var prefix = Drupal.settings.pathPrefix;
    if (!prefix) prefix = '';
    $.ajax({
      url: Drupal.settings.basePath + prefix + '?q=system/lightbox2/filter-xss',
      data: {
        'string' : str,
        'allowed_tags' : allowed_tags
      },
      type: "POST",
      async: false,
      dataType:  "json",
      success: function(data) {
        output = data;
      }
    });
    return output;
  }

};

// Initialize the lightbox.
Drupal.behaviors.initLightbox = {
  attach: function(context) {

  $('body:not(.lightbox-processed)', context).addClass('lightbox-processed').each(function() {
    Lightbox.initialize();
    return false; // Break the each loop.
  });

  // Attach lightbox to any links with lightbox rels.
  Lightbox.initList(context);
  $('#lightboxAutoModal', context).triggerHandler('click');
  }
};
})(jQuery);
;
/**
 * @file better_exposed_filters.js
 *
 * Provides some client-side functionality for the Better Exposed Filters module
 */
(function ($) {
  Drupal.behaviors.betterExposedFilters = {
    attach: function(context) {
      // Add highlight class to checked checkboxes for better theming
      $('.bef-tree input[type=checkbox], .bef-checkboxes input[type=checkbox]')
        // Highlight newly selected checkboxes
        .change(function() {
          _bef_highlight(this, context);
        })
        .filter(':checked').closest('.form-item', context).addClass('highlight')
      ;
    }
  };

  Drupal.behaviors.betterExposedFiltersSelectAllNone = {
    attach: function(context) {

      /*
       * Add Select all/none links to specified checkboxes
       */
      var selected = $('.form-checkboxes.bef-select-all-none:not(.bef-processed)');
      if (selected.length) {
        var selAll = Drupal.t('Select All');
        var selNone = Drupal.t('Select None');

        // Set up a prototype link and event handlers
        var link = $('<a class="bef-toggle" href="#">'+ selAll +'</a>')
        link.click(function(event) {
          // Don't actually follow the link...
          event.preventDefault();
          event.stopPropagation();

          if (selAll == $(this).text()) {
            // Select all the checkboxes
            $(this)
              .html(selNone)
              .siblings('.bef-checkboxes, .bef-tree')
                .find('.form-item input:checkbox').each(function() {
                  $(this).attr('checked', true);
                  _bef_highlight(this, context);
                })
              .end()

              // attr() doesn't trigger a change event, so we do it ourselves. But just on
              // one checkbox otherwise we have many spinning cursors
              .find('input[type=checkbox]:first').change()
            ;
          }
          else {
            // Unselect all the checkboxes
            $(this)
              .html(selAll)
              .siblings('.bef-checkboxes, .bef-tree')
                .find('.form-item input:checkbox').each(function() {
                  $(this).attr('checked', false);
                  _bef_highlight(this, context);
                })
              .end()

              // attr() doesn't trigger a change event, so we do it ourselves. But just on
              // one checkbox otherwise we have many spinning cursors
              .find('input[type=checkbox]:first').change()
            ;
          }
        });

        // Add link to the page for each set of checkboxes.
        selected
          .addClass('bef-processed')
          .each(function(index) {
            // Clone the link prototype and insert into the DOM
            var newLink = link.clone(true);

            newLink.insertBefore($('.bef-checkboxes, .bef-tree', this));

            // If all checkboxes are already checked by default then switch to Select None
            if ($('input:checkbox:checked', this).length == $('input:checkbox', this).length) {
              newLink.click();
            }
          })
        ;
      }

      // Check for and initialize datepickers
      var befSettings = Drupal.settings.better_exposed_filters;
      if (befSettings && befSettings.datepicker && befSettings.datepicker_options && $.fn.datepicker) {
        var opt = befSettings.datepicker_options.dateformat ? {dateFormat: befSettings.datepicker_options.dateformat} : {};
        $('.bef-datepicker').datepicker(opt);
      }

    }                   // attach: function() {
  };                    // Drupal.behaviors.better_exposed_filters = {

  Drupal.behaviors.betterExposedFiltersAllNoneNested = {
    attach:function (context, settings) {
      $('.form-checkboxes.bef-select-all-none-nested li').has('ul').once('bef-all-none-nested', function () {
        $(this)
          // To respect term depth, check/uncheck child term checkboxes.
          .find('input.form-checkboxes:first')
          .click(function() {
            $(this).parents('li:first').find('ul input.form-checkboxes').attr('checked', $(this).attr('checked'));
          })
          .end()
          // When a child term is checked or unchecked, set the parent term's
          // status.
          .find('ul input.form-checkboxes')
          .click(function() {
            var checked = $(this).attr('checked');
            // Determine the number of unchecked sibling checkboxes.
            var ct = $(this).parents('ul:first').find('input.form-checkboxes:not(:checked)').size();
            // If the child term is unchecked, uncheck the parent.
            // If all sibling terms are checked, check the parent.
            if (!checked || !ct) {
              $(this).parents('li:first').parents('li:first').find('input.form-checkboxes:first').attr('checked', checked);
            }
          });
      });
    }
  }

  Drupal.behaviors.better_exposed_filters_slider = {
    attach: function(context, settings) {
      var befSettings = settings.better_exposed_filters;
      if (befSettings && befSettings.slider && befSettings.slider_options) {
        $.each(befSettings.slider_options, function(i, sliderOptions) {
          // Only make one slider per filter.
          $("#" + sliderOptions.viewId + " #edit-" + sliderOptions.id + "-wrapper").once('slider-filter', function() {
            var $input = $(this).find('input[type=text]');

            // This is a "between" or "not between" filter with two values.
            if ($input.length == 2) {
              var $min = $input.parent().find('input#edit-' + sliderOptions.id + '-min'),
                  $max = $input.parent().find('input#edit-' + sliderOptions.id + '-max'),
                  default_min,
                  default_max;

              if (!$min.length || !$max.length) {
                return;
              }

              // Get the default values.
              // We use slider min & max if there are no defaults.
              default_min = parseFloat(($min.val() == '') ? sliderOptions.min : $min.val(), 10);
              default_max = parseFloat(($max.val() == '') ? sliderOptions.max : $max.val(), 10);
              // Set the element value in case we are using the slider min & max.
              $min.val(default_min);
              $max.val(default_max);

              $min.parents('div.views-widget').after(
                $('<div class="bef-slider"></div>').slider({
                  range: true,
                  min: parseFloat(sliderOptions.min, 10),
                  max: parseFloat(sliderOptions.max, 10),
                  step: parseFloat(sliderOptions.step, 10),
                  animate: sliderOptions.animate ? sliderOptions.animate : false,
                  orientation: sliderOptions.orientation,
                  values: [default_min, default_max],
                  // Update the textfields as the sliders are moved
                  slide: function (event, ui) {
                    $min.val(ui.values[0]);
                    $max.val(ui.values[1]);
                  },
                  // This fires when the value is set programmatically or the
                  // stop event fires.
                  // This takes care of the case that a user enters a value
                  // into the text field that is not a valid step of the slider.
                  // In that case the slider will go to the nearest step and
                  // this change event will update the text area.
                  change: function (event, ui) {
                    $min.val(ui.values[0]);
                    $max.val(ui.values[1]);
                  },
                  // Attach stop listeners.
                  stop: function(event, ui) {
                    // Click the auto submit button.
                    $(this).parents('form').find('.ctools-auto-submit-click').click();
                  }
                })
              );

              // Update the slider when the fields are updated.
              $min.blur(function() {
                befUpdateSlider($(this), 0, sliderOptions);
              });
              $max.blur(function() {
                befUpdateSlider($(this), 1, sliderOptions);
              });
            }
            // This is single value filter.
            else if ($input.length == 1) {
              if ($input.attr('id') != 'edit-' + sliderOptions.id) {
                return;
              }

              // Get the default value. We use slider min if there is no default.
              var default_value = parseFloat(($input.val() == '') ? sliderOptions.min : $input.val(), 10);
              // Set the element value in case we are using the slider min.
              $input.val(default_value);

              $input.parents('div.views-widget').after(
                $('<div class="bef-slider"></div>').slider({
                  min: parseFloat(sliderOptions.min, 10),
                  max: parseFloat(sliderOptions.max, 10),
                  step: parseFloat(sliderOptions.step, 10),
                  animate: sliderOptions.animate ? sliderOptions.animate : false,
                  orientation: sliderOptions.orientation,
                  value: default_value,
                  // Update the textfields as the sliders are moved.
                  slide: function (event, ui) {
                    $input.val(ui.value);
                  },
                  // This fires when the value is set programmatically or the
                  // stop event fires.
                  // This takes care of the case that a user enters a value
                  // into the text field that is not a valid step of the slider.
                  // In that case the slider will go to the nearest step and
                  // this change event will update the text area.
                  change: function (event, ui) {
                    $input.val(ui.value);
                  },
                  // Attach stop listeners.
                  stop: function(event, ui) {
                    // Click the auto submit button.
                    $(this).parents('form').find('.ctools-auto-submit-click').click();
                  }
                })
              );

              // Update the slider when the field is updated.
              $input.blur(function() {
                befUpdateSlider($(this), null, sliderOptions);
              });
            }
            else {
              return;
            }
          })
        });
      }
    }
  };

  // This is only needed to provide ajax functionality
  Drupal.behaviors.better_exposed_filters_select_as_links = {
    attach: function(context, settings) {

      $('.bef-select-as-links', context).once(function() {
        var $element = $(this);

        // Check if ajax submission is enabled. If it's not enabled then we
        // don't need to attach our custom submission handling, because the
        // links are already properly built.

        // First check if any ajax views are contained in the current page.
        if (typeof settings.views == 'undefined' || typeof settings.views.ajaxViews == 'undefined') {
          return;
        }

        // Now check that the view for which the current filter block is used,
        // is part of the configured ajax views.
        var $uses_ajax = false;
        $.each(settings.views.ajaxViews, function(i, item) {
          var $view_name = item.view_name.replace(/_/g, '-');
          var $view_display_id = item.view_display_id.replace(/_/g, '-');
          var $id = 'views-exposed-form-' + $view_name + '-' + $view_display_id;
          var $form_id = $element.parents('form').attr('id');
          if ($form_id == $id) {
            $uses_ajax = true;
            return;
          }
        });

        // If no ajax is used for form submission, we quit here.
        if (!$uses_ajax) {
          return;
        }

        // Attach selection toggle and form submit on click to each link.
        $(this).find('a').click(function(event) {
          var $wrapper = $(this).parents('.bef-select-as-links');
          var $options = $wrapper.find('select option');
          // We have to prevent the page load triggered by the links.
          event.preventDefault();
          event.stopPropagation();
          // Un select old select value.
          $wrapper.find('select option').removeAttr('selected');

          // Set the corresponding option inside the select element as selected.
          var link_text = $(this).text();
          $selected = $options.filter(function() {
            return $(this).text() == link_text;
          });
          $selected.attr('selected', 'selected');
          $wrapper.find('.bef-new-value').val($selected.val());
          $wrapper.find('a').removeClass('active');
          $(this).addClass('active');
          // Submit the form.
          $wrapper.parents('form').find('.views-submit-button *[type=submit]').click();
        });
      });
    }
  };

  Drupal.behaviors.betterExposedFiltersRequiredFilter = {
    attach: function(context, settings) {
      // Required checkboxes should re-check all inputs if a user un-checks
      // them all.
      $('.bef-select-as-checkboxes', context).once('bef-required-filter').ajaxComplete(function (e, xhr, s) {
        var $element = $(this);

        if (typeof settings.views == 'undefined' || typeof settings.views.ajaxViews == 'undefined') {
          return;
        }

        // Now check that the view for which the current filter block is used,
        // is part of the configured ajax views.
        var $view_name;
        var $view_display_id;
        var $uses_ajax = false;
        $.each(settings.views.ajaxViews, function(i, item) {
          $view_name = item.view_name;
          $view_display_id = item.view_display_id;
          var $id = 'views-exposed-form-' + $view_name.replace(/_/g, '-') + '-' + $view_display_id.replace(/_/g, '-');
          var $form_id = $element.parents('form').attr('id');
          if ($form_id == $id) {
            $uses_ajax = true;
            return;
          }
        });

        var $filter_name = $('input', this).attr('name').slice(0, -2);
        if (Drupal.settings.better_exposed_filters.views[$view_name].displays[$view_display_id].filters[$filter_name].required && $('input:checked', this).length == 0) {
          $('input', this).prop('checked', true);
        }
      });
    }
  }

  /*
   * Helper functions
   */

  /**
   * Adds/Removes the highlight class from the form-item div as appropriate
   */
  function _bef_highlight(elem, context) {
    $elem = $(elem, context);
    $elem.attr('checked')
      ? $elem.closest('.form-item', context).addClass('highlight')
      : $elem.closest('.form-item', context).removeClass('highlight');
  }

  /**
   * Update a slider when a related input element is changed.
   *
   * We don't need to check whether the new value is valid based on slider min,
   * max, and step because the slider will do that automatically and then we
   * update the textfield on the slider's change event.
   *
   * We still have to make sure that the min & max values of a range slider
   * don't pass each other though, however once this jQuery UI bug is fixed we
   * won't have to. - http://bugs.jqueryui.com/ticket/3762
   *
   * @param $el
   *   A jQuery object of the updated element.
   * @param valIndex
   *   The index of the value for a range slider or null for a non-range slider.
   * @param sliderOptions
   *   The options for the current slider.
   */
  function befUpdateSlider($el, valIndex, sliderOptions) {
    var val = parseFloat($el.val(), 10),
        currentMin = $el.parents('div.views-widget').next('.bef-slider').slider('values', 0),
        currentMax = $el.parents('div.views-widget').next('.bef-slider').slider('values', 1);
    // If we have a range slider.
    if (valIndex != null) {
      // Make sure the min is not more than the current max value.
      if (valIndex == 0 && val > currentMax) {
        val = currentMax;
      }
      // Make sure the max is not more than the current max value.
      if (valIndex == 1 && val < currentMin) {
        val = currentMin;
      }
      // If the number is invalid, go back to the last value.
      if (isNaN(val)) {
        val = $el.parents('div.views-widget').next('.bef-slider').slider('values', valIndex);
      }
    }
    else {
      // If the number is invalid, go back to the last value.
      if (isNaN(val)) {
        val = $el.parents('div.views-widget').next('.bef-slider').slider('value');
      }
    }
    // Make sure we are a number again.
    val = parseFloat(val, 10);
    // Set the slider to the new value.
    // The slider's change event will then update the textfield again so that
    // they both have the same value.
    if (valIndex != null) {
      $el.parents('div.views-widget').next('.bef-slider').slider('values', valIndex, val);
    }
    else {
      $el.parents('div.views-widget').next('.bef-slider').slider('value', val);
    }
  }

}) (jQuery);
;
(function($){
/**
 * To make a form auto submit, all you have to do is 3 things:
 *
 * ctools_add_js('auto-submit');
 *
 * On gadgets you want to auto-submit when changed, add the ctools-auto-submit
 * class. With FAPI, add:
 * @code
 *  '#attributes' => array('class' => array('ctools-auto-submit')),
 * @endcode
 *
 * If you want to have auto-submit for every form element,
 * add the ctools-auto-submit-full-form to the form. With FAPI, add:
 * @code
 *   '#attributes' => array('class' => array('ctools-auto-submit-full-form')),
 * @endcode
 *
 * If you want to exclude a field from the ctool-auto-submit-full-form auto submission,
 * add the class ctools-auto-submit-exclude to the form element. With FAPI, add:
 * @code
 *   '#attributes' => array('class' => array('ctools-auto-submit-exclude')),
 * @endcode
 *
 * Finally, you have to identify which button you want clicked for autosubmit.
 * The behavior of this button will be honored if it's ajaxy or not:
 * @code
 *  '#attributes' => array('class' => array('ctools-use-ajax', 'ctools-auto-submit-click')),
 * @endcode
 *
 * Currently only 'select', 'radio', 'checkbox' and 'textfield' types are supported. We probably
 * could use additional support for HTML5 input types.
 */

Drupal.behaviors.CToolsAutoSubmit = {
  attach: function(context) {
    // 'this' references the form element
    function triggerSubmit (e) {
      if ($.contains(document.body, this)) {
        var $this = $(this);
        if (!$this.hasClass('ctools-ajaxing')) {
          $this.find('.ctools-auto-submit-click').click();
        }
      }
    }

    // the change event bubbles so we only need to bind it to the outer form
    $('form.ctools-auto-submit-full-form', context)
      .add('.ctools-auto-submit', context)
      .filter('form, select, input:not(:text, :submit)')
      .once('ctools-auto-submit')
      .change(function (e) {
        // don't trigger on text change for full-form
        if ($(e.target).is(':not(:text, :submit, .ctools-auto-submit-exclude)')) {
          triggerSubmit.call(e.target.form);
        }
      });

    // e.keyCode: key
    var discardKeyCode = [
      16, // shift
      17, // ctrl
      18, // alt
      20, // caps lock
      33, // page up
      34, // page down
      35, // end
      36, // home
      37, // left arrow
      38, // up arrow
      39, // right arrow
      40, // down arrow
       9, // tab
      13, // enter
      27  // esc
    ];
    // Don't wait for change event on textfields
    $('.ctools-auto-submit-full-form input:text, input:text.ctools-auto-submit', context)
      .filter(':not(.ctools-auto-submit-exclude)')
      .once('ctools-auto-submit', function () {
        // each textinput element has his own timeout
        var timeoutID = 0;
        $(this)
          .bind('keydown keyup', function (e) {
            if ($.inArray(e.keyCode, discardKeyCode) === -1) {
              timeoutID && clearTimeout(timeoutID);
            }
          })
          .keyup(function(e) {
            if ($.inArray(e.keyCode, discardKeyCode) === -1) {
              timeoutID = setTimeout($.proxy(triggerSubmit, this.form), 500);
            }
          })
          .bind('change', function (e) {
            if ($.inArray(e.keyCode, discardKeyCode) === -1) {
              timeoutID = setTimeout($.proxy(triggerSubmit, this.form), 500);
            }
          });
      });
  }
}
})(jQuery);
;
(function($) {
  Drupal.behaviors.chosen = {
    attach: function(context, settings) {
      settings.chosen = settings.chosen || Drupal.settings.chosen;

      // Prepare selector and add unwantend selectors.
      var selector = settings.chosen.selector;

      // Function to prepare all the options together for the chosen() call.
      var getElementOptions = function (element) {
        var options = $.extend({}, settings.chosen.options);

        // The width default option is considered the minimum width, so this
        // must be evaluated for every option.
        if ($(element).width() < settings.chosen.minimum_width) {
          options.width = settings.chosen.minimum_width + 'px';
        }
        else {
          options.width = $(element).width() + 'px';
        }

        // Some field widgets have cardinality, so we must respect that.
        // @see chosen_pre_render_select()
        if ($(element).attr('multiple') && $(element).data('cardinality')) {
          options.max_selected_options = $(element).data('cardinality');
        }

        return options;
      };

      // Process elements that have opted-in for Chosen.
      // @todo Remove support for the deprecated chosen-widget class.
      $('select.chosen-enable, select.chosen-widget', context).once('chosen', function() {
        options = getElementOptions(this);
        $(this).chosen(options);
      });

      $(selector, context)
        // Disabled on:
        // - Field UI
        // - WYSIWYG elements
        // - Tabledrag weights
        // - Elements that have opted-out of Chosen
        // - Elements already processed by Chosen
        .not('#field-ui-field-overview-form select, #field-ui-display-overview-form select, .wysiwyg, .draggable select[name$="[weight]"], .draggable select[name$="[position]"], .chosen-disable, .chosen-processed')
        .filter(function() {
          // Filter out select widgets that do not meet the minimum number of
          // options.
          var minOptions = $(this).attr('multiple') ? settings.chosen.minimum_multiple : settings.chosen.minimum_single;
          if (!minOptions) {
            // Zero value means no minimum.
            return true;
          }
          else {
            return $(this).find('option').length >= minOptions;
          }
        })
        .once('chosen', function() {
          options = getElementOptions(this);
          $(this).chosen(options);
        });
    }
  };
})(jQuery);
;
