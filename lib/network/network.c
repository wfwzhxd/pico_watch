/* 
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Peter Lawrence
 *
 * influenced by lrndis https://github.com/fetisov/lrndis
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

/*
this appears as either a RNDIS or CDC-ECM USB virtual network adapter; the OS picks its preference

RNDIS should be valid on Linux and Windows hosts, and CDC-ECM should be valid on Linux and macOS hosts

The MCU appears to the host as IP address 192.168.7.1, and provides a DHCP server, DNS server, and web server.
*/
/*
Some smartphones *may* work with this implementation as well, but likely have limited (broken) drivers,
and likely their manufacturer has not tested such functionality.  Some code workarounds could be tried:

The smartphone may only have an ECM driver, but refuse to automatically pick ECM (unlike the OSes above);
try modifying ./examples/devices/net_lwip_webserver/usb_descriptors.c so that CONFIG_ID_ECM is default.

The smartphone may be artificially picky about which Ethernet MAC address to recognize; if this happens, 
try changing the first byte of tud_network_mac_address[] below from 0x02 to 0x00 (clearing bit 1).
*/

#include "bsp/board.h"
#include "tusb.h"

#include "lwip/init.h"
#include "lwip/timeouts.h"
#include "lwip/dhcp.h"
#include "lwip/apps/lwiperf.h"
#include "lwip/apps/sntp.h"
#include <time.h>
#include "network.h"

#include "FreeRTOS.h"
#include "watch.h"

/* lwip context */
static struct netif netif_data;

/* shared between tud_network_recv_cb() and service_traffic() */
static struct pbuf *received_frame;

/* this is used by this code, ./class/net/net_driver.c, and usb_descriptors.c */
/* ideally speaking, this should be generated from the hardware's unique ID (if available) */
/* it is suggested that the first byte is 0x02 to indicate a link-local address */
const uint8_t tud_network_mac_address[6] = {0x02, 0x02, 0x84, 0x6A, 0x96, 0x00};

static err_t linkoutput_fn(struct netif *netif, struct pbuf *p)
{
  (void)netif;

  for (;;)
  {
    /* if TinyUSB isn't ready, we must signal back to lwip that there is nothing we can do */
    if (!tud_ready())
      return ERR_USE;

    /* if the network driver can accept another packet, we make it happen */
    if (tud_network_can_xmit())
    {
      tud_network_xmit(p, 0 /* unused for this example */);
      return ERR_OK;
    }

    /* transfer execution to TinyUSB in the hopes that it will finish transmitting the prior packet */
    tud_task();
  }
}

static err_t output_fn(struct netif *netif, struct pbuf *p, const ip_addr_t *addr)
{
  return etharp_output(netif, p, addr);
}

static err_t netif_init_cb(struct netif *netif)
{
  LWIP_ASSERT("netif != NULL", (netif != NULL));
  netif->mtu = CFG_TUD_NET_MTU;
  netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP | NETIF_FLAG_UP;
  netif->state = NULL;
  netif->name[0] = 'E';
  netif->name[1] = 'X';
  netif->linkoutput = linkoutput_fn;
  netif->output = output_fn;
  return ERR_OK;
}

static void init_lwip(void)
{
  struct netif *netif = &netif_data;

  lwip_init();

  /* the lwip virtual MAC address must be different from the host's; to ensure this, we toggle the LSbit */
  netif->hwaddr_len = sizeof(tud_network_mac_address);
  memcpy(netif->hwaddr, tud_network_mac_address, sizeof(tud_network_mac_address));
  netif->hwaddr[5] ^= 0x01;

  netif = netif_add(netif, NULL, NULL, NULL, NULL, netif_init_cb, ip_input);
  netif_set_default(netif);
}

