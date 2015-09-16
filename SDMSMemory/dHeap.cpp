/*
 * dHeap.cpp
 *
 *  Created on: 12 de set. de 2015
 *      Author: bryan
 */

#include "dHeap.h"
#include "dPointer.h"

dHeap::dHeap(char path){
    pFolder = path;

}

void dHeap::dMalloc(int size, char* type){

    this->vPointer = new dPointer(type);
    this->vPointer->pType = type;


}




