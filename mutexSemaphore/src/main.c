#include <esp_timer.h>
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <freertos/task.h>
#include <freertos/timers.h>
#include <stdio.h>

SemaphoreHandle_t xSemaphore = NULL;

void task1() {
  xSemaphoreTake(xSemaphore, portMAX_DELAY);
  for (size_t i = 0; i < 5; i++) {
    printf("Time_Task1 %d: %lld\n", i, esp_timer_get_time() / 1000);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  xSemaphoreGive(xSemaphore);
  vTaskDelete(NULL);
}
void app_main() {
  xSemaphore = xSemaphoreCreateMutex();
  printf("\nMain Start: %lld\n", esp_timer_get_time() / 1000);
  // create task
  xTaskCreate(task1, "Task1", 2048, NULL, 1, NULL);
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  // take semaphore
  xSemaphoreTake(xSemaphore, portMAX_DELAY);
  printf("Main End: %lld\n", esp_timer_get_time() / 1000);
  // give semaphore
  xSemaphoreGive(xSemaphore);
}