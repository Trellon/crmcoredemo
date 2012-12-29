(function($){
  Drupal.behaviors.crm_core_mail = {
    attach: function (context, settings) {
      $('span.help').each(function() {
        var help = $(this).parents('.form-wrapper').find('fieldset > div');
        $(help).dialog({
          title:Drupal.t('Replacement patterns'),
          width:700,
          autoOpen: false
        });
        $(this).click(function() {
          $(help).dialog('open');
        });
      });
    }
  };
})(jQuery);
