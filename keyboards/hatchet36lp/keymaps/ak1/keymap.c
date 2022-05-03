/*
Copyright 2019 Sekigon

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
#include "app_ble_func.h"
#include <stdio.h>
#include "keycode.h"
#include "action.h"
#include "quantum.h"

enum custom_keycodes {
    AD_WO_L = SAFE_RANGE, /* Start advertising without whitelist  */
    BLE_DIS,              /* Disable BLE HID sending              */
    BLE_EN,               /* Enable BLE HID sending               */
    USB_DIS,              /* Disable USB HID sending              */
    USB_EN,               /* Enable USB HID sending               */
    DELBNDS,              /* Delete all bonding                   */
    ADV_ID0,              /* Start advertising to PeerID 0        */
    ADV_ID1,              /* Start advertising to PeerID 1        */
    ADV_ID2,              /* Start advertising to PeerID 2        */
    ADV_ID3,              /* Start advertising to PeerID 3        */
    ADV_ID4,              /* Start advertising to PeerID 4        */
    BATT_LV,              /* Display battery level in milli volts */
    DEL_ID0,              /* Delete bonding of PeerID 0           */
    DEL_ID1,              /* Delete bonding of PeerID 1           */
    DEL_ID2,              /* Delete bonding of PeerID 2           */
    DEL_ID3,              /* Delete bonding of PeerID 3           */
    DEL_ID4,              /* Delete bonding of PeerID 4           */
    ENT_DFU,              /* Start bootloader                     */
    ENT_SLP,              /* Deep sleep mode                      */
    LOWER,                /* Layer  keycode                       */
    RAISE,                /* Layer  keycode                       */
    ADJUST,               /* Layer  keycode                       */
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
};

void tap_ime_en(void);
void tap_ime_jp(void);

extern keymap_config_t keymap_config;

enum {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
      KC_Q, KC_L, KC_E, KC_W, KC_COMM, KC_B, KC_M, KC_Y, KC_H, KC_P, \
      KC_A, KC_O, KC_U, KC_I, KC_DOT, KC_G, KC_T, KC_N, KC_R, KC_S, \
      KC_C, KC_V, KC_X, KC_J, KC_ESC, KC_Z, KC_K, KC_F, KC_D, KC_MINS, \
      KC_LSFT, KC_SPACE, LOWER, RAISE, KC_ENT, KC_LCTL \
  ),

  [_LOWER] = LAYOUT(
      KC_NUBS, KC_MINUS, KC_PERCENT, KC_CIRCUMFLEX, KC_GRAVE, XXXXXXX, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_UP), LGUI(KC_RIGHT), \
      KC_PLUS, KC_ASTR, KC_SLASH, KC_EQUAL, KC_TILD, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, \
      KC_HASH, KC_DOLLAR, KC_QUESTION, KC_AT, KC_EXLM, XXXXXXX, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END, \
      XXXXXXX, XXXXXXX, XXXXXXX, ADJUST, KC_BSPC, KC_LGUI \
  ),

  [_RAISE] = LAYOUT(
      KC_TAB, KC_7, KC_8, KC_9, KC_COMMA, KC_PIPE, KC_LT, KC_GT, KC_LCBR, KC_RCBR, \
      LCTL(KC_TAB), KC_4, KC_5, KC_6, KC_DOT, KC_UNDS, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, \
      LCTL(LSFT(KC_TAB)), KC_1, KC_2, KC_3, KC_0, KC_AMPR, KC_COLN, KC_SCOLON, KC_QUOTE, KC_DQT, \
      KC_LALT, KC_SPACE, ADJUST, XXXXXXX, XXXXXXX, XXXXXXX \
  ),

  [_ADJUST] = LAYOUT ( \
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, \
    WIN1, WIN2, WIN3, WIN4, WIN5, AD_WO_L, ADV_ID1, ADV_ID2, ADV_ID3, ADV_ID4,\
    BATT_LV, ENT_SLP, ENT_DFU, RESET, KC_F11, KC_F12, DEL_ID1, DEL_ID2, DEL_ID3, DEL_ID4,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DELBNDS \
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

void tap_code(uint16_t keycode){
  register_code(keycode);
  unregister_code(keycode);
}

void tap_ime_en(void){
  tap_code(KC_F16);
};

void tap_ime_jp(void){
  tap_code(KC_F17);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  static bool is_ime_en_ready = false, is_ime_jp_ready = false;
  static bool has_win_num_pressed = false;
  char str[16];

  switch (keycode) {
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
  }
  if (record->event.pressed) {
    switch (keycode) {
    case DELBNDS:
      delete_bonds();
      return false;
    case AD_WO_L:
      restart_advertising_wo_whitelist();
      return false;
    case USB_EN:
      set_usb_enabled(true);
      return false;
      break;
    case USB_DIS:
      set_usb_enabled(false);
      return false;
      break;
    case BLE_EN:
      set_ble_enabled(true);
      return false;
      break;
    case BLE_DIS:
      set_ble_enabled(false);
      return false;
      break;
    case ADV_ID0:
      restart_advertising_id(0);
      return false;
    case ADV_ID1:
      restart_advertising_id(1);
      return false;
    case ADV_ID2:
      restart_advertising_id(2);
      return false;
    case ADV_ID3:
      restart_advertising_id(3);
      return false;
    case ADV_ID4:
      restart_advertising_id(4);
      return false;
    case DEL_ID0:
      delete_bond_id(0);
      return false;
    case DEL_ID1:
      delete_bond_id(1);
      return false;
    case DEL_ID2:
      delete_bond_id(2);
      return false;
    case DEL_ID3:
      delete_bond_id(3);
      return false;
    case BATT_LV:
      sprintf(str, "%4dmV", get_vcc());
      send_string(str);
      return false;
    case ENT_DFU:
      bootloader_jump();
      return false;
    }
  } else if (!record->event.pressed) {
    switch (keycode) {
    case ENT_SLP:
      sleep_mode_enter();
      return false;
    }

  } else if (record->event.pressed) {
      // ime
      is_ime_en_ready = false;
      is_ime_jp_ready = false;

      // for symbol ime en
      for (int i = 0; i < length_of_symbol_en; i++) {
          if (keycode == symbol_en[i]) {
              tap_ime_en();
          }
      }
  }
  return true;
}
