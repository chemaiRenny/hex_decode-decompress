typedef struct string_buffer
{
    char buf[1024];
}string_buffer;

string_buffer decode(char *);
string_buffer decompress(char *in_stream);
