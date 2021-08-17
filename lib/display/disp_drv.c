#include "disp_drv.h"
#include "LCD_1in14.h"
#include "DEV_Config.h"
#include "lvgl/lvgl.h"

void my_flush_cb(struct _lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    // printf("my_flush_cb: %d %d %d %d, %p\r\n", area->x1, area->y1, area->x2, area->y2, color_p);
    LCD_1IN14_DisplayWindows(area->x1, area->y1, area->x2 + 1, area->y2 + 2, color_p);
    /* IMPORTANT!!!
     * Inform the graphics library that you are ready with the flushing*/
    // printf("flush_ready\r\n");
    lv_disp_flush_ready(disp_drv);
}

void display_init()
{
    DEV_Delay_ms(100);
#ifdef DEBUG_PRINTF
    printf("LCD_1in14_test Demo\r\n");
#endif
    if (DEV_Module_Init() != 0)
    {
        return;
    }
    DEV_SET_PWM(50);
/* LCD Init */
#ifdef DEBUG_PRINTF
    printf("1.14inch LCD demo...\r\n");
#endif
    LCD_1IN14_Init(HORIZONTAL);

    LCD_1IN14_Clear(0xF800); // RED

    DEV_Delay_ms(200);

    /*A static or global variable to store the buffers*/
    static lv_disp_draw_buf_t disp_buf;

    /*Static or global buffer(s). The second buffer is optional*/
    static lv_color_t buf_1[MY_DISP_HOR_RES * MY_DISP_VER_RES];

    /*Initialize `disp_buf` with the buffer(s). With only one buffer use NULL instead buf_2 */
    lv_disp_draw_buf_init(&disp_buf, buf_1, NULL, MY_DISP_HOR_RES * MY_DISP_VER_RES);
    static lv_disp_drv_t disp_drv;      /*A variable to hold the drivers. Must be static or global.*/
    lv_disp_drv_init(&disp_drv);        /*Basic initialization*/
    disp_drv.draw_buf = &disp_buf;      /*Set an initialized buffer*/
    disp_drv.flush_cb = my_flush_cb;    /*Set a flush callback to draw to the display*/
    disp_drv.hor_res = MY_DISP_HOR_RES; /*Set the horizontal resolution in pixels*/
    disp_drv.ver_res = MY_DISP_VER_RES; /*Set the vertical resolution in pixels*/
    disp_drv.sw_rotate = 1;
    disp_drv.rotated = LV_DISP_ROT_NONE;

    lv_disp_t *disp;
    disp = lv_disp_drv_register(&disp_drv); /*Register the driver and save the created display objects*/
}
