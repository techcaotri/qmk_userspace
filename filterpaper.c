// Copyright @filterpaper
// SPDX-License-Identifier: GPL-2.0+

#include "filterpaper.h"
#include "keycodes.h"

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  // Activate layer with another key press
  if (IS_LAYER_TAP(keycode))
    return true;

  // from jbarr21_qmk_userspace
  return (keycode >= QK_MOD_TAP) && (keycode <= QK_MOD_TAP_MAX) &&
         !(IS_HOMEROW(record));
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  // from jbarr21_qmk_userspace
  return IS_HOMEROW(record) ? false : true;
}
#endif

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  // from jbarr21_qmk_userspace
  if (IS_HOMEROW(record)) {
    if (keycode >> 8 & MOD_MASK_SHIFT) {
      return TAPPING_TERM + 40;
    }
    return TAPPING_TERM + 80;
  }
  return TAPPING_TERM;
}
#endif

// from jbarr21_qmk_userspace
#ifdef QUICK_TAP_TERM_PER_KEY
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  return IS_HOMEROW(record) ? QUICK_TAP_TERM / 2 : QUICK_TAP_TERM;
}
#endif

#ifdef ACHORDION_ENABLE
#include "achordion.h"

void matrix_scan_user(void) { achordion_task(); }

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                     uint16_t other_keycode, keyrecord_t *other_record) {
  uprintf("achordion_chord\n");
  switch (tap_hold_keycode) {
  // Left thumb combo
  case TH_L1:
    if (other_keycode == TH_L2) {
      return true;
    }
    break;
  case TH_L2:
    if (other_keycode == TH_L1) {
      return true;
    }
    break;

  // Right thumb combo
  case TH_R1:
    if (other_keycode == TH_R3) {
      return true;
    }
    break;
  case TH_R3:
    if (other_keycode == TH_R1) {
      return true;
    }
    break;
  }

  // allow same-hand holds when the other key is in the rows above or
  // below the home-row mod
  // uprintf("achordion_chord: tap_hold_record->event.key.row=%d\n",
  // tap_hold_record->event.key.row);
  uprintf("achordion_chord: tap_hold_keycode=%04x\n", tap_hold_keycode);
  bool is_hrm = IS_HRM(tap_hold_keycode);
  uprintf("achordion_chord: IS_HRM=%d\n", is_hrm);
  if (IS_HRM(tap_hold_keycode)) {
    uprintf("achordion_chord other_record->event.key.row=%d\n",
            other_record->event.key.row);
    static int ROWS_PER_SPLIT = MATRIX_ROWS / 2;
    // the home-rows are 1 and ROWS_PER_SPLIT+1 respectively on left and right
    // half
    if ((other_record->event.key.row % ROWS_PER_SPLIT != 1) ||
        (tap_hold_record->event.key.row != other_record->event.key.row) || 
        // return true if other key is on col 4, 5, 6, 7
        (other_record->event.key.col >= 4 && other_record->event.key.col <= 7)) {
      return true;
    }
  }
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
  case TH_R1: // allow same-hand symbols
  case TH_R2: // allow same-hand shift
    return 0; // Bypass Achordion for these keys.
  }

  return 800; // Otherwise use a timeout of 800 ms.
}
#endif

// Turn off caps lock at a word boundry
static inline bool process_caps_unlock(uint16_t keycode, keyrecord_t *record) {
  // Skip if caps lock is off
  if (!host_keyboard_led_state().caps_lock)
    return true;

  // Get tap keycode from tap hold keys
  if (IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) {
    if (record->tap.count == 0)
      return true;
    keycode = GET_TAP_KEYCODE(keycode);
  }

  switch (keycode) {
  // Retain caps lock with the following keycodes
  // if there are no active non-Shift modifiers
  case KC_A ... KC_0:
  case KC_BSPC:
  case KC_MINS:
  case KC_UNDS:
  case KC_CAPS:
    if (!(get_mods() & ~MOD_MASK_SHIFT))
      break;
  // Everything else is a word boundary
  default:
    tap_code(KC_CAPS);
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// from jbarr21_qmk_userspace
#ifdef ACHORDION_ENABLE
  if (!process_achordion(keycode, record)) {
    return false;
  }
#endif

  if (record->event.pressed) {
#ifdef COMBO_SHOULD_TRIGGER
    if (record->event.type != COMBO_EVENT)
      input_timer = timer_read_fast();
#endif
    if (!process_caps_unlock(keycode, record))
      return false;
  }
  switch (keycode) {
  case RAG_T(KC_LPRN):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_LPRN); // Send KC_LPRN on tap
      return false;        // Return false to ignore further processing of key
    }
    break;
  case LCA_T(KC_RPRN):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_RPRN); // Send KC_RPRN on tap
      return false;        // Return false to ignore further processing of key
    }
    break;
  }
  return true;
}

// Simplify unused magic config functions
uint8_t mod_config(uint8_t mod) { return mod; }
uint16_t keycode_config(uint16_t keycode) { return keycode; }

// Reduce marix scanning delay
#ifndef DIRECT_PINS
void matrix_io_delay(void) { __asm__ volatile("nop\nnop\nnop\n"); }
#endif

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable = true;
  debug_matrix = true;
  // debug_keyboard=true;
  // debug_mouse=true;
}

void my_caps_lock_toggle(void) {
  // uprintf("my_caps_word_toggle\n");
  tap_code(KC_CAPS);
  // uprintf("caps_word_set_user, active: 0x%04X\n",active);
}
