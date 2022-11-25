#pragma once

#include "config_common.h"

#ifdef POINTING_DEVICE_ENABLE
    #define ADNS5050_SDIO_PIN B5
    #define ADNS5050_SCLK_PIN B4
    #define ADNS5050_CS_PIN   B3
    #define COCOT_ROTATION_ANGLE { 15 }
    #define COCOT_ROTATION_DEFAULT 0
    #define COCOT_CPI_OPTIONS { 1000 }
    #define COCOT_CPI_DEFAULT 0
#endif

#define USB_POLLING_INTERVAL_MS 1
#define POINTING_DEVICE_ROTATION_180
#define MOUSEKEY_DELAY 0
