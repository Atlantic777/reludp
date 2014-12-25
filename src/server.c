#include "reludp.h"
#include "ru_socket.h"
#include "ru_packet.h"
#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 256

char *addr = "127.0.0.1";
int   port = 8888;
char *filename = "out_file.jpg";
int status;

ru_socket *l_sock;

int main()
{
    if( (l_sock = listen_on_ru_socket(addr, port)) == NULL )
    {
        fprintf(stderr, "Something went wrong with opening listening socket.");
    }

    status = ru_recv_file(l_sock, filename);

    if(status < 0)
    {
        fprintf(stderr, "File not received");
    }

    return 0;
}
