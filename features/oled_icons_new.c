// Copyright 2022 @filterpaper
// SPDX-License-Identifier: GPL-2.0+

/* Graphical active layer and modifier status display.
   Modified from @soundmonster's keymap:
   (keyboards/crkbd/keymaps/soundmonster)

   Usage guide
   1 Place this file next to keymap.c or in userspace.
   2 Add the following lines into rules.mk:
        OLED_ENABLE = yes
        SRC += oled_icons_new.c
   3 Add the following lines into the main 'oled_task_user()'
     function to render this module:
        extern void render_mod_status(void);
        render_mod_status();
   4 Add the font file reference into `config.h`:
        #define OLED_FONT_H "oledfont.c"
*/

#include "oled_driver.h"
#include <stdint.h>
#include QMK_KEYBOARD_H

#define ANIMATION_FRAME_DURATION 200 // milliseconds
#define RUN_INTERVAL ANIMATION_FRAME_DURATION * 4
#define WALK_INTERVAL ANIMATION_FRAME_DURATION * 8

#define RENDER_SIZE 35
#define RENDER_TOTAL_PIXELS (RENDER_SIZE * RENDER_SIZE)
// scale based on 255, it affects the density of the rain
#define CURRENT_SCALE_DOWN 185

#define RAIN_PROBABILITY_DISTRIBUTION_SMALL 3   // there is a 1/3 chance of rain dot pixel
#define RAIN_PROBABILITY_DISTRIBUTION_MEDIUM 7
#define RAIN_PROBABILITY_DISTRIBUTION_LARGE 11
#define RAIN_SPEED_SLOW RAIN_PROBABILITY_DISTRIBUTION_LARGE
#define RAIN_SPEED_NORMAL RAIN_PROBABILITY_DISTRIBUTION_MEDIUM
#define RAIN_SPEED_FAST RAIN_PROBABILITY_DISTRIBUTION_SMALL

#define APPLE_LOGO_DELTA_FAST 3
#define APPLE_LOGO_DELTA_NORMAL 2
#define APPLE_LOGO_DELTA_SLOW 1
#define APPLE_LOGO_ON_DURATION (3000 / ANIMATION_FRAME_DURATION) // 3 seconds
#define APPLE_LOGO_OFF_DURATION (1000 / ANIMATION_FRAME_DURATION) // 1 second

// Draw hacker with laptop logo
static int8_t render_apple_logo_count = 6;
static uint8_t apple_logo_duration_count = 0;
static void render_my_logo(uint8_t const speed) {
  static const char PROGMEM raw_logo_apple[] = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x0c,
      0x02, 0x82, 0x81, 0x81, 0x81, 0x81, 0x81, 0x82, 0x04, 0x08, 0xf0, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0xfe, 0xcf, 0x1f, 0x0f, 0x0f,
      0x0f, 0x07, 0x03, 0x8f, 0xef, 0xfe, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0, 0xe8, 0xe4, 0x22,
      0x22, 0x21, 0x21, 0x20, 0x20, 0x23, 0x2e, 0x3e, 0xbe, 0xfe, 0x66, 0x21,
      0x20, 0x20, 0x21, 0x21, 0x22, 0x24, 0xc8, 0xd0, 0xe0, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0xff, 0x03, 0x03, 0x78, 0x00, 0x00, 0x00, 0x3c,
      0x7e, 0xff, 0xff, 0xff, 0x7e, 0xfe, 0xff, 0xff, 0x73, 0x22, 0x00, 0x00,
      0xc0, 0x1f, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x01, 0x01, 0x01, 0x01, 0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x06, 0x06,
      0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x07, 0x01, 0x01, 0x01,
      0x00, 0x00, 0x00, 0x00};
  static const char PROGMEM raw_logo[] = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x0c,
      0x02, 0x82, 0x81, 0x81, 0x81, 0x81, 0x81, 0x82, 0x04, 0x08, 0xf0, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0xfe, 0xcf, 0x1f, 0x0f, 0x0f,
      0x0f, 0x07, 0x03, 0x8f, 0xef, 0xfe, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0, 0xe8, 0xe4, 0x22,
      0x22, 0x21, 0x21, 0x20, 0x20, 0x23, 0x2e, 0x3e, 0x3e, 0x3e, 0x26, 0x21,
      0x20, 0x20, 0x21, 0x21, 0x22, 0x24, 0xc8, 0xd0, 0xe0, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0xff, 0x03, 0x03, 0x78, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0xc0, 0x1f, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x01, 0x01, 0x01, 0x01, 0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x07, 0x07,
      0x07, 0x07, 0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x07, 0x01, 0x01, 0x01,
      0x00, 0x00, 0x00, 0x00};
  render_apple_logo_count = render_apple_logo_count - speed;
  if (render_apple_logo_count <= 0) {
    oled_write_raw_P(raw_logo_apple, sizeof(raw_logo_apple));
    apple_logo_duration_count++;
    if (apple_logo_duration_count >= APPLE_LOGO_ON_DURATION) {
      render_apple_logo_count = 6;
      apple_logo_duration_count = 0;
    }
  } else {
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
    apple_logo_duration_count++;
    if (apple_logo_duration_count >= APPLE_LOGO_OFF_DURATION) {
      render_apple_logo_count = 0;
    }
  }
}

