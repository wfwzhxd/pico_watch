/* Kernel includes. */
#include "FreeRTOS.h" /* Must come first. */
#include "task.h"     /* RTOS task related API prototypes. */
#include <stdio.h>
#include "pico/stdlib.h"
#include "gui.h"
#include "shell.h"
#include "network.h"

static void prvSetupHardware(void);

int main(void)
{
    prvSetupHardware();
    gui_start();
    shell_start();
    network_start(NULL);
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
