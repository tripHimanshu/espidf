/*
esp32 devkit v1
platformIO and espidf platform
Author: Himanshu Tripathi
---
printing message on minitor
and printing all types of logs
adding delays with FreeRTOS
before running this code enable verbose logs in menuconfig
*/
#include <stdio.h>
#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define TAG "Logging"

void app_main() {
  // print message
  printf("Hello World\n");
  vTaskDelay(1000 / portTICK_PERIOD_MS); // delay for 1 sec
  int log_level = 1;
  // printing logs
  ESP_LOGE(TAG, "This is error logging with level %d", log_level++);
  vTaskDelay(1000 / portTICK_PERIOD_MS); // delay for 1 sec
  ESP_LOGW(TAG, "This is warning logging with level %d", log_level++);
  vTaskDelay(1000 / portTICK_PERIOD_MS); // delay for 1 sec
  ESP_LOGI(TAG, "This is Info logging with level %d", log_level++);
  vTaskDelay(1000 / portTICK_PERIOD_MS); // delay for 1 sec
  ESP_LOGD(TAG, "This is Debug logging with level %d", log_level++);
  vTaskDelay(1000 / portTICK_PERIOD_MS); // delay for 1 sec
  ESP_LOGV(TAG, "This is Verbose logging with level %d", log_level++);
  vTaskDelay(1000 / portTICK_PERIOD_MS); // delay for 1 sec
}