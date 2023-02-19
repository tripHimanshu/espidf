/*
esp32 devkit v1
platformIO and idf platform
Author: HImanshu Tripathi
---
creating two tasks and run them
Test1 - both tasks are identical and with same priority
Main executes first and then both tasks run in parallel
Test2 - change the value in vTaskDelay() in any one task
Test3 - both tasks are identical and they have different priority
*/
#include <esp_timer.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/timers.h>
#include <stdio.h>

// task 1 (printing time for 5 times)
void vtask1() {
  for (size_t i = 0; i < 5; i++) {
    printf("Task_1 %d: %lld\n", i, esp_timer_get_time() / 1000);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
  vTaskDelete(NULL);
}
// task 2 (printing time for 5 times)
void vtask2() {
  for (size_t i = 0; i < 5; i++) {
    printf("Task_2 %d: %lld\n", i, esp_timer_get_time() / 1000);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  vTaskDelete(NULL);
}

void app_main() {
  printf("\nMain Start: %lld\n", esp_timer_get_time() / 1000);
  // create task1
  xTaskCreate(vtask1,   // function to be called
              "Task 1", // task name
              2048,     // task stack size
              NULL,     // parameters to be passed in task
              1,        // task priority
              NULL);    // task handle

  // create task1
  xTaskCreate(vtask2,   // function to be called
              "Task 2", // task name
              2048,     // task stack size
              NULL,     // parameters to be passed in task
              1,        // task priority
              NULL);    // task handle
  printf("\nMain End: %lld\n", esp_timer_get_time() / 1000);
}