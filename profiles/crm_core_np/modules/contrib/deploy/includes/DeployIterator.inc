<?php

/**
 * Iterator class which does the heavy lifting for detecting dependencies.
 */
class DeployIterator extends EntityDependencyIterator {

  /**
   * We override this method since we need to return our own iterator.
   *
   * @return DeployIterator
   */
  public function getChildren() {
    return new DeployIterator($this->getChildrenEntities(), $this);
  }

  /**
   * We override this method since we need to return UUID entities, with some
   * extra hooks.
   *
   * @see http://www.odata.org/developers/protocols
   */
  public function current() {
    $current = current($this->entities);

    $uuids = entity_get_uuid_by_id($current['type'], array($current['id']));
    $uuid = reset($uuids);
    // Load the current entity with UUID.
    $entities = entity_uuid_load($current['type'], array($uuid));
    $entity = reset($entities);
    // Add necessary metadata to the entity.
    $cause = FALSE;
    if (!empty($this->causes[$current['type']][$current['id']])) {
      $cause_type = $this->causes[$current['type']][$current['id']]['type'];
      $cause_id = $this->causes[$current['type']][$current['id']]['id'];
      $cause_uuids = entity_get_uuid_by_id($cause_type, array($cause_id));
      $cause_uuid = reset($cause_uuids);
      $cause = $cause_type . '/' . $cause_uuid;
    }
    $entity->__metadata = array(
      'type' => $current['type'],
      'uri' => $current['type'] . '/' . $uuid,
      'cause' => $cause,
    );
    // Now mark this as traversed.
    $this->traversed[$current['type']][$current['id']] = TRUE;
    // Let other modules have their say.
    drupal_alter('deploy_entity', $entity, $current['type']);
    return $entity;
  }
}
