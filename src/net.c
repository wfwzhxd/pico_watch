#include "network.h"
#include <stdint.h>
#include "lwip/netif.h"

void net_config_cb(struct netif *netif)
{
    static uint8_t init = 0;
    if (!init)
    {
        init = 1;
        ip4_addr_t ip, mask, gw, dnss;
        IP4_ADDR(&ip, 10, 0, 0, 3);
        IP4_ADDR(&mask, 255, 255, 0, 0);
        IP4_ADDR(&gw, 10, 0, 0, 1);
        netif_set_addr(netif, &ip, &mask, &gw);
        IP4_ADDR(&dnss, 114, 114, 114, 114);
        dns_setserver(0, &dnss);
        // dhcp_start(netif);
        sntp_init();
    }
}

extern void stdio_net_cb(struct netif *netif);

void nettask_init()
{
    network_add_cb(net_config_cb);
    network_add_cb(stdio_net_cb);
}