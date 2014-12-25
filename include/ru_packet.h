#ifndef PACKET_H
#define PACKET_H

typedef enum { t_ru_ctrl, t_ru_data } ru_sock_t;

typedef struct {
    int type;
    int serno;
    int len;
} ru_header;

typedef struct {
    ru_header  header;
    char payload[1500];
} ru_packet;

void ru_print_header(ru_header *h);

#endif
