// File: Ultrasonic Header File
// Author: Fayyaz Shaikh
// Email ID: fayyaz.shaikh7862005@gmail.com
// LinkedIn: https://www.linkedin.com/in/fayyaz-shaikh-7646312a3/


#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <stdint.h>

#include "esp_system.h"
#include "driver/gpio.h"


uint32_t pulseIn(gpio_num_t pin, int level, uint32_t timeout_us);

float get_ultrasonic_distance(uint8_t echo, uint8_t trigger);


#endif