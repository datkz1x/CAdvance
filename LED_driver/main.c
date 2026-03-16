#include <stdio.h>
#include <stdint.h>
#include "led_driver.h"

int main() {
    printf("Test\n\n");
    //1
    if (!led_init(10)) {
        return 1;
    }
    printf("LED init success\n");
    const uint32_t* buffer = led_get_buffer();
    size_t count = led_get_pixel_count();
    //2
    printf("Check init value\n");
    for (size_t i = 0; i < count; i++) {
        printf("LED %ld %x\n", i, buffer[i]);
    }
    //3
    led_set_pixel_color(0, 255, 0, 0);
    //4
    led_set_pixel_color(9, 0, 0, 255);
    //5
    led_set_pixel_color(4, 255, 255, 255);
    //7
    printf("LED 0 %x\n", buffer[0]);
    printf("LED 4 %x\n", buffer[4]);
    printf("LED 9 %x\n", buffer[9]);
    //8
    printf("Check led fill\n");
    led_fill(0, 255, 0);
    for (size_t i = 0; i < count; i++) {
        printf("LED %ld %x\n", i, buffer[i]);
    }

    led_shutdown();


    return 0;
}