uint8_t l[RENDER_TOTAL_PIXELS];
uint8_t b[RENDER_TOTAL_PIXELS];
int i;

static long random_max(long howbig) {
  if (howbig == 0) {
    return 0;
  }
  return random() % howbig;
}

static void scale_down(uint8_t *array, uint size, uint8_t scale_max) {
  uint i;
  for (i = 0; i < size; i++) {
    array[i] = array[i] * scale_max / 255;
  }
}

static void render_digital_rain(void) {
  uint rows, cols;
  for (rows = 0; rows < RENDER_SIZE; rows++) {
    for (cols = 0; cols < RENDER_SIZE; cols++) {
      if (rows >= 21) {
        if (cols >= 5 && cols <= 29)
          continue;
      } else if (rows > 16) {
        if (cols >= 5 && cols <= 29)
          continue;
      } else if (rows >= 3) {
        if (cols >= 9 && cols <= 22)
          continue;
      }
      if (l[rows * RENDER_SIZE + cols] > 0x30) {
        oled_write_pixel(cols, rows, true);
      } else {
        oled_write_pixel(cols, rows, false);
      }
    }
  }
}

static void digital_rain_action(uint8_t speed, uint8_t const apple_logo_speed) {
  i = RENDER_SIZE;
  while (i--)
    // Faster raining speed
    // b[i] = !random(3) ? random(2) : 0;
    // Normal raining speed
    b[i] = !random_max(speed) ? random_max(2) : 0;
  memmove(b + RENDER_SIZE, b, RENDER_TOTAL_PIXELS - RENDER_SIZE);
  while (++i < RENDER_TOTAL_PIXELS)
    if (b[i])
      l[i] = ~0;
  // Scale all LEDs' brightness (each RGB values of each pixel) to under 200
  scale_down(l, RENDER_TOTAL_PIXELS, CURRENT_SCALE_DOWN);

  oled_set_cursor(0, 0);
  render_my_logo(apple_logo_speed);
  oled_set_cursor(0, 1);
  render_digital_rain();
}

static void animate_digital_rain(uint32_t interval) {
  uint8_t const mods = get_mods();
  bool const caps = host_keyboard_led_state().caps_lock;

  if (mods & MOD_MASK_SHIFT || caps)
    digital_rain_action(RAIN_SPEED_NORMAL, APPLE_LOGO_DELTA_NORMAL);

  if (mods & MOD_MASK_CAG)
    digital_rain_action(RAIN_SPEED_SLOW, APPLE_LOGO_DELTA_SLOW);
  else if (interval < RUN_INTERVAL)
    digital_rain_action(RAIN_SPEED_FAST, APPLE_LOGO_DELTA_FAST);
  else if (interval < WALK_INTERVAL)
    digital_rain_action(RAIN_SPEED_NORMAL, APPLE_LOGO_DELTA_NORMAL);
  else
    digital_rain_action(RAIN_SPEED_SLOW, APPLE_LOGO_DELTA_SLOW);
}

