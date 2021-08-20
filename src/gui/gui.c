#include "gui.h"
#include "lvgl/lvgl.h"
#include "disp_drv.h"
#include "FreeRTOS.h" /* Must come first. */
#include "task.h"     /* RTOS task related API prototypes. */
#include "watch.h"
#include "semphr.h"
#include "rtc.h"
#include <stdio.h>

static char time_str[TIME_LEN_MAX + 1];
static char date_str[DATE_LEN_MAX + 1];

static lv_obj_t *time, *date;

static volatile SemaphoreHandle_t xSemaphore;

LV_FONT_DECLARE(lv_font_kslyt_30);
LV_FONT_DECLARE(lv_font_kslyt_48);

void create_widgets(void)
{
#ifdef DEBUG_PRINTF
    printf("whtfk, create\n");
#endif
    lv_disp_set_bg_color(lv_disp_get_default(), lv_color_black());
    lv_obj_t *screen_watch = lv_obj_create(NULL);
    lv_obj_set_style_bg_opa(screen_watch, LV_OPA_0, 0);

    static lv_style_t timestyle;
    lv_style_init(&timestyle);
    lv_style_set_text_color(&timestyle, lv_color_white());
    lv_style_set_text_font(&timestyle, &lv_font_kslyt_48);

    /*Create a container with ROW flex direction*/
    time = lv_label_create(screen_watch);
    lv_obj_add_style(time, &timestyle, 0);
    lv_label_set_text_fmt(time, "15:13:17");
    lv_obj_set_align(time, LV_ALIGN_TOP_MID);
    lv_obj_set_y(time, 30);

    static lv_style_t datestyle;
    lv_style_init(&datestyle);
    lv_style_set_text_color(&datestyle, lv_color_white());
    lv_style_set_text_font(&datestyle, &lv_font_kslyt_30);
    date = lv_label_create(screen_watch);
    lv_obj_add_style(date, &datestyle, 0);
    lv_label_set_text_fmt(date, "11月12 星期四");
    lv_obj_set_align(date, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_y(date, -20);
    lv_disp_load_scr(screen_watch);
#ifdef DEBUG_PRINTF
    printf("whtfk, end\n");
#endif
}

void prepare_datetime()
{
    static const char *daymap[] = {"天", "一", "二", "三", "四", "五", "六"};
    datetime_t *tt = rtc_get_datetime2();
    lv_snprintf(time_str, TIME_LEN_MAX + 1, "%02d:%02d:%02d", tt->hour, tt->min, tt->sec);
    lv_snprintf(date_str, DATE_LEN_MAX, "%d月%02d 星期%s", tt->month, tt->day, daymap[tt->dotw]);
}

void refresh_datetime(struct _lv_timer_t * timer)
{
    prepare_datetime();
    lv_label_set_text(date, date_str);
    // printf("date changed: %s\n", date_str);
    lv_label_set_text(time, time_str);
    // printf("time changed: %s\n", time_str);
    lv_disp_load_scr(lv_scr_act());
}

// extern void lv_demo_keypad_encoder(void);
static void loop()
{
    uint8_t delay_ms = 50;
    lv_timer_ready(lv_timer_create(refresh_datetime, 100, NULL));
    while (1)
    {
        xSemaphoreTake(lvgl_mutex, portMAX_DELAY);
        lv_tick_inc(delay_ms);
        lv_task_handler();
        xSemaphoreGive(lvgl_mutex);
        vTaskDelay(pdMS_TO_TICKS(delay_ms));
    }
}

static void gui_entry(void *pvParameters)
{
    lvgl_mutex = xSemaphoreCreateMutex();
    xSemaphoreTake(lvgl_mutex, portMAX_DELAY);
    lv_init();
    display_init();
    xSemaphoreGive(lvgl_mutex);
    input_start();
    vTaskDelay(pdMS_TO_TICKS(100));
    xSemaphoreTake(lvgl_mutex, portMAX_DELAY);
    create_widgets();
    // lv_demo_keypad_encoder();
    xSemaphoreGive(lvgl_mutex);
    loop();
}

void gui_start()
{
    BaseType_t rt;
    /* Create the main task */
    rt = xTaskCreate(gui_entry, "gui", THREAD_GUI_STACK_SIZE, NULL, THREAD_GUI_THREAD_PRIORITY, NULL);
    if (rt != pdPASS)
    {
        printf("create thread [gui] failed %d\n", rt);
    }
}
