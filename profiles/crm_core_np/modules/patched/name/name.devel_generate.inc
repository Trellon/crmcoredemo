<?php
/**
 * @file
 * Devel Generate module integration.
 *
 * Helper functions to generate realistic random names instances.
 */

/**
 * Implements hook_devel_generate().
 */
function name_devel_generate($object, $field, $instance, $bundle) {
  if (field_behaviors_widget('multiple values', $instance) == FIELD_BEHAVIOR_CUSTOM) {
    return devel_generate_multiple('_name_devel_generate', $object, $field, $instance, $bundle);
  }
  else {
    return _name_devel_generate($object, $field, $instance, $bundle);
  }
}

/**
 * Callback function to generate name field instance data.
 *
 * You can specify another function here to generate your own list.
 */
function _name_devel_generate($object, $field, $instance, $bundle) {
  $object_field = array();

  $func = variable_get('name_devel_generate_names', '_name_devel_generate_name');
  $names = $func($field);

  $components = array_filter($field['settings']['components']);
  return array_intersect_key($names[array_rand($names)], $components);
}

/**
 * Helper function to generate set of fake names.
 *
 * @param field
 *   A name field to generate names from.
 */
function _name_devel_generate_name($field) {
  $names = &drupal_static(__FUNCTION__, array());

  // Generate 50 random names based off the field settings. These are stored
  // for future use to prevent the need to regenerate these.
  if (empty($names)) {
    module_load_include('inc', 'name', 'includes/name.content');

    // Parse the settings to find the field title and generational options.
    $titles = _name_field_get_options($field, 'title');
    unset($titles['']);
    $generational = _name_field_get_options($field, 'generational');
    unset($generational['']);

    $given = array('John', 'William', 'James', 'George', 'Charles', 'Frank', 'Joseph', 'Henry', 'Robert', 'Thomas', 'Edward', 'Harry', 'Walter', 'Arthur', 'Fred', 'Albert', 'Samuel', 'Clarence', 'Louis', 'David', 'Joe', 'Charlie', 'Richard', 'Ernest', 'Roy', 'Will', 'Andrew', 'Jesse', 'Oscar', 'Willie', 'Daniel', 'Benjamin', 'Carl', 'Sam', 'Alfred', 'Earl', 'Peter', 'Elmer', 'Frederick', 'Howard', 'Lewis', 'Ralph', 'Herbert', 'Paul', 'Lee', 'Tom', 'Herman', 'Martin', 'Jacob', 'Michael', 'Mary', 'Anna', 'Emma', 'Elizabeth', 'Margaret', 'Minnie', 'Ida', 'Bertha', 'Clara', 'Alice', 'Annie', 'Florence', 'Bessie', 'Grace', 'Ethel', 'Sarah', 'Ella', 'Martha', 'Nellie', 'Mabel', 'Laura', 'Carrie', 'Cora', 'Helen', 'Maude', 'Lillian', 'Gertrude', 'Rose', 'Edna', 'Pearl', 'Edith', 'Jennie', 'Hattie', 'Mattie', 'Eva', 'Julia', 'Myrtle', 'Louise', 'Lillie', 'Jessie', 'Frances', 'Catherine', 'Lula', 'Lena', 'Marie', 'Ada', 'Josephine', 'Fanny', 'Lucy', 'Dora');
    $middle = array('Aaron', 'Bailey', 'Carson', 'Damon', 'Edwin', 'Francis', 'Garrett', 'Holden', 'Ivan', 'Jace', 'Keaton', 'Layne', 'Malcolm', 'Noah', 'Owen', 'Payton', 'Quinn', 'Randall', 'Sawyer', 'Tilton', 'Tanner', 'Vernon', 'Wade', 'Zachariah', 'Aiden', 'Bennett', 'Chance', 'Dante', 'Ellis', 'Glenn', 'Houston', 'Jackson', 'Kelton', 'Layton', 'Marshall', 'Noel', 'Peyton', 'Quintin', 'Reese', 'Sean', 'Stewart', 'Taylor', 'Warren', 'Anton', 'Blair', 'Charles', 'Denver', 'Emmett', 'Grant', 'Jade', 'Adele', 'Bailee', 'Camden', 'Dawn', 'Elein', 'Fawn', 'Haiden', 'Jacklyn', 'Kae', 'Lane', 'Madisen', 'Nadeen', 'Ocean', 'Payten', 'Raine', 'Selene', 'Taye', 'Zion', 'Alice', 'Berlynn', 'Candice', 'Debree', 'Ellen', 'Faye', 'Hollyn', 'Jae', 'Kaitlin', 'Lashon', 'Mae', 'Naveen', 'Raven', 'Sharon', 'Taylore', 'Zoe', 'Anise', 'Bernice', 'Carelyn', 'Debree', 'Erin', 'Faye', 'Hollyn', 'Jane', 'Kalan', 'Lee', 'Merle', 'Olive', 'Reagan', 'Sue', 'Ann', 'Bree');
    $family = array('Smith', 'Johnson', 'Williams', 'James', 'Brown', 'Davis', 'Miller', 'Wilson', 'Moore', 'Taylor', 'Anderson', 'Thomas', 'Jackson', 'White', 'Harris', 'Martin', 'Tompson', 'Garcia', 'Martinez', 'Robinson', 'Clark', 'Rodrigez', 'Lewis', 'Lee', 'Walker', 'Hall', 'Allen', 'Young', 'Hernandez', 'King', 'Wright', 'Lopez', 'Hill', 'Scott', 'Green', 'Adams', 'Baker', 'Gonzales', 'Nelson', 'Carter', 'Mitchell', 'Perez', 'Roberts', 'Turner', 'Phillips', 'Campbell', 'Parker', 'Evans', 'Edwards', 'Collins', 'Stewart', 'Sanches', 'Morris', 'Rogers', 'Reed', 'Cook', 'Morgan', 'Bell', 'Murphy', 'Bailey', 'Rivera', 'Cooper', 'Richardson', 'Cox', 'Howard', 'Ward', 'Torez', 'Peterson', 'Gray', 'Ramirez', 'James', 'Watson', 'Brooks', 'Kelly', 'Sanders', 'Price', 'Bennett', 'Wood', 'Barness', 'Ross', 'Henderson', 'Coleman', 'Jenkins', 'Perry', 'Powel', 'Long', 'Patterson', 'Hughes', 'Flores', 'Washington', 'Butler', 'Simpson', 'Foster', 'Gonzales', 'Bryant', 'Alexander', 'Russel', 'Griffin', 'Diaz', 'Hayes');

    // Random use the components to create truely random names.
    for ($i = 0; $i < 50; $i++) {
      $names[] = array(
        'title' => $titles[array_rand($titles)],
        'given' => $given[array_rand($given)],
        'middle' => $middle[array_rand($middle)],
        'family' => $family[array_rand($family)],
        'generational' => $generational[array_rand($generational)],
        'credentials' => ucfirst(devel_generate_word(rand(3, 10))),
      );
    }
  }
  return $names;
}
