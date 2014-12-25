#include "ru_socket.h"
#include <stdlib.h>

ru_socket* get_ru_socket()
{
    ru_socket *rs = (ru_socket*)malloc(sizeof(ru_socket));
    rs->sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    rs->addr.sin_family = AF_INET;

    return rs;
}
