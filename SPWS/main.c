#include <stdio.h>
#include <stdint.h>

#include "config.h"
#include "hal_actuators.h"
#include "hal_buttons.h"
#include "hal_sensors.h"
#include "spws_controller.h"


SystemMode_t g_systemMode;
PumpState_t g_pumpState;
LedState_t g_ledState;
SensorData_t g_sensorData;
SystemSettings_t g_systemSetting;
SystemState_t g_systemState;

void System_Init(void){
    g_systemMode = MODE_AUTO;
    g_pumpState = PUMP_OFF;
    g_ledState = LED_NORMAL;

    g_sensorData.soilMoisturePercent = 0;
    g_sensorData.airTemperatureCelsius = 0;   

    g_systemSetting.minMoistureThreshold = 40;
    g_systemSetting.maxMoistureThreshold = 70;
    g_systemSetting.maxWateringDuration_s = 10;
    g_systemSetting.sensorReadInterval_s = 2;
    g_systemSetting.manualWateringDuration_s = 5;

    g_systemState.currentMode = MODE_AUTO;
    g_systemState.pumpState = PUMP_OFF;
    g_systemState.ledState = LED_NORMAL;
    g_systemState.wateringTimeCounter = 0;
    g_systemState.sensorCheckCounter = 0;

    printf("=== SPWS SYSTEM INIT ===\n");
}

void main(){

    System_Init();

    while(1){


    }

    return 0;
}

