#include "spws_controller.h"
#include "hal_actuators.h"
#include <stdio.h>

static uint16_t wateringTime = 0;

void SPWS_RunAutoMode(void){
    //Moisture
    if(g_sensorData.soilMoisturePercent < g_systemSetting.minMoistureThreshold){
        if(g_pumpState = PUMP_OFF){
            HAL_TurnPumpOn();
            g_ledState = LED_WATERING;
            wateringTime = 0;
        }
        
    }
    //
    if(g_pumpState = PUMP_ON){

        wateringTime++;

        if(g_sensorData.soilMoisturePercent > g_systemSetting.maxMoistureThreshold || wateringTime > g_settings.maxWateringDuration_s){
            HAL_TurnPumpOff();
            g_ledState = LED_NORMAL;

        }
    }
}

void SPWS_RunManualMode(void){
    g_ledState = LED_NORMAL;
}
