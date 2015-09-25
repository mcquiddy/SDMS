#ifndef DOBJECT_H
#define DOBJECT_H
#include <string>
#include <dobject.h>
#include <cstdio>
#include <cstdlib>
#include <dHeap.h>

using namespace std;

class dObject
{
protected:
    dHeap* heap=dHeap::getInstance();
public:
    dObject();

};

#endif // DOBJECT_H



