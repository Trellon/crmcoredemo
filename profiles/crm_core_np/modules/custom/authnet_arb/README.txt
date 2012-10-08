
Please install authorize.net SDK before enable this module.
Download the PHP vesrsion of SDK from http://developer.authorize.net/downloads/
  and place anet_php_sdk folder to sites/all/libraries or to authnet_arb module folder.

You can found additional info about SDK usage for ARB transactions on
  http://developer.authorize.net/api/arb/
  http://developer.authorize.net
  http://community.developer.authorize.net

Authorize.net SDK requirements:
  - cURL PHP Extension
  - PHP 5.2+
  - An Authorize.Net Merchant Account or Test Account. You can get a
  - free test account at http://developer.authorize.net/testaccount/


This module provide an API to authorize.net ARB

To allow authnet_arb module to process silentpost requests from an authorize.net
  you have configure a silentpost URL in your authorize.net account to
  http://<yourdomain>/authnet-arb-silentpost

The module has integration with commerce (drupal.org/project/commerce):
  it stores subscription information in $order->data
  and saves silentpost requests as a commerce_payment transactions attached to the order.

After enable the module go to admin/config/authnet-arb and put the authorize.net auth info.
The module may use authorize.net auth info as default configured for commerce_authnet if it is enabled.


Silentpost Testing:
authorize.net will send a silentpost request after you send a subscription only in a next day.
Obviously this is make a debugging and testing mutch harder.
To make it easier the module suggest you to request by browser a special url:
http://<yoursite>/authnet-arb-silentpost-test
When you will request it (actually with no post data) the module will emulate a silentpost request
by using not real but syntetic post data in format equal to ARB silentpost.
You may see the syntetic post data in authet_arb_get_sample_silentpost_post() function.
If you want to thange the data you can edit the function or pass parameters you want to change by GET, like:
http://<yoursite>/authnet-arb-silentpost-test/?x_response_code=3&x_response_reason_code=4


API:

/*
 * @param array @post
 *   $_POST array passed by authorize.net while silentpost request to your site
 */
hook_authnet_arb_silentpost($post)

Invoking only if request made by ARB and if md5 hash validation is passed
Using this hook you can implement any custom reaction on silentpost request.

/*
 * @param object @order
 *   A commerce order object
 */
hook_authet_arb_commerce_set_recurring($order)

Invoking while building ARB payment pane by commerce.
By default, user enter payment recurring settings by himself.
You may want to disable recurring settings to user and set recurring settings programaticly
in depend of product settings or other order properties.
Is this case use this hook and return reccuring settings you want to set:
return $recurring = array('period' => 'months','step' => 12);
'period' value allow values 'month' or 'days'
'step' value allow values from 7 to 365  for 'days' period and from 1 to 12 for 'years'
