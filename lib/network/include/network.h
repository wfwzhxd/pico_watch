#ifndef _NETWORK_H
#define _NETWORK_H

#define MAX_NET_CB_NUM 10

typedef void (*network_cb)(struct netif *netif);

// network_task_cb will be called from network thread periodly
void network_add_cb(network_cb cb);

void network_start();

#endif