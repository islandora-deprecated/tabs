<?php
// $Id$

/**
 * @file
 * Administrative page for tabs.
 */

/**
 * Menu callback for admin settings.
 */
function tabs_admin_settings() {
  $form = array();
  $form['tabs_slide'] = array(
    '#type' => 'radios',
    '#title' => t('Slide effect'),
    '#description' => t('Apply slide effect when changing tabs.'),
    '#default_value' => variable_get('tabs_slide', 0),
    '#options' => array(t('disabled'), t('enabled')),
  );
  $form['tabs_fade'] = array(
    '#type' => 'radios',
    '#title' => t('Fade effect'),
    '#description' => t('Apply fade effect when changing tabs.'),
    '#default_value' => variable_get('tabs_fade', 0),
    '#options' => array(t('disabled'), t('enabled')),
  );
  $form['tabs_speed'] = array(
    '#type' => 'radios',
    '#title' => t('Effect speed'),
    '#description' => t('Speed at which to apply effects.'),
    '#default_value' => variable_get('tabs_speed', 'slow'),
    '#options' => array('slow' => t('slow'), 'fast' => t('fast'), '1' => t('immediate')),
  );
  $form['tabs_navigation'] = array(
    '#type' => 'radios',
    '#title' => t('Navigation buttons'),
    '#description' => t('Enable to add "next" and "previous" buttons to the bottom of all tab sets.'),
    '#default_value' => variable_get('tabs_navigation', 0),
    '#options' => array(t('disabled'), t('enabled')),
  );
  $form['tabs_nav_next'] = array(
    '#type' => 'textfield',
    '#title' => t('Next button caption'),
    '#description' => t('The text to be displayed in the \'next\' button.'),
    '#default_value' => variable_get('tabs_nav_next', t('next')),
  );
  $form['tabs_nav_prev'] = array(
    '#type' => 'textfield',
    '#title' => t('Previous button caption'),
    '#description' => t('The text to be displayed in the \'previous\' button.'),
    '#default_value' => variable_get('tabs_nav_prev', t('previous')),
  );
  $form = system_settings_form($form);
  return $form;
}
