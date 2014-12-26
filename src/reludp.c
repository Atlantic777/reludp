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
    ru_packet p;

    while( ru_recv_p(l_sock, &p) != 0)
    {
        if (p.payload[0] == EOF)
            break;
    }

    puts("End of recv");
    return 0;
}

int ru_send_file(ru_socket *srv_sock, char *filename)
{
    int n_sent = 0;
    const int max_len = 4;
    char r[max_len];
    FILE *f = fopen(filename, "rb");

    int seqn = 0;
    int len = 0;

    ru_packet p;
    p.header.type = t_ru_data;

    while( (len = fread(r, 1, max_len, f)) != 0 )
    {
        p.header.serno = seqn++;
        p.header.len = len;
        memcpy(p.payload, r, len);

        ru_send_p(srv_sock, &p);
    }

    p.header.serno++;
    p.header.len = 1;
    p.payload[0] = EOF;
    ru_send_p(srv_sock, &p);


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

int ru_send_p(ru_socket *srv_sock, ru_packet *p)
{
    int res;

    res = sendto(srv_sock->sockfd,
               p, sizeof(p->header)+p->header.len, 0,
               (struct sockaddr *)&(srv_sock->addr),
               sizeof(srv_sock->addr));

    return res;
}

int ru_recv_p(ru_socket *l_sock, ru_packet *p)
{
    struct sockaddr_in remote;
    return recvfrom(l_sock->sockfd, p, sizeof(ru_packet), 0, (struct sockaddr *)&remote, &(l_sock->len));
}
