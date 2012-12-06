<?php

/**
 * @file
 * Support for migration into Name fields.
 */
class NameMigrateFieldHandler extends MigrateFieldHandler {

  /**
   * Declares the types of fields used.
   */
  public function __construct() {
    $this->registerTypes(array('name'));
  }

  /**
   * Converts incoming data into the proper field arrays for Name fields.
   *
   * @param object $entity
   *   The destination entity which will hold the field arrays.
   * @param array $field_info
   *   Metadata for the field being populated.
   * @param array $instance
   *   Metadata for this instance of the field being populated.
   * @param array $values
   *   Array of values to be fielded.
   *
   * @return array|null
   *   An array of name fields.
   */
  public function prepare($entity, array $field_info, array $instance, array $values) {
    $language = $this->getFieldLanguage($entity, $field_info, array());

    $return = array();

    // Setup the standard Field API array for saving.
    $delta = 0;
    foreach ($values as $name) {
      foreach (_name_translations() as $key => $label) {
        $return[$language][$delta][$key] = isset($name[$key]) ? $name[$key] : NULL;
      }
      $delta++;
    }
    if (empty($return)) {
      $return = NULL;
    }
    return $return;
  }
}
