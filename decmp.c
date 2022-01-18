#include <stdio.h>
#include <zlib.h>
#include <string.h>

typedef struct string_buffer
{
    char buf[1024];
}string_buffer;
string_buffer decompress(char *in_stream);


string_buffer decompress(char *in_stream)
{
    string_buffer str1={0};
    char out_stream[1024];
    
    //zlib struct
    z_stream comp_stream;
    comp_stream.zalloc = Z_NULL;
    comp_stream.zfree = Z_NULL;
    comp_stream.opaque = Z_NULL;
    
    //seting inputs and outputs
    
    comp_stream.avail_in = (uInt)strlen(in_stream)+1;
    comp_stream.next_in = (Bytef *)in_stream;
    
    comp_stream.avail_out = (uInt)sizeof(out_stream);
    comp_stream.next_out = (Bytef *)out_stream;
    
    //decompression
    //inflateInit(&comp_stream); //zlib compressed
    inflateInit2( &comp_stream, 16 + MAX_WBITS); //gzip
    inflate(&comp_stream,Z_NO_FLUSH);
    inflateEnd(&comp_stream);
    
    snprintf(str1.buf,sizeof(str1.buf),"%s",out_stream);
    return str1;        
}