static void render_digital_rain_status(void) {
  static uint16_t frame_timer = 0;
  uint32_t const input_timer = last_matrix_activity_time();

  if (timer_elapsed32(input_timer) > OLED_TIMEOUT) {
    oled_off();
  } else if (timer_elapsed(frame_timer) > ANIMATION_FRAME_DURATION) {
    frame_timer = timer_read();
    animate_digital_rain(timer_elapsed32(input_timer));
  }
}

static void render_wpm(void) {
  oled_set_cursor(0, 5);
  oled_write_ln(get_u8_str(get_current_wpm(), ' '), false);
}

void render_logo(void) {
  // oled_write_raw_P(glasses_boy, GLASSES_BOY_SIZE);
  // render_my_logo();
  render_digital_rain_status();
  render_wpm();

  oled_set_cursor(0, 10);
  switch (get_highest_layer(layer_state)) {
  case BSE:
    oled_write_ln_P(PSTR("BASE"), false);
    break;
  case NUM:
    oled_write_ln_P(PSTR("NUMB"), false);
    break;
  case MOU:
    oled_write_ln_P(PSTR("MOUS"), false);
    break;
  case FNC:
    oled_write_ln_P(PSTR("FUNC"), false);
    break;
  case SYS:
    oled_write_ln_P(PSTR("SYS"), false);
    break;
  default:
    oled_write_ln_P(PSTR("CORNE"), false);
  }
}

