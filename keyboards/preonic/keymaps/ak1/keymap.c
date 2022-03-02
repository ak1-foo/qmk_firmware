#include QMK_KEYBOARD_H

#include "keycode.h"

enum layer_number {
    _QED = 0,
    _QWERTY,
    _CALC,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QED = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  ADJUST,

  WIN1,
  WIN2,
  WIN3,
  WIN4,
  WIN5,
  WIN6,
  WIN7,
  WIN8,
  WIN9,
  WIN0,

  T_CTL,
  T_SFT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QED] = LAYOUT_preonic_grid( \
      XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
      XXXXXXX,         KC_Q,          KC_L,           KC_E,    KC_W,    KC_COMMA,  KC_B,  KC_M,    KC_Y,    KC_H,    KC_P,    XXXXXXX, \
      XXXXXXX,        KC_A,          KC_O,           KC_U,    KC_I,    KC_DOT,    KC_G,  KC_T,    KC_N,    KC_R,    KC_S,    XXXXXXX, \
      XXXXXXX,        KC_C,          KC_V,           KC_X,    KC_J,    KC_ESC,    KC_Z,  KC_K,    KC_F,    KC_D,    KC_MINUS, XXXXXXX, \
      XXXXXXX,        LALT(KC_LEFT), KC_LALT,        T_SFT, KC_SPACE,  LOWER, RAISE,   KC_ENT, T_CTL, XXXXXXX,   LALT(KC_F10),QWERTY \
      ),

  [_QWERTY] = LAYOUT_preonic_grid( \
      XXXXXXX, KC_1,     KC_2,     KC_3,    KC_4,    KC_5,       _______,     _______, _______, _______, _______, _______, \
      KC_ESC,  KC_Q,      KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,        KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
      KC_TAB,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,       KC_H,        KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT, _______, \
      KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,       KC_N,        KC_M,    KC_COMM, KC_DOT,  KC_SLSH, QED, \
      KC_LCTL, _______,  KC_ENT,  KC_M,    KC_LALT, KC_SPC,     ADJUST,   KC_ENT,  KC_LGUI, KC_LCTL,   LALT(KC_F10),QWERTY \
      ),

  [_LOWER] = LAYOUT_preonic_grid( \
      XXXXXXX,        XXXXXXX, XXXXXXX,     XXXXXXX,    XXXXXXX,       XXXXXXX,     XXXXXXX,        XXXXXXX,  LCA(KC_1),   KC_MPLY, XXXXXXX,  KC_SYSTEM_SLEEP, \
      _______,        KC_NUBS, KC_MINUS,   KC_PERCENT, KC_CIRCUMFLEX, KC_GRAVE,     XXXXXXX,    LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_UP),  LGUI(KC_RIGHT),  KC_DEL, \
      KC_LCTL,        KC_PLUS, KC_ASTR,     KC_SLASH,   KC_EQUAL,      KC_TILD,     XXXXXXX,     KC_LEFT,  KC_DOWN,   KC_UP,   KC_RIGHT,  KC_RCTL, \
      KC_LSFT,        KC_HASH, KC_DOLLAR, KC_QUESTION,  KC_AT,         KC_EXLM,     XXXXXXX,      KC_HOME,  KC_PGDOWN, KC_PGUP, KC_END,    KC_RSFT, \
      XXXXXXX,     XXXXXXX,   XXXXXXX,     XXXXXXX,     XXXXXXX,      XXXXXXX,           ADJUST,   KC_BSPC,   KC_DEL,   XXXXXXX,     XXXXXXX,  _______ \
      ),

  [_RAISE] = LAYOUT_preonic_grid( \
      XXXXXXX,    XXXXXXX,  XXXXXXX,XXXXXXX,     XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX, _______, \
      _______,     KC_TAB,    KC_7,  KC_8,   KC_9,              XXXXXXX,            KC_PIPE,        KC_LT,     KC_GT,     KC_LCBR,  KC_RCBR, KC_DEL, \
      _______,      LCTL(KC_TAB),   KC_4,     KC_5,       KC_6,       XXXXXXX,      KC_UNDS,     KC_LPRN,   KC_RPRN,   KC_LBRC,  KC_RBRC, KC_RCTL, \
      _______,       LCTL(LSFT(KC_TAB)),  KC_1,  KC_2, KC_3,                XXXXXXX,             KC_AMPR,        KC_COLN,   KC_SCOLON, KC_QUOTE, KC_DQT,  KC_RSFT, \
      XXXXXXX,        _______, KC_0,      KC_LCTL,   KC_0, ADJUST,           XXXXXXX,        XXXXXXX,  XXXXXXX,   XXXXXXX, KC_RALT,  _______ \
      ),

  [_ADJUST] =  LAYOUT_preonic_grid( \
      RESET,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX,        KC_F1,    KC_F2, KC_F3,KC_F4,KC_F5, KC_F6, KC_F7, KC_F8,KC_F9,KC_F10,XXXXXXX,\
      XXXXXXX,        WIN1, WIN2, WIN3, WIN4, WIN5, WIN6, WIN7, WIN8, WIN9,SGUI(KC_S),  XXXXXXX,\
      XXXXXXX,        KC_CAPS, LGUI(KC_V), LGUI(KC_X), XXXXXXX, KC_F11,   KC_F12, XXXXXXX,XXXXXXX,XXXXXXX, KC_LGUI,  XXXXXXX,\
      XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
      )
};

