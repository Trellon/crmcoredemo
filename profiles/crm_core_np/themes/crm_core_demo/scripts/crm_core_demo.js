(function($) {
  Drupal.behaviors.customToggler = {
    attach: function(context, settings){
      
      // hide textformat tips, enable rollover for help icon
      var options = {
        title: '',
        html: true,
      };
      
      // apply tooltips to tips for html formats
      $('.tips', context).each(function(idx, val){
        var item = $(this);
        options.title = item.html();
        item.tooltip(options);
      });
      
      // we need these tips to apply selectively, not throughout the entire interface
      // maybe limit them to content entry forms?
      
      // do the same with descriptions for various fields
      $('.text-format-wrapper > .description', context).each(function(idx, val){
        var item = $(this),
        label = item.parent().children('.control-group').children('LABEL');
        
        options.title = item.html();
        item.tooltip(options);
        
        // position the tip just to the right of the label
        
      });
      
      // do the same with textfields
      $('.form-type-textfield > .controls > .help-block', context).each(function(idx, val){
        var item = $(this), 
        label = item.parents('.control-group').children('LABEL');
        options.title = item.html();
        item.tooltip(options);
        
        // position the tip just to the right of the label
        // console.log(label);
        item.css('left', label.width() + 20);
        
      });
      
      // do the same with image upload fields
      
      // 
      $('.form-type-managed-file > .controls > .help-block', context).each(function(idx, val){
        var item = $(this), 
        label = item.parents('.control-group').children('LABEL');
        options.title = item.html();
        item.tooltip(options);
        
        // position the tip just to the right of the label
        // console.log(label);
        item.css('left', label.width() + 20);
        
      });
      
      // set up all textareas to autosize
      $('textarea', context).each(function(idx, val){
        var item = $(this);
        item.expandingTextarea();
      });
      
      // mods for views bulk operations
      // creates click events for 'altered' vbo menus using markup from bootstrap. 
      $('.vbo_btn_group').each(function(){
        var vbo_select = $(this).next().find('SELECT'),
        vbo_submit = $(this).next().find('.form-submit');
        $(this).find('.vbo_action').bind('click', function(){
          vbo_select.val($(this).attr('href'));
          vbo_submit.click();
          return false;
        });
      });
      
      // toggles disabled states on vbo forms
      $('.vbo-select, .vbo-table-select-all').each(function(){
        $(this).bind('click', function(){
          $('.vbo_action_link').removeClass('disabled');
          var any_selected = $('.vbo-select').is(':checked');
          if(!any_selected){
            $('.vbo_action_link').addClass('disabled');
          }
        });
      });
      
      // sets up masonry for blog posts
      var container = $('.view-crm-core-blog > .view-content');
      
      container.masonry({
        // options
        itemSelector  : '.views-row',
        isResizable   : true,
        isAnimated: true,
        animationOptions: {
          duration: 240,
          easing: 'linear',
          queue: false
        }        
        
      });
      
      
      
    },
  };
})(jQuery);
