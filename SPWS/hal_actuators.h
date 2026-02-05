#ifndef HAL_ACTUATORS_H
#define HAL_ACTUATORS_H


#include "config.h"

extern SystemState_t g_systemState;

void HAL_TurnPumpOn(void);
void HAL_TurnPumpOff(void);
void HAL_SetLed(void);


#endif