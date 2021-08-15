#include "network.h"
#include <stdint.h>

void net_config_cb(struct netif *netif)
{
    static uint8_t init = 0;
    if (!init)
    {
        init = 1;
        dhcp_start(netif);
        sntp_init();
    }
}

extern void stdio_net_cb(struct netif *netif);

void nettask_init()
{
    network_add_cb(net_config_cb);
    network_add_cb(stdio_net_cb);
}