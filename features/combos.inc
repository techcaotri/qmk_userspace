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
ACTN(tog_caps, my_caps_word_toggle(), KC_LSFT, KC_RSFT)

// Macros
//SSTR(vi_quit,  ":q!",    KC_Q,    KC_W)
//SSTR(vi_save,  ":x",     KC_Z,    KC_X)
SSTR(dir_up,   "../",    TH_DOT,  TH_SLSH)

COMB(vol_up,   KC_VOLU,  KC_P,    HM_QUOT)
COMB(vol_dn,   KC_VOLD,  HM_QUOT, TH_SLSH)

// Noop thumbs
COMB(thmb_l,   KC_NO,    FNC, LCA_ENT)
COMB(thmb_r,   KC_NO,    SFT_SPC, NUM_BSP)

// Layer toggles
COMB(tog_num,  TG(NUM),  NUM_BSP, KC_N, TH_M)
COMB(tog_fnc,  TG(FNC),  FNC, KC_B, KC_V)
<<<<<<< HEAD
=======

/* Horizontal combos - left hand */


/* Horizontal combos - right hand */
COMB(comb_base_bspc,    KC_BSPC,  KC_U, KC_I)
COMB(comb_base_del,     KC_DEL,   KC_I, KC_O)
COMB(comb_base_lprn,    KC_LPRN,  HM_J, HM_K)
COMB(comb_base_rprn,    KC_RPRN,  HM_K, HM_L)


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

>>>>>>> f6eaffc2b00d08c1990ad61a5201fb1dc7a4c4a8
