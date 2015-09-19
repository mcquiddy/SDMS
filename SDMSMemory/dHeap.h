/*
 * dHeap.h
 *
 *  Created on: 12 de set. de 2015
 *      Author: bryan
 */

#ifndef DHEAP_H_
#define DHEAP_H_
#include "dPointer.h"
#include "DLinked_List.h"
#include "socketserver.h"

class dHeap {

public:
    char pFolder;
    SocketServer *server;
    dPointer* vPointer;
    dHeap(char path);
    DLinked_List<int*> dDirections;
private:

    void dFree(dPointer toFree);
    void dMalloc(int size, char* type);
    void connectMemNode();
    void d_Set(dPointer toSend);
    void d_calloc(int pSize);
    void d_get(dPointer toGet);
};


#endif /* DHEAP_H_ */
