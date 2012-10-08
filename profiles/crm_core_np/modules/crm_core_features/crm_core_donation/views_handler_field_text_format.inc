<?php

class views_handler_field_text_format extends views_handler_field {
  function render($values) {
    $value = $values->{$this->field_alias};
    
    $render = unserialize($value);
    switch($render['format']) {
      case 'plain_text':
        return check_plain($render['value']);
      break;
      default:
        return check_markup($render['value'], $render['format']);
      break;
    }
    
    return $value;
  }
}
