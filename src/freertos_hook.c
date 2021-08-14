#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "pico/stdlib.h"

void vApplicationMallocFailedHook(void)
{
    printf("vApplicationMallocFailedHook\n");
}

void vApplicationStackOverflowHook(TaskHandle_t xTask,
                                   char *pcTaskName)
{
    printf("vApplicationStackOverflowHook %s\n", pcTaskName);
}

static TickType_t last_update_led = 0;
static const TickType_t led_period = pdMS_TO_TICKS(1000);

void vApplicationIdleHook(void)
{
    const TickType_t cur_tick = xTaskGetTickCount();
    if ((cur_tick > last_update_led + led_period) ||
        (cur_tick < last_update_led))
    {
        last_update_led = cur_tick;
        gpio_put(PICO_DEFAULT_LED_PIN, !gpio_get(PICO_DEFAULT_LED_PIN));
    }
}