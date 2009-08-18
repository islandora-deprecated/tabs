<?php
// $Id$

/**
 * @file
 * Theme functions for tabs.
 */

/**
 * Return rendered tabset.
 *
 * @themable
 */
function theme_tabset($element) {
  $output = '<div id="tabs-'. $element['#tabset_name'] .'"'. drupal_attributes($element['#attributes']) .'>';
  $output .= '<ul>';
  foreach (element_children($element) as $key) {
    if (isset($element[$key]['#type']) && $element[$key]['#type'] == 'tabpage') {
      $output .= '<li'. drupal_attributes($element[$key]['#attributes']) .'><a href="' . $element[$key]['#url'] . '">'. $element[$key]['#title'] .'</a></li>';
    }
  }
  $output .= '</ul>';
  if (isset($element['#children'])) {
    $output .= $element['#children'];
  }
  $output .= '</div>';
  return $output;
}

/**
 * Return rendered content of a tab.
 *
 * @themable
 */
function theme_tabpage($element) {
  $output = '';
  $output .= '<div id="' . $element['#tab_name'] . '" class="tabs-' . $element['#tabset_name'] . '">';
  $output .= '<h2 class="drupal-tabs-title js-hide">'. $element['#title'] .'</h2>';
  $output .= $element['#content'] . $element['#children'];
  $output .='</div>';
  return $output;
}
