// Copyright @filterpaper
// SPDX-License-Identifier: GPL-2.0+

#pragma once

// macOS shortcuts
#define Z_UND   G(KC_Z)
#define Z_CUT   G(KC_X)
#define Z_CPY   G(KC_C)
#define Z_PST   G(KC_V)
#define Z_LOCK  C(G(KC_Q))
#define Z_SLEEP A(G(KC_PWR))
#define Z_SHUT  C(A(G(KC_PWR)))
#define Z_SSAVE HYPR(KC_S)

// Tap hold macros
#define TH_M    LT(0,KC_M)
#define TH_COMM LT(0,KC_COMM)
#define TH_DOT  LT(0,KC_DOT)
#define TH_SLSH LT(0,KC_SLSH)
#define TH(k1,k2,k3,k4) LT(0,k1),LT(0,k2),LT(0,k3),LT(0,k4)

// Mod tap macros
#define HM_A    LCTL_T(KC_A)
#define HM_S    LALT_T(KC_S)
#define HM_D    LGUI_T(KC_D)
#define HM_F    LSFT_T(KC_F)
#define HM_J    RSFT_T(KC_J)
#define HM_K    RGUI_T(KC_K)
#define HM_L    RALT_T(KC_L)
#define HM_QUOT RCTL_T(KC_QUOT)
#define HRML(k1,k2,k3,k4) LSFT_T(k1),LCTL_T(k2),LALT_T(k3),LGUI_T(k4)
#define HRMR(k1,k2,k3,k4) LGUI_T(k1),RALT_T(k2),LCTL_T(k3),LSFT_T(k4)

// Navigation shortcuts
#define SA_UP S(A(KC_UP))
#define SA_DN S(A(KC_DOWN))

// Layers
enum layers { BSE, FNC, NUM, MOU, SYS };

// Thumb keys
#define LCA_ENT LCA_T(KC_ENT)
#define SFT_SPC RSFT_T(KC_SPC)
#define NUM_BSP LT(NUM,KC_BSPC)

// Default 3x5_2 split layout
#define _BASE \
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, \
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
                               MO(FNC), KC_SPC,      KC_ENT,  MO(NUM)
 /*╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮
   │  Q     │  W     │  E     │  R     │  T     │   │  Y     │  U     │  I     │  O     │  P     │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │  A/SFT │  S/CTL │  D/ALT │  F/GUI │  G     │   │  H     │  J/GUI │  K/ALT │  L/CTL │ ; :/SFT│
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │  Z     │  X     │  C     │  V     │  B     │   │  N     │  M     │ , <    │ . >    │ / ?    │
   ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯
                              │MO(FNC) │  SPC   │   │  ENT   │ MO(NUM)│
                              ╰────────┴────────╯   ╰────────┴────────╯*/

#define _FUNC \
    KC_F12, KC_F7,   KC_F8,   KC_F9,   KC_PSCR,      KC_PGUP, KC_HOME, KC_UP, KC_END, _______, \
    KC_F11, KC_F4,   KC_F5,   KC_F6,   KC_SCRL,      KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _______, \
    KC_F10, KC_F1,   KC_F2,   KC_F3,   KC_PAUS,      KC_INS, KC_DEL, _______, _______, _______, \
                           _______, _______,      _______, _______
 /*╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮
   │ F12    │  F7    │  F8    │  F9    │ PSCR   │   │ PGUP   │ HOME   │ UP     │ END    │        │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │ F11    │  F4    │  F5    │  F6    │ SCRL   │   │ PGDN   │ LEFT   │ DOWN   │ RIGHT  │        │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │ F10    │  F1    │  F2    │  F3    │ PAUS   │   │ INSERT │ DELETE │        │        │        │
   ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯
                              │        │        │   │        │        │
                              ╰────────┴────────╯   ╰────────┴────────╯*/

#define _NUMB \
    KC_INS,  KC_1,    KC_2,    KC_3,    KC_VOLU,     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_COLN, \
    KC_CAPS, KC_4,    KC_5,    KC_6,    KC_VOLD,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN, \
    KC_DEL,  KC_7,    KC_8,    KC_9,    KC_0,        _______, SA_DN,   SA_UP,   _______, _______, \
                               MO(FNC), KC_ESC,      _______, _______
 /*╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮
   │ INSERT │  1     │  2     │  3     │ VOL UP │   │ HOME   │ PG DN  │ PG UP  │ END    │  :     │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │ CAPS   │  4     │  5     │  6     │ VOL DN │   │ LEFT   │ DOWN   │ UP     │ RIGHT  │  ;     │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │ DELETE │  7     │  8     │  9     │  0     │   │        │ S/A DN │ S/A UP │        │        │
   ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯
                              │ FNC    │ ESC    │   │        │        │
                              ╰────────┴────────╯   ╰────────┴────────╯*/

#define _MOUS \
    _______, KC_LBRC, KC_LCBR, KC_RCBR, _______,     KC_CIRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_TILD, \
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_ASTR, KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  \
    _______, _______, KC_LT,   KC_GT,   _______,     KC_AMPR, KC_UNDS, KC_PLUS, KC_PIPE, _______, \
                               _______, _______,     _______, _______
 /*╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮
   │        │  [     │  {     │  }     │        │   │  ^     │  (     │  )     │  ]     │  ~     │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │  !     │  @     │  #     │  $     │  %     │   │  *     │  -     │  =     │  \     │  `     │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │        │        │  <     │  >     │        │   │  &     │  _     │  +     │  │     │        │
   ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯
                              │        │        │   │        │        │
                              ╰────────┴────────╯   ╰────────┴────────╯*/



// Mod-tap wrapper
#define HRM(k) HR_MODTAP(k)
#define HR_MODTAP( \
      l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, \
      l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, \
      l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
                     l16, l17,   r16, r17                 \
) \
      l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05,       \
HRML(l06, l07, l08, l09), l10,   r06, HRMR(r07, r08, r09, r10), \
      l11, l12, l13, l14, l15,   r11,   TH(r12, r13, r14, r15), \
                     l16, l17,   r16, r17


// Layout aliases for json keymap
#define LAYOUT_34key_w(...) LAYOUT_split_3x5_2(__VA_ARGS__)
#define LAYOUT_crkbd_w(...) LAYOUT_split_3x6_3(__VA_ARGS__)


// Convert 3x5_2 to 42-key
#define C_42(k) CONV_42(k)
#define CONV_42( \
         l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, \
         l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, \
         l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
                        l16, l17,   r16, r17                 \
) \
KC_TAB,  l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, KC_BSLS, \
QK_GESC, l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, KC_QUOT, \
KC_LSFT, l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, KC_RSFT,  \
         MO(MOU), l16, l17,   r16, r17, RAG_T(KC_DEL)