const uint16_t symbol_en[] = {
  KC_ESC,
  KC_NUBS,
  KC_PERCENT,
  KC_CIRCUMFLEX,
  KC_GRAVE,
  KC_PLUS,
  KC_ASTR,
  KC_SLASH,
  KC_EQUAL,
  KC_TILD,
  KC_HASH,
  KC_DOLLAR,
  KC_QUESTION,
  KC_AT,
  KC_EXLM,
  KC_PIPE,
  KC_LT,
  KC_GT,
  KC_LCBR,
  KC_RCBR,
  KC_UNDS,
  KC_LPRN,
  KC_RPRN,
  KC_AMPR,
  KC_COLN,
  KC_SCOLON,
  KC_QUOTE,
  KC_DQT,
};
const int length_of_symbol_en = sizeof(symbol_en) / sizeof(symbol_en[0]);

void tap_ime_en(void){
  tap_code(KC_F16);
};
void tap_ime_jp(void){
  tap_code(KC_F17);
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  static bool is_ime_en_ready = false, is_ime_jp_ready = false;
  static bool has_win_num_pressed = false;
  static bool has_T_CTL_pressed = false, has_T_SFT_pressed = false;

  switch (keycode) {
    case QED:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QED);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        if(is_ime_en_ready == true){
          tap_ime_en();
        }else{
          is_ime_en_ready = true;
        }
      } else {
        layer_off(_LOWER);
      }
      is_ime_jp_ready = false;
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        if(is_ime_jp_ready == true){
          tap_ime_jp();
        }else{
          is_ime_jp_ready = true;
        }
      } else {
        layer_off(_RAISE);
      }
      is_ime_en_ready = false;
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
          if(has_win_num_pressed == true){
            unregister_code(KC_LWIN);
            has_win_num_pressed = false;
          }
        }
        return false;
        break;

    case WIN1:
    case WIN2:
    case WIN3:
    case WIN4:
    case WIN5:
    case WIN6:
    case WIN7:
    case WIN8:
    case WIN9:
    case WIN0:
      if (record->event.pressed){
        if(has_win_num_pressed == false){
          register_code(KC_LWIN);
        }
        tap_code(keycode - WIN1 + KC_1); // if keycode = WIN2, tap_code(KC_2);
        has_win_num_pressed = true;

        // against win + f16
        is_ime_en_ready = false;
        is_ime_jp_ready = false;
      }
      return false;
      break;

    case T_CTL:
      if(record->event.pressed){
        if(has_T_CTL_pressed == false){
          register_code(KC_LCTL);
          has_T_CTL_pressed = true;
        }
      }
      return false;
      break;
    case T_SFT:
      if(record->event.pressed){
        if(has_T_SFT_pressed == false){
          register_code(KC_LSFT);
          has_T_SFT_pressed = true;
        }
      }
      return false;
      break;

    default:
      if(record->event.pressed){
        is_ime_en_ready = false;
        is_ime_jp_ready = false;
      }

      if(record->event.pressed){
        for(int i=0; i<length_of_symbol_en; i++){
          if(keycode == symbol_en[i]){
            tap_ime_en();
          }
        }
      }

      if(record->event.pressed == true && has_T_CTL_pressed == true){
        register_code(keycode);
        unregister_code(KC_LCTL);
        has_T_CTL_pressed = false;
        return false;
      }else if(record->event.pressed == true && has_T_SFT_pressed == true){
        register_code(keycode);
        unregister_code(KC_LSFT);
        has_T_SFT_pressed = false;
        return false;
      }
  }
  return true;
};
