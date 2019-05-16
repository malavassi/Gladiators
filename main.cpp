//
// Created by fabian on 24/03/19.
//

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

using namespace std;

int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "192.168.43.61", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    int condition;
    while (true){

        cout << "Do we send/recieve a message?" << endl;
        cin >> condition;

        if (condition == 1) {
            send(sock, hello, strlen(hello), 0);
            printf("Hello message sent\n");

        }else if(condition == 2){
            valread = read(sock ,buffer, 1024);
            printf("%s\n",buffer );
        }else if(condition == 3){
            break;
        }else{}
    }
    return 0;
}