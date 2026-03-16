#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

int led_init(size_t num_pixel);

int led_shutdown();

void led_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b);

void led_fill(uint8_t r, uint8_t g, uint8_t b);

void led_clear();

const uint32_t* led_get_buffer();

size_t led_get_pixel_count();

#endif