#include "reludp.h"
#include "ru_socket.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ru_socket* connect_to_ru_socket(char *addr, int port)
{
    ru_socket *rs = get_ru_socket();

    rs->addr.sin_port = htons(port);

    struct hostent *hp;
    hp = gethostbyname(addr);
    memcpy(&(rs->addr.sin_addr.s_addr), hp->h_addr, hp->h_length);

    return rs;
}

ru_socket* listen_on_ru_socket(char *addr, int port)
{
    ru_socket *rs = get_ru_socket();

    rs->addr.sin_port = htons(port);
    rs->addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(rs->sockfd, (struct sockaddr *)&(rs->addr), sizeof(rs->addr));

    rs->len = sizeof(rs->addr);
    getsockname(rs->sockfd, (struct sockaddr *)&(rs->addr), &(rs->len));

    return rs;
}

int ru_recv_file(ru_socket *l_sock, char *filename)
{
    char b;
    while( ru_recv_b(l_sock, &b) != 0)
    {
        if(b == EOF) break;
        printf("%c", b);

        //get ru_packet
        //send ack
        //increase serno
    }

    puts("End of recv");
    return 0;
}

int ru_send_file(ru_socket *srv_sock, char *filename)
{
    int n_sent = 0;
    char r;
    FILE *f = fopen(filename, "rb");

    while( fread(&r, 1, 1, f) != 0 )
    {
        ru_send_b(srv_sock, r);

        //create ru_packet
        //send ru_packet
        //wait for ack (start timer)
        //if timer is out, resend
        //else, send next block and increase serno
    }
    ru_send_b(srv_sock, EOF);

    fclose(f);
    return 0;
}

int ru_send_b(ru_socket *srv_sock, char b)
{
    return sendto(srv_sock->sockfd, &b, 1, 0, (struct sockaddr *)&(srv_sock->addr), sizeof(srv_sock->addr));
}

int ru_recv_b(ru_socket *l_sock, char *b)
{
    struct sockaddr_in remote;
    return recvfrom(l_sock->sockfd, b, 1, 0, (struct sockaddr *)&remote, &(l_sock->len));
}
