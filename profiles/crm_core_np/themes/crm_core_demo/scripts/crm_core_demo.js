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

      
      // console.log($('.tips', context).data());

      /*
      $(".toggler", context).once('custom-toggler').click(function(){
        $(this).next().slideToggle("slow");
        return false;
      }).next().hide();*/
      
      
      
    },
  };
})(jQuery);
