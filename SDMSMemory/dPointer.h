/*
 * dPointer.h
 *
 *  Created on: 12 de set. de 2015
 *      Author: bryan
 */

#ifndef DPOINTER_H_
#define DPOINTER_H_


class dPointer {
public:
    string type;
    string data;
    int ref;
    int DirectionPointer;
    int pSize;
    dPointer(char* type);
    char* pType;
};

#endif /* DPOINTER_H_ */