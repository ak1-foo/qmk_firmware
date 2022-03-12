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

#pragma once

#include "quantum.h"
#include "keycode.h"
#include QMK_KEYBOARD_H

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
bool process_record_user(uint16_t keycode, keyrecord_t *record);
void tap_ime_en(void);
void tap_ime_jp(void);
void persistent_default_layer_set(uint16_t default_layer);

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

  NEW_SAFE_RANGE,
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
