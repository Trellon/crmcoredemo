(function($) {
  Drupal.behaviors.customToggler = {
    attach: function(context, settings){
      
      // hide textformat tips, enable rollover for help icon
      var options = {
        title: '',
        html: true,
      };
      
      $('.tips', context).each(function(idx, val){
        var item = $(this);
        options.title = item.html();
        item.tooltip(options);
      });
      
      // do the same with descriptions for various fields
      $('.text-format-wrapper > .description', context).each(function(idx, val){
        var item = $(this);
        options.title = item.html();
        item.tooltip(options);
      });
      
      // set up all textareas to autosize
      // $('textarea', context).autosize();
      
      
      $('textarea', context).each(function(idx, val){
        var item = $(this);
        console.log('found one');
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
