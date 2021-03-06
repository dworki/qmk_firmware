#pragma once


/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6464
#define DEVICE_VER      0x0001
/* in python2: list(u"whatever".encode('utf-16-le')) */
/*   at most 32 characters or the ugly hack in usb_main.c works */

//  Modified by Xydane
#define MANUFACTURER "QMK"
#define USBSTR_MANUFACTURER    'T', '\x00', 'M', '\x00', 'K', '\x00', ' ', '\x00', '\xc6', '\x00'
#define PRODUCT "BluePill70"
#define USBSTR_PRODUCT         'C', '\x00', 'h', '\x00', 'i', '\x00', 'b', '\x00', 'i', '\x00', 'O', '\x00', 'S', '\x00', ' ', '\x00', 'Q', '\x00', 'M', '\x00', 'K', '\x00'
#define DESCRIPTION "QMK keyboard firmware with ChibiOS"

/* key matrix size */
//  Modified by Xydane
#define MATRIX_ROWS 6
#define MATRIX_COLS 15
#define DIODE_DIRECTION COL2ROW

// The pin connected to the data pin of the LEDs
#define RGB_DI_PIN          A7
#define RGBLED_NUM          45
#define RGBLIGHT_LIMIT_VAL  120
#define RGBLIGHT_SLEEP
//#define RGBLIGHT_ANIMATIONS
#define DYNAMIC_MACRO_NO_NESTING
#define DYNAMIC_MACRO_SIZE  256

#define SPACE_CADET_MODIFIER_CARRYOVER
#define TAPPING_TERM 200
// curly braces space cadet on CTRLs
#define LCPO_KEYS KC_LCTL, KC_LSFT, KC_LBRC
#define RCPC_KEYS KC_RCTL, KC_RSFT, KC_RBRC
