/*
 * dHeap.h
 *
 *  Created on: 12 de set. de 2015
 *      Author: bryan
 */

#ifndef DHEAP_H_
#define DHEAP_H_


#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include "linked_list.h"
#include "dPointer.h"
#include "rapidjson/reader.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "socketserverHeap.h"
#include "pthread.h"
#include "socketclienteHeap.h"
using namespace std;
using namespace rapidjson;




class dHeap
{
private:

      static dHeap* unicdHeap;
      static void* run(void* obj);
      SocketServerHeap * newSDSM;

    char pFolder;
    lista<string> pNodes;
    dPointer* vPointer;

    lista<dPointer> dDirections;
    int client;
    lista<SocketClienteHeap *>* list_ClientStatus;
    char* id;



    void d_calloc(int pSize);
    void d_free(dPointer toFree);
    void d_get(dPointer toGet);

    void d_set(dPointer toSend);
    void d_status();
    void dMalloc(int size, char* type);
    void checkcalloc(int status, int direccion);
    void checkfree(int status);
    void checkstatus(int mem_disponible,int max_chunck);
    void checkset(int status);
     dHeap();

public:

 static dHeap* getInstance();
 void newNode(char * message);
    void reciveMns(char * message);


    ~dHeap();


};

#endif /* DHEAP_H_ */
