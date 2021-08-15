#include "FreeRTOS.h"
#include "task.h"
#include "pico/stdio.h"
#include <stdio.h>
#include "FreeRTOSConfig.h"
#include "watch.h"
#include "rtc.h"
#include "util.h"
#include <string.h>
#include "hardware/watchdog.h"
#include "pico/bootrom.h"
#include "pico/time.h"

#define CMD_LEN_MAX 40

int cmd_set_datetime(char *args);
int cmd_list_cmd(char *args);
int cmd_help_cmd(char *args);
int cmd_task_list(char *args);
int cmd_heap_stat(char *args);
int cmd_reset(char *args);
int cmd_flash(char *args);
int cmd_uptime(char *args);

typedef int (*cmd_entry)(char *args);

typedef struct
{
    const char *const cmd;
    const char *const desc; // simple describle
    const char *const help; // detail usage helper
    const cmd_entry entry;
} cmd_t;

static const cmd_t cmd_map[] = {
    {.cmd = "uptime",
     .desc = "show how long does the device running",
     .help = NULL,
     .entry = cmd_uptime},
    {.cmd = "flash",
     .desc = "reboot device to flash mode for update fireware",
     .help = NULL,
     .entry = cmd_flash},
    {.cmd = "reset",
     .desc = "reset the whole device",
     .help = NULL,
     .entry = cmd_reset},
    {.cmd = "set_datetime",
     .desc = "set current datetime",
     .help = "usage example: datetime 2021 08 09, 12 23",
     .entry = cmd_set_datetime},
    {.cmd = "task_list",
     .desc = "show task info",
     .help = "no need arg",
     .entry = cmd_task_list},
    {.cmd = "heap_stat",
     .desc = "show heap memory usage",
     .help = "no need arg",
     .entry = cmd_heap_stat},
    {.cmd = "help",
     .desc = "show command usage, eg: help set_datetime",
     .help = "no need more explain",
     .entry = cmd_help_cmd},
    {.cmd = "h",
     .desc = "show all commands",
     .help = "no need more explain",
     .entry = cmd_list_cmd}};

const cmd_t *match_cmd(const char *cmds)
{
    while (' ' == *cmds) // strip
    {
        cmds++;
    }

    cmd_t *result = NULL;
    const unsigned char cmdsLen = strlen(cmds);
    for (__uint8_t i = 0; i < ARRAY_LEN(cmd_map); i++)
    {
        const unsigned char cmdLen = strlen(cmd_map[i].cmd);
        if (cmdsLen < cmdLen || (cmdsLen > cmdLen && cmds[cmdLen] != ' '))
        {
            continue;
        }
        if (strncmp(cmd_map[i].cmd, cmds, cmdLen) == 0)
        {
            result = &cmd_map[i];
            break;
        }
    }
#ifdef DEBUG_PRINTF
    printf("match_cmd [%s] to [%s]\n", cmds, result ? result->cmd : "NULL");
#endif
    return result;
}

static char cmdbuf[CMD_LEN_MAX + 1];

void dispatch_cmd()
{
    const cmd_t *cmd = match_cmd(cmdbuf);
    if (cmd)
    {
        if (cmd->entry(cmdbuf + strlen(cmd->cmd)) >= 0)
        {
            printf("--------------[success]--------------\n");
        }
        else
        {
            printf("--------------[failed]--------------\n");
        }
    }
    else
    {

        printf("unknown cmd: %s\n", cmdbuf);
    }
}

void shell_entry()
{
    static char c;
    static unsigned char idx = 0;
    char slash_shown = 0;
    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(50));
        c = getchar();
        // printf("recv: %d\n", c);
        if (c < 0)
        {
            continue;
        }
        cmdbuf[idx % CMD_LEN_MAX] = c;
        idx++;
        if (13 == c || 10 == c ) // 13 is \n, 10 is \r
        {
            cmdbuf[--idx] = 0;
            if (!slash_shown)
            {
                slash_shown = 1;
                printf("Welcome to shell!\nType 'h' to find usage");
            }
            else
            {
                if (strlen(cmdbuf) > 0)
                {
                    dispatch_cmd();
                }
            }
            idx = 0;
            cmdbuf[idx] = 0;
            printf("\n#");
        }
    }
}

