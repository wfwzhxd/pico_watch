#ifndef _WATCH_H
#define _WATCH_H

#include "task.h"

#define THREAD_GUI_STACK_SIZE 76 * 256  //  76K
#define THREAD_GUI_THREAD_PRIORITY tskIDLE_PRIORITY + 2

#define THREAD_SHELL_STACK_SIZE 2 * 256 // 2K
#define THREAD_SHELL_THREAD_PRIORITY tskIDLE_PRIORITY   // same with idle, because getchar() with block task

#define THREAD_NETWORK_STACK_SIZE 6 * 256 // 6K
#define THREAD_NETWORK_THREAD_PRIORITY tskIDLE_PRIORITY + 1


#endif