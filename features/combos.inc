// 3x5_2 layout key reference
// KC_Q    KC_W    KC_E    KC_R    KC_T      KC_Y    KC_U    KC_I    KC_O    KC_P
// HM_A    HM_S    HM_D    HM_F    KC_G      KC_H    HM_J    HM_K    HM_L    HM_QUOT
// KC_Z    KC_X    KC_C    KC_V    KC_B      KC_N    TH_M    TH_COMM TH_DOT  TH_SLSH
//                      SYM_TAB LCA_ENT      SFT_SPC NUM_BSP

#ifdef SWAP_HANDS_ENABLE
ACTN(swap_l, swap_hands_toggle(), KC_X, KC_C, KC_V)
ACTN(swap_r, swap_hands_toggle(), TH_M, TH_COMM, TH_DOT)
#endif
//ACTN(tog_ac, autocorrect_toggle(), KC_U, KC_I, KC_O)
ACTN(tog_caps, my_caps_lock_toggle(), KC_LSFT, KC_RSFT)

// Macros
//SSTR(vi_quit,  ":q!",    KC_Q,    KC_W)
//SSTR(vi_save,  ":x",     KC_Z,    KC_X)
SSTR(dir_up,   "../",    TH_DOT,  TH_SLSH)

// Special combos
COMB(tog_func,        TG(FNC), MO(FNC), KC_RSFT)
COMB(tog_numb,        TG(NUM), MO(NUM), KC_RSFT)
COMB(tog_mouse,       TG(MOU), MO(MOU), KC_RSFT)
COMB(mo_sys_left,     MO(SYS), MO(MOU), MO(FNC))
COMB(mo_sys_right,    MO(SYS), MO(NUM), KC_LGUI)

COMB(vol_up,   KC_VOLU,  KC_P,    HM_SCLN)
COMB(vol_dn,   KC_VOLD,  HM_SCLN, TH_SLSH)

// Noop thumbs
COMB(thmb_l,   KC_NO,    FNC, LCA_ENT)
COMB(thmb_r,   KC_NO,    SFT_SPC, NUM_BSP)

// Layer toggles
COMB(tog_num,  TG(NUM),  NUM_BSP, KC_N, TH_M)
COMB(tog_fnc,  TG(FNC),  FNC, KC_B, KC_V)

/* Horizontal combos - left hand */
COMB(comb_base_esc,     KC_ESC,   KC_W, KC_E)
COMB(comb_base_enter,   KC_ENT,   KC_E, KC_R)

COMB(comb_base_a,       C_S_T(KC_NO),  HM_A, HM_S)
COMB(comb_base_tab,     LCA_T(KC_TAB), HM_S, HM_D)
COMB(comb_base_spc,     LAG_T(KC_NO),  HM_D, HM_F)

COMB(comb_base_cut,     LCTL(KC_X),    KC_X, KC_V)
COMB(comb_base_copy,    LCTL(KC_INS),  KC_X, KC_C)
COMB(comb_base_paste,   LCTL(KC_INS),  HM_D, HM_F)

/* Horizontal combos - right hand */
COMB(comb_base_bspc,    KC_BSPC,  KC_U, KC_I)
COMB(comb_base_del,     KC_DEL,   KC_I, KC_O)

// QMK has issues with Shifted keycodes, refer to: https://thomasbaart.nl/2018/12/09/qmk-basics-tap-and-hold-actions/ and
// https://docs.qmk.fm/#/mod_tap?id=caveats
COMB(comb_base_lprn,    KC_LPRN,  HM_J, HM_K)
COMB(comb_base_rprn,    RCA_T(KC_RPRN),  HM_K, HM_L)
COMB(comb_base_seco,    RCS_T(KC_SCLN),  HM_L, HM_SCLN)

COMB(comb_base_lbrc,    KC_LBRC,  KC_M, KC_COMM)
COMB(comb_base_rbrc,    KC_RBRC,  KC_COMM, KC_DOT)

/* Vertical combos - left hand */
COMB(comb_base_at,      KC_AT,    KC_W, HM_S)
COMB(comb_base_hash,    KC_HASH,  KC_E, HM_D)
COMB(comb_base_dollar,  KC_DLR,   KC_R, HM_F)
COMB(comb_base_perc,    KC_PERC,  KC_T, KC_G)

COMB(comb_base_grave,   KC_GRAVE, HM_S, KC_X)
COMB(comb_base_bsls,    KC_BSLS,  HM_D, KC_C)
COMB(comb_base_equal,   KC_EQUAL, HM_F, KC_V)
COMB(comb_base_tilde,   KC_TILDE, KC_G, KC_B)

/* Vertical combos - right hand */
COMB(comb_base_circ,    KC_CIRC,  KC_Y, KC_H)
COMB(comb_base_plus,    KC_PLUS,  KC_U, HM_J)
COMB(comb_base_astr,    KC_ASTR,  KC_I, HM_K)
COMB(comb_base_ampr,    KC_AMPR,  KC_O, HM_L)

COMB(comb_base_unds,    KC_UNDS,  KC_H, KC_N)
COMB(comb_base_pmns,    KC_PMNS,  HM_J, KC_M)
COMB(comb_base_psls,    KC_PSLS,  HM_K, KC_COMM)
COMB(comb_base_pipe,    KC_PIPE, HM_L, KC_DOT)
