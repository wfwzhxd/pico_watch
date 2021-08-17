#include "input_drv.h"
#include "lvgl/lvgl.h"
#include "FreeRTOS.h"
#include "task.h"
#include "watch.h"
#include "gui.h"

static SemaphoreHandle_t keySem;

void all_key_callback(uint gpio, uint32_t events)
{
    xSemaphoreGiveFromISR(keySem, NULL);
#if INPUT_DEBUG
    printf("keySem given\n");
#endif
}

extern input_driver_t input_keypad;

#if USE_MOUSE
extern input_driver_t input_mouse;
static input_driver_t *input_drivers[] = {&input_mouse, &input_keypad};
#else
extern input_driver_t input_encoder;
static input_driver_t *input_drivers[] = {&input_encoder, &input_keypad};
#endif

void input_key_init(const input_key_t* keys, const int length)
{
    for (int i = 0; i < length; i++)
    {
        uint8_t gpio = keys->gpio_num;
        gpio_init(gpio);
        gpio_pull_up(gpio);
        gpio_set_dir(gpio, GPIO_IN);
        gpio_set_irq_enabled_with_callback(gpio, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, all_key_callback);
        keys++;
    }
}

void input_entry()
{
    keySem = xSemaphoreCreateBinary();
    xSemaphoreTake(lvgl_mutex, portMAX_DELAY);
    for (uint8_t i = 0; i < ARRAY_LEN(input_drivers); i++)
    {
        input_drivers[i]->regist();
    }
    xSemaphoreGive(lvgl_mutex);
    while (1)
    {
#if INPUT_DEBUG
        printf("keySem taking\n");
#endif
        xSemaphoreTake(keySem, portMAX_DELAY); // wait indefinitely
#if INPUT_DEBUG
        printf("keySem taken\n");
#endif
        while (1)
        {
            uint8_t keyCnt = 0;
            for (uint8_t i = 0; i < ARRAY_LEN(input_drivers); i++)
            {
                keyCnt += input_drivers[i]->scan();
            }
            if (!keyCnt)
            {
                break;
            }
            vTaskDelay(pdMS_TO_TICKS(30));
        }
    }
}

void input_start()
{
    BaseType_t rt;
    rt = xTaskCreate(input_entry, "input", THREAD_INPUT_STACK_SIZE, NULL, THREAD_INPUT_THREAD_PRIORITY, NULL);
    if (rt != pdPASS)
    {
        printf("create thread [input] failed %d\n", rt);
    }
}
