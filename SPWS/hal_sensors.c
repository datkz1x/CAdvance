#include "hal_sensors.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float HAL_ReadSoilMoisture(void){
    return rand() % 31 + 40; //random 40 -> 70
}

float HAL_ReadTemperature(void){
    return rand() % 16 + 25; //random 25-> 40
}