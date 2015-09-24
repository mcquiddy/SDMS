#ifndef SOCKETCLIENTEHEAP_H
#define SOCKETCLIENTEHEAP_H
#include <QObject>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <sstream>
#include "strstream"
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>

class dHeap;
using namespace std;
class SocketClienteHeap:public QObject
{
Q_OBJECT

public:
    SocketClienteHeap(int pPuerto, char* pIp);
void setComando(string mensaje);
        bool setMensaje(const char *msn);


public slots:
  bool connectar();



    private:

dHeap* heap;
static void * controlador(void *obj);

        int puerto;
       char* ip;
        int descriptor;
        sockaddr_in info;
       // static void * controlador(void *obj);


};

#endif // SOCKETCLIENTEHEAP_H
