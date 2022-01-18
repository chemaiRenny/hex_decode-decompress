#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct string_buffer
{
    char buf[1024];
}string_buffer;

void str_slice(char [],char [],int ,int );
string_buffer decode(char *);

string_buffer decode(char *encoded_string)
{
    char sub[1024];
    long n = 0;
    char temp[1024];
    string_buffer decode_msg = {0};

    for(int counter = 1; counter <= (strlen(encoded_string)); counter += 2)
    {
        str_slice(encoded_string,sub,counter,2);
        n = strtol(sub,NULL, 16);
        snprintf(temp,sizeof(temp),"%c",n); //%c used implicitely
        strncat(decode_msg.buf,temp,1);
    }
    return decode_msg;
}

void str_slice(char string[],char sub[],int position,int length)
{
   int counter = 0;
 
   for (counter = 0;counter < length; counter ++)
 {
      sub[counter] = string[position+counter-1];
   }
   sub[counter] = '\0';
}