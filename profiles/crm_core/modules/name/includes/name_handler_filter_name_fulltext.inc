<?php

/**
 * Field handler to provide simple renderer that allows linking to a entity.
 */
class name_handler_filter_name_fulltext extends views_handler_filter {
  var $always_multiple = TRUE;

  function option_definition() {
    $options = parent::option_definition();

    $options['operator']['default'] = 'contains';

    return $options;
  }

  /**
   * This kind of construct makes it relatively easy for a child class
   * to add or remove functionality by overriding this function and
   * adding/removing items from this array.
   */
  function operators() {
    return array(
       'contains' => array(
        'title' => t('Contains'),
        'short' => t('contains'),
        'method' => 'op_contains',
        'values' => 1,
      ),
      'word' => array(
        'title' => t('Contains any word'),
        'short' => t('has word'),
        'method' => 'op_word',
        'values' => 1,
      ),
      'allwords' => array(
        'title' => t('Contains all words'),
        'short' => t('has all'),
        'method' => 'op_word',
        'values' => 1,
      ),
    );
  }


  /**
   * Build strings from the operators() for 'select' options.
   */
  function operator_options($which = 'title') {
    $options = array();
    foreach ($this->operators() as $id => $info) {
      $options[$id] = $info[$which];
    }

    return $options;
  }

  /**
   * Provide a simple textfield for equality.
   */
  function value_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'textfield',
      '#size' => 15,
      '#default_value' => $this->value,
      '#attributes' => array('title' => t('Enter the name you wish to search for.')),
      '#title' => empty($form_state['exposed']) ? t('Value') : '',
    );
  }

  /**
   * Add this filter to the query.
   *
   * Due to the nature of fapi, the value and the operator have an unintended
   * level of indirection. You will find them in $this->operator
   * and $this->value respectively.
   */
  function query() {
    $name_table = $this->ensure_my_table();
    $field = "$this->table_alias.$this->real_field";
    $fulltext_field = "LOWER(CONCAT(' ', COALESCE({$field}_title, ''), ' ', COALESCE({$field}_given, ''), ' ', COALESCE({$field}_middle, ''), ' ', COALESCE({$field}_family, ''), ' ', COALESCE({$field}_generational, ''), ' ', COALESCE({$field}_credentials, '')))";

    $info = $this->operators();
    if (!empty($info[$this->operator]['method'])) {
      $this->{$info[$this->operator]['method']}($fulltext_field);
    }
  }

  function op_contains($fulltext_field) {
    $value = drupal_strtolower($this->value);
    $placeholder = $this->placeholder();
    $this->query->add_where_expression($this->options['group'], "$fulltext_field LIKE $placeholder", array($placeholder => '% ' . db_like($value) . '%'));
  }

  function op_word($fulltext_field) {
    $where = $this->operator == 'word' ? db_or() : db_and();

    // Don't filter on empty strings.
    if (empty($this->value)) {
      return;
    }

    $value = drupal_strtolower($this->value);

    $words = preg_split('/ /', $value, -1, PREG_SPLIT_NO_EMPTY);
    foreach($words as $word) {
      $placeholder =  $this->placeholder();
      $where->where("$fulltext_field LIKE $placeholder", array($placeholder => '% ' . db_like($word) . '%'));
    }

    $this->query->add_where($this->options['group'], $where);
  }
}
