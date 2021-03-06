/* Copyright 2018 Milton Griffin
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
#include QMK_KEYBOARD_H

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

// Keyboard Layers
#define _QW 0
#define _LOWER 1
#define _RAISE 2

#define KC_RASE RAISE
#define KC_RASEKN LT(_RAISE, KC_LANG1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | 1      | 2      | 3      | 4      | 5      |        |        |        | 6      | 7      | 8      | 9      | 0      | =      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |        |        |        | Y      | U      | I      | O      | P      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | Ctrl   | A      | S      | D      | F      | G      |        |        |        | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | [      |        | ]      | N      | M      | ,      | .      | /      | -      |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | Esc    | LOWER  | Ctrl   | Alt    | LGUI   | SPACE  | Del    |        | Bksp   | Enter  | Raise  | Left   | Down   | Up     | Right  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = LAYOUT_ortho_5x15(
    KC_GRV,  KC_1,  KC_2,    KC_3,    KC_4,            KC_5,   _______, _______, _______, KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_EQL, \
    KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R,            KC_T,   _______, _______, _______, KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_LCTL, KC_A,  KC_S,    KC_D,    KC_F,            KC_G,   _______, _______, _______, KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,  KC_X,    KC_C,    KC_V,            KC_B,   KC_LBRC, _______, KC_RBRC, KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_MINS, \
    KC_ESC,  MO(_LOWER), KC_LCTL, KC_LALT, GUI_T(KC_LANG2), KC_SPC, KC_DEL,  _______, KC_BSPC, KC_ENT,  KC_RASEKN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
    ),

 [_LOWER] = LAYOUT_ortho_5x15(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   _______, _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
    _______, _______, _______, _______, RGB_HUD,  RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12, \
    _______, _______, _______, _______, RGB_SAD,  RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, RGB_VAD,  RGB_VAI, KC_LCBR, _______, KC_RCBR, _______, _______, _______, _______, _______, _______, \
    RESET,   _______, _______, _______, RGB_RMOD, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [_RAISE] = LAYOUT_ortho_5x15(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, KC_F12, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_LCBR, _______, KC_RCBR, _______, _______, KC_LCBR, KC_RCBR, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
 )
};
