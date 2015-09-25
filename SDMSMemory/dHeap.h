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
<<<<<<< HEAD
#include <d_pointer_size_type.h>
=======
#include "pugiXML/pugixml.hpp"
>>>>>>> 0bfc03cecd3bb36e7f3481b76e5c99b8a8422cfb


using namespace std;
using namespace rapidjson;

struct NodoSDSM{
    SocketClienteHeap* puerto;
    SocketClienteHeap* status;
    int id;
};

class d_pointer_size_type;

class dHeap
{
private:
    static dHeap* unicdHeap;
    static void* run(void* obj);
    int contadorID;

    SocketServerHeap * newSDSM;
    SocketServerHeap * newStatus;
    bool flag_dirpointer;
    int dirPointer;
    char pFolder;
    lista<string> pNodes;
    dPointer* vPointer;
    lista<dPointer> dDirections;
    int client;
    lista<NodoSDSM *>* list_nodos;
    char* id;

    int cargarPuerto(char* port);
    void Node(char* ip,int puerto,int status);

    void d_calloc(int pSize);
    void d_free(dPointer toFree);
    void d_get(dPointer toGet);
    void d_set(dPointer toSend);
    void d_status();

<<<<<<< HEAD


=======
>>>>>>> 0c03dd1e6bd141a7cc8d82895ae6cbae82ae9df3
    void checkcalloc(int status, int direccion);
    void checkfree(int status);
    void checkstatus(int mem_disponible,int max_chunck);
    void checkset(int status);
    dHeap();

public:
<<<<<<< HEAD
     void cargarNodos();
     d_pointer_size_type *dMalloc(int size, char* type);
=======
<<<<<<< HEAD
d_pointer_size_type *dMalloc(int size, dChar type);
 static dHeap* getInstance();
 void newNode(char * message);
    void reciveMns(char * message);


    ~dHeap();
=======
>>>>>>> 0c03dd1e6bd141a7cc8d82895ae6cbae82ae9df3
     static dHeap* getInstance();
     void newNode(char * message);
     void reciveMns(char * message);
     ~dHeap();
>>>>>>> 0bfc03cecd3bb36e7f3481b76e5c99b8a8422cfb


};

#endif /* DHEAP_H_ */
