<?php
/**
 * @file
 * pmmi_distributor_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pmmi_distributor_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function pmmi_distributor_content_type_node_info() {
  $items = array(
    'distributor' => array(
      'name' => t('Distributor'),
      'base' => 'node_content',
      'description' => t('Stores information on an individual distributor.'),
      'has_title' => '1',
      'title_label' => t('Distributor Company Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
