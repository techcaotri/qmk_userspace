#line 40 "/home/tripham/Dev/Corne_QMK/filterpaper_qmk_userspace/layout.h"
enum layers { BSE, CMK, NUM, SYM, FNC };
#line 34 "/home/tripham/Dev/Corne_QMK/filterpaper_qmk_userspace/features/combos.h"
enum combos {
#line 14 "/home/tripham/Dev/Corne_QMK/filterpaper_qmk_userspace/features/combos.inc"
vi_quit,
vi_save,
dir_up,

vol_up,
vol_dn,
escape,


arr_up,
arr_dn,
arr_lt,
arr_rt,
nav_up,
nav_dn,


thmb_l,
thmb_r,


tog_num,
tog_fnc,
#line 36 "/home/tripham/Dev/Corne_QMK/filterpaper_qmk_userspace/features/combos.h"
};
#line 14 "/home/tripham/Dev/Corne_QMK/filterpaper_qmk_userspace/features/combos.inc"
uint16_t const vi_quit_combo[] PROGMEM = {    KC_Q,    KC_W, COMBO_END};
uint16_t const vi_save_combo[] PROGMEM = {     KC_Z,    KC_X, COMBO_END};
uint16_t const dir_up_combo[] PROGMEM = {    LT(0,KC_DOT),  LT(0,KC_SLSH), COMBO_END};

uint16_t const vol_up_combo[] PROGMEM = {  KC_P,    RCTL_T(KC_QUOT), COMBO_END};
uint16_t const vol_dn_combo[] PROGMEM = {  RCTL_T(KC_QUOT), LT(0,KC_SLSH), COMBO_END};
uint16_t const escape_combo[] PROGMEM = {   LALT_T(KC_S),    LGUI_T(KC_D), COMBO_END};


uint16_t const arr_up_combo[] PROGMEM = {    KC_U,    KC_I, COMBO_END};
uint16_t const arr_dn_combo[] PROGMEM = {  RSFT_T(KC_J),    RGUI_T(KC_K), COMBO_END};
uint16_t const arr_lt_combo[] PROGMEM = {  KC_H,    RSFT_T(KC_J), COMBO_END};
uint16_t const arr_rt_combo[] PROGMEM = {  RGUI_T(KC_K),    RALT_T(KC_L), COMBO_END};
uint16_t const nav_up_combo[] PROGMEM = {    LT(0,KC_COMM), LT(0,KC_DOT), COMBO_END};
uint16_t const nav_dn_combo[] PROGMEM = {    LT(0,KC_M),    LT(0,KC_COMM), COMBO_END};


uint16_t const thmb_l_combo[] PROGMEM = {    LT(SYM,KC_TAB), LCA_T(KC_ENT), COMBO_END};
uint16_t const thmb_r_combo[] PROGMEM = {    RSFT_T(KC_SPC), LT(NUM,KC_BSPC), COMBO_END};


