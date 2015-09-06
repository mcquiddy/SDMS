#ifndef SDSMEMORYNODE_H
#define SDSMEMORYNODE_H
#include <iostream>
#include <stdlib.h>
#include "SocketServer.h"

using namespace std;

class SDSMemoryNode
{
private:
    void* memoria_reservada;
    char* id;
    int size;
    SocketServer *puerto;
    SocketServer *puerto_status;


public:
    SDSMemoryNode(int cantidad,char exponente,int Puerto, int Puerto_status);
    void SaveMemory();
};

#endif // SDSMEMORYNODE_H

//struct
