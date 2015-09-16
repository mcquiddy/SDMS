/*
 * server.cpp
 *
 *  Created on: 15 de set. de 2015
 *      Author: bryan
 */
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include "DLinked_List.h"
using namespace std;
class server{
public:
	  	int client, pServer;
        int portNum = 8089;
        int bufsize = 1024;
	    bool isExit = false;
        char buffer[1024];

	    struct sockaddr_in server_addr;
	    socklen_t size;

	    server();
	    int StartServer();



};


