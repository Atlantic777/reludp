#ifndef RU_SOCK_H
#define RU_SOCK_H

#include <netdb.h>

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    int len;
} ru_socket;

ru_socket* get_ru_socket();

#endif
