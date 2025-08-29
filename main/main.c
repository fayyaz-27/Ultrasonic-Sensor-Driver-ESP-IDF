// File: Ultrasonic Application Code
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

#include "ultrasonic.h"

#define TAG "Ultrasonic Sensor"

void app_main(void){

    uint8_t echo = 13;
    uint8_t trigger = 4;

    gpio_set_direction(echo, GPIO_MODE_INPUT);
    gpio_set_direction(trigger, GPIO_MODE_OUTPUT);

    while(1){
                float distance = get_ultrasonic_distance(echo, trigger);

                ESP_LOGI(TAG, "Distance: %.2f cm", distance);
                vTaskDelay(50 / portTICK_PERIOD_MS);
    }

}