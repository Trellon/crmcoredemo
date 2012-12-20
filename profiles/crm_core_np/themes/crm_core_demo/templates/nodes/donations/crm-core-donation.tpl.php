<?php
/**
 * Template for donation pages
 *
 * @variables
 *
 * $message      The message which shows the url of the live PDP under the user/%/pdp path
 * $header       The donation page header
 * $amount       The donation amount section of the page
 * $dedication   In honor of, in memory of selections
 * $billing      The billing block 
 * $payment      The payment information block
 * $footer       The donation page footer
 *
 */
?>

<div class="row-fluid">
	<div class="span12">
    <?php if ($message): ?>
      <?php print $message; ?>
    <?php endif; ?>
    <?php if ($payment_method): ?>
      <?php print $payment_method; ?>
    <?php endif; ?>
	</div>
</div>

<div class="row-fluid">
	<div class="span6">
    <div id="donation_header">
      <?php print $header; ?>
    </div>
	</div>
	<div class="span6 well">
    <div id="amounts">
      <?php print $amount; ?>
    </div>
    <div id="dedication">
      <?php print $dedication; ?>
    </div>
    <div id="billing">
      <?php print $billing; ?>
    </div>
    <div id="payment">
      <?php print $payment; ?>
    </div>
    <?php print $submit; ?>
	</div>
</div>

<div class="row-fluid">
	<div class="span12">
    <div id="donation_footer">
      <?php print $footer; ?>
    </div>

	</div>
</div>


  <?php print $rest; ?>
