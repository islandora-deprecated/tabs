// $Id$

Drupal.behaviors.tabs = function (context) {
  // Set the active class to the first tab with an form error.
  $('.drupal-tabs ul').children('li').each( function() {
    if ($($(this).find('a').attr('href')).find('div.form-item .error:first').size()) {
      $(this).addClass('error').addClass('active');
    }
  });

  var fx = {duration: Drupal.settings.tabs.speed};
  if (Drupal.settings.tabs.fade) {
    fx.opacity = 'toggle';
  }
  if (Drupal.settings.tabs.slide) {
    fx.height = 'toggle';
  }
  // Process custom tabs.
  var selected = null;
  $('.drupal-tabs:not(.tabs-processed)', context)
    .addClass('tabs-processed')
    .each(function () {
      if ($(this).is('.tabs-navigation')) {
        Drupal.tabsNavigation(this);
      }
    })
    .find('> ul')
    .each(function () {
      var href = $(this).find('li.active:first a').attr('href');
      selected = href ? href.substring(href.indexOf('#')) : 1;
    })
    .tabs({
      select: selected,
      selectedClass: 'active',
      fx: fx
    })
    .addClass('tabs')
    .each(function () {
      // Assign secondary class to nested tabsets.
      var newClass = $(this).parents('.drupal-tabs').size() > 1 ? 'secondary' : 'primary';
      $(this).addClass(newClass);
    })
    .after('<span class="clear"></span>')
    .end()
    .show();
};

Drupal.tabsNavigation = function(elt) {
  // Extract tabset name.
  var tabsetName = $(elt).get(0).id.substring(5);
  var $tabs = $(elt).tabs();
  var i = 1;
  var $tabsContent = $('div.' + 'tabs-' + tabsetName, elt);
  var count = $tabsContent.size();
  $tabsContent.each(function() {
    if ((i > 1) || (i < count)) {
      $(this).append('<span class="clear"></span><div class="tabs-nav-link-sep"></div>');
    }
    if (i > 1) {
      var link = $(document.createElement('a'))
        .append(Drupal.settings.tabs.previous_text)
        .attr('id', 'tabs-' + tabsetName + '-previous-link-' + i)
        .addClass('tabs-nav-previous')
        .click(function() {
          var tabIndex = parseInt($(this).attr('id').substring($(this).attr('id').lastIndexOf('-') + 1)) -1;
          $tabs.tabs('select', tabIndex - 1);
          //Drupal.scrollTo(elt);
          return false;
        });
      $(this).append(link);
    }
    if (i < count) {
      var link = $(document.createElement('a'))
        .append(Drupal.settings.tabs.next_text)
        .attr('id', 'tabs-' + tabsetName + '-next-button-' + i)
        .addClass('tabs-nav-next')
        .click(function() {
          var tabIndex = parseInt($(this).attr('id').substring($(this).attr('id').lastIndexOf('-') + 1)) -1;
          $tabs.tabs('select', tabIndex + 1);
          //Drupal.scrollTo(elt);
          return false;
        });
      $(this).append(link);
    }
    $tabsContent.append('<span class="clear"></span>');
    i++;
  });
};

