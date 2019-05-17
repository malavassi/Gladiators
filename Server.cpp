//
// Created by cvaz on 08/05/19.
//

#include "Server.h"

using namespace std;

Server::Server() {
    client_socket=0;
}

int Server::run() {
    //Example code: A simple server side code, which echos back the received message.
//Handle multiple socket connections with select and fd_set on Linux
    int opt = TRUE;
    int master_socket, addrlen, new_socket,
            max_clients = 1, activity, i, valread, sd;
    int max_sd;
    struct sockaddr_in address;
    int condicion;
    char buffer[1025];  //data buffer of 1K
    //set of socket descriptors
    fd_set readfds;

    //initialise all client_socket[] to 0 so not checked
    for (i = 0; i < max_clients; i++) {
        client_socket = 0;
    }

    //create a master socket
    if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    //set master socket to allow multiple connections ,
    //this is just a good habit, it will work without this
    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *) &opt,
                   sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    //type of socket created
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    cout << inet_ntoa(address.sin_addr) << endl;

    //bind the socket to localhost port 8080
    if (bind(master_socket, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    printf("Listener on port %d \n", PORT);

    //try to specify maximum of 3 pending connections for the master socket
    if (listen(master_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //accept the incoming connection
    addrlen = sizeof(address);
    puts("Waiting for connections ...");

    bool kk;
    kk=true;

    while (kk) {
        //clear the socket set
        FD_ZERO(&readfds);

        //add master socket to set
        FD_SET(master_socket, &readfds);
        max_sd = master_socket;

        //add child sockets to set
        for (i = 0; i < max_clients; i++) {
            //socket descriptor
            sd = client_socket;

            //if valid socket descriptor then add to read list
            if (sd > 0)
                FD_SET(sd, &readfds);

            //highest file descriptor number, need it for the select function
            if (sd > max_sd)
                max_sd = sd;
        }

        //wait for an activity on one of the sockets , timeout is NULL ,
        //so wait indefinitely

        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if ((activity < 0) && (errno != EINTR)) {
            printf("select error");
        }
        cout << "este: " <<  ntohs(address.sin_port) << endl;
        //If something happened on the master socket ,
        //then its an incoming connection
        if (FD_ISSET(master_socket, &readfds)) {
            if ((new_socket = accept(master_socket,
                                     (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            //inform user of socket number - used in send and receive commands
            printf("New connection, socket fd is %d , ip is : %s , port : %d\n" , new_socket , inet_ntoa(address.sin_addr) , ntohs(address.sin_port));

            //add new socket to array of sockets
            client_socket = new_socket;
        }

        //else its some IO operation on some other socket
        for (i = 0; i < max_clients; i++) {
            kk = true;
            cout << "entrooooo"<<endl;
            sd = client_socket;

            if (FD_ISSET(sd, &readfds)) {
                //Check if it was for closing , and also read the
                //incoming message
                cout << "valreadAF: " << valread << endl;

                if ((readFromClient() == 0)) {
                    //Somebody disconnected , ge
                    // t his details and print
                    cout << "valread M: " << valread << endl;
                    getpeername(sd, (struct sockaddr *) &address, \
                        (socklen_t *) &addrlen);
                    printf("Host disconnected , ip %s , port %d \n",
                           inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    //Close the socket and mark as 0 in list for reuse
                    close(sd);
                    client_socket = 0;
                }
                    //Echo back the message that came in
                else {
                    //set the string terminating NULL byte on the end
                    //of the data read
                    client_socket = sd;
                    kk=false;
                    break;

                }
            }
        }
    }
}

void Server::sendToClient(string message) {
    const char *a = message.c_str();
    send(client_socket, a, strlen(message.c_str()), 0);
}

int Server::readFromClient() {
    //char buffer[1024];
    int valread= read(client_socket, buffer, 1024);
    buffer[valread] = '\0';
    return valread;
}
