/*
 * main.c
 *
 *  Created on: 2021年12月25日
 *      Author: ljm
 */

#include "ab_net/ab_tcp_server.h"
#include "ab_net/ab_socket.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#ifdef WIN32
#include <signal.h>
#else
#include <sys/signal.h>
#endif

static bool g_quit = true;
void signal_catch(int signal_num) {
    if (SIGINT == signal_num)
        g_quit = true;
}

static void accept_cb(void *sock, void *user_data) {
    const unsigned int buf_size = 64;
    char addr_buf[buf_size];
    unsigned short port = 0;

    memset(addr_buf, 0, buf_size);
    if (ab_socket_addr(sock, addr_buf, buf_size) == 0 &&
        ab_socket_port(sock, &port) == 0) {
        printf("New connection[%s:%d]\n", addr_buf, port);
    }
}

int main(int argc, char *argv[]) {
#ifdef WIN32
    setbuf(stdout, NULL);
#endif
    signal(SIGINT, signal_catch);

    ab_tcp_server_t tcp_server =
            ab_tcp_server_new(9527, accept_cb, NULL);

    g_quit = false;
    while (!g_quit) {
        sleep(1);
    }

    ab_tcp_server_free(&tcp_server);
    return EXIT_SUCCESS;
}
