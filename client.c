#include "client.h"

int main()
{
    int sk_desc;
    struct sockaddr_in server_addr;
    char server_msg[2000];
    char client_msg[2000] = "connected to server";
    //clean buffer

    memset(server_msg,'\0',sizeof(server_msg));

    sk_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (sk_desc == -1 )
    {
        printf("Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    printf("Socket created successfully\n");
    bzero(&server_addr, sizeof(server_addr));
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(IP);
    server_addr.sin_port = htons(PORT);

    //SEND REQUESTsu
    if (connect(sk_desc,(SA*)&server_addr, sizeof(server_addr)) != 0)
    {
        printf("Connection Error.\n");
        exit(EXIT_FAILURE);
    }
    printf("Connection successful\n");

    //send message
    
    if (send(sk_desc,client_msg,strlen(client_msg), 0) < 0 )
    {
        printf("Error sending the message\n");
        exit(EXIT_FAILURE);
    }

    if(recv(sk_desc,server_msg,sizeof(server_msg),0) < 0 )
    {
        printf("Error receiving message\n");
        exit(EXIT_FAILURE);
    }
    printf("Server message: %s\n",server_msg);
}
