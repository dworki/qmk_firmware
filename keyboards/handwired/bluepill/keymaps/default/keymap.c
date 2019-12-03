/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

//#include "backlight.h"

#define MODS_SHIFT_MASK (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Define layer names
#define _NORMAL 0
#define _FNONE 1
#define _FNTWO 2

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL,
  SFT_ESC,
  KEYLOCK
};


// Highly Modified by Xydane
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NORMAL] = LAYOUT_seventy_ansi(
      KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,  KC_F12, KC_PSCR, KC_HOME, KC_END, \
    KC_GRAVE, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,     KC_BSPC,      KC_DELETE, \
      KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,    KC_BSLASH,    KC_PGUP, \
     KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,           KC_ENT,         KC_PGDOWN, \
     KC_LSPO, KC_NUBS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,     KC_RSPC,     KC_UP,   TT(2), \
     KC_LCTL, KC_LGUI,KC_LALT,                        KC_SPC,                  KC_RALT,   MO(1),    KC_RCTL,   KC_LEFT, KC_DOWN, KC_RIGHT ),

  [_FNONE] = LAYOUT_seventy_ansi(
    KEYLOCK, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    DM_RSTP, DM_PLY1, DM_PLY2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_MUTE, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_VOLU, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_PAST, KC_TRNS,             KC_TRNS,       KC_VOLD, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0,   KC_PDOT, KC_PENT, KC_PSLS,      KC_TRNS,     KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS,                          KC_TRNS,   KC_TRNS,  KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS ),

  [_FNTWO] = LAYOUT_seventy_ansi(
    KEYLOCK, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, DYN_REC_START1, DM_REC2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_MUTE, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_VOLU, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_PAST, KC_TRNS,             KC_TRNS,       KC_VOLD, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0,   KC_PDOT, KC_PENT, KC_PSLS,      KC_TRNS,     KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS,                          KC_TRNS,   KC_TRNS,  KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS ),
};


// tap_code(KC_VOLU);

bool keys_locked = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == KEYLOCK && record->event.pressed) {
    keys_locked = !keys_locked;
    return false;
  }
  if (keys_locked && keycode != MO(1) && keycode != TT(2)) {
    return false;
  }

  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
    case SFT_ESC:
      if (record->event.pressed) {
        if (get_mods() & MODS_SHIFT_MASK) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (get_mods() & MODS_SHIFT_MASK) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      return false;
  }
  return true;
}

void matrix_init_user(void) {
}



/* Layer based ilumination, just binary */
uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
  case _FNONE:
    palSetPad(GPIOA, 0);  //OFF Color A
    palClearPad(GPIOA, 1); //ON Color B
    break;
  case _FNTWO:
    palClearPad(GPIOA, 0); //ON Color A
    palSetPad(GPIOA, 1);  //ON Color B
    break;
  default: //  for any other layers, or the default layer
    if (keys_locked) {
      palClearPad(GPIOA, 0); //ON Color A
      palClearPad(GPIOA, 1);  //OFF Color B
    } else {
      palSetPad(GPIOA, 0); //ON Color A
      palSetPad(GPIOA, 1);  //OFF Color B
    }
    break;
  }
  return state;
}
