#include "FreeRTOS.h"
#include "rtc.h"
#include "hardware/rtc.h"

int rtc_set_datetime2(uint16_t year, uint16_t month, uint16_t day, uint16_t hour, uint16_t min, uint16_t sec, uint16_t dotw)
{
    #ifdef DEBUG_PRINTF
    printf("set_datetime: %d %d %d, %d %d %d, %d\n", year, month, day, hour, min, sec, dotw);
    #endif
    datetime_t datetime_tt2;
    datetime_tt2.year = year;
    datetime_tt2.month = month;
    datetime_tt2.day = day;
    datetime_tt2.dotw = dotw;
    datetime_tt2.hour = hour;
    datetime_tt2.min = min;
    datetime_tt2.sec = sec;
    // vTaskDelay(pdMS_TO_TICKS(100));
    return rtc_set_datetime(&datetime_tt2);
}

datetime_t *rtc_get_datetime2()
{
    static datetime_t datetime_tt;
    static unsigned char rtc_inited = 0;
    if (!rtc_inited)
    {
        rtc_inited = 1;
        rtc_init();
        datetime_tt.year = 2021;
        datetime_tt.month = 8;
        datetime_tt.day = 13;
        datetime_tt.dotw = 5;
        datetime_tt.hour = 3;
        datetime_tt.min = 15;
        datetime_tt.sec = 20;
        rtc_set_datetime(&datetime_tt);
    }
    // while (1) {
    //     rtc_get_datetime(&datetime_tt);
    //     printf("rtc sec: %2d\n", datetime_tt.sec);
    // }
    rtc_get_datetime(&datetime_tt);
    return &datetime_tt;
}