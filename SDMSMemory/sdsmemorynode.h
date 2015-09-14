#ifndef SDSMEMORYNODE_H
#define SDSMEMORYNODE_H
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include "sdsmemoryserver.h"
#include "linked_list.h"
#include "rapidjson/reader.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "memorymannager.h"

using namespace std;
using namespace rapidjson;




class SDSMemoryNode: public SDSMemoryServer
{
private:
    MemoryMannager Manejador;
    int client;
    lista<int*> list_ClientStatus;
    void* memoria_reservada;
    char* id;
    void start(int Puerto,int Puerto_status);


    void d_calloc(int pSize);
    void d_free(d_pointer_size free);


    void d_set(int pStatus);
    void d_status();
    int parseToInt(string pInt);
    string parseDelimitador(string* pString);



public:
    SDSMemoryNode(int cantidad,char exponente,int Puerto, int Puerto_status);
    void newClient(int id,int Puerto)override;
    void reciveMns(char * message)override;


    ~SDSMemoryNode();


};

#endif // SDSMEMORYNODE_H

//struct
