#ifndef SOCKETSERVERHEAP_H
#define SOCKETSERVERHEAP_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

class dHeap;
using namespace std;

<<<<<<< HEAD

=======
>>>>>>> 0bfc03cecd3bb36e7f3481b76e5c99b8a8422cfb
struct dataSocketHeap{
    dHeap* server;
    int descriptor;
    int puerto;
    sockaddr_in info;
};


class SocketServerHeap
{
private:

    int Puerto;
    int descriptor;
    sockaddr_in info;
    dHeap *server;
    bool crear_Socket();
    bool ligar_kernel();
    static void *controladorCliente(void *obj);


public:
    SocketServerHeap(int puerto,dHeap* Server);
    void sentMns(const char* mns,int id);
    void run();
    int get_puerto();


};

#endif // SOCKETSERVERHEAP_H
