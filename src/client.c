#include "reludp.h"
#include "ru_packet.h"
#include "ru_socket.h"
#include <stdio.h>

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

char *addr = "127.0.0.1";
int   port = 8888;
ru_socket *srv_sock = NULL;

int main()
{
    //char filename[] = "lena_full.jpg";
    char filename[] = "src/test_file.txt";

    //Open connection
    if( (srv_sock = connect_to_ru_socket(addr, port)) == NULL )
    {
        fprintf(stderr, "Something went wrong with connecting to the socket.\n");
    }

    //Send file
    ru_send_file(srv_sock, filename);

    //Close connection

    return 0;
}
