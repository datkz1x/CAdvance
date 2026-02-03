#include "hal_actuators.h"
#include <stdio.h>


void HAL_TurnPumpOn(void){
    g_pumpState = PUMP_ON;
    printf("Pump On\n");
}

void HAL_TurnPumpOff(void){
    g_pumpState = PUMP_OFF;
    printf("Pump Off\n");
}

void HAL_SetLed(LedState_t led){
    switch (led){
        case LED_NORMAL: printf("Normal\n"); break;
        case LED_WATERING: printf("Watering\n"); break;
        case LED_LOW_MOISTURE_ALERT: printf("Low Moisture Alert\n"); break;
        case LED_ERROR: printf("Error\n"); break;
    }
}