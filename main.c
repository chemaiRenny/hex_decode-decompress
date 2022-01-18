#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hex_decode.c"
#include "decmp.c"
#if defined main
    printf("Main exists");
#undef main
#endif

int main(int argc,char **argv)
{
    if (argc < 2)
    {

        printf("Usage:\n\tmain <hex-encoded-compressed string>");
        exit(EXIT_FAILURE);
    }
    char *input = "1f8b080032f7d85f02ff55cac10980400c04c056b602abb18153721a249b2309dabe873fbfc3aca760932c0c89ee618dbb406d84df62c282266a9e8ac6d452277ab87d46e7e371290f64b59ac93fffe1f202fcefa41e62000000";

    char *decoded=decode(input).buf;

    char *end_res=decompress(decoded).buf;

    printf("%s",end_res);

}
