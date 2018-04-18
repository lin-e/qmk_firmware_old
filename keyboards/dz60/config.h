#ifndef CONFIG_H
    #define CONFIG_H

    #include "config_common.h"

    #define VENDOR_ID 0xFEED
    #define PRODUCT_ID 0x6060
    #define DEVICE_VER 0x0001
    #define MANUFACTURER lin-e
    #define PRODUCT DZ60
    #define DESCRIPTION DZ60 ISO [2.75 | 1.25 | 2.25]

    #define MATRIX_ROWS 5
    #define MATRIX_COLS 15
    #define MATRIX_ROW_PINS { D0, D1, D2, D3, D5 }
    #define MATRIX_COL_PINS { F0, F1, E6, C7, C6, B7, D4, B1, B0, B5, B4, D7, D6, B3, F4 }
    #define UNUSED_PINS

    #define DIODE_DIRECTION COL2ROW

    #define BACKLIGHT_PIN B6
    #define BACKLIGHT_LEVELS 5

    #define DEBOUNCING_DELAY 5
    #define LOCKING_SUPPORT_ENABLE
    #define LOCKING_RESYNC_ENABLE

    #define IS_COMMAND() ( \
        keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
    )

    #define PREVENT_STUCK_MODIFIERS

    #define RGB_DI_PIN E2
    #define RGBLIGHT_ANIMATIONS
    #define RGBLED_NUM 16
    #define RGBLIGHT_HUE_STEP 4
    #define RGBLIGHT_SAT_STEP 4
    #define RGBLIGHT_VAL_STEP 4

    #define MOUSEKEY_INTERVAL 10
    #define MOUSEKEY_MAX_SPEED 1
    #define MOUSEKEY_TIME_TO_MAX 40

    #define DISABLE_SPACE_CADET_ROLLOVER

    #define DYNAMIC_MACRO_SIZE 256 // don't change this.

#endif
