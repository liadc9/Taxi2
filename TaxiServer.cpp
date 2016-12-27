//
// Created by liad on 27/12/16.
//

#include "TaxiServer.h"

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int server() {
    //socket creator
    const int server_port = 5678;
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0) {
        perror("error creating socket");
    }
    //bind socket
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    //bind check
    if (bind(sock, (struct sockaddr *) &sin, sizeof (sin)) < 0) {
        perror("error binding to socket");
    }
    //receiving data
    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    char buffer
    [4096];
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    // receiving data check
    if(bytes < 0) {
        perror("error reading from socket");
    }
    cout << "The client sent: " << buffer << endl;
    //sending data check
    int sent_bytes= sendto(sock, buffer, bytes, 0, (struct sockaddr *)&from, sizeof(from));
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }
    close(sock);
    return 0; }