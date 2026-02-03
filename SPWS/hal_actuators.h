#ifndef HAL_ACTUATORS_H
#define HAL_ACTUATORS_H


#include "config.h"

extern PumpState_t g_pumpState;

void HAL_TurnPumpOn(void);
void HAL_TurnPumpOff(void);
void HAL_SetLed(LedState_t led);


#endif