uint16_t const tog_num_combo[] PROGMEM = {  LT(NUM,KC_BSPC), KC_N, LT(0,KC_M), COMBO_END};
uint16_t const tog_fnc_combo[] PROGMEM = {  LT(SYM,KC_TAB), KC_B, KC_V, COMBO_END};
#line 52 "/home/tripham/Dev/Corne_QMK/filterpaper_qmk_userspace/features/combos.h"
combo_t key_combos[] = {
#line 14 "/home/tripham/Dev/Corne_QMK/filterpaper_qmk_userspace/features/combos.inc"
[vi_quit] = COMBO_ACTION(vi_quit_combo),
[vi_save] = COMBO_ACTION(vi_save_combo),
[dir_up] = COMBO_ACTION(dir_up_combo),

[vol_up] = COMBO(vol_up_combo, KC_VOLU),
[vol_dn] = COMBO(vol_dn_combo, KC_VOLD),
[escape] = COMBO(escape_combo, KC_ESC),


[arr_up] = COMBO(arr_up_combo, KC_UP),
[arr_dn] = COMBO(arr_dn_combo, KC_DOWN),
[arr_lt] = COMBO(arr_lt_combo, KC_LEFT),
[arr_rt] = COMBO(arr_rt_combo, KC_RGHT),
[nav_up] = COMBO(nav_up_combo, S(A(KC_UP))),
[nav_dn] = COMBO(nav_dn_combo, S(A(KC_DOWN))),


[thmb_l] = COMBO(thmb_l_combo, KC_NO),
[thmb_r] = COMBO(thmb_r_combo, KC_NO),


[tog_num] = COMBO(tog_num_combo, TG(NUM)),
[tog_fnc] = COMBO(tog_fnc_combo, TG(FNC)),
#line 54 "/home/tripham/Dev/Corne_QMK/filterpaper_qmk_userspace/features/combos.h"
};
#line 62 "/home/tripham/Dev/Corne_QMK/filterpaper_qmk_userspace/features/combos.h"
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
#line 14 "/home/tripham/Dev/Corne_QMK/filterpaper_qmk_userspace/features/combos.inc"
case vi_quit: if (pressed) { SEND_STRING(":q!"); } break;
case vi_save: if (pressed) { SEND_STRING(":x"); } break;
case dir_up: if (pressed) { SEND_STRING("../"); } break;
#line 65 "/home/tripham/Dev/Corne_QMK/filterpaper_qmk_userspace/features/combos.h"
    }
}
#line 11 "corne_keymap_json.c"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x6_3(KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, QK_GESC, LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G,   KC_H, RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_QUOT), KC_SCLN, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_N, LT(0,KC_M), LT(0,KC_COMM), LT(0,KC_DOT), LT(0,KC_SLSH), KC_ENT, RSA_T(KC_ESC), LT(SYM,KC_TAB), LCA_T(KC_ENT),   RSFT_T(KC_SPC), LT(NUM,KC_BSPC), RAG_T(KC_DEL)),
	[1] = LAYOUT_split_3x6_3(KC_TAB,  KC_Q, KC_W, KC_F, KC_P, KC_G,   KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_BSPC, QK_GESC, LCTL_T(KC_A), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T), KC_D,   KC_H, RSFT_T(KC_N), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_O), KC_SCLN, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_K, LT(0,KC_M), LT(0,KC_COMM), LT(0,KC_DOT), LT(0,KC_SLSH), KC_ENT, RSA_T(KC_ESC), _______, _______,   _______, _______, RAG_T(KC_DEL)),
	[2] = LAYOUT_split_3x6_3(KC_TAB,  KC_INS, KC_1, KC_2, KC_3, KC_VOLU,   KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_COLN, KC_BSPC, QK_GESC, KC_CAPS, KC_4, KC_5, KC_6, KC_VOLD,   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_SCLN, KC_SCLN, KC_LSFT, KC_DEL, KC_7, KC_8, KC_9, KC_0,   _______, S(A(KC_DOWN)), S(A(KC_UP)), _______, _______, KC_ENT, RSA_T(KC_ESC), MO(FNC), KC_ESC,   _______, _______, RAG_T(KC_DEL)),
	[3] = LAYOUT_split_3x6_3(KC_TAB,  _______, KC_LBRC, KC_LCBR, KC_RCBR, _______,   KC_CIRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_TILD, KC_BSPC, QK_GESC, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,   KC_ASTR, KC_MINS, KC_EQL, KC_BSLS, KC_GRV, KC_SCLN, KC_LSFT, _______, _______, KC_LT, KC_GT, _______,   KC_AMPR, KC_UNDS, KC_PLUS, KC_PIPE, _______, KC_ENT, RSA_T(KC_ESC), _______, _______,   _______, _______, RAG_T(KC_DEL)),
	[4] = LAYOUT_split_3x6_3(KC_TAB,  QK_BOOT, KC_F1, KC_F2, KC_F3, KC_F10,   _______, KC_WH_U, KC_MS_U, KC_WH_D, TG(CMK), KC_BSPC, QK_GESC, _______, KC_F4, KC_F5, KC_F6, KC_F11,   _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_SCLN, KC_LSFT, A(G(KC_PWR)), KC_F7, KC_F8, KC_F9, KC_F12,   _______, KC_BTN2, KC_BTN1, _______, HYPR(KC_S), KC_ENT, RSA_T(KC_ESC), _______, _______,   _______, _______, RAG_T(KC_DEL))
};
