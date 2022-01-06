/*
 * ab_tcp_server.h
 *
 *  Created on: 2021年12月26日
 *      Author: ljm
 */

#ifndef AB_NET_AB_TCP_SERVER_H_
#define AB_NET_AB_TCP_SERVER_H_

#ifdef __cplusplus__
extern "C" {
#endif

#include "ab_socket.h"

#define T ab_tcp_server_t
typedef struct T *T;

extern T    ab_tcp_server_new(unsigned short port,
                              void new_connection_cb(ab_socket_t, void*),
                              void *user_data);
extern void ab_tcp_server_free(T *tcp_server);

#undef T

#ifdef __cplusplus__
}
#endif

#endif /* AB_NET_AB_TCP_SERVER_H_ */
