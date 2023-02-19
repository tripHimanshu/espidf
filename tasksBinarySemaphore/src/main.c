/*
esp32 devkit v1
platformIO and esp idf platform
Author: HImanshu Tripathi
---
creating binary semaphore and executing the high priority tasks in sequential
manner
*/
#include "freertos/FreeRTOS.h"
#include <esp_timer.h>
#include <freertos/semphr.h>
#include <freertos/task.h>
// #include <freertos/timers.h>
#include <stdio.h>

SemaphoreHandle_t xSemaphore = NULL;

void task1() {
  xSemaphoreTake(xSemaphore, portMAX_DELAY);
  for (size_t i = 0; i < 3; i++) {
    printf("Task1 %d: %lld\n", i, esp_timer_get_time() / 1000);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  printf("\n");
  xSemaphoreGive(xSemaphore);
  vTaskDelete(NULL);
}

void task2() {
  xSemaphoreTake(xSemaphore, portMAX_DELAY);
  for (size_t i = 0; i < 3; i++) {
    printf("Task2 %d: %lld\n", i, esp_timer_get_time() / 1000);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  printf("\n");
  xSemaphoreGive(xSemaphore);
  vTaskDelete(NULL);
}

void task3() {
  xSemaphoreTake(xSemaphore, portMAX_DELAY);
  for (size_t i = 0; i < 3; i++) {
    printf("Task3 %d: %lld\n", i, esp_timer_get_time() / 1000);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  printf("\n");
  xSemaphoreGive(xSemaphore);
  vTaskDelete(NULL);
}

void app_main() {
  printf("\n");
  //   in binary semaphore xSemaphoreCreateBinary() function creates and take
  //   the semaphore
  xSemaphore = xSemaphoreCreateBinary();

  printf("Main Start: %lld\n", esp_timer_get_time() / 1000);

  xSemaphoreGive(xSemaphore);

  xTaskCreate(task1, "Task 1", 2048, NULL, 2, NULL);
  xTaskCreate(task2, "Task 2", 2048, NULL, 2, NULL);
  xTaskCreate(task3, "Task 3", 2048, NULL, 2, NULL);

  xSemaphoreTake(xSemaphore, portMAX_DELAY);
  printf("Main End: %lld\n", esp_timer_get_time() / 1000);
}