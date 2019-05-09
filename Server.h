//
// Created by cvaz on 08/05/19.
//

#ifndef GLADIATORS_SERVER_H
#define GLADIATORS_SERVER_H


#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros
#include <cstdlib>
#include <string>
#include <iostream>




#define TRUE   1
#define FALSE  0

#define PORT 8080

using namespace std;

class Server {
public:
    int client_socket;
    struct sockaddr_in address;
    char buffer[1025] = {0};
    Server();
    int run ();

    void sendToClient(string message);
    int readFromClient();

};

#endif //GLADIATORS_SERVER_H
