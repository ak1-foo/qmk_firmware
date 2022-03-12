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


__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record){
    return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  static bool is_ime_en_ready = false, is_ime_jp_ready = false;
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

    default:
      // KC_ESC clear all one shotrmod and layer
      if (keycode == KC_ESC && record->event.pressed) {
        bool rc = true;
        uint8_t mods = 0;
        if ((mods = get_oneshot_mods()) && !has_oneshot_mods_timed_out()) {
            clear_oneshot_mods();
            unregister_mods(mods);
            rc = false;
        }
        if ((mods = get_oneshot_locked_mods())) {
            clear_oneshot_locked_mods();
            unregister_mods(mods);
            rc = false;
        }
        if (is_oneshot_layer_active()) {
            layer_clear();
            rc = false;
        }
        return rc;
      }

      if(record->event.pressed){
        // ime
        is_ime_en_ready = false;
        is_ime_jp_ready = false;

        // for symbol ime en
        for(int i=0; i<length_of_symbol_en; i++){
          if(keycode == symbol_en[i]){
            tap_ime_en();
          }
        }
      }
  }
  return process_record_keymap(keycode, record);
};

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
