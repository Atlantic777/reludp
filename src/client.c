#include "reludp.h"
#include "ru_packet.h"
#include "ru_socket.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

char *addr;
int   port = -1;
ru_socket *srv_sock = NULL;

int main(int argc, char **argv)
{
    if(argc != 4) {
        puts("Usage: <server-ip> <port> <file-to-send.xyz>");
        return -1;
    }

    addr = argv[1];
    port = atoi(argv[2]);

    //Open connection
    if( (srv_sock = connect_to_ru_socket(addr, port)) == NULL )
    {
        fprintf(stderr, "Something went wrong with connecting to the socket.\n");
    }

    //Send file
    ru_send_file(srv_sock, argv[3]);

    //Close connection

    return 0;
}
