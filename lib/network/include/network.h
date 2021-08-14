#ifndef _NETWORK_H
#define _NETWORK_H

typedef void (*network_task_cb)(void);

// network_task_cb will be called from network thread periodly
void network_start(network_task_cb cb);

#endif