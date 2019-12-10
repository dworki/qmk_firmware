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

#define MODS_SHIFT_MASK (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Define layer names
#define _NORMAL 0
#define _KEYPAD 1
#define _FUNC 2

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL,
  SFT_ESC,
  KEYLOCK,
  MYRST,
};


// Highly Modified by Xydane
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NORMAL] = LAYOUT_seventy_ansi(
     KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, TG(1),   KC_PGUP, \
    KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,       KC_BSPC,     KC_PGDOWN, \
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,      KC_BSLASH,  KC_DELETE, \
    KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,             KC_ENT,      KC_HOME, \
    KC_LSPO,  KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,     KC_RSPC,      KC_UP,  KC_END, \
    KC_LCPO, KC_LGUI, KC_LALT,                            KC_SPC,                      KC_RALT,   MO(2),      KC_RCPC,   KC_LEFT, KC_DOWN, KC_RIGHT ),

  [_KEYPAD] = LAYOUT_seventy_ansi(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS, \
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_TRNS, KC_TRNS,      KC_TRNS,    KC_TRNS, \
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_PAST, KC_TRNS,             KC_TRNS,     KC_TRNS, \
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0,   KC_TRNS, KC_TRNS, KC_PSLS,      KC_TRNS,    KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                     KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS ),

  [_FUNC] = LAYOUT_seventy_ansi(
    KEYLOCK, DM_REC1, DM_REC2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, \
    DM_RSTP, DM_PLY1, DM_PLY2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_INSERT,   KC_VOLD, \
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, MYRST,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,    KC_MUTE, \
    KC_CAPS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_FIND, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS,     KC_TRNS, \
    KC_TRNS,  KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NLCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,     RGB_VAI, KC_POWER, \
    KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                     KC_TRNS,   KC_TRNS,    KC_TRNS,   RGB_TOG, RGB_VAD, RGB_MOD ),
};

void setrgb_range(uint8_t r, uint8_t g, uint8_t b, uint8_t start, uint8_t end) {
    if (start < 0 || start >= end || end > RGBLED_NUM) {
        return;
    }

    for (uint8_t i = start; i < end; i++) {
        led[i].r = r;
        led[i].g = g;
        led[i].b = b;
    }
}

void sethsv_range(uint8_t hue, uint8_t sat, uint8_t val, uint8_t start, uint8_t end) {
    LED_TYPE tmp_led;
    sethsv(hue, sat, val, &tmp_led);
    setrgb_range(tmp_led.r, tmp_led.g, tmp_led.b, start, end);
}


bool keys_locked = false;
bool recording = false;
layer_state_t lState;
uint8_t usb_leds;

#define C_RED       0,255,255
#define C_PRIMARY   128,255,val
#define C_KEYPAD    85,255,val
#define C_FUNC      212,255,val
#define C_OFF       0,0,0

void update_backlight(void) {
  uint8_t val = rgblight_get_val();

  if (keys_locked) {
    sethsv_range(C_OFF,0,45);
    sethsv_range(C_RED,40,41);
    rgblight_set();
    return;
  }

  uint8_t l = get_highest_layer(lState);
  if (l == _FUNC) {
    sethsv_range(C_FUNC,0,45);
  } else {
    sethsv_range(C_PRIMARY,0,45);
  }
  if (layer_state_is(_KEYPAD)) {
    sethsv_range(C_KEYPAD,15,30);

  }

  if (recording) {
    sethsv_range(C_RED,38,42);
  }

  // CAPSLOCK
  if (usb_leds & (1<<USB_LED_CAPS_LOCK)) {
    sethsv_range(C_RED,41,45);
  }
  // CAPSLOCK
  if (layer_state_is(_KEYPAD) && (usb_leds & (1<<USB_LED_NUM_LOCK))) {
    sethsv_range(C_RED,25,27);
  }

  rgblight_set();

}
// tap_code(KC_VOLU);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == KEYLOCK && record->event.pressed) {
    keys_locked = !keys_locked;
    return false;
  }
  if (keys_locked && keycode != TG(1) && keycode != MO(2)) {
    return false;
  }

  switch (keycode) {
    case MYRST:
      if (record->event.pressed) {
          NVIC_SystemReset();
      }
      break;
    // case QMKBEST:
    //   if (record->event.pressed) {
    //     // when keycode QMKBEST is pressed
    //     SEND_STRING("QMK is the best thing ever!");
    //   } else {
    //     // when keycode QMKBEST is released
    //   }
    //   break;
    // case QMKURL:
    //   if (record->event.pressed) {
    //     // when keycode QMKURL is pressed
    //     SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
    //   } else {
    //     // when keycode QMKURL is released
    //   }
    //   break;
    // case SFT_ESC:
    //   if (record->event.pressed) {
    //     if (get_mods() & MODS_SHIFT_MASK) {
    //       add_key(KC_GRV);
    //       send_keyboard_report();
    //     } else {
    //       add_key(KC_ESC);
    //       send_keyboard_report();
    //     }
    //   } else {
    //     if (get_mods() & MODS_SHIFT_MASK) {
    //       del_key(KC_GRV);
    //       send_keyboard_report();
    //     } else {
    //       del_key(KC_ESC);
    //       send_keyboard_report();
    //     }
    //   }
    //   return false;
  }

  return true;
}

void dynamic_macro_record_start_user() {
  recording = true;
  update_backlight();
}

void dynamic_macro_record_end_user(int8_t direction) {
  recording = false;
  update_backlight();
}

void keyboard_post_init_user(void) {
  lState = 1;
  wait_ms(1);
  uint8_t val = rgblight_get_val();
  sethsv_range(C_RED, 0,45);
  rgblight_set();
  for (int8_t i = 40; i>=0; i-=5){
    wait_ms(100);
    sethsv_range(C_PRIMARY,i,i+5);
    rgblight_set();
  }
  wait_ms(1);
  update_backlight();
}

layer_state_t layer_state_set_user(layer_state_t state) {
  lState = state;
  //printf("layer: %d\n", state);
  return state;
}

void led_set(uint8_t usb_led){
  usb_leds = usb_led;
  //printf("led: %d\n", usb_leds);
  update_backlight();
}


// void suspend_power_down_user(void) {
//   rgb_matrix_set_suspend_state(true);
// }
//
// void suspend_wakeup_init_user(void) {
//   rgb_matrix_set_suspend_state(false);
// }
