/* Copyright (C) 2021 @filterpaper
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// Wrapper macro names for the real layout
#define LAYOUT_wrapper_split_3x6_3(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_wrapper_ortho_4x12(...) LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_wrapper_planck_mit(...) LAYOUT_planck_mit(__VA_ARGS__)

// Base QWERTY
#define BASE1 	KC_TAB,  Q_TH,         W_TH,         KC_E,         KC_R,         T_TH, KC_Y, KC_U,         KC_I,         KC_O,         KC_P,            KC_BSPC
#define BASE2 	KC_GESC, LSFT_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LGUI_T(KC_F), KC_G, KC_H, RGUI_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RSFT_T(KC_SCLN), KC_QUOT
#define BASE3 	KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B, N_TH, M_TH,         COMM_TH,      DOT_TH,       KC_SLSH,         KC_ENT
// Base QWERTY last row
#define CORNEBASE  LT(5,KC_VOLD), LT(2,KC_VOLU), RSFT_T(KC_ENT), RSFT_T(KC_SPC), LT(3,KC_SPC), KC_RGUI
#define PLANCKBASE KC_DEL, LALT_T(KC_VOLD), LCTL_T(KC_VOLU), KC_LGUI, LT(2,KC_SPC), RSFT_T(KC_SPC), RSFT_T(KC_SPC), LT(3,KC_SPC), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
#define BM40BASE   KC_DEL, LALT_T(KC_VOLD), LCTL_T(KC_VOLU), KC_LGUI, LT(2,KC_SPC), RSFT_T(KC_SPC), LT(3,KC_SPC), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT

// COLEMAK
#define COLEMAK1 KC_TRNS, KC_TRNS, KC_TRNS,      KC_F,         KC_P,         KC_G, KC_J,    KC_L,         KC_U,         KC_Y,         KC_SCLN,      KC_TRNS
#define COLEMAK2 KC_TRNS, KC_TRNS, LALT_T(KC_R), LCTL_T(KC_S), LGUI_T(KC_T), KC_D, KC_TRNS, RGUI_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RSFT_T(KC_O), KC_TRNS
#define COLEMAK3 KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_B, KC_K,    KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS
// COLEMAK last row
#define CORNECOLEMAK  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define PLANCKCOLEMAK KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define BM40COLEMAK   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

// Lower
#define LOWER1 KC_TRNS, KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,  KC_BSLS, KC_TRNS, KC_TRNS
#define LOWER2 KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS
#define LOWER3 KC_CAPS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
// Lower last row
#define CORNELOWER  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_TRNS
#define PLANCKLOWER KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_HOME, KC_PGDN, KC_PGUP, KC_END
#define BM40LOWER   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_HOME, KC_PGDN, KC_PGUP, KC_END

// Raise
#define RAISE1 KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,           KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS
#define RAISE2 KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,             KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS
#define RAISE3 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SGUI(LALT(KC_V)), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
// Raise last row
#define CORNERAISE  KC_TRNS, MO(4), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define PLANCKRAISE KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define BM40RAISE   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

// Adjust
#define ADJUST1 RESET,   KC_F1,              KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,           TG(1)
#define ADJUST2 KC_TRNS, KC_F11,             KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS,          KC_TRNS
#define ADJUST3 KC_TRNS, LALT(LGUI(KC_PWR)), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS,  KC_DEL,  KC_TRNS, LCTL(LGUI(KC_Q)), KC_TRNS
// Adjust last row
#define CORNEADJUST  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define PLANCKADJUST KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define BM40ADJUST   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

// Mouse
#define MOUSE1 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_U, KC_WH_D, KC_TRNS, KC_TRNS, KC_TRNS
#define MOUSE2 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS
#define MOUSE3 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN1, KC_TRNS, KC_TRNS, KC_TRNS
#define CORNEMOUSE KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
