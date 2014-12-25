#ifndef PACKET_H
#define PACKET_H

#define CTRL 0
#define DATA 1

typedef struct {
    int type;
    int serno;
    int len;
} ru_header;

typedef struct {
    ru_header  *header;
    char *payload;
} ru_packet;

#endif
