/* Copyright 2021 Jane Bernhardt
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

/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 */

#include QMK_KEYBOARD_H

enum {
    _ALPHA,   // default
    _GAME,    // gaming
    _SPECIAL, // special characters
    _NUMBERS  // numbers/function/motion
};

#include "g/keymap_combo.h"

#define KC_GUI_A   MT(MOD_LGUI, KC_A)    // Tap for A, hold for Meta
#define KC_SFT_Z   MT(MOD_RSFT, KC_Z)    // Tap for Z, hold for Shift
#define KC_SFT_SL  MT(MOD_RSFT, KC_SLSH) // Tap for slash, hold for Shift
#define KC_ALT_D   MT(MOD_LALT, KC_D)    // Tap for D, hold for Alt
#define KC_ALT_K   MT(MOD_RALT, KC_K)    // Tap for K, hold for Alt
#define KC_CTL_S   MT(MOD_LCTL, KC_S)    // Tap for S, hold for Control
#define KC_CTL_L   MT(MOD_RCTL, KC_L)    // Tap for L, hold for Control
#define KC_SPE_SPC LT(_SPECIAL, KC_SPC)  // Tap for Space, hold for Special layer
#define KC_NB      TG(_NUMBERS)          // Press for Numbers layer

    /* Combomap
     *
     * ,-----------------------------.      ,-----------------------------.
     * |     |     |     |     |     |      |     |     |     |     |     |
     * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-BSPC|
     * |     |     |     |     |     |      |     |     |     |     |     |
     * |-----+-----+-----+-ESC-+-TAB-|      |-----+-ENT-+-----+-----+-----|
     * |     |     |     |     |     |      |     |     |     |     |     |
     * `-----------------------------'      `-----------------------------'
     *            .-----------------.       .-----------------.
     *            |     |     |     |       |     |     |     |
     *            '-----------------'       '-----------------'
     */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Alpha layer
     *
     * ,-----------------------------.      ,-----------------------------.
     * |  Q  |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |  P  |
     * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
     * |A GUI|S CTL|D ALT|  F  |  G  |      |  H  |  J  |K ALT|L CTL|  ;  |
     * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
     * |SFT Z|  X  |  C  |  V  |  B  |      |  N  |  M  |  ,  |  .  |SFT /|
     * `-----------------------------'      `-----------------------------'
     *       .-----------------------.      .------------------.
     *       |      | SPC SPE |      |      |      | NUM |     |
     *       '-----------------------'      '------------------'
     */
    [_ALPHA] = LAYOUT_split_3x5_3(
         KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,   KC_U,   KC_I,     KC_O,    KC_P,
         KC_GUI_A, KC_CTL_S,KC_ALT_D,KC_F,    KC_G,          KC_H,   KC_J,   KC_ALT_K, KC_CTL_L,KC_SCLN,
         KC_SFT_Z, KC_X,    KC_C,    KC_V,    KC_B,          KC_N,   KC_M,   KC_COMMA, KC_DOT,  KC_SFT_SL,
                      KC_TRNS, KC_SPE_SPC, KC_TRNS,          KC_TRNS, KC_NB, KC_TRNS),

    /* Gaming layer
     *
     * ,-----------------------------.      ,-----------------------------.
     * | TAB |  Q  |  W  |  E  |  R  |      |     |     |     |     |     |
     * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
     * | CTRL|  A  |  S  |  D  |  F  |      |     |     |     |     |     |
     * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
     * | SHFT|  Z  |  X  |  C  |  V  |      |     |     |     |     |     |
     * `-----------------------------'      `-----------------------------'
     *            .------------------.      .------------------.
     *            | META | SPC |     |      |     |     |      |
     *            '------------------'      '------------------'
     */
    [_GAME] = LAYOUT_split_3x5_3(
         KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_LCTL,  KC_A,   KC_S,   KC_D,   KC_F,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_LSFT,  KC_Z,   KC_X,   KC_C,   KC_V,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                       KC_TRNS, KC_SPC ,KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS),

    /* Special characters layer
     *
     * ,-----------------------------.      ,-----------------------------.
     * |  !  |  @  |  {  |  }  |  |  |      |  `  |  -  |  =  |     |  \  |
     * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
     * |  #  |  $  |  (  |  )  |     |      | LFT | DWN | UP  | RGT |  '  |
     * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
     * |  %  |  ^  |  [  |  ]  |     |      |  &  |     |  +  |  *  |     |
     * `-----------------------------'      `-----------------------------'
     *           .-------------------.      .-----------------.
     *           |       |     |     |      |     |  "  |     |
     *           '-------------------'      '-----------------'
     */
    [_SPECIAL] = LAYOUT_split_3x5_3(
         KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,          KC_GRV,  KC_MINS, KC_EQL , KC_TRNS, KC_BSLS,
         KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TRNS,          KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_QUOT,
         KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TRNS,          KC_AMPR, KC_TRNS, KC_PLUS, KC_ASTR, KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, LSFT(KC_QUOTE), KC_TRNS),

    /* Numbers/Function/Motion layer
     *
     * ,-----------------------------.      ,-----------------------------.
     * |     |  7  |  8  |  9  |     |      | F10 | F7  |  F8 | F9  |     |
     * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
     * |     |  4  |  5  |  6  |     |      | F11 | F4  |  F5 | F6  |     |
     * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
     * |  0  |  1  |  2  |  3  |     |      | F12 | F1  |  F2 | F3  |     |
     * `-----------------------------'      `-----------------------------'
     *             .-----------------.      .-----------------.
     *             |     |     |     |      |     |     |     |
     *             '-----------------'      '-----------------'
     */
    [_NUMBERS] = LAYOUT_split_3x5_3(
         KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS,         KC_F10, KC_F7, KC_F8, KC_F9, KC_TRNS,
         KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS,         KC_F11, KC_F4, KC_F5, KC_F6, KC_TRNS,
         KC_0   , KC_1, KC_2, KC_3, KC_TRNS,         KC_F12, KC_F1, KC_F2, KC_F3, KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS)
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_GUI_A:
        case KC_CTL_S:
        case KC_ALT_D:
        case KC_ALT_K:
        case KC_CTL_L:
            return false;
        default:
            return true;
    }
}
