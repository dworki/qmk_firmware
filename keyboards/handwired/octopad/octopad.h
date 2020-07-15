#pragma once

#include "quantum.h"
#include "led.h"

#define LAYOUT_octopad( \
  K00,    K01,   K02, \
  K10, K11, K12, K13, \
       K20,      K21, \
  K30, K31, K32, K33 \
) { \
  { K00, KC_NO, K01, K02 }, \
  { K10, K11, K12, K13 }, \
  { KC_NO, K20, KC_NO, K21}, \
  { K30, K31, K32, K33} \
}
