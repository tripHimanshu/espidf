/*
esp32 devkit v1
platformIO and espidf platform
Author: Himanshu Tripathi
---
blinking on_board led of esp32 devkit
*/

#include <driver/gpio.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define TAG "LED State"

#define LED GPIO_NUM_2

void app_main() {
  // pin congiguration
  gpio_set_direction(LED, GPIO_MODE_OUTPUT);
  while (1) {
    gpio_set_level(LED, 1);
    ESP_LOGI(TAG, "LED is on\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    gpio_set_level(LED, 0);
    ESP_LOGI(TAG, "LED is off\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}