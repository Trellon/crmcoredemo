<?php

/**
 * @file
 * Custom preprocess callbacks for event registration.
 */

/**
 * Custom preprocess callback for event registration reports.
 */
function crm_core_event_registration_reports_preprocess(&$vars) {
  if (empty($vars['rows'])) {
    // get rid of csv export when the view is empty
    $vars['feed_icon'] = FALSE;
  }
}
