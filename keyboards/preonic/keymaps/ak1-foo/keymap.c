#include QMK_KEYBOARD_H

#include "keycode.h"
#include "ak1-foo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QED] = LAYOUT_preonic_grid( \
      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
      KC_Q,      KC_L,      KC_E,      KC_W,      KC_COMM,   XXXXXXX,   XXXXXXX,   KC_B,      KC_M,      KC_Y,      KC_H,      KC_P,      \
      KC_A,      KC_O,      KC_U,      KC_I,      KC_DOT,    XXXXXXX,   XXXXXXX,   KC_G,      KC_T,      KC_N,      KC_R,      KC_S,      \
      KC_C,      KC_V,      KC_X,      KC_J,      KC_ESC,    XXXXXXX,   XXXXXXX,   KC_Z,      KC_K,      KC_F,      KC_D,      KC_MINS,   \
      XXXXXXX,   XXXXXXX,   KC_LSFT,   KC_SPC,    LOWER,     XXXXXXX,   XXXXXXX,   RAISE,     KC_ENT,    KC_LCTL,   XXXXXXX,   XXXXXXX    \
      ),

  [_LOWER] = LAYOUT_preonic_grid( \
      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
      KC_PERC,   KC_MINS,   KC_BSLS,   KC_CIRC,   KC_GRV,    XXXXXXX,   XXXXXXX,   KC_DEL,    G(KC_LEFT),G(KC_DOWN),G(KC_UP),  G(KC_RGHT),\
      KC_PLUS,   KC_ASTR,   KC_SLSH,   KC_EQL,    KC_TILD,   XXXXXXX,   XXXXXXX,   KC_BSPC,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  \
      KC_HASH,   KC_DLR,    KC_QUES,   KC_AT,     KC_EXLM,   XXXXXXX,   XXXXXXX,   C(KC_BSPC),KC_HOME,   KC_PGDOWN, KC_PGUP,   KC_END,    \
      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   ADJUST,    KC_LNG1,   KC_LGUI,   XXXXXXX,   XXXXXXX    \
      ),

  [_RAISE] = LAYOUT_preonic_grid( \
      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
      C(KC_TAB), KC_7,      KC_8,      KC_9,      KC_COMMA,  XXXXXXX,   XXXXXXX,   KC_PIPE,   KC_LT,     KC_GT,     KC_LCBR,   KC_RCBR,   \
      KC_TAB,    KC_4,      KC_5,      KC_6,      KC_DOT,    XXXXXXX,   XXXXXXX,   KC_UNDS,   KC_LPRN,   KC_RPRN,   KC_LBRC,   KC_RBRC,   \
      C(S(KC_TAB)), KC_1,   KC_2,      KC_3,      KC_0,      XXXXXXX,   XXXXXXX,   KC_AMPR,   KC_COLN,   KC_SCOLON, KC_QUOTE,  KC_DQT,    \
      XXXXXXX,   XXXXXXX,   KC_LALT,   KC_LNG2,   ADJUST,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX    \
      ),

  [_ADJUST] =  LAYOUT_preonic_grid( \
      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
      KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     XXXXXXX,   XXXXXXX,   KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    \
      WIN1,      WIN2,      WIN3,      WIN4,      WIN5,      XXXXXXX,   XXXXXXX,   WIN6,      WIN7,      WIN8,      WIN9,      SGUI(KC_S),\
      KC_CAPS,   G(KC_V),   G(KC_X),   A(KC_F4),  KC_F11,    XXXXXXX,   XXXXXXX,   KC_F12,    XXXXXXX,   XXXXXXX,   KC_DEL,    KC_LGUI,   \
      XXXXXXX,   XXXXXXX,   RESET,     XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX    \
      )
};
