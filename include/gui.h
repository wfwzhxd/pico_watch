#ifndef _GUI_H
#define _GUI_H

#include "FreeRTOS.h"
#include "semphr.h"

#define TIME_LEN_MAX 8
#define DATE_LEN_MAX 50

SemaphoreHandle_t lvgl_mutex;   // use for lvgl in multithread

void gui_start();

void set_time(char *time);
void set_date(char *date);

#endif