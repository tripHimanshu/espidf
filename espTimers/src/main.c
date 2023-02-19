/*
esp32 devkit v1
platformIO and espidf platform
Author: HImanshu Tripathi
---
Demonstration of timers
FreeRTOS provides software timers with following limitations -
1. Maximum Resolution is equal to RTOS tick period
2. Timer callbacks are dispatched from a low priority task
Hardware timers are free from both limitations

esp_timer_get_time() tells the time in microseconds since the boot of the device
*/
#include <esp_timer.h>
#include <freertos/FreeRTOS.h>
#include <freertos/timers.h>
#include <stdio.h>

void app_main() {
  printf("\n");
  //   get the time in microseconds from the start of chip
  printf("\nTimer: %lld microseconds\n", esp_timer_get_time());

  //   get the value of portTICK_PERIOD_MS
  printf("\nThe portTICK_PERIOD_MS is %ld milliseconds\n", portTICK_PERIOD_MS);

  //   find the time delay generated by vTaskDelay() function
  printf("\nTimer milliseconds 1:\n");
  printf("Time: %lld microseconds\n", esp_timer_get_time() / 1000);
  vTaskDelay(1 / portTICK_PERIOD_MS); // delay of 1/10 ms (100 us)
  printf("Time: %lld milliseconds\n", esp_timer_get_time() / 1000);

  printf("\nTimer milliseconds: 10\n");
  printf("Time: %lld milliseconds\n", esp_timer_get_time() / 1000);
  vTaskDelay(10 / portTICK_PERIOD_MS); // delay of 1 sec (1000000 us)
  printf("Time: %lld milliseconds\n", esp_timer_get_time() / 1000);

  printf("\nTimer milliseconds: 100\n");
  printf("Time: %lld milliseconds\n", esp_timer_get_time() / 1000);
  vTaskDelay(100 / portTICK_PERIOD_MS); // delay of 1 sec (1000000 us)
  printf("Time: %lld milliseconds\n", esp_timer_get_time() / 1000);

  printf("\nTimer milliseconds: 1000\n");
  printf("Time: %lld milliseconds\n", esp_timer_get_time() / 1000);
  vTaskDelay(1000 / portTICK_PERIOD_MS); // delay of 1 sec (1000000 us)
  printf("Time: %lld milliseconds\n", esp_timer_get_time() / 1000);

  //   another method for generating delays
  printf("\nnpdMS_TO_TICKS\n");
  printf("\nTimer milliseconds 1:\n");
  printf("Time: %lld millisseconds\n", esp_timer_get_time() / 1000);
  vTaskDelay(pdMS_TO_TICKS(1));
  printf("Time: %lld millisseconds\n", esp_timer_get_time() / 1000);

  printf("\nTimer milliseconds 10:\n");
  printf("Time: %lld millisseconds\n", esp_timer_get_time() / 1000);
  vTaskDelay(pdMS_TO_TICKS(10));
  printf("Time: %lld millisseconds\n", esp_timer_get_time() / 1000);

  printf("\nTimer milliseconds 100:\n");
  printf("Time: %lld millisseconds\n", esp_timer_get_time() / 1000);
  vTaskDelay(pdMS_TO_TICKS(100));
  printf("Time: %lld millisseconds\n", esp_timer_get_time() / 1000);

  printf("\nTimer milliseconds 1000:\n");
  printf("Time: %lld millisseconds\n", esp_timer_get_time() / 1000);
  vTaskDelay(pdMS_TO_TICKS(1000));
  printf("Time: %lld millisseconds\n", esp_timer_get_time() / 1000);
}