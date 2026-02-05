#ifndef SPWS_CONTROLLER_H
#define SPWS_CONTROLLER_H


#include "config.h"

extern SensorData_t g_sensorData;
extern SystemSettings_t g_systemSetting;
extern SystemState_t g_systemState;

void SPWS_RunAutoMode(void);
void SPWS_RunManualMode(void);


#endif