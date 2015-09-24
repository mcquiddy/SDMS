/*
 * dPointer.h
 *
 *  Created on: 12 de set. de 2015
 *      Author: bryan
 */

#ifndef DPOINTER_H_
#define DPOINTER_H_
#include <iostream>

using namespace std;


class dPointer {

public:
    string data;
    int ref;
    int DirectionPointer;
    int pSize;
    dPointer(char* type);
    const char* pType;
};

#endif /* DPOINTER_H_ */

