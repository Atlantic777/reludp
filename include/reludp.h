#ifndef RELUDP_H
#define RELUDP_H

#include "ru_packet.h"
#include "ru_socket.h"

ru_socket* connect_to_ru_socket( char *addr, int port );
ru_socket*  listen_on_ru_socket( char *addr, int port );
int        ru_recv_file(ru_socket *l_sock, char *filename);
int        ru_send_file(ru_socket *srv_sock, char *filename);
int        ru_send_b(ru_socket *srv_sock, char b);
int        ru_recv_b(ru_socket *l_sock, char *b);
int        ru_send_p(ru_socket *srv_sock, ru_packet *b);
int        ru_recv_p(ru_socket *l_sock, ru_packet *b);

#endif
