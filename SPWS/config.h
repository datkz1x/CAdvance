#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    MODE_AUTO,
    MODE_MANUAL
} SystemMode_t;

typedef enum {
    PUMP_OFF,
    PUMP_ON
} PumpState_t;

typedef enum {
    LED_NORMAL, /*Green*/
    LED_WATERING, /*Yellow*/
    LED_LOW_MOISTURE_ALERT, /*Red*/
    LED_ERROR, /*Red*/
} LedState_t;

typedef struct 
{
    float soilMoisturePercent; 
    float airTemperatureCelsius; 
} SensorData_t;

typedef struct 
{
    float minMoistureThreshold; 
    float maxMoistureThreshold; 
    unsigned int maxWateringDuration_s;
    unsigned int sensorReadInterval_s;
    unsigned int manualWateringDuration_s;
} SystemSettings_t;

typedef struct 
{
    SystemMode_t currentMode;
    PumpState_t pumpState;
    LedState_t ledState;
    unsigned int wateringTimeCounter;
    unsigned int sensorCheckCounter;
} SystemState_t;

#endif
