(function ($) {
$(document).ready(function() {
  $("input[name='activity[field_donation_dedication_type][und]']").click(function() {
    if ($(this).val() != '_none') {
      $('#dedication_info').show();
    } else {
      $('#dedication_info').hide();
    }
  })
})  
}) (jQuery);

