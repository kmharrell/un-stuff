<?php

/**
 * @file
 * Map existing files from the library.
 */

/**
 * Class for mapping values using existing files from the media library.
 */
class MediaFeedsGUIDProvider extends MediaFeedsProvider {
  protected $file;

  public function __construct($value, $config = array()) {
    $fid = db_select('feeds_item', 'feed')
      ->fields('feed', array('entity_id'))
      ->condition('guid', $value, '=')
      ->execute()
      ->fetchField();

    if (!empty($fid)) {
      $file = file_load($fid);
      $this->file = $file;
    }
  }

  public function getFileObject() {
    return $this->file;
  }

  public function save() {
    return $this->file;
  }
}
