// File: Ultrasonic Driver Code
// Author: Fayyaz Shaikh
// Email ID: fayyaz.shaikh7862005@gmail.com
// LinkedIn: https://www.linkedin.com/in/fayyaz-shaikh-7646312a3/


#include <stdio.h>
#include <stdint.h>

#include "esp_system.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"   // for esp_timer_get_time()
#include "rom/ets_sys.h" // for ets_delay_us()

#include "ultrasonic.h"


#define TIMEOUT_US 30000  // 30 ms timeout, adjust if needed

uint32_t pulseIn(gpio_num_t pin, int level, uint32_t timeout_us)
{
    uint32_t start = esp_timer_get_time();

    // wait for pin to go to desired level
    while (gpio_get_level(pin) != level) {
        if ((esp_timer_get_time() - start) > timeout_us) {
            return 0; // timeout
        }
    }

    // record the start time
    uint32_t pulse_start = esp_timer_get_time();

    // wait for pin to leave the desired level
    while (gpio_get_level(pin) == level) {
        if ((esp_timer_get_time() - pulse_start) > timeout_us) {
            return 0; // timeout
        }
    }

    // return pulse width
    return (esp_timer_get_time() - pulse_start);
}

float get_ultrasonic_distance(uint8_t echo, uint8_t trigger)
{

    // gpio_set_direction(echo, GPIO_MODE_INPUT);
    // gpio_set_direction(trigger, GPIO_MODE_OUTPUT);
    gpio_set_level(trigger, 0);
    ets_delay_us(2);

    gpio_set_level(trigger, 1);
    ets_delay_us(10);
    gpio_set_level(trigger, 0);

    uint32_t duration = pulseIn(echo, 1, TIMEOUT_US);

    return ((duration * 0.0343) / 2);
}