bool tud_network_recv_cb(const uint8_t *src, uint16_t size)
{
  /* this shouldn't happen, but if we get another packet before 
  parsing the previous, we must signal our inability to accept it */
  if (received_frame)
    return false;

  if (size)
  {
    struct pbuf *p = pbuf_alloc(PBUF_RAW, size, PBUF_POOL);

    if (p)
    {
      /* pbuf_alloc() has already initialized struct; all we need to do is copy the data */
      memcpy(p->payload, src, size);

      /* store away the pointer for service_traffic() to later handle */
      received_frame = p;
    }
  }

  return true;
}

uint16_t tud_network_xmit_cb(uint8_t *dst, void *ref, uint16_t arg)
{
  struct pbuf *p = (struct pbuf *)ref;
  struct pbuf *q;
  uint16_t len = 0;

  (void)arg; /* unused for this example */

  /* traverse the "pbuf chain"; see ./lwip/src/core/pbuf.c for more info */
  for (q = p; q != NULL; q = q->next)
  {
    memcpy(dst, (char *)q->payload, q->len);
    dst += q->len;
    len += q->len;
    if (q->len == q->tot_len)
      break;
  }

  return len;
}

static void service_traffic(void)
{
  /* handle any packet received by tud_network_recv_cb() */
  if (received_frame)
  {
    ethernet_input(received_frame, &netif_data);
    pbuf_free(received_frame);
    received_frame = NULL;
    tud_network_recv_renew();
  }

  sys_check_timeouts();
}

void tud_network_init_cb(void)
{
  /* if the network is re-initializing and we have a leftover packet, we must do a cleanup */
  if (received_frame)
  {
    pbuf_free(received_frame);
    received_frame = NULL;
  }
}

static network_cb network_cbs[MAX_NET_CB_NUM];
static network_cbs_num = 0;

void network_add_cb(network_cb netcb)
{
  if (network_cbs_num < MAX_NET_CB_NUM)
  {
    network_cbs[network_cbs_num++] = netcb;
  }
}

void network_entry(void* args)
{
  /* initialize TinyUSB */
  board_init();
  tusb_init();

  /* initialize lwip, dhcp-server, dns-server, and http */
  init_lwip();
  while (!netif_is_up(&netif_data))
    ;
  // lwiperf_start_tcp_server_default(NULL, NULL);

  while (1)
  {
    tud_task();
    service_traffic();
    for (uint8_t i = 0; i < network_cbs_num; i++)
    {
        network_cbs[i](&netif_data);
    }
    vTaskDelay(pdMS_TO_TICKS(10));
  }

  // return 0;
}

void network_start()
{
  BaseType_t rt;
  /* Create the main task */
  rt = xTaskCreate(network_entry, "network", THREAD_NETWORK_STACK_SIZE, NULL, THREAD_NETWORK_THREAD_PRIORITY, NULL);
  if (rt != pdPASS)
  {
    printf("create thread [network] failed %d\n", rt);
  }
}

/* lwip has provision for using a mutex, when applicable */
sys_prot_t sys_arch_protect(void)
{
  return 0;
}
void sys_arch_unprotect(sys_prot_t pval)
{
  (void)pval;
}

/* lwip needs a millisecond time source, and the TinyUSB board support code has one available */
uint32_t sys_now(void)
{
  return board_millis();
}

extern void rtc_set_datetime2(uint16_t year, uint16_t month, uint16_t day, uint16_t hour, uint16_t min, uint16_t sec, uint16_t dotw);

void set_sys_rtc_time(uint32_t sec)
{
#ifdef DEBUG_PRINTF
  printf("sntp_set_sys_time:%d\n", sec);
#endif
  struct tm _tm;
  // tz +8
  const time_t tt = sec + 8 * 60 * 60;

  gmtime_r(&tt, &_tm);
  rtc_set_datetime2(_tm.tm_year + 1900, _tm.tm_mon + 1, _tm.tm_mday, _tm.tm_hour, _tm.tm_min, _tm.tm_sec, _tm.tm_wday);
}
