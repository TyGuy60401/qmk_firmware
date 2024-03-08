// Copyright 2021 Keyboard Dweebs (@doesntfazer)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H


#define _BASE 0
#define _GAMING 1
#define _COLEMAK 2

#define _GAME_NUM 4
#define _NAV 5
#define _SYM 6
#define _FUNC 7


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _SYM, _FUNC);
}

void leader_start_user(void) {

}


void leader_end_user(void) {
    bool did_leader_succeed = false;

    if (leader_sequence_one_key(KC_F)) {
        SEND_STRING("Testing the leader");
        did_leader_succeed = true;
    }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐          ┌───┬───┬───┬───┬───┐───┐
      * │ESC│ Q │ W │ E │ R │ T │          │ Y │ U │ I │ O │ P │ BS│
      * ├───┼───┼───┼───┼───┼───┤          ├───┼───┼───┼───┼───┤───┤
      * │SFT│ A │ S │ D │ F │ G │          │ H │ J │ K │ L │ ; │ENT│
      * ├───┼───┼───┼───┼───┼───┤          ├───┼───┼───┼───┼───┤───┤
      * │CTL│ Z │ X │ C │ V │ B │          │ N │ M │ , │ . │ / │ALT│
      * └───┴───┴───┴───┴───┴───┘          └───┴───┴───┴───┴───┘───┘
      *               ┌───┐                      ┌───┐
      *               │Bsp├───┐              ┌───┤Ent│
      *               └───┤Tab│───┐      ┌───│Spc├───┘
      *                   └───┘Tab│      │Spc└───┘
      *                       └───┘      └───┘
      */
    [_BASE] = LAYOUT_split_3x6_3(
    KC_ESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
    KC_LSFT,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT,
    KC_LCTL,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_LALT,
                                       KC_DEL, MO(_SYM), QK_LEAD,  MO(_NAV),KC_TAB,  KC_SPC
    ),
    [_GAMING] = LAYOUT_split_3x6_3(
    KC_TRNS, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       KC_SPC,   MO(_GAME_NUM), QK_LEAD,    KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_COLEMAK] = LAYOUT_split_3x6_3(
    KC_ESC, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_BSPC,
    KC_LSFT,KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                               KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_ENT,
    KC_LCTL,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RALT,
                                       KC_DEL, MO(_SYM), QK_LEAD,   KC_RGUI, KC_TAB,  KC_SPC
    ),
    [_NAV] = LAYOUT_split_3x6_3(
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_MUTE, KC_VOLU,                               KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_LGUI, KC_VOLD,                               KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_DEL,  KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_MPRV, KC_MNXT, KC_MPLY,                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                       KC_NO,    KC_TRNS,   KC_NO,      KC_NO,   KC_NO,   KC_NO
    ),
    [_SYM] = LAYOUT_split_3x6_3(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                               KC_ASTR, KC_9,    KC_EQL,  KC_UNDS, KC_GRV,  KC_DQUO,
    KC_TRNS, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_CIRC,                               KC_MINS, KC_5,    KC_6,    KC_7,    KC_8,    KC_QUOT,
    KC_TRNS, KC_LCBR, KC_RCBR, KC_LT,   KC_GT,   KC_AMPR,                               KC_PLUS, KC_1,    KC_2,    KC_3,    KC_4,    KC_TRNS,
                                       KC_TRNS,  KC_TRNS, KC_TRNS,    KC_PIPE, KC_BSLS, KC_0
    ),
    [_FUNC] = LAYOUT_split_3x6_3(
    KC_TRNS, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO,                               KC_SCRL, KC_F9,    KC_F10,    KC_F11,   KC_F12,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,                               KC_NUM,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,                               KC_CAPS, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_TRNS,
                                       KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_GAME_NUM] = LAYOUT_split_3x6_3(
    KC_ESC, KC_9,    KC_0,    KC_TRNS, KC_TRNS, KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
    KC_LSFT,KC_5,    KC_6,    KC_7,    KC_8,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT,
    KC_LCTL,KC_1,    KC_2,    KC_3,    KC_4,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RALT,
                                       KC_BSPC, KC_TAB, KC_LGUI,   KC_RGUI,KC_TAB,  KC_SPC
    ),
};




    // [_BASE] = LAYOUT_split_3x6_3(
    // KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //                                    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
    // ),
