#include <stdio.h>
#include "spws_controller.h"
#include "hal_actuators.h"


void SPWS_RunAutoMode(void){
    //Moisture < 40
    if(g_sensorData.soilMoisturePercent < g_systemSetting.minMoistureThreshold){ 
        if(g_systemState.pumpState = PUMP_OFF){
            HAL_TurnPumpOn();
            g_systemState.ledState = LED_WATERING;
            g_systemState.wateringTimeCounter = 0;
            printf("Auto watering start\n");
        }
    }
    //
    if(g_systemState.pumpState = PUMP_ON){

        g_systemState.wateringTimeCounter++;

        if(g_sensorData.soilMoisturePercent > g_systemSetting.maxMoistureThreshold || g_systemState.wateringTimeCounter > g_systemSetting.maxWateringDuration_s){
            HAL_TurnPumpOff();
            g_systemState.ledState = LED_NORMAL;
            printf("Auto watering stop\n");
        }
    }
}

void SPWS_RunManualMode(void){
    g_systemState.ledState = LED_NORMAL;
}
