<?php

/**
 * Wrapper class around the SPL RecursiveIteratorIterator.
 */
class EntityDependencyIteratorIterator extends RecursiveIteratorIterator {}

/**
 * Iterator class which does the heavy lifting for detecting dependencies.
 *
 * This iterator is reponsible for taking in an array of entity types and ids,
 * figuring out all their dependencies, and returning an iterable object of all
 * of them in a sane order (dependencies first). And since dependencies
 * in theory are nested and recursive, we are using a recursive iterator here.
 *
 * @todo
 *   We need to throw an exception when we detect a circular dependency.
 */
class EntityDependencyIterator implements RecursiveIterator {

  /**
   * The entities to be iterated over.
   *
   * @var array
   */
  public $entities = array();

  /**
   * The entity type of the entity currently being iterated over.
   *
   * @var string
   */
  public $entityType = NULL;

  /**
   * The entity ID of the entity currently being iterated over.
   *
   * @var string
   */
  public $entityId = NULL;

  /**
   * An array of dependencies to the entity being parsed.
   *
   * @var array
   */
  public $dependencies = array();

  /**
   * An array of belongings to the entity being parsed.
   *
   * @var array
   */
  public $belongings = array();

  /**
   * An array with information on the cause/reason why an entity exists in the
   * tree. Basically, the cause for term A's existance in the tree, might be
   * becasue node B depends on it.
   *
   * @var array
   */
  public $causes = array();

  /**
   * Keeps track of entities that have already been checked for dependencies.
   *
   * @var array
   */
  public $checked = array();

  /**
   * Keeps track of entities that have already been traversed (output).
   *
   * @var array
   */
  public $traversed = array();

  /**
   * Constructor.
   *
   * @param array $entities
   *   A structured array of entity ids and their entity types.
   * @param array $parent
   *   The parent array of the current entity.
   *
   * @see entity_dependency_iterator().
   */
  public function __construct($entities, &$parent = NULL) {
    $this->entities = $entities;

    if (empty($parent)) {
      foreach ($this->entities as $key => $entity) {
        $this->causes[$entity['type']][$entity['id']] = FALSE;
      }
    }
    else {
      $this->causes =& $parent->causes;
      $this->checked =& $parent->checked;
      $this->traversed =& $parent->traversed;
    }
  }

  /**
   * Returns TRUE if an iterator can be created for the current item in the
   * entities array.
   *
   * @return boolean
   */
  public function hasChildren() {
    $current = $this->current;
    // Don't check for dependencies twice.
    if (!empty($this->current['id']) && !isset($this->checked[$current['type']][$current['id']])) {
      // Load the current entity.
      $entities = entity_load($current['type'], array($current['id']));
      $entity = reset($entities);

      $this->dependencies = module_invoke_all('entity_dependencies', $entity, $current['type']);
      //$this->belongings = module_invoke_all('entity_belongings', $entity, $this->entityType);

      // Don't add dependencies that already were checked.
      foreach ($this->dependencies as $key => $dependency) {
        if (($dependency['type'] == $current['type'] && $dependency['id'] == $current['id'])
          || isset($this->checked[$dependency['type']][$dependency['id']])) {

          unset($this->dependencies[$key]);
        }
        else {
          $this->causes[$dependency['type']][$dependency['id']] = $current;
        }
      }

      // Let other modules have their say.
      drupal_alter('entity_dependencies', $this->dependencies, $entity, $current['type']);

      // Now mark this as checked.
      $this->checked[$current['type']][$current['id']] = TRUE;

      if (!empty($this->dependencies)) {
        return TRUE;
      }
    }
    return FALSE;
  }

  /**
   * Helper method to get entity dependencies.
   */
  public function getChildrenEntities() {
    $entities = array();
    $current = current($this->entities);

    if (!empty($this->dependencies)) {
      $entities = $this->dependencies;
      // In an iterator, having children means that the current key itself
      // isn't a part of the entities. However, we need that entity.. So we add
      // the parent as a part of the entities. And since children always should
      // go first, we add the parent last.
      $entities[] = array('id' => $current['id'], 'type' => $current['type']);
    }
    return $entities;
  }

  /**
   * Returns an iterator for the current entry.
   *
   * @return EntityDependencyIterator
   */
  public function getChildren() {
    return new EntityDependencyIterator($this->getChildrenEntities(), $this);
  }

  /**
   * Get the current entity formatted with some extra metadata according to
   * the OData protocol.
   *
   * @see http://www.odata.org/developers/protocols
   */
  public function current() {
    $current = current($this->entities);
    // Load the current entity.
    $entities = entity_load($current['type'], array($current['id']));
    $entity = reset($entities);
    // Add necessary metadata to the entity.
    $cause = FALSE;
    if (!empty($this->causes[$current['type']][$current['id']])) {
      $cause = $this->causes[$current['type']][$current['id']]['type'] . '/' . $this->causes[$current['type']][$current['id']]['id'];
    }
    $entity->__metadata = array(
      'type' => $current['type'],
      'uri' => $current['type'] . '/' . $current['id'],
      'cause' => $cause,
    );
    // Now mark this as traversed.
    $this->traversed[$current['type']][$current['id']] = TRUE;
    return $entity;
  }

  /**
   * Returns the key of the current element.
   */
  public function key() {
    return key($this->entities);
  }

  /**
   * Moves the current position to the next element.
   */
  public function next() {
    do {
      $current = next($this->entities);
    } while (!empty($current) && isset($this->traversed[$current['type']][$current['id']]));
  }

  /**
   * Rewinds the Iterator to the first element.
   */
  public function rewind() {
    reset($this->entities);
  }

  /**
   * Checks if current position is valid.
   *
   * @return boolean
   */
  public function valid() {
    $current = current($this->entities);
    if (!empty($current) && is_array($current) && isset($current['type']) && isset($current['id'])  && !isset($this->traversed[$current['type']][$current['id']])) {
      $this->current = $current;
      return TRUE;
    }
    return FALSE;
  }
}
