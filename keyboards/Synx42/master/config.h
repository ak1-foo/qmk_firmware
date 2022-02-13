#pragma once

#include "../board/custom_board.h"

#define THIS_DEVICE_ROWS 1
#define THIS_DEVICE_COLS 21

#define ENABLE_STARTUP_ADV_NOLIST

#define MATRIX_ROW_PINS { 0 }
#define MATRIX_COL_PINS { 16, 11, 6,  3,  15, 31, \
						  18, 12, 7,  4,  13, 19, \
						  20, 14, 8,  5,  2,  17, \
									  28, 27, 26}

#define IS_LEFT_HAND  true
//#define USE_AS_I2C_SLAVE
