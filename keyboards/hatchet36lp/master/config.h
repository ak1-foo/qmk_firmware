#pragma once

#include "../board/custom_board.h"

#define THIS_DEVICE_ROWS 4
#define THIS_DEVICE_COLS 10

#define ENABLE_STARTUP_ADV_NOLIST

#define MATRIX_ROW_PINS { 29, 30, 17, 20 }
#define MATRIX_COL_PINS { 31, 3, 5, 6, 7, 8, 12, 14, 16, 18}

#define IS_LEFT_HAND  true
//#define USE_AS_I2C_SLAVE
