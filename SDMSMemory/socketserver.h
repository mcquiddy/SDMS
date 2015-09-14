#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

class SDSMemoryServer;
using namespace std;

struct dataSocket{
    SDSMemoryServer* server;
    int descriptor;
    int puerto;
    sockaddr_in info;
};


class SocketServer
{
private:
    bool flag_listen;
    bool flag_busy;
    int Puerto;
    int descriptor;
    sockaddr_in info;
    SDSMemoryServer *server;
    bool crear_Socket();
    bool ligar_kernel();
    static void *controladorCliente(void *obj);


public:
    SocketServer(int puerto,SDSMemoryServer* Server);
    void sentMns(const char* mns,int id);
    void run();
    int get_puerto();
    void busy(bool flag);
    void closeSocket();

};

#endif // SOCKETSERVER_H
