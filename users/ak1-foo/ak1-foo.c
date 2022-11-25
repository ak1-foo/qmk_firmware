// Copyright 2022 ak1-foo
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "ak1-foo.h"
#include "action.h"
#include "quantum.h"
#include "trackball_module.h"

const uint16_t symbol_en[] = {
  KC_ESC,
  KC_BSLS,
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

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record){
    return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  static bool has_win_num_pressed = false;

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
        cocot_set_scroll_mode(true);
      } else {
        layer_off(_LOWER);
        cocot_set_scroll_mode(false);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
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
      }
      return false;
      break;

    default:
      if(record->event.pressed){
        // for symbol ime en
        for(int i=0; i<length_of_symbol_en; i++){
          if(keycode == symbol_en[i]){
            tap_code(KC_LNG2);
          }
        }
      }
  }
  return process_record_keymap(keycode, record);
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
};
