#ifndef SPWS_CONTROLLER_H
#define SPWS_CONTROLLER_H


#include "config.h"

extern SensorData_t g_sensorData;
extern SystemSettings_t g_systemSetting;
extern PumpState_t g_pumpState;
extern LedState_t g_ledState;

void SPWS_RunAutoMode(void);
void SPWS_RunManualMode(void);


#endif