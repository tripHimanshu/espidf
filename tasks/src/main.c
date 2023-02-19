/*
esp32 devkit v1
platformIO and espidf platform
Author: Himanshu Tripathi
---
Demonstration of functions execution
and the task creation and execution
point to notice in execution of task that main function executes before the task
execution or we may also say that main and tasks executes parallely
*/

#include <esp_timer.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/timers.h>
#include <stdio.h>

// function 1
void vfunction1() {
  for (size_t i = 0; i < 5; i++) {
    printf("Function1 %d: %lld\n", i, esp_timer_get_time() / 1000);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

// function 2
void vfunction2() {
  for (size_t i = 0; i < 5; i++) {
    printf("Function2 %d: %lld\n", i, esp_timer_get_time() / 1000);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

// task 1
// after execution of task, it is deleted
// normally tasks run forever but here for demonstration purpose it is deleted
void vTask1() {
  for (size_t i = 0; i < 5; i++) {
    printf("vTask1 %d: %lld\n", i, esp_timer_get_time() / 1000);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  vTaskDelete(NULL);
}

void app_main() {
  printf("\nTimer:Code Start: %lld\n\n", esp_timer_get_time() / 1000);

  vfunction1();
  printf("\n");
  vfunction2();

  //   create task
  xTaskCreate(vTask1,  // function to be called
              "Task1", // task name
              2048,    // stack memory for task
              NULL,    // parameters to pass to task
              1,       // task priority
              NULL);   // task handle

  printf("\nTimer:Code End: %lld\n", esp_timer_get_time() / 1000);
}