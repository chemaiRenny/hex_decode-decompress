#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hex_decode.c"
#include "decmp.c"

int main(int argc,char **argv)
{
    if (argc < 2)
    {

        printf("Usage:\n\tmain <hex-encoded-compressed string>");
        exit(EXIT_FAILURE);
    }
    char *input = argv[1];

    char *decoded=decode(input).buf;

    char *end_res=decompress(decoded).buf;

    printf("%s",end_res);

}
