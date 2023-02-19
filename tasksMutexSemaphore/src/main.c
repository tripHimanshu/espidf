/*
esp32 devkit v1
platformIO and esp idf platform
Author: Himanshu Tripathi
---
creating 3 tasks and running these tasks sequentially using
mutex semaphore
*/
#include <esp_timer.h>
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <freertos/task.h>
#include <freertos/timers.h>
#include <stdio.h>

SemaphoreHandle_t xSemaphore = NULL;

// Task 1
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

// Task 2
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

// Task 3
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
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  printf("\n");
  printf("Main Start: %lld\n", esp_timer_get_time() / 1000);
  xSemaphore = xSemaphoreCreateMutex(); // create semaphore mutex

  //   create and start tasks
  xTaskCreate(task1, "Task 1", 2048, NULL, 1, NULL);
  xTaskCreate(task2, "Task 2", 2048, NULL, 1, NULL);
  xTaskCreate(task3, "Task 3", 2048, NULL, 1, NULL);

  vTaskDelay(1000 / portTICK_PERIOD_MS); // to get into tasks

  xSemaphoreTake(xSemaphore, portMAX_DELAY);
  printf("\n");
  printf("Main End: %lld\n", esp_timer_get_time() / 1000);
  xSemaphoreGive(xSemaphore);
}