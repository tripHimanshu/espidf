/*
esp32 devkit v1
platformIO and espidf platform
Author: Himanshu Tripathi
---
printing message on minitor
and printing all types of logs
*/
#include <stdio.h>
#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include <esp_log.h>

#define TAG "Logging"

void app_main() {
  // print message
  printf("Hello World\n");
  int log_level = 1;
  // printing logs
  ESP_LOGE(TAG, "This is error logging with level %d", log_level++);
  ESP_LOGW(TAG, "This is warning logging with level %d", log_level++);
  ESP_LOGI(TAG, "This is Info logging with level %d", log_level++);
  ESP_LOGD(TAG, "This is Debug logging with level %d", log_level++);
  ESP_LOGV(TAG, "This is Verbose logging with level %d", log_level++);
}