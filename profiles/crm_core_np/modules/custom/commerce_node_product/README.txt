
This module is developed and maintaining by Trellon LLC, by Vladyslav Bogatyrov.

To Trellonauts:
Hi Team!
I am going to make this module a contributed one when it would be ready.
So if you have a suggestions or updated the code, please ping me - let's make it better
and contribute it together!.
Thanks!
================

This module based on using Product Reference Fields.

To use this module, first of all you have to add Product Reference Fields to
content types that you going to use for syncing with commerce products.

At this point the module works only with single-value Product Reference Fields that
can be referenced to only one product type

All syncronized field have to be the same type

At the moment there is no admin ui, but there is implemented hooks that allow you
to handle the module behaviour in most of common cases:
================

API:

hook_commerce_node_product_settings()
Use this hook to declare a product_reference fields that have to be synced.
An invoking function uses a db caching, so clear the cache after you implement it
or changed.

See a usage example:
function sf_product_event_commerce_node_product_settings () {
  $settings = array(
    'node' => array(
      'event' => array(
        'field_event_product' => array(
          'sync_fields' => array(
            'field_eventregprice' => 'commerce_price',
          ),
          'product_sku' => '[node:title]-registration-[node:created]',
          'product_title' => 'Registration for [node:title] event',
        ),
      ),
    ),
  );

  return $settings;
}

hook_commerce_node_product_allow_sync($entity, $type, $product_fieldname)
This hook invoked every time on a start of syncing process.
Yse it to handle in wnat cases the syncing should happens and where is not.
You should return FALSE if you want to deny a sync process in some cases.
If any of hook will return FALSE the syncing will not happens.

See a usage example:
function sf_product_event_commerce_node_product_allow_sync ($entity, $type, $product_fieldname) {
  if ($product_fieldname == 'field_event_product') {
    if (!empty($entity->field_eventregtype[LANGUAGE_NONE][0]['value'])
    && $entity->field_eventregtype[LANGUAGE_NONE][0]['value'] == 'internal') {
      return TRUE;
    } else {
      return FALSE;
    }
  }
}
================

ToDo: add an admin UI to allow user to select fields instances we wont to sync to products.
  
ToDo: make a synced fields configurable via UI.

ToDo: make it working with all kinds of entities.

ToDo: implement a behaviour for product reference field deleting

ToDo: implement a behaviour for one of synced fields deleting

ToDo: submit the module to D.O.

ToDo: put in order a language and token usage

ToDo: add more comments.

ToDo: add an option to select an action on entity deleting: do nothing, delete or disable.