void shell_start()
{
    BaseType_t rt;
    /* Create the main task */
    rt = xTaskCreate(/* The function that implements the task. */
                     shell_entry,
                     /* Text name for the task, just to help debugging. */
                     "shell",
                     /* The size (in words) of the stack that should be created
            for the task. */
                     THREAD_SHELL_STACK_SIZE,
                     /* A parameter that can be passed into the task.  Not used
            in this simple demo. */
                     NULL,
                     /* The priority to assign to the task.  tskIDLE_PRIORITY
            (which is 0) is the lowest priority.  configMAX_PRIORITIES - 1
            is the highest priority. */
                     THREAD_SHELL_THREAD_PRIORITY,
                     /* Used to obtain a handle to the created task.  Not used in
            this simple demo, so set to NULL. */
                     NULL);
    if (rt != pdPASS)
    {
        printf("create thread [shell] failed %d\n", rt);
    }
}

int cmd_set_datetime(char *args)
{
    if (strlen(args) < 17)
    {
        return -1;
    }
    __uint16_t year, month, day, hour, min, sec, dotw;
    // portDISABLE_INTERRUPTS();
    if (7 == sscanf(args, "%hd %hd %hd, %hd %hd %hd, %hd", &year, &month, &day, &hour, &min, &sec, &dotw) || rtc_set_datetime2(year, month, day, hour, min, sec, dotw))
    {
        return 0;
    }
    else
    {
        printf("error format\n");
        return -1;
    }
    // portENABLE_INTERRUPTS();
}

int cmd_list_cmd(char *args)
{
    printf("all commands:\n");
    for (__uint8_t i = 0; i < ARRAY_LEN(cmd_map); i++)
    {
        printf("[%s]: %s\n", cmd_map[i].cmd, cmd_map[i].desc);
    }
}

int cmd_help_cmd(char *args)
{
    const cmd_t *cmd = match_cmd(args);
    if (cmd)
    {
        printf("[%s]: %s\n", cmd->cmd, cmd->help);
    }
    else
    {
        return -1;
    }
}

int cmd_task_list(char *args)
{
    char buf[300];
    portDISABLE_INTERRUPTS();
    vTaskList(buf);
    printf("%s\n", buf);
    portENABLE_INTERRUPTS();
}

int cmd_heap_stat(char *args)
{
    // THIS FUCN MAY NOT EXIST
    HeapStats_t xHeapStats;
    vPortGetHeapStats(&xHeapStats);
    portDISABLE_INTERRUPTS();
    printf("xAvailableHeapSpaceInBytes: %ld\n", xHeapStats.xAvailableHeapSpaceInBytes);
    printf("xSizeOfLargestFreeBlockInBytes: %ld\n", xHeapStats.xSizeOfLargestFreeBlockInBytes);
    printf("xSizeOfSmallestFreeBlockInBytes: %ld\n", xHeapStats.xSizeOfSmallestFreeBlockInBytes);
    printf("xNumberOfFreeBlocks: %ld\n", xHeapStats.xNumberOfFreeBlocks);
    printf("xMinimumEverFreeBytesRemaining: %ld\n", xHeapStats.xMinimumEverFreeBytesRemaining);
    printf("xNumberOfSuccessfulAllocations: %ld\n", xHeapStats.xNumberOfSuccessfulAllocations);
    printf("xNumberOfSuccessfulFrees: %ld\n", xHeapStats.xNumberOfSuccessfulFrees);
    portENABLE_INTERRUPTS();
}

int cmd_reset(char *args)
{
    //use watch dog to reset
    portDISABLE_INTERRUPTS();
    watchdog_enable(0, 0);
    while (1)
        ;
}

int cmd_flash(char *args)
{
    reset_usb_boot(0, 0);
}

int cmd_uptime(char *args)
{
    portDISABLE_INTERRUPTS();
    uint32_t uptime = to_ms_since_boot(get_absolute_time()) / 1000; //sec
    portENABLE_INTERRUPTS();
    uint8_t sec = uptime % 60;
    uptime = uptime / 60; // min
    uint8_t min = uptime % 60;
    uptime = uptime / 60; // hour
    uint8_t hour = uptime % 60;
    uptime = uptime / 24; // day
    uint8_t day = uptime;
    printf("uptime:  %d days %d hours %d minutes %d seconds\n", day, hour, min, sec);
}