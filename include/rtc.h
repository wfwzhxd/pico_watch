#ifndef _RTC_H
#define _RTC_H

#include "hardware/rtc.h"

int rtc_set_datetime2(uint16_t year, uint16_t month, uint16_t day, uint16_t hour, uint16_t min, uint16_t sec, uint16_t dotw);

datetime_t *rtc_get_datetime2();

#endif