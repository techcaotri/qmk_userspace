// Copyright @filterpaper
// SPDX-License-Identifier: GPL-2.0+

#pragma once

// Common QMK settings
#define USB_SUSPEND_WAKEUP_DELAY 2000
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1500U
// Space saving options
#define LAYER_STATE_8BIT
#define NO_ACTION_ONESHOT

// Tap-hold settings
#define INPUT_INTERVAL TAPPING_TERM

// from jbarr21_qmk_userspace
#undef TAPPING_TERM
#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY

#define ACHORDION_ENABLE



#ifdef SPLIT_KEYBOARD
#   define EE_HANDS
#endif

#ifdef COMBO_ENABLE
#   define COMBO_TERM 45
#   define EXTRA_SHORT_COMBOS
#   define COMBO_SHOULD_TRIGGER
// #   define COMBO_ONLY_FROM_LAYER 0
#endif

#ifdef MOUSEKEY_ENABLE
//#   define MK_KINETIC_SPEED
#   define MOUSEKEY_DELAY               0 // Delay between pressing a key and cursor movement
#   define MOUSEKEY_INTERVAL           16 // Time between cursor movements in milliseconds
#   if defined (MK_KINETIC_SPEED)
#       define MOUSEKEY_MOVE_DELTA     25
#       define MOUSEKEY_INITIAL_SPEED 200
#       define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 4
#   else // Default accelerated
#       define MOUSEKEY_MAX_SPEED      10
#       define MOUSEKEY_MOVE_DELTA     10 // Step size for acceleration
#       define MOUSEKEY_TIME_TO_MAX    80
#   endif
#   define MOUSEKEY_WHEEL_DELAY        16
#   define MOUSEKEY_WHEEL_INTERVAL     30
#   define MOUSEKEY_WHEEL_MAX_SPEED    10
#   define MOUSEKEY_WHEEL_TIME_TO_MAX  95
#endif

#ifdef OLED_ENABLE
#   define OLED_TIMEOUT 10000
#   define OLED_BRIGHTNESS 180
#   define OLED_FONT_H "oled_font.c"
#endif

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES
#   define ENABLE_RGB_MATRIX_CANDY_TAP
#   define ENABLE_RGB_MATRIX_CANDY_RAIN
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CUSTOM_CANDY_TAP
#   define DEF_MODE RGB_MATRIX_DEFAULT_MODE
#   define CMK_MODE RGB_MATRIX_CUSTOM_CANDY_RAIN
#endif

// TriPham: press both shift to enable caps word
#define CAPS_WORD_INVERT_ON_SHIFT

// Start of idank 'config.h'
#undef MASTER_LEFT
// #undef EE_HANDS
#undef MASTER_RIGHT

#define SERIAL_USART_TX_PIN GP1

#ifdef POINTING_DEVICE_POSITION_LEFT
#define MASTER_LEFT
#else
#define MASTER_RIGHT
#endif

#ifdef POINTING_DEVICE_CONFIGURATION_PIMORONI_CIRQUE35
    // The pimoroni needs frequest updates, set a value so the Cirque configs don't set it to 10ms.
    #define POINTING_DEVICE_TASK_THROTTLE_MS 1
    // A pimoroni on the left side can only go in this orientation.
    #define POINTING_DEVICE_ROTATION_270
#endif

#ifdef POINTING_DEVICE_CONFIGURATION_CIRQUE35_PIMORONI
    // The pimoroni needs frequest updates, set a value so the Cirque configs don't set it to 10ms.
    #define POINTING_DEVICE_TASK_THROTTLE_MS 1
    // Determine right side rotation based on POINTING_DEVICE_POSITION flag.
#   if POINTING_DEVICE_POSITION_THUMB_OUTER
      #define POINTING_DEVICE_ROTATION_270_RIGHT
#   elif defined(POINTING_DEVICE_POSITION_THUMB) || defined(POINTING_DEVICE_POSITION_THUMB_INNER)
#   else
       #define POINTING_DEVICE_ROTATION_90_RIGHT
#   endif
#endif

// Configuration for dual trackballs.
#ifdef POINTING_DEVICE_CONFIGURATION_PIMORONI_PIMORONI
    // A pimoroni on the left side can only go in this orientation.
    #define POINTING_DEVICE_ROTATION_270
    // Determine right side rotation based on POINTING_DEVICE_POSITION flag.
#   if POINTING_DEVICE_POSITION_THUMB_OUTER
      #define POINTING_DEVICE_ROTATION_270_RIGHT
#   elif defined(POINTING_DEVICE_POSITION_THUMB) || defined(POINTING_DEVICE_POSITION_THUMB_INNER)
#   else
       #define POINTING_DEVICE_ROTATION_90_RIGHT
#   endif
#endif

// Generic Cirque configuration.
#ifdef POINTING_DEVICE_DRIVER_cirque_pinnacle_i2c
#define CIRQUE_PINNACLE_DIAMETER_MM 35
// Tap for left click.
#define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#endif

// Configuration for single trackball.
#ifdef POINTING_DEVICE_CONFIGURATION_PIMORONI
#   ifdef POINTING_DEVICE_POSITION_LEFT
      #define POINTING_DEVICE_ROTATION_270
#   elif POINTING_DEVICE_POSITION_RIGHT
       #define POINTING_DEVICE_ROTATION_90
#   elif POINTING_DEVICE_POSITION_THUMB_OUTER
      #define POINTING_DEVICE_ROTATION_270
#   elif defined(POINTING_DEVICE_POSITION_THUMB) || defined(POINTING_DEVICE_POSITION_THUMB_INNER) || defined(POINTING_DEVICE_POSITION_MIDDLE)
#   endif
#endif

#ifdef POINTING_DEVICE_CONFIGURATION_TRACKPOINT
    // The default streaming mode is flaky and doesn't always work. This setting doesn't seem to affect performance.
    #define PS2_MOUSE_USE_REMOTE_MODE

    // Serial uses PIO0, change PS2 to PIO1.
    #define PS2_PIO_USE_PIO1

    #define PS2_MOUSE_INVERT_X
    #define PS2_MOUSE_INVERT_Y

    #define PS2_DATA_PIN    GP2
    #define PS2_CLOCK_PIN   GP3

    // Start faster when keyboard resets.
    #define PS2_MOUSE_INIT_DELAY 500
#endif

#ifdef OLED_ENABLE
    #define SPLIT_ACTIVITY_ENABLE
    #define SPLIT_WPM_ENABLE
    #define SPLIT_MODS_ENABLE
    #define SPLIT_LED_STATE_ENABLE
    #define SPLIT_LAYER_STATE_ENABLE
#endif

// Layout macros
#ifndef __ASSEMBLER__
#   include "layout.h"
#endif
