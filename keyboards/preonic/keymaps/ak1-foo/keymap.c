#include QMK_KEYBOARD_H

#include "keycode.h"
#include "ak1-foo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QED] = LAYOUT_preonic_grid( \
      XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
      XXXXXXX,         KC_Q,          KC_L,           KC_E,    KC_W,    KC_COMMA,  KC_B,  KC_M,    KC_Y,    KC_H,    KC_P,    XXXXXXX, \
      XXXXXXX,        KC_A,          KC_O,           KC_U,    KC_I,    KC_DOT,    KC_G,  KC_T,    KC_N,    KC_R,    KC_S,    XXXXXXX, \
      XXXXXXX,        KC_C,          KC_V,           KC_X,    KC_J,    KC_ESC,    KC_Z,  KC_K,    KC_F,    KC_D,    KC_MINUS, XXXXXXX, \
      XXXXXXX,        XXXXXXX, XXXXXXX,        KC_LSFT, KC_SPACE,  LOWER, RAISE,   KC_ENT, KC_LCTRL, XXXXXXX,   XXXXXXX, XXXXXXX \
      ),

  [_LOWER] = LAYOUT_preonic_grid( \
      XXXXXXX,        XXXXXXX, XXXXXXX,     XXXXXXX,    XXXXXXX,       XXXXXXX,     XXXXXXX,        XXXXXXX,  LCA(KC_1),   KC_MPLY, XXXXXXX,  KC_SYSTEM_SLEEP, \
      _______,        KC_NUBS, KC_MINUS,   KC_PERCENT, KC_CIRCUMFLEX, KC_GRAVE,     XXXXXXX,    LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_UP),  LGUI(KC_RIGHT),  KC_DEL, \
      KC_LCTL,        KC_PLUS, KC_ASTR,     KC_SLASH,   KC_EQUAL,      KC_TILD,     XXXXXXX,     KC_LEFT,  KC_DOWN,   KC_UP,   KC_RIGHT,  KC_RCTL, \
      KC_LSFT,        KC_HASH, KC_DOLLAR, KC_QUESTION,  KC_AT,         KC_EXLM,     XXXXXXX,      KC_HOME,  KC_PGDOWN, KC_PGUP, KC_END,    KC_RSFT, \
      XXXXXXX,     XXXXXXX,   XXXXXXX,     XXXXXXX,     XXXXXXX,      XXXXXXX,           ADJUST,   KC_BSPC,   KC_LGUI,   XXXXXXX,     XXXXXXX,  _______ \
      ),

  [_RAISE] = LAYOUT_preonic_grid( \
      XXXXXXX,    XXXXXXX,  XXXXXXX,XXXXXXX,     XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX, _______, \
      _______,     KC_TAB,    KC_7,  KC_8,   KC_9,             KC_COMMA,            KC_PIPE,        KC_LT,     KC_GT,     KC_LCBR,  KC_RCBR, KC_DEL, \
      _______,      LCTL(KC_TAB),   KC_4,     KC_5,       KC_6,       KC_DOT,      KC_UNDS,     KC_LPRN,   KC_RPRN,   KC_LBRC,  KC_RBRC, KC_RCTL, \
      _______,       LCTL(LSFT(KC_TAB)),  KC_1,  KC_2, KC_3,      KC_0,             KC_AMPR,        KC_COLN,   KC_SCOLON, KC_QUOTE, KC_DQT,  KC_RSFT, \
      XXXXXXX,        _______, _______,      KC_LALT,   KC_0, ADJUST,           XXXXXXX,        XXXXXXX,  XXXXXXX,   XXXXXXX, KC_RALT,  _______ \
      ),

  [_ADJUST] =  LAYOUT_preonic_grid( \
      RESET,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX,        KC_F1,    KC_F2, KC_F3,KC_F4,KC_F5, KC_F6, KC_F7, KC_F8,KC_F9,KC_F10,XXXXXXX,\
      XXXXXXX,        WIN1, WIN2, WIN3, WIN4, WIN5, WIN6, WIN7, WIN8, WIN9,SGUI(KC_S),  XXXXXXX,\
      XXXXXXX,        KC_CAPS, LGUI(KC_V), LGUI(KC_X), XXXXXXX, KC_F11,   KC_F12, XXXXXXX,XXXXXXX, KC_DEL, KC_LGUI,  XXXXXXX,\
      XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
      )
};
