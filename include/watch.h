#ifndef _WATCH_H
#define _WATCH_H

#include "task.h"

#define THREAD_GUI_STACK_SIZE 4 * 256  //  4K
#define THREAD_GUI_THREAD_PRIORITY tskIDLE_PRIORITY + 2

#define THREAD_SHELL_STACK_SIZE 2 * 256 // 2K
#define THREAD_SHELL_THREAD_PRIORITY THREAD_GUI_THREAD_PRIORITY
#define THREAD_NETWORK_STACK_SIZE 3 * 256 // 3K
#define THREAD_NETWORK_THREAD_PRIORITY THREAD_GUI_THREAD_PRIORITY  // improve network thread's priority, for the case that gui halt, but need send printf via network

#define THREAD_INPUT_STACK_SIZE 3 * 256  //  3K
#define THREAD_INPUT_THREAD_PRIORITY THREAD_GUI_THREAD_PRIORITY

#endif