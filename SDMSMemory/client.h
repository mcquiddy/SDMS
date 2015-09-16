/*
 * client.cpp
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


using namespace std;
class client{

public:
	int pClient;
	bool isExit=false;
    int	portNum = 8089;
    const char* ip = "192.168.1.114";
	int	bufsize = 1024;
    char buffer[1024];

	struct sockaddr_in server_addr;
	    client();
	    int StartClient();
};