static void render_layer_state(uint8_t const state) {
  static char const second_layer[] PROGMEM = {
      0x20, 0x9a, 0x9b, 0x9c, 0x20, 0x20, 0xba, 0xbb,
      0xbc, 0x20, 0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
  static char const third_layer[] PROGMEM = {0x20, 0x94, 0x95, 0x96, 0x20, 0x20,
                                             0xb4, 0xb5, 0xb6, 0x20, 0x20, 0xd4,
                                             0xd5, 0xd6, 0x20, 0};
  static char const top_layer[] PROGMEM = {0x20, 0x97, 0x98, 0x99, 0x20, 0x20,
                                           0xb7, 0xb8, 0xb9, 0x20, 0x20, 0xd7,
                                           0xd8, 0xd9, 0x20, 0};
  static char const all_layer[] PROGMEM = {0x20, 0x9d, 0x9e, 0x9f, 0x20, 0x20,
                                           0xbd, 0xbe, 0xbf, 0x20, 0x20, 0xdd,
                                           0xde, 0xdf, 0x20, 0};
  static char const bottom_layer[] PROGMEM = {
      0x20, 0x3d, 0x3e, 0x3f, 0x20, 0x20, 0x5d, 0x5e,
      0x5f, 0x20, 0x20, 0x7d, 0x7e, 0x7f, 0x20, 0};

  if (state == 2)
    oled_write_P(third_layer, false);
  else if (state == 3)
    oled_write_P(top_layer, false);
  else if (state == 4)
    oled_write_P(all_layer, false);
  else if (state == 1)
    oled_write_P(second_layer, false);
  else
    oled_write_P(bottom_layer, false);
}

static void render_gui_alt(uint8_t const gui, uint8_t const alt) {
  static char const gui_off_1[] PROGMEM = {0x85, 0x86, 0};
  static char const gui_off_2[] PROGMEM = {0xa5, 0xa6, 0};
  static char const gui_on_1[] PROGMEM = {0x8d, 0x8e, 0};
  static char const gui_on_2[] PROGMEM = {0xad, 0xae, 0};

  static char const alt_off_1[] PROGMEM = {0x87, 0x88, 0};
  static char const alt_off_2[] PROGMEM = {0xa7, 0xa8, 0};
  static char const alt_on_1[] PROGMEM = {0x8f, 0x90, 0};
  static char const alt_on_2[] PROGMEM = {0xaf, 0xb0, 0};

  // Fillers between icon frames
  static char const off_off_1[] PROGMEM = {0xc5, 0};
  static char const off_off_2[] PROGMEM = {0xc6, 0};
  static char const on_off_1[] PROGMEM = {0xc7, 0};
  static char const on_off_2[] PROGMEM = {0xc8, 0};
  static char const off_on_1[] PROGMEM = {0xc9, 0};
  static char const off_on_2[] PROGMEM = {0xca, 0};
  static char const on_on_1[] PROGMEM = {0xcb, 0};
  static char const on_on_2[] PROGMEM = {0xcc, 0};

  // Top half with in between fillers
  oled_write_P(gui ? gui_on_1 : gui_off_1, false);
  if (gui && alt)
    oled_write_P(on_on_1, false);
  else if (gui)
    oled_write_P(on_off_1, false);
  else if (alt)
    oled_write_P(off_on_1, false);
  else
    oled_write_P(off_off_1, false);
  oled_write_P(alt ? alt_on_1 : alt_off_1, false);

  // Bottom half with in between fillers
  oled_write_P(gui ? gui_on_2 : gui_off_2, false);
  if (gui && alt)
    oled_write_P(on_on_2, false);
  else if (gui)
    oled_write_P(on_off_2, false);
  else if (alt)
    oled_write_P(off_on_2, false);
  else
    oled_write_P(off_off_2, false);
  oled_write_P(alt ? alt_on_2 : alt_off_2, false);
}

static void render_ctrl_shift(uint8_t const ctrl, uint8_t const shift) {
  uprintf("render_ctrl_shift, ctrl=%d, shift=%d\n", ctrl, shift);
  static char const ctrl_off_1[] PROGMEM = {0x89, 0x8a, 0};
  static char const ctrl_off_2[] PROGMEM = {0xa9, 0xaa, 0};
  static char const ctrl_on_1[] PROGMEM = {0x91, 0x92, 0};
  static char const ctrl_on_2[] PROGMEM = {0xb1, 0xb2, 0};

  static char const shift_off_1[] PROGMEM = {0x8b, 0x8c, 0};
  static char const shift_off_2[] PROGMEM = {0xab, 0xac, 0};
  static char const shift_on_1[] PROGMEM = {0xcd, 0xce, 0};
  static char const shift_on_2[] PROGMEM = {0xcf, 0xd0, 0};

  // Fillers between icon frames
  static char const off_off_1[] PROGMEM = {0xc5, 0};
  static char const off_off_2[] PROGMEM = {0xc6, 0};
  static char const on_off_1[] PROGMEM = {0xc7, 0};
  static char const on_off_2[] PROGMEM = {0xc8, 0};
  static char const off_on_1[] PROGMEM = {0xc9, 0};
  static char const off_on_2[] PROGMEM = {0xca, 0};
  static char const on_on_1[] PROGMEM = {0xcb, 0};
  static char const on_on_2[] PROGMEM = {0xcc, 0};

  // Top half with in between fillers
  oled_write_P(ctrl ? ctrl_on_1 : ctrl_off_1, false);
  if (ctrl && shift)
    oled_write_P(on_on_1, false);
  else if (ctrl)
    oled_write_P(on_off_1, false);
  else if (shift)
    oled_write_P(off_on_1, false);
  else
    oled_write_P(off_off_1, false);
  oled_write_P(shift ? shift_on_1 : shift_off_1, false);

  // Bottom half with in between fillers
  oled_write_P(ctrl ? ctrl_on_2 : ctrl_off_2, false);
  if (ctrl && shift)
    oled_write_P(on_on_2, false);
  else if (ctrl)
    oled_write_P(on_off_2, false);
  else if (shift)
    oled_write_P(off_on_2, false);
  else
    oled_write_P(off_off_2, false);
  oled_write_P(shift ? shift_on_2 : shift_off_2, false);
}

// Primary modifier status display function
void render_mod_status(void) {
  uint8_t const mods = get_mods();

  render_logo();
  oled_set_cursor(0, 6);
  render_layer_state(get_highest_layer(layer_state | default_layer_state));

  oled_set_cursor(0, 12);
  render_gui_alt(mods & MOD_MASK_GUI, mods & MOD_MASK_ALT);
  render_ctrl_shift(mods & MOD_MASK_CTRL,
                    mods & MOD_MASK_SHIFT ||
                        host_keyboard_led_state().caps_lock);
}
