/* Kernel includes. */
#include "FreeRTOS.h" /* Must come first. */
#include "task.h"     /* RTOS task related API prototypes. */
#include <stdio.h>
#include "pico/stdlib.h"

#include "network.h"

static void prvSetupHardware(void);

extern void nettask_init();

int main(void)
{
    prvSetupHardware();
    network_start();    // register stdio_net first
    nettask_init();
#ifdef DEBUG_PRINTF
    printf("vTaskStartScheduler start\n");
#endif
    vTaskStartScheduler();

    /* should never reach here */
    panic_unsupported();
}

static void prvSetupHardware(void)
{
    /* Want to be able to printf */
    stdio_init_all();
#ifdef DEBUG_PRINTF
    printf("prvSetupHardware\n");
#endif
    /* And flash LED */
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
}

void DEV_Delay_ms(uint32_t xms)
{
    vTaskDelay(pdMS_TO_TICKS(xms));
}

// void isr_hardfault() {
//     printf("isr_hardfault\n");
// }