#include "FreeRTOS.h"
#include "queue.h"
#include "lwip/tcp.h"
#include "pico/stdio/driver.h"

#define STDIO_NET_PORT 63

#define DEBUG_STDIO_NET 0

static err_t stdio_net_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err);
static void stdio_net_send(struct tcp_pcb *pcb);
static err_t stdio_net_sent(void *arg, struct tcp_pcb *pcb, u16_t len);
static void stdio_net_err(void *arg, err_t err);
static err_t stdio_net_poll(void *arg, struct tcp_pcb *pcb);
static err_t stdio_net_accept(void *arg, struct tcp_pcb *pcb, err_t err);

static QueueHandle_t queue_stdin;  // printf <- network
static QueueHandle_t queue_stdout; // printf -> network

static void stdio_net_out_chars(const char *buf, int length);
static int stdio_net_in_chars(char *buf, int length);

static stdio_driver_t stdio_net = {
    .out_chars = stdio_net_out_chars,
    .in_chars = stdio_net_in_chars,
#if PICO_STDIO_ENABLE_CRLF_SUPPORT
    .crlf_enabled = PICO_STDIO_DEFAULT_CRLF
#endif
};

#define STDIO_NET_BUF_SIZE 1024

static void stdio_net_init_driver()
{
    stdio_set_driver_enabled(&stdio_net, true);
}

static void stdio_net_init_tcp()
{
    struct tcp_pcb *tpcb = tcp_new();
    if (!tpcb)
    {
        printf("tcp_new failed\n");
        return;
    }
    err_t e = tcp_bind(tpcb, IP_ANY_TYPE, STDIO_NET_PORT);
    if (ERR_OK != e)
    {
        printf("tcp_bind failed %hd\n", e);
        return;
    }
    tpcb = tcp_listen(tpcb);
    if (!tpcb)
    {
        printf("tcp_listen_with_backlog failed\n");
        return;
    }
    tcp_accept(tpcb, stdio_net_accept);
}

static int try_send_out = 0;
static struct tcp_pcb *global_pcb = NULL;
void stdio_net_cb(struct netif *netif)
{
    static uint8_t init = 0;
    if (!init)
    {
        init = 1;
        queue_stdin = xQueueCreate(STDIO_NET_BUF_SIZE, 1);
        queue_stdout = xQueueCreate(STDIO_NET_BUF_SIZE, 1);
        stdio_net_init_driver();
        stdio_net_init_tcp();
    }
    if  (NULL != global_pcb) {
        stdio_net_send(global_pcb);
    }
}

static err_t stdio_net_accept(void *arg, struct tcp_pcb *pcb, err_t err)
{
#if DEBUG_STDIO_NET
    printf("stdio_net_accept, arg: %p, pcb: %p, err: %d\n", arg, pcb, err);
#endif
    LWIP_UNUSED_ARG(arg);
    if ((err != ERR_OK) || (pcb == NULL))
    {
        return ERR_VAL;
    }
    tcp_recv(pcb, stdio_net_recv);
    tcp_err(pcb, stdio_net_err);
    tcp_poll(pcb, stdio_net_poll, 1);
    global_pcb = pcb;
    return ERR_OK;
}

static err_t stdio_net_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err)
{
#if DEBUG_STDIO_NET
    printf("stdio_net_recv, arg: %p, pcb: %p, pbuf: %p, err: %d\n", arg, pcb, p, err);
#endif
    if ((err != ERR_OK) || (p == NULL))
    {
        /* error or closed by other side? */
        if (p != NULL)
        {
            /* Inform TCP that we have taken the data. */
            tcp_recved(pcb, p->tot_len);
            pbuf_free(p);
        }
        // todo: close tcp conn
        return ERR_OK;
    }
    char *data = (char *)p->payload;
    int data_len = p->len;
    while (data_len > 0)
    {
        xQueueSendToBack(queue_stdin, data, 0); // no wait
        data++;
        data_len--;
    }
    tcp_recved(pcb, p->tot_len);
    pbuf_free(p);
    // // delay , wait output
    // for (int j = 0; j < 3; j++)
    // {
    //     vTaskDelay(pdMS_TO_TICKS(100));
    //     stdio_net_send(pcb);
    // }

    return ERR_OK;
}

#define MAX_SEND_BUF STDIO_NET_BUF_SIZE
static void stdio_net_send(struct tcp_pcb *pcb)
{
#if DEBUG_STDIO_NET
    printf("stdio_net_send, pcb: %p\n", pcb);
#endif
    static char sendbuf[MAX_SEND_BUF];
    int buflen = 0;
    const int maxlen = tcp_sndbuf(pcb) > MAX_SEND_BUF ? MAX_SEND_BUF : tcp_sndbuf(pcb);
    while (buflen < maxlen)
    {
        if (pdPASS == xQueueReceive(queue_stdout, sendbuf + buflen, 0))
        {
            buflen++;
        }
        else
        {
            break;
        }
    }
    if (buflen)
    {
        tcp_write(pcb, sendbuf, buflen, TCP_WRITE_FLAG_COPY);
        tcp_output(pcb);
    }
}

static err_t stdio_net_sent(void *arg, struct tcp_pcb *pcb, u16_t len)
{
#if DEBUG_STDIO_NET
    printf("stdio_net_sent, arg: %p, tcp_pcb: %p, len: %d\n", arg, pcb, len);
#endif
    stdio_net_send(pcb);
    return ERR_OK;
}

static err_t stdio_net_poll(void *arg, struct tcp_pcb *pcb)
{
    stdio_net_send(pcb);
    return ERR_OK;
}

static void stdio_net_err(void *arg, err_t err)
{
#if DEBUG_STDIO_NET
    printf("stdio_net_err, arg: %p, err: %d\n", arg, err);
#endif
    global_pcb = NULL;
}

static void stdio_net_out_chars(const char *buf, int length)
{
    while (length > 0)
    {
        xQueueSendToBack(queue_stdout, buf, 0); // no wait
        buf++;
        length--;
    }
}

static int stdio_net_in_chars(char *buf, int length)
{
    int recv = 0;
    while (recv < length)
    {
        if (pdPASS == xQueueReceive(queue_stdin, buf, 0))
        {
            recv++;
            buf++;
        }
        else
        {
            break;
        }
    }
    return recv;
}
