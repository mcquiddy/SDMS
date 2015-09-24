#ifndef SOCKETCLIENTE_H
#define SOCKETCLIENTE_H
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


using namespace std;
class SocketCliente:public QObject
{
Q_OBJECT

public:
    SocketCliente(int pPuerto, char* pIp);
void setComando(string mensaje);
        void setMensaje(const char *msn);


public slots:
  bool connectar();



    private:




        int puerto;
       char* ip;
        int descriptor;
        sockaddr_in info;
       // static void * controlador(void *obj);


};

#endif // SOCKETCLIENTE_H
