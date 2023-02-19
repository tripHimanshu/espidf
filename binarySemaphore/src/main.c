/*
esp32 devkit v1
platformIO and idf platform
Author: Himanshu Tripathi
---
to control the task binary Semaphores can be used
main task starts and then our defined task1 executes
during its execution task 1 holds the semaphore handle
and release it after completion of task1
then only main task executes and complete
*/

#include <esp_timer.h>
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <freertos/task.h>
#include <freertos/timers.h>
#include <stdio.h>

SemaphoreHandle_t xSemaphore = NULL;

// task
void vtask1() {
  for (size_t i = 0; i < 5; i++) {
    printf("Task_1 %d: %lld\n", i, esp_timer_get_time() / 1000);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  //   give semaphore handle after completion of task
  xSemaphoreGive(xSemaphore);
  vTaskDelete(NULL);
}

void app_main() {
  // create binary semaphores
  xSemaphore = xSemaphoreCreateBinary();
  printf("\nMain Start: %lld\n", esp_timer_get_time() / 1000);
  // create task
  xTaskCreate(vtask1,   // function to be called
              "Task 1", // taks name
              2048,     // task stack size
              NULL,     // parameters to be passed in function
              1,        // task priority
              NULL);    // task handle

  //   if (xSemaphoreTake(xSemaphore, portMAX_DELAY)) {
  //     printf("\nMain Ends: %lld\n", esp_timer_get_time() / 1000);
  //   }
  xSemaphoreTake(xSemaphore, portMAX_DELAY);
  printf("\nMain Ends: %lld\n", esp_timer_get_time() / 1000);
}