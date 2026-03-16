#include "led_driver.h"

static uint32_t* p_led_buffer = NULL;
static size_t g_num_pixel = 0;

int led_init(size_t num_pixel){
    p_led_buffer = (uint32_t*)malloc(num_pixel*sizeof(uint32_t));
    g_num_pixel = num_pixel;

    if(p_led_buffer == NULL){
        printf("No memory left");
        return 0;
    }

    for (size_t i = 0; i < num_pixel; i++) {
        p_led_buffer[i] = 0;
    }

    return 1;
}

int led_shutdown(){
    if (p_led_buffer != NULL) {
        free(p_led_buffer);
        p_led_buffer = NULL;
        g_num_pixel = 0;
        return 1;
    }
    return 0;
}

void led_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b){
    if (index >= g_num_pixel || p_led_buffer == NULL) return;
    p_led_buffer[index] = ((uint32_t)g << 16) | ((uint32_t)r << 8) | b;
}

void led_fill(uint8_t r, uint8_t g, uint8_t b){
    if(p_led_buffer == NULL) return;
    for(size_t i = 0; i < g_num_pixel; i++){
        led_set_pixel_color(i, r, g, b);
    }
}

void led_clear(){
    if (p_led_buffer == NULL) return;

    for (size_t i = 0; i < g_num_pixel; i++) {
        p_led_buffer[i] = 0;
    }
}

const uint32_t* led_get_buffer() {
    return p_led_buffer;
}

size_t led_get_pixel_count(){
    return g_num_pixel;
}