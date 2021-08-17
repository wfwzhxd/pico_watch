#ifndef __INPUT_DRV_H
#define __INPUT_DRV_H

#include "pico/stdlib.h"
#include "lvgl/lvgl.h"
#include "util.h"
#include <stdio.h>

#define INPUT_DEBUG     0
#define USE_MOUSE 0      // 1 FOR MOUSE, 0 FOR ENCODER

#if USE_MOUSE
#define USE_ENCODER 0
#else
#define USE_ENCODER 1
#endif


#define PIN_KEY_UP      2
#define PIN_KEY_DOWN    18
#define PIN_KEY_LEFT    16
#define PIN_KEY_RIGHT   20
#define PIN_KEY_ENTER   3

#define PIN_KEY_A       15
#define PIN_KEY_B       17

typedef struct {
    const uint8_t gpio_num;    // gpio number on harware board
    const uint8_t key_code;    // key_code send to lvgl
} input_key_t;

typedef struct {
    void (*regist)(); // register
    int (*scan)();     // scan
} input_driver_t;

#define IS_KEY_PRESSED(k) (!gpio_get(k))

void input_start();

void input_key_init(const input_key_t* keys, const int length);

#endif