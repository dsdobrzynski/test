<?php
/**
 * @file
 * pmmi_industries_served_vocabulary.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pmmi_industries_served_vocabulary_taxonomy_default_vocabularies() {
  return array(
    'industries_served' => array(
      'name' => 'Industries Served',
      'machine_name' => 'industries_served',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
