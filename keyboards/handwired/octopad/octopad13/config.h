#pragma once


/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6465
#define DEVICE_VER      0x0001
/* in python2: list(u"whatever".encode('utf-16-le')) */
/*   at most 32 characters or the ugly hack in usb_main.c works */

//  Modified by Xydane
#define MANUFACTURER "QMK"
#define USBSTR_MANUFACTURER    'T', '\x00', 'M', '\x00', 'K', '\x00', ' ', '\x00', '\xc6', '\x00'
#define PRODUCT "OctoPad13"
#define USBSTR_PRODUCT         'C', '\x00', 'h', '\x00', 'i', '\x00', 'b', '\x00', 'i', '\x00', 'O', '\x00', 'S', '\x00', ' ', '\x00', 'Q', '\x00', 'M', '\x00', 'K', '\x00'
#define DESCRIPTION "QMK keyboard firmware with ChibiOS"

/* key matrix size */
//  Modified by Xydane
#define MATRIX_ROWS 4
#define MATRIX_COLS 4
#define DIODE_DIRECTION COL2ROW
