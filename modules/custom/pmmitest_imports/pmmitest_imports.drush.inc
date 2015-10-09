<?php
/**
 * @file
 * PG Gardens Approval drush include file.
 */

/**
 * Implements hook_permission().
 */
function pg_gardens_approval_permission() {
  return array(
    'manage garden approvals' => array(
      'title' => t('Manage Garden Approvals'),
      'description' => ('Allows managing garden status (approved, pending, denied)'),
    ),
  );
}

/**
 * Implements hook_menu().
 */
function pg_gardens_approval_menu() {
  $items = array();

  $items['admin/config/pg-gardens-approval-settings'] = array(
    'title' => 'PG Gardens Approval',
    'description' => 'Configuration for the PG Gardens approval module.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('pg_gardens_approval_form'),
    'access arguments' => array('manage garden approvals'),
    'file' => 'includes/admin.inc',
    'file path' => drupal_get_path('module', 'pg_gardens_approval'),
    'type' => MENU_NORMAL_ITEM,
  );

 return $items;
}

/**
 * Implements hook_mail().
 */
function pg_gardens_approval_mail($key, &$message, $params) {
  $report_csv = views_embed_view('pg_gardens_approval', 'views_data_export_csv');
  $csv_path = 'public://gardens_approved.csv';
  file_unmanaged_save_data($report_csv, $csv_path, FILE_EXISTS_REPLACE);
  $date_generated = date('Y-m-d', time());
  $date_start = date('M+d+Y', time() - 518400);
  $date_end = date('M+d+Y', time());
  $options = array(
    'query' => array(
      'field_garden_status_value[]' => 'Approved',
      'field_garden_auto_approved_value' => 1,
      'field_garden_approval_date_value[min][date]' => $date_start,
      'field_garden_approval_date_value[max][date]' => $date_end,
    ),
    'absolute' => TRUE,
  );
  $report_link = rawurldecode(url('gardens-approval', $options));

  // Default message settings.
  $message['headers']['MIME-Version'] = '1.0';
  $message['headers']['Content-Type'] = 'multipart/mixed;';
  $message['headers']['Content-Type'] = 'text/html;';
  switch ($key) {
    case 'weekly_report':
      $message['subject'] = variable_get('pg_gardens_approval_email_subject');
      $message['body'][] = t('<p>Please find attached a CSV report of gardens auto-approved in the past week. The report may also be viewed at @report</p>', array('@report' => $report_link));
      $attachment = array(
        'filecontent' => file_get_contents($csv_path),
        'filename' => 'gardens_approved_' . $date_generated . '.csv',
        'filemime' => 'text/csv',
      );
      $message['params']['attachments'][] = $attachment;
      break;
  }
}

/**
 * Sends an e-mail with a report of gardens approved the previous week.
 */
function pg_gardens_approval_weekly_report_mail_send() {
  $module = 'pg_gardens_approval';
  $key = 'weekly_report';

  $to = variable_get('pg_gardens_approval_email_recipients');
  module_load_include('inc', 'mimemail');
  $from = mimemail_address(array(
    'name' => variable_get('site_name', 'People\'s Garden'),
    'mail' => variable_get('site_mail', 'admin@example.com'),
  ));
  $params = array();
  $language = language_default();
  $send = TRUE;

  $result = drupal_mail($module, $key, $to, $language, $params, $from, $send);
  if ($result != TRUE) {
    watchdog('pg_gardens_approval', '<p>The gardens approval weekly report e-mail could not be sent.</p>', array(), WATCHDOG_ERROR);
  }
}

/**
 * Implements hook_cronapi().
 */
function pg_gardens_approval_cronapi($op, $job = NULL) {
  $items['pg_gardens_approval_weekly_email'] = array(
    'description' => 'Send an e-mail with auto-approved gardens list from previous week every Monday at 5 am.',
    'rule' => '0 5 * * 1',
    'callback' => 'pg_gardens_approval_weekly_report_mail_send',
  );

  return $items;
}

/**
 * Implements hook_node_presave().
 */
function pg_gardens_approval_node_presave($node) {
  if (user_access('administer content') || user_access('manage garden approvals')) {
    return;
  }

  $garden = '';
  switch ($node->type) {
    case 'garden_information':
        $garden = entity_metadata_wrapper('node', $node);
      break;
  }

  if (!empty($garden)) {
    $garden_pass = _pg_gardens_approval_check_required_fields($garden);
  }

  if (!empty($garden)) {
    if (!empty($garden_pass) && $garden->field_garden_status->value() == 'Pending') {
      $garden->field_garden_status = 'Approved';
      $garden->field_garden_approval_date = time();
      $garden->field_garden_auto_approved = TRUE;
      $node->status = 1;
    }
    elseif ((empty($garden_pass) && $garden->field_garden_status->value() == 'Approved')) {
      $garden->field_garden_status = 'Pending';
      $garden->field_garden_auto_approved = FALSE;
      $node->status = 0;
    }
  }
}

/**
 * Helper function to determine if required fields have data.
 *
 * @param object $wrapper
 *   The entity metadata wrapper object.
 *
 * @return boolean
 *   Returns TRUE if all required fields have data and FALSE otherwise.
 */
function _pg_gardens_approval_check_required_fields($wrapper) {
  $required_fields = array(
    'garden_information' => array(
      'field_address_1',
      'field_location_type',
      'field_garden_components',
    ),
  );

  if ($wrapper->getBundle() == 'garden_information') {
    $fields = $required_fields['garden_information'];
  }

  if ($fields) {
    foreach ($fields as $field) {
      $value = NULL;
      $value = $wrapper->$field->value();
      if (empty($value)) {
        // Required field doesn't have data. No need to check other fields.
        return FALSE;
      }
    }
  }

  // All required fields have data, so return TRUE.
  return TRUE;
}
