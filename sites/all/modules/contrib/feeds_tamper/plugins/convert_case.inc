<?php

/**
 * @file
 * Convert text to upper, lower, or title case.
 */

$plugin = array(
  'form' => 'feeds_tamper_convert_case_form',
  'callback' => 'feeds_tamper_convert_case_callback',
  'name' => 'Convert case',
  'multi' => 'loop',
  'category' => 'Text',
);

function feeds_tamper_convert_case_form($importer, $element_key, $settings) {
  $form = array();
  $form['mode'] = array(
    '#type' => 'radios',
    '#title' => t('How to convert case'),
    '#default_value' => isset($settings['mode']) ? $settings['mode'] : MB_CASE_TITLE,
    '#options' => array(
      MB_CASE_TITLE => t('Title Case'),
      MB_CASE_LOWER => t('lower case'),
      MB_CASE_UPPER => t('UPPER CASE'),
      'ucfirst' => t('Sentence case'),
    ),
  );
  return $form;
}

function feeds_tamper_convert_case_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  if ($settings['mode'] === 'ucfirst') {
    $field = strtoupper(substr($field, 0, 1, 'UTF-8'), 'UTF-8') . strtolower(substr($field, 1, strlen($field, 'UTF-8'), 'UTF-8'));
  }
  else {
   $field = mb_convert_case($field, MB_CASE_TITLE, 'UTF-8');
  }
}
