#include "ru_packet.h"
#include <stdio.h>

void ru_print_header(ru_header *h)
{
    puts("Header info");
    puts("-----------");
    printf("Type:\t%d\n", h->type);
    printf("Serno:\t%d\n", h->serno);
    printf("Len:\t%d\n", h->len);
    puts("-----------\n");
}
