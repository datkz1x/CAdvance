#ifndef HAL_BUTTONS_H
#define HAL_BUTTONS_H


#include <stdbool.h>
#include <config.h>


bool HAL_IsButton1Pressed(void); // Auto <-> Manual
bool HAL_IsButton2Pressed(void); // Turn on Pump when in Manual Mode


#endif