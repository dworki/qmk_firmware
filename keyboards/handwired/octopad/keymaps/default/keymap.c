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
#include "led.h"


// Define layer names
#define _NORMAL 0


// Highly Modified by Xydane
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NORMAL] = LAYOUT_octopad(
    KC_1,          KC_2,        KC_3, \
    KC_Q,    KC_W,    KC_E,     KC_R, \
             KC_UP,             KC_PGUP, \
    KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDOWN ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void keyboard_post_init_user(void) {

}
