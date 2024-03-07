// Copyright 2021 Keyboard Dweebs (@doesntfazer)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H


#define _BASE 0
#define _GAMING 1
#define _COLEMAK 2

#define _NAV 5
#define _SYM 6


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │Bsp├───┐   ┌───┤Ent│
      *               └───┤Tab│   │Spc├───┘
      *                   └───┘   └───┘
      */
    [_BASE] = LAYOUT_split_3x6_3(
    KC_ESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
    KC_LSFT,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT,
    KC_LCTL,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_LALT,
                                       KC_BSPC, MO(_SYM), DF(_GAMING),  MO(_NAV),KC_TAB,  KC_SPC
    ),
    [_GAMING] = LAYOUT_split_3x6_3(
    KC_TRNS, KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_A,    KC_S,    KC_D,    KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       KC_SPC,   KC_TRNS, DF(_COLEMAK),    KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_COLEMAK] = LAYOUT_split_3x6_3(
    KC_ESC, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_BSPC,
    KC_LSFT,KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                               KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_ENT,
    KC_LCTL,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RALT,
                                       KC_BSPC, MO(_SYM), DF(_BASE),   KC_RGUI, KC_TAB,  KC_SPC
    ),
    [_NAV] = LAYOUT_split_3x6_3(
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_MUTE, KC_VOLU,                               KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_LGUI, KC_VOLD,                               KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_DEL,  KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_MPRV, KC_MNXT, KC_MPLY,                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                       KC_NO,    KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO
    ),
    [_SYM] = LAYOUT_split_3x6_3(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                               KC_ASTR, KC_9,    KC_EQL,  KC_UNDS, KC_GRV,  KC_DQUO,
    KC_TRNS, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_CIRC,                               KC_MINS, KC_5,    KC_6,    KC_7,    KC_8,    KC_QUOT,
    KC_TRNS, KC_LCBR, KC_RCBR, KC_LT,   KC_GT,   KC_AMPR,                               KC_PLUS, KC_1,    KC_2,    KC_3,    KC_4,    KC_TRNS,
                                       KC_TRNS,  KC_TRNS, KC_TRNS,    KC_PIPE, KC_BSLS, KC_0
    ),
    // [_NUMBERS] = LAYOUT_split_3x6_3(
    // KC_ESC, KC_9,    KC_0,    KC_TRNS, KC_TRNS,  KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
    // KC_LSFT,KC_5,    KC_6,    KC_7,    KC_8,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT,
    // KC_LCTL,KC_1,    KC_2,    KC_3,    KC_4,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RALT,
    //                                    KC_BSPC, KC_TAB, KC_LGUI,   KC_RGUI,KC_TAB,  KC_SPC
    // ),
};




    // [_BASE] = LAYOUT_split_3x6_3(
    // KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //                                    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
    // ),
