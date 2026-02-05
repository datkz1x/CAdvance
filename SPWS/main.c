#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#include "config.h"
#include "hal_actuators.h"
#include "hal_buttons.h"
#include "hal_sensors.h"
#include "spws_controller.h"


SensorData_t g_sensorData;
SystemSettings_t g_systemSetting;
SystemState_t g_systemState;

void System_Init(void){

    g_systemState.currentMode = MODE_AUTO;
    g_systemState.pumpState = PUMP_OFF;
    g_systemState.ledState = LED_NORMAL;
    g_systemState.wateringTimeCounter = 0;
    g_systemState.sensorCheckCounter = 0;

    g_sensorData.soilMoisturePercent = 0;
    g_sensorData.airTemperatureCelsius = 0;   

    g_systemSetting.minMoistureThreshold = 40;
    g_systemSetting.maxMoistureThreshold = 70;
    g_systemSetting.maxWateringDuration_s = 5;
    g_systemSetting.sensorReadInterval_s = 2;
    g_systemSetting.manualWateringDuration_s = 5;


    printf("=== SPWS SYSTEM INIT ===\n");
}

int main(){

    System_Init();

    while(1){

        g_sensorData.airTemperatureCelsius = HAL_ReadTemperature();
        g_sensorData.soilMoisturePercent = HAL_ReadSoilMoisture();

        printf("Temperature: %0.1f, Moisture Percentage: %0.1f\n", 
            g_sensorData.airTemperatureCelsius, 
            g_sensorData.soilMoisturePercent);
        
        /*Logic Button 1*/
        if(HAL_IsButton1Pressed()){

            if(g_systemState.currentMode == MODE_AUTO){
                g_systemState.currentMode = MODE_MANUAL;
                HAL_TurnPumpOff();
                printf("MANUAL MODE ON\n");
            } 
            else if(g_systemState.currentMode == MODE_MANUAL){
                g_systemState.currentMode = MODE_AUTO;
                printf("AUTO MODE ON\n");
            }
            else{
                printf("Can not detect system MODE\n");
            }
        }

        /*Logic Button 2*/
        if (g_systemState.currentMode == MODE_MANUAL && HAL_IsButton2Pressed()){
            
            printf("Manual watering start\n");
            HAL_TurnPumpOn();
            sleep(g_systemSetting.manualWateringDuration_s); 
            HAL_TurnPumpOff();
            printf("Manual watering end\n");
        }

        if (g_systemState.currentMode == MODE_AUTO){
            SPWS_RunAutoMode();
        }
        else{
            SPWS_RunManualMode();
        }

        HAL_SetLed();

        sleep(g_systemSetting.sensorReadInterval_s);
    }
    return 0;
}

